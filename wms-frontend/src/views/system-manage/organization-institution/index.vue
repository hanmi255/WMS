<template>
	<p>组织机构列表</p>
	<TableTitle v-model="titleData" class="title" @user-click="userChildClick" />

	<el-table
		@row-click="handleRowClick"
		@selection-change="multipleSelectRows = $event"
		@current-change="handleCurrentChange"
		:data="data"
		style="width: 100%; margin-bottom: 20px"
		row-key="tnId"
		border
		stripe
		highlight-current-row
	>
		<el-table-column type="index" />
		<el-table-column prop="departName" label="组织机构名称" width="250" />
		<el-table-column prop="description" label="组织机构描述" width="150" />
		<el-table-column prop="orgCode" label="机构编码" width="100" />
		<el-table-column prop="orgType" label="机构类型" width="100" />
		<el-table-column prop="mobile" label="电话" width="100" />
		<el-table-column prop="fax" label="传真" width="100" />
		<el-table-column prop="address" label="地址" width="100" />
		<el-table-column prop="operation-bar" label="操作" width="300">
			<template #default="{ row }">
				<el-button type="danger" size="small" :icon="Delete" @click="btnDelete(row)">删除</el-button>
				<el-button type="success" size="small" :icon="User" @click="btnSearch(row)">查看成员</el-button>
				<el-button type="primary" size="small" :icon="Setting" @click="btnSet(row)">角色设置</el-button>
			</template>
		</el-table-column>
	</el-table>
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
		:model="multipleSelectRows[0]"
		:rules="rules"
		ref="form"
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
			<el-form-item label="组织机构名称" style="width: 300px">
				<el-input v-model="multipleSelectRows[0].departName" />
			</el-form-item>
			<el-form-item label="组织机构描述" style="width: 300px">
				<el-input v-model="multipleSelectRows[0].description" />
			</el-form-item>
			<el-form-item label="上级组织机构" style="width: 300px">
				<el-select placeholder="--请选择组织机构--" v-model="multipleSelectRows[0].orgCode">
					<el-option label="厦门境图智能科技有限公司" value="厦门境图智能科技有限公司" />
				</el-select>
			</el-form-item>
			<el-form-item label="机构类型" style="width: 300px">
				<el-select placeholder="--请选择--" v-model="multipleSelectRows[0].orgType">
					<el-option label="公司" value="公司" />
				</el-select>
			</el-form-item>
			<el-form-item label="电话" style="width: 300px">
				<el-input v-model="multipleSelectRows[0].mobile" />
			</el-form-item>
			<el-form-item label="传真" style="width: 300px">
				<el-input v-model="multipleSelectRows[0].fax" />
			</el-form-item>
			<el-form-item label="地址" style="width: 300px">
				<el-input v-model="multipleSelectRows[0].address" />
			</el-form-item>
		</el-form>
		<template #footer>
			<span class="dialog-footer">
				<el-button type="primary" @click="btnConfirm" v-if="dialogTitle !== '查看'">确定</el-button>
				<el-button @click="dialogVisible = false">关闭</el-button>
			</span>
		</template>
	</el-dialog>
	<!-- 抽屉 -->
	<!-- 成员 -->
	<el-drawer v-model="drawer1" size="35%" :modal="false">
		<Member></Member>
	</el-drawer>
	<!-- 角色 -->
	<el-drawer v-model="drawer2" size="25%" :modal="false">
		<Role></Role>
	</el-drawer>

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
import Member from "./components/member.vue";
import Role from "./components/role.vue";
import { Delete, User, Setting } from "@element-plus/icons-vue";
import { ref } from "vue";
import TableTitle from "@/components/table-title/TableTitle.vue";

import { getOrgListAPI, importOrgAPI } from "@/apis/sysmgr/index.js";
import { read, utils, writeFileXLSX } from "xlsx"; // 导入 xlsx 库的方法
definePage({
	meta: {
		menuType: "page",
		text: "组织机构",
		icon: "IconHouse",
	},
});

// 选中的表格数据
const multipleSelectRows = ref([]);
// 当前行
const currentRow = ref(null);
// 弹窗显示
const dialogVisible = ref(false);
// 弹窗标题
const dialogTitle = ref("");
// 控制抽屉
const drawer1 = ref(false);
const drawer2 = ref(false);

//获取form组件实例
let form = ref();

// 发送到子组件的数据
const titleData = ref({
	unfold: false,
	bottomList: [
		{
			name: "组织机构录入",
			iconType: "Add",
		},
		{
			name: "组织机构编辑",
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

// 表格内数据
const data = ref([]);

// 获取组织列表
const getOrgList = async () => {
	const parentDepartId = "40289fe393dddaa90193de2cb61a0004";
	// const res = await getOrgListAPI({ parentDepartId: parentDepartId });
	const res = await getOrgListAPI();
	console.log(res);
	// if (res.code === 10000) {
	// 	data.value = res.data;
	// 	// 处理 menuType 和 menuLevels 的转换
	// 	transformMenuData(data.value);
	// 	// 获取图标 URL 并映射到 items
	// 	await fetchAndMapIcons(data.value);
	// 	// 给每个isParentNode===1的data加上children
	// 	// 给每个 isParentNode === 1 的 item 添加 children
	// 	addChildrenToParentNodes(data.value);
	// 	console.log("菜单列表", data.value);
	// } else {
	// 	ElMessage.error(res.message);
	// }
};
// 处理 menuType 和 menuLevels 的转换
const transformMenuData = (items) => {
	items.forEach((item) => {
		item.menuType = item.menuType === 0 ? "菜单类型" : "权限类型";
		item.menuLevels = item.menuLevels === 0 ? "一级菜单" : "下级菜单";
	});
};
// 给每个 isParentNode === 1 的 item 添加 children
const addChildrenToParentNodes = (items) => {
	items.forEach((child) => {
		if (child.isParentNode === 1) {
			child.children = [{}];
		}
	});
};

onMounted(() => {
	getOrgList();
});

// 表单校验的规则
const rules = {
	departName: [{ required: true, message: "请填写组织机构名称", trigger: ["blur", "change"] }],
};

// 处理子组件按钮事件
const userChildClick = (icon) => {
	if (icon.name === "组织机构录入") {
		handleAdd(multipleSelectRows);
	}
	if (icon.name === "组织机构编辑") {
		handleSingleRowEdit(multipleSelectRows);
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
};

//组织机构录入
const handleAdd = (multipleSelectRows) => {
	multipleSelectRows.value = [{ type: "", templateName: "", templateContent: "" }];
	dialogVisible.value = true;
	dialogTitle.value = "组织机构录入";
};
// 组织机构编辑
const handleSingleRowEdit = (multipleSelectRows) => {
	console.log(multipleSelectRows.value.length);
	if (multipleSelectRows.value.length < 1) {
		ElMessage.warning("请选择编辑项目");
		return;
	}
	if (multipleSelectRows.value.length > 1) {
		ElMessage.warning("请选择一条记录进行编辑");
		return;
	}
	dialogVisible.value = true;
	dialogTitle.value = "组织机构编辑";
};

// 确定
const btnConfirm = () => {
	form.value.validate((valid) => {
		if (valid) {
			// 表单验证通过
			// TODO 修改组织机构数据

			console.log(data);
			if (dialogTitle.value === "组织机构录入") {
				// TODO 录入组织机构 发送请求重新获取数据
			}
			dialogVisible.value = false;
		} else {
			// 表单验证失败
			ElMessage.warning("请重新填写");
			return false;
		}
	});
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
	// 调用 importOrgAPI 接口
	importOrgAPI(file.file)
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
	utils.book_append_sheet(wb, ws, "组织机构");

	// 导出 Excel 文件
	writeFileXLSX(wb, "组织机构表.xlsx");

	ElMessage.success("导出成功");
};

// 表格内单独删除
const btnDelete = (row) => {
	// TODO 删除组织成员
	console.log(row);
};
// 表格内查看成员
const btnSearch = (row) => {
	console.log(row);
	drawer1.value = true;
};
// 表格内成员设置
const btnSet = (row) => {
	console.log(row);
	drawer2.value = true;
};

// 处理行点击事件
const handleRowClick = (row, column, event) => {
	console.log("点击的行数据:", row);
	multipleSelectRows.value[0] = row;
	currentRow.value = row; // 更新当前行
};

const handleCurrentChange = (val) => {
	currentRow.value = val;
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
/* 自定义抽屉样式 */
::v-deep(.el-drawer) {
	background-color: transparent !important; /* 设置抽屉背景颜色为透明 */
}

/* 自定义遮罩层样式 */
::v-deep(.el-overlay) {
	background-color: rgba(0, 0, 0, 0) !important; /* 设置遮罩层透明度为0 */
}

::v-deep(header.el-drawer__header) {
	margin: 0;
}
</style>
