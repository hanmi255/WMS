import { RequiredPick } from "type-plus";
import { ParamsQueryKey, useRequest } from "composables/use-request/index";
import { PageDTO } from "@/types/PageDTO";

/**
 * 分类对象
 * @description
 * 新增 编辑 表格数据
 *
 * @see https://app.apifox.com/link/project/5901227/apis/api-264076051
 */
export interface Catagory {
	/**
	 * 图标的唯一编号
	 */
	iconId?: string;
	/**
	 * 分类的唯一编号
	 */
	id?: string;
	/**
	 * 分类名称
	 */
	name?: string;
	/**
	 * 上级id
	 */
	parentId?: string;
}

/**
 * 新增分类接口
 * @description
 * ParamsBodyKey
 * @see https://app.apifox.com/link/project/5901227/apis/api-264076051
 */
export function sysmanagerCatagoryAddCatagory<T = string>(options: UseAxiosOptionsJsonVO<T>) {
	return useRequest<ParamsBodyKey, T, Catagory>({
		httpParamWay: "body",
		options,
		url: "/sysmanager/catagory/add-catagory",
		config: {
			data: {},
			method: "POST",
		},
	});
}

/**
 * 编辑分类接口
 * @description
 * id必填
 * @see https://app.apifox.com/link/project/5901227/apis/api-264076052
 */
export function sysmanagerCatagoryModifyCatagory<T = string>(options: UseAxiosOptionsJsonVO<T>) {
	return useRequest<ParamsBodyKey, T, RequiredPick<Catagory, "id">>({
		url: "/sysmanager/catagory/modify-catagory",
		options,
		httpParamWay: "body",
		config: {
			method: "PUT",
			data: {
				id: "",
			},
		},
	});
}

/** 分类列表查询接口 vo */
export interface QueryCatagoryListVO {
	/**
	 * 分类id
	 */
	catagoryId?: string;
	/**
	 * 分类类型编码
	 */
	code?: string;
	/**
	 * 是否有字节点
	 */
	haveChildren?: boolean;
	/**
	 * 图标的唯一编号
	 */
	iconId?: string;
	/**
	 * 分类名称
	 */
	name?: string;
	/**
	 * 上级id
	 */
	parentId?: string;
}

/**
 * 分类
 */
export interface QueryCatagoryListDTO {
	/**
	 * 分类id
	 */
	catagoryId?: string;
	/**
	 * 分类类型编码
	 */
	code?: string;
	/**
	 * 是否有字节点
	 */
	haveChildren?: boolean;
	/**
	 * 图标的唯一编号
	 */
	iconId?: string;
	/**
	 * 分类名称
	 */
	name?: string;
	/**
	 * 查询页码
	 */
	pageIndex?: number;
	/**
	 * 查询条数
	 */
	pageSize?: number;
	/**
	 * 上级id
	 */
	parentId?: string;
}

/**
 * 分类列表查询接口
 * @see https://app.apifox.com/link/project/5901227/apis/api-268876761
 */
export function sysmanagerCatagoryQueryCatagoryList<T = QueryCatagoryListDTO[]>(options: UseAxiosOptionsJsonVO<T>) {
	return useRequest<ParamsQueryKey, T, QueryCatagoryListVO>({
		url: "/sysmanager/catagory/query-catagory-list",
		options,
		httpParamWay: "query",
		config: {
			method: "get",
			data: {},
		},
	});
}

/**
 * 删除分类接口
 * @description
 * ParamsPathKey
 *
 * id必填 { id: string }
 * @see https://app.apifox.com/link/project/5901227/apis/api-264076055
 */
export function sysmanagerCatagoryRemoveCatagory<T = string>(options: UseAxiosOptionsJsonVO<T>) {
	return useRequest<
		ParamsQueryKey,
		T,
		{
			/** 分类的唯一编号 */
			id: string;
		}
	>({
		url: "/sysmanager/catagory/remove-catagory",
		options,
		httpParamWay: "query",
		config: {
			method: "delete",
			data: {
				id: "",
			},
		},
	});
}
