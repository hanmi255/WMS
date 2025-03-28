// @ts-check

/**
 * 其他范围配置
 * @description
 * 该配置是为了提供更多的范围配置，以便于更好的管理提交范围。
 *
 * 这里罗列一些高频更改配置的文件，并定位为专门的提交范围。
 */
const otherScopesConfigs = [
	{
		code: "config",
		value: "config",
		desc: "各种配置文件",
	},
	{
		code: "turbo",
		value: "turbo",
		desc: "任务调度器",
	},
	{
		code: "root",
		value: "root",
		desc: "根目录",
	},
	{
		code: "package.json",
		value: "package.json",
		desc: "包配置",
	},
	{
		code: "vite.config.js/ts",
		value: "vite",
		desc: "vite打包工具配置",
	},
	{
		code: "vitepress",
		value: "文档配置",
		desc: "vitepress文档工具配置",
	},
	{
		code: "commitlint.config.cjs",
		value: "commitlint",
		desc: "cz配置，即git提交工具的配置",
	},
	{
		code: "tsconfig",
		value: "tsc",
		desc: "typescript项目配置",
	},
	{
		code: "router",
		value: "router",
		desc: "路由配置",
	},
	{
		code: "vscode/settings.json",
		value: "vsc",
		desc: "vscode配置",
	},
];

/**
 * 业务名称分类 由组长对业务名称划分，并提供英文命名规范
 *
 * 暂时不考虑用 i18n 来配置。
 *
 * 暂时不考虑拆分移植该配置。
 */
const businessScopesConfigs = [
	{
		code: "dialog-promise",
		value: "命令式弹框",
		desc: "命令式弹框",
	},

	{
		code: "table",
		value: "表格组件",
		desc: "简单表格组件",
	},

	{
		code: "dinamic-table-form",
		value: "动态表格样式表单",
		desc: "动态表格样式表单，可以动态增删表格行的表单",
	},

	{
		code: "base-form",
		value: "通用基础表单",
		desc: "base-form，通用基础表单，本项目内常用的，基础的表单组件。",
	},

	{
		code: "daily-check",
		value: "每日检查",
		desc: "每日检查",
	},
];

const scopesConfigs = [...otherScopesConfigs, ...businessScopesConfigs];

/** @type {import("cz-git").ScopesType} */
const userScopes = scopesConfigs.map((conf) => {
	return {
		name: `${conf.code} | ${conf.desc}`,
		value: conf.value,
	};
});

module.exports = require("@ruan-cat/commitlint-config").getUserConfig(userScopes);
