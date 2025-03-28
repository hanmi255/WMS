import { Omit, RequiredPick, PartialPick } from "type-plus";
import type { TableProps, TableColumnInstance } from "element-plus";

/**
 * ElTableColumn 组件的 props 值
 * @description
 */
export type TableColumnProps = TableColumnInstance["$props"];

/**
 * 移除掉冗余的 多余报错字段的表格props传参类型
 * @description
 * 实际业务使用的时候 不可能传递 context 这个字段
 */
export type OmitTableProps<T> = Omit<TableProps<T>, "context">;

/**
 * 表格的默认props
 * @description
 * data不是默认必填的字段
 *
 * 本类型仅仅是为了便于配置必填的table属性 固定写死一些功能
 */
export type DefaultTableProps<T> = PartialPick<OmitTableProps<T>, "data">;

/**
 * 表格列可以配置的字段
 * @description
 * 这里携带操作栏的标识符 便于配置操作栏
 *
 * 这里的写法是为了排除掉冗余的类型
 */
export type SimpleDataTableColumnProp<T> =
	| (string & keyof T)
	// 操作栏
	| "operation-bar"
	// 索引栏
	| "index-bar"
	// 选择栏
	| "selection-bar";

type Index = Pick<RequiredPick<TableColumnProps, "index">, "index">;

/** 表格列 索引栏 */
export type TableColumnIndexBar = RequiredPick<TableColumnProps, "index"> & {
	type: "index";
	/** 固定取值为索引栏 */
	prop: "index-bar";
	/**
	 * 表格列标题
	 * @description
	 * 固定取名为序号
	 */
	label: "序号";
};

/**
 * 表格列 多选栏
 * @see https://element-plus.org/zh-CN/component/table.html#多选
 */
export type TableColumnSelectionBar = TableColumnProps & {
	type: "selection";
	/** 固定取值为索引栏 */
	prop: "selection-bar";
};

/**
 * 普通表格列的配置
 * @description
 * KeyPropObj 根据特殊的对象，生成特别的表格列属性
 * 在特殊情况下 表格列的渲染字段 与 实际表格渲染的数据结构有差别
 * 不传递时 默认按照当前渲染的数据来识别列字段
 */
export type CommonTableColumn<T> = TableColumnProps & {
	/**
	 * 表格列标题
	 * @description
	 */
	label: string;

	/** 识别当前列用的字段 */
	prop: SimpleDataTableColumnProp<T>;
};

/**
 * 表格列类型
 * @description
 * 目前仅考虑以下这三种类型
 *
 * - 普通的数据列
 * - 索引栏
 * - 选择栏
 */
export type SimpleDataTableColumn<T> = CommonTableColumn<T> | TableColumnIndexBar | TableColumnSelectionBar;
