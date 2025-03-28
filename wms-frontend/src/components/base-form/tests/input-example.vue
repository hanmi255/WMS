<script lang="ts" setup>
import { ref } from "vue";

import ComponentsBaseForm, { type BaseFormProps } from "components/base-form/index.vue";

interface TestBuzi {
	age: number;
}

const form = ref<TestBuzi>({
	age: 1321,
});

const props = ref<BaseFormProps<TestBuzi>>({
	form: form.value,
	formItems: [
		{
			type: "input",
			props: {
				label: "年龄",
				prop: "age",
				placeholder: "请输入年龄",
				maxlength: 10,
				responsive: { md: 12, lg: 8 },
			},
		},
	],
});
</script>

<template>
	<section>
		<ComponentsBaseForm :="props" />
	</section>
</template>
