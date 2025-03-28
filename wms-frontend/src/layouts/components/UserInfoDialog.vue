<template>
	<el-dialog
		:model-value="visible"
		title="个人信息"
		width="30%"
		:before-close="handleClose"
		@update:model-value="handleUpdateVisible"
	>
		<el-form :model="form" label-width="100px">
			<el-form-item label="用户账号">
				<el-input v-model="form.username" disabled />
			</el-form-item>
			<el-form-item label="姓名">
				<el-input v-model="form.name" />
			</el-form-item>
			<el-form-item label="手机号码">
				<el-input v-model="form.phone" />
			</el-form-item>
			<el-form-item label="邮箱">
				<el-input v-model="form.email" />
			</el-form-item>
		</el-form>
		<template #footer>
			<el-button @click="handleClose">关闭</el-button>
			<el-button type="primary" @click="handleSubmit">保存</el-button>
		</template>
	</el-dialog>
</template>

<script lang="ts" setup>
import { ref } from "vue";

const { visible } = defineProps({
	visible: {
		type: Boolean,
		required: true,
	},
});

const emit = defineEmits(["update:visible"]);

const form = ref({
	username: "admin",
	name: "管理员",
	phone: "",
	email: "",
});

const handleClose = () => {
	emit("update:visible", false);
};

const handleSubmit = () => {
	// 这里可以添加保存逻辑
	alert("个人信息已保存！");
	handleClose();
};

const handleUpdateVisible = (value: boolean) => {
	emit("update:visible", value);
};
</script>

<style scoped>
.el-form-item {
	margin-bottom: 20px;
}
</style>
