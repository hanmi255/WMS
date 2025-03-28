<template>
	<div style="display: flex; align-items: center">
		<div style="justify-content: flex-end; margin-left: 5px">
			<!-- 选项抬头 -->
			{{ message.name }}:
		</div>
		<div style="display: flex; flex: 1; margin: 5px 0">
			<el-input v-model="listDataOne" placeholder="请输入" :size="size" @input="updata()" />
			<div>-</div>
			<el-input v-model="listDataTwo" placeholder="请输入" :size="size" @input="updata()" />
		</div>
	</div>
</template>
<script lang="ts" setup>
import { ref, watch } from "vue";
// 收到父组件的数据
// loc data
const size = ref<"default" | "large" | "small">("small");
const listDataOne = ref<string>("");
const listDataTwo = ref<string>("");
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
	const data = [];
	data.push(listDataOne.value);
	data.push(listDataTwo.value);
	model.value = data;
};

// 检测父组件数据修改
watch(model, (newData) => {
	const [one, two, ...three] = newData;
	listDataOne.value = one;
	listDataTwo.value = two;
});
</script>
