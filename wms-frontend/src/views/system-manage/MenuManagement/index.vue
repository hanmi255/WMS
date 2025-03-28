<template>
	<p>菜单管理</p>
	<TableTitle v-model="titleData" class="title" @user-click="userChildClick" />

	<el-table
		@row-click="handleRowClick"
		@selection-change="multipleSelectRows = $event"
		@current-change="handleCurrentChange"
		@@expand-change="handleExpandChange"
		@expand-change="haneleTableNode"
		:data="data"
		style="width: 100%; margin-bottom: 20px"
		:props="defaultProps"
		row-key="menuId"
		border
		highlight-current-row
		:height="600"
	>
		<!-- 自定义索引列 -->
		<el-table-column type="index" label="" :index="indexMethod"></el-table-column>

		<el-table-column prop="menuName" label="菜单名称" width="300" />
		<el-table-column prop="menuIcon" label="图标" width="100">
			<template #default="{ row }">
				<img :src="row.menuIcon" alt="" style="width: 24px; height: 24px" v-if="row.menuIcon" />
			</template>
		</el-table-column>
		<el-table-column prop="menuType" label="菜单类型" width="100" />
		<el-table-column prop="menuUrl" label="菜单地址" width="300" />
		<el-table-column prop="menuSort" label="菜单顺序" width="100" />
		<el-table-column prop="menuIconStyle" label="菜单图标样式" width="120" />
		<el-table-column prop="operation-bar" label="操作" width="100">
			<template #default="{ row }">
				<el-popconfirm
					:title="`确定要删除该数据吗？`"
					confirm-button-text="确定"
					cancel-button-text="取消"
					@confirm="handleConfirmDelete(row)"
				>
					<template #reference>
						<el-button type="success" size="small" :icon="Delete">删除</el-button>
					</template>
				</el-popconfirm>
			</template>
		</el-table-column>
	</el-table>
	<!-- 单行编辑弹窗 -->
	<el-dialog
		v-model="dialogVisible"
		:title="dialogTitle"
		width="40%"
		:close-on-click-modal="false"
		:close-on-press-escape="false"
		draggable
		:destroy-on-close="true"
		class="detail-dialog"
		:model="multipleSelectRows[0]"
		:rules="rules"
		ref="form"
	>
		<el-form
			:label-position="left"
			label-width="auto"
			:model="multipleSelectRows[0]"
			:rules="rules"
			ref="form"
			style="max-width: 600px"
		>
			<el-form-item label="菜单名称" style="width: 300px" prop="menuName">
				<el-input v-model="currentRow.menuName" />
			</el-form-item>
			<el-form-item label="菜单类型" style="width: 300px">
				<el-select placeholder="菜单类型" v-model="currentRow.menuType">
					<el-option label="菜单类型" value="0" />
					<el-option label="权限类型" value="1" />
				</el-select>
			</el-form-item>
			<el-form-item label="菜单等级" style="width: 300px">
				<el-select placeholder="下级菜单" v-model="currentRow.menuLevels">
					<el-option label="一级菜单" value="0" />
					<el-option label="下级菜单" value="1" />
				</el-select>
			</el-form-item>
			<el-form-item v-show="currentRow.menuLevels === '1'" label="父菜单" style="width: 300px" v-if="isAdd">
				<el-select
					v-model="parentFunctionName"
					placeholder="基础配置"
					@change="handleChange"
					@click="getParentTree"
					ref="parentRef"
				>
					<el-option :value="parentFunctionId" label="parentFunctionName" style="height: auto">
						<el-tree
							:data="dataTree"
							:props="defaultProps1"
							@node-click="handleNodeClick"
							label="parentFunctionName"
						></el-tree>
					</el-option>
				</el-select>
			</el-form-item>
			<el-form-item label="菜单地址" style="width: 300px">
				<el-input v-model="currentRow.menuUrl" />
			</el-form-item>
			<el-form-item label="图标" style="width: 300px">
				<el-select v-model="currentRow.menuIcon" placeholder="默认">
					<el-option
						v-for="option in menuIconOptions"
						:key="option.value"
						:label="option.label"
						:value="option.value"
					/>
				</el-select>
			</el-form-item>
		</el-form>
		<template #footer>
			<span class="dialog-footer">
				<el-button type="primary" @click="btnConfirm">确定</el-button>
				<el-button @click="dialogVisible = false">关闭</el-button>
			</span>
		</template>
	</el-dialog>
</template>
<script setup>
import { Delete } from "@element-plus/icons-vue";
import { ref, onMounted } from "vue";
import TableTitle from "@/components/table-title/TableTitle.vue";
import {
	getMenuListAPI,
	addMenuAPI,
	getMenuTreeAPI,
	getMenuNameTreeAPI,
	getIconListAPI,
	updateMenuAPI,
} from "@/apis/menu";
import { ElMessage } from "element-plus";
definePage({
	meta: {
		menuType: "page",
		text: "菜单管理",
		icon: "IconMenu",
	},
});
// 被选中的父菜单id
const parentFunctionId = ref("mc90ac564c9d6734014csd6f4e370100");
// 默认父菜单名称
const parentFunctionName = ref("基础配置");
// 选中的表格数据s
const multipleSelectRows = ref([]);
// 创建一个中间变量来处理当前行的数据
const currentRow = computed({
	get() {
		return multipleSelectRows.value[0] || {}; // 如果没有选中行，则返回空对象
	},
	set(value) {
		if (multipleSelectRows.value.length > 0) {
			multipleSelectRows.value[0] = value; // 更新选中行的数据
		}
	},
});

// 当前行
const currentRowData = ref(null);
// 弹窗显示
const dialogVisible = ref(false);
// 弹窗标题
const dialogTitle = ref("");
// 控制菜单录入的父菜单
const isAdd = ref(false);

//获取form组件实例
let form = ref();
let parentRef = ref();

// 图标
const menuIconOptions = ref([
	{ label: "默认", value: "默认" },
	{ label: "小车", value: "小车" },
	{ label: "星星", value: "星星" },
	{ label: "小圆点", value: "小圆点" },
]);
const defaultProps = ref({
	label: "menuName",
	children: "children",
});
const defaultProps1 = ref({
	label: "menuName",
	children: "children",
});

// 菜单名称树 通过获取菜单名称树接口获得
const dataTree = ref([]);

// 发送到子组件的数据
const titleData = ref({
	unfold: false,
	bottomList: [
		{
			name: "菜单录入",
			iconType: "Add",
		},
		{
			name: "菜单编辑",
			iconType: "Edit",
		},
	],
});

// 表格内数据
const data = ref([]);

// 自定义行号
const indexMethod = (index) => {
	return index + 1;
};

// 菜单名称自定义校验 请填写2到15位任意字符！
const validatorMenuName = (rule, value, callBack) => {
	const reg = /^[a-zA-Z0-9\u4e00-\u9fa5]{2,15}$/;
	if (reg.test(value)) {
		callBack();
	} else {
		callBack(new Error("请填写2到15位任意字符！"));
	}
};

// 自定义菜单顺序校验 请填写1到3位数字！
const validatorMenuSort = (rule, value, callback) => {
	const reg = /^\d{1,3}$/;
	if (reg.test(value)) {
		callback();
	} else {
		callback(new Error("请填写1到3位数字！"));
	}
};

// 表单校验的规则
const rules = {
	menuName: [
		{ required: true, message: "请填写菜单名称", trigger: ["blur", "change"] },
		{
			trigger: "change",
			validator: validatorMenuName,
		},
	],
	menuSort: [
		{ required: true, message: "请填写菜单排序", trigger: ["blur", "change"] },
		{ trigger: "change", validator: validatorMenuSort },
	],
};

// 组件加载完毕后
onMounted(() => {
	getMenuList();
});

// 处理子组件按钮事件
const userChildClick = (icon) => {
	if (icon.name === "菜单录入") {
		handleAdd(multipleSelectRows);
	}
	if (icon.name === "菜单编辑") {
		handleSingleRowEdit(multipleSelectRows);
	}
};

//菜单录入
const handleAdd = (multipleSelectRows) => {
	isAdd.value = true;
	multipleSelectRows.value = [
		{
			menuIcon: "默认",
			menuType: "菜单类型",
			menuLevels: "一级菜单",
			menuName: "", // 添加默认值
			menuUrl: "",
			menuSort: "",
			menuIconStyle: "",
		},
	];
	dialogVisible.value = true;
	dialogTitle.value = "菜单录入";
};
// 菜单编辑
const handleSingleRowEdit = (multipleSelectRows) => {
	isAdd.value = false;
	// console.log(multipleSelectRows.value.length);
	if (!multipleSelectRows.value[0].menuName) {
		ElMessage.warning("请选择编辑项目");
		return;
	}
	if (multipleSelectRows.value.length > 1) {
		ElMessage.warning("请选择一条记录进行编辑");
		return;
	}
	dialogVisible.value = true;
	dialogTitle.value = "菜单编辑";
};

// 确定
const btnConfirm = () => {
	form.value.validate(async (valid) => {
		if (valid) {
			try {
				const res = await performAction();
				if (res.code === 10000) {
					dialogVisible.value = false;
					// 刷新
					await getMenuList();
					ElMessage.success(dialogTitle.value === "菜单录入" ? "添加成功" : "修改成功");
					return;
				} else {
					ElMessage.warning(res.message);
				}
			} catch (error) {
				ElMessage.warning(error.data.message);
			}
			dialogVisible.value = false;
			return;
		} else {
			// 表单验证失败
			ElMessage.warning("请重新填写");
			return;
		}
	});
};

const performAction = async () => {
	if (dialogTitle.value === "菜单录入") {
		return await addMenuAPI({
			// TODO 还无法获取到所有图标
			menuIcon: multipleSelectRows.value[0].menuIcon === "默认" ? "8a8ab0b246dc81120146dc8180460000" : "",
			menuType: multipleSelectRows.value[0].menuType === "菜单类型" ? 0 : 1,
			menuLevels: multipleSelectRows.value[0].menuLevels === "一级菜单" ? 0 : 1,
			menuUrl: multipleSelectRows.value[0].menuUrl,
			menuName: multipleSelectRows.value[0].menuName,
			parentFunctionId: parentFunctionId.value,
		});
	} else if (dialogTitle.value === "菜单编辑") {
		return await updateMenuAPI({
			// menuIcon:
			// 	multipleSelectRows.value[0].menuIcon === "默认"
			// 		? "http://121.43.101.169:8888/group1/M00/00/01/oYYBAGfXw5uAMDmpAAA3UytLVCc281.png?token=6de7c1ff30687961b10323c73086192a&ts=1742292087"
			// 		: "",
			menuIcon: multipleSelectRows.value[0].menuIcon === "默认" ? "8a8ab0b246dc81120146dc8180460000" : "",
			menuType: multipleSelectRows.value[0].menuType === "菜单类型" ? 0 : 1,
			menuLevels: multipleSelectRows.value[0].menuLevels === "一级菜单" ? 0 : 1,
			menuUrl: multipleSelectRows.value[0].menuUrl,
			menuName: multipleSelectRows.value[0].menuName,
			parentFunctionId: parentFunctionId.value,
		});
	}
};

// 处理确认删除事件
const handleConfirmDelete = async (row) => {
	console.log("row.menuId", row.menuId, typeof row.menuId);
	const res = await deleteResourceAPI(row.menuId);
	if (res.code === 10000) {
		await getMenuList();
		ElMessage.success("删除成功");
	} else {
		ElMessage.warning(res.message);
	}
};

// 处理行点击事件
const handleRowClick = (row, column, event) => {
	console.log("点击的行数据:", row);
	multipleSelectRows.value[0] = row;
	currentRowData.value = row; // 更新当前行
};

// 获取菜单列表
const getMenuList = async () => {
	const res = await getMenuListAPI();
	console.log(res);
	if (res.code === 10000) {
		data.value = res.data;
		// 处理 menuType 和 menuLevels 的转换
		transformMenuData(data.value);
		// 获取图标 URL 并映射到 items
		await fetchAndMapIcons(data.value);
		// 给每个isParentNode===1的data加上children
		// 给每个 isParentNode === 1 的 item 添加 children
		addChildrenToParentNodes(data.value);
		console.log("菜单列表", data.value);
	} else {
		ElMessage.error(res.message);
	}
};

// 表格树形节点点击事件
const haneleTableNode = async (row) => {
	// 我点一次节点就会获取到当前节点下的数据，我会把数据存到当前节点的children里面，

	console.log("当前展开row", row.menuId, row.menuLevels);

	// data.value 中 当前row
	const res = await getMenuTreeAPI(row.menuId);
	row.children = res.data; // 要把这个数据存到对应的data的哪个位置
	console.log("row.children", row.children);
	// 处理 menuType 和 menuLevels 的转换
	transformMenuData(row.children);
	// 获取图标 URL 并映射到 items
	await fetchAndMapIcons(row.children);
	// 给每个 isParentNode === 1 的 item 添加 children
	addChildrenToParentNodes(row.children);

	console.log(data.value);
};

// 处理 menuType 和 menuLevels 的转换
const transformMenuData = (items) => {
	items.forEach((item) => {
		item.menuType = item.menuType === 0 ? "菜单类型" : "权限类型";
		item.menuLevels = item.menuLevels === 0 ? "一级菜单" : "下级菜单";
	});
};

// 获取图标 URL 并映射到 items
const fetchAndMapIcons = async (items) => {
	const uniqueIconIds = [...new Set(items.map((item) => item.menuIcon))].filter((iconId) => iconId !== undefined);
	const iconMap = {};
	for (const iconId of uniqueIconIds) {
		let iconUrl = await getIcon(iconId);
		iconMap[iconId] = iconUrl;
	}
	items.forEach((item) => {
		item.menuIcon = iconMap[item.menuIcon];
	});
};

// 给每个 isParentNode === 1 的 item 添加 children
const addChildrenToParentNodes = (items) => {
	items.forEach((child) => {
		if (child.isParentNode === 1) {
			child.children = [{}];
		}
	});
};

//树形
// const handleCheckChange = (data, checked, indeterminate) => {
// 	console.log("handleCheckChange", data, checked, indeterminate);
// };

const handleCurrentChange = (currentNode) => {
	console.log("handleCurrentChange", currentNode);
	currentRowData.value = currentNode;
};

// 树节点点击事件
const handleNodeClick = (data) => {
	console.log("1", data.menuName);
	parentFunctionName.value = data.menuName;
	parentFunctionId.value = data.menuId; // 更新父菜单选项
	parentRef.value.blur(); //关闭下拉菜单
};

const handleChange = (value) => {
	// console.log("选中的值:", value);
};

// 获取父菜单列表
const getParentTree = async () => {
	const res = await getMenuNameTreeAPI();
	dataTree.value = res.data;
	console.log("父菜单列表", res);
};

// 转化为图标
const getIcon = async (id) => {
	const res = await getIconListAPI(id);
	console.log("图标", res);

	return res.data.url;
};
</script>

<style lang="scss" scoped>
p {
	width: 100%;
	border-bottom: 1px solid #efefef;
}

.title {
	width: 100%;
	padding-bottom: 10px;
	border-bottom: 1px solid #efefef;
}
/* 自定义抽屉样式 */
::v-deep(.el-drawer) {
	background-color: transparent !important; /* 设置抽屉背景颜色为透明 */
}

/* 自定义遮罩层样式 */
::v-deep(.el-overlay) {
	background-color: rgba(0, 0, 0, 0) !important; /* 设置遮罩层透明度为0 */
}

::v-deep(header.el-drawer__header) {
	margin: 0;
}
</style>
