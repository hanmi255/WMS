<template>
	<p>用户管理</p>
	<TableTitle v-model="titleData" class="title" @user-click="userChildClick" @select-click="selectChildClick" />
	<ComponentsTable v-bind="tableProps" @selection-change="multipleSelectRows = $event">
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
		@close="handleClose"
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
			:model="multipleSelectRows[0]"
			:rules="rules"
			ref="form"
			style="max-width: 600px"
			:disabled="dialogTitle === '查看'"
		>
			<el-form-item label="用户账号" style="width: 300px" prop="username" v-if="isAdd || isEdit">
				<el-input v-model="currentRow.username" />
			</el-form-item>
			<el-form-item label="用户姓名" style="width: 300px" prop="userKey" v-if="isAdd || isEdit">
				<el-input v-model="currentRow.userKey" />
			</el-form-item>
			<el-form-item label="密码" style="width: 300px" prop="password" v-if="isAdd || isReset">
				<el-input type="password" v-model="currentRow.password" />
			</el-form-item>
			<el-form-item label="重复密码" style="width: 300px" prop="confirmPassword" v-if="isAdd || isReset">
				<el-input type="password" v-model="currentRow.confirmPassword" label-suffix="密码至少6个字符,最多18个字符" />
			</el-form-item>
			<el-form-item label="组织机构" style="width: 300px" prop="departname" v-if="isAdd || isEdit">
				<el-input v-model="currentRow.departname" disabled />
				<div class="btn">
					<el-button size="small" type="primary" :icon="Search" @click="showOrg = true">选择</el-button>
					<el-button size="small" type="primary" :icon="Position" @click="currentRow.departname = ''">清空</el-button>
				</div>
			</el-form-item>
			<el-form-item label="角色" style="width: 300px" prop="rolename" v-if="isAdd || isEdit">
				<el-input v-model="currentRow.rolename" disabled />
				<div class="btn">
					<el-button size="small" type="primary" :icon="Search" @click="showRol = true">选择</el-button>
					<el-button size="small" type="primary" :icon="Position" @click="btnReset">清空</el-button>
				</div>
			</el-form-item>
			<el-form-item label="用户类型" v-if="isAdd || isEdit">
				<el-radio-group v-model="currentRow.userType">
					<el-radio value="4">当前用户权限</el-radio>
					<el-radio value="3">公司权限</el-radio>
					<el-radio value="1">系统用户</el-radio>
					<el-radio value="2">接口用户</el-radio>
				</el-radio-group>
			</el-form-item>
			<el-form-item label="手机号码" style="width: 300px" v-if="isAdd || isEdit" prop="mobileNumber">
				<el-input v-model="currentRow.mobileNumber" />
			</el-form-item>
			<el-form-item label="办公电话" style="width: 300px" v-if="isAdd || isEdit">
				<el-input v-model="currentRow.officePhone" />
			</el-form-item>
			<el-form-item label="常用邮箱" style="width: 300px" v-if="isAdd || isEdit">
				<el-input v-model="currentRow.email" />
			</el-form-item>
		</el-form>
		<template #footer>
			<span class="dialog-footer">
				<el-button type="primary" @click="btnConfirm" v-if="dialogTitle !== '查看'">确定</el-button>
				<el-button @click="dialogVisible = false">关闭</el-button>
			</span>
		</template>
	</el-dialog>
	<div v-if="multipleSelectRows[0]">
		<!-- 用户录入编辑对话框里的按钮点击后弹窗的组织机构列表对话框 -->
		<!-- 双向绑定 -->
		<Organization v-model:org="showOrg" v-model:DepartmentNamesIds="DepartmentNamesIds"></Organization>
		<!-- 角色输入框 -->
		<!-- 父传子子传父 -->
		<Role
			:showRol="showRol"
			@show-role-dialog="showRoleDialog"
			@get-role-list="getRoleList"
			v-model:RoleIds="RoleIds"
		></Role>
	</div>
	<!-- 锁定 -->
	<el-dialog title="确定" v-model="confirmLockDialog" width="20%">
		确定锁定用户吗
		<template #footer>
			<span class="dialog-footer">
				<el-button type="primary" @click="btnConfirmLock()">确定</el-button>
				<el-button @click="confirmLockDialog = false">关闭</el-button>
			</span>
		</template>
	</el-dialog>
	<!-- 激活 -->
	<el-dialog title="确定" v-model="confirmActiveDialog" width="20%">
		确定激活用户吗
		<template #footer>
			<span class="dialog-footer">
				<el-button type="primary" @click="btnConfirmActive()">确定</el-button>
				<el-button @click="confirmActiveDialog = false">关闭</el-button>
			</span>
		</template>
	</el-dialog>
	<!-- 这是上方输入框的组件 -->
	<Organization1 v-model:dep="showDep" v-model:DepartmentNamesIds1="DepartmentNamesIds1"></Organization1>

	<!-- 用户名称输入框 -->
	<UserDialog v-model:showName="showName"></UserDialog>
	<el-dialog
		@close="handleClose1"
		v-model="showUpload"
		title="文件导入"
		width="40%"
		:close-on-click-modal="false"
		:close-on-press-escape="false"
		draggable
		:destroy-on-close="true"
	>
		<!-- 文件上传组件 -->
		<el-upload
			ref="uploadRef"
			class="upload-demo"
			action=""
			:limit="1"
			:on-exceed="handleExceed"
			:auto-upload="false"
			:before-upload="beforeUpload"
			:http-request="handleUpload"
		>
			<template #trigger>
				<el-button type="primary">选择文件</el-button>
			</template>
			<el-button type="success" class="ml-3" @click="submitUpload" style="margin-left: 10px">开始上传</el-button>
			<template #tip>
				<div class="el-upload__tip text-red"></div>
			</template>
		</el-upload>
	</el-dialog>
</template>
<script setup>
import UserDialog from "./components/username-dialog.vue";
import Role from "./components/role-input.vue";
import Organization from "./components/organization-input.vue";
import Organization1 from "./components/organization-input-top.vue";
import { Delete } from "@element-plus/icons-vue";
import { ref, onMounted, watch } from "vue";
import TableTitle from "@/components/table-title/TableTitle.vue";
import ComponentsTable from "@/components/table/index.vue";
import { ElMessage } from "element-plus";
import { read, utils, writeFileXLSX } from "xlsx"; // 导入 xlsx 库的方法
import {
	getUserListAPI,
	addUserAPI,
	updateUserAPI,
	deleteUserAPI,
	getUserDetailAPI,
	resetUserPasswordAPI,
	lockUserStatusAPI,
	activeUserStatusAPI,
	importUserAPI,
} from "@/apis/sysmanager-ok/index.js";
definePage({
	meta: {
		menuType: "page",
		text: "用户管理",
		icon: "IconUser",
	},
});

// 选中的表格数据
const multipleSelectRows = ref([]);
// 创建一个中间变量来处理当前行的数据
const currentRow = computed({
	get() {
		return multipleSelectRows.value[0] || {}; // 如果没有选中行，则返回空对象
	},
	set(value) {
		if (multipleSelectRows.value.length > 0) {
			multipleSelectRows.value[0] = value; // 更新选中行的数据
		}
	},
});

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
// 展示选择部门组件 暂时认为和组织机构列表的树形一样
const showDep = ref(false);
// 接受选择部门输入框
const depName = ref("");
// 用户名称输入框
const showName = ref(false);
// // 只有编辑的时候不会出现密码输入框 编辑为false
// const showPassword = ref(false);
// // 密码重置的时候只有两个密码输入框 为true时有密码框
// const notPassword = ref(true);
const isAdd = ref(true);
const isEdit = ref(false);
const isReset = ref(false);
// 确定锁定用户
const confirmLockDialog = ref(false);
// 确定激活用户
const confirmActiveDialog = ref(false);
// 用来接受子组件传递的数据
const DepartmentNamesIds = ref([]);
const RoleIds = ref([]);
// 这是编辑前获取到的id和roleId
const initDepId = ref([]);
const initRoleId = ref([]);
// 上方组织机构zhi
const DepartmentNamesIds1 = ref([]);

watch(
	() => DepartmentNamesIds.value,
	(newVal) => {
		// 确保 multipleSelectRows.value[0] 存在
		if (multipleSelectRows.value.length === 0) {
			multipleSelectRows.value = [{}]; // 初始化为一个空对象
		}

		if (newVal && newVal.length > 0) {
			multipleSelectRows.value[0].departname = newVal.map((item) => item.departname).join(", ");
		} else {
			multipleSelectRows.value[0].departname = "";
		}
	},
);

watch(
	() => DepartmentNamesIds1.value,
	(newVal) => {
		if (newVal && newVal.length > 0) {
			console.log("newVal", newVal);

			titleData.value.contentList[2].content = newVal.map((item) => item.departname);
			console.log("titleData.value.contentList[2].content", titleData.value.contentList[2].content);
		} else {
			titleData.value.contentList[2].content = "";
		}
	},
);
watch(
	() => RoleIds.value,
	(newVal) => {
		// 确保 multipleSelectRows.value[0] 存在
		if (multipleSelectRows.value.length === 0) {
			multipleSelectRows.value = [{}]; // 初始化为一个空对象
		}

		if (newVal && newVal.length > 0) {
			multipleSelectRows.value[0].rolename = newVal.map((item) => item.rolename).join(", ");
		} else {
			multipleSelectRows.value[0].rolename = "";
		}
	},
	{
		deep: true,
		immediate: true,
	},
);

// 发送到子组件的数据
const titleData = ref({
	unfold: true,
	rightButton: true,
	contentList: [
		{
			name: "用户账号",
			type: "AddSininput",
			content: [""],
		},
		{
			name: "用户名称",
			type: "AddSininput",
			content: [""],
		},
		{
			name: "选择部门",
			type: "AddSininput",
			content: [],
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
			name: "密码重置",
			iconType: "Reset",
		},
		{
			name: "锁定用户",
			iconType: "Edit",
		},
		{
			name: "激活用户",
			iconType: "Edit",
		},
		{
			name: "导入",
			iconType: "Add",
		},
		{
			name: "导出",
			iconType: "Export",
		},
	],
});

const data = ref([]);
// 表格配置
const tableProps = ref({
	isIndex: true,
	isMultipleSelect: true,
	data: data,
	columns: [
		{ prop: "username", label: "用户账号", width: "120px" },
		{ prop: "userKey", label: "用户名称", width: "80px" },
		{ prop: "departname", label: "组织机构", width: "250px" },
		{ prop: "roleName", label: "角色", width: "150px" },
		{ prop: "createDate", label: "创建时间", width: "150px" },
		{ prop: "status", label: "状态", width: "90px" },
		{ prop: "operation-bar", label: "操作", width: "90px" },
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
	};
	getUserList(params);
};

// 对重复密码输入框的自定义验证
const validatorConfirmPassword = (rule, value, callBack) => {
	if (value === multipleSelectRows.value[0].password) {
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

// 判断手机号是否符合格式
const validatorMobileNumber = (rule, value, callBack) => {
	const reg = /^1[3-9]\d{9}$/;
	if (reg.test(value)) {
		callBack();
	} else {
		callBack(new Error("请填写正确的手机号"));
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
	departname: [{ required: true, message: "请填写组织机构", trigger: ["blur", "change"] }],
	rolename: [{ required: true, message: "请填写角色", trigger: ["blur", "change"] }],
	mobileNumber: [{ trigger: ["blur", "change"], validator: validatorMobileNumber }],
};

onMounted(() => {
	getUserList();
});

// 获取用户管理列表
const getUserList = async (params) => {
	const res = await getUserListAPI(
		params || {
			pageIndex: pageIndex.value,
			pageSize: pageSize.value,
		},
	);
	if (res.code === 10000) {
		data.value = res.data.rows;
		data.value = res.data.rows.map((item) => {
			return {
				...item,
				status: item.status === 1 ? "激活" : "锁定",
				createDate: new Date(item.createDate).toLocaleDateString("en-CA"), // 格式化日期
			};
		});
		total.value = res.data.total;
		if (params && res.data.rows.length > 0) {
			ElMessage.success("获取数据成功");
		} else if (params && res.data.rows.length === 0) {
			ElMessage.warning("暂无数据");
		} else {
			ElMessage.error("查询失败", res.message);
		}
	} else {
		ElMessage.warning(res.message);
	}
};

// 处理子组件按钮事件
const userChildClick = (icon) => {
	if (icon.name === "用户录入") {
		handleAdd(multipleSelectRows);
	}
	if (icon.name === "用户编辑") {
		handleSingleRowEdit(multipleSelectRows);
	}
	if (icon.name === "密码重置") {
		handleReset(multipleSelectRows);
	}
	if (icon.name === "锁定用户") {
		handleLock(multipleSelectRows);
	}
	if (icon.name === "激活用户") {
		handleActive(multipleSelectRows);
	}
	if (icon.name === "导入") {
		handleInput(multipleSelectRows);
	}
	if (icon.name === "导出") {
		handleExport(multipleSelectRows);
	}
	if (icon.name === "模板下载") {
		handleLoad(multipleSelectRows);
	}
	if (icon.name === "右侧查询") {
		handleSearch(multipleSelectRows);
	}
	if (icon.name === "右侧重置") {
		handleResetData(multipleSelectRows);
	}
};

// 处理子组件输入框事件
const selectChildClick = (input) => {
	if (input.name === "用户名称") {
		handleInput1();
	}
	if (input.name === "选择部门") {
		handleInput2();
	}
};

// 用户名称输入框
const handleInput1 = () => {
	showName.value = true;
};

// 选择部门输入框
const handleInput2 = () => {
	// showDep.value = true;
	showDep.value = true;
	console.log(showDep.value);
};

//用户录入
const handleAdd = (multipleSelectRows) => {
	// showPassword.value = true;
	// notPassword.value = true;
	isAdd.value = true;
	isEdit.value = false;
	isReset.value = false;
	multipleSelectRows.value = [
		{
			...multipleSelectRows.value,
			userType: "4",
		},
	];
	console.log(multipleSelectRows.value);
	dialogVisible.value = true;
	dialogTitle.value = "用户录入";
};
// 用户编辑
const handleSingleRowEdit = async (multipleSelectRows) => {
	// showPassword.value = false;
	// notPassword.value = false;
	isEdit.value = true;
	isAdd.value = false;
	isReset.value = false;
	console.log("multipleSelectRows.value[0].id ", multipleSelectRows.value[0]);

	if (!multipleSelectRows.value[0].username) {
		ElMessage.warning("请选择编辑项目");
		return;
	}
	if (multipleSelectRows.value.length > 1) {
		ElMessage.warning("请选择一条记录进行编辑");
		return;
	}
	const res = await getUserDetailAPI(multipleSelectRows.value[0].id);
	if (res.code === 10000) {
		// 确保 departmentVO 是一个数组
		const departmentVOArray = Array.isArray(res.data.departmentVO) ? res.data.departmentVO : [res.data.departmentVO];
		const departmentIds = departmentVOArray.map((dept) => dept.id);
		const departmentNames = departmentVOArray.map((dept) => dept.departname);

		// 确保 roleVO 是一个数组
		const roleVOArray = Array.isArray(res.data.roleVO) ? res.data.roleVO : [res.data.roleVO];
		const roleIds = roleVOArray.map((role) => role.id);
		const roleNames = roleVOArray.map((role) => role.rolename);
		initDepId.value = departmentIds;
		initRoleId.value = roleIds;
		multipleSelectRows.value[0] = {
			...res.data,
			userKey: res.data.userKey || "",
			departmentIds: departmentIds,
			roleIds: roleIds,
			departname: departmentNames.join(", "),
			rolename: roleNames.join(", "),
		};
		console.log("编辑前multipleSelectRows.value[0]", multipleSelectRows.value[0]);
	}
	// multipleSelectRows.value[0] = { ...multipleSelectRows.value[0] };
	dialogTitle.value = "编辑";
	dialogVisible.value = true;
};

// 判断是空数组
function isEmptyArray(value) {
	return Array.isArray(value) && value.length === 0;
}

// 确定
const btnConfirm = () => {
	form.value.validate(async (valid) => {
		if (valid) {
			try {
				if (dialogTitle.value === "用户录入") {
					// 录入
					const res = await addUserAPI({
						username: multipleSelectRows.value[0].username,
						userKey: multipleSelectRows.value[0].userKey,
						password: multipleSelectRows.value[0].password,
						departmentIds: DepartmentNamesIds.value.map((item) => item.id),
						roleIds: RoleIds.value.map((item) => item.ID),
						userType: multipleSelectRows.value[0].userType,
						mobileNumber: multipleSelectRows.value[0].mobileNumber,
						officePhone: multipleSelectRows.value[0].officePhone,
						email: multipleSelectRows.value[0].email,
					});
					handleApiResponse(res);
				} else if (dialogTitle.value === "用户编辑") {
					// 编辑
					let departmentNamesIds = DepartmentNamesIds.value.map((item) => item.id);
					if (isEmptyArray(departmentNamesIds)) {
						departmentNamesIds = initDepId.value;
					}
					let roleIds = RoleIds.value.map((item) => item.ID);
					if (isEmptyArray(roleIds)) {
						roleIds = initRoleId.value;
					}
					// 可能为从子组件中获取到值，所有可能为空
					const res = await updateUserAPI({
						username: multipleSelectRows.value[0].username,
						userKey: multipleSelectRows.value[0].userKey,
						departmentIds: departmentNamesIds,
						roleIds: roleIds,
						userType: multipleSelectRows.value[0].userType,
						mobileNumber: multipleSelectRows.value[0].mobileNumber,
						officePhone: multipleSelectRows.value[0].officePhone,
						email: multipleSelectRows.value[0].email,
					});
					handleApiResponse(res);
				} else {
					// 重置密码
					const res = await resetUserPasswordAPI({
						userId: multipleSelectRows.value[0].id,
						newPassword: multipleSelectRows.value[0].confirmPassword,
					});
					handleApiResponse(res);
				}
			} catch (error) {
				ElMessage.error(error.message, error.data);
			} finally {
				dialogVisible.value = false;
			}
		} else {
			// 表单验证失败
			ElMessage.warning("请重新填写");
		}
	});
};

// 处理 API 响应的通用函数
const handleApiResponse = (res) => {
	if (res.code === 10000) {
		ElMessage.success("操作成功");
		// 刷新
		getUserList({ pageIndex: pageIndex.value, pageSize: pageSize.value });
	} else if (res.code === 9999) {
		ElMessage.warning(res.message, res.data);
	} else {
		ElMessage.warning(res.message);
	}
};

// 密码重置
const handleReset = (multipleSelectRows) => {
	// showPassword.value = true;
	// notPassword.value = true;
	isReset.value = true;
	isAdd.value = false;
	isEdit.value = false;
	if (!multipleSelectRows.value[0].username) {
		ElMessage.warning("请选择编辑项目");
		return;
	}
	if (multipleSelectRows.value.length > 1) {
		ElMessage.warning("请选择一条记录进行编辑");
		return;
	}
	dialogVisible.value = true;
	dialogTitle.value = "密码重置";
	// TODO 密码重置
};

// 锁定用户
const handleLock = (multipleSelectRows) => {
	if (!multipleSelectRows.value[0].username) {
		ElMessage.warning("请选择编辑项目");
		return;
	}
	if (multipleSelectRows.value.length > 1) {
		ElMessage.warning("请选择一条记录进行编辑");
		return;
	}

	confirmLockDialog.value = true;
};

// 确定锁定用户 把状态改成锁定
const btnConfirmLock = async () => {
	// 如果已经锁定就不用发送请求
	if (multipleSelectRows.value[0].status === "锁定") {
		ElMessage.warning("该用户已锁定");
		confirmLockDialog.value = false;
		return;
	}
	try {
		const res = await lockUserStatusAPI(multipleSelectRows.value[0].id);
		handleApiResponse(res);
	} catch (error) {
		ElMessage.error("锁定用户时发生错误: " + error.data.message);
		console.log(error);
	} finally {
		confirmLockDialog.value = false;
	}
};

// 激活用户
const handleActive = (multipleSelectRows) => {
	if (!multipleSelectRows.value[0].username) {
		ElMessage.warning("请选择编辑项目");
		return;
	}
	if (multipleSelectRows.value.length > 1) {
		ElMessage.warning("请选择一条记录进行编辑");
		return;
	}

	confirmActiveDialog.value = true;
};

// 确定激活用户 把状态改成激活
const btnConfirmActive = async () => {
	// 如果已经激活就不用发送请求
	if (multipleSelectRows.value[0].status === "激活") {
		ElMessage.warning("该用户已激活");
		confirmActiveDialog.value = false;
		return;
	}
	try {
		const res = await activeUserStatusAPI(multipleSelectRows.value[0].id);
		handleApiResponse(res);
	} catch (error) {
		ElMessage.error("激活用户时发生错误: " + error.data.message);
		console.log(error);
	} finally {
		confirmActiveDialog.value = false;
	}
};

const showUpload = ref(false);
const uploadRef = ref();

// 显示文件上传对话框
const handleInput = () => {
	showUpload.value = true;
	console.log(showUpload.value);
};

// 文件上传前的验证
const beforeUpload = (file) => {
	const isExcel =
		file.type === "application/vnd.ms-excel" ||
		file.type === "application/vnd.openxmlformats-officedocument.spreadsheetml.sheet";
	if (!isExcel) {
		ElMessage.error("只能上传 Excel 文件!");
	}
	return isExcel;
};

// 手动触发上传
const submitUpload = () => {
	uploadRef.value.submit();
};

// 处理文件上传
const handleUpload = (file) => {
	// 调用 importUserAPI 接口
	importUserAPI(file.file)
		.then((res) => {
			if (res.code === 10000) {
				ElMessage.success("文件导入成功");
				// 刷新角色列表
				getRoleList();
			} else {
				ElMessage.error(`文件导入失败: ${res.message}`);
			}
		})
		.catch((error) => {
			console.log("err", error);
			let errorMessage = "文件导入失败，服务器错误";

			// 检查 error.response 是否存在
			if (error.response) {
				// 检查 error.response.data 是否为对象
				if (typeof error.response.data === "object" && error.response.data !== null) {
					errorMessage = error.response.data.message || errorMessage;
				}
			} else if (error.message) {
				// 使用 error.message 作为错误信息
				errorMessage = error.message;
			}

			// 显示错误消息
			ElMessage.error(errorMessage);
		});
};

// 处理文件超出限制
const handleExceed = (files, fileList) => {
	ElMessage.warning(
		`当前限制选择 1 个文件，本次选择了 ${files.length} 个文件，共选择了 ${files.length + fileList.length} 个文件`,
	);
};

// 处理文件上传dialog关闭的回调
const handleClose1 = () => {
	showUpload.value = false;
};

// 导出
const handleExport = () => {
	// 检查是否有数据
	if (data.value.length === 0) {
		ElMessage.warning("暂无数据可导出");
		return;
	}

	// 创建工作表
	const ws = utils.json_to_sheet(data.value);

	// 创建工作簿
	const wb = utils.book_new();

	// 将工作表添加到工作簿
	utils.book_append_sheet(wb, ws, "角色管理");

	// 导出 Excel 文件
	writeFileXLSX(wb, "用户管理表.xlsx");

	ElMessage.success("导出成功");
};

// 右侧查询
const handleSearch = () => {
	const params = {
		pageIndex: pageIndex.value,
		pageSize: pageSize.value,
	};
	const username = titleData.value.contentList[0].content[0] || "";
	if (username) {
		params.username = username;
	}
	const realname = titleData.value.contentList[1].content[0] || "";
	if (realname) {
		params.realname = realname;
	}
	const department = titleData.value.contentList[2].content[0] || "";
	if (department) {
		params.department = department;
	}
	getUserList(params);
};
// 右侧重置
const handleResetData = () => {
	titleData.value.contentList[0].content = ["", ""];
	titleData.value.contentList[1].content = ["", ""];
	titleData.value.contentList[2].content = ["", ""];
	getUserList({
		pageIndex: pageIndex.value,
		pageSize: pageSize.value,
	});
};

// 处理确认删除事件
const handleConfirmDelete = async (row) => {
	console.log("删除的id", row.useId);
	const res = await deleteUserAPI(row.useId);
	if (res.code === 10000) {
		getUserList({ pageIndex: pageIndex.value, pageSize: pageSize.value });
		ElMessage.success("删除成功");
	} else {
		ElMessage.warning(res.message);
	}
};

const btnReset = () => {
	multipleSelectRows.value[0].role = "";
};

const showRoleDialog = (value) => {
	showRol.value = value;
};

const getRoleList = (val) => {
	multipleSelectRows.value[0].role = val;
};

// 处理dialog关闭的回调 重置
const handleClose = () => {
	multipleSelectRows.value[0] = "";
	console.log("关闭");
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
