<script lang="ts" setup generic="T extends Object">
import { ref, computed, watch } from "vue";
import { createTemplatePromise, useToggle, type TemplatePromiseProps } from "@vueuse/core";

import { DialogPromiseProps } from "./types";
import { before } from "lodash-es";

const props = defineProps<DialogPromiseProps<T>>();

// type TemplatePromisePropsTuple = [T, [DemoDialogProps]];
// TemplatePromisePropsTuple[1]
const TemplatePromise = createTemplatePromise<T>();

// 维护弹框的显示与打开属性 是为了触发弹框的回调事件函数
const [isOpen, toggleOpen] = useToggle(false);

/** 对外暴露使用的弹框打开函数 开始执行异步行为 */
async function open() {
	// 打开弹框 触发弹框组件的事件
	toggleOpen(true);
	return await TemplatePromise.start();
}

defineExpose({
	open,
});
</script>

<template>
	<TemplatePromise v-slot="{ promise, resolve, reject, args }">
		<!-- @close="props.onDialogClose({ resolve, reject })" -->
		<!-- :before-close="() => props.onDialogClose({ resolve, reject })" -->
		<ElDialog
			class="dialog-promise-root"
			:model-value="isOpen"
			:draggable="true"
			:destroy-on-close="true"
			:before-close="async () => await props.onDialogClose({ resolve, reject })"
			:="props.dialogProps"
		>
			<template #header>
				<slot name="header"> </slot>
			</template>

			<template #default>
				<slot name="default"> 默认的弹框内容，请传递你的弹框内容。 </slot>
			</template>

			<template #footer>
				<slot name="footer" :resolve="resolve" :reject="reject">
					<ElButton type="danger" @click="props.onDialogClose({ resolve, reject })"> 关闭弹框 </ElButton>
				</slot>
			</template>
		</ElDialog>
	</TemplatePromise>
</template>

<style lang="scss" scoped>
.dialog-promise-root {
}
</style>
