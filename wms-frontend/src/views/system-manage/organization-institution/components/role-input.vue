<template>
	<!-- <el-dialog :model-value="rol" @update:model-value="handleDialogChange" draggable title="角色列表"> -->
	<el-dialog :model-value="showRol" @update:model-value="handleDialogChange" draggable title="角色列表">
		<p>角色选择</p>
		<TableTitle v-model="titleData" class="title" @user-click="userChildClick" />
		<ComponentsTable v-bind="tableProps" @selection-change="rolVal = $event"> </ComponentsTable>
		<template #footer>
			<span class="dialog-footer">
				<el-button type="primary" @click="btnInConfirm">确定</el-button>
				<el-button @click="btnClose">关闭</el-button>
			</span>
		</template>
	</el-dialog>
</template>

<script setup>
import TableTitle from "@/components/table-title/TableTitle.vue";
import ComponentsTable from "@/components/table/index.vue";

const props = defineProps(["showRol"]);
const emit = defineEmits(["show-role-dialog", "get-role-list"]);

// 使用 defineModel实现双向绑定
// const rol = defineModel("rol");
// const rolVal = defineModel("rolVal");

const rolVal = ref([]);
const rolValList = ref([]);

// 发送到子组件的数据
const titleData = ref({
	unfold: true,
	rightButton: true,
	contentList: [
		{
			name: "角色名称",
			type: "AddSininput",
			content: ["", ""],
		},
	],
});

const data = ref([
	{
		rolename: "管理员1",
	},
	{
		rolename: "管理员2",
	},
	{
		rolename: "管理员3",
	},
]);

// 表格配置
const tableProps = ref({
	isIndex: true,
	isMultipleSelect: true,
	data: data,
	columns: [{ prop: "rolename", label: "角色名称", width: "200px" }],
});

// 处理子组件按钮事件
const userChildClick = (icon) => {
	if (icon.name === "右侧查询") {
		handleSearch(rolVal);
	}
	if (icon.name === "右侧重置") {
		handleReset(rolVal);
	}
};

// 最里面对话框的确定按钮
const btnInConfirm = () => {
	// rolValList.value = [];
	// if (rolVal.value.length > 0) {
	// 	rolVal.value.forEach((item) => rolValList.value.push(item.rolename));
	// 	console.log(rolVal.value);
	// 	rolVal.value = rolValList.value;
	// 	console.log(rolVal.value);
	// }
	// rol.value = false;
	rolValList.value = [];
	rolVal.value.forEach((item) => rolValList.value.push(item.rolename));
	console.log("rolVal.value", rolVal.value);
	console.log("rolValList.value", rolValList.value);
	emit("get-role-list", rolValList.value);
	emit("show-role-dialog", false);
};

const btnClose = () => {
	// showRol.value = false;
	emit("show-role-dialog", false);
};
// 右侧查询
const handleSearch = () => {
	// const templateName = titleData.value.contentList[0].content;
	// const type = titleData.value.contentList[1].content;
	//TODO 获取组织成员(条件+分页)
};
// 右侧重置
const handleReset = () => {
	titleData.value.contentList[0].content = ["", ""];
};
</script>

<style lang="scss" scoped></style>
