<script lang="ts" setup>
import { ref, computed, watch } from "vue";
</script>

<template>
	<!-- 登录页面的布局框 -->
	<section class="login-root">
		<router-view />
	</section>
</template>

<style lang="scss" scoped>
.login-root {
	// width: 100vw;
	// height: 100%;
}
</style>
