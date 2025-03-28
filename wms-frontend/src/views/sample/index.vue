<script setup>
import { reactive } from "vue";

// 该组件在生产环境下将会固定移除
definePage({
	meta: {
		menuType: "page",
		isSample: true,
		text: "自测组件-演示页面",
		icon: "IconSetting",
	},
});
</script>

<template>
	<div>
		<el-header>
			<div class="header-nav">示例效果演示页</div>
		</el-header>
		<el-container>
			<!-- 警告 我们不再使用这个侧边栏了 这里保留代码仅仅是为了参考 -->
			<el-aside v-if="false">
				<div class="menu-wrap">
					<el-scrollbar max-height="95vh">
						<el-menu
							default-active="/sample/file"
							active-text-color="#409EFF"
							text-color="#fff"
							background-color="#545c64"
							unique-opened
							router
						>
							<el-menu-item v-for="(menu, index) in menus" :key="index" :index="menu.path">
								<el-icon>
									<icon-menu />
								</el-icon>
								<span>{{ menu.text }}</span>
							</el-menu-item>
						</el-menu>
					</el-scrollbar>
				</div>
			</el-aside>

			<el-main>
				<router-view />
			</el-main>
		</el-container>
	</div>
</template>

<style scoped>
.el-header {
	background-color: #5d6672;
	height: 5vh;
	display: flex;
	justify-content: space-between;
	padding: 0;
}

.header-nav {
	line-height: 5vh;
	width: 100%;
	color: #f8f8f8;
	text-align: center;
}

.el-aside {
	background-color: #545c64;
	height: 95vh;
	width: 221px;
}

.menu-wrap {
	width: 220px;
}

.el-menu {
	border: 0;
}

.el-main {
	padding: 20px;
	background-color: #edecec;
}
</style>
