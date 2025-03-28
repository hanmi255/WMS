<script lang="ts" setup>
import { ref } from "vue";
import TableTitle from "@/components/table-title/TableTitle.vue";
import ComponentsTable from "components/table/index.vue";

definePage({
	meta: {
		// 页面必须要填写为page类型
		menuType: "page",
		text: "进货通知明细",
		icon: "IconSetting",
	},
});

// 发送到子组件的数据
const titleData = ref({
	unfold: true,
	rightButton: true,
	contentList: [
		{
			name: "通知单号",
			type: "AddSininput",
			content: ["", ""],
		},
		{
			name: "客户编码",
			type: "AddSininput",
			optionData: ["", ""],
		},
		{
			name: "客户名称",
			type: "AddSininput",
			content: ["", ""],
		},
		{
			name: "通知单状态",
			type: "AddSininput",
			content: ["", ""],
		},
		{
			name: "商品编码",
			type: "AddSininput",
			content: ["", ""],
		},
		{
			name: "商品名称",
			type: "AddSininput",
			content: ["", ""],
		},
		{
			name: "客户订单号",
			type: "AddSininput",
			content: ["", ""],
		},
		{
			name: "生产日期",
			type: "AddCal",
			content: ["", ""],
			optionData: ["", ""],
		},
	],
	bottomList: [
		{
			name: "导出excle",
			iconType: "Bottom",
		},
	],
});

// 表格内数据
const data = [
	{
		noticeNumber: "NT001",
		customerCode: "CUST001",
		customerName: "客户A",
		noticeStatus: "待处理",
		productCode: "PROD001",
		productName: "商品A",
		noticeQuantity: 100,
		acceptanceQuantity: 80,
		unit: "箱",
		volumeCm3: 500,
		weightKg: 10,
		customerOrderNumber: "CO001",
		baseUnitQuantity: 1000,
		baseUnit: "件",
		productionDate: "2023-09-01",
	},
	{
		noticeNumber: "NT002",
		customerCode: "CUST002",
		customerName: "客户B",
		noticeStatus: "已完成",
		productCode: "PROD002",
		productName: "商品B",
		noticeQuantity: 50,
		acceptanceQuantity: 50,
		unit: "箱",
		volumeCm3: 300,
		weightKg: 5,
		customerOrderNumber: "CO002",
		baseUnitQuantity: 500,
		baseUnit: "件",
		productionDate: "2023-09-15",
	},
	{
		noticeNumber: "NT003",
		customerCode: "CUST003",
		customerName: "客户C",
		noticeStatus: "已取消",
		productCode: "PROD003",
		productName: "商品C",
		noticeQuantity: 200,
		acceptanceQuantity: 0,
		unit: "箱",
		volumeCm3: 800,
		weightKg: 15,
		customerOrderNumber: "CO003",
		baseUnitQuantity: 2000,
		baseUnit: "件",
		productionDate: "2023-08-20",
	},
];

const tableProps = ref({
	data: data,
	isIndex: true,
	columns: [
		{ prop: "noticeNumber", label: "通知单号", width: "90px" },
		{ prop: "customerCode", label: "客户编码", width: "100px" },
		{ prop: "customerName", label: "客户名称", width: "100px" },
		{ prop: "noticeStatus", label: "通知单状态", width: "100px" },
		{ prop: "productCode", label: "商品编码", width: "100px" },
		{ prop: "productName", label: "商品名称", width: "80px" },
		{ prop: "noticeQuantity", label: "通知单数量", width: "60px" },
		{ prop: "acceptanceQuantity", label: "验收数量", width: "60px" },
		{ prop: "unit", label: "单位", width: "60px" },
		{ prop: "volumeCm3", label: "体积CM3", width: "60px" },
		{ prop: "weightKg", label: "重量KG", width: "60px" },
		{ prop: "customerOrderNumber", label: "客户订单号", width: "100px" },
		{ prop: "baseUnitQuantity", label: "基本单位数量", width: "120px" },
		{ prop: "baseUnit", label: "基本单位", width: "90px" },
		{ prop: "productionDate", label: "生产日期", width: "120px" },
	],
});
</script>

<template>
	<h1>进货通知明细</h1>
	<TableTitle v-model="titleData" class="title" @user-click="userChildClick" />
	<ComponentsTable v-bind="tableProps"> </ComponentsTable>
	<el-pagination
		style="margin-top: 20px"
		v-model:current-page="currentPage4"
		v-model:page-size="pageSize4"
		:page-sizes="[10, 20, 30]"
		:size="size"
		:disabled="disabled"
		:background="background"
		layout="total, sizes, prev, pager, next, jumper"
		:total="400"
		@size-change="handleSizeChange"
		@current-change="handleCurrentChange"
	/>
</template>

<style lang="scss" scoped></style>
