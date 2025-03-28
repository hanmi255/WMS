// sysmanager
import Request from "../request";

/**
 * 获取组织列表
 */
export const getOrgListAPI = (obj) => {
	return Request.requestJson(Request.POST, "/sysmgr/get-organization-list", obj);
};

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
 * 导入组织
 */
export const importOrgAPI = (file) => {
	return Request.postFile("/sysmgr/import-organization", file);
};
