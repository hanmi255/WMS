<template>
	<base-config-table
		title="商品类目配置"
		:columns="columns"
		:form-fields="formFields"
		:table-data="mockData"
		@row-click="handleRowClick"
	>
		<template #column-categoryName="{ row }">
			<div class="category-name-cell" :style="{ paddingLeft: `${(row._level || 0) * 20}px` }">
				<el-icon v-if="row.hasChildren" @click.stop="toggleExpand(row)">
					<ArrowRight class="expand-icon" :class="{ 'is-expanded': row.expanded }" />
				</el-icon>
				<el-icon v-else class="category-icon-placeholder"></el-icon>
				<el-icon class="category-icon">
					<FolderOpened v-if="row.hasChildren && row.expanded" />
					<Folder v-else-if="row.hasChildren" />
					<Document v-else />
				</el-icon>
				<span class="category-name">{{ row.categoryName }}</span>
			</div>
		</template>
	</base-config-table>
</template>

<script setup lang="ts">
import { reactive, ref, nextTick } from "vue";
import { Goods } from "@element-plus/icons-vue";
import { Document, Folder, FolderOpened, ArrowRight } from "@element-plus/icons-vue";
import BaseConfigTable from "../components/BaseTable.vue";
// import { productCategoryApi } from "@/api/product";

definePage({
	meta: {
		menuType: "page",
		text: "商品类目",
		icon: Goods,
	},
});

// 定义表格列
const columns = [
	{ prop: "createTime", label: "创建日期", width: 120 },
	{
		prop: "categoryCode",
		label: "类目编码",
		width: 120,
	},
	{
		prop: "categoryName",
		label: "类目名称",
		width: 200,
		// 使用插槽自定义渲染
		slotName: "column-categoryName",
	},
	{ prop: "categoryLevel", label: "类目级别", width: 100 },
];

// 定义表单字段
const formFields = [
	{
		prop: "categoryCode",
		label: "类目编码",
		type: "input",
		rules: [{ required: true, message: "请输入类目编码", trigger: "blur" }],
	},
	{
		prop: "categoryName",
		label: "类目名称",
		type: "input",
		rules: [{ required: true, message: "请输入类目名称", trigger: "blur" }],
	},
	{
		prop: "categoryLevel",
		label: "类目级别",
		type: "number",
		rules: [{ required: true, message: "请输入类目级别", trigger: "blur" }],
	},
	{
		prop: "parentId",
		label: "父级类目",
		type: "select",
		options: [], // 从后端获取
	},
];

// 模拟数据 - 一级类目
const mockData = ref([
	{
		id: 1,
		parentId: 0,
		categoryCode: "30001",
		categoryName: "日用",
		categoryLevel: 1,
		createTime: "2024-03-13",
		hasChildren: true,
		expanded: false,
		_level: 2,
		// children属性将在展开时动态添加
	},
	{
		id: 2,
		parentId: 0,
		categoryCode: "30002",
		categoryName: "电缆",
		categoryLevel: 1,
		createTime: "2024-10-02",
		hasChildren: true,
		expanded: false,
		_level: 2,
	},
	{
		id: 6,
		parentId: 0,
		categoryCode: "30003",
		categoryName: "家电",
		categoryLevel: 2,
		createTime: "2024-11-15",
		hasChildren: true,
		expanded: false,
		_level: 2,
	},
]);

// 模拟后端接口数据 - 按类目ID获取子级类目
const categoryAPIData = {
	// 日用类目(id=1)的子类目
	1: [
		{
			id: 3,
			parentId: 1,
			categoryCode: "001",
			categoryName: "洗浴用品",
			categoryLevel: 2,
			createTime: "2024-12-22",
			hasChildren: true,
			expanded: false,
		},
		{
			id: 7,
			parentId: 1,
			categoryCode: "002",
			categoryName: "厨房用品",
			categoryLevel: 2,
			createTime: "2024-11-05",
			hasChildren: true,
			expanded: false,
		},
	],
	// 电缆类目(id=2)的子类目
	2: [
		{
			id: 8,
			parentId: 2,
			categoryCode: "2001",
			categoryName: "电源线",
			categoryLevel: 2,
			createTime: "2024-10-12",
			hasChildren: false,
			expanded: false,
		},
		{
			id: 9,
			parentId: 2,
			categoryCode: "2002",
			categoryName: "网线",
			categoryLevel: 2,
			createTime: "2024-10-15",
			hasChildren: false,
			expanded: false,
		},
	],
	// 家电类目(id=6)的子类目
	6: [
		{
			id: 10,
			parentId: 6,
			categoryCode: "3001",
			categoryName: "冰箱",
			categoryLevel: 2,
			createTime: "2024-11-20",
			hasChildren: false,
			expanded: false,
		},
	],
	// 洗浴用品类目(id=3)的子类目
	3: [
		{
			id: 4,
			parentId: 3,
			categoryCode: "00101",
			categoryName: "沐浴露",
			categoryLevel: 3,
			createTime: "2024-12-23",
			hasChildren: false,
			expanded: false,
		},
		{
			id: 5,
			parentId: 3,
			categoryCode: "00102",
			categoryName: "洗发露",
			categoryLevel: 3,
			createTime: "2024-12-23",
			hasChildren: false,
			expanded: false,
		},
	],
	// 厨房用品类目(id=7)的子类目
	7: [
		{
			id: 11,
			parentId: 7,
			categoryCode: "00201",
			categoryName: "锅具",
			categoryLevel: 3,
			createTime: "2024-11-10",
			hasChildren: true,
			expanded: false,
		},
	],
	// 锅具类目(id=11)的子类目
	11: [
		{
			id: 12,
			parentId: 11,
			categoryCode: "0020101",
			categoryName: "炒锅",
			categoryLevel: 4,
			createTime: "2024-11-11",
			hasChildren: false,
			expanded: false,
		},
		{
			id: 13,
			parentId: 11,
			categoryCode: "0020102",
			categoryName: "汤锅",
			categoryLevel: 4,
			createTime: "2024-11-12",
			hasChildren: false,
			expanded: false,
		},
	],
};

// 存储已展开的行的ID，用于重建展开状态
const expandedRows = ref(new Set());

// 处理行点击事件
const handleRowClick = (row) => {
	// 点击行时也可以触发展开/折叠
	if (row.hasChildren) {
		toggleExpand(row);
	}
};

// 切换展开/折叠状态
const toggleExpand = (row) => {
	if (!row.hasChildren) return;

	row.expanded = !row.expanded;

	if (row.expanded) {
		// 记录展开状态
		expandedRows.value.add(row.id);
		// 展开时加载子级数据
		expandCategory(row);
	} else {
		// 移除展开状态
		expandedRows.value.delete(row.id);
		// 折叠时移除子级数据
		collapseCategory(row);
	}

	// 强制刷新数据引用，确保视图更新
	mockData.value = [...mockData.value];
};

const expandCategory = (row) => {
	// 获取子类目数据
	const childrenData = categoryAPIData[row.id] || [];

	childrenData.forEach((child) => {
		child._level = row._level ? row._level + 1 : 1;
	});

	const index = mockData.value.findIndex((item) => item.id === row.id);
	if (index > -1) {
		mockData.value.splice(index + 1, 0, ...childrenData);

		// 强制刷新数据引用，确保视图更新
		mockData.value = [...mockData.value];
	}
};

const collapseCategory = (row) => {
	const startIndex = mockData.value.findIndex((item) => item.id === row.id);
	if (startIndex === -1) return;
	const toRemove = [];

	for (let i = startIndex + 1; i < mockData.value.length; i++) {
		const current = mockData.value[i];

		let isChild = false;
		let parent = current;

		while (parent.parentId !== 0) {
			if (parent.parentId === row.id) {
				isChild = true;
				break;
			}

			const parentItem = mockData.value.find((item) => item.id === parent.parentId);
			if (!parentItem) break;
			parent = parentItem;
		}

		if (isChild) {
			toRemove.push(i);
		} else if (current.parentId === 0 || current.parentId < row.id) {
			break;
		}
	}
	// 从后向前删除，避免索引变化问题
	for (let i = toRemove.length - 1; i >= 0; i--) {
		mockData.value.splice(toRemove[i], 1);
	}
};

// API获取方法
// const api = {
// 	list: productCategoryApi.getList,
// 	add: productCategoryApi.add,
// 	update: productCategoryApi.update,
// 	delete: productCategoryApi.delete,
// 	batchDelete: productCategoryApi.batchDelete,
// 	export: productCategoryApi.export,
// 	import: productCategoryApi.import,
// };
</script>

<style scoped lang="scss">
.category-name-cell {
	display: flex;
	align-items: center;
	cursor: pointer;

	.expand-icon {
		transition: transform 0.3s;
		margin-right: 4px;

		&.is-expanded {
			transform: rotate(90deg);
		}
	}

	.category-icon-placeholder {
		width: 16px;
		margin-right: 4px;
		visibility: hidden;
	}

	.category-icon {
		margin-right: 8px;
		font-size: 16px;
		color: #409eff;
	}

	.category-name {
		font-size: 14px;
	}
}
</style>
