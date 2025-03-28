<template>
	<el-dialog v-model="visible" :title="isEdit ? '编辑用户' : '新增用户'" @close="handleClose">
		<el-form :model="form" label-width="80px">
			<el-form-item label="用户账号">
				<el-input v-model="form.account" />
			</el-form-item>
			<el-form-item label="用户名称">
				<el-input v-model="form.name" />
			</el-form-item>
			<el-form-item label="组织机构">
				<el-input v-model="form.department" />
			</el-form-item>
			<el-form-item label="角色">
				<el-select v-model="form.role">
					<el-option label="管理员" value="管理员" />
					<el-option label="财务" value="财务" />
					<el-option label="仓管" value="仓管" />
				</el-select>
			</el-form-item>
			<el-form-item label="状态">
				<el-select v-model="form.status">
					<el-option label="激活" value="激活" />
					<el-option label="未激活" value="未激活" />
				</el-select>
			</el-form-item>
		</el-form>
		<template #footer>
			<el-button @click="handleClose">取消</el-button>
			<el-button type="primary" @click="handleSubmit">确定</el-button>
		</template>
	</el-dialog>
</template>

<script lang="ts" setup>
import { ref } from "vue";

interface User {
	account: string;
	name: string;
	department: string;
	role: string;
	status: string;
}

const visible = ref(false);
const isEdit = ref(false);
const form = ref<User>({
	account: "",
	name: "",
	department: "",
	role: "",
	status: "激活",
});

const emit = defineEmits(["submit"]);

function open(user?: User) {
	if (user) {
		form.value = { ...user };
		isEdit.value = true;
	} else {
		form.value = { account: "", name: "", department: "", role: "", status: "激活" };
		isEdit.value = false;
	}
	visible.value = true;
}

function handleClose() {
	visible.value = false;
}

function handleSubmit() {
	emit("submit", form.value);
	handleClose();
}

defineExpose({ open });
</script>
