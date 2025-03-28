<template>
	<div class="editable-data-grid">
		<div class="toolbar">
			<div class="leftb">
				<!-- 单行完整编辑 -->
				<el-button type="primary" plain :icon="Edit" @click="handleSingleRowEdit">编辑</el-button>
				<el-button type="info" plain :icon="View" @click="handleView">查看</el-button>
				<el-button type="success" plain :icon="Download" @click="handleExport">导出</el-button>
				<!-- 多行特定字段编辑 -->
				<el-button type="warning" plain :icon="EditPen" @click="handleMultiRowEdit">选择修改</el-button>
				<el-button type="success" plain :icon="Check" :disabled="!isEditing" @click="handleSave">修改保存</el-button>
				<el-button type="danger" plain :icon="Close" :disabled="!isEditing" @click="handleCancel">取消修改</el-button>
			</div>
			<div class="rightb">
				<el-button type="primary" plain :icon="Search">查询</el-button>
				<el-button type="danger" plain :icon="RefreshRight">重置</el-button>
			</div>
		</div>
		<el-table ref="tableRef" :data="dataSource" border style="width: 100%" @selection-change="handleSelectionChange">
			<!-- <el-table-column type="index" label="序号" width="50" align="center" :index="calculateIndex" fixed />
			<el-table-column type="selection" width="55" align="center" fixed /> -->
			<!-- 固定选择框列 -->
			<el-table-column type="selection" width="55" align="center" fixed />
			<!-- 固定序号列 -->
			<el-table-column type="index" label="序号" width="55" align="center" :index="calculateIndex" fixed />

			<el-table-column
				v-for="col in columns.filter((c) => !c.hidden)"
				:key="col.field"
				:prop="col.field"
				:label="col.title"
				:width="col.width"
				align="center"
			>
				<template #default="{ row }">
					<template v-if="editingRows.has(row.id) && col.editable && editMode === 'multi'">
						<el-input
							v-model="editedData.get(row.id)[col.field]"
							@input="(val) => handleCellChange(row, col.field, val)"
						/>
					</template>
					<template v-else>
						<span>{{ col.formatter ? col.formatter(row[col.field]) : row[col.field] }}</span>
					</template>
				</template>
			</el-table-column>
		</el-table>

		<!-- 单行编辑弹窗 -->
		<el-dialog
			v-model="dialogVisible"
			:title="dialogTitle"
			width="70%"
			:close-on-click-modal="false"
			:close-on-press-escape="false"
			draggable
			:destroy-on-close="true"
			class="detail-dialog"
		>
			<el-form :model="currentEditRow" label-width="120px" class="detail-form">
				<el-row :gutter="20">
					<el-col v-for="col in columns.filter((c) => !c.hidden)" :key="col.field" :span="12">
						<el-form-item :label="col.title">
							<template v-if="col.field === 'productionDate' || col.field === 'createDate'">
								<el-date-picker
									v-model="currentEditRow[col.field]"
									type="date"
									placeholder="选择日期"
									format="YYYY-MM-DD"
									:disabled="dialogMode === 'view'"
									class="full-width"
								/>
							</template>
							<template v-else>
								<el-input v-model="currentEditRow[col.field]" :disabled="dialogMode === 'view'" class="full-width" />
							</template>
						</el-form-item>
					</el-col>
				</el-row>
			</el-form>
			<template #footer>
				<span class="dialog-footer">
					<el-button @click="dialogVisible = false">取消</el-button>
					<el-button v-if="dialogMode === 'edit'" type="primary" @click="saveSingleRow">保存</el-button>
				</span>
			</template>
		</el-dialog>
	</div>
</template>

<script setup lang="ts">
import { ref, defineProps, defineEmits, computed } from "vue";
import { ElMessage } from "element-plus";
import { Edit, View, Download, EditPen, Check, Close, Search, RefreshRight } from "@element-plus/icons-vue";
interface Column {
	title: string;
	field: string;
	width?: number;
	editable?: boolean;
	hidden?: boolean;
	formatter?: (val: any) => string;
}

interface TableData {
	id: string | number;
	[key: string]: any;
}

//
const props = defineProps<{
	columns: Column[]; //列配置
	dataSource: TableData[]; //数据源
	title?: string; //标题
	currentPage?: number;
	pageSize?: number;
}>();

const emit = defineEmits(["save", "edit", "cancel", "export", "view"]);

const calculateIndex = (index: number) => {
	const currentPage = 1;
	const pageSize = 10;
	return (currentPage - 1) * pageSize + index + 1;
};
// 编辑状态管理
const tableRef = ref();
const editingRows = ref<Set<string | number>>(new Set());
const selectedRows = ref<TableData[]>([]);
const editedData = ref<Map<string | number, any>>(new Map());
const editMode = ref<"single" | "multi">("multi");
const isEditing = computed(() => editingRows.value.size > 0);
const currentClickRow = ref<TableData | null>(null);

// 弹窗
const dialogMode = ref<"edit" | "view">("edit");
const dialogVisible = ref(false);
const dialogTitle = ref("编辑数据");
const currentEditRow = ref<any>({});
const currentEditId = ref<string | number | null>(null);

// 处理表格选择变化
const handleSelectionChange = (rows: TableData[]) => {
	selectedRows.value = rows;
};

// 单行完整编辑
const handleSingleRowEdit = () => {
	if (selectedRows.value.length !== 1) {
		ElMessage.warning("请选择一条记录进行编辑");
		return;
	}

	const row = selectedRows.value[0];
	currentEditId.value = row.id;
	currentEditRow.value = { ...row };
	dialogTitle.value = `编辑 - ${row.id}`;
	dialogMode.value = "edit";

	dialogVisible.value = true;
	editMode.value = "single";
};

// 保存单行编辑
const saveSingleRow = () => {
	if (currentEditId.value === null) return;

	const updatedRow = { ...currentEditRow.value };
	emit("save", [updatedRow]);
	dialogVisible.value = false;
	currentEditId.value = null;
};

// 多行特定字段编辑
const handleMultiRowEdit = () => {
	if (selectedRows.value.length === 0) {
		ElMessage.warning("请选择要编辑的行");
		return;
	}

	editMode.value = "multi";
	selectedRows.value.forEach((row) => {
		editingRows.value.add(row.id);
		editedData.value.set(row.id, { ...row });
	});

	emit(
		"edit",
		selectedRows.value.map((row) => row.id),
	);
};

// 保存多行编辑
const handleSave = () => {
	if (editMode.value === "multi") {
		const updatedRows = Array.from(editingRows.value).map((id) => editedData.value.get(id));
		emit("save", updatedRows);
		editingRows.value.clear();
		editedData.value.clear();
	}
};

// 取消修改
const handleCancel = () => {
	editingRows.value.clear();
	editedData.value.clear();
	editMode.value = "multi";
	tableRef.value?.clearSelection();
	emit("cancel");
};

// 导出
const handleExport = () => {
	emit("export");
};

// 查看详情
const handleView = () => {
	if (selectedRows.value.length !== 1) {
		ElMessage.warning("请选择一条记录查看");
		return;
	}
	// emit("view", selectedRows.value[0].id);
	const row = selectedRows.value[0];
	currentEditId.value = row.id;
	currentEditRow.value = { ...row };
	dialogTitle.value = `查看详情 - ${row.id}`;
	dialogMode.value = "view";
	dialogVisible.value = true;
};

// 处理单元格值变化
const handleCellChange = (row: TableData, field: string, value: any) => {
	const editedRow = editedData.value.get(row.id);
	if (editedRow) {
		editedRow[field] = value;
	}
};
</script>

<style scoped lang="scss">
.detail-dialog :deep(.el-dialog__header) {
	border-bottom: 1px solid #ebeef5;
	padding: 15px 20px;
	background-color: #f5f7fa;
}
.detail-dialog :deep(.el-dialog__body) {
	padding: 20px 30px;
	max-height: 60vh;
	overflow-y: auto;
}
.detail-dialog :deep(.el-dialog__footer) {
	border-top: 1px solid #ebeef5;
	padding: 15px 20px;
}
.detail-form .el-form-item {
	margin-bottom: 18px;
}
.full-width {
	width: 100%;
}
.detail-form :deep(.is-disabled) {
	background-color: #f5f7fa;
	border-color: #e4e7ed;
	color: #606266;
	cursor: not-allowed;
}
.detail-form .el-row {
	margin-bottom: 10px;
}
.detail-form .el-col {
	margin-bottom: 5px;
}
.editable-data-grid {
	.toolbar {
		margin-bottom: 16px;
		display: flex;
		justify-content: space-between;
		align-items: center;
		.leftb {
			display: flex;
			align-items: center;
		}
		.rightb {
			display: flex;
			align-items: center;
		}
		::deep(.el-button) {
			margin: 0;
			.el-icon {
				margin-right: 4px;
			}
		}
		// ::deep(.el-button-group) {
		// 	.el-button:not(:last-child) {
		// 		margin-right: -1px;
		// 	}
		// }
	}
}

.dialog-footer {
	display: flex;
	justify-content: flex-end;

	.el-button {
		margin-left: 8px;
	}
}
</style>
