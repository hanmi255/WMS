/**
 * 命令式弹框不允许外部传递的 el-dialog 属性
 * @description
 * - modelValue 不允许外部来管控弹框组件的`显示`和`隐藏`状态
 * - draggable 弹框固定就是可以拖拽的 避免外部组件覆写掉该配置
 * - beforeClose 不允许弹框组件使用该配置 该配置默认被 `onDialogClose` 函数使用
 */
const notUseElDialogProps = <const>["modelValue", "draggable", "beforeClose"];

export default notUseElDialogProps;
