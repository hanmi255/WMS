import AutoImport from "unplugin-auto-import/vite";
import { VueRouterAutoImports } from "unplugin-vue-router";
import { ElementPlusResolver } from "unplugin-vue-components/resolvers";

export default AutoImport({
	imports: [
		VueRouterAutoImports,
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

		// 导入二次封装时使用的vueuse类型
		{
			from: "@ruan-cat/utils/vueuse",
			imports: [
				"KeyHelper",
				"UseAxiosOptions",
				"UseAxiosWrapperParams",
				"KeyAxiosRequestConfig",
				"RemoveUrlMethod",
				"CreateAxiosRequestConfig",
			],
			type: true,
		},

		// import { RequiredPick, PartialPick } from "type-plus";
		{
			from: "type-plus",
			imports: ["RequiredPick", "PartialPick"],
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
	resolvers: [ElementPlusResolver()],
});
