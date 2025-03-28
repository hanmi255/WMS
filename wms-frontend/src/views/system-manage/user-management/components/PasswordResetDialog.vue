<template>
	<el-dialog :visible.sync="dialogVisible" title="密码重置">
		<template #content>
			<el-form :model="resetForm" ref="resetFormRef" label-width="120px">
				<el-form-item label="新密码" prop="newPassword">
					<el-input v-model="resetForm.newPassword" placeholder="请输入新密码" type="password" />
				</el-form-item>
				<el-form-item label="确认密码" prop="confirmPassword">
					<el-input v-model="resetForm.confirmPassword" placeholder="请再次输入新密码" type="password" />
				</el-form-item>
			</el-form>
		</template>
		<template #footer>
			<el-button @click="dialogVisible = false">取消</el-button>
			<el-button type="primary" @click="handleResetPassword">确定</el-button>
		</template>
	</el-dialog>
</template>

<script lang="ts" setup>
import { ref, reactive } from "vue";
import { ElMessage, ElForm } from "element-plus";

// 控制对话框的显示与隐藏
const dialogVisible = ref(false);

// 表单数据
const resetForm = reactive({
	newPassword: "",
	confirmPassword: "",
});

// 表单引用
const resetFormRef = ref<InstanceType<typeof ElForm>>();

// 打开对话框的方法
const open = () => {
	dialogVisible.value = true;
	// 清空表单数据
	resetForm.newPassword = "";
	resetForm.confirmPassword = "";
};

// 处理密码重置逻辑
const handleResetPassword = () => {
	if (resetForm.newPassword !== resetForm.confirmPassword) {
		ElMessage.error("两次输入的密码不一致，请重新输入");
		return;
	}
	// 这里可以添加实际的密码重置请求逻辑，例如调用 API
	console.log("新密码:", resetForm.newPassword);
	ElMessage.success("密码重置成功");
	dialogVisible.value = false;
};

// 导出 open 方法，供外部调用
defineExpose({
	open,
});
</script>

<style scoped>
/* 可以在这里添加样式 */
</style>
