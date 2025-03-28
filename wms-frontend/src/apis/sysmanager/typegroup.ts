/**
 * 删除字典分类
 * @description
 * ParamsPathKey
 * @see https://app.apifox.com/link/project/5901227/apis/api-266276392
 */
export function sysmanagerTypegroupRemove<T = string>(options: UseAxiosOptionsJsonVO<T>) {
	return useRequest<ParamsPathKey, T>({
		url: "/sysmanager/typegroup/remove/{id}",
		options,
		httpParamWay: "path",
		config: {
			url: "/sysmanager/typegroup/remove/{id}",
			method: "delete",
		},
	});
}
