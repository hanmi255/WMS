<template>
	<div class="product-attribute-page">
		<base-config-table
			ref="baseTableRef"
			title="产品属性配置"
			:columns="columns"
			:form-fields="formFields"
			:table-data="mockData"
		>
		</base-config-table>
	</div>
</template>

<script setup lang="ts">
import { ref } from "vue";
import { InfoFilled } from "@element-plus/icons-vue";
import { ElMessage, ElMessageBox } from "element-plus";
import BaseConfigTable from "../components/BaseTable.vue";
// import { productAttributeApi } from "@/api/product";

definePage({
	meta: {
		menuType: "page",
		text: "产品属性",
		icon: InfoFilled,
	},
});

const baseTableRef = ref();

// 定义表格列
const columns = [
	{ prop: "attributeCode", label: "产品属性编码", width: 120 },
	{ prop: "attributeName", label: "产品属性名称", width: 120 },
];

// 定义表单字段
const formFields = [
	{
		prop: "attributeCode",
		label: "产品属性编码",
		type: "input",
		rules: [{ required: true, message: "请输入产品属性编码", trigger: "blur" }],
	},
	{
		prop: "attributeName",
		label: "产品属性名称",
		type: "input",
		rules: [{ required: true, message: "请输入产品属性名称", trigger: "blur" }],
	},
];

// 删除行的处理函数
const handleRowDelete = (row) => {
	ElMessageBox.confirm("确定要删除该产品属性吗？", "提示", {
		confirmButtonText: "确定",
		cancelButtonText: "取消",
		type: "warning",
	})
		.then(async () => {
			// 实际项目中应调用API
			// try {
			//   await productAttributeApi.delete(row.id);
			//   ElMessage.success("删除成功");
			//   baseTableRef.value.fetchData();
			// } catch (error) {
			//   console.error("删除失败", error);
			//   ElMessage.error("删除失败");
			// }

			// 模拟成功
			ElMessage.success("删除成功");
		})
		.catch(() => {
			// 用户取消操作
		});
};

// API方法（预留）
// const api = {
// 	list: productAttributeApi.getList,
// 	add: productAttributeApi.add,
// 	update: productAttributeApi.update,
// 	delete: productAttributeApi.delete,
// 	batchDelete: productAttributeApi.batchDelete,
// 	export: productAttributeApi.export,
// 	import: productAttributeApi.import,
// };

// 模拟数据
const mockData = [
	{
		id: 1,
		attributeCode: "PA001",
		attributeName: "颜色",
	},
	{
		id: 2,
		attributeCode: "PA002",
		attributeName: "尺寸",
	},
	{
		id: 3,
		attributeCode: "PA003",
		attributeName: "重量",
	},
	{
		id: 4,
		attributeCode: "PA004",
		attributeName: "材质",
	},
	{
		id: 5,
		attributeCode: "PA005",
		attributeName: "品牌",
	},
];
</script>

<style scoped lang="scss">
.product-attribute-page {
	width: 100%;
}
</style>
