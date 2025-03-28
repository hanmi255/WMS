<template>
	<p>业务SQL表</p>
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
			:model="multipleSelectRows[0]"
			:rules="rules"
			ref="form"
			:label-position="left"
			label-width="auto"
			style="max-width: 600px"
			:disabled="dialogTitle === '查看'"
		>
			<el-form-item label="SQL名称" style="width: 300px" prop="sqlName">
				<el-input v-model="currentRow.sqlName" />
			</el-form-item>
			<el-form-item label="SQL内容">
				<el-input type="textarea" v-model="currentRow.sqlContent" />
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
import { getSqlListAPI, updateSqlAPI, deleteSqlAPI } from "@/apis/message-middle/index.js";
import { ElMessage } from "element-plus";
definePage({
	meta: {
		menuType: "page",
		text: "业务SQL",
		icon: "IconSetting",
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
//获取form组件实例
let form = ref();

// 发送到子组件的数据
const titleData = ref({
	unfold: true,
	rightButton: true,
	contentList: [
		{
			name: "SQL名称",
			type: "AddSininput",
			content: ["", ""],
		},
		{
			name: "SQL内容",
			type: "AddSininput",
			content: ["", ""],
		},
	],
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
		{
			name: "查看",
			iconType: "Search",
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
		{ prop: "sqlName", label: "SQL名称", width: "150px" },
		{ prop: "sqlContent", label: "SQL内容", width: "600px" },
		{ prop: "operation-bar", label: "操作", width: "90px" },
	],
});
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
		pageIndex: pageIndex.value,
		pageSize: val,
	};
	getSqlList(params);
};

// 改变页码
const handlePageIndex = (val) => {
	console.log(val);
	pageIndex.value = val;
	const params = {
		pageIndex: val,
		pageSize: pageSize.value,
	};
	getSqlList(params);
};

// 获取sql列表
const getSqlList = async (params) => {
	const res = await getSqlListAPI(
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
	getSqlList();
});

// 表单校验的规则
const rules = {
	sqlName: [{ required: true, message: "请填写SQL名称", trigger: ["blur", "change"] }],
};

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
	if (icon.name === "查看") {
		handleLook(multipleSelectRows);
	}
	if (icon.name === "右侧查询") {
		handleSearch();
	}
	if (icon.name === "右侧重置") {
		handleReset();
	}
};

//录入
const handleAdd = (multipleSelectRows) => {
	multipleSelectRows.value = [
		{
			sqlContent: " ",
			sqlName: " ",
		},
	];
	dialogVisible.value = true;
	dialogTitle.value = "录入";
};
// 编辑
const handleSingleRowEdit = (multipleSelectRows) => {
	if (isValidMultipleSelectRow) {
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
	form.value.validate(async (valid) => {
		if (valid) {
			console.log("dialogTitle.value", dialogTitle.value);
			if (dialogTitle.value === "录入") {
				// 录入
				const res = await addSqlAPI({
					sqlName: multipleSelectRows.value[0].sqlName,
					sqlContent: multipleSelectRows.value[0].sqlContent,
				});
				if (res.code === 10000) {
					dialogVisible.value = false;
					ElMessage.success("添加成功");
					// 刷新
					getSqlList({ pageIndex: pageIndex.value, pageSize: pageSize.value });
				} else if (res.code === 9999) {
					ElMessage.warning(res.message, res.data);
				} else {
					ElMessage.warning(res.message);
				}
			} else {
				// 编辑
				const res = await updateSqlAPI({
					sqlName: multipleSelectRows.value[0].sqlName,
					sqlContent: multipleSelectRows.value[0].sqlContent,
					sqlId: multipleSelectRows.value[0].sqlId,
				});
				if (res.code === 10000) {
					ElMessage.success("修改成功");
					dialogVisible.value = false;
					// 刷新
					getSqlList({ pageIndex: pageIndex.value, pageSize: pageSize.value });
				} else if (res.code === 9999) {
					ElMessage.warning(res.message, res.data);
				} else {
					ElMessage.warning(res.message);
				}
			}
			dialogVisible.value = false;
		} else {
			// 表单验证失败
			ElMessage.warning("请重新填写");
		}
	});
};

// 批量删除
const handleDelete = (multipleSelectRows) => {
	if (multipleSelectRows.value.length < 1) {
		ElMessage.warning("请选择需要删除的数据");
		return;
	}
	console.log(multipleSelectRows.value);
	// TODO 删除SQL
	// data.splice(0, data.length);
	// multipleSelectRows.value.splice(0, multipleSelectRows.value.length);
	// console.log(data);
};

// 查看
const handleLook = (multipleSelectRows) => {
	if (isValidMultipleSelectRow) {
		ElMessage.warning("请选择查看项目");
		return;
	}
	if (multipleSelectRows.value.length > 1) {
		ElMessage.warning("请选择一条记录再查看");
		return;
	}
	dialogVisible.value = true;
	dialogTitle.value = "查看";
};

// 右侧查询
const handleSearch = () => {
	const params = {
		pageIndex: pageIndex.value,
		pageSize: pageSize.value,
	};

	const sqlName = titleData.value.contentList[0].content[0] || "";
	if (sqlName) {
		params.sqlName = sqlName;
	}
	// TODO sqlContent查询不了
	const sqlContent = titleData.value.contentList[1].content[0] || "";
	if (sqlContent) {
		params.sqlContent = sqlContent;
	}

	getSqlList(params);
};
// 右侧重置
const handleReset = () => {
	titleData.value.contentList[0].content = ["", ""];
	titleData.value.contentList[1].content = ["", ""];
	getSqlList({
		pageIndex: pageIndex.value,
		pageSize: pageSize.value,
	});
};

// 处理确认删除事件
const handleConfirmDelete = async (row) => {
	console.log("删除的id", row.sqlId);
	const res = await deleteSqlAPI({
		sqlId: row.sqlId,
	});
	if (res.code === 10000) {
		getSqlList({ pageIndex: pageIndex.value, pageSize: pageSize.value });
		ElMessage.success("删除成功");
	} else {
		ElMessage.warning(res.message);
	}
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
