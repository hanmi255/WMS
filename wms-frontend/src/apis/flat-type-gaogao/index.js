// j4组-单位类型-目录下的请求方法
import Request from "../request";

// 定义一个功能模块基础url
const currBaseUrl = "/unitype/baseconfig";

/**
 * 参数修改接口
 * @param data 数据
 * @param success 成功回调
 * @param fail 失败回调
 */

/**
 * 获取参数类型列表（条件+分页）
 */
export const listFlatType = async (data, success, fail) => {
	try {
		console.log(data);

		// 发送请求
		const res = await Request.requestForm(Request.GET, currBaseUrl + "/getunittypelist", data);
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
export const addFlatType = async (data, success, fail) => {
	try {
		// 发送请求
		const res = await Request.requestForm(Request.POST, currBaseUrl + "/addunittype", data);
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
export const updateFlatType = async (data, success, fail) => {
	try {
		// 发送请求
		const res = await Request.requestForm(Request.PUT, currBaseUrl + "/modifyunittype", data);
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
export const deleteFlatType = async (data, success, fail) => {
	try {
		// 发送请求
		const res = await Request.requestForm(Request.DELETE, currBaseUrl + "/deletebatchunittype", data);
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
export const exportFlatType = async (data, success, fail) => {
	try {
		// 发送请求
		const res = await Request.requestForm(Request.GET, currBaseUrl + "exportunittype", data);
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
export const importFlatType = async (data, success, fail) => {
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
