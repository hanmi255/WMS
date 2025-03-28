import { setupLayouts, createGetRoutes } from "virtual:meta-layouts";
import { routes, handleHotUpdate } from "vue-router/auto-routes";
import { createRouter, createWebHistory } from "vue-router/auto";

import { storeToRefs } from "pinia";
import { ElMessage } from "element-plus";
import { useUserStore } from "stores/user";

import { isConditionsSome } from "@ruan-cat/utils";

/**
 * 菜单类型
 * @description
 * 每一个页面都必须配置一个菜单类型
 * 告诉菜单自己属于什么类型？
 *
 * - 具体的页面
 * - 目录文件夹
 */
export type MenuType =
	// 页面类型
	| "page"
	// 文件夹类型 即菜单侧边栏的折叠目录
	| "folder"
	// 忽略 这个页面拥有路由，但不会在菜单中显示
	| "ignore";

/**
 * 拓展路由元信息
 * @description
 * 从菜单项复制粘贴部分可用的属性
 *
 * @see https://router.vuejs.org/zh/guide/advanced/meta#TypeScript
 */
declare module "vue-router" {
	interface RouteMeta {
		/** 菜单类型 */
		menuType: MenuType;

		/**
		 * 侧边栏标题
		 * @description
		 * 必须配置的侧边栏标题
		 */
		text: string;

		/**
		 * 侧边栏显示用的icon标签
		 * @description
		 * TODO: 将icon显示的取值列表 提取出来
		 */
		icon: string;

		// 配置侧边栏时 不需要配置子项
		// children?: MenuItem[];

		/**
		 * 是否是案例演示页面？
		 * @description
		 * 对案例演示页面做出专门的配置
		 */
		isSample?: boolean;

		/**
		 * 侧边栏菜单排序
		 * @description
		 * 默认按照降序排序
		 *
		 * 数值越小的，在菜单的位置越靠前
		 *
		 * 数值越大的，在菜单的位置越靠后
		 */
		order?: number;
	}
}

/**
 * 项目原本就有的路由
 * @description
 * 这里预设的都是静态路由
 */
const originRoutes = [
	// 警告 这些路由配置已经重新配置了 被分散配置到各个单独的页面组件内使用了。
	// {
	// 	path: "/:pathMatch(.*)*",
	// 	name: "NotFound",
	// 	component: () => import("../views/status/404.vue"),
	// },
	// {
	// 	path: "/forbidden",
	// 	name: "Forbidden",
	// 	component: () => import("../views/status/403.vue"),
	// },
	// {
	// 	path: "/error",
	// 	name: "Error",
	// 	component: () => import("../views/status/500.vue"),
	// },
];

// 警告 不再需要读取主模块路由了 用自动路由的方式实现完毕
// // 读取main模块路由
// const mainRouter = import.meta.glob("./main/index.js", { eager: true });
// for (const path in mainRouter) {
// 	// @ts-ignore
// 	originRoutes.push(...mainRouter[path].default);
// }

// TODO[TEST_CODE]:读取示例演示模块路由
// TODO: 在自动化路由读取函数内 增加忽略匹配 忽略掉全部的 sample 菜单
if (import.meta.env.DEV) {
	// 手动地移除掉示例模块的路由 不再加载
	// const sampleRouter = import.meta.glob("./sample/index.js", { eager: true });
	// for (const path in sampleRouter) {
	// 	// @ts-ignore
	// 	originRoutes.push(...sampleRouter[path].default);
	// }
}

// 定义一个路由对象
const router = createRouter({
	history: createWebHistory(import.meta.env.BASE_URL),
	routes: setupLayouts(routes),
});

/**
 * 获取路由
 * @description
 * 由于布局系统需要在最外层嵌套一层布局路由
 *
 * 因此在获取路由表时可能会造成混淆
 *
 * 此时可以使用辅助功能
 * @see https://github.com/dishait/vite-plugin-vue-meta-layouts/blob/main/README_EN.md#note
 */
export const getRoutes = createGetRoutes(router);

// 添加一个路由的全局前置守卫
router.beforeEach(async function (to, from, next) {
	// 判断是否是登录页面
	if (
		isConditionsSome([
			() => to.name === "Login",
			() => to.name === "NotFound",
			() => to.name === "Forbidden",
			() => to.name === "Error",
		])
	) {
		next();
		return;
	}

	// TODO[TEST_CODE]:放行示例模块访问
	if (import.meta.env.DEV) {
		if (to.path.indexOf("sample") !== -1) {
			next();
			return;
		}
	}

	// 判断本地是否记录token值
	const store = useUserStore();
	const { isLoaded: _isLoaded, getToken } = storeToRefs(store);
	const token = getToken.value;

	// 如果有token
	if (token) {
		// 判断是否已经加载数据
		const isLoaded = _isLoaded.value;
		// 如果没有加载
		if (!isLoaded) {
			// 加载用户信息
			await store.loadUser();
			// 加载菜单资源
			await store.loadMenus();
			// 设置加载完毕
			store.setLoaded(true);
		}
		next();
	}
	// 如果没有token值，直接进入登录
	else {
		next({ name: "Login" });
		ElMessage.warning("在未登录时，禁止访问其他页面！");
	}
});

// This will update routes at runtime without reloading the page
if (import.meta.hot) {
	console.log("我正在热更新路由表！");
	handleHotUpdate(router);
}

export default router;
