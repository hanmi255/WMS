// 以下是j2组系统管理目录下的请求方法
import Request from "../request";
/**
 * =======================================================================================================================
 */
// TODO 系统公告业务

/**
 * 获取公告列表（分页）
 */
export const getNoticeListAPI = (obj) => {
	return Request.requestForm(Request.GET, "/sysmgr/announcement/page-anno", obj);
};

/**
 * 录入公告接口
 */
export const addNoticeAPI = (obj) => {
	return Request.requestJson(Request.POST, "/sysmgr/announcement/add", obj);
};

/**
 * 修改公告接口
 */
export const updateNoticeAPI = (obj) => {
	return Request.requestJson(Request.POST, "/sysmgr/announcement/update", obj);
};

/**
 * 删除公告（支持批量删除）接口
 */
export const deleteNoticeAPI = (obj) => {
	return Request.requestJson(Request.POST, "/sysmgr/announcement/deleteBatch", obj);
};

/**
 * 获取公告详细信息
 */
export const getNoticeDetailAPI = (obj) => {
	return Request.requestForm(Request.GET, "/sysmgr/announcement/detail-anno", obj);
};

/**
 * =======================================================================================================================
 */

// TODO 角色组织业务

/**
 * 获取组织名称树
 */
export const getDepartmentTreeAPI = () => {
	return Request.requestJson(Request.GET, "/sysmgr/department/tree");
};

/**
 * 获取组织列表
 */
export const getDepartmentListAPI = (parentDepartId) => {
	return Request.requestJson(Request.POST, "/sysmgr/get-organization-list", parentDepartId);
};

/**
 * 录入组织机构
 */
export const addDepartmentAPI = (obj) => {
	return Request.requestJson(Request.POST, "/sysmgr/add-depart", obj);
};

/**
 * 修改组织机构数据
 */
export const updateDepartmentDataAPI = (obj) => {
	return Request.requestJson(Request.POST, "/sysmgr/modify-depart", obj);
};
/**
 * 删除组织机构
 */
export const deleteDepartmentAPI = (obj) => {
	return Request.requestJson(Request.POST, "/sysmgr/delete-depart", obj);
};

/**
 * 导入组织
 */
export const importDepartmentAPI = (obj) => {
	return Request.requestJson(Request.POST, "/sysmgr/import-depart", obj, http.upType.file);
};

/**
 * 导出选择组织
 */
export const exportSelectedDepartmentAPI = (obj) => {
	return Request.requestJson(Request.POST, "/sysmgr/export-selected-organization", obj);
};

/**
 * 删除组织成员
 */
export const deleteDepartmentMemberAPI = (obj) => {
	return Request.requestJson(Request.POST, "/sysmgr/t-suser-org/deleteUser", obj);
};

/**
 * 获取组织成员(条件+分页)
 */
export const getDepartmentMemberAPI = (obj) => {
	return Request.requestJson(Request.GET, "/sysmgr/t-suser-org/listUser", obj);
};

/**
 * 添加组织成员
 */
export const addDepartmentMemberAPI = (obj) => {
	return Request.requestJson(Request.POST, "/sysmgr/t-suser-org/addUser", obj);
};

// TODO 少了用户编辑和添加已有客户和删除用户

/**
 * 获取组织角色
 */
export const getDepartmentRoleAPI = (obj) => {
	return Request.requestJson(Request.GET, "/sysmgr/role-org/query-by-org", obj);
};

/**
 * 更新组织角色
 */
export const updateDepartmentAPI = (obj) => {
	return Request.requestJson(Request.POST, "/sysmgr/role-org/update-role-org", obj);
};
