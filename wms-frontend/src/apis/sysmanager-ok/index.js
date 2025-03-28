// sysmanager
import Request from "../request";

/**
 * 获取角色列表（条件+分页）
 */
export const getRoleListAPI = (obj) => {
	return Request.requestForm(Request.GET, "/sysmanager/role/query-role", obj);
};

/**
 * 录入角色
 */
export const addRoleAPI = (obj) => {
	return Request.requestJson(Request.POST, "/sysmanager/role/add-role", obj);
};

/**
 * 修改角色
 */
export const updateRoleAPI = (obj) => {
	return Request.requestJson(Request.POST, "/sysmanager/role/update-role", obj);
};

/**
 * 删除角色
 */
export const deleteRoleAPI = (id) => {
	return Request.requestForm(Request.GET, `/sysmanager/role/remove-role?id=${id}`);
};

/**
 * 导入角色文件
 */
export const importRoleAPI = (file) => {
	return Request.postFile("/sysmanager/role/import-role", file);
};

/**
 * 导出角色文件
 */
export const exportRoleAPI = () => {
	return Request.requestForm(Request.GET, "/sysmanager/role/export-role");
};

/**
 * ================================================
 */
/**
 * 获取用户列表（条件+分页）
 */
export const getUserListAPI = (obj) => {
	return Request.requestJson(Request.POST, "/sysmanager/user/query-user", obj);
};

/**
 * 添加用户
 */
export const addUserAPI = (obj) => {
	return Request.requestJson(Request.POST, "/sysmanager/user/adduser", obj);
};

/**
 * 编辑用户详情
 */
export const updateUserAPI = (obj) => {
	return Request.requestJson(Request.PUT, `/sysmanager/user/modify/userdetail`, obj);
};

/**
 * 删除用户
 */
export const deleteUserAPI = (userId) => {
	return Request.requestForm(Request.DELETE, `/sysmanager/user/${userId}`);
};

/**
 * 获取组织名称树
 */
export const getOrgNameTreeAPI = () => {
	return Request.requestForm(Request.GET, "/sysmanager/user/query-department-all");
};

/**
 * 获取角色名称列表（条件+分页）
 */
export const getRoleNameListAPI = (obj) => {
	return Request.requestForm(Request.GET, "/sysmanager/role/query-rolename", obj);
};

/**
 * 查询用户详情
 */
export const getUserDetailAPI = (userId) => {
	return Request.requestForm(Request.GET, `/sysmanager/user/get/userdetail/${userId}`);
};

/**
 * 重置用户密码
 */
export const resetUserPasswordAPI = (obj) => {
	return Request.requestForm(Request.POST, `/sysmanager/user/reset-password`, obj);
};

/**
 * 锁定用户状态
 */
export const lockUserStatusAPI = (obj) => {
	return Request.requestForm(Request.PUT, `/sysmanager/user/modify/modifyuserstatus-to-ban`, obj);
};

/**
 * 激活用户状态
 */
export const activeUserStatusAPI = (obj) => {
	return Request.requestForm(Request.PUT, `/sysmanager/user/modify/modifyuserstatus-to-active`, obj);
};

/**
 * 导入用户
 */
export const importUserAPI = (file) => {
	return Request.postFile("/sysmanager/user/import", file);
};

/**
 * 获取角色用户列表（查询属于该角色的用户）（条件+分页）
 */
export const getRoleUserSearchListAPI = (obj) => {
	return Request.requestForm(Request.GET, "/sysmanager/role/query-roleUserList", obj);
};

/**
 * 添加角色用户（添加单个
 */
export const addOneRoleUserAPI = (obj) => {
	return Request.requestForm(Request.POST, "/sysmanager/role/add-roleUser", obj);
};
