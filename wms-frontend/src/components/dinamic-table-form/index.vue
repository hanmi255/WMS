<script lang="ts" setup generic="T extends Record<string, any>">
import { ref, defineProps, toRef, type Ref } from "vue";
import { cloneDeep, remove, isEqual, isEmpty } from "lodash-es";

import ComponentsTable, { type SimpleDataTableProps } from "components/table/index.vue";
import type { SimpleDataTableColumn } from "components/table/types";
import type {
	_OmitSimpleDataTableProps,
	EditableTableColumn,
	DinamicTableFormEmit,
} from "components/dinamic-table-form/types";
import { ElMessage } from "element-plus";

/**
 * 动态表格样式表单 props值
 * @version 2
 * @description
 */
export interface DinamicTableFormProps<
	T extends Record<string, any>,
	Column extends SimpleDataTableColumn<T> = EditableTableColumn<T>,
> extends /* @vue-ignore */ _OmitSimpleDataTableProps<T, Column> {
	/**
	 * 新行数据
	 * @description
	 * 新增一行时，所使用的默认行数据。
	 *
	 * 你可以提供一个填写有默认数据的对象，用于新增一行时的默认数据。
	 *
	 * 一般来说，这里的数据应该是业务意义的对象。拥有全部的字段，但是每个字段的取值均为业务意义上的空数据。
	 */
	newRowData: T;

	/**
	 * 被修改的数组
	 * @version 2
	 * @description
	 * 之前的字段名称为 `tableData`
	 */
	data: T[];

	/**
	 * 表格列配置
	 * @version 2
	 * @description
	 * 之前的数组类型是 `columsItem`
	 */
	columns: Column[];
}

const props = defineProps<DinamicTableFormProps<T>>();
const emit = defineEmits<DinamicTableFormEmit<T>>();

const { isIndex = true, isMultipleSelect = true } = props;

/** 增加固定的操作栏 */
const columns = computed(() => {
	props.columns.push({
		prop: "operation-bar",
		label: "操作",
		width: 60,
		editable: true,
	});
	return props.columns;
});

/**
 * 多选项
 * @description
 * 这里要做强制类型转换 详情请阅读此 issue
 * @see https://github.com/vuejs/core/issues/2136#issuecomment-908269949
 */
const multipleSelection = ref<T[]>([]) as Ref<T[]>;

/** 新增行 */
function addNewRow() {
	// eslint-disable-next-line vue/no-mutating-props
	props.data.push(cloneDeep(props.newRowData));
	console.log(" 新增行 ", props.data);
	emit("change-data", props.data);
}

/** 删除单行 */
function deleteRow(index: number) {
	// eslint-disable-next-line vue/no-mutating-props
	props.data.splice(index, 1);
	console.log(" 删除单行 ", props.data);
	emit("change-data", props.data);
}

/** 删除选中行 */
function deleteSelected() {
	if (isEmpty(multipleSelection.value)) {
		ElMessage.warning("请先选择要删除的行");
		return;
	}

	remove(props.data, (item) => multipleSelection.value.some((selectedItem) => isEqual(item, selectedItem)));
	console.log(" 删除选中行 ", props.data);
	emit("change-data", props.data);
}

/** 切换编辑状态 @deprecated */
function toggleEdit(row: { editing: boolean }) {
	row.editing = !row.editing;
}

/** 保存数据 @deprecated */
function handleSave(row: { editing: boolean }) {
	row.editing = false;
}

/** 处理多选 */
function handleSelectionChange(rows: T[]) {
	multipleSelection.value = rows;
}

function getEditable(column: EditableTableColumn<T>) {
	return column.editable;
}
</script>

<template>
	<div class="editable-table" style="width: 100%">
		<div class="table-actions">
			<el-button @click="addNewRow" type="primary"> 新增行 </el-button>
			<el-button @click="deleteSelected" type="danger"> 删除所选行 </el-button>
		</div>

		<ComponentsTable
			style="width: 100%"
			:="props"
			:is-index="isIndex"
			:columns="columns"
			:is-multiple-select="isMultipleSelect"
			empty-text="请新增行"
			@selection-change="handleSelectionChange"
		>
			<template #bodyCell="{ index, prop, row, column }">
				<!-- 操作栏 -->
				<template v-if="prop === 'operation-bar'">
					<el-button @click="deleteRow(index)" link type="danger"> 删除 </el-button>
				</template>

				<template v-if="prop !== 'index-bar' && prop !== 'operation-bar' && prop !== 'selection-bar'">
					<template v-if="getEditable(column)">
						<el-input v-model="row[prop]" />
					</template>
					<span v-else>{{ row[prop] }}</span>
				</template>
			</template>
		</ComponentsTable>
	</div>
</template>

<style lang="scss" scoped>
.editable-table {
	padding: 20px;
	background: #fff;
	box-shadow: 0 2px 12px 0 rgba(0, 0, 0, 0.1);
	border-radius: 8px;
}

.table-actions {
	margin-bottom: 15px;
}
</style>
