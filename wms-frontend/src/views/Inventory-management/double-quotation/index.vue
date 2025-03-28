<script lang="ts" setup>
import { ref, computed, watch } from "vue";

definePage({
	meta: {
		menuType: "page",
		text: "复盘",
		icon: "IconSetting",
	},
});

// console.log(getRoutes());
console.log(` 进入了 复盘 `);
</script>

<template>
	<section class="double-quotation-root">
		<h2>复盘</h2>
	</section>
</template>

<style lang="scss" scoped>
.double-quotation-root {
}
</style>
