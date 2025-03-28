<template>
	<dinamicForm @form-finish="onFinish" :series="series" />
</template>
<script setup lang="ts">
definePage({
	meta: {
		menuType: "page",
		isSample: true,
		text: "动态表单演示",
		icon: "IconSetting",
	},
});

import { reactive } from "vue";
import dinamicForm from "../../components/base-form/index.vue";
import { DynamicComponentConfig } from "@/components/base-form/types";

// 表单配置
const series = reactive<DynamicComponentConfig[]>([
	{
		type: "input", //标识组件的类型
		props: {
			label: "出货人",
			dataKey: "name", // 接受表单的值的key
			placeholder: "请输入姓名",
			maxlength: 10,
			responsive: { md: 12, lg: 8 },
		},
	},
	{
		type: "select",
		props: {
			label: "货物类型",
			dataKey: "type",
			options: [
				{ label: "电子产品", value: 1 },
				{ label: "日用品", value: 2 },
				{ label: "食品", value: 3 },
			], //select组件的options
			responsive: { md: 12, lg: 8 },
		},
	},
	{
		type: "date",
		props: {
			label: "出货日期",
			dataKey: "date",
			type: "datetime",
			placeholder: "选择日期时间",
			format: "YYYY/MM/DD HH:mm:ss",
			valueFormat: "YYYY/MM/DD HH:mm:ss",
			responsive: { md: 12, lg: 8 },
		},
	},
	{
		type: "number",
		props: {
			label: "出货数量",
			dataKey: "count",
			min: 0,
			max: 100,
			step: 10,
			precision: 0,
			responsive: { md: 12, lg: 8 },
		},
	},
	{
		type: "table",
		props: {
			label: "库存信息表",
			dataKey: "countInfo",
			tableData: [], //表格的初始值
			columns: [
				{ dataKey: "address", label: "当前地址", editable: true },
				{ dataKey: "supplyType", label: "供应类型", editable: true },
				{ dataKey: "warehouse", label: "仓库", editable: true },
				{ dataKey: "manager", label: "负责人", editable: true },
			],
			responsive: { xs: 24, md: 24, lg: 24 },
		},
	},
]);

function onFinish(values: any) {
	console.log("拿到了表单数据", values);
}
</script>
