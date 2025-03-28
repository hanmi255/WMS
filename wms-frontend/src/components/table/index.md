---
order: 10
---

# 表格组件

这是专门用于简单数据渲染的表格组件。

## 导入组件

::: details 导入组件

<<< ./tests/import.example.ts

:::

::: tip 项目已使用自动导入组件

你可以直接在模板内写 `<ComponentsTable />` ，即可直接使用表格组件。无需手写导入语句。

:::

## 最小案例

本组件最少要传递 data 和 columns 。传递 data 渲染的数据，传递 columns 表格列配置。

::: details 自动导入的最低限度案例

<<< ./tests/auto-import-mini-example.vue

:::

## 开启索引栏

在 `props` 内传递 `isIndex` 属性来使用默认的索引栏，效果如下：

::: details 索引栏例子

<demo vue="./tests/isIndex-example.vue" />

:::

## 开启多选栏

1. 在 props 内开启 `isMultipleSelect` ，开启多选栏模式。默认在索引栏的前面。
2. `@selection-change` 使用事件获取到数据。

::: details 多选栏例子

<demo vue="./tests/isMultipleSelect-example.vue" />

:::

## 插槽

每一个表格列都可以使用插槽，使用 `bodyCell` 插槽来自定义当前行。

插槽目前默认暴露出 `prop` 和 `row` 值。

- `prop` 当前列的 `key` 值
- `row` 当前行的数据

::: details 插槽

<demo vue="./tests/slot-example.vue" />

:::

## 操作栏

表格业务最常见的配置是实现操作栏。本组件仅负责单纯的数据渲染，不负责内部封装更多的功能，仅负责暴露出操作栏插槽来使用。

操作栏标题名称固定为 `操作` 二字。

使用案例如下：

::: details 操作栏

<demo vue="./tests/operation-bar-slot-example.vue" />

:::

## 靠左前置的操作栏

在某些业务内，操作栏是前置的，放在较前面。

配置操作栏表格列在前面即可。

::: details 前置操作栏

<demo vue="./tests/top-operation-bar-example.vue" />

:::

## 封装组件的参考资料

- https://juejin.cn/post/7331361547011145755
- https://github.com/DrssXpro/table-demo
