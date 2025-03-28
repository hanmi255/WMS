<script lang="ts" setup>
import { Box } from "@element-plus/icons-vue";
definePage({
	meta: {
		menuType: "folder",
		text: "基础配置",
		icon: Box,
	},
});
</script>

<template>
	<section class="outbound-root">
		<RouterView></RouterView>
	</section>
</template>

<style lang="scss" scoped>
.outbound-root {
}
</style>
