<script lang="ts" setup>
import { ref } from "vue";
import TableTitle from "@/components/table-title/TableTitle.vue";
import ComponentsTable from "components/table/index.vue";

definePage({
	meta: {
		// 页面必须要填写为page类型
		menuType: "page",
		text: "预约进货",
		icon: "IconSetting",
	},
});

// 发送到子组件的数据
const titleData = ref({
	unfold: true,
	rightButton: true,
	contentList: [
		{
			name: "进货通知单号",
			type: "AddSininput",
			content: ["", ""],
		},
		{
			name: "货主",
			type: "AddCheckBox",
			optionData: ["测试2", "测试1"],
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
			name: "运输号码",
			type: "AddSininput",
			content: ["", ""],
		},
		{
			name: "运输公司",
			type: "AddSininput",
			content: ["", ""],
		},
		{
			name: "供应商编号",
			type: "AddSininput",
			content: ["", ""],
		},
		{
			name: "供应商名称",
			type: "AddCheckBox",
			content: ["", ""],
			optionData: ["213", "test"],
		},
		{
			name: "订单类型",
			type: "AddCheckBox",
			content: ["", ""],
			optionData: ["越库通知", "其他入库", "出库通知", "其他出库", "出库通知", "出库通知", "出货通知"],
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
		{
			name: "导入",
			iconType: "Bottom",
		},
		{
			name: "模板下载",
			iconType: "Download",
		},
	],
});

// 表格内数据
const data = [
	{
		name: "张三",
		creatTime: "2023-10-01",
		noticeNumber: "NT123456",
		code: "H001",
		arriveTime: "2023-10-05 12:00",
		clientNumber: "CO123",
		car: "车123",
		driver: "运输公司A",
		driverNumber: "供应商001",
		orderType: "供应商A",
		platform: "入库",
		remark: "无",
		stauts: "已处理",
	},
	{
		name: "李四",
		creatTime: "2023-10-02",
		noticeNumber: "NT123457",
		code: "H002",
		arriveTime: "2023-10-06 14:00",
		clientNumber: "CO124",
		car: "车124",
		driver: "运输公司B",
		driverNumber: "供应商002",
		orderType: "供应商B",
		platform: "出库",
		remark: "需要加急",
		stauts: "处理中",
	},
	{
		name: "王五",
		creatTime: "2023-10-03",
		noticeNumber: "NT123458",
		code: "H003",
		arriveTime: "2023-10-07 09:00",
		clientNumber: "CO125",
		car: "车125",
		driver: "运输公司C",
		driverNumber: "供应商003",
		orderType: "供应商C",
		platform: "入库",
		remark: "无备注",
		stauts: "未处理",
	},
	{
		name: "赵六",
		creatTime: "2023-10-04",
		noticeNumber: "NT123459",
		code: "H004",
		arriveTime: "2023-10-08 11:00",
		clientNumber: "CO126",
		car: "车126",
		driver: "运输公司D",
		driverNumber: "供应商004",
		orderType: "供应商D",
		platform: "出库",
		remark: "注意安全",
		stauts: "已完成",
	},
];

const tableProps = ref({
	data: data,
	isIndex: true,
	isMultipleSelect: true,
	columns: [
		{ prop: "operation-bar", label: "操作", width: "200px" },
		{ prop: "name", label: "创建人名称", width: "60px" },
		{ prop: "creatTime", label: "创建日期", width: "100px" },
		{ prop: "noticeNumber", label: "进货通知单号", width: "100px" },
		{ prop: "code", label: "货主", width: "60px" },
		{ prop: "arriveTime", label: "预计到货时间", width: "120px" },
		{ prop: "clientNumber", label: "客户订单号", width: "80px" },
		{ prop: "car", label: "运输号码", width: "100px" },
		{ prop: "driver", label: "运输公司", width: "60px" },
		{ prop: "driverNumber", label: "供应商编号", width: "100px" },
		{ prop: "orderType", label: "供应商名称", width: "80px" },
		{ prop: "platform", label: "订单类型", width: "80px" },
		{ prop: "remark", label: "备注", width: "90px" },
		{ prop: "stauts", label: "单据状态", width: "90px" },
	],
});
</script>

<template>
	<h1>预约进货</h1>
	<TableTitle v-model="titleData" class="title" @user-click="userChildClick" />
	<ComponentsTable v-bind="tableProps">
		<template #bodyCell="{ prop, row }">
			<template v-if="prop === 'operation-bar'">
				<ElButton type="primary" size="small">通知单</ElButton>
				<ElButton type="primary" size="small">货品信息</ElButton>
				<ElButton type="primary" size="small">打印入库</ElButton>
				<ElButton type="primary" size="small">验收单</ElButton>
				<ElButton type="primary" size="small">导出入库</ElButton>
				<ElButton type="primary" size="small">托盘标签</ElButton>
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
