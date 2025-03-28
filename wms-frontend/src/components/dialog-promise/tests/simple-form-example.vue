<script lang="ts" setup>
import { ref, computed, watch, useTemplateRef } from "vue";
import { isEqual, isNil, cloneDeep } from "lodash-es";
import { ElMessageBox } from "element-plus";

import ComponentsDialogPromise from "components/dialog-promise/index.vue";
import { type DialogPromiseProps } from "components/dialog-promise/types";

interface TestBuzi {
	name: string;
	age: number;
}

/** 空的表单 */
const emptyForm = {
	name: "",
	age: 0,
};

/** 表单对象 */
const form = ref<TestBuzi>(cloneDeep(emptyForm));

/** 重设表单 */
function resetForm() {
	form.value = cloneDeep(emptyForm);
}

/** 表单是否填写过了？是否存在修改？ */
function hasChange() {
	return !isEqual(form.value, {
		name: "",
		age: 0,
	});
}

const dialogPromiseProps = ref<DialogPromiseProps<TestBuzi>>({
	dialogProps: {
		title: "新增用户信息",
	},

	async onDialogClose({ reject, resolve }) {
		if (hasChange()) {
			return await ElMessageBox.confirm("确定要关闭弹框么？你填写的内容尚未保存。", "关闭弹框", {
				confirmButtonText: "关闭",
				cancelButtonText: "取消",
				type: "warning",
			})
				.then(() => {
					// 关闭弹框前做手动做一次表单重设
					resetForm();
					// 本次弹框没有产生有意义的数据 故返回 undefined
					reject(void 0);
					// 返回 true 表示弹框关闭成功
					return true;
				})
				.catch(
					// 返回 false 表示弹框不关闭 用户取消了关闭弹框
					() => false,
				);
		} else {
			// 用户没有做任何修改 也可以无条件的做一次表单重设
			resetForm();
			// 可以将现在全部为空的数据 返回给父组件
			resolve(form.value);
			// 返回 true 表示弹框关闭成功
			return true;
		}
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
			<template #default>
				<ElForm :model="form" label-position="right" label-width="80px">
					<ElFormItem prop="name" label="名称">
						<ElInput v-model="form.name"></ElInput>
					</ElFormItem>

					<ElFormItem prop="age" label="年龄">
						<ElInput v-model="form.age"></ElInput>
					</ElFormItem>
				</ElForm>
			</template>
		</ComponentsDialogPromise>
	</section>
</template>
