<script lang="ts" setup>
import { ref, computed, watch } from "vue";

definePage({
	meta: {
		menuType: "page",
		text: "盘点差异",
		icon: "IconSetting",
	},
});

// console.log(getRoutes());
console.log(` 进入了 盘点差异 `);
</script>

<template>
	<section class="inventory-difference-root">
		<h2>盘点差异</h2>
	</section>
</template>

<style lang="scss" scoped>
.inventory-difference-root {
}
</style>
