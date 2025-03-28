import { createI18n } from "vue-i18n";

// 语言包
const messages = {
	zh: {
		login: {
			title: "零壹仓储管理系统",
			username: "请输入用户名",
			password: "请输入密码",
			rememberMe: "记住用户名",
			loginButton: "登录",
			captchaEnabled: "启用验证码",
			captchaDisabled: "关闭验证码",
		},
	},
	en: {
		login: {
			title: "ZeroOne Warehouse Management System",
			username: "Please enter username",
			password: "Please enter password",
			rememberMe: "Remember username",
			loginButton: "Login",
			captchaEnabled: "Enable Captcha",
			captchaDisabled: "Disable Captcha",
		},
	},
};

// 创建 i18n 实例
const i18n = createI18n({
	locale: "zh", // 默认语言
	fallbackLocale: "en", // 回退语言
	messages,
});

export default i18n;
