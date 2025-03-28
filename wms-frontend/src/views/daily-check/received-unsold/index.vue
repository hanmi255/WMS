<script lang="ts" setup>
import { ref, computed, watch } from "vue";

definePage({
	meta: {
		menuType: "page",
		text: "收货未上架",
		icon: "IconSetting",
	},
});
</script>

<template>
	<section class="received-unsold-root">
		<h2>收货未上架</h2>
	</section>
</template>

<style lang="scss" scoped>
.received-unsold-root {
}
</style>
