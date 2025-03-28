import axios from "axios";
import { AxiosError } from "axios";
import qs from "qs";

import type { Router } from "vue-router";
import type { AxiosInstance, AxiosRequestConfig } from "axios";
import { ElMessage } from "element-plus";

import { HttpCode } from "./tools";

/**
 * 创建axios实例
 * @description
 * 从商城项目内获取得来
 *
 * @see https://apifox.com/apidoc/shared-c05cb8d7-e591-4d9c-aff8-11065a0ec1de/api-67132167
 */
export function createAxiosInstance() {
	const instance = axios.create({
		// TODO: 从环境变量内获取请求地址
		baseURL: "https://apifoxmock.com/m1/5901227-5588101-default",

		/** 请求超时时间 */
		timeout: 10000,

		/** 允许跨域 */
		withCredentials: true,

		/**
		 * 在 vitest 内做接口请求时，会使用node环境内的环境变量
		 * 比如 HTTPS_PROXY 变量。这里设置为false，不使用代理。
		 */
		proxy: false,
	});

	// 使用qs序列化参数params参数
	instance.defaults.paramsSerializer = function (params) {
		return qs.stringify(params);
	};

	return instance;
}

/**
 * 接口请求时用的请求实例
 * @description
 * 目前作为专用于 useAxios 的接口请求实例
 */
export const axiosInstance = createAxiosInstance();

/**
 * 注册 useAxios 版本的 axios 实例对象
 * @description
 * 本函数主要实现拦截器的配置
 */
export function registerAxiosInstanceWithUseAxiosHook(router: Router, axiosInstance: AxiosInstance) {
	// 请求拦截处理
	axiosInstance.interceptors.request.use(
		function onFulfilled(config) {
			// 提交的时候携带登录凭证
			let store = useUserStore();
			// @ts-ignore
			let token = store.getToken;

			/** 临时token */
			const tempToken = import.meta.env.VITE_temp_token;

			/** 如果存在有意义的临时token 就赋值 */
			if (tempToken) {
				token = tempToken;
			}

			if (token) {
				config.headers["Authorization"] = `Bearer ${token}`;
			}

			/** 处理反向代理的虚拟地址问题 */
			function _handleBaseUrl(config: AxiosRequestConfig) {
				/**
				 * 请求前缀配置
				 * @description
				 * 后端的接口请求中 其生产环境的是特殊的
				 * 有特定的虚拟前缀 故需要在请求的时候特殊处理
				 */
				const cfg = [
					{
						regExps: ["/app", "/columnattribute"],
						target: "/j3-cms-base",
					},
					{
						regExps: ["/sortallocation", "/dataconfig", "/form", "/resourcefile"],
						target: "/j3-cms-setting",
					},
				];

				for (const item of cfg) {
					for (const regExp of item.regExps) {
						if (new RegExp("^" + regExp).test(<string>config.url)) {
							/** 请求前缀 */
							// let prefix = "";
							// 如果是开发环境 这需要增加反向代理的前缀
							// 开发环境需要反向代理
							// 在生产环境，也需要nginx提供的反向代理
							// if (import.meta.env.MODE === "development") {
							// 	prefix = import.meta.env.VITE_proxy_prefix;
							// } else {
							// 	prefix = "";
							// }
							// config.baseURL = `${prefix}${item.target}`;

							// 增加虚拟前缀
							config.baseURL = `${import.meta.env.VITE_proxy_prefix}${item.target}`;
							break;
						}
					}
				}
			}
			// _handleBaseUrl(config);

			return config;
		},

		function onRejected(error) {
			return Promise.reject(error);
		},
	);

	// 响应拦截处理
	axiosInstance.interceptors.response.use(
		async function onFulfilled(response) {
			/**
			 * 不解包的原始数据
			 * @description
			 * useAxios 会默认解包一层数据 所以本回调函数在任何情况下，均不应该默认解包一次
			 *
			 * 在成功的回调内 不做解包数据
			 *
			 * 在业务失败的回调内 解包数据
			 */
			const _nowrapData = response;

			// HTTP响应状态码正常
			if (response.status === 200) {
				if ("code" in response.data) {
					let store = useUserStore();
					const data = response.data;

					if (data.code === HttpCode.SUCCESS) {
						// 将数据继续传递下去
						return Promise.resolve(_nowrapData);
					}

					if (data.code === HttpCode.FORBIDDEN) {
						// 权限不足
						ElMessage.error("权限不够，请联系管理员");
						// 将数据继续传递下去
						return Promise.reject(_nowrapData.data);
					}

					if (data.code === HttpCode.UNAUTHORIZED) {
						// 判断是否是超时
						if (typeof data.data === "string" && data.data.indexOf("Jwt expired at") >= 0) {
							// 刷新凭证
							// @ts-ignore
							await store.reloadToken();
							// 设置为未加载
							// @ts-ignore
							store.setLoaded(false);
							// 跳转到主页
							router.push("/home");
						} else {
							// 没有登录或登录已失效
							router.push("/");
							// 重置数据
							// @ts-ignore
							store.resetSaveData();
						}
						// 将数据继续传递下去
						return Promise.reject(_nowrapData.data);
					}

					if (data.code === HttpCode.NOT_FOUND) {
						ElMessage.warning(data.message || "404访问页面不存在");
						return Promise.reject(_nowrapData.data);
					}

					if (
						isConditionsSome([
							() => data.code === HttpCode.CONTENT_TYPE_ERR,
							() => data.code === HttpCode.PARAMS_INVALID,
						])
					) {
						ElMessage.warning(data.message || "请求参数或请求头错误");
						return Promise.reject(_nowrapData.data);
					}

					// 显示操作失败提示
					// ElMessage.error(data.message || '操作失败!!!')
					return Promise.reject(_nowrapData.data);
				}

				return Promise.reject(_nowrapData.data);
			}

			// 接口404的情况
			else if (response.status === 404) {
				ElMessage.warning("404访问页面不存在");
				return Promise.reject(_nowrapData.data);
			}

			// 其他情况
			else {
				return Promise.reject(_nowrapData.data);
			}
		},

		function onRejected(error) {
			if (
				isConditionsSome([() => error.code === AxiosError.ECONNABORTED, () => error.code === AxiosError.ERR_NETWORK])
			) {
				ElMessage.error("连接服务器失败!!!");
			}

			return Promise.reject(error);
		},
	);
}

/**
 * 全局注册axios实例
 * @description
 * 模仿本项目其他插件的配置 在 main.ts 内调用
 * @example installAxiosWithVueUse(router, axiosInstance)
 */
export const installAxiosWithVueUse = registerAxiosInstanceWithUseAxiosHook;
