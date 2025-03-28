import eslint from "@eslint/js";
import tseslint from "typescript-eslint";
import eslintPluginVue from "eslint-plugin-vue";
import globals from "globals";
import eslintPluginPrettierRecommended from "eslint-plugin-prettier/recommended";
import prettier from "eslint-config-prettier";

export default [
	{
		// Ignore files
		ignores: ["dist", "node_modules", "public", "src/components/verifition"],
	},
	//js 推荐规则
	eslint.configs.recommended,
	// ts 推荐规则
	...tseslint.configs.recommended,
	// vue 推荐规则
	...eslintPluginVue.configs["flat/recommended"],

	// javascript 规则
	{
		rules: {
			"no-console": "off",
			"no-debugger": "off",
			"no-alert": "off",
			"no-unused-vars": "off",
			"no-undef": "off",
			"no-unused-expressions": "off",
			"no-restricted-syntax": "off",
		},
	},

	//配置全局变量
	{
		languageOptions: {
			globals: {
				...globals.browser,
				//可以在这里追加一些其他自定义的全局变量
			},
		},
	},

	// vue 规则
	{
		files: ["**/*.vue"],
		languageOptions: {
			parserOptions: {
				parser: tseslint.parser,
				ecmaVersion: "latest",
				ecmaFeatures: {
					jsx: true,
				},
			},
		},
		rules: {
			//禁止在组件内部直接修改通过 props 传递进来的属性值
			"vue/no-mutating-props": ["error"],
			"vue/multi-word-component-names": "off",
			"vue/attribute-hyphenation": "off",
			"vue/attributes-order": "off",
		},
	},
	// ts 规则
	{
		files: ["**/*.{ts,vue}"],
		rules: {
			"@typescript-eslint/no-explicit-any": "off",
		},
	},
	// 会合并 prettier 的规则
	eslintPluginPrettierRecommended,
	// 禁用掉与 prettier 冲突的规则
	prettier,
];
