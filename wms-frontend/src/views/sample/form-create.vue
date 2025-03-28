<template>
	<fc-designer ref="designer" height="88vh" />
</template>

<script setup>
definePage({
	meta: {
		menuType: "page",
		isSample: true,
		text: "可视化表单演示",
		icon: "IconSetting",
	},
});

import "element-plus/dist/index.css";
import { ref } from "vue";
const designer = ref(null);
</script>
