<template>
	<el-dialog :model-value="myModel" @update:model-value="handleDialogChange" draggable>
		<p>添加已有客户</p>
		<TableTitle v-model="titleData" class="title" @user-click="userChildClick" />
		<ComponentsTable v-bind="tableProps" @selection-change="multipleSelectRows2 = $event"> </ComponentsTable>
		<el-pagination
			style="margin-top: 20px"
			v-model:current-page="pageIndex"
			v-model:page-size="pageSize"
			:page-sizes="[10, 20, 30]"
			:disabled="disabled"
			layout="total, sizes, prev, pager, next, jumper"
			:total="400"
			@size-change="handlePageSize"
			@current-change="handlePageIndex"
		/>

		<template #footer>
			<span class="dialog-footer">
				<el-button type="primary" @click="btnInConfirm">确定</el-button>
				<el-button @click="myModel = false">关闭</el-button>
			</span>
		</template>
	</el-dialog>
</template>

<script setup>
import { ref, onMounted, defineModel } from "vue";
import TableTitle from "@/components/table-title/TableTitle.vue";
import ComponentsTable from "@/components/table/index.vue";
definePage({
	meta: {
		menuType: "page",
		text: "消息中心",
		icon: "IconSetting",
	},
});

// 使用 defineModel实现双向绑定
const myModel = defineModel("myModel");

// 消息列表
const messageList = ref([]);
// 选中的表格数据
const multipleSelectRows2 = ref([]);

// 发送到子组件的数据
const titleData = ref({
	unfold: true,
	rightButton: true,
	contentList: [
		{
			name: "用户账号",
			type: "AddSininput",
			content: ["", ""],
		},
		{
			name: "用户名称",
			type: "AddSininput",
			content: ["", ""],
		},
	],
});

// 表格内数据
const data = [
	{
		username: "admin",
		status: "激活",
		realname: "管理员",
	},
	{
		username: "admin",
		status: "激活",
		realname: "管理员",
	},
	{
		username: "admin",
		status: "激活",
		realname: "管理员",
	},
];

//表格配置
const tableProps = ref({
	isIndex: true,
	isMultipleSelect: true,
	data: data,
	columns: [
		{ prop: "username", label: "用户账号", width: "70px" },
		{ prop: "realname", label: "用户名称", width: "70px" },
		{ prop: "status", label: "状态", width: "70px" },
	],
});

onMounted(() => {});

const getMessageList = () => {
	// TODO 获取消息列表
	messageList.value = data;
};

// 处理子组件按钮事件
const userChildClick = (icon) => {
	if (icon.name === "右侧查询") {
		handleSearch();
	}
	if (icon.name === "右侧重置") {
		handleReset();
	}
};

// 右侧查询
const handleSearch = () => {
	// const templateName = titleData.value.contentList[0].content;
	// const type = titleData.value.contentList[1].content;
	// TODO 获取消息列表
};
// 右侧重置
const handleReset = () => {
	titleData.value.contentList[0].content = ["", ""];
	titleData.value.contentList[1].content = ["", ""];
};

// 处理可见性变化
const handleDialogChange = (value) => {
	console.log("点击关闭", value);
	myModel.value = value;
};

// 最里面对话框的确定按钮
const btnInConfirm = () => {
	myModel.value = false;
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
</style>
