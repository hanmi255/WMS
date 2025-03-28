import type { TemplatePromiseProps } from "@vueuse/core";
import type { DialogProps } from "element-plus";
import notUseElDialogProps from "./not-use-el-dialog-props";

type OnDialogCloseParams<T> = Pick<TemplatePromiseProps<T>, "resolve" | "reject">;

/** 可选的弹框props */
type DialogPropsPartial = Partial<DialogProps>;

/**
 * 移除掉不需要key值
 * @description
 * 命令式弹框的props不需要这些配置
 */
type DialogPropsRemoveKey = Omit<DialogPropsPartial, (typeof notUseElDialogProps)[number]>;

/** promise命令式弹框 props */
export interface DialogPromiseProps<T> {
	/**
	 * 即 ElDialog 的 `@close` 事件的函数
	 * @see https://element-plus.org/zh-CN/component/dialog.html#事件
	 * 请在此函数内处理弹框是否要关闭逻辑，成功了返回true，失败了返回false
	 */
	onDialogClose: (params: OnDialogCloseParams<T>) => Promise<boolean>;

	/**
	 * 弹框组件的属性
	 * @description
	 * 设计成可选的 对于命令式弹框 本组件不会过多的预设弹框组件的行为
	 *
	 * 预期只会接受弹框组件的title标题和width宽度
	 */
	dialogProps?: DialogPropsRemoveKey;
}
