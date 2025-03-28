<script lang="ts" setup>
import { ref, computed, watch, useTemplateRef } from "vue";
import { isNil } from "lodash-es";

import ComponentsDialogPromise from "components/dialog-promise/index.vue";
import { type DialogPromiseProps } from "components/dialog-promise/types";

interface TestBuzi {
	name: string;
	age: number;
}

const testBuzi = ref<TestBuzi>({
	name: "张三",
	age: 18,
});

const dialogPromiseProps = ref<DialogPromiseProps<TestBuzi>>({
	dialogProps: {
		title: "默认弹框标题",
		width: "75vw",
	},
	async onDialogClose({ reject, resolve }) {
		resolve(testBuzi.value);
		return true;
	},
});

const dialogRef = useTemplateRef("dialog");

function openDialog() {
	if (!isNil(dialogRef.value)) {
		dialogRef.value.open().then((result) => {
			console.log("result", result);
		});
	}
}
</script>

<template>
	<section>
		<ElButton type="success" @click="openDialog">打开弹框</ElButton>

		<ComponentsDialogPromise :="dialogPromiseProps" ref="dialog">
			<template #footer="{ reject, resolve }">
				<ElButton type="info" @click="dialogPromiseProps.onDialogClose({ reject, resolve })"> 关闭弹框 </ElButton>
			</template>
		</ComponentsDialogPromise>
	</section>
</template>
