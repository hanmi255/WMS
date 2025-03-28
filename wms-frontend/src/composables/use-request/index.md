# 基于 useAxios 的请求函数 <Badge type="tip" text="^0.4.0" />

useAxios 是 vueuse 集成里面的函数，在本项目内做了二次封装了。

这是一个接口请求用的工具函数，使用方式如下：

## 导入函数

<<< ./tests/import.example.ts

::: tip 自动导入

如果你使用的是 typescript，你不需要手动导入该内容。本项目已经实现自动导入功能了。

直接使用该函数名即可。

:::

## 选项配置类型

`UseAxiosOptionsJsonVO`，是包含我们项目返回值的一个工具类型。我们在定义接口时，可以使用 useAxios 的 options 配置，用该配置实现接口成功和失败的回调定义。

## 定义 query 传参的接口

如下例子所示：

::: details query 传参的接口

<<< ./tests/query.example.ts

:::

- `ParamsQueryKey` 类型是用来约束该函数传参时需要填写那些字段的。
- `httpParamWay` 要填写为 query

### 使用 query 接口

你可以使用 useAxios 函数所提供的全部响应式工具和回调函数。

::: details 使用 query 接口的测试用例

<<< ./tests/query.test.ts

:::

## 定义 body 传参的接口

::: details body 传参的接口

<<< ./tests/body.example.ts

:::

- `ParamsBodyKey` 类型是用来约束该函数传参时需要填写那些字段的。
- `httpParamWay` 要填写为 body

### 使用 body 接口

你可以使用 useAxios 函数所提供的全部响应式工具和回调函数。

::: details 使用 body 接口的测试用例

<<< ./tests/body.test.ts

:::

## 定义 path 传参的接口

::: details path 传参的接口

<<< ./tests/path.example.ts

:::

- `ParamsPathKey` 类型是用来约束该函数传参时需要填写那些字段的。
- `httpParamWay` 要填写为 path

::: warning path 传参的 url 可以乱写

这里为了实现类型约束，会强制要求你补全填写 url，但是由于 path 传参的 url 最终是前端自己拼接的，所以此处的 url 事实上是不生效的。你可以乱填写。

但是为了语义化，建议你填写看起来比较正常的地址。

比如本例子就填写了看起来能读懂的地址：

```json
{
	"url": "/sysmanager/typegroup/remove/{id}"
}
```

:::

### 使用 path 接口

你可以使用 useAxios 函数所提供的全部响应式工具和回调函数。

::: details 使用 path 接口的测试用例

<<< ./tests/path.test.ts

:::

::: tip path 传参方式

path 传参方式要求前端在接口请求路径上传递参数，请注意填写值的格式。需要前端自己拼接接口参数。

先拼接，再做接口请求。

:::

<!-- TODO: 文档尚未编辑完成 -->
<!-- ## 其他参考
具体使用见以下文档：
- https://utils.ruan-cat.com/vueuse/useAxios/ -->
