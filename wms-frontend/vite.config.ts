import { dirname, resolve } from "node:path";
import { fileURLToPath, URL } from "node:url";
import * as fs from "node:fs";

import { type ConfigEnv, defineConfig, loadEnv } from "vite";
import vue from "@vitejs/plugin-vue";
import AutoImport from "./src/plugins/unplugin-auto-import/index.ts";
import Components from "./src/plugins/unplugin-vue-components/index.ts";
import tsAlias from "./src/plugins/vite-plugin-ts-alias/index.ts";
import Icons from "unplugin-icons/vite";

import { createHtmlPlugin } from "vite-plugin-html";
import vueDevTools from "vite-plugin-vue-devtools";
import VueRouter from "unplugin-vue-router/vite";
import MetaLayouts from "vite-plugin-vue-meta-layouts";

import { getRouteName } from "./src/plugins/unplugin-vue-router.ts";
import autoImport from "./src/plugins/vite-plugin-autogeneration-import-file.ts";

/**
 * 用全量导入的方式 获取类型
 * 这些类型不能写成export导入的形式，会导致全局类型声明失效
 *
 * 也可以等效地用 三斜线表达式 实现全量导入
 * <reference types="./types/env.shim.d.ts" />
 */
import "./types/env.shim.d.ts";

// https://vitejs.dev/config/
export default defineConfig(({ mode }) => {
	/**
	 * 根据当前工作目录中的 `mode` 加载 .env 文件
	 * @deprecated
	 * 不推荐 环境变量的类型声明文件 现在包含了vite的客户端拓展
	 *
	 * 客户端的拓展类型 包含一个索引类型
	 *
	 * 故无法准确推断key值的类型了
	 *
	 * 该函数效果不佳 故不推荐使用
	 */
	const getViteEnv = (mode: ConfigEnv["mode"], target: keyof ImportMetaEnv) => {
		return loadEnv(mode, process.cwd())[target];
	};

	// 提供类型声明 便于得到使用提示
	const env = loadEnv(mode, process.cwd()) as unknown as ImportMetaEnv;
	const VITE_proxy_prefix = env.VITE_proxy_prefix;
	const VITE_base_url = env.VITE_base_url;
	const VITE_app_port = env.VITE_app_port;
	const VITE_API_URL = env.VITE_API_URL;

	return {
		server: {
			open: true,
			host: "0.0.0.0",
			port: 3000,
			// FIXME: 该配置导致了类型不兼容 需要研究是不是vite版本导致类型声明对不上
			// https: false,
			proxy: {
				"/api": {
					changeOrigin: true,
					target: "http://8.140.208.103:10001", // 网关
					rewrite: (path) => path.replace(/^\/api/, ""),

					//TODO[TEST_CODE]:使用Apifox云MOCK
					// target: "https://apifoxmock.com/m1/5579661-5257590-default",
					// rewrite: (path) => path.replace(/^\/api/, ""),
				},
				"/captcha": {
					changeOrigin: true,
					target: "http://8.140.208.103:10001",
					rewrite: (path) => path.replace(/^\/captcha/, ""),
				},
			},
		},

		build: {
			assetsDir: "static",
			chunkSizeWarningLimit: 1000,
			rollupOptions: {
				output: {
					manualChunks(id) {
						if (id.includes("node_modules")) {
							const regex = /.pnpm\/(.*?)\//;
							const ids = id.toString().split("node_modules/");
							const targetId = ids[1];
							const chunkNames = targetId.split("/");
							// 如果等于pnpm，说明是pnpm的包，需要取第二个
							if (chunkNames[0] === ".pnpm") {
								return chunkNames[1];
							} else {
								return chunkNames[0];
							}
						}
					},
				},

				// 排除掉全部的 sample 案例页面
				external: new RegExp("(views/sample/.*)"),
			},
		},

		plugins: [
			/**
			 * 类型化路由插件
			 * @description
			 * 其定义位置必须在 `@vitejs/plugin-vue` 插件之前。
			 *
			 * @see https://uvr.esm.is/introduction.html#installation
			 */
			VueRouter({
				dts: "./types/typed-router.d.ts",
				routesFolder: [
					{
						/**
						 * 在我们项目中，页面放在 views 文件夹下。
						 * 文档建议是写在pages内
						 * src: "src/pages",
						 */
						src: "src/views",
						exclude: [
							...[
								// 全部的components文件夹都不需要生成路由
								"**/components",
								// status菜单栏下面的全部页面 不生成自动路由
								"src/views/status/**",
							],
							/**
							 * 自动路由组件的忽略配置
							 * 如果是生产环境模式，就排除掉多余的案例组件
							 */
							...(mode === "production" ? ["src/views/sample/**"] : []),
						],

						// 下面的配置暂时不使用
						// override globals
						// exclude: (excluded) => excluded,
						// filePatterns: (filePatterns) => filePatterns,
						// extensions: (extensions) => extensions,
					},
				],
				getRouteName,
				// 该配置被覆盖掉了 故迁移到上面的配置中
				// exclude: mode === "production" ? ["src/views/sample/**"] : [],
			}),

			vue(),

			/** @see https://github.com/dishait/vite-plugin-vue-meta-layouts/blob/main/README_EN.md#config */
			MetaLayouts(),

			// 自动生成类型声明文件插件
			autoImport,

			// 自动导入插件
			AutoImport,

			// 自动导入vue组件的插件
			Components,

			Icons({
				autoInstall: true,
			}),

			/**
			 * 开发调试插件
			 * @description
			 * vueDevTools 必须在 createHtmlPlugin 的前面导入
			 *
			 * @see https://github.com/vuejs/devtools-next/issues/278#issuecomment-2021745201
			 */
			vueDevTools(),

			createHtmlPlugin({
				inject: {
					data: {
						title: getViteEnv(mode, "VITE_APP_TITLE"),
					},
				},
			}),

			tsAlias,
		],
	};
});
