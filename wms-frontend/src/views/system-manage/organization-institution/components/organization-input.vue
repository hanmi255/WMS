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

// 使用 defineModel实现双向绑定
const org = defineModel("org");
const departmentNames = defineModel("departmentNames");

// 由于departmentNames可以不止一个
const departmentNamesList = ref([]);

const props = {
	children: "children",
	label: "label",
};

const data = ref([
	{
		label: "1",
	},
	{
		label: "2",
	},
	{
		label: "3",
	},
	{
		label: "广州华壹智能科技有限公司",
		children: [
			{
				label: "4",
			},
			{
				label: "5",
			},
		],
	},
]);

// 处理可见性变化
const handleDialogChange = (value) => {
	console.log("点击关闭", value);
	org.value = value;
};

// 最里面对话框的确定按钮
const btnInConfirm = () => {
	departmentNames.value = departmentNamesList.value;
	departmentNamesList.value = [];
	org.value = false;
};

// 节点复选框被点击时候触发
const handleCheckChange = (data) => {
	departmentNamesList.value.push(data.label);
	console.log(data);
};
</script>

<style lang="scss" scoped></style>
