<script lang="ts" setup>
import { ref, computed, watch } from "vue";

definePage({
	meta: {
		menuType: "page",
		text: "动仓盘点",
		icon: "IconSetting",
	},
});

// console.log(getRoutes());
console.log(` 进入了 动仓盘点 `);
</script>

<template>
	<section class="moving-count-root">
		<h2>动仓盘点</h2>
	</section>
</template>

<style lang="scss" scoped>
.moving-count-root {
}
</style>
