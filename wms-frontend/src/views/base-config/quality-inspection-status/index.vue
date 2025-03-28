<template>
	<base-config-table title="品检状态配置" :columns="columns" :form-fields="formFields" :table-data="mockData" />
</template>

<script setup lang="ts">
import { reactive } from "vue";
import { CircleCheck } from "@element-plus/icons-vue";
import BaseConfigTable from "../components/BaseTable.vue";
// import { qualityInspectionStatusApi } from "@/api/quality";
definePage({
	meta: {
		menuType: "page",
		text: "品检状态",
		icon: CircleCheck,
	},
});
// 定义表格列
const columns = [
	{ prop: "statusCode", label: "品检状态代码", width: 120 },
	{ prop: "statusName", label: "品检状态名称", width: 120 },
];

// 定义表单字段
const formFields = [
	{
		prop: "statusCode",
		label: "品检状态代码",
		type: "input",
		rules: [{ required: true, message: "请输入品检状态代码", trigger: "blur" }],
	},
	{
		prop: "statusName",
		label: "品检状态名称",
		type: "input",
		rules: [{ required: true, message: "请输入品检状态名称", trigger: "blur" }],
	},
];

// API方法
// const api = {
// 	list: qualityInspectionStatusApi.getList,
// 	add: qualityInspectionStatusApi.add,
// 	update: qualityInspectionStatusApi.update,
// 	delete: qualityInspectionStatusApi.delete,
// 	batchDelete: qualityInspectionStatusApi.batchDelete,
// 	export: qualityInspectionStatusApi.export,
// 	import: qualityInspectionStatusApi.import,
// };

const mockData = [
	{
		id: 1,
		statusCode: "QIS001",
		statusName: "待检",
	},
	{
		id: 2,
		statusCode: "QIS002",
		statusName: "合格",
	},
	{
		id: 3,
		statusCode: "QIS003",
		statusName: "不合格",
	},
	{
		id: 4,
		statusCode: "QIS004",
		statusName: "部分合格",
	},
	{
		id: 5,
		statusCode: "QIS005",
		statusName: "待复检",
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
