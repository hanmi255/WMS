<template>
	<el-dialog
		style="height: 700px"
		:model-value="showName"
		@update:model-value="handleDialogChange"
		title="用户名称"
		class="content"
		width="1200px"
	>
		<h4>组织机构</h4>
		<el-row>
			<el-col :span="5">
				<el-tree
					ref="treeRef"
					style="max-width: 600px; border-right: 1px solid #efefef; height: 100%; margin-right: 10px"
					:props="props"
					:data="dataTree"
					check-strictly
					node-key="label"
					@check-change="handleCheckChange"
					@current-change="handleCurrentChange"
				/>
			</el-col>
			<el-col :span="19">
				<p>用户选择</p>
				<TableTitle v-model="titleData" @user-click="userChildClick" @select-click="selectChildClick" />
				<ComponentsTable
					v-bind="tableProps"
					@selection-change="multipleSelectRows = $event"
					style="margin-bottom: 250px"
				>
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
					size="small"
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
			</el-col>
		</el-row>
		<template #footer>
			<span class="dialog-footer">
				<el-button type="primary" @click="btnConfirm">确定</el-button>
				<el-button @click="showName = false">关闭</el-button>
			</span>
		</template>
	</el-dialog>
</template>

<script setup>
import TableTitle from "@/components/table-title/TableTitle.vue";
import ComponentsTable from "@/components/table/index.vue";
import { ref, defineModel } from "vue";
import { getOrgNameTreeAPI } from "@/apis/sysmanager-ok/index.js";
import {
	getUserListAPI,
	addUserAPI,
	updateUserAPI,
	deleteUserAPI,
	getUserDetailAPI,
	resetUserPasswordAPI,
	lockUserStatusAPI,
	activeUserStatusAPI,
} from "@/apis/sysmanager-ok/index.js";
const showName = defineModel("showName");
// 添加 treeRef 引用
const treeRef = ref(null);
// 当前选中的节点
const currentNodeKey = ref(null);
// 由于departmentNames可以不止一个
// const departmentNamesList = ref([]);

const dataTree = ref([]);

// 发送到子组件的数据
const titleData = ref({
	unfold: true,
	rightButton: true,
	contentList: [
		{
			name: "用户账号",
			type: "AddSininput",
			content: [""],
		},
	],
	bottomList: [],
});

// 表格内数据
const data = ref([
	{
		username: "admin",
		userKey: "管理员",
		departname: "厦门境图智能科技有限公司,1,",
		roleName: "管理员",
		createDate: "2020-04-15",
		status: "激活",
		departmentNames: "组织机构",
		role: "角色",
		userType: "当前用户权限",
	},
	{
		username: "admin",
		userKey: "管理员",
		departname: "厦门境图智能科技有限公司,1,",
		roleName: "管理员",
		createDate: "2020-04-15",
		status: "激活",
		departmentNames: "组织机构",
		role: "角色",
		userType: "当前用户权限",
	},
]);

// 表格配置
const tableProps = ref({
	isIndex: true,
	isMultipleSelect: true,
	data: data,
	columns: [
		{ prop: "username", label: "用户账号", width: "100px" },
		{ prop: "departname", label: "组织机构", width: "250px" },
		{ prop: "userKey", label: "用户名称", width: "80px" },
		{ prop: "roleName", label: "角色", width: "150px" },
		{ prop: "status", label: "状态", width: "90px" },
		{ prop: "operation-bar", label: "操作", width: "90px" },
	],
});

// 监听 visible 属性的变化
watch(
	() => showName.value,
	async (newVal) => {
		if (newVal) {
			// departmentNamesList.value = [];
			await getNoticeList();
			await getUserList();
		}
	},
);
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
	getUserList(params);
};

// 改变页码
const handlePageIndex = (val) => {
	console.log(val);
	pageIndex.value = val;
	const params = {
		pageIndex: val,
		pageSize: pageSize.value,
	};
	getUserList(params);
};

// 获取组织名称树
const getNoticeList = async () => {
	const res = await getOrgNameTreeAPI();
	dataTree.value = res.data.rows;
};

// 获取用户管理列表
const getUserList = async (params) => {
	const res = await getUserListAPI(
		params || {
			pageIndex: pageIndex.value,
			pageSize: pageSize.value,
		},
	);
	if (res.code === 10000) {
		data.value = res.data.rows;
		data.value = res.data.rows.map((item) => {
			return {
				...item,
				status: item.status === 1 ? "激活" : "锁定",
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
	if (icon.name === "右侧查询") {
		handleSearch();
	}
	if (icon.name === "右侧重置") {
		handleResetData();
	}
};

// 右侧查询
const handleSearch = () => {
	const params = {
		pageIndex: pageIndex.value,
		pageSize: pageSize.value,
	};
	const username = titleData.value.contentList[0].content[0] || "";
	console.log("username", username);
	if (username) {
		params.username = username;
	}
	// const realname = titleData.value.contentList[1].content[0] || "";
	// if (realname) {
	// 	params.realname = realname;
	// }
	// const department = titleData.value.contentList[2].content[0] || "";
	// if (department) {
	// 	params.department = department;
	// }
	getUserList(params);
};

// 右侧重置
const handleResetData = () => {
	titleData.value.contentList[0].content = ["", ""];
	getUserList({
		pageIndex: pageIndex.value,
		pageSize: pageSize.value,
	});
};

// 最里面对话框的确定按钮
// const btnInConfirm = () => {
// 	let checkedNodes = treeRef.value.getCheckedNodes(); // 获取所有选中的节点
// 	console.log("所有选中的节点", checkedNodes);
// 	checkedNodes = checkedNodes.map((item) => item.label);

// 	emit("getDep", checkedNodes);

// 	dep.value = false;
// };

// 节点复选框被点击时候触发
const handleCheckChange = (data, checked) => {
	// 当前
	// console.log(data.label);
	// console.log(typeof data.label);
	if (checked) {
		// 取消其他节点的选中状态
		treeRef.value.setCheckedKeys([]);
		treeRef.value.setChecked(data, true);
	}
};

// 当前选中的节点变化时触发
const handleCurrentChange = (data) => {
	console.log(data.label);
	currentNodeKey.value = data.label;
	// console.log(currentNodeKey.value);
};

// 处理确认删除事件
const handleConfirmDelete = async (row) => {
	console.log("删除的id", row.useId);
	const res = await deleteUserAPI(row.useId);
	if (res.code === 10000) {
		getUserList({ pageIndex: pageIndex.value, pageSize: pageSize.value });
		ElMessage.success("删除成功");
	} else {
		ElMessage.warning(res.message);
	}
};

const btnConfirm = () => {
	showName.value = false;
};

// 处理可见性变化
const handleDialogChange = (value) => {
	// console.log("点击关闭", value);
	showName.value = value;
};
</script>

<style lang="scss" scoped>
// .content {
// 	height: 500px;
// 	width: 100%;
// 	display: flex;
// 	justify-content: center;
// 	.left {
// 		display: flex;
// 		height: 500px;
// 		width: 15%;
// 		// flex: 2;
// 		background-color: red;
// 	}
// 	.right {
// 		display: flex;
// 		height: 500px;
// 		// flex: 8;
// 		width: 75%;
// 		background-color: blue;
// 	}
// }
</style>
