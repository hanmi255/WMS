<template>
	<p>消息模块表</p>
	<TableTitle v-model="titleData" class="title" @user-click="userChildClick" />
	<ComponentsTable :height="500" v-bind="tableProps" @selection-change="multipleSelectRows = $event">
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
			:model="multipleSelectRows[0]"
			:rules="rules"
			ref="form"
			style="max-width: 600px"
			:disabled="dialogTitle === '查看'"
		>
			<el-form-item label="模块类型" style="width: 300px" prop="type">
				<el-select placeholder="--请选择--" v-model="multipleSelectRows[0].type">
					<!-- <el-option label="--请选择--" value="" /> -->
					<el-option label="邮件提醒模块" value="邮件提醒模块" />
					<el-option label="短信提醒模块" value="短信提醒模块" />
				</el-select>
			</el-form-item>

			<el-form-item label="模块名称" style="width: 300px" prop="templateName">
				<el-input v-model="multipleSelectRows[0].templateName" />
			</el-form-item>
			<el-form-item label="模块内容">
				<el-input type="textarea" v-model="multipleSelectRows[0].templateContent" />
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
import { ElMessage } from "element-plus";
import {
	getMessageTemplateListAPI,
	addMessageTemplateAPI,
	updateMessageTemplateAPI,
	deleteMessageTemplateAPI,
} from "@/apis/message-middle";
definePage({
	meta: {
		menuType: "page",
		text: "消息模块",
		icon: "IconMessage",
	},
});

// 选中的表格数据
const multipleSelectRows = ref([]);
// 弹窗显示
const dialogVisible = ref(false);
// 弹窗标题
const dialogTitle = ref("");
//获取form组件实例
let form = ref();

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
	getMessageTemplate(params);
};

// 改变页码
const handlePageIndex = (val) => {
	console.log(val);
	pageIndex.value = val;
	const params = {
		pageIndex: val,
		pageSize: pageSize.value,
	};
	getMessageTemplate(params);
};

// 发送到子组件的数据
const titleData = ref({
	unfold: true,
	rightButton: true,
	contentList: [
		{
			name: "模板名称",
			type: "AddSininput",
			content: ["", ""],
		},
		{
			name: "模板类型",
			type: "AddCheckBox",
			content: ["", ""],
			optionData: ["短信提醒模板", "邮件提醒模板"],
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

// 表格配置
const tableProps = ref({
	isIndex: true,
	isMultipleSelect: true,
	data: data,
	columns: [
		{ prop: "templateName", label: "模板名称", width: "150px" },
		{ prop: "type", label: "模板类型", width: "150px" },
		{ prop: "templateContent", label: "模板内容", width: "600px" },
		{ prop: "operation-bar", label: "操作", width: "90px" },
	],
});

// 表单校验的规则
const rules = {
	templateName: [{ required: true, message: "请选择模板名称", trigger: ["blur", "change"] }],
	type: [{ required: true, message: "请选择模板类型", trigger: ["blur", "change"] }],
};

// 获取消息模板列表
const getMessageTemplate = async (params) => {
	// TODO 获取消息模板详细信息
	const res = await getMessageTemplateListAPI(
		params || {
			pageIndex: pageIndex.value,
			pageSize: pageSize.value,
		},
	);
	if (res.code === 10000) {
		data.value = res.data;
		data.value = res.data.map((item) => {
			return {
				...item,
				type: item.type === "E" ? "邮件提醒模块" : "短信提醒模块",
			};
		});
		total.value = data.value.length;
	} else {
		ElMessage.error(res.message);
	}
};

onMounted(() => {
	getMessageTemplate();
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
	multipleSelectRows.value = [{ type: "", templateName: "", templateContent: "" }];
	dialogVisible.value = true;
	dialogTitle.value = "录入";
};
// 编辑
const handleSingleRowEdit = (multipleSelectRows) => {
	if (
		multipleSelectRows.value.length < 1 ||
		!multipleSelectRows.value[0] ||
		Object.keys(multipleSelectRows.value[0]).length === 0
	) {
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
				const res = await addMessageTemplateAPI({
					type: multipleSelectRows.value[0].type === "邮件提醒模块" ? "E" : "S",
					templateName: multipleSelectRows.value[0].templateName,
					templateContent: multipleSelectRows.value[0].templateContent,
				});
				if (res.code === 10000) {
					// 刷新
					await getMessageTemplate();
					dialogVisible.value = false;
					ElMessage.success("添加成功");
				} else if (res.code === 9999) {
					ElMessage.warning(res.message, res.data);
				} else {
					ElMessage.warning(res.message);
				}
			} else {
				// 编辑
				const res = await updateMessageTemplateAPI({
					type: multipleSelectRows.value[0].type,
					templateName: multipleSelectRows.value[0].templateName,
					templateContent: multipleSelectRows.value[0].templateContent,
				});
				if (res.code === 10000) {
					// 刷新
					await getMessageTemplate();
					dialogVisible.value = false;
					ElMessage.success("修改成功");
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
	// 删除功能应该是直接发送删除请求然后获取最新列表
	// TODO 删除消息模板
	// multipleSelectRows.value.splice(0, multipleSelectRows.value.length);
	// console.log(data);
};

// 查看
const handleLook = (multipleSelectRows) => {
	if (multipleSelectRows.value.length < 1) {
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
	// const templateName = titleData.value.contentList[0].content;
	// const type = titleData.value.contentList[1].content;
	// TODO 获取消息模板详细信息
};
// 右侧重置
const handleReset = () => {
	titleData.value.contentList[0].content = ["", ""];
	titleData.value.contentList[1].content = ["", ""];
};

// 处理确认删除事件
const handleConfirmDelete = async (row) => {
	console.log("删除的id", row);
	const res = await deleteMessageTemplateAPI({
		templateContent: row.templateContent,
		templateName: row.templateName,
		type: row.type === "邮件提醒模块" ? "E" : "S",
	});
	if (res.code === 10000) {
		getMessageTemplate({ pageIndex: pageIndex.value, pageSize: pageSize.value });
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
