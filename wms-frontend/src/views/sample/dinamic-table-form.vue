<script lang="ts" setup>
definePage({
	meta: {
		menuType: "page",
		isSample: true,
		text: "动态表格样式表单",
		icon: "IconSetting",
	},
});

import MiniExample from "components/dinamic-table-form/tests/mini-example.vue";
</script>

<template>
	<section class="dinamic-table-form-root">
		<h1>动态表格样式表单</h1>

		<ElCollapse accordion>
			<ElCollapseItem title="最小使用案例">
				<MiniExample />
			</ElCollapseItem>
		</ElCollapse>
	</section>
</template>

<style lang="scss" scoped>
.dinamic-table-form-root {
}
</style>
