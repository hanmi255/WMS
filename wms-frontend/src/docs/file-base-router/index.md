# 基于文件的路由

我们项目现在已经全面地使用了基于文件的路由。

## 目录规范

在 views 文件夹下面，根据业务新建文件夹和页面即可。

下面以 daily-check 的 temperature-maintain 为例子说明如何组织侧边栏文件夹。

::: details 侧边栏文件夹

![2025-03-02-16-34-34](https://gh-img-store.ruan-cat.com/01s-docs/10wms/2025-03-02-16-34-34.png)

:::

## 1 新建业务目录

新建 `src\views\daily-check`。比如这里的业务是每日检查，那么我们就在 views 文件夹下新建文件夹。

## 2 新建侧边栏文件夹组件

新建 `src\views\daily-check\index.vue` 文件，用于定义侧边栏的文件夹，如下示例：

::: details 菜单目录例子

<<< ./menu-folder-example.vue

:::

::: warning 该组件必须命名为 index.vue

根据自动路由插件的规范，你必须命名为 index.vue ，否者无法被当做是父级路由，无法生成干净的路由。

:::

这个配置将会用于生成侧边栏的折叠栏。

## 3 新建页面文件夹

根据你的业务，新建存放具体页面的文件夹。比如本例子的 `src\views\daily-check\temperature-maintain` 目录。

## 4 新建页面组件

新建 `src\views\daily-check\temperature-maintain\index.vue` 文件。该文件就是实现业务的页面了。

具体编写例子如下：

::: details 页面文件例子

<<< ./menu-page-example.vue

:::

::: warning 该组件必须命名为 index.vue

根据自动路由插件的规范，你必须命名为 index.vue ，否者无法被当做是子路由，无法生成干净的路由。

:::

## 5 组织实现业务用的组件

实现业务一定会涉及到新建组件的，在你的页面文件旁边，新建 components 文件夹，存放你实现业务的组件。

::: details 新建 components 文件夹

![2025-03-02-16-58-11](https://gh-img-store.ruan-cat.com/01s-docs/10wms/2025-03-02-16-58-11.png)

:::

::: warning 该文件夹的命名必须为 components

目前本项目的自动路由组件，排除掉了 components 文件下全部的 vue 组件，这些 vue 组件不会自动生成路由，也不会出现在侧边栏内。

如果你乱取名，你会搞乱侧边栏的生成，到时候会生成一大堆无法点击的，空的侧边栏。

目前插件仅匹配 `components` 这个文件夹名称。

:::

## 关于案例页面

案例页面不会在这个侧边栏内生成，他们被排除了。他们预期会在别的侧边栏内显示出来。

如果你在编写案例页面，你应该在 `src\views\sample` 内新建 vue 组件。

案例页面的 definePage 配置如下：

::: details definePage 的 isSample 配置

<<< ./sample-page-definePage.example.ts

:::

## 那些东西我不用再继续做了？

你并不需要在 `src\routers` 目录下新建路由了。全部的路由配置将会基于文件目录结构来生成。

## 这是怎么实现的？

由两个 vite 插件共同实现的。

- [unplugin-vue-router](https://github.com/posva/unplugin-vue-router)
- [vite-plugin-vue-meta-layouts](https://github.com/dishait/vite-plugin-vue-meta-layouts)

这两个插件的试用可以参考这个项目：

- [vitesse](https://github.com/antfu-collective/vitesse)
