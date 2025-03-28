<template>
	<base-config-table title="工作状态配置" :columns="columns" :form-fields="formFields" :table-data="mockData" />
</template>

<script setup lang="ts">
import { reactive } from "vue";
import { Clock } from "@element-plus/icons-vue";
import BaseConfigTable from "../../base-config/components/BaseTable.vue";
// import { workStatusApi } from "@/api/personnel";

definePage({
	meta: {
		menuType: "page",
		text: "性别代码",
		icon: Clock,
	},
});

// 定义表格列
const columns = [
	{ prop: "statusCode", label: "工作状态代码", width: 150 },
	{ prop: "statusName", label: "工作状态名称", width: 200 },
];

// 定义表单字段
const formFields = [
	{
		prop: "statusCode",
		label: "工作状态代码",
		type: "input",
		rules: [{ required: true, message: "请输入工作状态代码", trigger: "blur" }],
	},
	{
		prop: "statusName",
		label: "工作状态名称",
		type: "input",
		rules: [{ required: true, message: "请输入工作状态名称", trigger: "blur" }],
	},
];

// API方法
// const api = {
//   list: workStatusApi.getList,
//   add: workStatusApi.add,
//   update: workStatusApi.update,
//   delete: workStatusApi.delete,
//   batchDelete: workStatusApi.batchDelete,
//   export: workStatusApi.export,
//   import: workStatusApi.import,
// };

// 模拟数据
const mockData = [
	{
		id: 1,
		statusCode: "WS001",
		statusName: "在岗",
	},
	{
		id: 2,
		statusCode: "WS002",
		statusName: "休假",
	},
	{
		id: 3,
		statusCode: "WS003",
		statusName: "出差",
	},
	{
		id: 4,
		statusCode: "WS004",
		statusName: "培训",
	},
	{
		id: 5,
		statusCode: "WS005",
		statusName: "会议",
	},
	{
		id: 6,
		statusCode: "WS006",
		statusName: "临时外出",
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
