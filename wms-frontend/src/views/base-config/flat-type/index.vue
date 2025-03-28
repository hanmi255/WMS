<script lang="ts" setup>
definePage({
	meta: {
		menuType: "page",
		text: "单位类型",
		icon: "IconSetting",
	},
});
import ComponentsTable from "components/table/index.vue";
import { ElButton, ElMessage, ElMessageBox } from "element-plus";

import { ref, useTemplateRef, onMounted } from "vue";
import { isEqual, isNil, cloneDeep } from "lodash-es";
import ComponentsDialogPromise from "components/dialog-promise/index.vue";
import { type DialogPromiseProps } from "components/dialog-promise/types";
import Pagination from "@/components/Pagination/index.vue";
// 确保Element Plus的样式被导入
import "element-plus/dist/index.css";
import { Download, Plus, Upload, View } from "@element-plus/icons-vue";
import Edit from "@/components/table-title/table-icon/Edit.vue";
import Delete from "@/components/table-title/table-icon/Delete.vue";

import { read, utils, writeFileXLSX } from "xlsx";

// 导入API
import {
	listFlatType,
	addFlatType,
	updateFlatType,
	deleteFlatType,
	exportFlatType,
} from "@/apis/flat-type-gaogao/index";

// =============================表格部分=============================
interface TableData {
	/**
	 * 单位类型唯一ID
	 */
	id?: string;
	/**
	 * 单位类型代码
	 */
	unitTypeCode?: string;
	/**
	 * 单位类型名称
	 */
	unitTypeName?: string;
}

// 表格组件数据
const componentsTableProps = ref<SimpleDataTableProps<TableData>>({
	isIndex: true,
	isMultipleSelect: true,
	data: [],
	columns: [
		{ prop: "unitTypeCode", label: "单位类型代码" },
		{ prop: "unitTypeName", label: "单位类型名称" },
		{ prop: "operation-bar", label: "操作" },
	],
});

// 当前分页参数
const currentPageData = ref({
	pageIndex: 1,
	pageSize: 10,
	pages: 0,
	total: 0,
});

function loadData() {
	listFlatType(
		{
			pageIndex: currentPageData.value.pageIndex,
			pageSize: currentPageData.value.pageSize,
		},
		(data: any) => {
			// 成功
			componentsTableProps.value.data = data.rows;
			currentPageData.value.pages = data.pages;
			currentPageData.value.total = data.total;
		},
		() => {
			// 失败
			ElMessage.error("系统参数数据加载失败");
		},
	);
}
onMounted(() => {
	loadData();
});

// =============================弹窗部分=============================
export interface OnConfirmParams<T> {
	resolve: (value: T) => void;
	reject: (reason?: any) => void;
}
export type OnConfirmFunction<T> = (params: OnConfirmParams<T>) => Promise<boolean>;

/** 空的表单 */
const emptyForm = {
	unitTypeCode: "",
	unitTypeName: "",
};

/** 弹窗类型 0 新增 1 编辑  2 删除 3 导出*/
const dialogType = ref<number>(0);

/** 表单对象 */
const form = ref<TableData>(cloneDeep(emptyForm));

/** 重设表单 */
function resetForm() {
	form.value = cloneDeep(emptyForm);
}

/** 表单是否填写过了？是否存在修改？ */
function hasChange() {
	return !isEqual(form.value, {
		unitTypeCode: "",
		unitTypeName: "",
	});
}
const isViewMode = ref(false); //默认不是查看模式
const dialogPromiseProps = ref<DialogPromiseProps<TableData>>({
	dialogProps: {
		// title: "单位类型录入",
		title: isViewMode.value ? "单位类型查看" : "单位类型录入",
	},

	async onDialogClose({ reject, resolve }) {
		if (isViewMode.value) {
			// 查看模式下直接关闭弹框
			resetForm();
			isViewMode.value = false; // 编辑模式
			resolve(form.value);
			// 返回 true 表示弹框关闭成功
			return true;
		}
		if (hasChange()) {
			return await ElMessageBox.confirm("确定要关闭弹框么？你填写的内容尚未保存。", "关闭弹框", {
				confirmButtonText: "关闭",
				cancelButtonText: "取消",
				type: "warning",
				customClass: "custom-message-box",
			})
				.then(() => {
					// 关闭弹框前做手动做一次表单重设
					resetForm();
					isViewMode.value = false; // 编辑模式
					// 本次弹框没有产生有意义的数据 故返回 undefined
					reject(void 0);
					// 返回 true 表示弹框关闭成功
					return true;
				})
				.catch(
					// 返回 false 表示弹框不关闭 用户取消了关闭弹框
					() => false,
				);
		} else {
			// 用户没有做任何修改 也可以无条件的做一次表单重设
			resetForm();
			isViewMode.value = false; // 编辑模式
			// 可以将现在全部为空的数据 返回给父组件
			resolve(form.value);
			// 返回 true 表示弹框关闭成功
			return true;
		}
	},
});
// 提交逻辑
const onConfirm: OnConfirmFunction<any> = async ({ resolve, reject }) => {
	try {
		// 成功时调用 resolve
		resolve(form.value);
		console.log("ok form", form.value);

		//根据窗口类型进行不同的操作
		if (dialogType.value === 0) {
			addFlatType(
				form.value,
				() => {
					// 成功逻辑
					ElMessage.success("新增成功");
					loadData();
				},
				() => {
					// 失败逻辑
					ElMessage.error("新增失败");
				},
			);
		} else if (dialogType.value === 1) {
			updateFlatType(
				form.value,
				() => {
					// 成功逻辑
					ElMessage.success("编辑成功");
					loadData();
				},
				() => {
					// 失败逻辑
					ElMessage.error("编辑失败");
				},
			);
			/**	}  else if (dialogType.value === 2) {
			deleteFlatType(
				[form.value.id],
				() => {
					// 成功逻辑
					ElMessage.success("删除成功");
					loadData();
				},
				() => {
					// 失败逻辑
					ElMessage.error("删除失败");
				},
			);*/
		} else if (dialogType.value === 3) {
			exportFlatType(
				() => {
					// 成功逻辑
					ElMessage.success("导出成功");
				},
				() => {
					// 失败逻辑
					ElMessage.error("导出失败");
				},
			);
		}

		return true;
	} catch (error) {
		// 失败时调用 reject
		reject(error);
		return false;
	}
};
// 弹窗引用
const dialogRef = useTemplateRef("dialog");
// 打开弹窗
function openDialog() {
	if (!isNil(dialogRef.value)) {
		dialogRef.value.open().then((result) => {
			console.log("result", result);
		});
	}
}

// 选中的行
const selectedRows: Ref<TableData[]> = ref([]);

// 录入逻辑
const handleAdd = () => {
	resetForm();
	isViewMode.value = false; // 编辑模式
	dialogType.value = 0;
	openDialog();
};

// 编辑
const handleEdit = () => {
	if (selectedRows.value.length !== 1) {
		ElMessage.warning("请选择一条记录进行编辑");
		return;
	}
	form.value = {
		id: selectedRows.value[0].id ?? "",
		unitTypeCode: selectedRows.value[0].unitTypeCode ?? "",
		unitTypeName: selectedRows.value[0].unitTypeName ?? "",
	}; // 填充表单数据
	isViewMode.value = false; // 编辑模式
	dialogType.value = 1;
	openDialog(); // 打开弹窗
};

// 查看
const handleView = () => {
	if (selectedRows.value.length !== 1) {
		ElMessage.warning("请选择一条记录进行查看");
		return;
	}
	form.value = {
		id: selectedRows.value[0].id ?? "",
		unitTypeCode: selectedRows.value[0].unitTypeCode ?? "",
		unitTypeName: selectedRows.value[0].unitTypeName ?? "",
	};
	// 填充表单数据
	isViewMode.value = true; // 查看模式
	dialogType.value = 2;
	openDialog(); // 打开弹窗
};

// 批量删除
const handleBatchDelete = () => {
	if (selectedRows.value.length === 0) {
		ElMessage.warning("请至少选择一条记录进行删除");
		return;
	}
	form.value = {
		id: selectedRows.value[0].id ?? "",
		unitTypeCode: selectedRows.value[0].unitTypeCode ?? "",
		unitTypeName: selectedRows.value[0].unitTypeName ?? "",
	};
	ElMessageBox.confirm(`确定要删除选中的 ${selectedRows.value.length} 条记录吗？`, "提示", {
		confirmButtonText: "确定",
		cancelButtonText: "取消",
		type: "warning",
	})
		.then(async () => {
			deleteFlatType(
				selectedRows.value.map((rows) => rows.id),
				() => {
					// 成功逻辑
					ElMessage.success("批量删除成功");
					loadData();
				},
				() => {
					// 失败逻辑
					ElMessage.error("批量删除失败");
				},
			);
		})
		.catch(() => {
			// 取消删除
		});
};

// 单行删除
const handleDelete = (row: TableData) => {
	ElMessageBox.confirm("确定要删除这条记录吗？", "提示", {
		confirmButtonText: "确定",
		cancelButtonText: "取消",
		type: "warning",
	})
		.then(() => {
			// 调用删除接口
			deleteFlatType(
				[row.id], // 将当前行的 id 传给后端
				() => {
					ElMessage.success("删除成功");
					loadData(); // 重新加载数据
				},
				() => {
					ElMessage.error("删除失败");
				},
			);
		})
		.catch(() => {
			// 取消删除
		});
};
// 导出
const rows = ref([]);
// onMounted(async () => {
// 	/* Download from https://sheetjs.com/pres.numbers */
// 	const f = await fetch("https://sheetjs.com/pres.numbers");
// 	const ab = await f.arrayBuffer();
// 	/* parse workbook */
// 	const wb = read(ab);
// 	/* update data */
// 	rows.value = utils.sheet_to_json(wb.Sheets[wb.SheetNames[0]]);
// });

/* get state data and export to XLSX */
function exportFile() {
	const ws = utils.json_to_sheet(rows.value);
	const wb = utils.book_new();
	utils.book_append_sheet(wb, ws, "Data");
	writeFileXLSX(wb, "SheetJSVueAoO.xlsx");
}

// ===========================分页组件部分=============================

const handlePageChange = (data: any) => {
	currentPageData.value.pageIndex = data.pageNum;
	currentPageData.value.pageSize = data.pageSize;
	loadData();
	console.log("页码变化：", data);
};
</script>

<template>
	<section class="menu-page.example-root">
		<!-- 这是实现具体业务的地方 请编写你的组件 -->
		<!-- ===============弹窗部分============== -->
		<div class="button-group">
			<ElButton type="primary" @click="handleAdd">
				<el-icon><Plus /></el-icon>录入</ElButton
			>
			<ElButton type="primary" @click="handleEdit">
				<el-icon><Edit /></el-icon>编辑</ElButton
			>
			<ElButton type="danger" @click="handleBatchDelete">
				<el-icon><Delete /></el-icon>批量删除</ElButton
			>
			<ElButton type="success" @click="handleView">
				<el-icon><View /></el-icon>查看</ElButton
			>
			<ElButton @click="openDialog">
				<el-icon><Upload /></el-icon>Excel模板导入</ElButton
			>
			<ElButton @click="exportFile">
				<el-icon><Download /></el-icon>Excel导出</ElButton
			>
		</div>
		<ComponentsDialogPromise :="dialogPromiseProps" ref="dialog">
			<template #default>
				<ElForm :model="form" label-position="right" label-width="150px">
					<h2>表单信息管理</h2>
					<ElFormItem prop="unitTypeCode" label="单位类型代码：">
						<ElInput v-model="form.unitTypeCode" :readonly="isViewMode" />
					</ElFormItem>
					<ElFormItem prop="unitTypeName" label="单位类型名称：">
						<ElInput v-model="form.unitTypeName" :readonly="isViewMode" />
					</ElFormItem>
				</ElForm>
			</template>
			<template #footer="{ reject, resolve }">
				<ElButton type="info" @click="dialogPromiseProps.onDialogClose({ reject, resolve })"> 关闭 </ElButton>
				<ElButton type="primary" @click="onConfirm({ reject, resolve })" v-if="!isViewMode"> 确认 </ElButton>
			</template>
		</ComponentsDialogPromise>
		<!-- ===============表格部分============== -->
		<ComponentsTable :="componentsTableProps" @selection-change="selectedRows = $event">
			<template #bodyCell="{ prop }">
				<template v-if="prop === 'operation-bar'">
					<ElButton type="danger" @click="() => handleDelete(row)">删除</ElButton>
				</template>
			</template>
		</ComponentsTable>
		<!-- ==================分页组件部分================= -->
		<div class="demo-section">
			<Pagination
				:page-total="currentPageData.total"
				:page-sizes="[10, 20, 50, 100]"
				:pager-count="currentPageData.pages"
				:current-page="currentPageData.pageIndex"
				:page-size="currentPageData.pageSize"
				layout="total, sizes, prev, pager, next, jumper"
				@page-func="handlePageChange"
			/>
		</div>
	</section>
</template>

<style lang="scss" scoped>
// .menu-page.example-root {
// 	// 这是实现具体业务的地方 请编写你的组件样式
// }
.custom-message-box .el-message-box__content {
	display: flex !important;
	align-items: center !important;
	justify-content: center !important;
	text-align: center !important;
}
.custom-message-box .el-message-box__status {
	color: #e6a23c !important; // 警告图标颜色
	font-size: 24px !important; // 图标大小
	margin-right: 10px !important;
}
.custom-message-box .el-message-box__message {
	margin: 0 !important;
	font-size: 16px !important;
	color: #606266 !important;
}
.custom-message-box .el-message-box__btns {
	.el-button {
		margin: 0 10px !important;
	}
}
.button-group {
	margin: 20px 5px;
}
.el-input {
	width: 200px; /* 调整输入框宽度 */
}
h2 {
	color: brown;
	font-size: 20px;
	font-weight: bold;
	margin-bottom: 10px;
}
// 分页组件样式
.demo-section {
	// position: fixed;
	// bottom: 0;
	// left: 0;
	margin-bottom: 30px;
	padding: 20px;
	border: 1px solid #eee;
	border-radius: 8px;
}
</style>
