<script lang="ts" setup>
definePage({
	meta: {
		// 页面必须要填写为page类型
		menuType: "page",
		text: "某某业务标题",
		icon: "IconSetting--侧边栏显示用的icon取值",
	},
});
</script>

<template>
	<section class="menu-page.example-root">
		<!-- 这是实现具体业务的地方 请编写你的组件 -->
	</section>
</template>

<style lang="scss" scoped>
.menu-page.example-root {
	// 这是实现具体业务的地方 请编写你的组件样式
}
</style>
