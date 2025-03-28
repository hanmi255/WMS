<script lang="ts" setup>
import { ref } from "vue";
import { type TestBuziDataForTable, testBuziDataForTable } from "./data";
import ComponentsTable from "components/table/index.vue";

const componentsTableProps = ref<SimpleDataTableProps<TestBuziDataForTable>>({
	isIndex: true,
	data: testBuziDataForTable,
	columns: [
		{ prop: "name", label: "姓名", width: 70 },
		{ prop: "age", label: "年龄" },
	],
});
</script>

<template>
	<section>
		<ComponentsTable :="componentsTableProps"></ComponentsTable>
	</section>
</template>
