<script lang="ts" setup>
import { ref } from "vue";
import TableTitle from "@/components/table-title/TableTitle.vue";
import ComponentsTable from "components/table/index.vue";

definePage({
	meta: {
		// 页面必须要填写为page类型
		menuType: "page",
		text: "其他入库",
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
			name: "预计到货时间",
			type: "AddDbcal",
			content: ["", ""],
		},
		{
			name: "客户订单号",
			type: "AddSininput",
			content: ["", ""],
		},
		{
			name: "车号",
			type: "AddSininput",
			content: ["", ""],
		},
		{
			name: "司机",
			type: "AddSininput",
			content: ["", ""],
		},
		{
			name: "司机电话",
			type: "AddSininput",
			content: ["", ""],
		},
		{
			name: "订单类型",
			type: "AddCheckBox",
			content: ["", ""],
			optionData: ["越库通知", "其他入库", "出库通知", "其他出库", "出库通知", "出库通知", "出货通知"],
		},
		{
			name: "月台",
			type: "AddCheckBox",
			content: ["", ""],
			optionData: ["213", "test"],
		},
		{
			name: "单据状态",
			type: "AddSininput",
			content: ["", ""],
		},
	],
	bottomList: [
		{
			name: "录入",
			iconType: "Add",
		},
		{
			name: "编辑",
			iconType: "Edit",
		},
		{
			name: "查看",
			iconType: "Search",
		},
	],
});

// 表格内数据
const data = [
	{
		name: "张三",
		creatTime: "2023-10-01",
		noticeNumber: "ND123456",
		code: "H001",
		arriveTime: "2023-10-05 12:00:00",
		clientNumber: "CO123",
		car: "车123",
		driver: "李四",
		driverNumber: "13800138000",
		orderType: "其他入库",
		platform: "月台A",
		remark: "无备注",
	},
	{
		name: "李四",
		creatTime: "2023-10-02",
		noticeNumber: "ND123457",
		code: "H002",
		arriveTime: "2023-10-06 14:00:00",
		clientNumber: "CO124",
		car: "车124",
		driver: "王五",
		driverNumber: "13900139000",
		orderType: "其他入库",
		platform: "月台B",
		remark: "紧急处理",
	},
];

const tableProps = ref({
	data: data,
	isIndex: true,
	isMultipleSelect: true,
	columns: [
		{ prop: "name", label: "创建人名称", width: "60px" },
		{ prop: "creatTime", label: "创建日期", width: "100px" },
		{ prop: "operation-bar", label: "操作", width: "240px" },
		{ prop: "noticeNumber", label: "通知单号", width: "100px" },
		{ prop: "code", label: "货主编码", width: "60px" },
		{ prop: "arriveTime", label: "预计到货时间", width: "120px" },
		{ prop: "clientNumber", label: "客户订单号", width: "80px" },
		{ prop: "car", label: "车号", width: "100px" },
		{ prop: "driver", label: "司机", width: "60px" },
		{ prop: "driverNumber", label: "司机电话", width: "120px" },
		{ prop: "orderType", label: "订单类型", width: "90px" },
		{ prop: "platform", label: "月台", width: "90px" },
		{ prop: "remark", label: "备注", width: "90px" },
	],
});
</script>

<template>
	<h1>其他入库</h1>
	<TableTitle v-model="titleData" class="title" @user-click="userChildClick" />
	<ComponentsTable v-bind="tableProps">
		<template #bodyCell="{ prop, row }">
			<template v-if="prop === 'operation-bar'">
				<ElButton type="primary" size="small"> 验收单 </ElButton>
				<ElButton type="primary" size="small"> 入库单 </ElButton>
				<ElButton type="primary" size="small"> 货品id </ElButton>
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
