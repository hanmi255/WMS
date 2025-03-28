<script lang="ts" setup>
definePage({
	meta: {
		menuType: "page",
		isSample: true,
		text: "表格组件",
		icon: "IconSetting",
	},
});

// @ts-ignore
import AutoImportMiniExample from "components/table/tests/auto-import-mini-example.vue";
// @ts-ignore
import IsIndexExample from "components/table/tests/isIndex-example.vue";
// @ts-ignore
import IsMultipleSelectExample from "components/table/tests/isMultipleSelect-example.vue";
// @ts-ignore
import SlotExample from "components/table/tests/slot-example.vue";
</script>

<template>
	<section class="table-root">
		<h1>表格组件演示界面</h1>

		<ElCollapse accordion>
			<ElCollapseItem title="最小案例">
				<AutoImportMiniExample />
			</ElCollapseItem>

			<ElCollapseItem title="开启索引栏">
				<IsIndexExample />
			</ElCollapseItem>

			<ElCollapseItem title="开启多选栏">
				<IsMultipleSelectExample />
			</ElCollapseItem>

			<ElCollapseItem title="插槽">
				<SlotExample />
			</ElCollapseItem>
		</ElCollapse>
	</section>
</template>
