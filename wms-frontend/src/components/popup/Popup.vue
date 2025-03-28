<template>
	<!-- 蒙层 -->
	<div v-show="props.visible" class="popup-layer-mask">
		<!-- 弹框主体 -->
		<div class="popup-body" :style="{ transform: `translate(${offsetX}px, ${offsetY}px)` }">
			<!-- 标题 -->
			<div class="popup-title" @mousedown="startDrag">
				<h3>{{ props.title }}</h3>
				<button class="close-btn" @click="closepopup">x</button>
			</div>
			<!-- 内容区域 -->
			<div class="popup-content">
				<!-- 插槽用于传递内容 -->
				<slot></slot>
			</div>
			<!-- 底部按钮 -->
			<div class="popup-bottom-button">
				<button @click="ok">确定</button>
				<button @click="closepopup">关闭</button>
			</div>
		</div>
	</div>
</template>

<script setup lang="ts">
import { ref, onUnmounted } from "vue";

const props = defineProps({
	visible: {
		type: Boolean,
		default: false,
	},
	title: {
		type: String,
		default: "提示",
	},
});

const emit = defineEmits(["update:visible", "close", "confirm"]);

// 拖拽相关状态
const offsetX = ref(0); // 弹框的 X 偏移量
const offsetY = ref(0); // 弹框的 Y 偏移量
const isDragging = ref(false); // 是否正在拖拽
const startX = ref(0); // 拖拽起始点 X 坐标
const startY = ref(0); // 拖拽起始点 Y 坐标

// 开始拖拽
const startDrag = (e: MouseEvent) => {
	isDragging.value = true;
	startX.value = e.clientX - offsetX.value;
	startY.value = e.clientY - offsetY.value;

	// 监听 mousemove 和 mouseup 事件
	window.addEventListener("mousemove", onDrag);
	window.addEventListener("mouseup", stopDrag);
};

// 拖拽中
const onDrag = (e: MouseEvent) => {
	if (!isDragging.value) return;

	// 计算偏移量
	offsetX.value = e.clientX - startX.value;
	offsetY.value = e.clientY - startY.value;

	// 限制拖拽范围
	const { innerWidth, innerHeight } = window;
	offsetX.value = Math.max(-innerWidth / 2, Math.min(offsetX.value, innerWidth / 2));
	offsetY.value = Math.max(-innerHeight / 2, Math.min(offsetY.value, innerHeight / 2));
};

// 结束拖拽
const stopDrag = () => {
	isDragging.value = false;

	// 移除事件监听
	window.removeEventListener("mousemove", onDrag);
	window.removeEventListener("mouseup", stopDrag);
};

// 关闭弹框
const closepopup = () => {
	emit("update:visible", false);
	emit("close");
};

// 点击确定按钮
const ok = () => {
	emit("confirm");
	closepopup();
};

// 组件卸载时移除事件监听
onUnmounted(() => {
	window.removeEventListener("mousemove", onDrag);
	window.removeEventListener("mouseup", stopDrag);
});
</script>

<style scoped>
/* 蒙层样式 */
.popup-layer-mask {
	position: fixed;
	top: 0;
	left: 0;
	width: 100%;
	height: 100%;
	background-color: rgba(0, 0, 0, 0.5); /* 半透明黑色 */
	display: flex;
	justify-content: center;
	align-items: center;
	z-index: 1000; /* 确保蒙层在最上层 */
}

/* 主体样式 */
.popup-body {
	width: 400px;
	background-color: white;
	border-radius: 8px;
	box-shadow: 0 2px 8px rgba(0, 0, 0, 0.3);
	position: relative; /* 确保 transform 生效 */
}

.popup-title {
	padding: 16px;
	border-bottom: 1px solid #eee;
	display: flex;
	justify-content: space-between;
	align-items: center;
	cursor: move; /* 拖拽时显示可移动光标 */
}

.popup-content {
	padding: 16px;
}

.popup-bottom-button {
	padding: 16px;
	border-top: 1px solid #eee;
	text-align: right;
}

/* 关闭按钮样式 */
.close-btn {
	cursor: pointer;
	background: none;
	border: none;
	font-size: 16px;
}

.close-btn:hover {
	color: #f00; /* 鼠标悬停时变红色 */
}
</style>
