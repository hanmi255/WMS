/**
 *
 * @author f1-阮喵喵
 * @description
 * 数据分页的返回对象
 */
export interface PageDTO<T> {
	/**
	 * 当前页码
	 */
	pageIndex: number;

	/**
	 * 每页显示最大数据条数
	 */

	pageSize: number;

	/**
	 * 总条数
	 */
	total: number;

	/**
	 * 总页数
	 */
	pages: number;

	/**
	 * 当前页数据列表
	 */
	rows: T[];
}
