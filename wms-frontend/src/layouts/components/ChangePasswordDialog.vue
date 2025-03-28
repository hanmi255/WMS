<template>
	<el-dialog
		:model-value="modelValue"
		title="修改密码"
		width="30%"
		:before-close="handleClose"
		@update:model-value="handleUpdateVisible"
	>
		<el-form :model="form" label-width="100px">
			<el-form-item label="原密码">
				<el-input v-model="form.oldPassword" type="password" placeholder="请输入原密码" />
			</el-form-item>
			<el-form-item label="新密码">
				<el-input v-model="form.newPassword" type="password" placeholder="密码至少6个字符,最多18个字符！" />
			</el-form-item>
			<el-form-item label="重复密码">
				<el-input v-model="form.repeatPassword" type="password" placeholder="请重复新密码" />
			</el-form-item>
		</el-form>
		<template #footer>
			<el-button @click="handleClose">关闭</el-button>
			<el-button type="primary" @click="handleSubmit">确定</el-button>
		</template>
	</el-dialog>
</template>

<script lang="ts" setup>
import { ref } from "vue";

const { modelValue } = defineProps({
	modelValue: {
		type: Boolean,
		required: true,
	},
});

const emit = defineEmits(["update:modelValue"]);

const form = ref({
	oldPassword: "",
	newPassword: "",
	repeatPassword: "",
});

const handleClose = () => {
	emit("update:modelValue", false);
};

const handleSubmit = () => {
	if (form.value.newPassword !== form.value.repeatPassword) {
		alert("新密码和重复密码不一致！");
		return;
	}
	alert("密码修改成功！");
	handleClose();
};

const handleUpdateVisible = (value: boolean) => {
	emit("update:modelValue", value);
};
</script>
