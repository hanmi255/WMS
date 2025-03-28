<script lang="ts" setup>
import { ref } from "vue";
import TableTitle from "@/components/table-title/TableTitle.vue";
import ComponentsTable from "components/table/index.vue";

definePage({
	meta: {
		// 页面必须要填写为page类型
		menuType: "page",
		text: "批量收货",
		icon: "IconSetting",
	},
});

// 发送到子组件的数据
const titleData = ref({
	unfold: true,
	rightButton: true,
	contentList: [
		{
			name: "到货通知单",
			type: "AddSininput",
			content: ["", ""],
		},
		{
			name: "客户订单号",
			type: "AddSininput",
			content: ["", ""],
		},
		{
			name: "备注",
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
	],
	bottomList: [
		{
			name: "选择验收",
			iconType: "Edit",
		},
		{
			name: "验收保存",
			iconType: "DocumentChecked",
		},
		{
			name: "取消验收",
			iconType: "Back",
		},
	],
});

// 表格内数据
const data = [
	{
		creatorName: "张三",
		creationTime: "2023-10-01",
		noticeNumber: "NT0001",
		clientOrderNumber: "CO0001",
		remark: "无",
		productCode: "P001",
		productName: "商品A",
		reservedQuantity: 100,
		registeredQuantity: 80,
		unreceivedQuantity: 20,
		productionDate: "2023-09-15",
		batch: "Batch001",
	},
	{
		creatorName: "李四",
		creationTime: "2023-10-02",
		noticeNumber: "NT0002",
		clientOrderNumber: "CO0002",
		remark: "需要跟进",
		productCode: "P002",
		productName: "商品B",
		reservedQuantity: 150,
		registeredQuantity: 100,
		unreceivedQuantity: 50,
		productionDate: "2023-09-10",
		batch: "Batch002",
	},
	{
		creatorName: "王五",
		creationTime: "2023-10-03",
		noticeNumber: "NT0003",
		clientOrderNumber: "CO0003",
		remark: "急单",
		productCode: "P003",
		productName: "商品C",
		reservedQuantity: 200,
		registeredQuantity: 200,
		unreceivedQuantity: 0,
		productionDate: "2023-09-20",
		batch: "Batch003",
	},
];

const tableProps = ref({
	data: data,
	isIndex: true,
	isMultipleSelect: true,
	columns: [
		{ prop: "operation-bar", label: "操作", width: "80px" },
		{ prop: "creatorName", label: "创建人名称", width: "100px" },
		{ prop: "creationTime", label: "创建日期", width: "100px" },
		{ prop: "noticeNumber", label: "进货通知单号", width: "100px" },
		{ prop: "clientOrderNumber", label: "客户订单号", width: "100px" },
		{ prop: "remark", label: "备注", width: "90px" },
		{ prop: "productCode", label: "商品编码", width: "120px" },
		{ prop: "productName", label: "商品名称", width: "80px" },
		{ prop: "reservedQuantity", label: "预约数量", width: "100px" },
		{ prop: "registeredQuantity", label: "已登记数量", width: "100px" },
		{ prop: "unreceivedQuantity", label: "未收货数量", width: "100px" },
		{ prop: "productionDate", label: "生产日期", width: "120px" },
		{ prop: "batch", label: "批次", width: "100px" },
	],
});
</script>

<template>
	<h1>批量收货</h1>
	<TableTitle v-model="titleData" class="title" @user-click="userChildClick" />
	<ComponentsTable v-bind="tableProps">
		<template #bodyCell="{ prop, row }">
			<template v-if="prop === 'operation-bar'">
				<ElButton type="primary" size="small">验收</ElButton>
			</template>
		</template>
	</ComponentsTable>
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
