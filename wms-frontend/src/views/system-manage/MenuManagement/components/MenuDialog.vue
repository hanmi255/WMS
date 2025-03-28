<template>
	<el-dialog v-model="visible" :title="isEdit ? '编辑菜单' : '新增菜单'" width="30%">
		<el-form :model="form" label-width="100px">
			<el-form-item label="菜单名称">
				<el-input v-model="form.name" />
			</el-form-item>
			<el-form-item label="图标">
				<el-input v-model="form.icon" />
			</el-form-item>
			<el-form-item label="菜单类型">
				<el-input v-model="form.type" />
			</el-form-item>
			<el-form-item label="菜单地址">
				<el-input v-model="form.address" />
			</el-form-item>
			<el-form-item label="菜单服务">
				<el-input v-model="form.service" />
			</el-form-item>
			<el-form-item label="图标样式">
				<el-input v-model="form.iconStyle" />
			</el-form-item>
		</el-form>
		<template #footer>
			<el-button @click="visible = false">取消</el-button>
			<el-button type="primary" @click="submit">确定</el-button>
		</template>
	</el-dialog>
</template>

<script lang="ts" setup>
import { ref } from "vue";

const visible = ref(false);
const isEdit = ref(false);
const form = ref({
	name: "",
	icon: "",
	type: "",
	address: "",
	service: "",
	iconStyle: "",
});

const emit = defineEmits(["submit"]);

function open(menu?: any) {
	if (menu) {
		form.value = { ...menu };
		isEdit.value = true;
	} else {
		form.value = {
			name: "",
			icon: "",
			type: "",
			address: "",
			service: "",
			iconStyle: "",
		};
		isEdit.value = false;
	}
	visible.value = true;
}

function submit() {
	emit("submit", form.value);
	visible.value = false;
}

defineExpose({ open });
</script>
