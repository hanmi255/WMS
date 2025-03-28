<template>
	<p>{{ prop.rowList.rolename }}:用户</p>
	<TableTitle v-model="titleData" class="title" @user-click="userChildClick" />
	<ComponentsTable v-bind="tableProps" @selection-change="multipleSelectRows1 = $event">
		<template #bodyCell="{ row, prop }">
			<div v-if="prop === 'operation-bar'">
				<el-popconfirm
					:title="`确定要删除该数据吗？`"
					confirm-button-text="确定"
					cancel-button-text="取消"
					@confirm="handleConfirmDelete(row)"
				>
					<template #reference>
						<el-button type="success" size="small" :icon="Delete">删除</el-button>
					</template>
				</el-popconfirm>
			</div>
		</template>
	</ComponentsTable>
	<el-pagination
		style="margin-top: 20px"
		v-model:current-page="pageIndex"
		v-model:page-size="pageSize"
		:page-sizes="[10, 20, 30]"
		:disabled="disabled"
		layout="total, sizes, prev, pager, next, jumper"
		:total="total"
		@size-change="handlePageSize"
		@current-change="handlePageIndex"
	/>
	<!-- 单行编辑弹窗 -->
	<el-dialog
		v-model="dialogVisible"
		:title="dialogTitle"
		width="40%"
		:close-on-click-modal="false"
		:close-on-press-escape="false"
		draggable
		:destroy-on-close="true"
		class="detail-dialog"
	>
		<el-form
			:label-position="left"
			label-width="auto"
			:model="multipleSelectRows1[0]"
			:rules="rules"
			ref="form"
			style="max-width: 600px"
			:disabled="dialogTitle === '查看'"
		>
			<el-form-item label="用户账号" style="width: 300px" prop="username">
				<el-input v-model="multipleSelectRows1[0].username" />
			</el-form-item>
			<el-form-item label="用户姓名" style="width: 300px" prop="userName">
				<el-input v-model="multipleSelectRows1[0].userName" />
			</el-form-item>
			<el-form-item label="密码" style="width: 300px" prop="password" v-if="showPassword">
				<el-input type="password" v-model="multipleSelectRows1[0].password" />
			</el-form-item>
			<el-form-item label="重复密码" style="width: 300px" prop="confirmPassword" v-if="showPassword">
				<el-input
					type="password"
					v-model="multipleSelectRows1[0].confirmPassword"
					label-suffix="密码至少6个字符,最多18个字符"
				/>
			</el-form-item>
			<el-form-item label="组织机构" style="width: 300px" prop="departmentNames">
				<el-input v-model="multipleSelectRows1[0].departmentNames" disabled />
				<div class="btn">
					<el-button size="small" type="primary" :icon="Search" @click="showOrg = true">选择</el-button>
					<el-button size="small" type="primary" :icon="Position" @click="multipleSelectRows1[0].departmentNames = ''"
						>清空</el-button
					>
				</div>
			</el-form-item>
			<el-form-item label="角色" style="width: 300px" prop="role">
				<el-input v-model="multipleSelectRows1[0].role" disabled />
				<div class="btn">
					<el-button size="small" type="primary" :icon="Search" @click="showRol = true">选择</el-button>
					<el-button size="small" type="primary" :icon="Position" @click="btnReset">清空</el-button>
				</div>
			</el-form-item>
			<el-form-item label="用户类型">
				<el-radio-group v-model="multipleSelectRows1[0].userType">
					<el-radio value="当前用户权限">当前用户权限</el-radio>
					<el-radio value="公司权限">公司权限</el-radio>
					<el-radio value="系统用户">系统用户</el-radio>
					<el-radio value="接口用户">接口用户</el-radio>
				</el-radio-group>
			</el-form-item>
			<el-form-item label="手机号码" style="width: 300px">
				<el-input v-model="multipleSelectRows1[0].mobileNumber" />
			</el-form-item>
			<el-form-item label="办公电话" style="width: 300px">
				<el-input v-model="multipleSelectRows1[0].officePhone" />
			</el-form-item>
			<el-form-item label="常用邮箱" style="width: 300px">
				<el-input v-model="multipleSelectRows1[0].email" />
			</el-form-item>
		</el-form>
		<template #footer>
			<span class="dialog-footer">
				<el-button type="primary" @click="btnConfirm" v-if="dialogTitle !== '查看'">确定</el-button>
				<el-button @click="dialogVisible = false">关闭</el-button>
			</span>
		</template>
	</el-dialog>
	<!-- 添加已有客户 -->
	<AddMember v-model:myModel="isVisible"></AddMember>
	<div v-if="multipleSelectRows1[0]">
		<!-- 用户录入编辑对话框里的按钮点击后弹窗的组织机构列表对话框 -->
		<!-- 双向绑定 -->
		<Organization v-model:org="showOrg" v-model:departmentNames="multipleSelectRows1[0].departmentNames"></Organization>
		<!-- 角色输入框 -->
		<!-- <Role v-model:rol="showRol" v-model:rolVal="multipleSelectRows1[0].role"></Role> -->
		<!-- 父传子子传父 -->
		<Role :showRol="showRol" @show-role-dialog="showRoleDialog" @get-role-list="getRoleList"></Role>
	</div>
</template>
<script setup>
import Role from "./role-input.vue";
import Organization from "./organization-input.vue";
import AddMember from "./add-member.vue";
import { Delete, Search, Position } from "@element-plus/icons-vue";
import { ref, onMounted } from "vue";
import TableTitle from "@/components/table-title/TableTitle.vue";
import ComponentsTable from "@/components/table/index.vue";
import { ElMessage } from "element-plus";
import { getRoleUserSearchListAPI, addOneRoleUserAPI } from "@/apis/sysmanager-ok/index.js";

const prop = defineProps(["rowList"]);
// AddMember显示隐藏
const isVisible = ref(false);
// 组织成员
const memberList = ref([]);
// 选中的表格数据
const multipleSelectRows1 = ref([]);
// 弹窗显示
const dialogVisible = ref(false);
// 弹窗标题
const dialogTitle = ref("");
//获取form组件实例
let form = ref();
// 展示Org
const showOrg = ref(false);
// 展示Rol
const showRol = ref(false);
// 只有录入的时候会出现密码输入框
const showPassword = ref(false);

// 发送到子组件的数据
const titleData = ref({
	unfold: true,
	rightButton: true,
	contentList: [
		{
			name: "用户账号",
			type: "AddSininput",
			content: ["", ""],
		},
		{
			name: "用户名称",
			type: "AddSininput",
			content: ["", ""],
		},
	],
	bottomList: [
		{
			name: "用户录入",
			iconType: "Add",
		},
		{
			name: "用户编辑",
			iconType: "Edit",
		},
		{
			name: "添加已有客户",
			iconType: "Add",
		},
	],
});

// 表格内数据
const data = ref([
	// {
	// 	username: "admin",
	// 	status: "激活",
	// 	userName: "管理员",
	// 	departmentNames: "组织机构",
	// 	role: "角色",
	// 	userType: "当前用户权限",
	// },
]);

// 表格配置
const tableProps = ref({
	isIndex: true,
	isMultipleSelect: true,
	data: data,
	columns: [
		{ prop: "username", label: "用户账号", width: "70px" },
		{ prop: "userName", label: "用户名称", width: "70px" },
		{ prop: "status", label: "状态", width: "70px" },
		{ prop: "operation-bar", label: "操作", width: "80px" },
	],
});

// 页码
const pageIndex = ref(1);
// 页面大小
const pageSize = ref(10);
// total
const total = ref(0);

// 改变页面大小
const handlePageSize = (val) => {
	console.log(val);
	pageSize.value = val;
	const params = {
		pageIndex: pageIndex.value,
		pageSize: val,
		id: prop.rowList.ID,
	};
	getUserList(params);
};

// 改变页码
const handlePageIndex = (val) => {
	console.log(val);
	pageIndex.value = val;
	const params = {
		pageIndex: val,
		pageSize: pageSize.value,
		id: prop.rowList.ID,
	};
	getUserList(params);
};

// 获取用户列表
const getUserList = async (params) => {
	const res = await getRoleUserSearchListAPI(
		params || {
			pageIndex: pageIndex.value,
			pageSize: pageSize.value,
			id: prop.rowList.ID,
		},
	);
	if (res.code === 10000) {
		data.value = res.data.rows;
		total.value = res.data.total;
		if (params && data.value.length > 0) {
			ElMessage.success("查询成功");
		} else if (params && data.value.length === 0) {
			ElMessage.warning("暂无数据");
		} else {
			ElMessage.error("查询失败", res.message);
		}
		return;
	} else {
		ElMessage.warning(res.message);
	}
};

// 对重复密码输入框的自定义验证
const validatorConfirmPassword = (rule, value, callBack) => {
	if (value === multipleSelectRows1.value[0].password) {
		callBack();
	} else {
		callBack(new Error("两次输入的密码不一致！"));
	}
};

// 判断用户账号是否重复 该值不可用，系统中已存在
const validatorUserName = (rule, value, callBack) => {
	// 账号列表
	const templateNameList = ["11", "22"];
	if (!templateNameList.includes(value)) {
		callBack();
	} else {
		callBack(new Error("该值不可用，系统中已存在"));
	}
};

// 表单校验的规则
const rules = {
	username: [
		{ required: true, message: "请填写用户账号", trigger: ["blur", "change"] },
		{ trigger: "change", validator: validatorUserName }, //判断用户账号是否重复 该值不可用，系统中已存在
	],
	password: [
		{ required: true, message: "请填写密码", trigger: ["blur"] },
		{
			min: 6,
			max: 18,
			message: "请填写6到18位任意字符！",
			trigger: ["blur", "change"],
		},
	],
	confirmPassword: [
		{ required: true, message: "请重复密码", trigger: ["blur", "change"] },

		{ trigger: "change", validator: validatorConfirmPassword },
	],
	departmentNames: [{ required: true, message: "请填写组织机构", trigger: ["blur", "change"] }],
	role: [{ required: true, message: "请填写角色", trigger: ["blur", "change"] }],
};

// 监听 drawer1 属性的变化
watch(
	() => prop.rowList.ID,
	async (newVal) => {
		console.log("drawer1 变化了,现在为", newVal);
		getUserList({
			pageIndex: pageIndex.value,
			pageSize: pageSize.value,
			id: newVal,
		});
	},
	{
		immediate: true,
	},
);

// 获取组织成员数据
const getMemberList = () => {
	// TODO 获取组织成员(条件+分页)
};
// 处理子组件按钮事件
const userChildClick = (icon) => {
	if (icon.name === "用户录入") {
		handleAdd(multipleSelectRows1);
	}
	if (icon.name === "用户编辑") {
		handleSingleRowEdit(multipleSelectRows1);
	}
	if (icon.name === "添加已有客户") {
		addOwnCustomer(multipleSelectRows1);
	}
	if (icon.name === "右侧查询") {
		handleSearch();
	}
	if (icon.name === "右侧重置") {
		handleReset();
	}
};

//用户录入
const handleAdd = (multipleSelectRows1) => {
	showPassword.value = true;
	multipleSelectRows1.value = [
		{
			...multipleSelectRows1.value,
			userType: "当前用户权限",
		},
	];
	dialogVisible.value = true;
	dialogTitle.value = "用户录入";
};
// 用户编辑
const handleSingleRowEdit = (multipleSelectRows1) => {
	console.log(multipleSelectRows1.value[0]);
	if (multipleSelectRows1.value.length < 1) {
		ElMessage.warning("请选择编辑项目");
		return;
	}
	if (multipleSelectRows1.value.length > 1) {
		ElMessage.warning("请选择一条记录进行编辑");
		return;
	}
	multipleSelectRows1.value[0] = { ...multipleSelectRows1.value[0] };
	dialogVisible.value = true;
	dialogTitle.value = "用户编辑";
};

// 添加已有客户
const addOwnCustomer = (multipleSelectRows1) => {
	isVisible.value = true;
	console.log("点击添加已有客户", isVisible.value);
};

// 确定
const btnConfirm = () => {
	form.value.validate((valid) => {
		if (valid) {
			// 表单验证通过
			// TODO 修改消息模板
			console.log(data);
			if (dialogTitle.value === "用户录入") {
				// TODO 录入消息模板 发送请求重新获取数据
			}

			dialogVisible.value = false;
		} else {
			// 表单验证失败
			ElMessage.warning("请重新填写");
			return false;
		}
	});
};

// 右侧查询
const handleSearch = () => {
	// const templateName = titleData.value.contentList[0].content;
	// const type = titleData.value.contentList[1].content;
	//TODO 获取组织成员(条件+分页)
};
// 右侧重置
const handleReset = () => {
	titleData.value.contentList[0].content = ["", ""];
	titleData.value.contentList[1].content = ["", ""];
};

// 表格内单独删除
const btnDelete = (row) => {
	console.log(row);
	// TODO 删除消息模板接口
};

const btnReset = () => {
	multipleSelectRows1.value[0].role = "";
};

const showRoleDialog = (value) => {
	showRol.value = value;
};

const getRoleList = (val) => {
	multipleSelectRows1.value[0].role = val;
};
</script>

<style lang="scss" scoped>
p {
	width: 100%;
	border-bottom: 1px solid #efefef;
}

.title {
	width: 100%;
	padding-bottom: 10px;
	border-bottom: 1px solid #efefef;
}
</style>
