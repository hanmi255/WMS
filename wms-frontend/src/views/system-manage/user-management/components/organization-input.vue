<template>
	<el-dialog :model-value="org" @update:model-value="handleDialogChange" draggable title="组织机构列表">
		<el-tree style="max-width: 600px" :props="props" :data="data" show-checkbox @check-change="handleCheckChange" />
		<template #footer>
			<span class="dialog-footer">
				<el-button type="primary" @click="btnInConfirm">确定</el-button>
				<el-button @click="org = false">关闭</el-button>
			</span>
		</template>
	</el-dialog>
</template>

<script setup>
import { ref, onMounted, defineModel } from "vue";
import { getOrgNameTreeAPI } from "@/apis/sysmanager-ok/index.js";

// 使用 defineModel实现双向绑定
const org = defineModel("org");

const DepartmentNamesIds = defineModel("DepartmentNamesIds");

// 由于departmentNames可以不止一个
const departmentNamesList = ref([]);

const props = {
	label: "departname",
};

const data = ref([]);

// 监听 visible 属性的变化
watch(
	() => org.value,
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
	console.log("点击关闭", value);
	org.value = value;
};

// 最里面对话框的确定按钮
const btnInConfirm = () => {
	DepartmentNamesIds.value = departmentNamesList.value.map((item) => ({
		id: item.id,
		departname: item.departname,
	}));
	org.value = false;
};

// 节点复选框被点击时候触发
const handleCheckChange = (data) => {
	departmentNamesList.value.push(data);
};
</script>

<style lang="scss" scoped></style>
