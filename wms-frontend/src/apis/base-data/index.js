// 以下是j5组基础资料目录下的请求方法
import Request from "../request";
/**
 * =======================================================================================================================
 */

// TODO 消息模块业务

/**
 * 获取消息模板详细信息
 */
/**
 * 获取商品列表的API函数
 *
 * @param obj 请求参数对象
 * @returns 返回一个异步函数，用于加载商品列表
 */

export const getshangpingApi = async (data, success, fail) => {
	// const $store = useUserStore();
	try {
		// 发送登录请求
		const res = await Request.requestForm(Request.GET, "/md/goods/query-all", data);
		// 处理登录结果
		if (res.data) {
			// 记录Token到本地
			// 执行成功回调
			success(res.data);
			return;
		}
	} catch (err) {
		// 打印错误信息
		console.warn(err);
		// 执行失败回调
		fail();
	}
};

/**
 * 录入消息模板
 */
export const addMessageTemplateAPI = (obj) => {
	return Request.request(Request.POST, "/msgmw/add-messageTemplate", obj, http.upType.json);
};

/**
 * 修改消息模板
 */
export const updateMessageTemplateAPI = (obj) => {
	return Request.request(Request.PUT, "/msgmw/update-messageTemplate", obj, http.upType.json);
};

/**
 * 删除消息模板，通过勾选对应的消息模版删除(可多项勾选)
 */
export const deleteMessageTemplateAPI = (obj) => {
	return Request.request(Request.DELETE, "/msgmw/delete-messageTemplate", obj, http.upType.json);
};

/**
 * =======================================================================================================================
 */

// TODO 消息中心业务
/**
 * 获取消息列表（带条件分页）
 */
export const getMessageCenterAPI = (obj) => {
	return Request.request(Request.GET, "/msgmw/messages", obj, http.upType.json);
};

/**
 * 修改消息
 */
export const updateMessageCenterAPI = (obj, id) => {
	return Request.request(Request.PUT, `/msgmw/messages/${id}`, obj, http.upType.json);
};

/**
 * =======================================================================================================================
 */

// TODO 业务配置业务

/**
 * 获取业务配置列表（条件+分页）
 */
export const getWorkSettingAPI = (obj) => {
	return Request.request(Request.POST, "/msgmw/query", obj, http.upType.json);
};

/**
 * 录入业务配置
 */
export const addWorkSettingAPI = (obj) => {
	return Request.request(Request.POST, "/msgmw/add", obj, http.upType.json);
};

/**
 * 修改业务配置
 */
export const updateWorkSettingAPI = (obj) => {
	return Request.request(Request.PUT, "/msgmw/update", obj, http.upType.json);
};

/**
 * 删除业务配置（支持批量）
 */
export const deleteWorkSettingAPI = (obj) => {
	return Request.request(Request.DELETE, "/msgmw/delete", obj, http.upType.json);
};

/**
 * =======================================================================================================================
 */

// TODO 业务SQL业务

/**
 * 获取SQL列表(条件+分页)
 */
export const getSqlListAPI = (obj) => {
	return Request.request(Request.GET, "/msgmw/query-sql-list", obj, http.upType.json);
};

/**
 * 录入SQL
 */
export const addSqlAPI = (obj) => {
	return Request.request(Request.POST, "/msgmw/add-sql", obj, http.upType.json);
};

/**
 * 修改SQL
 */
export const updateSqlAPI = (obj) => {
	return Request.request(Request.PUT, "/msgmw/modify-sql", obj, http.upType.json);
};

/**
 * 删除SQL
 */
export const deleteSqlAPI = (obj) => {
	return Request.request(Request.DELETE, "/msgmw/remove-sql", obj, http.upType.json);
};
