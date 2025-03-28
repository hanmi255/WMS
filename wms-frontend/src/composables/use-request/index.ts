import qs from "qs";
import { merge, isNil } from "lodash-es";
import type { AxiosRequestConfig } from "axios";
import type { PartialPick } from "type-plus";

import type { UseAxiosWrapperParams, KeyAxiosRequestConfig } from "@ruan-cat/utils/vueuse";
import type { UseAxiosOptionsBase } from "@vueuse/integrations/useAxios";
import { useAxiosWrapper } from "@ruan-cat/utils/vueuse";

import { axiosInstance } from "./createAxiosInstance.ts";
import type { AxiosRequestConfigBaseKey } from "./tools.ts";

export * from "./tools.ts";

export type ParamsPathKey = AxiosRequestConfigBaseKey | "url";
export type ParamsQueryKey = AxiosRequestConfigBaseKey | "data";
export type ParamsBodyKey = AxiosRequestConfigBaseKey | "data";

type UseAxiosWrapperUseKey<T extends HttpParamWay, K extends KeyAxiosRequestConfig> =
	//
	T extends HttpParamWay ? Exclude<K, AxiosRequestConfigBaseKey> : never;

interface _Params<K extends KeyAxiosRequestConfig, T = any, D = any>
	extends UseAxiosWrapperParams<K, T, UseAxiosOptionsBase<JsonVO<T>>, D> {
	httpParamWay: HttpParamWay;
	upType?: UpType;
}

/** 建议封装接口请求函数不传递 useAxios 的 instance 和 options 参数 */
type Params<K extends KeyAxiosRequestConfig, T = any, D = any> = PartialPick<_Params<K, T, D>, "instance" | "options">;

/**
 * 项目内用的接口请求
 * @description
 * @version 2
 */
export function useRequest<
	K extends KeyAxiosRequestConfig,
	T = any,
	D = any,
	HttpParamWayTemp extends HttpParamWay = Params<K>["httpParamWay"],
>(
	params: Params<
		//
		UseAxiosWrapperUseKey<HttpParamWayTemp, K>,
		T,
		D
	>,
) {
	const {
		config,
		options = createDefaultUseAxiosOptions(),
		instance = axiosInstance,
		httpParamWay,
		upType,
		url,
	} = params;
	setHeaders(config, upType);
	setDefaultUseAxiosOptions(options);
	setDataByHttpParamWay({
		httpParamWay,
		config,
	});
	return useAxiosWrapper<
		//
		UseAxiosWrapperUseKey<HttpParamWayTemp, K>,
		JsonVO<T>,
		UseAxiosOptionsBase<JsonVO<T>>,
		D
	>({ config, instance, options, url });
}
