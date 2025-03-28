<script lang="ts" setup>
import { ref, computed, watch } from "vue";

definePage({
	meta: {
		menuType: "page",
		text: "出货延迟预警",
		icon: "IconSetting",
	},
});
</script>

<template>
	<section class="shipment-delay-warn-root">
		<h2>出货延迟预警</h2>
	</section>
</template>

<style lang="scss" scoped>
.shipment-delay-warn-root {
}
</style>
