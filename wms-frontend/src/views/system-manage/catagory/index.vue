<template>
	<base-config-table title="分类管理" :columns="columns" :form-fields="formFields" :table-data="mockData" />
</template>

<script setup lang="ts">
import { reactive } from "vue";
import { UserFilled } from "@element-plus/icons-vue";
import BaseConfigTable from "../../base-config/components/BaseTable1.vue";
// import { employmentStatusApi } from "@/api/personnel";

definePage({
	meta: {
		menuType: "page",
		text: "分类管理",
		icon: UserFilled,
	},
});

// 定义表格列
const columns = [
	{ prop: "statusCode", label: "类型名称", width: 150 },
	{ prop: "statusName", label: "图标", width: 200 },
	{ prop: "statusName", label: "类型编码", width: 200 },
];

// 定义表单字段
const formFields = [
	{
		prop: "statusCode",
		label: "类型名称",
		type: "input",
		rules: [{ required: true, message: "请输入类型名称", trigger: "blur" }],
	},
	{
		prop: "statusName",
		label: "图标",
		type: "input",
		rules: [{ required: true, message: "", trigger: "select" }],
	},
	{
		prop: "statusName",
		label: "所属上级",
		type: "input",
		rules: [{ required: true, message: "", trigger: "select" }],
	},
];

// API方法
// const api = {
//   list: employmentStatusApi.getList,
//   add: employmentStatusApi.add,
//   update: employmentStatusApi.update,
//   delete: employmentStatusApi.delete,
//   batchDelete: employmentStatusApi.batchDelete,
//   export: employmentStatusApi.export,
//   import: employmentStatusApi.import,
// };

// 模拟数据
const mockData = [
	{
		id: 1,
		statusCode: "ES001",
		statusName: "在职",
	},
	{
		id: 2,
		statusCode: "ES002",
		statusName: "离职",
	},
	{
		id: 3,
		statusCode: "ES003",
		statusName: "试用期",
	},
	{
		id: 4,
		statusCode: "ES004",
		statusName: "实习",
	},
	{
		id: 5,
		statusCode: "ES005",
		statusName: "退休",
	},
	{
		id: 6,
		statusCode: "ES006",
		statusName: "停职",
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
