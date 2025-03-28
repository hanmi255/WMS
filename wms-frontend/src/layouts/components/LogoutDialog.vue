<template>
	<el-dialog v-model="visible" title="提示" width="30%" :before-close="handleClose">
		<span>确定退出该系统吗？</span>
		<template #footer>
			<el-button @click="handleClose">取消</el-button>
			<el-button type="primary" @click="handleConfirm">确定</el-button>
		</template>
	</el-dialog>
</template>

<script lang="ts" setup>
import { ref } from "vue";
import { useRouter } from "vue-router";
import { useUserStore } from "stores/user"; // 假设你使用了 Pinia 管理用户状态

const visible = ref(false);
const router = useRouter();
const userStore = useUserStore();

const showDialog = () => {
	visible.value = true;
};

const handleClose = () => {
	visible.value = false;
};

const handleConfirm = () => {
	// 清除用户信息
	userStore.clearUser(); // 假设你在 userStore 中有一个 clearUser 方法
	// 跳转到登录页面
	router.push("/login"); // 假设登录页面的路由是 '/login'
	visible.value = false;
};

defineExpose({
	showDialog,
});
</script>
