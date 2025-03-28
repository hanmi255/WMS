<template>
	<div class="demo-container">
		<h2>分页组件演示</h2>

		<!-- 基础用法 -->
		<div class="demo-section">
			<h3>基础用法</h3>
			<Pagination :page-total="100" @page-func="handlePageChange" />
		</div>

		<!-- 自定义每页显示条数 -->
		<div class="demo-section">
			<h3>自定义每页显示条数</h3>
			<Pagination :page-total="200" :page-sizes="[10, 20, 30, 50]" :page-size="20" @page-func="handlePageChange" />
		</div>

		<!-- 自定义布局 -->
		<div class="demo-section">
			<h3>自定义布局</h3>
			<Pagination :page-total="300" layout="prev, pager, next" @page-func="handlePageChange" />
		</div>

		<!-- 完整功能 -->
		<div class="demo-section">
			<h3>完整功能展示</h3>
			<Pagination
				:page-total="500"
				:page-sizes="[10, 20, 50, 100]"
				:pager-count="7"
				:current-page="1"
				:page-size="20"
				layout="total, sizes, prev, pager, next, jumper"
				@page-func="handlePageChange"
			/>
		</div>

		<!-- 显示当前分页数据 -->
		<div class="demo-section">
			<div class="current-data">
				当前页码：{{ currentData.pageNum }}
				<br />
				每页条数：{{ currentData.pageSize }}
			</div>
		</div>
	</div>
</template>

<script setup>
import { ref } from "vue";
import Pagination from "@/components/Pagination/index.vue";

// 确保Element Plus的样式被导入
import "element-plus/dist/index.css";
definePage({
	meta: {
		menuType: "page",
		text: "分页组件",
		isSample: true,
		icon: "IconSetting",
	},
});

const currentData = ref({
	pageNum: 1,
	pageSize: 10,
});

const handlePageChange = (data) => {
	currentData.value = data;
	console.log("页码变化：", data);
};
</script>

<style scoped lang="less">
.demo-container {
	padding: 20px;
	max-width: 800px;
	margin: 0 auto;

	h2 {
		text-align: center;
		margin-bottom: 30px;
		color: #333;
	}

	.demo-section {
		margin-bottom: 30px;
		padding: 20px;
		border: 1px solid #eee;
		border-radius: 8px;

		h3 {
			margin-bottom: 15px;
			color: #666;
			font-size: 16px;
		}
	}

	.current-data {
		margin-top: 20px;
		padding: 15px;
		background: #f5f7fa;
		border-radius: 4px;
		color: #666;
		line-height: 1.8;
	}
}
</style>
