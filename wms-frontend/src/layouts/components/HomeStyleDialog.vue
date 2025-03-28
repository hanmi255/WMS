<template>
	<el-dialog :model-value="visible" title="首页风格" width="400px" draggable @update:model-value="updateVisible">
		<!-- 风格选项 -->
		<div class="style-options">
			<el-radio-group v-model="selectedStyle">
				<el-radio v-for="style in styles" :key="style.value" :label="style.value">
					{{ style.label }}
				</el-radio>
			</el-radio-group>
		</div>

		<!-- 底部按钮 -->
		<template #footer>
			<div class="dialog-footer">
				<el-button @click="handleConfirm">确定</el-button>
				<el-button @click="handleCancel">关闭</el-button>
			</div>
		</template>
	</el-dialog>
</template>

<script setup lang="ts">
import { ref, defineProps, defineEmits } from "vue";
import { ElMessage } from "element-plus"; // 引入 ElMessage

// 定义 Props
defineProps<{
	visible: boolean; // 控制弹框显示
}>();

// 定义 Emits
const emit = defineEmits(["update:visible", "confirm"]);

// 风格选项
const styles = ref([
	{ value: "ace", label: "ACE平面风格" },
	{ value: "shortcut", label: "ShortCut风格" },
	{ value: "classic", label: "经典风格" },
	{ value: "hplus", label: "H+平面风格" },
]);

// 选中的风格（单选）
const selectedStyle = ref("");

// 确定按钮
const handleConfirm = () => {
	emit("confirm", selectedStyle.value);
	emit("update:visible", false);

	// 显示提示信息
	ElMessage.success("样式修改成功，请刷新页面");

	// 刷新页面
	setTimeout(() => {
		window.location.reload();
	}, 1500); // 1.5秒后刷新页面
};

// 关闭按钮
const handleCancel = () => {
	emit("update:visible", false);
};

// 更新 visible 状态
const updateVisible = (value: boolean) => {
	emit("update:visible", value);
};
</script>

<style lang="scss" scoped>
.style-options {
	display: flex;
	flex-direction: column;
	gap: 10px;
}

.dialog-footer {
	text-align: right;
}
</style>
