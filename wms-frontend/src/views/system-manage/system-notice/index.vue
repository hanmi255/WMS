<template>
	<p>公告</p>
	<TableTitle v-model="titleData" class="title" @user-click="userChildClick" />
	<ComponentsTable v-bind="tableProps" @selection-change="multipleSelectRows = $event">
		<template #bodyCell="{ row, prop }">
			<div v-if="prop === 'operation-bar'">
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
			</div>
		</template>
	</ComponentsTable>
	<el-pagination
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
			<el-form-item label="标题" style="width: 300px">
				<el-input v-model="currentRow.noticeTitle" />
			</el-form-item>
			<el-form-item label="内容">
				<el-input type="textarea" v-model="currentRow.noticeContent" />
			</el-form-item>
			<el-form-item label="类型">
				<el-radio-group v-model="currentRow.noticeType">
					<el-radio value="通知">通知</el-radio>
					<el-radio value="公告">公告</el-radio>
				</el-radio-group>
			</el-form-item>
			<el-form-item label="授权级别">
				<el-radio-group v-model="currentRow.noticeLevel">
					<el-radio value="全员">全员</el-radio>
					<el-radio value="角色授权">角色授权</el-radio>
					<el-radio value="用户授权">用户授权</el-radio>
				</el-radio-group>
			</el-form-item>
			<el-form-item label="阅读期限">
				<el-date-picker v-model="currentRow.noticeTerm" type="date" clearable />
			</el-form-item>
		</el-form>
		<template #footer>
			<span class="dialog-footer">
				<el-button type="primary" @click="btnConfirm" v-if="dialogTitle !== '查看'">确定</el-button>
				<el-button @click="dialogVisible = false">关闭</el-button>
			</span>
		</template>
	</el-dialog>
</template>
<script setup>
import { Delete } from "@element-plus/icons-vue";
import { ref, onMounted } from "vue";
import TableTitle from "@/components/table-title/TableTitle.vue";
import ComponentsTable from "@/components/table/index.vue";
import {
	getNoticeListAPI,
	addNoticeAPI,
	updateNoticeAPI,
	deleteNoticeAPI,
	getNoticeDetailAPI,
} from "@/apis/system-manage-ok";
definePage({
	meta: {
		menuType: "page",
		text: "系统公告",
		icon: "IconMessage",
	},
});

// 选中的表格数据
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
// 计算属性：检查 multipleSelectRows 是否包含有效的数据
const isValidMultipleSelectRow = computed(() => {
	return (
		multipleSelectRows.value.length > 0 &&
		multipleSelectRows.value[0] &&
		Object.keys(multipleSelectRows.value[0]).length > 0
	);
});
// 弹窗显示
const dialogVisible = ref(false);
// 弹窗标题
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
};

// 改变页码
const handlePageIndex = (val) => {
	console.log(val);
	pageIndex.value = val;
};

// 发送到子组件的数据
const titleData = ref({
	unfold: false,
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
	],
});

// 表格内数据
const data = ref([]);

const tableProps = ref({
	isIndex: true,
	isMultipleSelect: true,
	data: data,
	columns: [
		{ prop: "noticeTitle", label: "通知标题", width: "200px" },
		{ prop: "noticeType", label: "类型名称", width: "100px" },
		{ prop: "noticeLevel", label: "授权级别", width: "100px" },
		{ prop: "noticeTerm", label: "阅读期限", width: "100px" },
		{ prop: "operation-bar", label: "操作", width: "100px" },
	],
});
// 获取公告列表
const getNoticeList = async (params) => {
	const res = await getNoticeListAPI(
		params || {
			pageIndex: pageIndex.value,
			pageSize: pageSize.value,
		},
	);
	if (res.code === 10000) {
		data.value = res.data.rows;
		total.value = res.data.total;
		if (params && res.data.rows.length > 0) {
			ElMessage.success("获取数据成功");
		} else if (params && res.data.rows.length === 0) {
			ElMessage.warning("暂无数据");
		} else {
			ElMessage.error("查询失败", res.message);
		}
	} else {
		ElMessage.warning(res.message);
	}
};
onMounted(() => {
	getNoticeList();
});

// 处理子组件按钮事件
const userChildClick = (icon) => {
	if (icon.name === "录入") {
		handleAdd(multipleSelectRows);
	}
	if (icon.name === "编辑") {
		handleSingleRowEdit(multipleSelectRows);
	}
	if (icon.name === "批量删除") {
		handleDelete(multipleSelectRows);
	}
};

//录入
const handleAdd = (multipleSelectRows) => {
	multipleSelectRows.value = [{ noticeTitle: "", noticeType: "公告", noticeLevel: "全员", noticeTerm: "" }];
	dialogVisible.value = true;
	dialogTitle.value = "录入";
};
// 编辑
const handleSingleRowEdit = (multipleSelectRows) => {
	// console.log(multipleSelectRows.value[0]);
	// console.log(multipleSelectRows.value);
	// console.log(multipleSelectRows.value.length);
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
	if (dialogTitle.value === "录入") {
		// TODO 录入公告接口
		console.log(data);
	}
	// 保存请求
	// TODO 修改公告接口
	dialogVisible.value = false;
};

// 批量删除
const handleDelete = (multipleSelectRows) => {
	if (multipleSelectRows.value.length < 1) {
		ElMessage.warning("请选择需要删除的数据");
		return;
	}
	console.log(multipleSelectRows.value);
	// TODO 删除公告（支持批量删除）接口
	// data.splice(0, data.length);
	// multipleSelectRows.value.splice(0, multipleSelectRows.value.length);
	// console.log(data);
};

// 表格内单独删除
const btnDelete = (row) => {
	console.log(row);
	// TODO 删除公告（支持批量删除）接口
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
