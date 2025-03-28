<script lang="ts" setup>
import { ref, computed, watch } from "vue";

definePage({
	meta: {
		menuType: "page",
		text: "盘点",
		icon: "IconSetting",
	},
});

// console.log(getRoutes());
console.log(` 进入了 盘点 `);
</script>

<template>
	<section class="inventory-root">
		<h2>盘点</h2>
	</section>
</template>

<style lang="scss" scoped>
.inventory-root {
}
</style>
