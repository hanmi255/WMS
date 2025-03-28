<template>
	<base-config-table
		title="品质代码配置"
		:columns="columns"
		:form-fields="formFields"
		:table-data="mockData"
		:show-edit-button="false"
	/>
</template>

<script setup lang="ts">
import { reactive } from "vue";
import { Medal } from "@element-plus/icons-vue";
import BaseConfigTable from "../components/BaseTable.vue";
// import { qualityCodeApi } from "@/api/quality";
definePage({
	meta: {
		menuType: "page",
		text: "品质代码",
		icon: Medal,
	},
});
// 定义表格列
const columns = [
	{ prop: "codeValue", label: "品质代码", width: 120 },
	{ prop: "codeName", label: "品质代码名称", width: 120 },
];

// 定义表单字段
const formFields = [
	{
		prop: "codeValue",
		label: "品质代码",
		type: "input",
		rules: [{ required: true, message: "请输入品质代码", trigger: "blur" }],
	},
	{
		prop: "codeName",
		label: "品质代码名称",
		type: "input",
		rules: [{ required: true, message: "请输入品质代码名称", trigger: "blur" }],
	},
];

// API方法
// const api = {
// 	list: qualityCodeApi.getList,
// 	add: qualityCodeApi.add,
// 	update: qualityCodeApi.update,
// 	delete: qualityCodeApi.delete,
// 	batchDelete: qualityCodeApi.batchDelete,
// 	export: qualityCodeApi.export,
// 	import: qualityCodeApi.import,
// };

const mockData = [
	{
		id: 1,
		codeValue: "QC001",
		codeName: "一级品",
	},
	{
		id: 2,
		codeValue: "QC002",
		codeName: "二级品",
	},
	{
		id: 3,
		codeValue: "QC003",
		codeName: "三级品",
	},
	{
		id: 4,
		codeValue: "QC004",
		codeName: "不良品",
	},
	{
		id: 5,
		codeValue: "QC005",
		codeName: "待处理品",
	},
];
</script>
<style scoped lang="scss">
.title {
	margin-bottom: 20px;
	font-size: 20px;
	font-weight: bold;
}
</style>
