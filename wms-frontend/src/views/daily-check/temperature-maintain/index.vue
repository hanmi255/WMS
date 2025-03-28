<script lang="ts" setup>
import { ref, computed, watch } from "vue";

definePage({
	meta: {
		menuType: "page",
		text: "温度维护",
		icon: "IconSetting",
	},
});
</script>

<template>
	<section class="temperature-maintain-root">
		<h2>温度维护</h2>
	</section>
</template>

<style lang="scss" scoped>
.temperature-maintain-root {
}
</style>
