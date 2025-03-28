<template>
	<el-dialog v-model="visible" title="提示信息" width="30%" :before-close="handleClose">
		<span>{{ message }}</span>
		<template #footer>
			<el-button type="primary" @click="handleClose">确定</el-button>
		</template>
	</el-dialog>
</template>

<script lang="ts" setup>
import { ref } from "vue";

const visible = ref(false);
const message = ref("");

const showDialog = (msg: string) => {
	message.value = msg;
	visible.value = true;
};

const handleClose = () => {
	visible.value = false;
};

defineExpose({
	showDialog,
});
</script>
