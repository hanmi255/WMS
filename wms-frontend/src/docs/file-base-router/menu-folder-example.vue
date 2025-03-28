<script lang="ts" setup>
definePage({
	meta: {
		// 菜单目录必须要填写为folder类型
		menuType: "folder",
		text: "侧边栏分组标题",
		icon: "IconSetting--侧边栏显示用的icon取值",
	},
});
</script>

<!-- 菜单目录组件 不需要其他任何dom元素 他们不被渲染 -->
