<script lang="ts" setup>
import { ref, computed, watch } from "vue";

definePage({
	meta: {
		menuType: "page",
		text: "效期预警",
		icon: "IconSetting",
	},
});
</script>

<template>
	<section class="validity-warn-root">
		<h2>效期预警</h2>
	</section>
</template>

<style lang="scss" scoped>
.validity-warn-root {
}
</style>
