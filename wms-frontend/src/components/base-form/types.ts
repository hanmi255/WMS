import type { FormProps } from "element-plus";
import type { DinamicTableFormProps } from "components/dinamic-table-form/index.vue";

/** 表单组件 可用的表单类型 */
export type FormComponentType =
	// 输入框
	| "input"
	// 选择框
	| "select"
	// 日期时间选择框
	| "date"
	// 输入框（纯数字）
	| "number"
	// 动态表格框
	| "table";

/**
 * 响应式配置
 * @description
 * 每个表单项的响应式布局配置
 */
export interface ResponsiveConfig {
	xs?: number;
	sm?: number;
	md?: number;
	lg?: number;
	xl?: number;
}

/**
 * 移除掉部分字段的 FormProps
 * @description
 * 让基础表单组件可以使用 `<el-form>` 组件的全部props属性
 * @private 预期仅用于基础表单组件的props属性继承
 */
export type _OmitFormProps = Omit<Partial<FormProps>, "rules">;

/**
 * 表单配置对象 可以配置的字段
 * @description
 * 这里的写法是为了排除掉冗余的类型
 *
 * 预期用于表单校验等场景
 */
export type BaseFormPropKey<T> = string & keyof T;
// export type BaseFormPropKey<T> = keyof T;

/**
 * 每一个表单配置项都具有的字段
 * @description
 * 该类型预期被继承 本类型旨在于框定每一个表单配置项都要填写的字段
 * @private 暂不考虑该类型被其他组件使用
 */
interface _BaseFormItemProps<T> {
	/** 表单字段 */
	label: string;
	/**
	 * 表单的字段key值
	 * @version 2 即之前的 `dataKey` 配置
	 * @description
	 * 取名为 prop 是为了配合表单校验所需的字段
	 *
	 * @see https://element-plus.org/zh-CN/component/form#表单校验
	 */
	prop: BaseFormPropKey<T>;

	/**
	 * 响应式布局配置
	 * @description
	 * 每个表单项的响应式布局配置·
	 */
	responsive?: ResponsiveConfig;
}

/** 输入框 props */
interface InputProps<T> extends _BaseFormItemProps<T> {
	placeholder?: string;
	maxlength?: number;
	lableWidth?: number;
	width?: number;
	required?: boolean;
}

/** 选择框 props */
interface SelectProps<T> extends _BaseFormItemProps<T> {
	options: Array<{ label: string; value: any }>;
	multiple?: boolean;
	filterable?: boolean;
}

/** 日期框 props */
interface DateProps<T> extends _BaseFormItemProps<T> {
	placeholder?: string;
	format?: string;
	valueFormat?: string;
	type?:
		| "date"
		| "datetime"
		| "year"
		| "years"
		| "month"
		| "months"
		| "dates"
		| "week"
		| "datetimerange"
		| "daterange"
		| "monthrange"
		| "yearrange";
}

/** 输入框（纯数字） props */
interface NumberProps<T> extends _BaseFormItemProps<T> {
	min?: number;
	max?: number;
	step?: number;
	precision?: number;
}

/**
 * 表格框 props
 * @description
 * TODO: 未来对接新的，专门的表格字段类型 DinamicTableFormProps
 */
interface TableProps<
	T,
	Row = T[_BaseFormItemProps<T>["prop"]] extends Record<string, any>
		? T[_BaseFormItemProps<T>["prop"]]
		: Record<string, any>,
> extends _BaseFormItemProps<T>,
		DinamicTableFormProps<Row extends Record<string, any> ? Row : never> {}

// 创建联合类型
/** 基础表单项 */
export type BaseFormItem<T> =
	| {
			type: "input";
			props: InputProps<T>;
	  }
	| {
			type: "select";
			props: SelectProps<T>; // 这里使用强制要求 props 的写法
	  }
	| {
			type: "date";
			props: DateProps<T>;
	  }
	| {
			type: "number";
			props: NumberProps<T>;
	  }
	| {
			type: "table";
			props: TableProps<T>;
	  };

/**
 * 设置动态表格列的配置类型 该配置类型用于动态表格列的配置
 * @version 1
 * @description
 * 该类型目前有计划地完成替代 未来会有新的类型代替本类型的使用。
 * @deprecated 正在有计划地废弃该组件
 */
export interface columsItem {
	/** 未来被替换成 prop */
	dataKey: string;
	label: string;
	/** 未来不是必填项 默认都是可编辑的 */
	editable: boolean;
	requirred?: boolean;
}

/**
 * 动态表格样式表单 事件
 * @description
 * TODO: 暂时不实现事件数据传递。 目前考虑的业务场景都有用户主动点击提交或查询按钮的情况
 *
 * 用户会获取表单的数据 暂不需要考虑时时刻刻的双向数据绑定。
 */
export interface BaseFormEmit<T extends Object> {
	/**
	 * 数据变更事件 时刻地将更改的数据返回给父级组件
	 * @description
	 * 旨在于取代之前的 `form-finish` 事件。
	 *
	 * TODO: 未来实现的功能： 本组件会时时刻刻的返回数据给父级组件
	 *
	 */
	(e: "change-data", rows: T[]): void;
}
