<script lang="ts" setup>
definePage({
	meta: {
		menuType: "page",
		text: "客户",
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
import type { FormInstance, UploadFile } from "element-plus";
import { read, utils, writeFileXLSX } from "xlsx";

// 导入API
import {getshangpingApi} from  "@/apis/base-data/index.js";

// =============================弹窗部分=============================
export interface OnConfirmParams<T> {
	resolve: (value: T) => void;
	reject: (reason?: any) => void;
}
export type OnConfirmFunction<T> = (params: OnConfirmParams<T>) => Promise<boolean>;

interface TestBuzi {
	code_type: string;
	organization: string;
	prefix: string;
	separator: string;
	year_digits: number;
	month_digits: number;
	day_digits: number;
	serial_digits: number;
	example_number: string;
}

/** 空的表单 */
const emptyForm: TestBuzi = {
	code_type: "",
	organization: "",
	prefix: "",
	separator: "",
	year_digits: 0,
	month_digits: 0,
	day_digits: 0,
	serial_digits: 0,
	example_number: "",
};

/** 表单对象 */
const form = ref<TestBuzi>(cloneDeep(emptyForm));

/** 重设表单 */
function resetForm() {
	form.value = cloneDeep(emptyForm);
}

/** 表单是否填写过了？是否存在修改？ */
function hasChange() {
	return !isEqual(form.value, {
		code_type: "",
		organization: "",
		prefix: "",
		separator: "",
		year_digits: 0,
		month_digits: 0,
		day_digits: 0,
		serial_digits: 0,
		example_number: "",
	});
}
// 选中的行
const selectedRows: Ref<TableData[]> = ref([]);
const isViewMode = ref(false); //默认不是查看模式
const dialogPromiseProps = ref<DialogPromiseProps<TestBuzi>>({
	dialogProps: {
		// title: "编码规则录入",
		title: isViewMode.value ? "查看编码规则" : "编辑编码规则",
	},

	async onDialogClose({ reject, resolve }) {
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

// 新的逻辑：编辑
const handleEdit = () => {
	if (selectedRows.value.length !== 1) {
		ElMessage.warning("请选择一条记录进行编辑");
		return;
	}
	form.value = {
		code_type: selectedRows.value[0].code_type || "",
		organization: selectedRows.value[0].organization || "",
		prefix: selectedRows.value[0].prefix || "",
		separator: selectedRows.value[0].separator || "",
		year_digits: selectedRows.value[0].year_digits || 0,
		month_digits: selectedRows.value[0].month_digits || 0,
		day_digits: selectedRows.value[0].day_digits || 0,
		serial_digits: selectedRows.value[0].serial_digits || 0,
		example_number: selectedRows.value[0].example_number || "",
	}; // 填充表单数据
	isViewMode.value = false; // 编辑模式
	openDialog(); // 打开弹窗
};

// 新的逻辑：查看
const handleView = () => {
	if (selectedRows.value.length !== 1) {
		ElMessage.warning("请选择一条记录进行查看");
		return;
	}
	form.value = {
		code_type: selectedRows.value[0].code_type || "",
		organization: selectedRows.value[0].organization || "",
		prefix: selectedRows.value[0].prefix || "",
		separator: selectedRows.value[0].separator || "",
		year_digits: selectedRows.value[0].year_digits || 0,
		month_digits: selectedRows.value[0].month_digits || 0,
		day_digits: selectedRows.value[0].day_digits || 0,
		serial_digits: selectedRows.value[0].serial_digits || 0,
		example_number: selectedRows.value[0].example_number || "",
	}; // 填充表单数据
	isViewMode.value = true; // 查看模式
	openDialog(); // 打开弹窗
};

// 新的逻辑：批量删除
const handleBatchDelete = () => {
	if (selectedRows.value.length === 0) {
		ElMessage.warning("请至少选择一条记录进行删除");
		return;
	}
	ElMessageBox.confirm(`确定要删除选中的 ${selectedRows.value.length} 条记录吗？`, "提示", {
		confirmButtonText: "确定",
		cancelButtonText: "取消",
		type: "warning",
	})
		.then(async () => {
			// 调用 API 批量删除
			// await api.batchDelete(selectedRows.value.map(row => row.id));
			ElMessage.success("批量删除成功");
		})
		.catch(() => {
			// 取消删除
		});
};

// 录入逻辑（保持不变）
const handleAdd = () => {
	resetForm();
	isViewMode.value = false; // 编辑模式
	openDialog();
};

// 导出
const rows = ref([]);
onMounted(async () => {
	/* Download from https://sheetjs.com/pres.numbers */
	const f = await fetch("https://sheetjs.com/pres.numbers");
	const ab = await f.arrayBuffer();
	/* parse workbook */
	const wb = read(ab);
	/* update data */
	rows.value = utils.sheet_to_json(wb.Sheets[wb.SheetNames[0]]);
});

/* get state data and export to XLSX */
function exportFile() {
	const ws = utils.json_to_sheet(rows.value);
	const wb = utils.book_new();
	utils.book_append_sheet(wb, ws, "Data");
	writeFileXLSX(wb, "SheetJSVueAoO.xlsx");
}

// =============================表格部分=============================
interface TableData {
	[key: string]: any;
	/**
	 * 编号类型
	 */
	code_type?: string;
	/**
	 * 组织机构
	 */
	organization?: string;
	/**
	 * 前缀
	 */
	prefix?: string;
	/**
	 * 分隔符
	 */
	separator?: string;
	/**
	 * 年位数
	 */
	year_digits?: number;
	/**
	 * 月位数
	 */
	month_digits?: number;
	/**
	 * 日位数
	 */
	day_digits?: number;
	/**
	 * 序号位数
	 */
	serial_digits?: number;
	/**
	 * 示例号码
	 */
	example_number?: string;
}
/** 
const data = ref<TableData[]>([
	{
		code_type: "Ab3Ck",
		organization: "LmN5pQr8St",
		prefix: "Xy7",
		separator: "_",
		year_digits: 2,
		month_digits: 2,
		day_digits: 1,
		serial_digits: 4,
		example_number: "gH9iJ1k3L5m7n9o",
	},
	{
		code_type: "DeF6g",
		organization: "OpQ7rSt9Uv",
		prefix: "Wx2",
		separator: "/",
		year_digits: 4,
		month_digits: 1,
		day_digits: 2,
		serial_digits: 6,
		example_number: "pR3sT5u7V9w1x3y",
	},
	{
		code_type: "HiJ8k",
		organization: "W1G2a7K6bC",
		prefix: "Z0a",
		separator: "-",
		year_digits: 3,
		month_digits: 2,
		day_digits: 2,
		serial_digits: 5,
		example_number: "m4N6p8Q0r2S4t6u",
	},
]);
*/

const componentsTableProps = ref<SimpleDataTableProps<TableData>>({
	isIndex: true,
	isMultipleSelect: true,
	data: [],
	columns: [
		{ prop: "code_type", label: "编号类型" },
		{ prop: "organization", label: "组织机构" },
		{ prop: "prefix", label: "前缀" },
		{ prop: "separator", label: "分隔符" },
		{ prop: "year_digits", label: "年位数" },
		{ prop: "month_digits", label: "月位数" },
		{ prop: "day_digits", label: "日位数" },
		{ prop: "serial_digits", label: "序号位数" },
		{ prop: "example_number", label: "示例号码" },
		{ prop: "operation-bar", label: "操作" },
	],
});

function loadData() {
	listAutoCoding(
		{
			pageIndex: 1,
			pageSize: 10,
			pages: 100,
		},
		(data: any) => {
			// 成功
			componentsTableProps.value.data = data.rows;
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
// ===========================分页组件部分=============================
const currentData = ref({
	pageNum: 1,
	pageSize: 10,
});

const handlePageChange = (data: { pageNum: number; pageSize: number } | { pageNum: number; pageSize: number }) => {
	currentData.value = data;
	console.log("页码变化：", data);
};

const importDialogVisible = ref(false);
const fileList = ref<UploadFile[]>([]);
const handleFileChange = (file: UploadFile) => {
	fileList.value = [file];
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
			<el-button @click="handleAdd">
				<el-icon><Upload /></el-icon>Excel模板导入
			</el-button>
			<el-dialog v-model="importDialogVisible" title="Excel导入" width="500px">
				<el-upload
					class="upload-excel"
					action="#"
					:auto-upload="false"
					:on-change="handleFileChange"
					:limit="1"
					:file-list="fileList"
				>
					<el-button type="primary">选择文件</el-button>
					<template #tip>
						<div class="el-upload__tip">只能上传excel文件，且不超过10MB</div>
					</template>
				</el-upload>
				<template #footer>
					<span class="dialog-footer">
						<el-button @click="importDialogVisible = false">取消</el-button>
						<el-button type="primary" @click="importDialogVisible = false">确定</el-button>
					</span>
				</template>
			</el-dialog>
			<el-button @click="exportFile">
				<el-icon><Download /></el-icon>Excel导出
			</el-button>
		</div>
		<!-- 表单内容 -->
		<ComponentsDialogPromise :="dialogPromiseProps" ref="dialog">
			<template #default>
				<ElForm :model="form" label-position="right" label-width="150px">
					<h2>表单信息管理</h2>
					<ElFormItem prop="code_type" label="企业属性：" label-width="150px">
						<el-select v-model="form.code_type" placeholder="--请选择--">
							<el-option label="生鲜供应商1" value="shanghai" />
							<el-option label="生鲜供应商1" value="beijing" />
						</el-select>
					</ElFormItem>

					<ElFormItem prop="organization" label="属性：">
						<el-select v-model="form.organization" :readonly="isViewMode" placeholder="--请选择--">
							<el-option label="年龄" value="shanghai" />
							<el-option label="测试" value="beijing" />
						</el-select>
					</ElFormItem>
					<ElFormItem prop="prefix" label="中文全称：">
						<ElInput v-model="form.prefix" :readonly="isViewMode" />
					</ElFormItem>
					<ElFormItem prop="separator" label="合同：">
						<ElInput v-model="form.separator" :readonly="isViewMode" />
					</ElFormItem>
					<ElFormItem prop="year_digits" label="地址：">
						<ElInput v-model="form.year_digits" :readonly="isViewMode" />
					</ElFormItem>
					<ElFormItem prop="month_digits" label="负责人：">
						<ElInput v-model="form.month_digits" :readonly="isViewMode" />
					</ElFormItem>
					<ElFormItem prop="day_digits" label="联系人：">
						<ElInput v-model="form.day_digits" :readonly="isViewMode" />
					</ElFormItem>
					<ElFormItem prop="serial_digits" label="邮箱：">
						<ElInput v-model="form.serial_digits" :readonly="isViewMode" />
					</ElFormItem>
					<ElFormItem prop="example_number" label="备注：">
						<ElInput v-model="form.example_number" :readonly="isViewMode" />
					</ElFormItem>
				</ElForm>
			</template>
			<template #footer="{ reject, resolve }">
				<ElButton type="info" @click="dialogPromiseProps.onDialogClose({ reject, resolve })"> 关闭 </ElButton>
				<ElButton type="primary" @click="onConfirm({ reject, resolve })"> 确认 </ElButton>
			</template>
		</ComponentsDialogPromise>

		<!-- ===============表格部分============== -->
		<ComponentsTable :="componentsTableProps" @selection-change="selectedRows = $event">
			<template #bodyCell="{ prop }">
				<template v-if="prop === 'operation-bar'">
					<ElButton type="danger">删除</ElButton>
				</template>
			</template>
		</ComponentsTable>
		<!-- ==================分页组件部分================= -->
		<div class="demo-section">
			<Pagination
				:page-total="500"
				:page-sizes="[10, 20, 50, 100]"
				:pager-count="7"
				:current-page="1"
				:page-size="20"
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
