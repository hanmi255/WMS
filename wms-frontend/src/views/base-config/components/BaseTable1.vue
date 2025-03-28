<template>
	<div class="base-config-table">
		<div class="header">
			<h2>{{ title }}</h2>
		</div>
		<div class="tool-bar">
			<div class="left-buttons">
				<el-button type="primary" plain @click="handleAdd">
					<el-icon><Plus /></el-icon>录入
				</el-button>
				<el-button type="primary" plain @click="handleEdit">
					<el-icon><Edit /></el-icon>编辑
				</el-button>
			</div>
			<div class="right-tools">
				<el-select v-model="searchField" placeholder="选择显示字段" class="filter-select">
					<el-option
						v-for="col in columns.filter((c) => !c.fixed)"
						:key="col.prop"
						:label="col.label"
						:value="col.prop"
					/>
				</el-select>
			</div>
		</div>

		<el-table
			v-loading="loading"
			:data="props.tableData"
			:row-key="(row) => row.id"
			:tree-props="{
				children: 'children',
				hasChildren: 'hasChildren',
			}"
			:default-expand-all="false"
			border
			stripe
			style="width: 100%"
			@selection-change="handleSelectionChange"
			@row-click="(row) => emit('row-click', row)"
		>
			<el-table-column type="selection" width="55" fixed="left" />
			<el-table-column type="index" label="序号" width="60" fixed="left" />

			<template v-for="col in props.columns" :key="col.prop">
				<el-table-column
					:prop="col.prop"
					:label="col.label"
					:width="col.width"
					:sortable="col.sortable"
					:show-overflow-tooltip="true"
				>
					<template v-if="col.slotName" #default="scope">
						<slot :name="col.slotName" :row="scope.row" :$index="scope.$index" :column="col"></slot>
					</template>
				</el-table-column>
			</template>
			<el-table-column label="操作" width="150" fixed="right">
				<template #default="scope">
					<el-button v-if="props.showEditButton" type="primary" size="small" @click="handleRowEdit(scope.row)">
						编辑
					</el-button>
					<el-button type="danger" size="small" @click="handleRowDelete(scope.row)"> 删除 </el-button>
				</template>
			</el-table-column>
		</el-table>
		<!-- 分页组件 -->
		<div class="pagination-container">
			<el-pagination
				v-model:current-page="currentPage"
				v-model:page-size="pageSize"
				:page-sizes="[10, 20, 50, 100]"
				:total="total"
				layout="total, sizes, prev, pager, next, jumper"
				@size-change="handleSizeChange"
				@current-change="handleCurrentChange"
			/>
		</div>

		<el-dialog
			v-model="dialogVisible"
			:title="dialogType === 'view' ? '查看' : dialogType === 'edit' ? '编辑' : '新增'"
			width="600px"
			@closed="resetForm"
		>
			<el-form ref="formRef" :model="formData" :rules="formRules" label-width="120px" :disabled="dialogType === 'view'">
				<el-form-item v-for="field in formFields" :key="field.prop" :label="field.label" :prop="field.prop">
					<!-- 根据字段类型渲染不同的表单控件 -->
					<template v-if="field.type === 'select'">
						<el-select v-model="formData[field.prop]" :placeholder="`请选择${field.label}`" style="width: 100%">
							<el-option
								v-for="option in field.options"
								:key="option.value"
								:label="option.label"
								:value="option.value"
							/>
						</el-select>
					</template>

					<template v-else-if="field.type === 'number'">
						<el-input-number v-model="formData[field.prop]" :placeholder="`请输入${field.label}`" style="width: 100%" />
					</template>

					<template v-else-if="field.type === 'textarea'">
						<el-input v-model="formData[field.prop]" type="textarea" :rows="3" :placeholder="`请输入${field.label}`" />
					</template>
					<template v-else-if="field.type === 'select'">
						<el-dropdown>
							<span class="el-dropdown-link">
								Dropdown List
								<el-icon class="el-icon--right">
									<arrow-down />
								</el-icon>
							</span>
							<template #dropdown>
								<el-dropdown-menu>
									<el-dropdown-item>Action 1</el-dropdown-item>
									<el-dropdown-item>Action 2</el-dropdown-item>
									<el-dropdown-item>Action 3</el-dropdown-item>
									<el-dropdown-item disabled>Action 4</el-dropdown-item>
									<el-dropdown-item divided>Action 5</el-dropdown-item>
								</el-dropdown-menu>
							</template>
						</el-dropdown>
					</template>

					<template v-else>
						<el-input v-model="formData[field.prop]" :placeholder="`请输入${field.label}`" />
					</template>
				</el-form-item>
			</el-form>

			<template #footer>
				<span class="dialog-footer">
					<el-button @click="dialogVisible = false">取消</el-button>
					<el-button v-if="dialogType !== 'view'" type="primary" @click="submitForm"> 确定 </el-button>
				</span>
			</template>
		</el-dialog>

		<!-- Excel导入弹窗 -->
		<el-dialog v-model="importDialogVisible" title="Excel导入" width="500px">
			<el-upload
				class="upload-excel"
				action="#"
				:auto-upload="false"
				:on-change="handleFileChange"
				:limit="1"
				:file-list="fileList"
			>
				<el-button type="primary">选择文件</el-button>
				<template #tip>
					<div class="el-upload__tip">只能上传excel文件，且不超过10MB</div>
				</template>
			</el-upload>
			<template #footer>
				<span class="dialog-footer">
					<el-button @click="importDialogVisible = false">取消</el-button>
					<el-button type="primary" @click="uploadExcel">确定</el-button>
				</span>
			</template>
		</el-dialog>
	</div>
</template>

<script setup lang="ts">
import { Plus, Edit, Delete, View, Upload, Download, Search } from "@element-plus/icons-vue";
import { ref, computed, watch, onMounted } from "vue";
import { ElMessage, ElMessageBox } from "element-plus";
import type { FormInstance, UploadFile } from "element-plus";

interface Props {
	// debug: { type: boolean; default: false };
	// 表格标题
	title: string;
	showEditButton?: boolean;
	// 表格列
	columns: Array<{
		prop: string;
		label: string;
		width?: number;
		sortable?: boolean;
		fixed?: boolean;
		slotName?: string;
	}>;
	// 表单字段
	formFields: Array<{
		prop: string;
		label: string;
		type: "input" | "select" | "number" | "textarea" | "Dropdown";
		options?: Array<{
			label: string;
			value: string | number;
		}>;
		rules?: Array<any>;
	}>;
	tableData?: Array<any>;
	api?: {
		list?: (params: any) => Promise<any>;
		add?: (data: any) => Promise<any>;
		update?: (data: any) => Promise<any>;
		delete?: (id: string | number) => Promise<any>;
		batchDelete?: (ids: Array<string | number>) => Promise<any>;
		export?: () => Promise<any>;
		import?: (file: File) => Promise<any>;
	};
	immediate?: boolean;
}
const searchField = ref("");
const searchKeyword = ref("");
// 定义默认值
const props = withDefaults(defineProps<Props>(), {
	title: "基础配置",
	immediate: true,
	tableData: () => [],
	showEditButton: false,
});
// 定义事件
const emit = defineEmits([
	"add-success",
	"update-success",
	"delete-success",
	"import-success",
	"export-success",
	"row-click",
]);

// 表格数据
const loading = ref(false);
const tableData = ref<any[]>([]);
const selectedRows = ref<any[]>([]);
const total = ref(0);
const currentPage = ref(1);
const pageSize = ref(10);

// 表格列筛选
const columnFilter = ref<string[]>([]);
// const visibleColumns = computed(() => {
// 	if (columnFilter.value.length === 0) {
// 		return props.columns.filter((col) => !col.fixed);
// 	}
// 	return props.columns.filter((col) => columnFilter.value.includes(col.prop) || col.fixed);
// });

// 初始化列筛选
watch(
	() => props.columns,
	(newCols) => {
		if (newCols.length > 0) {
			// 设置默认搜索字段为第一个非固定列
			const firstNonFixedCol = newCols.find((col) => !col.fixed);
			if (firstNonFixedCol) {
				searchField.value = firstNonFixedCol.prop;
			}
		}
	},
	{ immediate: true },
);
watch(searchKeyword, (newValue) => {
	if (newValue === "") {
		handleSearch();
	}
});
// 弹窗
const dialogVisible = ref(false);
const dialogType = ref<"add" | "edit" | "view">("add");
const formRef = ref<FormInstance>();
const formData = ref<Record<string, any>>({});
const currentId = ref<string | number>("");

// 导入
const importDialogVisible = ref(false);
const fileList = ref<UploadFile[]>([]);

// 根据表单字段生成校验规则
const formRules = computed(() => {
	const rules: Record<string, any> = {};
	props.formFields.forEach((field) => {
		if (field.rules) {
			rules[field.prop] = field.rules;
		} else {
			// 默认必填规则
			rules[field.prop] = [
				{
					required: true,
					message: `请${field.type === "select" ? "选择" : "输入"}${field.label}`,
					trigger: field.type === "select" ? "select" : "blur",
				},
			];
		}
	});
	return rules;
});

// 初始化方法
onMounted(() => {
	if (props.immediate) {
		fetchData();
	}
});

// 加载表格数据
const fetchData = async () => {
	loading.value = true;
	try {
		// 如果直接传入了tableData，则使用传入的数据
		if (props.tableData && props.tableData.length > 0) {
			// 根据搜索字段和关键字过滤数据
			const filteredData = props.tableData.filter((item) => {
				if (!searchKeyword.value) return true;

				// 如果选择了特定字段，只在该字段中搜索
				if (searchField.value) {
					const fieldValue = item[searchField.value];
					return (
						fieldValue !== undefined && String(fieldValue).toLowerCase().includes(searchKeyword.value.toLowerCase())
					);
				}

				// 否则在所有字段中搜索
				return Object.values(item).some(
					(val) => val !== undefined && String(val).toLowerCase().includes(searchKeyword.value.toLowerCase()),
				);
			});

			tableData.value = filteredData;
			total.value = filteredData.length;
		}
		// 否则尝试调用API获取数据
		else if (props.api?.list) {
			// 模拟API调用延迟
			await new Promise((resolve) => setTimeout(resolve, 500));

			const params = {
				page: currentPage.value,
				pageSize: pageSize.value,
				keyword: searchKeyword.value,
				field: searchField.value, // 添加搜索字段参数
			};

			const res = await props.api.list(params);
			if (res.code === 200) {
				tableData.value = res.data.records || res.data.list || res.data;
				total.value = res.data.total || tableData.value.length;
			} else {
				ElMessage.error(res.message || "获取数据失败");
			}
		} else {
			// 如果没有API也没有tableData，提示用户配置数据源
			console.warn("未配置数据源，请传入tableData或配置api.list方法");
			tableData.value = [];
			total.value = 0;
		}
	} catch (error) {
		console.error("获取数据失败", error);
		ElMessage.error("获取数据失败");
	} finally {
		loading.value = false;
	}
};

// 表格选择事件
const handleSelectionChange = (selection: any[]) => {
	selectedRows.value = selection;
};

// 分页事件
const handleSizeChange = () => {
	currentPage.value = 1;
	fetchData();
};

const handleCurrentChange = () => {
	fetchData();
};

// 新增事件
const handleAdd = () => {
	dialogType.value = "add";
	dialogVisible.value = true;
	formData.value = {};
};

// 编辑事件
const handleEdit = () => {
	if (selectedRows.value.length !== 1) {
		ElMessage.warning("请选择一条记录进行编辑");
		return;
	}

	dialogType.value = "edit";
	currentId.value = selectedRows.value[0].id;
	formData.value = { ...selectedRows.value[0] };
	dialogVisible.value = true;
};

// 查看事件
const handleView = () => {
	if (selectedRows.value.length !== 1) {
		ElMessage.warning("请选择一条记录进行查看");
		return;
	}

	dialogType.value = "view";
	formData.value = { ...selectedRows.value[0] };
	dialogVisible.value = true;
};

// 行编辑事件
const handleRowEdit = (row: any) => {
	dialogType.value = "edit";
	currentId.value = row.id;
	formData.value = { ...row };
	dialogVisible.value = true;
};

// 行删除事件
const handleRowDelete = (row: any) => {
	ElMessageBox.confirm("确定要删除此条记录吗？", "提示", {
		confirmButtonText: "确定",
		cancelButtonText: "取消",
		type: "warning",
	})
		.then(async () => {
			if (!props.api?.delete) return;

			try {
				const res = await props.api.delete(row.id);
				if (res.code === 200) {
					ElMessage.success("删除成功");
					fetchData();
					emit("delete-success");
				} else {
					ElMessage.error(res.message || "删除失败");
				}
			} catch (error) {
				console.error("删除失败", error);
				ElMessage.error("删除失败");
			}
		})
		.catch(() => {
			// 取消删除
		});
};

// 批量删除事件
const handleBatchDelete = () => {
	if (selectedRows.value.length === 0) {
		ElMessage.warning("请至少选择一条记录进行删除");
		return;
	}

	ElMessageBox.confirm(`确定要删除选中的 ${selectedRows.value.length} 条记录吗？`, "提示", {
		confirmButtonText: "确定",
		cancelButtonText: "取消",
		type: "warning",
	})
		.then(async () => {
			if (!props.api?.batchDelete) return;

			const ids = selectedRows.value.map((row) => row.id);
			try {
				const res = await props.api.batchDelete(ids);
				if (res.code === 200) {
					ElMessage.success("批量删除成功");
					fetchData();
					emit("delete-success");
				} else {
					ElMessage.error(res.message || "批量删除失败");
				}
			} catch (error) {
				console.error("批量删除失败", error);
				ElMessage.error("批量删除失败");
			}
		})
		.catch(() => {
			// 取消删除
		});
};

// 导出事件
const handleExport = async () => {
	if (!props.api?.export) {
		ElMessage.warning("导出功能未配置");
		return;
	}

	try {
		const res = await props.api.export();
		if (res.code === 200) {
			// 处理文件下载
			const blob = new Blob([res.data], { type: "application/vnd.ms-excel" });
			const url = URL.createObjectURL(blob);
			const link = document.createElement("a");
			link.href = url;
			link.download = `${props.title}_${new Date().getTime()}.xlsx`;
			link.click();
			URL.revokeObjectURL(url);

			ElMessage.success("导出成功");
			emit("export-success");
		} else {
			ElMessage.error(res.message || "导出失败");
		}
	} catch (error) {
		console.error("导出失败", error);
		ElMessage.error("导出失败");
	}
};

// 导入事件
const handleImport = () => {
	importDialogVisible.value = true;
	fileList.value = [];
};

// 文件变更事件
const handleFileChange = (file: UploadFile) => {
	fileList.value = [file];
};

// 上传Excel
const uploadExcel = async () => {
	if (fileList.value.length === 0) {
		ElMessage.warning("请选择文件");
		return;
	}

	if (!props.api?.import) {
		ElMessage.warning("导入功能未配置");
		return;
	}

	const file = fileList.value[0].raw;
	if (!file) return;

	try {
		const res = await props.api.import(file);
		if (res.code === 200) {
			ElMessage.success("导入成功");
			importDialogVisible.value = false;
			fetchData();
			emit("import-success");
		} else {
			ElMessage.error(res.message || "导入失败");
		}
	} catch (error) {
		console.error("导入失败", error);
		ElMessage.error("导入失败");
	}
};

// 提交表单
const submitForm = async () => {
	if (!formRef.value) return;

	await formRef.value.validate(async (valid) => {
		if (!valid) return;

		if (dialogType.value === "add") {
			if (!props.api?.add) return;

			try {
				const res = await props.api.add(formData.value);
				if (res.code === 200) {
					ElMessage.success("添加成功");
					dialogVisible.value = false;
					fetchData();
					emit("add-success");
				} else {
					ElMessage.error(res.message || "添加失败");
				}
			} catch (error) {
				console.error("添加失败", error);
				ElMessage.error("添加失败");
			}
		} else if (dialogType.value === "edit") {
			if (!props.api?.update) return;

			try {
				const res = await props.api.update({ ...formData.value, id: currentId.value });
				if (res.code === 200) {
					ElMessage.success("更新成功");
					dialogVisible.value = false;
					fetchData();
					emit("update-success");
				} else {
					ElMessage.error(res.message || "更新失败");
				}
			} catch (error) {
				console.error("更新失败", error);
				ElMessage.error("更新失败");
			}
		}
	});
};

// 重置表单
const resetForm = () => {
	if (formRef.value) {
		formRef.value.resetFields();
	}
	formData.value = {};
	currentId.value = "";
};
const handleSearch = () => {
	currentPage.value = 1;
	fetchData();
};

watch(
	() => props.tableData,
	(newVal) => {
		console.log("BaseTable received new tableData:", newVal);
	},
	{ deep: true },
);

// 提供给父组件使用的方法
defineExpose({
	fetchData,
	resetForm,
});
</script>

<style scoped lang="scss">
.base-config-table {
	width: 100%;

	.header {
		margin-bottom: 20px;

		h2 {
			font-size: 20px;
			font-weight: 600;
			color: #303133;
			margin: 0;
		}
	}

	.tool-bar {
		display: flex;
		justify-content: space-between;
		align-items: center;
		margin-bottom: 20px;

		.left-buttons {
			display: flex;
			gap: 10px;
			flex-wrap: wrap;
		}

		.right-tools {
			min-width: 200px;
		}
	}

	.pagination-container {
		margin-top: 20px;
		display: flex;
		justify-content: flex-end;
	}

	.upload-excel {
		display: flex;
		justify-content: center;

		.el-upload__tip {
			margin-top: 8px;
			color: #909399;
		}
	}
	.tool-bar {
		display: flex;
		justify-content: space-between;
		align-items: center;
		margin-bottom: 20px;

		.left-buttons {
			display: flex;
			gap: 10px;
			flex-wrap: wrap;
		}

		.right-tools {
			display: flex;
			gap: 10px;
			align-items: center;

			.filter-select {
				width: 240px;
			}

			.search-input {
				width: 220px;
			}
		}
	}
}
</style>
