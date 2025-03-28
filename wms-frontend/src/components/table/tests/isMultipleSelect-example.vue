<script lang="ts" setup>
import { ref, computed } from "vue";

import { type TestBuziDataForTable, testBuziDataForTable } from "./data";
import ComponentsTable from "components/table/index.vue";
import type { SimpleDataTableColumn } from "components/table/types";

const componentsTableProps = ref<SimpleDataTableProps<TestBuziDataForTable>>({
	isIndex: true,
	isMultipleSelect: true,
	data: testBuziDataForTable,
	columns: [
		{ prop: "name", label: "姓名", width: 70 },
		{ prop: "age", label: "年龄" },
	],
});

const multipleSelectRows = ref<TestBuziDataForTable[]>([]);

const componentsTableSelect = computed<SimpleDataTableProps<TestBuziDataForTable>>(() => {
	return {
		isIndex: true,
		emptyText: "请选择数据",
		data: multipleSelectRows.value,
		columns: [
			{ prop: "name", label: "姓名", width: 70 },
			{ prop: "age", label: "年龄" },
		],
	};
});
</script>

<template>
	<section>
		<ElRow :gutter="10">
			<ElCol :span="12">
				<h2>含有选择栏的表格</h2>
				<ComponentsTable :="componentsTableProps" @selection-change="multipleSelectRows = $event"></ComponentsTable>
			</ElCol>

			<ElCol :span="12">
				<h2>选择的行</h2>
				<ComponentsTable :="componentsTableSelect"></ComponentsTable>
			</ElCol>
		</ElRow>
	</section>
</template>
