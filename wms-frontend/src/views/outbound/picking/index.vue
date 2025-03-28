<template>
	<div class="picking-list">
		<EditableDataGrid
			title="按单拣货"
			:columns="columns"
			:data-source="dataSource"
			@save="handleSave"
			@export="handleExport"
			@view="handleView"
			@edit="handleEdit"
			@cancel="handleCancel"
		/>
	</div>
</template>

<script setup lang="ts">
import { Tickets } from "@element-plus/icons-vue";
import { ref } from "vue";
import EditableDataGrid from "./components/MultiRowEditor.vue";
import { ElMessage } from "element-plus";
import type { Column } from "./types/picking";

definePage({
	meta: {
		menuType: "page",
		text: "按单拣货",
		icon: Tickets,
	},
});

// 定义表格列配置
const columns: Column[] = [
	{
		title: "创建日期",
		field: "createDate",
		width: 100,
		formatter: (val) => (val ? new Date(val).toLocaleDateString() : ""),
	},
	{ title: "原始单据编码", field: "orderId", width: 120 },
	{ title: "商品编码", field: "goodsId", width: 100 },
	{ title: "商品名称", field: "goodsName", width: 200 },
	{ title: "客户订单号", field: "customerOrderNo", width: 120 },
	{ title: "备注", field: "remark", width: 120 },
	{ title: "数量", field: "quantity", width: 80, editable: true },
	{ title: "复核数量", field: "checkQuantity", width: 80, editable: true },
	{ title: "基本单位", field: "baseUnit", width: 80, editable: true },
	{ title: "单位", field: "unit", width: 60 },
	{
		title: "生产日期",
		field: "productionDate",
		width: 100,
		formatter: (val) => (val ? new Date(val).toLocaleDateString() : ""),
		editable: true,
	},
	{ title: "源托盘码", field: "palletCode", width: 80, editable: true },
	{ title: "库位编码", field: "locationCode", width: 80, editable: true },
	{ title: "货主", field: "owner", width: 80 },
];

// 模拟数据
const dataSource = ref([
	{
		id: 1,
		createDate: new Date("2023-10-15"),
		orderId: "SO20231015001",
		goodsId: "SKU10045",
		goodsName: "苹果iPhone 15 Pro 256GB 钛金色",
		customerOrderNo: "JD89745632",
		remark: "易碎品，小心轻放",
		quantity: 5,
		checkQuantity: 5,
		baseUnit: "台",
		unit: "台",
		productionDate: new Date("2023-09-01"),
		palletCode: "PLT-A-1001",
		locationCode: "A-01-01-01",
		owner: "京东自营",
	},
	{
		id: 2,
		createDate: new Date("2023-10-15"),
		orderId: "SO20231015001",
		goodsId: "SKU10046",
		goodsName: "苹果AirPods Pro 2代",
		customerOrderNo: "JD89745632",
		remark: "",
		quantity: 3,
		checkQuantity: 3,
		baseUnit: "个",
		unit: "个",
		productionDate: new Date("2023-08-15"),
		palletCode: "PLT-A-1002",
		locationCode: "A-01-01-02",
		owner: "京东自营",
	},
	{
		id: 3,
		createDate: new Date("2023-10-16"),
		orderId: "SO20231016002",
		goodsId: "SKU20078",
		goodsName: "华为Mate 60 Pro 512GB 曜金黑",
		customerOrderNo: "TMO7865432",
		remark: "优先发货",
		quantity: 2,
		checkQuantity: 2,
		baseUnit: "台",
		unit: "台",
		productionDate: new Date("2023-09-10"),
		palletCode: "PLT-B-2001",
		locationCode: "B-02-01-01",
		owner: "天猫旗舰店",
	},
	{
		id: 4,
		createDate: new Date("2023-10-16"),
		orderId: "SO20231016003",
		goodsId: "SKU30112",
		goodsName: "小米电视 65英寸 4K超高清",
		customerOrderNo: "PDD6543219",
		remark: "需要安装服务",
		quantity: 1,
		checkQuantity: 1,
		baseUnit: "台",
		unit: "台",
		productionDate: new Date("2023-08-20"),
		palletCode: "PLT-C-3005",
		locationCode: "C-03-02-01",
		owner: "拼多多专营",
	},
	{
		id: 5,
		createDate: new Date("2023-10-17"),
		orderId: "SO20231017004",
		goodsId: "SKU40256",
		goodsName: "戴森吸尘器 V12 Detect Slim",
		customerOrderNo: "JD89746123",
		remark: "含税发票",
		quantity: 3,
		checkQuantity: 2,
		baseUnit: "台",
		unit: "台",
		productionDate: new Date("2023-07-15"),
		palletCode: "PLT-D-4002",
		locationCode: "D-01-03-02",
		owner: "京东自营",
	},
	// {
	// 	id: 6,
	// 	createDate: new Date("2023-10-17"),
	// 	orderId: "SO20231017005",
	// 	goodsId: "SKU50389",
	// 	goodsName: "耐克Air Jordan 1 篮球鞋",
	// 	customerOrderNo: "TMO7865987",
	// 	remark: "指定快递：顺丰",
	// 	quantity: 10,
	// 	checkQuantity: 10,
	// 	baseUnit: "双",
	// 	unit: "箱",
	// 	productionDate: new Date("2023-06-01"),
	// 	palletCode: "PLT-E-5010",
	// 	locationCode: "E-02-01-03",
	// 	owner: "天猫旗舰店",
	// },
	// {
	// 	id: 7,
	// 	createDate: new Date("2023-10-18"),
	// 	orderId: "SO20231018006",
	// 	goodsId: "SKU60472",
	// 	goodsName: "雅诗兰黛小棕瓶精华液 100ml",
	// 	customerOrderNo: "JD89747654",
	// 	remark: "保税仓发货",
	// 	quantity: 20,
	// 	checkQuantity: 20,
	// 	baseUnit: "瓶",
	// 	unit: "盒",
	// 	productionDate: new Date("2023-05-10"),
	// 	palletCode: "PLT-F-6007",
	// 	locationCode: "F-01-02-01",
	// 	owner: "京东国际",
	// },
	// {
	// 	id: 8,
	// 	createDate: new Date("2023-10-18"),
	// 	orderId: "SO20231018007",
	// 	goodsId: "SKU70568",
	// 	goodsName: "Apple MacBook Pro 14英寸 M2 Pro",
	// 	customerOrderNo: "TMO7866543",
	// 	remark: "顾客要求送货上门",
	// 	quantity: 2,
	// 	checkQuantity: 2,
	// 	baseUnit: "台",
	// 	unit: "台",
	// 	productionDate: new Date("2023-08-05"),
	// 	palletCode: "PLT-G-7003",
	// 	locationCode: "G-03-01-02",
	// 	owner: "天猫旗舰店",
	// },
	// {
	// 	id: 9,
	// 	createDate: new Date("2023-10-19"),
	// 	orderId: "SO20231019008",
	// 	goodsId: "SKU80675",
	// 	goodsName: "三星Galaxy S23 Ultra 512GB 幻影黑",
	// 	customerOrderNo: "PDD6544321",
	// 	remark: "",
	// 	quantity: 3,
	// 	checkQuantity: 3,
	// 	baseUnit: "台",
	// 	unit: "台",
	// 	productionDate: new Date("2023-07-20"),
	// 	palletCode: "PLT-H-8001",
	// 	locationCode: "H-01-01-01",
	// 	owner: "拼多多专营",
	// },
	// {
	// 	id: 10,
	// 	createDate: new Date("2023-10-19"),
	// 	orderId: "SO20231019009",
	// 	goodsId: "SKU90782",
	// 	goodsName: "索尼PlayStation 5 数字版",
	// 	customerOrderNo: "JD89748765",
	// 	remark: "需开具增值税专用发票",
	// 	quantity: 5,
	// 	checkQuantity: 4,
	// 	baseUnit: "台",
	// 	unit: "台",
	// 	productionDate: new Date("2023-09-05"),
	// 	palletCode: "PLT-I-9004",
	// 	locationCode: "I-02-02-01",
	// 	owner: "京东自营",
	// },
	// {
	// 	id: 11,
	// 	createDate: new Date("2023-10-20"),
	// 	orderId: "SO20231020010",
	// 	goodsId: "SKU10893",
	// 	goodsName: "飞利浦空气净化器 AC2889",
	// 	customerOrderNo: "TMO7867654",
	// 	remark: "送货前电话联系",
	// 	quantity: 8,
	// 	checkQuantity: 8,
	// 	baseUnit: "台",
	// 	unit: "台",
	// 	productionDate: new Date("2023-06-15"),
	// 	palletCode: "PLT-J-1008",
	// 	locationCode: "J-01-03-01",
	// 	owner: "天猫旗舰店",
	// },
	// {
	// 	id: 12,
	// 	createDate: new Date("2023-10-20"),
	// 	orderId: "SO20231020011",
	// 	goodsId: "SKU20945",
	// 	goodsName: "卡西欧G-SHOCK 运动手表",
	// 	customerOrderNo: "PDD6545432",
	// 	remark: "礼品包装",
	// 	quantity: 15,
	// 	checkQuantity: 15,
	// 	baseUnit: "只",
	// 	unit: "盒",
	// 	productionDate: new Date("2023-04-20"),
	// 	palletCode: "PLT-K-2006",
	// 	locationCode: "K-02-01-02",
	// 	owner: "拼多多专营",
	// },
]);

// 处理编辑开始
const handleEdit = (rowIds: (string | number)[]) => {
	console.log("开始编辑行:", rowIds);
};

// 处理保存
const handleSave = async (updatedRows: any[]) => {
	try {
		// 模拟API调用
		await new Promise((resolve) => setTimeout(resolve, 800));

		// 更新本地数据
		updatedRows.forEach((updatedRow) => {
			const index = dataSource.value.findIndex((item) => item.id === updatedRow.id);
			if (index !== -1) {
				dataSource.value[index] = { ...dataSource.value[index], ...updatedRow };
			}
		});

		console.log("保存的数据:", updatedRows);
		ElMessage.success(`成功保存了 ${updatedRows.length} 条数据`);
	} catch (error) {
		console.error("保存失败:", error);
		ElMessage.error("保存失败: " + (error instanceof Error ? error.message : "未知错误"));
	}
};

// 处理取消
const handleCancel = () => {
	console.log("取消编辑");
	ElMessage.info("已取消编辑");
};

// 处理导出
// const handleExport = () => {
// 	// 模拟导出逻辑
// 	ElMessage.info("正在导出数据，请稍候...");
// 	setTimeout(() => {
// 		console.log("导出数据:", dataSource.value);
// 		ElMessage.success("数据已导出到Excel文件");
// 	}, 1500);
// };
// 处理导出 (不使用外部库的版本)
const handleExport = () => {
	ElMessage.info("正在导出数据，请稍候...");

	try {
		// 准备CSV内容
		const headers = columns.map((col) => `"${col.title}"`).join(",");

		const rows = dataSource.value
			.map((row) => {
				return columns
					.map((col) => {
						let cellValue = row[col.field];
						// 应用格式化函数
						if (col.formatter && cellValue !== undefined) {
							cellValue = col.formatter(cellValue);
						}
						// 处理包含逗号的字符串
						if (typeof cellValue === "string" && cellValue.includes(",")) {
							return `"${cellValue}"`;
						}
						return cellValue;
					})
					.join(",");
			})
			.join("\n");

		const csvContent = `${headers}\n${rows}`;

		// 创建Blob对象
		const blob = new Blob(["\ufeff" + csvContent], { type: "text/csv;charset=utf-8;" });

		// 获取当前页面名称作为文件名
		const fileName = "按单拣货" + "_" + new Date().toISOString().slice(0, 10) + ".csv";

		// 创建下载链接
		const link = document.createElement("a");
		link.href = URL.createObjectURL(blob);
		link.setAttribute("download", fileName);
		link.style.display = "none";
		document.body.appendChild(link);

		// 触发下载
		link.click();

		// 清理
		document.body.removeChild(link);

		ElMessage.success("数据已成功导出");
	} catch (error) {
		console.error("导出失败:", error);
		ElMessage.error("导出失败: " + (error instanceof Error ? error.message : "未知错误"));
	}
};

// 查看详情 - 现在接收ID而不是整行数据
const handleView = (rowId: number | string) => {
	const row = dataSource.value.find((item) => item.id === rowId);
	if (row) {
		console.log("查看详情:", row);

		// 待实现查看详情的逻辑，打开一个新的详情页面弹窗
		ElMessage.info(`正在查看订单 ${row.orderId} 中的商品 ${row.goodsName}`);
		// openDetailDialog(row);
	}
};
</script>

<style scoped lang="scss">
.picking-list {
	padding: 20px;
}
</style>
