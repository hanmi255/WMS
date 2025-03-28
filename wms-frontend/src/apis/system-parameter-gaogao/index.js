// j4组-系统参数-目录下的请求方法
import Request from "../request";

// 定义一个功能模块基础url
const currBaseUrl = "/systemparameter";

/**
 * 参数修改接口
 * @param data 数据
 * @param success 成功回调
 * @param fail 失败回调
 */

/**
 * 获取参数类型列表（条件+分页）
 */
export const listSystemParameter = async (data, success, fail) => {
	try {
		// 发送请求
		const res = await Request.requestForm(Request.GET, currBaseUrl + "/query-all", data);
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
export const addSystemParameter = async (data, success, fail) => {
	try {
		// 发送请求
		const res = await Request.requestJson(Request.POST, currBaseUrl + "/add", data);
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
export const updateSystemParameter = async (data, success, fail) => {
	try {
		// 发送请求
		const res = await Request.requestJson(Request.POST, currBaseUrl + "/modify", data);
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
export const deleteSystemParameter = async (data, success, fail) => {
	try {
		// 发送请求
		const res = await Request.requestJson(Request.DELETE, currBaseUrl + "/delete-SystemParameter", data);
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
export const exportSystemParameter = async (data, success, fail) => {
	try {
		// 发送请求
		const res = await Request.requestForm(Request.GET, currBaseUrl + "export-SystemParameter", data);
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
export const importSystemParameter = async (data, success, fail) => {
	try {
		// 发送请求
		const res = await Request.requestForm(Request.POST, currBaseUrl + "import-SystemParameter", data);
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
