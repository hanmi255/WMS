<script lang="js" setup>
definePage({
	meta: {
		menuType: "page",
		text: "仓储费率",
		icon: "IconSetting",
	},
});
import TableTitle from "@/components/table-title/TableTitle.vue";
import ComponentsTable from "@/components/table/index.vue";
import Pagination from "@/components/Pagination/index.vue";
import { ref } from "vue";
import { Delete } from "@element-plus/icons-vue";
const titleData = ref({
	unfold: true,
	rightButton: true,
	contentList: [
		{
			name: "客户编码",
			type: "AddDbcal",
			content: ["", ""],
			optionData: ["短信提醒", "邮件提醒", "系统提醒"],
		},
		{
			name: "合同编号",
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
			name: "批量删除",
			iconType: "Delete",
		},
		{
			name: "批量核算",
			iconType: "Reset",
		},
		{
			name: "Excel数据导入",
			iconType: "Export",
		},
		{
			name: "Excel数据导出",
			iconType: "Save",
		},
	],
});
const tableData = ref([
	{
		code: "001",
		name: "张三",
		operation: "删除",
		date: "2022-12-12",
		cus_code: "001",
		contract_name: "001",
		start_date: "2022-12-12",
		end_date: "2022-12-12",
		note: "备注",
	},
]);
const tableColumns = ref([
	{ prop: "code", label: "代码" },
	{ prop: "name", label: "创建人名称" },
	{ prop: "date", label: "创建日期" },
	{ prop: "cus_code", label: "客户编码" },
	{ prop: "contract_name", label: "合同编号" },
	{ prop: "start_date", label: "开始日期" },
	{ prop: "end_date", label: "结束日期" },
	{ prop: "note", label: "备注" },
	{ prop: "operation", label: "操作" },
]);
</script>

<template>
	<section class="warehousing-rate-root">
		<p class="title">费用类型</p>
		<TableTitle v-model="titleData"></TableTitle>
		<ComponentsTable is-index="true" is-multiple-select="true" :data="tableData" :columns="tableColumns">
			<template #bodyCell="{ prop }">
				<div v-if="prop === 'operation'">
					<el-button type="primary" size="small" :icon="Delete">删除</el-button>
				</div>
			</template>
		</ComponentsTable>
		<Pagination class="pagination"></Pagination>
	</section>
</template>

<style lang="scss" scoped>
.warehousing-rate-root {
	.title {
		width: 100%;
		border: 1px;
		height: 2rem;
		line-height: 2rem;
		padding-left: 10px;
		background-color: gainsboro;
	}
}
</style>
