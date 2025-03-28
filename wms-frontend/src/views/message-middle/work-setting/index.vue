<template>
	<p>消息模板_业务SQL配置表</p>
	<TableTitle v-model="titleData" class="title" @user-click="userChildClick" />
	<ComponentsTable v-bind="tableProps" @selection-change="multipleSelectRows = $event">
		<template #bodyCell="{ prop, row }">
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
		v-model:current-page="page"
		v-model:page-size="size"
		:page-sizes="[10, 20, 30]"
		:disabled="disabled"
		layout="total, sizes, prev, pager, next, jumper"
		:total="total"
		@size-change="handlesize"
		@current-change="handlepage"
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
			style="max-width: 600px"
			:rules="rules"
			ref="form"
			:disabled="dialogTitle === '查看'"
		>
			<el-form-item label="配置CODE" style="width: 300px" prop="code">
				<el-input v-model="multipleSelectRows[0].code" />
			</el-form-item>
			<el-form-item label="配置名称" style="width: 300px" prop="name">
				<el-input v-model="multipleSelectRows[0].name" />
			</el-form-item>
			<el-form-item label="业务SQLID" style="width: 300px" prop="sqlId">
				<el-select placeholder="--请选择--" v-model="multipleSelectRows[0].sqlId">
					<el-option label="SQL-查询收货预约" value="SQL-查询收货预约" />
					<el-option label="SQL-查询出货通知" value="SQL-查询出货通知" />
					<el-option label="SQL-查询用户姓名" value="SQL-查询用户姓名" />
				</el-select>
			</el-form-item>
			<el-form-item label="消息模本ID" style="width: 300px" prop="templateId">
				<el-select placeholder="--请选择--" v-model="multipleSelectRows[0].templateId">
					<el-option label="收货预约通知" value="收货预约通知" />
					<el-option label="出货预约通知" value="出货预约通知" />
					<el-option label="充值短信提醒模板" value="充值短信提醒模板" />
				</el-select>
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
import { Delete, Upload } from "@element-plus/icons-vue";
import { ref, onMounted } from "vue";
import TableTitle from "@/components/table-title/TableTitle.vue";
import ComponentsTable from "@/components/table/index.vue";
import {
	getWorkSettingAPI,
	addWorkSettingAPI,
	updateWorkSettingAPI,
	deleteWorkSettingAPI,
} from "@/apis/message-middle";
import { template } from "lodash-es";
definePage({
	meta: {
		menuType: "page",
		text: "业务配置",
		icon: "IconSetting",
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

// 发送到子组件的数据
const titleData = ref({
	unfold: true,
	rightButton: true,
	contentList: [
		{
			name: "配置CODE",
			type: "AddSininput",
			content: ["", ""],
		},
		{
			name: "配置名称",
			type: "AddSininput",
			content: ["", ""],
		},
		{
			name: "创建日期",
			type: "AddDbcal",
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

// 表格配置
const tableProps = ref({
	isIndex: true,
	isMultipleSelect: true,
	data: data,
	columns: [
		{ prop: "code", label: "配置CODE", width: "150px" },
		{ prop: "name", label: "配置名称", width: "150px" },
		{ prop: "sqlId", label: "业务SQLID", width: "150px" },
		{ prop: "templateId", label: "消息模板ID", width: "150px" },
		{ prop: "createDate", label: "创建日期", width: "150px" },
		{ prop: "operation-bar", label: "操作", width: "150px" },
	],
});

// 页码
const page = ref(1);
// 页面大小
const size = ref(10);
// total
const total = ref(0);

// 改变页面大小
const handlesize = (val) => {
	console.log(val);
	size.value = val;
	const params = {
		page: page.value,
		size: val,
	};
	getWorkList(params);
};

// 改变页码
const handlepage = (val) => {
	console.log(val);
	page.value = val;
	const params = {
		page: val,
		size: size.value,
	};
	getWorkList(params);
};

// 表单校验的规则
const rules = {
	code: [{ required: true, message: "请填写配置CODE", trigger: ["blur", "change"] }],
	name: [{ required: true, message: "请填写配置名称", trigger: ["blur", "change"] }],
	sqlId: [{ required: true, message: "请选择业务SQLID", trigger: ["blur", "change"] }],
	templateId: [{ required: true, message: "请选择消息模本ID", trigger: ["blur", "change"] }],
};

onMounted(() => {
	getWorkList();
});

// 获取业务配置列表
const getWorkList = async (params) => {
	const res = await getWorkSettingAPI(
		params || {
			page: page.value,
			size: size.value,
		},
	);
	if (res.code === 10000) {
		data.value = res.data.rows;
		data.value = res.data.rows.map((item) => {
			return {
				...item,
				// status: item.status === 1 ? "激活" : "锁定",
				sqlId: item.sqlId === "1" ? "SQL-查询收货预约" : item.sqlId === "2" ? "SQL-查询出货通知" : "SQL-查询用户姓名",
				templateId:
					item.templateId === "1" ? "收货预约通知" : item.templateId === "2" ? "出货预约通知" : "充值短信提醒模板",
				createDate: new Date(item.createDate).toLocaleDateString("en-CA"), // 格式化日期
			};
		});
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
	multipleSelectRows.value = [{ code: "", name: "", sqlId: "", templateId: "" }];
	dialogVisible.value = true;
	dialogTitle.value = "录入";
};
// 编辑
const handleSingleRowEdit = (multipleSelectRows) => {
	if (!multipleSelectRows.value[0].code) {
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
			try {
				if (dialogTitle.value === "录入") {
					// 录入
					const res = await addWorkSettingAPI({
						code: multipleSelectRows.value[0].code,
						name: multipleSelectRows.value[0].name,
						sqlId:
							multipleSelectRows.value[0].sqlId === "SQL-查询收货预约"
								? "1"
								: multipleSelectRows.value[0].sqlId === "SQL-查询出货通知"
									? "2"
									: "3",
						templateId:
							multipleSelectRows.value[0].templateId === "收货预约通知"
								? "1"
								: multipleSelectRows.value[0].templateId === "出货预约通知"
									? "2"
									: "3",
					});
					handleApiResponse(res);
				} else if (dialogTitle.value === "编辑") {
					// 编辑
					const res = await updateWorkSettingAPI({
						id: multipleSelectRows.value[0].id,
						code: multipleSelectRows.value[0].code,
						name: multipleSelectRows.value[0].name,
						sqlId:
							multipleSelectRows.value[0].sqlId === "SQL-查询收货预约"
								? "1"
								: multipleSelectRows.value[0].sqlId === "SQL-查询出货通知"
									? "2"
									: "3",
						templateId:
							multipleSelectRows.value[0].templateId === "收货预约通知"
								? "1"
								: multipleSelectRows.value[0].templateId === "出货预约通知"
									? "2"
									: "3",
					});
					handleApiResponse(res);
				}
			} catch (error) {
				ElMessage.error(error.message, error.data);
			} finally {
				dialogVisible.value = false;
			}
		} else {
			// 表单验证失败
			ElMessage.warning("请重新填写");
		}
	});
};

// 处理 API 响应的通用函数
const handleApiResponse = (res) => {
	if (res.code === 10000) {
		ElMessage.success("操作成功");
		// 刷新
		getWorkList({ page: page.value, size: size.value });
	} else if (res.code === 9999) {
		ElMessage.warning(res.message, res.data);
	} else {
		ElMessage.warning(res.message);
	}
};

// 批量删除
const handleDelete = async (multipleSelectRows) => {
	if (multipleSelectRows.value.length < 1) {
		ElMessage.warning("请选择需要删除的数据");
		return;
	}
	console.log(multipleSelectRows.value);
	const ids = multipleSelectRows.value.map((item) => item.id).join(",");
	const res = await deleteWorkSettingAPI(ids);
	if (res.code === 10000) {
		ElMessage.success("删除成功");
		getWorkList({ page: page.value, size: size.value });
	} else {
		ElMessage.warning(res.message);
	}
};

// 查看
const handleLook = (multipleSelectRows) => {
	if (!multipleSelectRows.value[0].code) {
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
		page: page.value,
		size: size.value,
	};
	const configCode = titleData.value.contentList[0].content[0] || "";
	if (configCode) {
		params.configCode = configCode;
	}
	const configName = titleData.value.contentList[1].content[0] || "";
	if (configName) {
		params.configName = configName;
	}
	const createDateStart = titleData.value.contentList[2].content[0] || "";
	if (createDateStart) {
		params.createDateStart = formatDate(createDateStart);
	}
	const createDateEnd = titleData.value.contentList[2].content[1] || "";
	if (createDateEnd) {
		params.createDateEnd = formatDate(createDateEnd);
	}
	getWorkList(params);
};

// 日期格式化函数
const formatDate = (dateString) => {
	const date = new Date(dateString);
	const year = date.getFullYear();
	const month = String(date.getMonth() + 1).padStart(2, "0");
	const day = String(date.getDate()).padStart(2, "0");
	const hours = String(date.getHours()).padStart(2, "0");
	const minutes = String(date.getMinutes()).padStart(2, "0");
	const seconds = String(date.getSeconds()).padStart(2, "0");
	return `${year}-${month}-${day} ${hours}:${minutes}:${seconds}`;
};
// 右侧重置
const handleReset = () => {
	titleData.value.contentList[0].content = ["", ""];
	titleData.value.contentList[1].content = ["", ""];
	titleData.value.contentList[2].content = ["", ""];
	getWorkList({
		page: page.value,
		size: size.value,
	});
};

// 处理确认删除事件
const handleConfirmDelete = async (row) => {
	console.log("删除的id", row.id);
	const res = await deleteWorkSettingAPI(row.id);
	if (res.code === 10000) {
		ElMessage.success("删除成功");
		getWorkList({ page: page.value, size: size.value });
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
