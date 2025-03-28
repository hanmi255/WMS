import type { Ref } from "vue";

import type { MenuItem } from "types/MenuItem";

import type { RouterOptions, RouteRecordRaw, RouteRecordNormalized } from "vue-router";

import { isEmpty, isUndefined, uniqueId, toNumber, cloneDeep, concat } from "lodash-es";
import { isConditionsEvery, isConditionsSome } from "@ruan-cat/utils";
import consola from "consola";

interface UseRouterToMenuItemParams {
	/**
	 * 路由
	 * @description
	 * 这里期望传递的是有自动化路由工具生成出来的 静态路由 数组
	 */
	// routes: RouterOptions["routes"];
	routes: RouteRecordNormalized[];

	/**
	 * 是否显示案例页面的菜单？
	 * @description
	 * 默认不显示案例页面的菜单
	 *
	 * 传递响应式的数据
	 * @default false
	 */
	isSampleMenu: Ref<boolean>;
}

interface RecursiveTraversalParams {
	// routes: RouterOptions["routes"];
	routes: RouteRecordNormalized[];

	/** 父级传递的path地址 */
	parentPaths: string[];
}

function pathAddPrefix(path: string) {
	let currentPath = path;
	if (currentPath[0] !== "/") {
		currentPath = `/${currentPath}`;
	}
	return currentPath;
}

function handleSetParentPaths(params: { parentPaths: string[]; path: string }) {
	const { parentPaths, path } = params;
	if (path === "") {
		return parentPaths;
	}
	return [...parentPaths, pathAddPrefix(path)];
}

const res: {
	path: string;
	name: string | undefined | symbol;
}[] = [];

/**
 * @private
 * @deprecated
 */
function recursiveTraversal(params: RecursiveTraversalParams) {
	const { routes, parentPaths } = params;

	routes.forEach((route) => {
		if (route.children) {
			// parentPaths.push(route.path);

			recursiveTraversal({
				// @ts-ignore
				routes: route.children,
				parentPaths: [...parentPaths, pathAddPrefix(route.path)],
			});
		} else {
			res.push({
				path: [...parentPaths, pathAddPrefix(route.path)].join(""),
				name: route.name,
			});
			// console.log(" route: ", , route.name);
		}
	});
}

/** 当前节点是否是叶子节点？ */
function isLeafNode(route: RouteRecordRaw) {
	const { meta } = route;

	return isConditionsEvery([
		// 当前节点不存在子项 不应该有任何有意义的数据
		() => isEmpty(route?.children),

		// 当前遍历的节点 是否具有meta配置信息？
		() => !isUndefined(meta),

		// 当前遍历的节点 isLayout 不存在，且不为true
		() => meta?.isLayout !== true,
	]);
}

/** 当前节点 是否应该被跳过？ 直接开始下一层的递归 */
function isShouldJump(route: RouteRecordRaw) {
	/**
	 * 从路由数组内 获取路由
	 * 目前全部的路由数组内都是要有内容的 这是自动化路由决定的
	 */
	// console.warn(" 现在被检查的路由是： ", route);

	// 同时满足以下要求时， 该节点被跳过
	return isConditionsEvery([
		// 当前路由节点有子项
		() => !isUndefined(route?.children),

		// 数组长度是不是仅有1项？
		() => route?.children?.length === 1,

		// 且第一项的路由path是空字符串？
		() => route?.children?.[0].path === "",

		// 当前遍历的节点 有明确的 isLayout 配置。
		() => route.meta?.isLayout === true,
	]);
}

/** 当前节点是否和 sample 示例页面有关？ @deprecated 设计冗余 */
function isSamplePage(route: RouteRecordRaw) {
	return route.path.indexOf("sample") !== -1;
}

/** 当前项目是否是开发环境模式？ @deprecated 设计冗余 */
function isDevMode() {
	return import.meta.env.DEV;
}

interface DoChangeParams {
	/** 自动路由插件生成的全体路由数组 */
	routes: RouterOptions["routes"];

	/** 菜单数组 */
	menus: MenuItem[];

	/** 父级传递的path地址 */
	parentPaths: string[];
}

/**
 * 执行路由格式转换工作
 * @deprecated
 * 不再使用基于嵌套路由生成菜单的方式
 *
 * 因为使用布局插件 所以生成的路由结构信息是很混乱的，有很多脏数据，处理麻烦
 *
 * 新的布局插件提供了扁平化的函数来生成菜单 实现会更加清晰有效
 */
function doChange(params: DoChangeParams) {
	const { routes, parentPaths } = params;

	console.log(" 0 进入到新的一次递归 ", parentPaths);

	for (let i = 0; i < routes.length; i++) {
		const route = routes[i];
		const { meta } = route;

		// 1 判断当前节点是否应该被跳过？
		// 1.1 判断该节点是不是脏数据节点？ 是否应该直接跳过
		if (isShouldJump(route)) {
			console.info(` 1 当前节点将会直接进入到下一层递归 `, route, params.menus);

			// 跳过当前的路由信息遍历 直接进入到下一层
			doChange({
				//@ts-ignore 将当前节点的下一层路由信息 传递下去递归
				routes: route.children,
				// 本节点没有做任何菜单处理 将本层的菜单信息 传递下去
				menus: params.menus,
				parentPaths: handleSetParentPaths({ parentPaths, path: route.path }),
			});
			// 下面的内容不用看了 进入到下一轮循环
			continue;
		}

		// 2 当前节点是不是叶子节点？
		if (isLeafNode(route)) {
			console.warn(` 2 叶子节点 `, route, params.menus);

			/** 准备好基础的菜单信息 */
			const menuItem: MenuItem = {
				icon: <string>meta?.icon ?? "IconSetting",
				text: <string>meta?.text ?? "暂无菜单名称",
				// 从父级传递过来的path地址 拼接成可以执行的路由完整地址
				href: handleSetParentPaths({ parentPaths, path: route.path }).join(""),
				id: toNumber(uniqueId()) + 112,
			};

			// 存储菜单信息
			params.menus.push(menuItem);
			// 处理完叶子节点后，进入到下一次循环。
			continue;
		}

		// 3 当前节点是不是一半意义的普通节点？
		if (!isUndefined(route?.children)) {
			/** 带有子项的菜单信息 */
			const menuItemWithChildren: MenuItem = {
				icon: <string>meta?.icon ?? "IconSetting",
				text: <string>meta?.text ?? "暂无菜单名称",
				// 从父级传递过来的path地址 拼接成可以执行的路由完整地址
				href: handleSetParentPaths({ parentPaths, path: route.path }).join(""),
				id: toNumber(uniqueId()) + 112,
				children: [],
			};

			// 存储菜单信息
			params.menus.push(menuItemWithChildren);
			const last = params.menus.length - 1;

			console.warn(` 3 普通节点 `, route, params.menus);

			// 有子项数据 就递归下去处理
			doChange({
				routes: route.children,
				// @ts-ignore 这里的子项是存在的
				menus: params.menus[last].children,
				parentPaths: handleSetParentPaths({ parentPaths, path: route.path }),
			});
			continue;
		}

		console.error(` 错误警告： 按理说不应该到达此处，存在预期之外的脏数据： `, route);
	}
}

/**
 * 将自动路由的信息 转换成 菜单信息
 */
export function useRouterToMenuItem(params: UseRouterToMenuItemParams) {
	const { routes, isSampleMenu } = params;

	/**
	 * 当前路由是否有期望的 meta 数据？
	 * @description
	 * 绝大多数的页面会有meta配置的
	 *
	 * 不排除某些页面缺乏配置的情况 如果缺少配置 那么就要发出报错信息
	 */
	function hasMeta(route: RouteRecordNormalized) {
		const res = !isUndefined(route?.meta);
		if (!res) {
			consola.error(" 当前路由没有meta配置信息，是脏数据： ", route);
		}
		return res;
	}

	/** 将路由变成菜单文件夹 */
	function routeToMenuFolder(route: RouteRecordNormalized): MenuItem {
		return {
			icon: route.meta.icon,
			text: route.meta.text,
			id: toNumber(uniqueId()) + 112,
			children: [],
		};
	}

	/** 将路由变成菜单页面 */
	function routeToMenuPage(route: RouteRecordNormalized): MenuItem {
		return {
			icon: route.meta.icon,
			text: route.meta.text,
			id: toNumber(uniqueId()) + 112,
			href: route.path,
		};
	}

	/** 生成普通的菜单数组 */
	function createCommonMenus() {
		/** 可以被随时产出删减的路由数组 */
		const routesCandel = cloneDeep(routes);

		/**
		 * 菜单配置映射
		 * @description
		 * 以目录菜单为键值对
		 */
		const menusMap = new Map<string, MenuItem>();

		/**
		 * 1 先整理数据 删除掉全部不需要的路由
		 * 2 将目录菜单的配置提取出来 建立专门的菜单目录对象
		 *
		 * 不提供循环递增条件
		 */
		for (let i = 0; i < routesCandel.length; ) {
			const route = routesCandel[i];

			// 处理需要被直接删除掉不处理的路由
			if (
				isConditionsSome([
					// 当前路由没有配置 meta 信息
					() => !hasMeta(route),
					// 当前路由被忽略
					() => route.meta.menuType === "ignore",
					// 当前路由属于案例演示页面
					() => route.meta?.isSample === true,
				])
			) {
				// 将当前数组元素删除
				routesCandel.splice(i, 1);
				continue;
			}

			// 处理目录菜单的配置
			if (route.meta.menuType === "folder") {
				/**
				 * 用路由的地址来作为key
				 * 不用路由的name 应为有可能会配置自己独特的路由name
				 *
				 * 经过拆分后的数组 会有空字符串的元素
				 * 所以要过滤掉空字符串
				 *
				 * 使用第一个元素作为key
				 */
				const mapKey = route.path.split("/").filter(Boolean)[0];
				menusMap.set(mapKey as string, routeToMenuFolder(route));

				// 将当前数组元素删除
				routesCandel.splice(i, 1);
				// 处理完了就到下一个元素
				continue;
			}

			// 只有正常到了循环的最后一项 才允许递增
			i++;
		}

		/**
		 * 3 将页面加入到目录对象内
		 */
		for (let i = 0; i < routesCandel.length; ) {
			/** 当前路由 */
			const route = routesCandel[i];

			/**
			 * 当前路由的唯一识别key
			 * 一般来说是父级路由的名称
			 * 这里仅考虑两层的路由结构，没有考虑更深的目录结构
			 */
			const key = route.path.split("/").filter(Boolean)[0];
			if (
				isConditionsEvery([
					// 当前页面属于页面类型？
					() => route.meta.menuType === "page",
					// 该页面的父级目录是否存在？
					() => menusMap.has(key),
				])
			) {
				/** 父级菜单 */
				const parent = menusMap.get(key);

				// 排除掉类型约束为 undefined 的情况
				if (!isUndefined(parent)) {
					// 排除掉类型约束为 undefined 的情况
					if (!isUndefined(parent.children)) {
						// 将当前页面加入到父级目录内
						parent.children.push(routeToMenuPage(route));

						// 将当前数组元素删除
						routesCandel.splice(i, 1);
						// 处理完了就到下一个元素
						continue;
					}
				}
			} else {
				consola.warn(" 当前页面没有找到对应的父级目录，可能是脏数据： ", route);
			}

			/**
			 * 有某些页面没有对应的父级目录 直接显示到菜单页面上的
			 * 进入到下一层循环 对此不做任何处理
			 */
			i++;
		}

		/** 最终的菜单数组 */
		const menus = concat(
			// 将剩余的路由数组 全部变成菜单页面
			routesCandel.map((route) => {
				return routeToMenuPage(route);
			}),

			// 将菜单内容平铺出来
			[...menusMap.values()],
		);

		// TODO: 实现菜单的排序功能 根据特定的 order字段实现

		return menus;
	}

	/** 生成案例页面的菜单数组 */
	function createSampleMenus() {
		/** 可以被随时产出删减的路由数组 */
		const routesCandel = cloneDeep(routes);

		const resMenus = routesCandel
			.filter((route) => {
				return route.meta?.isSample === true;
			})
			.map((sampleRoute) => {
				return routeToMenuPage(sampleRoute);
			});

		// TODO: 实现菜单的排序功能 根据特定的 order字段实现

		return resMenus;
	}

	/** 普通的菜单数组 */
	const commonMenus = ref(createCommonMenus());

	/** 案例页面的菜单数组 */
	const sampleMenus = ref(createSampleMenus());

	/**
	 * 最终的菜单数组
	 * @description
	 * 根据参数给的值 动态给出不同的菜单
	 */
	const resMenus = computed(() => (isSampleMenu.value ? sampleMenus.value : commonMenus.value));

	return resMenus;
}
