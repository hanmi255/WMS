<template>
	<!-- 为 ECharts 准备一个 DOM 用于渲染图表 -->
	<div id="main"></div>
</template>

<script setup>
definePage({
	meta: {
		menuType: "page",
		isSample: true,
		text: "图表演示",
		icon: "IconSetting",
	},
});

import { onMounted } from "vue";
// 引入 echarts 核心模块，核心模块提供了 echarts 使用必须要的接口。
import * as echarts from "echarts/core";
// 引入柱状图图表，图表后缀都为 Chart
import { BarChart } from "echarts/charts";
// 引入标题，提示框，直角坐标系，数据集，内置数据转换器组件，组件后缀都为 Component
import {
	TitleComponent,
	TooltipComponent,
	GridComponent,
	DatasetComponent,
	TransformComponent,
} from "echarts/components";
// 标签自动布局、全局过渡动画等特性
import { LabelLayout, UniversalTransition } from "echarts/features";
// 引入 Canvas 渲染器，注意引入 CanvasRenderer 或者 SVGRenderer 是必须的一步
import { CanvasRenderer } from "echarts/renderers";
// 注册必须的组件
echarts.use([
	TitleComponent,
	TooltipComponent,
	GridComponent,
	DatasetComponent,
	TransformComponent,
	BarChart,
	LabelLayout,
	UniversalTransition,
	CanvasRenderer,
]);

// 在 mounted 中初始化图表
onMounted(() => {
	// 初始化图表
	const myChart = echarts.init(document.getElementById("main"), "dark");
	// 设置大小
	myChart.resize({ width: 600, height: 400 });
	// 设置配置项
	myChart.setOption({
		title: {
			text: "ECharts 入门示例",
		},
		tooltip: {},
		xAxis: {
			data: ["衬衫", "羊毛衫", "雪纺衫", "裤子", "高跟鞋", "袜子"],
		},
		yAxis: {},
		series: [
			{
				name: "1月销量",
				type: "bar",
				data: [5, 20, 36, 10, 10, 20],
			},
			{
				name: "2月销量",
				type: "bar",
				data: [15, 15, 30, 16, 19, 11],
			},
		],
	});
});
</script>
