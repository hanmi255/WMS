<script lang="ts" setup>
import { ref, computed, watch } from "vue";

definePage({
	meta: {
		menuType: "page",
		text: "上架调整",
		icon: "IconSetting",
	},
});

// console.log(getRoutes());
console.log(` 进入了 上架调整 `);
</script>

<template>
	<section class="shelf-adjustment-root">
		<h2>上架调整</h2>
	</section>
</template>

<style lang="scss" scoped>
.shelf-adjustment-root {
}
</style>
