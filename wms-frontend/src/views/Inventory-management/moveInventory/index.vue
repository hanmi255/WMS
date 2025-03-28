<script lang="ts" setup>
import { ref, computed, watch } from "vue";

definePage({
	meta: {
		menuType: "page",
		text: "动碰盘",
		icon: "IconSetting",
	},
});

// console.log(getRoutes());
console.log(` 进入了 动碰盘 `);
</script>

<template>
	<section class="moveInventory-root">
		<h2>动碰盘</h2>
	</section>
</template>

<style lang="scss" scoped>
.inventory-difference-root {
}
</style>
