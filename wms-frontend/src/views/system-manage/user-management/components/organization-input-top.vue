<template>
	<el-dialog :model-value="dep" @update:model-value="handleDialogChange" draggable title="组织机构列表">
		<el-tree
			style="max-width: 600px"
			:props="props"
			:data="data"
			show-checkbox
			check-strictly
			node-key="label"
			@check-change="handleCheckChange"
			@current-change="handleCurrentChange"
		/>
		<template #footer>
			<span class="dialog-footer">
				<el-button type="primary" @click="btnInConfirm">确定</el-button>
				<el-button @click="dep = false">关闭</el-button>
			</span>
		</template>
	</el-dialog>
</template>

<script setup>
import { ref, onMounted, defineModel } from "vue";
import { getOrgNameTreeAPI } from "@/apis/sysmanager-ok/index.js";

const emit = defineEmits(["getDep"]);

// 使用 defineModel实现双向绑定
const dep = defineModel("dep");

const DepartmentNamesIds1 = defineModel("DepartmentNamesIds1");

// 由于departmentNames可以不止一个
const departmentNamesList = ref([]);

const props = {
	label: "departname",
};

const data = ref([]);

// 监听 visible 属性的变化
watch(
	() => dep.value,
	(newVal) => {
		if (newVal) {
			departmentNamesList.value = [];
			getNoticeList();
		}
	},
);

// 获取组织名称树
const getNoticeList = async () => {
	const res = await getOrgNameTreeAPI();
	data.value = res.data.rows;
};

// 处理可见性变化
const handleDialogChange = (value) => {
	// console.log("点击关闭", value);
	dep.value = value;
};

// 最里面对话框的确定按钮
const btnInConfirm = () => {
	DepartmentNamesIds1.value = departmentNamesList.value.map((item) => ({
		id: item.id,
		departname: item.departname,
	}));

	dep.value = false;
};

// 节点复选框被点击时候触发
const handleCheckChange = (data, checked) => {
	if (checked) {
		// 如果复选框被选中，添加节点数据
		departmentNamesList.value.push(data);
	} else {
		// 如果复选框被取消选中，移除节点数据
		departmentNamesList.value = departmentNamesList.value.filter((item) => item.id !== data.id);
	}
	console.log("节点触发departmentNamesList.value", departmentNamesList.value);
};
</script>

<style lang="scss" scoped></style>
