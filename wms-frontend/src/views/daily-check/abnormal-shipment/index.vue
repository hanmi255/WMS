<script lang="ts" setup>
import { ref, computed, watch } from "vue";

definePage({
	meta: {
		menuType: "page",
		text: "出货异常",
		icon: "IconSetting",
	},
});

const tests = [
	{
		use: 1,
		age: 2,
	},
	{
		use: "egwetgher",
		age: "gsrgser",
	},
	{
		use: 1,
		age: 2,
	},
];

// console.log(getRoutes());
console.log(` 进入了 出货异常 `);
</script>

<template>
	<section class="abnormal-shipment-root">
		<h2>温度维护</h2>
		<ComponentsTable
			:data="tests"
			:columns="[
				{ prop: 'use', label: '使用' },
				{ prop: 'age', label: '年龄' },
			]"
		/>
	</section>
</template>

<style lang="scss" scoped>
.abnormal-shipment-root {
}
</style>
