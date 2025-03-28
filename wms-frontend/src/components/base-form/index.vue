<script setup lang="ts" generic="T extends Record<string, any>">
import { defineEmits, defineProps, useTemplateRef, nextTick } from "vue";
import type { Ref, ComputedRef } from "vue";
import type { FormItemRule, FormRules, FormProps } from "element-plus";
import { isNil, cloneDeep } from "lodash-es";

import ComponentsDinamicTableForm from "components/dinamic-table-form/index.vue";
import type { BaseFormItem, _OmitFormProps } from "./types";

/** 基础通用表单 props */
export interface BaseFormProps<T extends Record<string, any>>
/* @vue-ignore */
	extends _OmitFormProps {
	/**
	 * 表单对象
	 * @description
	 * 本组件主要服务的对象 该对象会被修改
	 */
	form: T;

	/**
	 * 表单字段配置
	 * @description
	 * 用于实现表单渲染的配置项 是本组件的核心配置项
	 * @version 2 类似于之前的 series 字段
	 */
	formItems: BaseFormItem<T>[];

	/**
	 * 业务意义上纯净的，被重置的表单原始值
	 * @description
	 * 重置表单时 如果提供了此表单对象 将会按照该对象来完成表单重置
	 *
	 * 比如搜索栏重置表单 ， 业务表单重置表单等等情况。
	 */
	beResetForm?: T;

	/**
	 * 校验规则
	 * @description
	 * 对于
	 */
	rules?: FormRules<T>;
}

const props = defineProps<BaseFormProps<T>>();

/** @deprecated TODO: 暂不需要实现事件数据传递 */
const emits = defineEmits(["form-finish"]);

/** 被遍历的表单配置项 */
const formItems = computed(() => props.formItems);

/** 组件校验规则 */
const rules = computed(() => props.rules);

/**
 * 是否传递了 beResetForm 变量？
 * @description
 * 用来针对性的开启某些功能
 */
const hasBeResetForm = computed(() => !isNil(props.beResetForm));

/** 表单组件示例 */
const formRef = useTemplateRef("formRef");

/** 表单对象 在本组件内预期被高频率修改 */
const form = ref<T>(props.form) as Ref<T>;

/**
 * 获取表单数据
 * @description
 * 让外部组件 直接获取本组件的表单数据
 *
 * TODO: 未来实现组件数据监听 对外暴露数据变更事件
 * @public 外部组件能够有效使用本函数
 */
function getForm() {
	return form.value;
}

/**
 * 得到数据表更之后的组件实例
 * @private 本组件内部使用 不考虑对外暴露出去
 */
async function getFormRef() {
	// 无条件地先等待数据变化 变化完毕后再从组件内使用函数做
	await nextTick();
	return formRef.value;
}

/**
 * 表单是否校验完毕？
 * @description
 * TODO: 未来对接 表格表单的内部校验配置
 *
 * 时间不够 先不做表格表单的场景考虑
 */
async function isValidatePass() {
	const formRef = await getFormRef();
	if (isNil(formRef)) {
		console.error("表单引用未找到");
		// 认定表单校验失败了。
		return false;
	}

	/**
	 * 整个表单的校验结果
	 * @default true 默认校验是通过的
	 */
	let validateRes = true;

	await formRef.validate((valid, fields) => {
		// 只要出现任何一个字段校验失败 就认定为整个表单都校验失败了
		if (!valid) {
			// TODO: 未来实现表单校验失败的提示 将错误的 fields 显示出来
			// TODO: 实现错误字段的滚动定位 或者是错误项的高亮
			validateRes = false;
		}
	});

	return validateRes;
}

/**
 * 提交
 * @description
 * 认定是表单提交 只负责返回本组件的form数据
 *
 * 1. 先做表单校验
 * 2. 然后再对外返回经过校验的数据
 *
 * 不会做有意义的接口请求 本组件不负责和业务直接关联的异步请求
 * @public 外部组件能够有效使用本函数
 */
async function submit() {
	const formRef = await getFormRef();
	if (!isNil(formRef)) {
		const validateRes = await isValidatePass();
		if (validateRes) {
			return getForm();
		}
	}
}

/**
 * 重置表单
 * @description
 * 用的是组件库内部的重置能力 重置不等于清空表单
 * @public 外部组件能够有效使用本函数
 */
async function resetForm() {
	/**
	 * 如果外部提供了专用于重置表单的值 那么重置表单就用外部传递的值实现
	 * 这里的写法实际上是冗余的 仅仅是为了通过typescript类型约束移除掉不存在的值罢了
	 */
	if (hasBeResetForm.value && props.beResetForm) {
		form.value = cloneDeep(props.beResetForm);
		return;
	}

	const formRef = await getFormRef();
	if (!isNil(formRef)) {
		formRef.resetFields();
		return;
	}
}

defineExpose({
	getForm,
	submit,
	resetForm,
});
</script>

<template>
	<ElForm
		class="dynamic-form"
		:="{ ...$attrs, ...props }"
		:model="form"
		:rules="rules"
		label-suffix=":"
		ref="formRef"
		@submit.prevent
	>
		<ElRow :gutter="20">
			<template v-for="(formItem, index) in formItems" :key="index">
				<!-- 
					表格类型特殊处理
					其表单项的布局是固定写死为top的，否则展示效果很差
				-->
				<template v-if="formItem.type === 'table'">
					<ElCol :span="24">
						<ElFormItem :label="formItem.props.label" label-position="top">
							<!-- <div class="table-title">{{ label }}</div> -->
							<ComponentsDinamicTableForm :="formItem.props" />
						</ElFormItem>
					</ElCol>
				</template>

				<!-- 常规表单项 -->
				<ElCol
					v-else
					:span="formItem.props.responsive?.xs || 24"
					:sm="formItem.props.responsive?.sm"
					:md="formItem.props.responsive?.md || 12"
					:lg="formItem.props.responsive?.lg || 8"
					:xl="formItem.props.responsive?.xl"
				>
					<ElFormItem :label="formItem.props.label" :prop="formItem.props.prop">
						<!-- 输入框 -->
						<ElInput
							v-if="formItem.type === 'input'"
							v-model="form[formItem.props.prop]"
							:placeholder="formItem.props.placeholder"
							:maxlength="formItem.props.maxlength"
						/>

						<!-- 选择器 -->
						<ElSelect v-else-if="formItem.type === 'select'" v-model="form[formItem.props.prop]">
							<ElOption
								v-for="(option, i) in formItem.props.options"
								:key="i"
								:label="option.label"
								:value="option.value"
							/>
						</ElSelect>

						<!-- 日期选择 -->
						<ElDatePicker
							v-else-if="formItem.type === 'date'"
							v-model="form[formItem.props.prop]"
							:type="formItem.props.type"
							:placeholder="formItem.props.placeholder"
							:format="formItem.props.format"
							:value-format="formItem.props.valueFormat"
						/>

						<!-- 数字输入 -->
						<ElInputNumber
							v-else-if="formItem.type === 'number'"
							v-model="form[formItem.props.prop]"
							:min="formItem.props.min"
							:max="formItem.props.max"
							:step="formItem.props.step"
							:precision="formItem.props.precision"
							controls-position="right"
						/>
					</ElFormItem>
				</ElCol>
			</template>
		</ElRow>
		<!-- 
			TODO: 纯粹的表单组件 不内置封装这些按钮 这些按钮在其他场景内完成
			在别的派生组件内封装该功能
		-->
		<!-- <ElButton @click="handleFinish">提交</ElButton>
		<ElButton @click="clearForm">重置</ElButton> -->
	</ElForm>
</template>

<style lang="scss">
.dynamic-form {
	.ElFormItem {
		margin-bottom: 18px;

		&__label {
			font-weight: 500;
			padding-bottom: 4px !important;
			color: #606266;
		}
	}

	.el-input,
	.ElSelect,
	.el-date-editor,
	.ElInputNumber {
		width: 100% !important;
	}

	.ElInputNumber {
		.el-input__wrapper {
			padding-left: 10px;
			padding-right: 10px;
		}
	}

	@media (max-width: 768px) {
		.ElFormItem {
			margin-bottom: 12px;
		}
	}
}
</style>
