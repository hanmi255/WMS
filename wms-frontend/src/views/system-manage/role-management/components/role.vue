<template>
	<div class="header">
		<p>当前角色权限</p>
	</div>
	<div class="title">
		<p>菜单列表</p>
	</div>
	<div class="content">
		<el-button @click="allChecked">全选</el-button>
		<el-button @click="resetAll">重置</el-button>
		<el-button @click="change">切换模式</el-button>
		<el-button @click="save">保存</el-button>
		<el-tree
			ref="treeRef"
			style="max-width: 600px"
			:data="menuList"
			show-checkbox
			default-expand-all
			node-key="id"
			highlight-current
			:props="defaultProps"
			:default-checked-keys="checkedKeys"
			@check-change="handleCheckChange"
		/>
	</div>
</template>

<script setup>
import { ref, onMounted, watch, computed } from "vue";
import { getResourceNameTreeAPI, setRoleResourceAPI, getRoleResourceAPI } from "@/apis/menu";

const prop = defineProps(["rowList", "drawer2"]);
const treeRef = ref();

const menuList = ref([]);
// 计算属性 initList
const initList = computed(() => prop.rowList.roleFunctionAssignment);

const defaultProps = {
	label: "functionName",
	children: "subItems",
};

// 递归函数：在树形结构中找到对应的item，并更新flag
const toggleFlagById1 = (nodes, id) => {
	if (!Array.isArray(nodes)) {
		return;
	}
	nodes.forEach((node) => {
		if (node.id === id) {
			node.flag = node.flag === "1" ? "0" : "1";
			console.log("把flag变为", node.flag);
			console.log("把flag变为1时候的初始状态", initList.value);
		}
		if (Array.isArray(node.subItems) && node.subItems.length > 0) {
			toggleFlagById1(node.subItems, id);
		}
	});
};
const toggleFlagById2 = (nodes) => {
	let selectNode = [];
	treeRef.value.setCheckedKeys([]);
	if (!Array.isArray(nodes)) {
		return;
	}
	nodes.forEach((node) => {
		if (node.flag === "1") {
			// treeRef.value.setCheckedKeys([node.id]);
			selectNode.push(node.id);
			// console.log("选上了", node.id);
		}

		if (Array.isArray(node.subItems) && node.subItems.length > 0) {
			toggleFlagById2(node.subItems);
		}
	});
	return selectNode;
};

// 监听 drawer2 属性的变化
watch(
	() => prop.drawer2,
	async (newVal) => {
		if (newVal) {
			if (newVal === true) {
				console.log("drawer2 变化了,现在为", prop.drawer2);
				// console.log("rowList", prop.rowList);
				// 把根据角色编码获得的名称树 rowList 赋值给 menuList
				menuList.value = await prop.rowList.roleFunctionAssignment;
				console.log("初始化menuList.value", menuList.value);
				// 将menuList中flag为1的节点的复选框勾上
				nextTick(() => {
					let selectNode = toggleFlagById2(menuList.value);
					console.log("selectNode", selectNode);
					treeRef.value.setCheckedKeys(selectNode);
				});

				console.log("打勾后menuList.value", menuList.value);
				// 此时是初始化完成，如果点击重置就是进入现在状态
			} else {
				menuList.value = [];
				console.log("关闭抽屉", menuList.value);
			}
		}
	},
	{
		immediate: true,
	},
);

// 树复选框
const handleCheckChange = async (data, checked, indeterminate) => {
	// console.log(data, checked, indeterminate);
	console.log("data.id", data.id);
	// 在menuList中找到对应的item，把flag取反,注意menuList的数据是树形结构，所以需要递归
	await toggleFlagById1(menuList.value, data.id);
	console.log("menuList.value", menuList.value);
	// 发送请求
};

// 全选功能
const allChecked = () => {
	// 使用 setCheckedNodes 方法选中所有节点
	treeRef.value.setCheckedNodes(menuList.value);
};

// 重置功能
const resetAll = async () => {
	// 这个应该是清空功能
	// 使用 setCheckedKeys 方法清空所有选中节点
	// treeRef.value.setCheckedKeys([]);
	// 重置是回退到初始状态
	console.log("重置前menuList.value ", menuList.value);
	console.log("初始状态是", initList);
	menuList.value = initList;
	let selectNode = await toggleFlagById2(menuList.value);
	treeRef.value.setCheckedKeys(selectNode);
	console.log("重置后menuList.value ", menuList.value);
};

// 切换功能
const change = () => {
	console.log(menuList.value);
};

// 保存
const save = async () => {
	// 发送请求
	const res = await setRoleResourceAPI({
		roleCode: prop.rowList.roleCode,
		langType: prop.rowList.langType,
		roleFunctionAssignment: menuList.value,
	});
	if (res.code === 10000) {
		// 重新获取对应角色的菜单名称树
		await getRoleResourceAPI(prop.rowList.roleCode);
		ElMessage.success("保存成功");
	} else {
		ElMessage.error("保存失败");
	}
};
</script>

<style lang="scss" scoped>
* {
	margin: 0;
	padding: 0;
	list-style: none;
}

p {
	width: 100%;
	margin-bottom: 10px;
	border-bottom: 1px solid #efefef;
}

::v-deep(.el-button span) {
	padding: 2px;
}

.content {
	margin-top: 20px;
	ul {
		margin-top: 10px;
	}
	li {
		margin-bottom: 5px;
		.role {
			margin-left: 4px;
		}
	}
}

svg {
	margin-right: 4px;
}
</style>
