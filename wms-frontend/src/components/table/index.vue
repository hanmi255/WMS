<script lang="ts" setup generic="T extends Object, Column extends SimpleDataTableColumn<T>">
import { ref, computed, watch } from "vue";
import { merge } from "lodash-es";

/**
 * 简单的数据表格 props
 */
export interface SimpleDataTableProps<
	T extends Object,
	Column extends SimpleDataTableColumn<T> = SimpleDataTableColumn<T>,
> extends /* @vue-ignore */ OmitTableProps<T> {
	data: T[];
	/**
	 * 表格列配置
	 * @description
	 * 这是表格组件每一列的配置 是配置最繁忙的地方
	 */
	columns: Column[];

	/**
	 * 是否索引表格？
	 * @description
	 * 默认不提供索引表格，开启后，表格的第一列为索引列
	 * @default false
	 */
	isIndex?: boolean;

	/**
	 * 是否多选？
	 * @description
	 * 默认不开启多选
	 * @default false
	 */
	isMultipleSelect?: boolean;
}

const props = defineProps<SimpleDataTableProps<T, Column>>();

const emit = defineEmits<{
	(e: "selection-change", rows: T[]): void;
}>();

/** @see https://cn.vuejs.org/api/sfc-script-setup.html#defineslots */
defineSlots<{
	bodyCell(props: {
		//
		row: T;
		prop: SimpleDataTableColumnProp<T>;
		index: number;
		column: Column;
	}): any;
	table(): any;
}>();

/** 默认的表格配置 */
const defaultElTableProps = ref<DefaultTableProps<T>>({
	// 默认开启斑马纹
	stripe: true,
	// 默认开启边框
	border: true,
});

/** 默认的表格列配置 */
const defaultElTableColumnProps = ref<TableColumnProps>({
	// 表格列内容默认居中
	align: "center",
});

/** 增加默认配置字段的 props */
const propsComputed = computed(() => {
	return merge(
		{
			...defaultElTableProps.value,
		},
		{ ...props },
	);
});

/** 处理 isIndex 的表格列逻辑 */
function handleIsIndex() {
	/** 默认索引栏配置 */
	const defIndexBar: TableColumnIndexBar = {
		prop: "index-bar",
		label: "序号",
		width: 70,
		type: "index",
		index(index) {
			return index + 1;
		},
	};

	/** 项目内已经配置有的索引栏的对象 */
	let indexBar: SimpleDataTableColumn<T> | undefined;

	/** 在配置栏内找到索引栏 */
	function findIndexBar() {
		return propsComputed.value.columns.find((item) => item.prop === "index-bar");
	}

	/** 是否有索引栏？ */
	function hasIndexBar() {
		indexBar = findIndexBar();
		return !isUndefined(indexBar);
	}

	/** 是否配置了需要index配置 */
	function isIndex() {
		return propsComputed.value.isIndex;
	}

	/**
	 * 是否满足其中一个条件？
	 * 1. 需要配置位于顶部的索引栏
	 * 2. 存在用户自己定义的索引栏
	 */
	if (isConditionsSome([isIndex, hasIndexBar])) {
		if (isIndex()) {
			// 数组最顶部提供默认配置的索引栏
			propsComputed.value.columns.unshift(<Column>defIndexBar);
		}

		if (hasIndexBar()) {
			if (!isUndefined(indexBar)) {
				// 直接更改数组内的对象
				merge(defIndexBar, indexBar);
			}
		}
	}
}

/** 处理拓展表格列字段的逻辑 */
function expandColumns() {
	return propsComputed.value.columns.map((item) => merge({}, defaultElTableColumnProps.value, item));
}

/**
 * 处理多选的逻辑
 * @see https://element-plus.org/zh-CN/component/table.html#多选
 */
function handleSelectionChange(rows: T[]) {
	emit("selection-change", rows);
}

/** 处理 isMultipleSelect 是否多选的表格列逻辑 */
function handleSelection() {
	/** 默认选择栏配置 */
	const defSelectionBar: TableColumnSelectionBar = {
		type: "selection",
		prop: "selection-bar",
		width: 50,
	};

	/** 是否配置了需要多选配置 */
	function isMultipleSelect() {
		return propsComputed.value.isMultipleSelect;
	}

	if (isMultipleSelect()) {
		// 数组最顶部提供默认配置的选择栏
		propsComputed.value.columns.unshift(<Column>defSelectionBar);
	}
}

/**
 * 拓展字段后的表格列配置
 * @description
 * 增加额外的字段 补齐默认的字段
 */
const columns = computed(() => {
	handleIsIndex();
	handleSelection();
	return expandColumns();
});
</script>

<template>
	<section class="table-root">
		<el-table :="{ ...propsComputed, ...$attrs }" @selection-change="handleSelectionChange">
			<template v-for="(item, index) in columns" :key="item.prop">
				<!-- 如果是 索引栏 -->
				<template v-if="item.prop === 'index-bar'">
					<el-table-column :="item"> </el-table-column>
				</template>

				<!-- 如果是 多选栏 -->
				<template v-else-if="item.prop === 'selection-bar'">
					<el-table-column :="item"> </el-table-column>
				</template>

				<!-- 
					如果是 普通栏
					目前 操作栏 仅仅是对外暴露插槽，故不做判断
				-->
				<template v-else>
					<el-table-column :="item">
						<template #default="scope">
							<!-- 通过 bodyCell 插槽，传出行数据 row 以及列标识 prop -->
							<slot name="bodyCell" :row="scope.row" :prop="item.prop" :index="scope.$index" :column="item">
								{{ scope.row[item.prop] }}
							</slot>
						</template>
					</el-table-column>
				</template>
			</template>
		</el-table>
	</section>
</template>

<style lang="scss" scoped>
.table-root {
}
</style>
