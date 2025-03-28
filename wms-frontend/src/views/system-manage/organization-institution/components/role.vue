<template>
	<div class="header">
		<p>11:机构</p>
	</div>
	<div class="title">
		<p>角色列表</p>
	</div>
	<div class="content">
		<el-button @click="allChecked">全选</el-button>
		<el-button @click="resetAll">重置</el-button>
		<el-button @click="save">保存</el-button>
		<ul>
			<li v-for="(item, index) in checkboxList" :key="index">
				<svg
					t="1741526080029"
					class="icon"
					viewBox="0 0 1024 1024"
					version="1.1"
					xmlns="http://www.w3.org/2000/svg"
					p-id="1897"
					width="16"
					height="16"
				>
					<path
						d="M642 673.1H301.6c-9.9 0-17.9-8-17.9-17.9s8-17.9 17.9-17.9H642c9.9 0 17.9 8 17.9 17.9s-8 17.9-17.9 17.9zM642 511.8H301.6c-9.9 0-17.9-8-17.9-17.9 0-9.9 8-17.9 17.9-17.9H642c9.9 0 17.9 8 17.9 17.9 0 9.9-8 17.9-17.9 17.9zM480.7 350.6H301.6c-9.9 0-17.9-8-17.9-17.9s8-17.9 17.9-17.9h179.2c9.9 0 17.9 8 17.9 17.9s-8.1 17.9-18 17.9zM874.9 350.6H695.7c-49.4 0-89.6-40.2-89.6-89.6V81.9c0-9.9 8-17.9 17.9-17.9 9.9 0 17.9 8 17.9 17.9V261c0 29.6 24.1 53.7 53.7 53.7h179.2c9.9 0 17.9 8 17.9 17.9s-7.9 18-17.8 18z"
						fill="#f3e80f"
						p-id="1898"
					></path>
					<path
						d="M794.3 959.7H221c-49.4 0-89.6-40.2-89.6-89.6V153.5c0-49.4 40.2-89.6 89.6-89.6h403.1c4.8 0 9.3 1.9 12.7 5.2L887.6 320c3.4 3.4 5.2 7.9 5.2 12.7v537.5c0 52.7-51.9 89.5-98.5 89.5zM221 99.8c-29.6 0-53.7 24.1-53.7 53.7v716.6c0 29.6 24.1 53.7 53.7 53.7h573.3c29 0 62.7-23.5 62.7-53.7v-530L616.7 99.8H221z"
						fill="#f3e80f"
						p-id="1899"
					></path>
				</svg>
				<el-checkbox v-model="checkboxList[index]" />
				<span class="role">测试 {{ index + 1 }}</span>
			</li>
		</ul>
	</div>
</template>

<script setup>
import { ref, onMounted } from "vue";

// 用户列表
const roleList = ref([]);

onMounted(() => {});

// 获取用户列表
const getRoleList = () => {
	// TODO 获取组织角色
};
// 定义复选框状态数组
const checkboxList = ref(new Array(10).fill(false));

// 全选功能
const allChecked = () => {
	checkboxList.value = checkboxList.value.map(() => true);
};

// 重置功能
const resetAll = () => {
	checkboxList.value = checkboxList.value.map(() => false);
};

// 保存功能
const save = () => {
	// TODO 更新组织角色
	console.log(checkboxList.value);
};
</script>

<style lang="scss" scoped>
* {
	margin: 0;
	padding: 0;
	list-style: none;
}

p {
	width: 100%;
	margin-bottom: 10px;
	border-bottom: 1px solid #efefef;
}

::v-deep(.el-button span) {
	padding: 2px;
}

.content {
	margin-top: 20px;
	ul {
		margin-top: 10px;
	}
	li {
		margin-bottom: 5px;
		.role {
			margin-left: 4px;
		}
	}
}

svg {
	margin-right: 4px;
}
</style>
