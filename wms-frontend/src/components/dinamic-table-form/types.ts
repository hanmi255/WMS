import type { CommonTableColumn, SimpleDataTableColumn } from "components/table/types";
import type { SimpleDataTableProps } from "components/table/index.vue";

/**
 * 可编辑表格列的配置
 * @description
 * 从表格组件的 CommonTableColumn 类型派生而来
 *
 * 从数据列派生成为专门的可编辑列
 *
 * 未来应该会派生出更多的表单种类类型。
 *
 * @version 2
 * @description
 * 本类型旨在于替代 `columsItem` 类型。属于破坏性变更。
 */
export type EditableTableColumn<T> = CommonTableColumn<T> & {
	/**
	 * 当前列是否可编辑？
	 * @description
	 * 必须设置当前行是否是可以编辑。
	 * @default true 默认全部的字段都是可以编辑的
	 *
	 * @description
	 * TODO: 设计不合理 未来要被改掉，替换成默认就可以编辑的情况。
	 *
	 * TODO: 工期不够 暂停优化。
	 */
	editable: boolean;

	/** 当前列字段是否是必填项？ */
	requirred?: boolean;
};

/**
 * 简单表格移除掉特定的配置
 * @description
 * 移除掉特定的字段 便于重设新的字段
 * @private 本类型事实上是私有的 仅供给给特定类型使用
 */
export type _OmitSimpleDataTableProps<
	T extends Object,
	//
	Column extends SimpleDataTableColumn<T>,
> = Omit<SimpleDataTableProps<T, Column>, "columns">;

/** 动态表格样式表单 事件 */
export interface DinamicTableFormEmit<T extends Object> {
	/** 数据表更事件 时刻地将更改的数据返回给父级组件 */
	(e: "change-data", rows: T[]): void;
}
