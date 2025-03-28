import installHttp from "@/plugins/http";
import http from "axios";
// TODO 测试的时候需要修改成对应的服务器地址，一般修改成网关服务器地址
http.defaults.baseURL = "https://apifoxmock.com/m1/5579661-5257590-default";
import { createApp } from "vue";
import { createPinia } from "pinia";

export function withSetup(composable) {
	let result;
	const app = createApp({
		setup() {
			if (composable) result = composable();
			return () => {};
		},
	});
	app.use(createPinia());
	app.mount(document.createElement("div"));

	// 设置axios中间件
	installHttp();

	// 返回结果与应用实例
	// 用来测试供给和组件卸载
	return [result, app];
}
