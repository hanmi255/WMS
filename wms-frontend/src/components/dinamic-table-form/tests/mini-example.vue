<script lang="ts" setup>
import { ref, computed } from "vue";
import ComponentsDinamicTableForm, { type DinamicTableFormProps } from "components/dinamic-table-form/index.vue";
import ComponentsTable, { type SimpleDataTableProps } from "components/table/index.vue";

interface TestBuzi {
	name: string;
	age: number;
}

const dataAsForm = ref<TestBuzi[]>([
	{ name: "张三", age: 18 },
	{ name: "李四", age: 20 },
	{ name: "王五", age: 22 },
]);

const props = ref<DinamicTableFormProps<TestBuzi>>({
	label: "用户年龄修改表",
	newRowData: { name: "", age: 0 },
	data: dataAsForm.value,
	columns: [
		{ prop: "name", label: "姓名", editable: true },
		{ prop: "age", label: "年龄", editable: true },
	],
});

const changData = ref<TestBuzi[]>([]);

const changDataTableProps = computed<SimpleDataTableProps<TestBuzi>>(() => {
	return {
		data: changData.value,
		columns: [
			{ prop: "name", label: "姓名" },
			{ prop: "age", label: "年龄" },
		],
	};
});
</script>

<template>
	<section>
		<ElRow :gutter="10">
			<ElCol :span="12">
				<h1>表单</h1>
				<ComponentsDinamicTableForm :="props" @change-data="changData = $event" />
			</ElCol>

			<ElCol :span="12">
				<h1>已选择的数据</h1>
				<ComponentsTable :="changDataTableProps" />
			</ElCol>
		</ElRow>
	</section>
</template>
