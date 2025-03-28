const routes = [
	{
		path: "/home",
		name: "Home",
		component: () => import("@/views/index.vue"),
		// 不需要考虑重定向
		// redirect: { name: "Dashboard" },
		// children: [
		// 	{
		// 		path: "/dashboard",
		// 		name: "Dashboard",
		// 		component: () => import("@/views/dashboard/Dashboard.vue"),
		// 	},
		// ],
	},
];

// 读取子目录下面菜单设置为二级路由
const secondRouter = import.meta.glob("./**/index.js", { eager: true });
for (const path in secondRouter) {
	routes[0].children.push(...secondRouter[path].default);
}

export default routes;
