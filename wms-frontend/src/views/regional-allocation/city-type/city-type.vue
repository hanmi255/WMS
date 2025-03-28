<template>
	<base-config-table title="城市分类" :columns="columns" :form-fields="formFields" :table-data="mockData" />
</template>

<script setup lang="ts">
import { reactive } from "vue";
import { UserFilled } from "@element-plus/icons-vue";
import BaseConfigTable from "../../base-config/components/BaseTable.vue";
import { id } from "element-plus/es/locale/index.mjs";

definePage({
	meta: {
		menuType: "page",
		text: "城市分类",
		icon: UserFilled,
	},
});

const formFields = [
	{
		prop: "id",
		label: "序号",
		type: "input",
		rules: [{ required: true, message: "请输入序号", trigger: "blur" }],
	},
	{
		prop: "city_type_code",
		label: "城市类型代码",
		type: "input",
		rules: [{ required: true, message: "请输入城市类型代码", trigger: "blur" }],
	},
	{
		prop: "city_type_name",
		label: "城市类型名称",
		type: "input",
		rules: [{ required: true, message: "请输入城市类型名称", trigger: "blur" }],
	},
];
const mockData = [{ id: 1, city_type_code: "1", city_type_name: "城市一" }];
const columns = [
	{ prop: "city_type_code", label: "城市类型代码", width: "400px" },
	{ prop: "city_type_name", label: "城市类型名称", width: "400px" },
];
</script>

<style scoped lang="scss">
.title {
	margin-bottom: 20px;
	font-size: 20px;
	font-weight: bold;
}
</style>
