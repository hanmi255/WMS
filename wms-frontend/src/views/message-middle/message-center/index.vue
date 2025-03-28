<template>
	<!-- <div>消息发送列表</div> -->
	<p>消息发送列表</p>
	<TableTitle v-model="titleData" class="title" @user-click="userChildClick" />
	<ComponentsTable v-bind="tableProps" @selection-change="multipleSelectRows = $event"> </ComponentsTable>
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
	>
		<el-form
			:label-position="left"
			label-width="auto"
			:model="formLabelAlign"
			style="max-width: 600px"
			:disabled="dialogTitle === '查看'"
		>
			<el-form-item label="消息标题" style="width: 300px">
				<el-input v-model="multipleSelectRows[0].esTitle" />
			</el-form-item>

			<el-form-item label="消息类型" style="width: 300px">
				<el-select placeholder="--请选择--" v-model="multipleSelectRows[0].esType">
					<el-option label="--请选择--" value="" />
					<el-option label="短信提醒" value="短信提醒" />
					<el-option label="邮件提醒" value="邮件提醒" />
					<el-option label="系统提醒" value="系统提醒" />
				</el-select>
			</el-form-item>

			<el-form-item label="接收人" style="width: 300px">
				<el-input v-model="multipleSelectRows[0].esReceiver" />
			</el-form-item>

			<el-form-item label="内容">
				<el-input type="textarea" v-model="multipleSelectRows[0].esContent" />
			</el-form-item>

			<el-form-item label="发送状态" style="width: 300px">
				<el-select placeholder="--请选择--" v-model="multipleSelectRows[0].esStatus">
					<el-option label="--请选择--" value="" />
					<el-option label="发送成功" value="发送成功" />
					<el-option label="发送失败" value="发送失败" />
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
import { ref, onMounted } from "vue";
import TableTitle from "@/components/table-title/TableTitle.vue";
import ComponentsTable from "@/components/table/index.vue";
import { getMessageCenterAPI } from "@/apis/message-middle";
definePage({
	meta: {
		menuType: "page",
		text: "消息中心",
		icon: "IconMessage",
	},
});

// 消息列表
const messageList = ref([]);
// 选中的表格数据
const multipleSelectRows = ref([]);
// 弹窗显示
const dialogVisible = ref(false);
// 弹窗标题
const dialogTitle = ref("");
// 页码
const pageIndex = ref(1);
// 页面大小
const pageSize = ref(10);

// 改变页面大小
const handlePageSize = (val) => {
	console.log(val);
	pageSize.value = val;
};

// 改变页码
const handlePageIndex = (val) => {
	console.log(val);
	pageIndex.value = val;
};

// 发送到子组件的数据
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
			name: "消息修正",
			iconType: "Edit",
		},
	],
});

// 表格内数据
const data = ref([
	{
		esType: "系统提醒",
		esTitle: "收货通知",
		esSender: "admin",
		esReceiver: "admin",
		esContent: "刘阳蔬菜批发部客户的出货订单CK20200116-0008将于出货，请准备出货。",
		createDate: "2023-10-01",
		esSendtime: "2023-10-01 10:00:00",
		esStatus: "发送成功",
		remark: "发送成功",
	},
	{
		esType: "系统提醒",
		esTitle: "收货通知",
		esSender: "admin",
		esReceiver: "admin",
		esContent: "刘阳蔬菜批发部客户的出货订单CK20200116-0008将于出货，请准备出货。",
		createDate: "2023-10-01",
		esSendtime: "2023-10-01 10:00:00",
		esStatus: "发送成功",
		remark: "发送成功",
	},
	{
		esType: "系统提醒",
		esTitle: "收货通知",
		esSender: "admin",
		esReceiver: "admin",
		esContent: "刘阳蔬菜批发部客户的出货订单CK20200116-0008将于出货，请准备出货。",
		createDate: "2023-10-01",
		esSendtime: "2023-10-01 10:00:00",
		esStatus: "发送成功",
		remark: "发送成功",
	},
]);

//表格配置
const tableProps = ref({
	isIndex: true,
	isMultipleSelect: true,
	data: data,
	columns: [
		{ prop: "esType", label: "消息类型", width: "90px" },
		{ prop: "esTitle", label: "消息标题", width: "100px" },
		{ prop: "esSender", label: "发送人", width: "65px" },
		{ prop: "esReceiver", label: "接收人", width: "65px" },
		{ prop: "esContent", label: "内容", width: "500px" },
		{ prop: "createDate", label: "创建日期", width: "120px" },
		{ prop: "esSendtime", label: "发送时间", width: "160px" },
		{ prop: "esStatus", label: "发送状态", width: "90px" },
		{ prop: "remark", label: "备注", width: "90px" },
	],
});

onMounted(() => {
	getMessageList();
});

const getMessageList = async () => {
	// TODO 获取消息列表
	const res = await getMessageCenterAPI({
		pageIndex: pageIndex.value,
		pageSize: pageSize.value,
	});
	console.log(res);
	messageList.value = data;
};

// 处理子组件按钮事件
const userChildClick = (icon) => {
	if (icon.name === "消息修正") {
		handleSingleRowEdit(multipleSelectRows);
	}

	if (icon.name === "右侧查询") {
		handleSearch();
	}
	if (icon.name === "右侧重置") {
		handleReset();
	}
};

// 消息修正
const handleSingleRowEdit = (multipleSelectRows) => {
	if (multipleSelectRows.value.length < 1) {
		ElMessage.warning("请选择编辑项目");
		return;
	}
	if (multipleSelectRows.value.length > 1) {
		ElMessage.warning("请选择一条记录进行编辑");
		return;
	}

	dialogVisible.value = true;
	dialogTitle.value = "编辑";
};

// 确定
const btnConfirm = () => {
	// 保存请求

	// TODO 修改消息
	dialogVisible.value = false;
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
	titleData.value.contentList[2].content = ["", ""];
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
