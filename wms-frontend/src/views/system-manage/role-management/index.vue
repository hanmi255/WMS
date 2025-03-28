<template>
	<p>角色管理</p>
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
				<el-button type="primary" size="small" :icon="User" @click="btnUser(row)">用户</el-button>
				<el-button type="success" size="small" :icon="Setting" @click="btnPower(row)">权限设置</el-button>
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
		>
			<el-form-item label="角色名称" style="width: 300px" prop="rolename">
				<el-input v-model="currentRow.rolename" />
			</el-form-item>
			<el-form-item label="角色编码" style="width: 300px" prop="rolecode">
				<el-input v-model="currentRow.rolecode" />
			</el-form-item>
		</el-form>
		<template #footer>
			<span class="dialog-footer">
				<el-button type="primary" @click="btnConfirm">确定</el-button>
				<el-button @click="dialogVisible = false">关闭</el-button>
			</span>
		</template>
	</el-dialog>
	<!-- 抽屉 -->
	<!-- 成员 -->
	<el-drawer v-model="drawer1" size="35%" :modal="false">
		<Member :rowList="rowList"></Member>
	</el-drawer>
	<!-- 角色 -->
	<el-drawer v-model="drawer2" size="25%" :modal="false">
		<Role :rowList="rowList" :drawer2="drawer2"></Role>
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
import { Delete, Setting, User } from "@element-plus/icons-vue";
import { ref, onMounted } from "vue";
import TableTitle from "@/components/table-title/TableTitle.vue";
import ComponentsTable from "@/components/table/index.vue";
import { ElMessage } from "element-plus";
import { read, utils, writeFileXLSX } from "xlsx"; // 导入 xlsx 库的方法
import {
	getRoleListAPI,
	addRoleAPI,
	updateRoleAPI,
	deleteRoleAPI,
	importRoleAPI,
	exportRoleAPI,
} from "@/apis/sysmanager-ok/index.js";
import { getRoleResourceAPI } from "@/apis/menu";
definePage({
	meta: {
		menuType: "page",
		text: "角色管理",
		icon: "IconUser",
	},
});

// 是否展示抽屉，用于控制抽屉里面数据的渲染时机

// 传递的row
const rowList = ref([]);
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
// 控制抽屉
const drawer1 = ref(false);
const drawer2 = ref(false);

// 发送到子组件的数据
const titleData = ref({
	unfold: true,
	rightButton: true,
	contentList: [
		{
			name: "角色名称",
			type: "AddSininput",
			content: [""],
		},
	],
	bottomList: [
		{
			name: "角色录入",
			iconType: "Add",
		},
		{
			name: "角色编辑",
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

// 表格配置
const tableProps = ref({
	isIndex: true,
	isMultipleSelect: true,
	data: data,
	columns: [
		{ prop: "rolecode", label: "角色编码", width: "100px" },
		{ prop: "rolename", label: "角色名称", width: "100px" },
		{ prop: "operation-bar", label: "操作", width: "300px" },
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
};

// 改变页码
const handlePageIndex = (val) => {
	console.log(val);
	pageIndex.value = val;
};

// 获取角色列表
const getRoleList = async (params) => {
	const res = await getRoleListAPI(
		params || {
			pageIndex: pageIndex.value,
			pageSize: pageSize.value,
		},
	);
	if (res.code === 10000) {
		data.value = res.data.rows;
		total.value = data.value.length;
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

onMounted(() => {
	getRoleList();
});

// 对角色范围的自定义验证
const validatorRoleName = (rule, value, callBack) => {
	const reg = /^.{2,8}$/;
	if (reg.test(value)) {
		callBack();
	} else {
		callBack(new Error("请填写2到8位字符！"));
	}
};

// 对角色编码的自定义验证
const validatorRoleCode = (rule, value, callBack) => {
	const reg = /^.{2,15}$/;
	if (reg.test(value)) {
		callBack();
	} else {
		callBack(new Error("请填写2到15位字符！"));
	}
};

// 编码不能重复(录入的时候)，先获取所有编码 在find
const validatorRoleCode1 = (rule, value, callBack) => {
	if (dialogTitle.value === "角色录入") {
		const found = data.value.find((item) => item.rolecode === value);
		if (found) {
			callBack(new Error("编码不能重复！"));
		}
	}
	callBack();
};

// 表单校验的规则
const rules = {
	rolename: [
		{ required: true, message: "请输入角色名称", trigger: "blur" },
		{ trigger: "change", validator: validatorRoleName },
	],
	rolecode: [
		{ required: true, message: "请输入角色编码", trigger: "blur" },
		{ trigger: "change", validator: validatorRoleCode },
		{ trigger: "change", validator: validatorRoleCode1 },
	],
};

// 处理子组件按钮事件
const userChildClick = (icon) => {
	if (icon.name === "角色录入") {
		handleAdd(multipleSelectRows);
	}
	if (icon.name === "角色编辑") {
		handleSingleRowEdit(multipleSelectRows);
	}
	if (icon.name === "导入") {
		handleInput();
	}
	if (icon.name === "导出") {
		handleExport();
	}
	if (icon.name === "右侧查询") {
		handleSearch(multipleSelectRows);
	}
	if (icon.name === "右侧重置") {
		handleResetData(multipleSelectRows);
	}
};

//角色录入
const handleAdd = (multipleSelectRows) => {
	multipleSelectRows.value = [
		{
			rolename: " ",
			rolecode: " ",
		},
	];
	dialogVisible.value = true;
	dialogTitle.value = "角色录入";
};
// 角色编辑
const handleSingleRowEdit = (multipleSelectRows) => {
	if (
		multipleSelectRows.value.length < 1 ||
		!multipleSelectRows.value[0] ||
		Object.keys(multipleSelectRows.value[0]).length === 0
	) {
		ElMessage.warning("请选择编辑项目");
		return;
	}
	if (multipleSelectRows.value.length > 1) {
		ElMessage.warning("请选择一条记录进行编辑");
		return;
	}
	dialogVisible.value = true;
	dialogTitle.value = "角色编辑";
};

// 确定
const btnConfirm = () => {
	form.value.validate(async (valid) => {
		if (!valid) {
			// 表单验证失败
			ElMessage.warning("请重新填写");
			return;
		} else {
			// 表单验证通过
			try {
				if (dialogTitle.value === "角色录入") {
					// 角色录入
					const res = await addRoleAPI({
						rolecode: multipleSelectRows.value[0].rolecode,
						rolename: multipleSelectRows.value[0].rolename,
					});
					if (res.code === 10000) {
						dialogVisible.value = false;
						// 刷新角色列表
						getRoleList();
						ElMessage.success("添加成功");
						return;
					} else {
						ElMessage.warning(res.message);
					}
					dialogVisible.value = false;
					return;
				} else if (dialogTitle.value === "角色编辑") {
					// 编辑
					const res = await updateRoleAPI({
						ID: multipleSelectRows.value[0].ID,
						rolecode: multipleSelectRows.value[0].rolecode,
						rolename: multipleSelectRows.value[0].rolename,
					});
					if (res.code === 10000) {
						dialogVisible.value = false;
						// 刷新角色列表
						getRoleList();
						ElMessage.success("修改成功");
						return;
					} else {
						ElMessage.warning(res.message);
					}
					dialogVisible.value = false;
				}
			} catch (error) {
				console.log("err", error);
				let errorMessage = "操作失败，服务器错误";

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
			}
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
	// 调用 importRoleAPI 接口
	importRoleAPI(file.file)
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
	writeFileXLSX(wb, "角色管理表.xlsx");

	ElMessage.success("导出成功");
};

// 右侧查询
const handleSearch = async () => {
	const rolename = titleData.value.contentList[0].content[0];
	getRoleList({
		pageIndex: pageIndex.value,
		pageSize: pageSize.value,
		rolename: rolename,
	});
};
// 右侧重置
const handleResetData = async () => {
	titleData.value.contentList[0].content = ["", ""];
	getRoleList({
		pageIndex: pageIndex.value,
		pageSize: pageSize.value,
	});
};

// 处理确认删除事件
const handleConfirmDelete = async (row) => {
	console.log("删除的id", row.ID);
	const res = await deleteRoleAPI(row.ID);
	if (res.code === 10000) {
		getRoleList();
		ElMessage.success("删除成功");
	} else {
		ElMessage.warning(res.message);
	}
};

// 处理dialog关闭的回调 重置
const handleClose = () => {
	multipleSelectRows.value[0] = "";
	console.log("关闭");
};

// 打开用户组件
const btnUser = (row) => {
	rowList.value = row;
	console.log("rowList.value", rowList.value);
	drawer1.value = true;
};

// 打开权限组件
const btnPower = async (row) => {
	rowList.value = row;
	console.log(rowList.value);
	const res = await getRoleResourceAPI(row.rolecode);
	if (res.code === 10000) {
		rowList.value = res.data;
	} else {
		ElMessage.warning(res.message);
	}
	drawer2.value = true;
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
