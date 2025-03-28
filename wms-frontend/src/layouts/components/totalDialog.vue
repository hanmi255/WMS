<!-- 这是点击查看全部后的组件 -->
<template>
	<el-dialog
		:model-value="visible"
		:title="status === 1 ? '公告' : '消息'"
		width="800"
		draggable
		@update:model-value="updateVisible"
	>
		<div v-if="data1 || data2">
			<ComponentsTable v-bind="status === 1 ? tableProps1 : tableProps2">
				<template #bodyCell="{ prop, row }" >
					<div v-if="prop === 'operation-bar'">
						<el-button type="success" @click="goNoticeDetail(status === 1 ? 1 : 2, row)">阅读</el-button>
					</div>
				</template>
			</ComponentsTable>
		</div>

		<el-pagination
			v-if="status === 1"
			style="margin-top: 20px"
			v-model:current-page="pageIndex"
			v-model:page-size="pageSize"
			:page-sizes="[10, 20, 30]"
			:disabled="disabled"
			layout="total, sizes, prev, pager, next, jumper"
			:total="total"
			@size-change="handlePageSize"
			@current-change="handlePageIndex"
		/>
		<template #footer>
			<div class="dialog-footer">
				<el-button @click="handleCancel">取消</el-button>
			</div>
		</template>
	</el-dialog>
	<noticeDetail v-model:control="showDetail" :dialogTitle="dialogTitle" :noticeId="noticeId"></noticeDetail>
</template>

<script setup>
import noticeDetail from "./notice-detail.vue";
import { defineProps, defineEmits, ref, onMounted } from "vue";
import ComponentsTable from "@/components/table/index.vue";
import { getNoticeListAPI, getMessageListAPI, updateNoticeStatusAPI } from "@/apis/notice-remind/index.js";

const noticeId = ref("");
const showDetail = ref(false);
const dialogTitle = ref("");

// 页码
const pageIndex = ref(1);
// 页面大小
const pageSize = ref(10);
// total
const total = ref(0);

// 改变页面大小
const handlePageSize = (val) => {
	console.log(val);
	pageSize.value = val;
	const params = {
		currentPage: pageIndex.value,
		pageSize: val,
	};
	// const params1 = {
	// 	pageIndex: pageIndex.value,
	// 	pageSize: val,
	// };
	getNoticeList(params);
	// getMessageList(params1);
};

// 改变页码
const handlePageIndex = (val) => {
	console.log(val);
	pageIndex.value = val;
	const params = {
		currentPage: val,
		pageSize: pageSize.value,
	};
	// const params1 = {
	// 	pageIndex: val,
	// 	pageSize: pageSize.value,
	// };
	getNoticeList(params);
	// getMessageList(params1);
};

// 下面是提供给tabledialog的数据
const data1 = ref();

const tableProps1 = ref({
	isIndex: true,
	data: data1,
	columns: [
		{ prop: "isRead", label: "状态", width: "100px" },
		{ prop: "noticeTitle", label: "标题", width: "300px" },
		{ prop: "noticeTime", label: "时间", width: "200px" },
		{ prop: "operation-bar", label: "操作", width: "100px" },
	],
});

const data2 = ref();

const tableProps2 = ref({
	data: data2,
	columns: [
		{ prop: "noticeContent", label: "内容", width: "435px" },
		{ prop: "createTime", label: "发送时间", width: "300px" },
	],
});

const prop = defineProps(["visible", "status"]);

const emit = defineEmits(["update:visible"]);

// 获取公告列表
const getNoticeList = async (params) => {
	const res = await getNoticeListAPI(
		params || {
			currentPage: pageIndex.value,
			pageSize: pageSize.value,
		},
	);
	if (res.code === 10000) {
		data1.value = res.data.rows;
		data1.value = res.data.rows.map((item) => {
			return {
				...item,
				isRead: item.isRead === 0 ? "未读" : "已读",
			};
		});
		// 还得判断时间，注意不显示过期公告
		total.value = res.data.total;
	}
	// console.log(res);
};
// 获取消息列表
const getMessageList = async () => {
	const res = await getMessageListAPI({
		pageIndex: pageIndex.value,
		pageSize: pageSize.value,
	});
	if (res.code === 10000) {
		data2.value = res.data.rows;
		total.value = res.data.total;
	}
	// console.log(res);
};
// 修改公告状态
const updateNoticeStatus = async (id) => {
	const res = await updateNoticeStatusAPI({
		noticeId: id,
	});
	if (res.code === 10000) {
		ElMessage.success("修改成功"); // 修改阅读状态
		getNoticeList();
	}
};

// 监听 visible 属性的变化
watch(
	() => prop.visible,
	(newVal) => {
		if (newVal) {
			getNoticeList();
			getMessageList();
		}
	},
);

// TODO 去往公告详情页
const goNoticeDetail = (type, row) => {
	// 发生put请求修改公告状态 跳转详情 通过row获取传递的noticeid
	// console.log(row.noticeId);
	//假设传入id为1
	noticeId.value = row.noticeId;
	updateNoticeStatus(row.noticeId);
	dialogTitle.value = type === 1 ? "通知公告详情" : "系统消息详情";
	showDetail.value = true;
};

//取消
const handleCancel = () => {
	emit("update:visible", false);
};

const updateVisible = (value) => {
	emit("update:visible", value);
};
</script>

<style lang="scss" scoped></style>
