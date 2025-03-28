<template>
	<!-- <el-dialog :model-value="rol" @update:model-value="handleDialogChange" draggable title="角色列表"> -->
	<el-dialog :model-value="showRol" @update:model-value="handleDialogChange" draggable title="角色列表">
		<p>角色选择</p>
		<TableTitle v-model="titleData" class="title" @user-click="userChildClick" />
		<ComponentsTable v-bind="tableProps" @selection-change="rolVal = $event" style="height: 300px"> </ComponentsTable>
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
import { getRoleNameListAPI } from "@/apis/sysmanager-ok";

const props = defineProps(["showRol"]);
const emit = defineEmits(["show-role-dialog", "get-role-list"]);

const RoleIds = defineModel("RoleIds");

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

const data = ref([]);

// 表格配置
const tableProps = ref({
	isIndex: true,
	isMultipleSelect: true,
	data: data,
	columns: [{ prop: "rolename", label: "角色名称", width: "200px" }],
});

// 监听 visible 属性的变化
watch(
	() => props.showRol,
	(newVal) => {
		if (newVal) {
			const params = {
				pageIndex: 1,
				pageSize: 20,
			};
			getNoticeList(params);
		}
	},
);
// 获取角色名称列表
const getNoticeList = async (params) => {
	const res = await getRoleNameListAPI(params);
	if (res.code === 10000) {
		data.value = res.data.rows;
	}
};

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
	rolVal.value.forEach((item) => RoleIds.value.push({ ID: item.ID, rolename: item.rolename }));

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
const handleSearch = async () => {
	const rolename = titleData.value.contentList[0].content[0];
	await getNoticeList({
		pageIndex: 1,
		pageSize: 20,
		rolename: rolename,
	});
	ElMessage.success("查询成功");
};
// 右侧重置
const handleReset = () => {
	titleData.value.contentList[0].content = ["", ""];
	getNoticeList({
		pageIndex: 1,
		pageSize: 20,
	});
};
</script>

<style lang="scss" scoped></style>
