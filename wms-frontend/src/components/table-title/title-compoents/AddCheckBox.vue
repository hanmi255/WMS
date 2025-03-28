<template>
	<div style="display: flex; align-items: center">
		<div style="justify-content: flex-end; margin-left: 5px">
			<!-- 选项抬头 -->
			{{ message.name }}:
		</div>
		<div class="flex flex-wrap gap-4 items-center" style="flex: 1">
			<!-- 选择器or日历or输入框 -->
			<el-select v-model="listData" placeholder="选择" :size="size" style="margin: 5px 0" @change="updata()">
				<el-option v-for="item in message.optionData" :key="item" :label="item" :value="item" />
			</el-select>
		</div>
	</div>
</template>
<script lang="ts" setup>
import { ref, watch } from "vue";
// 收到父组件的数据
interface PropsData {
	message: {
		name: string;
		options: string[];
	};
}
const props = defineProps<PropsData>();
// 动态绑定父组件的数据
const model = defineModel<string>();
const updata = () => {
	model.value = listData;
};
const listData = ref<string>("");
const size = ref<"default" | "large" | "small">("small");
// 检测父组件数据修改
watch(model, (newData) => {
	listData.value = newData;
});
</script>
