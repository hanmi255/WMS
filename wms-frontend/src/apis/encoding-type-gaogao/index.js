// j4组-编码类型-目录下的请求方法
import Request from "../request";

// 定义一个功能模块基础url
const currBaseUrl = "/codetype/baseconfig";

/**
 * 参数修改接口
 * @param data 数据
 * @param success 成功回调
 * @param fail 失败回调
 */

/**
 * 获取参数类型列表（条件+分页）
 */
export const listCodeBaseConfig = async (data, success, fail) => {
	try {
		// 发送请求
		const res = await Request.requestForm(Request.GET, currBaseUrl + "/query-encodingtype", data);
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
export const addCodeBaseConfig = async (data, success, fail) => {
	try {
		// 发送请求
		const res = await Request.requestJson(Request.POST, currBaseUrl + "/add-encodingtype", data);
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
export const updateCodeBaseConfig = async (data, success, fail) => {
	try {
		// 发送请求
		const res = await Request.requestJson(Request.PUT, currBaseUrl + "/modify-encodingtype", data);
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
export const deleteCodeBaseConfig = async (data, success, fail) => {
	try {
		// 发送请求
		const res = await Request.requestJson(Request.DELETE, currBaseUrl + "/delete-encodingtype", data);
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
export const exportCodeBaseConfig = async (data, success, fail) => {
	try {
		// 发送请求
		const res = await Request.requestForm(Request.GET, currBaseUrl + "export-encodingtype", data);
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
export const importCodeBaseConfig = async (data, success, fail) => {
	try {
		// 发送请求
		const res = await Request.requestForm(Request.POST, currBaseUrl + "import-encodingtype", data);
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
