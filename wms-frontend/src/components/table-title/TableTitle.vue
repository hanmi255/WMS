<template>
	<div>
		<div v-if="transferTitleData.unfold">
			<el-switch
				v-model="showTitle"
				class="ml-2"
				inline-prompt
				style="--el-switch-on-color: #13ce66; --el-switch-off-color: #ff4949; margin-left: 5px"
				active-text="展示内容"
				inactive-text="隐藏内容"
			/>
		</div>
		<transition name="titleAnimate">
			<div v-if="showTitle" class="animated-div">
				<el-row>
					<!-- 这里是选择操作栏 -->
					<el-col v-for="data in transferTitleData.contentList" :key="data.name" :span="8" style="min-width: 220px">
						<div @click="selectClick(data)">
							<component :is="componentMaps[data.type]" v-model="data.content" :message="data"></component>
						</div>
					</el-col>
				</el-row>
			</div>
		</transition>
		<div style="display: flex">
			<div style="width: 100%">
				<!-- 这里是下方的表单操作栏 -->
				<div style="display: flex; justify-content: space-between; width: 100%">
					<!-- 左侧多个按钮 -->
					<div style="display: flex">
						<div v-for="data in transferTitleData.bottomList" :key="data.name">
							<div @click="userClick(data)" style="margin-right: 5px">
								<el-button type="info" size="small">
									<component :is="iconMaps[data.iconType]"></component>
									<p>{{ data.name }}</p>
								</el-button>
							</div>
						</div>
					</div>
					<!-- 右侧两个按钮 -->
					<div v-if="transferTitleData.rightButton">
						<div style="display: flex">
							<div @click="userClick({ name: '右侧查询', rightButton: true })">
								<el-button type="info" size="small">
									<svg xmlns="http://www.w3.org/2000/svg" width="14" height="14" viewBox="0 0 24 24">
										<g class="search-outline">
											<g fill="currentColor" fill-rule="evenodd" class="Vector" clip-rule="evenodd">
												<path d="M11 17a6 6 0 1 0 0-12a6 6 0 0 0 0 12m0 2a8 8 0 1 0 0-16a8 8 0 0 0 0 16" />
												<path
													d="M15.32 15.29a1 1 0 0 1 1.414.005l3.975 4a1 1 0 0 1-1.418 1.41l-3.975-4a1 1 0 0 1 .004-1.414Z"
												/>
											</g>
										</g>
									</svg>
									<p>查询</p>
								</el-button>
							</div>
							<div @click="userClick({ name: '右侧重置', rightButton: true })">
								<el-button type="info" size="small" style="margin-left: 5px">
									<svg xmlns="http://www.w3.org/2000/svg" width="14" height="14" viewBox="0 0 24 24">
										<path
											fill="currentColor"
											fill-rule="evenodd"
											d="M2.281 8a1 1 0 0 1 1-1H15.76c2.814 0 6 2.366 6 6s-3.186 6-6 6H7.982a1 1 0 1 1 0-2h7.778c1.88 0 4-1.634 4-4s-2.12-4-4-4H3.28a1 1 0 0 1-1-1Z"
											clip-rule="evenodd"
										/>
										<path
											fill="currentColor"
											fill-rule="evenodd"
											d="M6.707 4.293a1 1 0 0 1 0 1.414L4.362 8.052l2.397 2.797a1 1 0 0 1-1.518 1.302l-3-3.5a1 1 0 0 1 .052-1.358l3-3a1 1 0 0 1 1.414 0"
											clip-rule="evenodd"
										/>
									</svg>
									<p>重置</p>
								</el-button>
							</div>
						</div>
					</div>
				</div>
			</div>
		</div>
	</div>
</template>
<script setup lang="ts">
import { ref } from "vue";

// 导入组件maps
// // 导入title组件
const addTitleComponent = import.meta.glob("@/components/table-title/title-compoents/*.vue");
const componentMaps = Object.entries(addTitleComponent).reduce(
	(acc, [path, component]) => {
		// 从路径中提取文件名
		const componentName = path.match(/\/([^/]+)\.vue$/)?.[1] || "";
		acc[componentName] = defineAsyncComponent(component);
		return acc;
	},
	{} as Record<string, Component>,
);
// // 导入icon组件
const addIconComponent = import.meta.glob("@/components/table-title/table-icon/*.vue");
const iconMaps = Object.entries(addIconComponent).reduce(
	(acc, [path, component]) => {
		// 从路径中提取文件名
		const componentName = path.match(/\/([^/]+)\.vue$/)?.[1] || "";
		acc[componentName] = defineAsyncComponent(component);
		return acc;
	},
	{} as Record<string, Component>,
);
console.log("VUE : iconMaps :", iconMaps);

// loc data
const showTitle = ref(true);
const triggerNumber = ref(0);
// 动态绑定父组件的数据
const transferTitleData = defineModel();
// 发送父组件的数据
const emit = defineEmits(["user-click", "select-click"]); // 添加新的emit事件

/**
 * @function userClick
 * 触发用户点击事件
 * @param {string} name - 被点击的组件的name
 * @emits user-click
 */
const userClick = (data: object) => {
	console.log("VUE : FUNC : userClick : data:", data);
	emit("user-click", data);
};

/**
 * @function selectClick
 * 触发选择操作栏的点击事件
 * @param {object} data - 被点击的组件的数据
 * @emits select-click
 */
const selectClick = (data: object) => {
	console.log("VUE : FUNC : selectClick : data:", data);
	emit("select-click", data);
};
</script>
<style scoped>
.animated-div {
	/* background-color: gainsboro; */
	padding: 10px;
	margin-top: 5px;
	opacity: 1;
	transform: translateY(0px);
	transition:
		transform 0.3s ease-out,
		opacity 0.3s ease-out;
}

.titleAnimate-enter-active,
.titleAnimate-leave-active {
	transition:
		transform 0.3s ease-out,
		opacity 0.3s ease-out;
}

.titleAnimate-enter-from,
.titleAnimate-leave-to {
	opacity: 0;
	transform: translateY(-10px);
}

.titleAnimate-enter-to,
.titleAnimate-leave-from {
	opacity: 1;
	transform: translateY(0);
}
</style>
