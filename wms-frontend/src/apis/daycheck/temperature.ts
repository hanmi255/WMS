/**
 * 温度信息录入对象
 * @see https://app.apifox.com/link/project/5901227/apis/api-264076098
 */
export interface TemperatureAdd {
	/**
	 * 备注
	 */
	wenduBz?: string;
	/**
	 * 采集时间
	 */
	wenduCjsj?: Date;
	/**
	 * 温度地点
	 */
	wenduDd?: string;
	/**
	 * 温度摄氏度
	 */
	wenduZhi?: number;
}

/**
 * 录入温度接口
 * @see https://app.apifox.com/link/project/5901227/apis/api-264076098
 */
export function daycheckTemperatureAdd() {
	return useRequest<string, ParamsBodyKey, TemperatureAdd>({
		httpParamWay: "body",
		config: {
			url: "/daycheck/temperature/add",
			method: "POST",
			data: {},
		},
	});
}

/**
 * 查询温度信息详情接口 查询对象
 * @see https://app.apifox.com/link/project/5901227/apis/api-264076100
 */
export interface DaycheckTemperatureDetailDto {
	/**
	 * 备注
	 */
	wenduBz?: string;
	/**
	 * 采集时间
	 */
	wenduCjsj?: Date;
	/**
	 * 温度地点
	 */
	wenduDd?: string;
	/**
	 * 温度id
	 */
	wenduId?: string;
	/**
	 * 温度摄氏度
	 */
	wenduZhi?: number;
}

/**
 * 查询温度信息详情接口
 * @see https://app.apifox.com/link/project/5901227/apis/api-264076100
 */
export function daycheckTemperatureDetail() {
	// TODO: 返回值类型不正确。等待后端处理
	return useRequest<string>({
		httpParamWay: "query",
		config: {
			url: "/daycheck/temperature/detail",
			method: "get",
			data: {},
		},
	});
}
