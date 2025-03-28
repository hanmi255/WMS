<template>
	<base-config-table title="片区信息" :columns="columns" :form-fields="formFields" :table-data="mockData" />
</template>

<script setup lang="ts">
import { reactive } from "vue";
import { UserFilled } from "@element-plus/icons-vue";
import BaseConfigTable from "../../base-config/components/BaseTable.vue";
import { id } from "element-plus/es/locale/index.mjs";

definePage({
	meta: {
		menuType: "page",
		text: "片区信息",
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
		prop: "region_code",
		label: "片区代码",
		type: "input",
		rules: [{ required: true, message: "请输入片区代码", trigger: "blur" }],
	},
	{
		prop: "region_name",
		label: "片区名称",
		type: "input",
		rules: [{ required: true, message: "请输入片区名称", trigger: "blur" }],
	},
	{
		prop: "region_rdata",
		label: "回单时限",
		type: "input",
		rules: [{ required: true, message: "请输入回单时限", trigger: "blur" }],
	},
];
const mockData = [{ id: 1, region_code: "213", region_name: "321", region_rdata: "123" }];
const columns = [
	{ prop: "region_code", label: "片区代码", width: "250px" },
	{ prop: "region_name", label: "片区名称", width: "250px" },
	{ prop: "region_rdata", label: "回单时限", width: "250px" },
];
</script>

<style scoped lang="scss">
.title {
	margin-bottom: 20px;
	font-size: 20px;
	font-weight: bold;
}
</style>
