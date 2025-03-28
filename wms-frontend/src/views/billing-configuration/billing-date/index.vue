<script lang="js" setup>
definePage({
	meta: {
		menuType: "page",
		text: "计费日期",
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
			name: "计费日期",
			type: "AddCal",
			content: ["", ""],
			optionData: ["短信提醒", "邮件提醒", "系统提醒"],
		},
		{
			name: "是否已计费",
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
	{ date: "2023-01-01", count: "Y" },
	{ date: "2023-01-02", count: "Y" },
	{ date: "2023-01-03", count: "Y" },
	{ date: "2023-01-04", count: "Y" },
	{ date: "2023-01-05", count: "Y" },
	{ date: "2023-01-06", count: "Y" },
	{ date: "2023-01-07", count: "Y" },
]);
const tableColumns = ref([
	{ prop: "date", label: "计费日期" },
	{ prop: "count", label: "是否已计费" },
	{ prop: "operation", label: "操作" },
]);
</script>

<template>
	<section class="billing-date-root">
		<p class="title">计费日期</p>
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
.billing-date-root {
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
