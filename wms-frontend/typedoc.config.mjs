// @ts-check

/**
 * @type { import('typedoc').TypeDocOptions &
 * import('typedoc-plugin-markdown').PluginOptions &
 * import('typedoc-plugin-frontmatter').PluginOptions
 * }
 *
 * 允许使用 `typedoc.config.mjs` 作为配置文件
 * @see https://typedoc.org/documents/Options.Configuration.html#options
 *
 * 类型声明配置
 * @see https://typedoc-plugin-markdown.org/docs/typedoc-usage#javascript-files
 */
// @ts-ignore
const config = {
	name: "本地化示例",

	entryPointStrategy: "Resolve",

	// 指定项目的入口点
	entryPoints: [
		// "types/auto-imports.d.ts",
		// 全部的 组合式工具
		// "src/composables/**/*.ts",
		// 全部的 pinia状态存储
		// "src/stores/**/*.ts",
		// // 全部的 类型
		"src/types/**/*.ts",
		// // 全部的 api接口
		// "src/apis/**/*.ts",
	],

	// 排除不需要生成文档的目录
	// exclude: ["node_modules", "libs", "src/routers/index.ts"],
	// exclude: "**/+()",
	// externalPattern: ["**/+(routers|components)"],

	plugin: [
		"typedoc-plugin-markdown",
		// "typedoc-plugin-frontmatter"
	],
	// 指定输出目录
	out: "./src/docs/typedoc-md",

	// 指定 TypeScript 配置文件
	tsconfig: "./tsconfig.typedoc.json",
	// gitRevision: "main",
	lang: "zh",
	excludeExternals: false,
	excludePrivate: true,
	excludeProtected: true,
	// 不需要专门移动readme文件
	readme: "none",
	// "readme": "readme.md",
	hidePageHeader: true,
	hideBreadcrumbs: true,
	enumMembersFormat: "table",
	parametersFormat: "table",
	propertiesFormat: "table",
	typeDeclarationFormat: "table",
	indexFormat: "table",
	useCodeBlocks: true,
	expandObjects: true,

	validation: {
		notExported: false,
		notDocumented: false,
	},
	treatWarningsAsErrors: false,
	treatValidationWarningsAsErrors: false,

	/**
	 * 设置生成文件首页的信息
	 * @description
	 * 让生成出来的首页带有特定的排序值
	 *
	 * 配置语法：
	 * @see https://typedoc-plugin-markdown.org/plugins/frontmatter/options#readmefrontmatter
	 *
	 * 配置参数语法：
	 * @see https://theme-hope.vuejs.press/zh/config/frontmatter/layout.html#dir
	 * @see https://theme-hope.vuejs.press/zh/config/frontmatter/layout.html#order
	 */
	// readmeFrontmatter: {
	// 	order: 90,
	// 	dir: {
	// 		order: 90,
	// 	},
	// },
};

export default config;
