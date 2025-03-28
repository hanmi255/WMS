<script lang="ts" setup>
definePage({
	meta: {
		menuType: "page",
		isSample: true,
		text: "下载导出按钮演示",
		icon: "IconSetting",
	},
});
// ---单图表导出示例---
// 引入jspdf,html2canvas用于打印导出
import html2canvas from "html2canvas";
import jsPDF from "jspdf";
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
} from "echarts/components";
// 标签自动布局、全局过渡动画等特性
import { LabelLayout, UniversalTransition } from "echarts/features";
// 引入 Canvas 渲染器，注意引入 CanvasRenderer 或者 SVGRenderer 是必须的一步
import { CanvasRenderer } from "echarts/renderers";
import { BarChart, LineChart, PieChart } from "echarts/charts";
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
]);
// 饼状图
onMounted(() => {
	// 初始化图表
	const myChart = echarts.init(document.getElementById("one"));
	// 设置大小
	myChart.resize({ width: 480, height: 350 });
	myChart.setOption({
		title: {
			text: "上架数量前6",
			left: "center",
		},
		tooltip: {
			trigger: "item",
			formatter: "{a} <br/>{b}: {c} ({d}%)",
		},
		legend: {
			orient: "horizontal",
			bottom: "0",
			left: "center",
			data: ["RL001-牛羊肉半成品-箱", "001-羽绒服-个", "20222-燕糖-厢", "0000-可口可乐-箱", "123456789-小蓝管-支"],
		},
		series: [
			{
				name: "上架数量",
				type: "pie",
				radius: "50%",
				data: [
					{ value: 10455.0, name: "RL001-牛羊肉半成品-箱" },
					{ value: 500.0, name: "001-羽绒服-个" },
					{ value: 250.0, name: "20222-燕糖-厢" },
					{ value: 200.0, name: "0000-可口可乐-箱" },
					{ value: 100.0, name: "123456789-小蓝管-支" },
				],
				emphasis: {
					itemStyle: {
						shadowBlur: 10,
						shadowOffsetX: 0,
						shadowColor: "rgba(0, 0, 0, 0.5)",
					},
				},
				label: {
					show: true,
					formatter: "{c} ", // 显示名称、值和百分比
				},
			},
		],
	});
});

const pagePrint = () => {
	window.print();
};
// 导出多张图表为一张图片
// dmo元素里的内容转换为canvas,并将canvas下载为图片
const chartExport = (fileType: string, typeDisplay: string) => {
	// 转换成canvas
	html2canvas(document.getElementById("one") as HTMLElement).then(function (canvas) {
		console.log(canvas);
		if (fileType !== "application/pdf") {
			var fileDownload = canvas.toDataURL(fileType).replace(fileType, "image/octet-stream"); // 创建a标签，实现下载
			var creatIMg = document.createElement("a");
			creatIMg.download = "图表." + typeDisplay; // 设置下载的文件名，
			creatIMg.href = fileDownload; // 下载url
			document.body.appendChild(creatIMg);
			creatIMg.click();
			creatIMg.remove(); // 下载之后把创建的元素删除
		} else {
			let contentWidth = canvas.width;
			let contentHeight = canvas.height;
			//a4纸的尺寸[595.28,841.89]，html页面生成的canvas在pdf中图片的宽高
			let imgWidth = 595.28;
			let imgHeight = (592.28 / contentWidth) * contentHeight; // 第一个参数： l：横向  p：纵向
			// 第二个参数：测量单位（"pt"，"mm", "cm", "m", "in" or "px"）
			let pdf = new jsPDF("p", "pt");
			pdf.addImage(canvas.toDataURL("image/jpeg", 1.0), "JPEG", 0, 0, imgWidth, imgHeight);
			pdf.save("图表" + ".pdf");
		}
	});
};
const gridDatas = [
	{
		date: "下载png图片",
		fileType: "image/png",
		typeDisplay: ".png",
	},
	{
		date: "下载JPEG图片",
		fileType: "image/jpeg",
		typeDisplay: ".jpg",
	},
	{
		date: "下载pdf文件",
		fileType: "application/pdf",
		typeDisplay: ".pdf",
	},
	{
		date: "下载svg矢量图片",
		fileType: "image/svg+xml",
		typeDisplay: ".svg",
	},
];
</script>

<template>
	<div id="one"></div>
	<!-- 打印 -->
	<el-button @click="pagePrint"
		><el-icon> <iconPrinter /> </el-icon
	></el-button>
	<!-- 下载文件 -->
	<el-dropdown
		><el-button
			><el-icon> <iconDownload /> </el-icon
		></el-button>
		<template #dropdown>
			<el-dropdown-menu>
				<el-dropdown-item
					v-for="(gridData, index) in gridDatas"
					:key="index"
					@click="chartExport(gridData.fileType, gridData.typeDisplay)"
					>{{ gridData.date }}</el-dropdown-item
				>
			</el-dropdown-menu>
		</template>
	</el-dropdown>
</template>

<style scoped></style>
