<script lang="ts" setup>
import { ref, useTemplateRef } from "vue";
import { isNil } from "lodash-es";

import ComponentsBaseForm, { type BaseFormProps } from "components/base-form/index.vue";

interface TestBuzi {
	age: number;
}

const form = ref<TestBuzi>({
	age: 1321,
});
const beResetForm = ref<TestBuzi>({
	age: 0,
});

const props = ref<BaseFormProps<TestBuzi>>({
	form: form.value,
	beResetForm: beResetForm.value,
	formItems: [
		{
			type: "input",
			props: {
				label: "年龄",
				prop: "age",
				placeholder: "请输入年龄",
				responsive: { md: 12, lg: 8 },
			},
		},
	],
});

const baseFormRef = useTemplateRef("baseFormRef");

function resetForm() {
	baseFormRef.value?.resetForm();
}

async function search() {
	const res = await baseFormRef.value?.submit();
	if (!isNil(res)) {
		form.value = res;
	}
}
</script>

<template>
	<section>
		<ComponentsBaseForm :="props" ref="baseFormRef" />

		<ElRow>
			<ElButton type="warning" @click="resetForm">重置</ElButton>
			<ElButton type="success" @click="search">搜索</ElButton>
		</ElRow>

		<ElRow>
			{{ form }}
		</ElRow>
	</section>
</template>
