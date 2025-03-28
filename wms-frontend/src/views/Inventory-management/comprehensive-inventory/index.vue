<script lang="ts" setup>
import { ref, computed, watch } from "vue";

definePage({
	meta: {
		menuType: "page",
		text: "综合盘点",
		icon: "IconSetting",
	},
});

// console.log(getRoutes());
console.log(` 进入了 综合盘点 `);
</script>

<template>
	<section class="comprehensive-inventory-root">
		<h2>综合盘点</h2>
	</section>
</template>

<style lang="scss" scoped>
.comprehensive-inventory-root {
}
</style>
