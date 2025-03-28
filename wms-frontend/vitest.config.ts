import { fileURLToPath } from "node:url";

import tsAlias from "vite-plugin-ts-alias";
import AutoImport from "unplugin-auto-import/vite";

import { mergeConfig, defineConfig, configDefaults } from "vitest/config";
import viteConfig from "./vite.config";

// 定义测试配置
const testConfig = defineConfig({
	test: {
		environment: "jsdom",
		exclude: [...configDefaults.exclude, "e2e/**"],
		root: fileURLToPath(new URL("./", import.meta.url)),
	},

	plugins: [
		AutoImport({
			imports: [
				// VueRouterAutoImports,
				"@vueuse/core",
				"vue",
				"pinia",
				{
					"@vueuse/integrations/useAxios": ["useAxios"],
				},
				{
					"@ruan-cat/utils": ["isConditionsEvery", "isConditionsSome"],
				},
				{
					from: "@ruan-cat/utils",
					imports: ["Prettify", "ToNumberLike"],
					type: true,
				},
				{
					"lodash-es": ["isUndefined", "isEmpty", "cloneDeep", "merge", "uniqueId"],
				},
			],
			ignore: ["vue-router"],
			dirs: [
				{
					glob: "src/**/*",
					types: true,
				},
			],
			dts: "./types/auto-imports.d.ts",
			// resolvers: [ElementPlusResolver()],
		}),

		tsAlias({
			/**
			 * tsconfig name, optional.
			 * @default 'tsconfig.json'
			 */
			tsConfigName: "tsconfig.app.json",
		}),
	],
});

// 导出合并后的配置
export default defineConfig(({ mode }) => {
	/**
	 * 暂不考虑从vite内获取配置 目前vite允许导入ts文件，而vitest却不允许
	 * @see https://cn.vitejs.dev/config/#configuring-vite
	 * 故目前vitest不导入vite配置。
	 */

	// @ts-ignore
	// return mergeConfig(testConfig, viteConfig({ mode }));
	return testConfig;
});
