<template>
	<el-dialog :model-value="visible" title="系统消息" width="600" draggable @update:model-value="updateVisible">
		<!-- 表格 -->
		<el-table :data="messages" style="width: 100%">
			<el-table-column prop="content" label="内容" />
			<el-table-column prop="time" label="发送时间" width="180" />
		</el-table>

		<!-- 如果消息列表为空，显示占位符 -->
		<div v-if="messages.length === 0" class="empty-placeholder">暂无系统信息！</div>

		<!-- 底部按钮 -->
		<template #footer>
			<div class="dialog-footer">
				<el-button @click="handleCancel">关闭</el-button>
			</div>
		</template>
	</el-dialog>
</template>

<script setup lang="ts">
import { defineProps, defineEmits } from "vue";

// 定义 Props
defineProps<{
	visible: boolean; // 控制弹框显示
	messages: any[]; // 消息列表
}>();

// 定义 Emits
const emit = defineEmits(["update:visible"]);

// 关闭弹框
const handleCancel = () => {
	emit("update:visible", false);
};

// 更新 visible 状态
const updateVisible = (value: boolean) => {
	emit("update:visible", value);
};
</script>

<style lang="scss" scoped>
.dialog-footer {
	text-align: right;
}

.empty-placeholder {
	text-align: center;
	padding: 20px;
	color: #999;
}
</style>
