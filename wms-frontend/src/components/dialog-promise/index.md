---
order: 20
---

# 命令式弹框

以 promise 回调方式使用的 `<el-dialog>` 弹框组件。将打开弹框组件当做是打开一个异步函数，并从中获取到返回值。

## 设计初衷

尽量避免使用过于复杂的方式调用弹框。尽可能最简单的方式包装组件，满足简单的业务即可。

### 实现表单业务的返回值

特别是为了满足弹框内表单的业务。比如说弹框负责完成表单数据交互，完成后返回已经新增或修改的数据。页面随即从返回的数据内做其他接口交互，或者是其他行为。

### 不再让父组件维护弹框组件的显隐状态

避免让父组件手动管理弹框组件的显示和隐藏。这种方式很麻烦，容易新建很多变量。

## 最小案例

1. 必须要提供`异步`的 `onDialogClose` 函数。该函数默认返回`布尔值`，表示控制弹框是否关闭。
2. 必须要获得弹框实例，使用内部的异步函数控制弹框是否打开，并从中获取到返回值。

::: details 最小案例

<demo vue="./tests/mini-example.vue" />

:::

## 底部插槽

使用底部插槽提供 `reject` 和 `resolve` 作用域插槽参数，实现弹框的关闭逻辑。你应该在弹框关闭函数 onDialogClose 内实现全部的弹框关闭逻辑，比如常见的表单校验逻辑。

::: details 自己封装弹框关闭按钮

<demo vue="./tests/footer-slot-example.vue" />

:::

## 设置弹框属性

在 `dialogProps` 内设置 `<el-dialog>` 的属性即可。

::: details 设置弹框标题

<demo vue="./tests/dialog-props-example.vue" />

:::

::: warning 部分字段不允许填写且不生效

为了防止使用的时候不小心覆盖掉弹框组件的默认行为，有部分字段被屏蔽使用了。被禁用的，默认使用的字段如下：

<<< ./not-use-el-dialog-props.ts

:::

## 表单弹框例子

以下例子演示了如何使用命令式弹框实现简单的表单业务。

::: details

<demo vue="./tests/simple-form-example.vue" />

:::

## 实现原理

本组件本质上是对 [vueuse](https://vueuse.org/) 的 [createTemplatePromise](https://vueuse.org/core/createTemplatePromise) 工具做二次封装。
