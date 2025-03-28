<template>
	<div>
		<h3>弹窗组件测试页面</h3>

		<!-- 多个按钮 -->
		<el-button type="primary" @click="openPopup(1)"> 录入</el-button>
		<el-button type="primary" @click="openPopup(2)">编辑</el-button>
		<el-button type="warning" @click="openPopup(3)">批量删除</el-button>
		<el-button type="info" @click="openPopup(4)">查看</el-button>

		<!-- 弹窗组件 -->
		<Popup v-model:visible="showPopup" :title="popupTitle">
			<p>{{ popupContent }}</p>
		</Popup>
	</div>
</template>

<script setup lang="ts">
definePage({
	meta: {
		menuType: "page",
		isSample: true,
		text: "弹窗组件",
		icon: "IconSetting",
	},
});

import { ref } from "vue";
import { ElButton } from "element-plus";
import Popup from "@/components/popup/Popup.vue";

// 控制弹窗显示状态
const showPopup = ref(false);

// 弹窗标题和内容
const popupTitle = ref("");
const popupContent = ref("");

// 打开弹窗
const openPopup = (buttonId: number) => {
	switch (buttonId) {
		case 1:
			popupTitle.value = "录入";
			popupContent.value = "内容。";
			break;
		case 2:
			popupTitle.value = "编辑";
			popupContent.value = "内容。";
			break;
		case 3:
			popupTitle.value = "批量删除";
			popupContent.value = "内容。";
			break;
		case 4:
			popupTitle.value = "查看";
			popupContent.value = "内容。";
			break;
		default:
			popupTitle.value = "默认弹窗";
			popupContent.value = "内容。";
	}

	showPopup.value = true; // 显示弹窗
};
</script>

<style scoped>
h3 {
	margin-bottom: 20px;
}

/* 按钮间距 */
.el-button {
	margin-right: 10px;
}
</style>
