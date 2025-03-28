<template>
	<div style="display: flex; align-items: center">
		<div style="justify-content: flex-end; margin-left: 5px">
			<!-- 选项抬头 -->
			{{ message.name }}:
		</div>
		<div class="demo-date-picker" style="flex: 1">
			<!-- 选择器or日历or输入框 -->
			<div class="block">
				<el-date-picker
					v-model="listData"
					type="daterange"
					range-separator="-"
					start-placeholder="开始日期"
					end-placeholder="结束日期"
					:size="size"
					style="width: 100%"
					:readonly="false"
					@change="updata()"
				/>
			</div>
		</div>
	</div>
</template>

<script lang="ts" setup>
// 发送父组件的数据
import { ref, watch } from "vue";
// loc data
const listData = ref<string>("");
const size = ref<"default" | "large" | "small">("small");
// 收到父组件的数据
interface PropsData {
	message: {
		name: string;
		options: string[];
	};
}
const props = defineProps<PropsData>();
// 动态绑定父组件的数据
const model = defineModel<string[]>();

const updata = () => {
	model.value = listData.value;
};
// 检测父组件数据修改
watch(model, (newData) => {
	const [one, two, ...three] = newData;
	listData.value[0] = one;
	listData.value[1] = two;
});
</script>

<style scoped>
.demo-date-picker {
	display: flex;
	width: 100%;
	padding: 0;
	flex-wrap: wrap;
}

.demo-date-picker .block {
	padding: 5px 0;
	text-align: center;
	border-right: solid 1px var(--el-border-color);
	flex: 1;
}

.demo-date-picker .block:last-child {
	border-right: none;
}

.demo-date-picker .demonstration {
	display: block;
	color: var(--el-text-color-secondary);
	font-size: 14px;
	margin-bottom: 20px;
}
</style>
