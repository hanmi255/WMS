// j4组-自动编码-目录下的请求方法
import Request from "../request";

// 定义一个功能模块基础url
const currBaseUrl = "/autocode/baseconfig/automaticencoding";

/**
 * 参数修改接口
 * @param data 数据
 * @param success 成功回调
 * @param fail 失败回调
 */

/**
 * 获取参数类型列表（条件+分页）
 */
export const listAutoCoding = async (data, success, fail) => {
	try {
		// 发送请求
		const res = await Request.requestForm(Request.GET, currBaseUrl + "/queryall", data);
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
export const addAutoCoding = async (data, success, fail) => {
	try {
		// 发送请求
		const res = await Request.requestForm(Request.POST, currBaseUrl + "/save", data);
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
export const updateAutoCoding = async (data, success, fail) => {
	try {
		// 发送请求
		const res = await Request.requestForm(Request.POST, currBaseUrl + "/update", data);
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
export const deleteAutoCoding = async (data, success, fail) => {
	try {
		// 发送请求
		const res = await Request.requestJson(Request.DELETE, currBaseUrl + "/delete", data);
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
export const exportAutoCoding = async (data, success, fail) => {
	try {
		// 发送请求
		const res = await Request.requestForm(Request.GET, currBaseUrl + "export", data);
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
export const importAutoCoding = async (data, success, fail) => {
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
