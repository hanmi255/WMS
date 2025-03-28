<script lang="js" setup>
definePage({
	meta: {
		menuType: "page",
		text: "计费商品类",
		icon: "IconSetting",
	},
});
import TableTitle from "@/components/table-title/TableTitle.vue";
import ComponentsTable from "@/components/table/index.vue";
import { ref } from "vue";
import { Delete } from "@element-plus/icons-vue";
import Pagination from "@/components/Pagination/index.vue";
const titleData = ref({
	unfold: true,
	rightButton: true,
	contentList: [
		{
			name: "消息类型",
			type: "AddCheckBox",
			content: ["", ""],
			optionData: ["短信提醒", "邮件提醒", "系统提醒"],
		},
		{
			name: "消息标题",
			type: "AddSininput",
			content: ["", ""],
		},
		{
			name: "发送状态",
			type: "AddCheckBox",
			content: ["", ""],
			optionData: ["未发送", "发送成功", "发送失败"],
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
			name: "查看",
			iconType: "Search",
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
	{ code: "001", name: "商品类1" },
	{ code: "002", name: "商品类2" },
	{ code: "003", name: "商品类3" },
	{ code: "004", name: "商品类4" },
	{ code: "005", name: "商品类5" },
	{ code: "006", name: "商品类6" },
	{ code: "007", name: "商品类7" },
	{ code: "008", name: "商品类8" },
]);
const tableColumns = ref([
	{ prop: "code", label: "计费商品类代码" },
	{ prop: "name", label: "计费商品类名称" },
	{ prop: "operation", label: "操作" },
]);
</script>

<template>
	<section class="billing-commodity-category-root">
		<p class="title">计费商品类</p>
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
.billing-commodity-category-root {
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
