<script lang="ts" setup>
import { Box } from "@element-plus/icons-vue";
definePage({
	meta: {
		menuType: "folder",
		text: "仓库管理",
		icon: Box,
	},
});
</script>

<template>
	<section class="ware-config-root">
		<RouterView></RouterView>
	</section>
</template>

<style lang="scss" scoped>
.ware-config-root {
}
</style>
