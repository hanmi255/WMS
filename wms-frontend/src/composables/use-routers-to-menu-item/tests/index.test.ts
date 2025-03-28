import { test } from "vitest";

import { PartialPick } from "type-plus";
import type { RouteRecordRaw, RouteRecordNormalized } from "vue-router";
import { useRouterToMenuItem } from "composables/use-routers-to-menu-item/index";

type Route = PartialPick<RouteRecordRaw, "redirect">;

// RouteRecordRedirect

declare module "vue-router" {
	interface RouteRecordRedirect {
		// @ts-ignore
		redirect?: RouteRecordRedirectOption;
	}
}

/**
 * 测试数组 这些路由都是写死的测试路由
 */
const routes_v1: Readonly<Route[]> = [
	{
		path: "/sample",
		component: {
			__name: "default",
			__hmrId: "19b56bd5",
			__scopeId: "data-v-19b56bd5",
			__file: "D:/code/01s/202502-10wms/01s-10wms/wms-frontend/src/layouts/default.vue",
		},
		children: [
			{
				path: "",
				name: "Sample",
				redirect: {
					path: "/sample/file",
				},
				children: [
					{
						path: "/sample/file",
					},
					{
						path: "/sample/excel",
					},
					{
						path: "/sample/print",
					},
					{
						path: "/sample/editor",
					},
					{
						path: "/sample/pdfobject",
					},
					{
						path: "/sample/echarts",
					},
					{
						path: "/sample/formcreate",
					},
					{
						path: "/sample/flow",
					},
				],
			},
		],
		// @ts-ignore
		meta: {
			isLayout: true,
		},
	},
	{
		path: "/",
		component: {
			__name: "default",
			__hmrId: "19b56bd5",
			__scopeId: "data-v-19b56bd5",
			__file: "D:/code/01s/202502-10wms/01s-10wms/wms-frontend/src/layouts/default.vue",
		},
		children: [
			{
				path: "/",
				name: "Login",
				// @ts-ignore
				meta: {},
				alias: [],
			},
		],
		// @ts-ignore
		meta: {
			isLayout: true,
		},
	},
	{
		path: "/daily-check",
		component: {
			__name: "default",
			__hmrId: "19b56bd5",
			__scopeId: "data-v-19b56bd5",
			__file: "D:/code/01s/202502-10wms/01s-10wms/wms-frontend/src/layouts/default.vue",
		},
		children: [
			{
				path: "",
				children: [
					{
						path: "abnormal-shipment",
						name: "daily-check-abnormal-shipment",
						// @ts-ignore
						meta: {
							text: "温度维护",
							icon: "温度维护-fuck",
						},
						alias: [],
					},
					{
						path: "received-unsold",
						name: "daily-check-received-unsold",
						// @ts-ignore
						meta: {
							text: "收货未上架",
							icon: "收货未上架-kya",
						},
						alias: [],
					},
				],
			},
		],
		// @ts-ignore
		meta: {
			isLayout: true,
		},
	},
	{
		path: "/home",
		component: {
			__name: "default",
			__hmrId: "19b56bd5",
			__scopeId: "data-v-19b56bd5",
			__file: "D:/code/01s/202502-10wms/01s-10wms/wms-frontend/src/layouts/default.vue",
		},
		children: [
			{
				path: "",
				name: "home",
				// @ts-ignore
				meta: {},
				alias: [],
			},
		],
		// @ts-ignore
		meta: {
			isLayout: true,
		},
	},
	{
		path: "/sample",
		component: {
			__name: "default",
			__hmrId: "19b56bd5",
			__scopeId: "data-v-19b56bd5",
			__file: "D:/code/01s/202502-10wms/01s-10wms/wms-frontend/src/layouts/default.vue",
		},
		children: [
			{
				path: "",
				children: [
					{
						path: "echarts",
						children: [
							{
								path: "Echarts",
								name: "sample-echarts-Echarts",
							},
						],
					},
					{
						path: "editor",
						children: [
							{
								path: "Editor",
								name: "sample-editor-Editor",
							},
						],
					},
					{
						path: "excel",
						children: [
							{
								path: "Excel",
								name: "sample-excel-Excel",
							},
						],
					},
					{
						path: "file",
						children: [
							{
								path: "FileUpload",
								name: "sample-file-FileUpload",
							},
						],
					},
					{
						path: "flow",
						children: [
							{
								path: "Flow",
								name: "sample-flow-Flow",
							},
						],
					},
					{
						path: "formcreate",
						children: [
							{
								path: "FormCreate",
								name: "sample-formcreate-FormCreate",
							},
						],
					},
					{
						path: "pdfobject",
						children: [
							{
								path: "PdfObject",
								name: "sample-pdfobject-PdfObject",
							},
						],
					},
					{
						path: "print",
						children: [
							{
								path: "Print",
								name: "sample-print-Print",
							},
						],
					},
					{
						path: "SampleView",
						name: "sample-SampleView",
					},
				],
			},
		],
		// @ts-ignore
		meta: {
			isLayout: true,
		},
	},
	{
		path: "/status",
		component: {
			__name: "default",
			__hmrId: "19b56bd5",
			__scopeId: "data-v-19b56bd5",
			__file: "D:/code/01s/202502-10wms/01s-10wms/wms-frontend/src/layouts/default.vue",
		},
		children: [
			{
				path: "",
				children: [
					{
						path: "/:pathMatch(.*)*",
						name: "NotFound",
						// @ts-ignore
						meta: {},
						alias: [],
					},
					{
						path: "/error",
						name: "Error",
						// @ts-ignore
						meta: {},
						alias: [],
					},
					{
						path: "/forbidden",
						name: "Forbidden",
						// @ts-ignore
						meta: {},
						alias: [],
					},
				],
			},
		],
		// @ts-ignore
		meta: {
			isLayout: true,
		},
	},
];

type RouteRecordNormalized_Test = Omit<
	RouteRecordNormalized,
	//
	| "leaveGuards"
	//
	| "updateGuards"
	| "redirect"
	| "beforeEnter"
	| "mods"
	| "aliasOf"
	| "instances"
> & {
	leaveGuards: {};
	updateGuards: {};
	instances: {};
};

/** 来自 getRoutes 生成的扁平化路由 */
const routes_v2: RouteRecordNormalized_Test[] = [
	{
		path: "/base-data/customer",
		name: "base-data-customer",
		meta: {
			menuType: "page",
			text: "客户",
			icon: "IconWarningFilled",
		},
		props: {
			default: false,
		},
		children: [],
		instances: {},
		leaveGuards: {},
		updateGuards: {},
		enterCallbacks: {},
		components: {},
	},
	{
		path: "/customer-report/repertory",
		name: "customer-report-repertory",
		meta: {
			menuType: "page",
			text: "客户库存",
			icon: "IconSetting",
		},
		props: {
			default: false,
		},
		children: [],
		instances: {},
		leaveGuards: {},
		updateGuards: {},
		enterCallbacks: {},
		components: {},
	},
	{
		path: "/customer-report/validity-warn",
		name: "customer-report-validity-warn",
		meta: {
			menuType: "page",
			text: "效期预警",
			icon: "IconSetting",
		},
		props: {
			default: false,
		},
		children: [],
		instances: {},
		leaveGuards: {},
		updateGuards: {},
		enterCallbacks: {},
		components: {},
	},
	{
		path: "/daily-check/abnormal-shipment",
		name: "daily-check-abnormal-shipment",
		meta: {
			menuType: "page",
			text: "出货异常",
			icon: "IconSetting",
		},
		props: {
			default: false,
		},
		children: [],
		instances: {
			default: {},
		},
		leaveGuards: {},
		updateGuards: {},
		enterCallbacks: {},
		components: {
			default: {
				__name: "index",
				__hmrId: "b50325fa",
				__scopeId: "data-v-b50325fa",
				__file: "D:/code/01s/202502-10wms/01s-10wms/wms-frontend/src/views/daily-check/abnormal-shipment/index.vue",
			},
		},
	},
	{
		path: "/daily-check/received-unsold",
		name: "daily-check-received-unsold",
		meta: {
			menuType: "page",
			text: "收货未上架",
			icon: "IconSetting",
		},
		props: {
			default: false,
		},
		children: [],
		instances: {},
		leaveGuards: {},
		updateGuards: {},
		enterCallbacks: {},
		components: {},
	},
	{
		path: "/daily-check/shipment-delay-warn",
		name: "daily-check-shipment-delay-warn",
		meta: {
			menuType: "page",
			text: "出货延迟预警",
			icon: "IconSetting",
		},
		props: {
			default: false,
		},
		children: [],
		instances: {},
		leaveGuards: {},
		updateGuards: {},
		enterCallbacks: {},
		components: {},
	},
	{
		path: "/daily-check/temperature-maintain",
		name: "daily-check-temperature-maintain",
		meta: {
			menuType: "page",
			text: "温度维护",
			icon: "IconSetting",
		},
		props: {
			default: false,
		},
		children: [],
		instances: {},
		leaveGuards: {},
		updateGuards: {},
		enterCallbacks: {},
		components: {},
	},
	{
		path: "/sample/echarts",
		name: "sample-echarts",
		meta: {
			menuType: "page",
			isSample: true,
			text: "图表演示",
			icon: "IconSetting",
		},
		props: {
			default: false,
		},
		children: [],
		instances: {},
		leaveGuards: {},
		updateGuards: {},
		enterCallbacks: {},
		components: {},
	},
	{
		path: "/sample/editor",
		name: "sample-editor",
		meta: {
			menuType: "page",
			isSample: true,
			text: "富文本框演示",
			icon: "IconSetting",
		},
		props: {
			default: false,
		},
		children: [],
		instances: {},
		leaveGuards: {},
		updateGuards: {},
		enterCallbacks: {},
		components: {},
	},
	{
		path: "/sample/excel",
		name: "sample-excel",
		meta: {
			menuType: "page",
			isSample: true,
			text: "Excel演示",
			icon: "IconSetting",
		},
		props: {
			default: false,
		},
		children: [],
		instances: {},
		leaveGuards: {},
		updateGuards: {},
		enterCallbacks: {},
		components: {},
	},
	{
		path: "/sample/file-upload",
		name: "sample-file-upload",
		meta: {
			menuType: "page",
			isSample: true,
			text: "文件上传",
			icon: "IconSetting",
		},
		props: {
			default: false,
		},
		children: [],
		instances: {},
		leaveGuards: {},
		updateGuards: {},
		enterCallbacks: {},
		components: {},
	},
	{
		path: "/sample/flow",
		name: "sample-flow",
		meta: {
			menuType: "page",
			isSample: true,
			text: "流程图编辑器演示",
			icon: "IconSetting",
		},
		props: {
			default: false,
		},
		children: [],
		instances: {},
		leaveGuards: {},
		updateGuards: {},
		enterCallbacks: {},
		components: {},
	},
	{
		path: "/sample/form-create",
		name: "sample-form-create",
		meta: {
			menuType: "page",
			isSample: true,
			text: "可视化表单演示",
			icon: "IconSetting",
		},
		props: {
			default: false,
		},
		children: [],
		instances: {},
		leaveGuards: {},
		updateGuards: {},
		enterCallbacks: {},
		components: {},
	},
	{
		path: "/sample/pdf-object",
		name: "sample-pdf-object",
		meta: {
			menuType: "page",
			isSample: true,
			text: "PDF预览演示",
			icon: "IconSetting",
		},
		props: {
			default: false,
		},
		children: [],
		instances: {},
		leaveGuards: {},
		updateGuards: {},
		enterCallbacks: {},
		components: {},
	},
	{
		path: "/sample/print",
		name: "sample-print",
		meta: {
			menuType: "page",
			isSample: true,
			text: "打印演示",
			icon: "IconSetting",
		},
		props: {
			default: false,
		},
		children: [],
		instances: {},
		leaveGuards: {},
		updateGuards: {},
		enterCallbacks: {},
		components: {},
	},
	{
		path: "/sample/table",
		name: "sample-table",
		meta: {
			menuType: "page",
			isSample: true,
			text: "表格组件",
			icon: "IconSetting",
		},
		props: {
			default: false,
		},
		children: [],
		instances: {},
		leaveGuards: {},
		updateGuards: {},
		enterCallbacks: {},
		components: {},
	},
	{
		path: "/sample/TableTitleDisplay",
		name: "sample-TableTitleDisplay",
		meta: {
			menuType: "page",
			isSample: true,
			text: "表格标题栏",
			icon: "IconSetting",
		},
		props: {
			default: false,
		},
		children: [],
		instances: {},
		leaveGuards: {},
		updateGuards: {},
		enterCallbacks: {},
		components: {},
	},
	{
		path: "/",
		name: "Login",
		meta: {
			layout: "login",
			// 登录页应该被忽略 不属于菜单侧边栏的一部分
			menuType: "ignore",
			text: "登录页",
			icon: "WarningFilled",
		},
		props: {
			default: false,
		},
		children: [],
		instances: {
			default: null,
		},
		leaveGuards: {},
		updateGuards: {},
		enterCallbacks: {},
		components: {
			default: {
				__name: "login",
				__hmrId: "d0e06bca",
				__file: "D:/code/01s/202502-10wms/01s-10wms/wms-frontend/src/views/login.vue",
			},
		},
	},
	{
		path: "/base-data",
		name: "base-data",
		meta: {
			menuType: "folder",
			text: "基础资料",
			icon: "WarningFilled",
			order: 10,
		},
		props: {
			default: false,
		},
		children: [],
		instances: {},
		leaveGuards: {},
		updateGuards: {},
		enterCallbacks: {},
		components: {},
	},
	{
		path: "/customer-report",
		name: "customer-report",
		meta: {
			menuType: "folder",
			text: "客户报表",
			icon: "IconSetting",
		},
		props: {
			default: false,
		},
		children: [],
		instances: {
			default: null,
		},
		leaveGuards: {},
		updateGuards: {},
		enterCallbacks: {},
		components: {
			default: {
				__name: "index",
				__hmrId: "e6cc6f32",
				__scopeId: "data-v-e6cc6f32",
				__file: "D:/code/01s/202502-10wms/01s-10wms/wms-frontend/src/views/customer-report/index.vue",
			},
		},
	},
	{
		path: "/daily-check",
		name: "daily-check",
		meta: {
			menuType: "folder",
			text: "每日检查",
			icon: "IconSetting",
		},
		props: {
			default: false,
		},
		children: [],
		instances: {
			default: null,
		},
		leaveGuards: {},
		updateGuards: {},
		enterCallbacks: {},
		components: {
			default: {
				__name: "index",
				__hmrId: "11d0bd34",
				__scopeId: "data-v-11d0bd34",
				__file: "D:/code/01s/202502-10wms/01s-10wms/wms-frontend/src/views/daily-check/index.vue",
			},
		},
	},
	{
		path: "/home",
		name: "home",
		meta: {
			icon: "IconSetting",
			menuType: "page",
			text: "首页",
		},
		props: {
			default: false,
		},
		children: [],
		instances: {
			default: null,
		},
		leaveGuards: {},
		updateGuards: {},
		enterCallbacks: {},
		components: {
			default: {
				__name: "index",
				__hmrId: "b301384e",
				__scopeId: "data-v-b301384e",
				__file: "D:/code/01s/202502-10wms/01s-10wms/wms-frontend/src/views/index.vue",
			},
		},
	},
	{
		path: "/sample",
		name: "sample",
		meta: {
			menuType: "folder",
			isSample: true,
			text: "自测组件-演示页面",
			icon: "IconSetting",
		},
		props: {
			default: false,
		},
		children: [],
		instances: {},
		leaveGuards: {},
		updateGuards: {},
		enterCallbacks: {},
		components: {},
	},
];

test("将静态路由转换为侧边栏数组", () => {
	const resMenus = useRouterToMenuItem({
		// @ts-ignore
		routes: routes_v2,
	});

	console.log(` 检查最终生成的菜单 `, resMenus);
});
