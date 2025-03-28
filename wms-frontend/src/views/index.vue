<!-- 本组件就是原来的 dashboard 控制台面板组件 -->
<script setup>
import { ref, onMounted, onUnmounted } from "vue";

definePage({
	// 首页的默认路由名称为home
	name: "home",
	// 认定此处的路由地址为写死home
	path: "/home",
	meta: {
		menuType: "page",
		text: "首页",
		icon: "no-use-any-icon",
	},
});

// 引入 echarts 核心模块，核心模块提供了 echarts 使用必须要的接口。
import * as echarts from "echarts/core";
// 引入标题，提示框，直角坐标系，数据集，内置数据转换器组件，组件后缀都为 Component
import {
	TitleComponent,
	TooltipComponent,
	GridComponent,
	DatasetComponent,
	TransformComponent,
	LegendComponent,
	ToolboxComponent,
} from "echarts/components";

// 标签自动布局、全局过渡动画等特性
import { LabelLayout, UniversalTransition } from "echarts/features";
// 引入 Canvas 渲染器，注意引入 CanvasRenderer 或者 SVGRenderer 是必须的一步
import { CanvasRenderer } from "echarts/renderers";
import { BarChart, LineChart, PieChart } from "echarts/charts";
import {
	getWaitReceiveGoodsCountAPI,
	getWaitShelfGoodsCountAPI,
	getWaitPickGoodsCountAPI,
	getPickingGoodsCountAPI,
	getTopShelfGoodsCountAPI1,
	getShelfGoodsCountAPI2,
	getTopDownGoodsCountAPI3,
	getGoodsToUpInRecentDaysAPI4,
} from "@/apis/dashboard";
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
	LegendComponent,
	PieChart,
	LineChart,
	ToolboxComponent,
]);

const time = ref(new Date().toLocaleString());
// 待收货
const waitReceiveGoodsCount = ref(null);
// 待上架
const waitShelfGoodsCount = ref(null);
// 待拣货
const waitPickGoodsCount = ref(null);
// 拣货中
const pickingGoodsCount = ref(null);

// 待收货
const getWaitReceiveGoodsCount = async () => {
	const res = await getWaitReceiveGoodsCountAPI();
	if (res.code === 10000) {
		waitReceiveGoodsCount.value = res.data.goodsNumber;
		console.log("待收获", waitReceiveGoodsCount.value);
	}
};

// 待上架
const getWaitShelfGoodsCount = async () => {
	const res = await getWaitShelfGoodsCountAPI();
	if (res.code === 10000) {
		waitShelfGoodsCount.value = res.data.goodsNumber;
		console.log("待上架", waitShelfGoodsCount.value);
	}
};

// 待拣货
const getWaitPickGoodsCount = async () => {
	const res = await getWaitPickGoodsCountAPI();
	if (res.code === 10000) {
		waitPickGoodsCount.value = +res.data.goodsNumber;
		console.log("待拣货", waitPickGoodsCount.value);
	}
};

// 拣货中
const getPickingGoodsCount = async () => {
	const res = await getPickingGoodsCountAPI();
	if (res.code === 10000) {
		pickingGoodsCount.value = +res.data.goodsNumber;
		console.log("拣货中", pickingGoodsCount.value);
	}
};
const data1 = ref([]);
const data11 = ref([]);
const data2 = ref([]);
const data22 = ref([]);
const data3 = ref([]);
const data33 = ref([]);
const data4 = ref([]);
const data44 = ref([]);

// 上架商品数量Top6
const getTopShelfGoodsCount1 = async () => {
	const res = await getTopShelfGoodsCountAPI1();
	if (res.code === 10000) {
		data1.value = res.data.map((item) => item.goodsName);
		data11.value = res.data.map((item) => ({
			value: Number(item.totalGoodsQua), // 确保 value 是数字类型
			name: item.goodsName,
		}));
	}
};

// 七天内下架商品数量
const getShelfGoodsCount2 = async () => {
	const res = await getShelfGoodsCountAPI2();
	if (res.code === 10000) {
		data2.value = res.data.map((item) => item.createDateDay);
		data22.value = res.data.map((item) => item.totalGoodsUpQua);
	}
};

// 下架商品数量Top6
const getTopDownGoods3 = async () => {
	const res = await getTopDownGoodsCountAPI3();
	if (res.code === 10000) {
		data3.value = res.data.map((item) => item.goodsName);
		data33.value = res.data.map((item) => Number(item.totalGoodsQua));
	}
};
// 七天内上架商品数量
const getGoodsToUpInRecentDays4 = async () => {
	const res = await getGoodsToUpInRecentDaysAPI4();
	if (res.code === 10000) {
		data4.value = res.data.map((item) => item.createDateDay);
		data44.value = res.data.map((item) => item.totalGoodsUpQua);
	}
};

let timer;
// 时间格式化
function formatDate() {
	const now = new Date(); // 获取当前时间

	const year = now.getFullYear(); // 获取年份
	const month = now.getMonth() + 1; // 获取月份（注意：月份从0开始，需加1）
	const day = now.getDate(); // 获取日期
	const hours = now.getHours(); // 获取小时
	const minutes = now.getMinutes(); // 获取分钟
	const seconds = now.getSeconds(); // 获取秒钟

	// 格式化为"xx年xx月xx日 xx点xx分xx秒"
	const formattedDate = `${year}年${month}月${day}日 ${hours}点${minutes}分${seconds}秒`;

	return formattedDate;
}
let myChart1;
let myChart2;
let myChart3;
let myChart4;
onMounted(async () => {
	timer = setInterval(() => {
		time.value = formatDate();
	}, 1000);
	getWaitReceiveGoodsCount();
	getWaitShelfGoodsCount();
	getWaitPickGoodsCount();
	getPickingGoodsCount();
	// 初始化图表容器
	myChart1 = echarts.init(document.getElementById("one"));
	myChart2 = echarts.init(document.getElementById("two"));
	myChart3 = echarts.init(document.getElementById("three"));
	myChart4 = echarts.init(document.getElementById("four"));
	await getTopShelfGoodsCount1(); // 没数据
	await getShelfGoodsCount2(); //没数据
	await getTopDownGoods3();
	await getGoodsToUpInRecentDays4();
	// 数据加载完成后设置图表选项
	setPieChartOptions1();
	setPieChartOptions2();
	setPieChartOptions3();
	setPieChartOptions4();
});

onUnmounted(() => {
	clearInterval(timer);
});

const setPieChartOptions1 = () => {
	if (myChart1 && data11.value.length > 0) {
		myChart1.resize({ width: 360, height: 340 });
		myChart1.setOption({
			title: {
				text: "上架数量前6",
				left: "center",
				top: "5%",
				textStyle: {
					fontFamily: "Arial",
					fontSize: 13,
					fontWeight: "normal",
					color: "rgb(62, 87, 111)",
				},
			},
			tooltip: {
				trigger: "item",
				formatter: "{a} <br/>{b}: {c} ({d}%)",
			},
			toolbox: {
				show: true,
				orient: "horizontal",
				itemSize: 20,
				feature: {
					mytool: {
						show: true,
						title: "打印",
						icon: "image://data:image/svg+xml;base64,PHN2ZyB0PSIxNzQwMzIzMzk1ODQwMyIgY2xhc3M9Imljb24iIHZpZXdCb3g9IjAgMCAxMDI0IDEwMjQiIHZlcnNpb249IjEuMSIgeG1sbnM9Imh0dHA6Ly93d3cudzMub3JnLzIwMDAvc3ZnIiBwLWlkPSI2NTkwIiB3aWR0aD0iMzIiIGhlaWdodD0iMzIiPjxwYXRoIGQ9Ik05MjggMjg4SDk2djM4NGgxNjB2MjI0aDUxMlY2NzJoMTYwek03MDQgODMySDMyMFY1NDRoMzg0eiBtMTYwLTIyNGgtOTZ2LTEyOEgyNTZ2MTI4aC05NlYzNTJoNzA0ek0zMjAgMTkyaDM4NHY2NGg2NFYxMjhIMjU2djEyOGg2NHYtNjR6IiBmaWxsPSIjMzMzMzMzIiBwLWlkPSI2NTkxIj48L3BhdGg+PHBhdGggZD0iTTM4NCA2MDhoMjU2djY0SDM4NHpNMzg0IDcwNGgyNTZ2NjRIMzg0eiIgZmlsbD0iIzMzMzMzMyIgcC1pZD0iNjU5MiI+PC9wYXRoPjxwYXRoIGQ9Ik04MDAgNDE2bS0zMiAwYTMyIDMyIDAgMSAwIDY0IDAgMzIgMzIgMCAxIDAtNjQgMFoiIGZpbGw9IiMzMzMzMzMiIHAtaWQ9IjY1OTMiPjwvcGF0aD48L3N2Zz4=", // 使用Base64编码的SVG图标
						onclick: function () {
							window.print();
						},
					},
					saveAsImage: {
						show: true,
						title: "保存为图片",
						type: "png",
						name: "chart",
						excludeComponents: ["toolbox"],
					},
				},
			},
			legend: {
				orient: "horizontal",
				bottom: 0,
				left: "center",
				data: data1.value,
				borderWidth: 0.5,
				borderColor: "#000",
				padding: 4,
				backgroundColor: "#f1f4f5",
				borderRadius: 5,
			},
			series: [
				{
					name: "上架数量",
					type: "pie",
					radius: "50%",
					data: data11.value,
					emphasis: {
						itemStyle: {
							shadowBlur: 10,
							shadowOffsetX: 0,
							shadowColor: "rgba(0, 0, 0, 0.5)",
						},
					},
					label: {
						show: true,
						formatter: (params) => `${params.value.toFixed(1)}`, // 显示名称、值和百分比，保留一位小数
					},
				},
			],
		});
	}
};
const setPieChartOptions2 = () => {
	if (myChart2 && data2.value.length > 0) {
		myChart2.resize({ width: 320, height: 340 });
		myChart2.setOption({
			title: {
				text: "近七日下架数",
				left: "center",
				top: "5%", // 距离顶部 10%
				textStyle: {
					fontFamily: " Arial", // 设置字体
					fontSize: 13, // 设置字体大小
					fontWeight: "normal", // 设置字体粗细
					color: "rgb(62, 87, 111)", // 设置字体颜色
				},
			},
			tooltip: {
				trigger: "axis",
			},
			toolbox: {
				show: true,
				orient: "horizontal",
				itemSize: 20,
				feature: {
					// 添加自定义打印按钮
					mytool: {
						show: true, // 显示自定义按钮
						title: "打印", // 按钮的提示文字
						icon: "image://data:image/svg+xml;base64,PHN2ZyB0PSIxNzQwMzIzMzk1ODQwMyIgY2xhc3M9Imljb24iIHZpZXdCb3g9IjAgMCAxMDI0IDEwMjQiIHZlcnNpb249IjEuMSIgeG1sbnM9Imh0dHA6Ly93d3cudzMub3JnLzIwMDAvc3ZnIiBwLWlkPSI2NTkwIiB3aWR0aD0iMzIiIGhlaWdodD0iMzIiPjxwYXRoIGQ9Ik05MjggMjg4SDk2djM4NGgxNjB2MjI0aDUxMlY2NzJoMTYwek03MDQgODMySDMyMFY1NDRoMzg0eiBtMTYwLTIyNGgtOTZ2LTEyOEgyNTZ2MTI4aC05NlYzNTJoNzA0ek0zMjAgMTkyaDM4NHY2NGg2NFYxMjhIMjU2djEyOGg2NHYtNjR6IiBmaWxsPSIjMzMzMzMzIiBwLWlkPSI2NTkxIj48L3BhdGg+PHBhdGggZD0iTTM4NCA2MDhoMjU2djY0SDM4NHpNMzg0IDcwNGgyNTZ2NjRIMzg0eiIgZmlsbD0iIzMzMzMzMyIgcC1pZD0iNjU5MiI+PC9wYXRoPjxwYXRoIGQ9Ik04MDAgNDE2bS0zMiAwYTMyIDMyIDAgMSAwIDY0IDAgMzIgMzIgMCAxIDAtNjQgMFoiIGZpbGw9IiMzMzMzMzMiIHAtaWQ9IjY1OTMiPjwvcGF0aD48L3N2Zz4=", // 使用Base64编码的SVG图标
						onclick: function () {
							// 打印图表内容
							window.print(); // 触发浏览器打印对话框
						},
					},
					saveAsImage: {
						show: true,
						title: "保存为图片",
						type: "png",
						name: "chart", // 图片文件名
						excludeComponents: ["toolbox"], // 排除 toolbox 组件
					},
				},
			},
			legend: {
				data: ["近七日下架量"],
				bottom: 0,
				left: "center",
				borderWidth: 0.5, // 设置边框宽度
				borderColor: "#000", // 设置边框颜色
				padding: 5, // 设置内边距
				backgroundColor: "#f1f4f5", // 设置背景颜色（可选）
				borderRadius: 5, // 设置圆角半径
			},
			xAxis: {
				type: "category",
				boundaryGap: false,
				data: data2.value,
				axisLine: {
					show: true,
					onZero: false, // 设置 x 轴不在 y 轴的 0 刻度处显示
					zeroAxisIndex: 0, // 指定零轴索引（这里只有一个 y 轴，所以是 0 ）
				},
				axisLabel: {
					interval: 0, // 显示所有标签
					formatter: (value) => {
						const parts = value.split("-");
						return [`{a|${parts[0]}}`, `{b|${parts[1]}-${parts[2]}}`].join("\n"); // 使用换行符
					},
					rich: {
						a: {
							lineHeight: 20,
							align: "center",
							fontSize: 12,
						},
						b: {
							lineHeight: 20,
							align: "center",
							fontSize: 12,
						},
					},
				},
			},
			yAxis: {
				type: "value",
				name: "Y-values",
				nameLocation: "middle",
				nameRotate: 90,
				nameGap: 32,
				min: -200,
				max: 600,
			},
			series: [
				{
					name: "近七日下架量",
					type: "line",
					// data: [10, 30, 2, 1, 10, 580, 0],
					data: data22.value,
					itemStyle: {
						color: "#4E8BC1",
					},
					lineStyle: {
						width: 2,
					},
					symbol: "circle", // 数据点的形状
					symbolSize: 6, // 数据点的大小
				},
			],
		});
	}
};
const setPieChartOptions3 = () => {
	if (myChart3 && data3.value.length > 0) {
		myChart3.resize({ width: 350, height: 350 });
		myChart3.setOption({
			title: {
				text: "下架数量前6",
				left: "center",
				top: "5%", // 距离顶部 10%
				textStyle: {
					fontFamily: " Arial", // 设置字体
					fontSize: 13, // 设置字体大小
					fontWeight: "normal", // 设置字体粗细
					color: "rgb(62, 87, 111)", // 设置字体颜色
				},
			},
			toolbox: {
				show: true,
				orient: "horizontal",
				itemSize: 20,
				feature: {
					// 添加自定义打印按钮
					mytool: {
						show: true, // 显示自定义按钮
						title: "打印", // 按钮的提示文字
						icon: "image://data:image/svg+xml;base64,PHN2ZyB0PSIxNzQwMzIzMzk1ODQwMyIgY2xhc3M9Imljb24iIHZpZXdCb3g9IjAgMCAxMDI0IDEwMjQiIHZlcnNpb249IjEuMSIgeG1sbnM9Imh0dHA6Ly93d3cudzMub3JnLzIwMDAvc3ZnIiBwLWlkPSI2NTkwIiB3aWR0aD0iMzIiIGhlaWdodD0iMzIiPjxwYXRoIGQ9Ik05MjggMjg4SDk2djM4NGgxNjB2MjI0aDUxMlY2NzJoMTYwek03MDQgODMySDMyMFY1NDRoMzg0eiBtMTYwLTIyNGgtOTZ2LTEyOEgyNTZ2MTI4aC05NlYzNTJoNzA0ek0zMjAgMTkyaDM4NHY2NGg2NFYxMjhIMjU2djEyOGg2NHYtNjR6IiBmaWxsPSIjMzMzMzMzIiBwLWlkPSI2NTkxIj48L3BhdGg+PHBhdGggZD0iTTM4NCA2MDhoMjU2djY0SDM4NHpNMzg0IDcwNGgyNTZ2NjRIMzg0eiIgZmlsbD0iIzMzMzMzMyIgcC1pZD0iNjU5MiI+PC9wYXRoPjxwYXRoIGQ9Ik04MDAgNDE2bS0zMiAwYTMyIDMyIDAgMSAwIDY0IDAgMzIgMzIgMCAxIDAtNjQgMFoiIGZpbGw9IiMzMzMzMzMiIHAtaWQ9IjY1OTMiPjwvcGF0aD48L3N2Zz4=", // 使用Base64编码的SVG图标
						onclick: function () {
							// 打印图表内容
							window.print(); // 触发浏览器打印对话框
						},
					},
					saveAsImage: {
						show: true,
						title: "保存为图片",
						type: "png",
						name: "chart", // 图片文件名
						excludeComponents: ["toolbox"], // 排除 toolbox 组件
					},
				},
			},
			tooltip: {},
			legend: {
				show: true, //是否显示
				data: ["下架数量前6"],
				bottom: "5%",
				left: "center",
				borderWidth: 0.5, // 设置边框宽度
				borderColor: "#000", // 设置边框颜色
				padding: 5, // 设置内边距
				backgroundColor: "#f1f4f5", // 设置背景颜色（可选）
				borderRadius: 5, // 设置圆角半径
			},
			xAxis: {
				type: "category",
				data: data3.value,
				axisLabel: {
					interval: 0,
				},
			},
			yAxis: {
				type: "value",
				name: "Y-values",
				nameLocation: "middle",
				nameRotate: 90,
				nameGap: 35,
			},
			series: [
				{
					name: "下架数量前6",
					type: "bar",
					data: data33.value,
					label: {
						show: true,
						position: "top",
						formatter: (params) => `${params.value.toFixed(1)}`, // 显示名称、值和百分比，保留一位小数
					},
				},
			],
		});
	}
};
const setPieChartOptions4 = () => {
	if (myChart4 && data4.value.length > 0) {
		myChart4.resize({ width: 320, height: 340 });
		myChart4.setOption({
			title: {
				text: "近七日上架数",
				left: "center",
				top: "5%", // 距离顶部 10%
				textStyle: {
					fontFamily: " Arial", // 设置字体
					fontSize: 13, // 设置字体大小
					fontWeight: "normal", // 设置字体粗细
					color: "rgb(62, 87, 111)", // 设置字体颜色
				},
			},
			tooltip: {
				trigger: "axis",
			},
			toolbox: {
				show: true,
				orient: "horizontal",
				itemSize: 20,
				feature: {
					// 添加自定义打印按钮
					mytool: {
						show: true, // 显示自定义按钮
						title: "打印", // 按钮的提示文字
						icon: "image://data:image/svg+xml;base64,PHN2ZyB0PSIxNzQwMzIzMzk1ODQwMyIgY2xhc3M9Imljb24iIHZpZXdCb3g9IjAgMCAxMDI0IDEwMjQiIHZlcnNpb249IjEuMSIgeG1sbnM9Imh0dHA6Ly93d3cudzMub3JnLzIwMDAvc3ZnIiBwLWlkPSI2NTkwIiB3aWR0aD0iMzIiIGhlaWdodD0iMzIiPjxwYXRoIGQ9Ik05MjggMjg4SDk2djM4NGgxNjB2MjI0aDUxMlY2NzJoMTYwek03MDQgODMySDMyMFY1NDRoMzg0eiBtMTYwLTIyNGgtOTZ2LTEyOEgyNTZ2MTI4aC05NlYzNTJoNzA0ek0zMjAgMTkyaDM4NHY2NGg2NFYxMjhIMjU2djEyOGg2NHYtNjR6IiBmaWxsPSIjMzMzMzMzIiBwLWlkPSI2NTkxIj48L3BhdGg+PHBhdGggZD0iTTM4NCA2MDhoMjU2djY0SDM4NHpNMzg0IDcwNGgyNTZ2NjRIMzg0eiIgZmlsbD0iIzMzMzMzMyIgcC1pZD0iNjU5MiI+PC9wYXRoPjxwYXRoIGQ9Ik04MDAgNDE2bS0zMiAwYTMyIDMyIDAgMSAwIDY0IDAgMzIgMzIgMCAxIDAtNjQgMFoiIGZpbGw9IiMzMzMzMzMiIHAtaWQ9IjY1OTMiPjwvcGF0aD48L3N2Zz4=", // 使用Base64编码的SVG图标
						onclick: function () {
							// 打印图表内容
							window.print(); // 触发浏览器打印对话框
						},
					},
					saveAsImage: {
						show: true,
						title: "保存为图片",
						type: "png",
						name: "chart", // 图片文件名
						excludeComponents: ["toolbox"], // 排除 toolbox 组件
					},
				},
			},
			legend: {
				data: ["近七日上架量"],
				bottom: 0,
				left: "center",
				borderWidth: 0.5, // 设置边框宽度
				borderColor: "#000", // 设置边框颜色
				padding: 5, // 设置内边距
				backgroundColor: "#f1f4f5", // 设置背景颜色（可选）
				borderRadius: 5, // 设置圆角半径
			},
			xAxis: {
				type: "category",
				boundaryGap: false,
				data: data4.value,
				axisLine: {
					show: true,
					onZero: false, // 设置 x 轴不在 y 轴的 0 刻度处显示
					zeroAxisIndex: 0, // 指定零轴索引（这里只有一个 y 轴，所以是 0 ）
				},
				axisLabel: {
					interval: 0, // 显示所有标签
					formatter: (value) => {
						const parts = value.split("-");
						return [`{a|${parts[0]}}`, `{b|${parts[1]}-${parts[2]}}`].join("\n"); // 使用换行符
					},
					rich: {
						a: {
							lineHeight: 20,
							align: "center",
							fontSize: 12,
						},
						b: {
							lineHeight: 20,
							align: "center",
							fontSize: 12,
						},
					},
				},
			},
			yAxis: {
				type: "value",
				name: "Y-values",
				nameLocation: "middle",
				nameRotate: 90,
				nameGap: 32,
				min: -200,
				max: 600,
			},
			series: [
				{
					name: "近七日上架量",
					type: "line",
					// data: [10, 30, 2, 1, 10, 580, 0],
					data: data44.value,
					itemStyle: {
						color: "#4E8BC1",
					},
					lineStyle: {
						width: 2,
					},
					symbol: "circle", // 数据点的形状
					symbolSize: 6, // 数据点的大小
				},
			],
		});
	}
};
</script>

<template>
	<div class="container">
		<div class="header">
			<p>欢迎您使用WMS，现在时间:{{ time }}</p>
			<p>您有 10391 件商品需要做库存调整，请及时调整</p>
		</div>
		<div class="body">
			<div class="card">
				<div class="up">
					<div class="icon" style="background-color: rgb(242, 166, 84)">
						<div class="iconfont icon-gouwuche"></div>
					</div>
					<span>待收货</span>
				</div>
				<div class="down">
					<div class="box1">
						<div class="iconfont icon-xiangshang1"></div>
						<span>{{ waitReceiveGoodsCount || "0" }}</span>
					</div>
					<div class="box2">
						<span>待收获件数</span>
					</div>
				</div>
			</div>
			<div class="card">
				<div class="up">
					<div class="icon" style="background-color: rgb(249, 104, 104)">
						<div class="iconfont icon-renminbi1688"></div>
					</div>
					<span>待上架</span>
				</div>
				<div class="down">
					<div class="box1">
						<div class="iconfont icon-xiangshang1"></div>
						<span>{{ waitShelfGoodsCount || "0" }}</span>
					</div>
					<div class="box2">
						<span>待上架件数</span>
					</div>
				</div>
			</div>
			<div class="card">
				<div class="up">
					<div class="icon" style="background-color: rgb(70, 190, 138)">
						<div class="iconfont icon-xiaoyanjing"></div>
					</div>
					<span>待拣货</span>
				</div>
				<div class="down">
					<div class="box1">
						<div class="iconfont icon-xiangshang1"></div>
						<span>{{ waitPickGoodsCount || "0" }}</span>
					</div>
					<div class="box2">
						<span>待拣货件数</span>
					</div>
				</div>
			</div>
			<div class="card">
				<div class="up">
					<div class="icon" style="background-color: rgb(98, 168, 234)">
						<div class="iconfont icon-xiaoren"></div>
					</div>
					<span>拣货中</span>
				</div>
				<div class="down">
					<div class="box1">
						<div class="iconfont icon-xiangshang1"></div>
						<span>{{ pickingGoodsCount || "0" }}</span>
					</div>
					<div class="box2">
						<span>拣货中件数</span>
					</div>
				</div>
			</div>
		</div>
		<div class="footer">
			<div id="one"></div>
			<div id="two"></div>
			<div id="three"></div>
			<div id="four"></div>
		</div>
	</div>
</template>

<style scoped>
* {
	margin: 0;
	padding: 0;
}

.container {
	display: flex;
	flex-direction: column;
	background-color: #f2f2f2;
}
.header {
	margin: 5px 5px 30px 5px;
	width: 99%;
	height: 120px;
	background-color: #fff;
	display: flex; /* 添加 Flexbox */
	flex-direction: column; /* 设置为列方向 */
	justify-content: center; /* 垂直居中 */
	align-items: flex-start; /* 左对齐 */
}

.header p {
	padding-left: 50px;
	font-size: 18px;
	color: rgb(55, 71, 79);
}

.body {
	margin: 5px 5px 30px 5px;
	width: 99%;
	height: 150px;
	background-color: #fff;
	display: flex;
}

.card {
	padding: 20px;
	height: 100%;
	width: 25%;
	background-color: #fff;
	border-right: 1px solid #f1f4f5;
	display: flex;
	flex-direction: column;
}
.card .up {
	height: 50%;
	width: 100%;
	display: flex;
}
.card .up span {
	color: #76838f;
	font-size: 12px;
	margin-left: 20px;
	height: 50px;
	line-height: 40px;
}
.icon {
	width: 40px;
	height: 40px;
	border-radius: 50%;
}

.icon div {
	font-size: 12px;
	color: white;
	line-height: 40px;
	text-align: center;
}

.card .down {
	text-align: center;
	display: flex;
	flex-direction: column;
}
.box1 {
	display: flex;
	width: 100%;
	justify-content: center;
}

.box1 .iconfont {
	font-size: 12px;
	color: #f96868;
}

.box1 span {
	color: #76838f;
	font-size: 30px;
	line-height: 30px;
	margin-left: 5px;
}

.box2 span {
	color: #a3afb7;
	font-size: 12px;
}

.footer {
	margin: 5px 5px 5px 0px;
	width: 99%;
	height: 350px;
	background-color: #fff;
	display: flex;
}
</style>
