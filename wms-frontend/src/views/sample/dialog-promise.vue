<script lang="ts" setup>
definePage({
	meta: {
		menuType: "page",
		isSample: true,
		text: "命令式弹框",
		icon: "IconSetting",
	},
});

import SimpleFormExample from "components/dialog-promise/tests/simple-form-example.vue";
import FooterSlotExample from "components/dialog-promise/tests/footer-slot-example.vue";
import MiniExample from "components/dialog-promise/tests/mini-example.vue";
</script>

<template>
	<section class="dialog-promise-root">
		<h1>命令式弹框</h1>

		<ElCollapse accordion>
			<ElCollapseItem title="最小使用案例">
				<MiniExample />
			</ElCollapseItem>

			<ElCollapseItem title="打开弹框并返回结果">
				<SimpleFormExample />
			</ElCollapseItem>

			<ElCollapseItem title="底部插槽">
				<FooterSlotExample />
			</ElCollapseItem>
		</ElCollapse>
	</section>
</template>

<style lang="scss" scoped>
.dialog-promise-root {
}
</style>
