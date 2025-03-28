<template>
	<base-config-table title="地区信息" :columns="columns" :form-fields="formFields" :table-data="mockData" />
</template>

<script setup lang="ts">
import { reactive } from "vue";
import { UserFilled } from "@element-plus/icons-vue";
import BaseConfigTable from "../../base-config/components/BaseTable.vue";
import { id } from "element-plus/es/locale/index.mjs";

definePage({
	meta: {
		menuType: "page",
		text: "地区信息",
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
		prop: "city_code",
		label: "地区代码",
		type: "input",
		rules: [{ required: true, message: "请输入地区代码", trigger: "blur" }],
	},
	{
		prop: "city_name",
		label: "地区名称",
		type: "input",
		rules: [{ required: true, message: "请输入地区名称", trigger: "blur" }],
	},
	{
		prop: "city_serc",
		label: "地区助记码",
		type: "input",
		rules: [{ required: true, message: "请输入地区助记码", trigger: "blur" }],
	},
	{
		prop: "city_type",
		label: "城市类型",
		type: "input",
		rules: [{ required: true, message: "请输入城市类型", trigger: "blur" }],
	},
	{
		prop: "barea_name",
		label: "片区信息",
		type: "input",
		rules: [{ required: true, message: "请输入片区信息", trigger: "blur" }],
	},
	{
		prop: "area_name",
		label: "大区信息",
		type: "input",
		rules: [{ required: true, message: "请输入大区信息", trigger: "blur" }],
	},
	{
		prop: "city_del",
		label: "停用",
		type: "select",
		options: [
			{ label: "启用", value: "0" },
			{ label: "停用", value: "1" },
		],
	},
];
const mockData = [
	{
		id: 1,
		city_code: "213",
		city_name: "河南",
		city_serc: "hn",
		city_type: "city1",
		barea_name: "bar1",
		area_name: "da21",
		city_del: "0",
	},
];
const columns = [
	{ prop: "city_code", label: "地区代码", width: "150px" },
	{ prop: "city_name", label: "地区名称", width: "150px" },
	{ prop: "city_serc", label: "地区助记码", width: "150px" },
	{ prop: "city_type", label: "城市类型", width: "150px" },
	{ prop: "barea_name", label: "片区信息", width: "150px" },
	{ prop: "area_name", label: "大区信息", width: "150px" },
	{ prop: "city_del", label: "停用", width: "150px" },
];
</script>

<style scoped lang="scss">
.title {
	margin-bottom: 20px;
	font-size: 20px;
	font-weight: bold;
}
</style>
