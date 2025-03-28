const routes = [
	{
		path: "/sample",
		name: "Sample",
		redirect: { path: "/sample/file" },
		component: () => import("@/views/sample/SampleView.vue"),
		children: [
			{
				path: "/sample/file",
				component: () => import("@/views/sample/file/FileUpload.vue"),
			},
			{
				path: "/sample/excel",
				component: () => import("@/views/sample/excel/Excel.vue"),
			},
			{
				path: "/sample/print",
				component: () => import("@/views/sample/print/Print.vue"),
			},
			{
				path: "/sample/editor",
				component: () => import("@/views/sample/editor/Editor.vue"),
			},
			{
				path: "/sample/pdfobject",
				component: () => import("@/views/sample/pdfobject/PdfObject.vue"),
			},
			{
				path: "/sample/echarts",
				component: () => import("@/views/sample/echarts/Echarts.vue"),
			},
			{
				path: "/sample/formcreate",
				component: () => import("@/views/sample/formcreate/FormCreate.vue"),
			},
			{
				path: "/sample/flow",
				component: () => import("@/views/sample/flow/Flow.vue"),
			},
			{
				path: "/sample/dinamicForm",
				component: () => import("@/views/sample/dinamicForm/index.vue"),
			},
		],
	},
];

export default routes;
