// j4组-计量单位-目录下的请求方法
import Request from "../request";

// 定义一个功能模块基础url
const currBaseUrl = "/measurementunit";

/**
 * 参数修改接口
 * @param data 数据
 * @param success 成功回调
 * @param fail 失败回调
 */

/**
 * 获取参数类型列表（条件+分页）
 */
export const listMeasurementUnit = async (data, success, fail) => {
	/** 
	success({
		pageIndex: 1,
		pageSize: 10,
		pages: 100,
		rows: [
			{
				economy_code: "1",
				economy_name: "宏远科技有限公司",
				english_name: "Hogan Technology Co., Ltd.",
			},
			{
				economy_code: "2",
				economy_name: "蓝天贸易公司",
				english_name: "Blue Sky Trading Company",
			},
			{
				economy_code: "3",
				economy_name: "华瑞建筑工程公司",
				english_name: "Haru Construction Engineering Company",
			},
		],
		total: 100000,
	});
	*/
	try {
		// 发送请求
		const res = await Request.requestForm(Request.GET, currBaseUrl + "/getunitlist", data);
		// 处理结果
		if (res.data) {
			// 执行成功回调
			success(res.data);
			return;
		}
		// 处理失败
		fail();
	} catch (err) {
		// 打印错误信息
		console.warn(err);
		// 执行失败回调
		fail();
	}
};

/**
 * 录入参数类型
 */
export const addMeasurementUnit = async (data, success, fail) => {
	try {
		// 发送请求
		const res = await Request.requestJson(Request.POST, currBaseUrl + "/insertunit", data);
		// 处理结果
		if (res.data) {
			// 执行成功回调
			success(res.data);
			return;
		}
		// 处理失败
		fail();
	} catch (err) {
		// 打印错误信息
		console.warn(err);
		// 执行失败回调
		fail();
	}
};

/**
 * 修改参数类型
 */
export const updateMeasurementUnit = async (data, success, fail) => {
	try {
		// 发送请求
		const res = await Request.requestJson(Request.POST, currBaseUrl + "/updateunit", data);
		// 处理结果
		if (res.data) {
			// 执行成功回调
			success(res.data);
			return;
		}
		// 处理失败
		fail();
	} catch (err) {
		// 打印错误信息
		console.warn(err);
		// 执行失败回调
		fail();
	}
};

/**
 * 删除参数类型（支持批量删除）
 */
export const deleteMeasurementUnit = async (data, success, fail) => {
	try {
		// 发送请求
		const res = await Request.requestJson(Request.DELETE, currBaseUrl + "/deleteunit", data);
		// 处理结果
		if (res.data) {
			// 执行成功回调
			success(res.data);
			return;
		}
		// 处理失败
		fail();
	} catch (err) {
		// 打印错误信息
		console.warn(err);
		// 执行失败回调
		fail();
	}
};

/**
 * 导出参数类型
 */
export const exportMeasurementUnit = async (data, success, fail) => {
	try {
		// 发送请求
		const res = await Request.requestForm(Request.GET, currBaseUrl + "expo", data);
		// 处理结果
		if (res.data) {
			// 执行成功回调
			success(res.data);
			return;
		}
		// 处理失败
		fail();
	} catch (err) {
		// 打印错误信息
		console.warn(err);
		// 执行失败回调
		fail();
	}
};

/**
 * 导入参数类型
 */
export const importMeasurementUnit = async (data, success, fail) => {
	try {
		// 发送请求
		const res = await Request.requestForm(Request.POST, currBaseUrl + "import", data);
		// 处理结果
		if (res.data) {
			// 执行成功回调
			success(res.data);
			return;
		}
		// 处理失败
		fail();
	} catch (err) {
		// 打印错误信息
		console.warn(err);
		// 执行失败回调
		fail();
	}
};
