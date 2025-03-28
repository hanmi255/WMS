<script lang="ts" setup>
import { ref, computed, watch } from "vue";

definePage({
	meta: {
		menuType: "page",
		text: "盘点差异过账",
		icon: "IconSetting",
	},
});

// console.log(getRoutes());
console.log(` 进入了 盘点差异过账 `);
</script>

<template>
	<section class="differential-posting-root">
		<h2>盘点差异过账</h2>
	</section>
</template>

<style lang="scss" scoped>
.differential-posting-root {
}
</style>
