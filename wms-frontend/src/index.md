---
order: 10
---

# 10wms 前端技术文档

这是前端项目的文档，其中包括了组件说明文档，api 生成出来的文档等等。

## 关于此文档

::: details 文档负责人

前端组成员，`f1-阮喵喵`

- https://github.com/ruan-cat

:::

::: details 图片无法加载

本文档站点的全部图片，均使用 github 图床。你需要确保你的网络条件能够翻墙，能够进 github。

你可以下载免费的 [Watt Toolkit](https://steampp.net/) 加速访问 [github](https://github.com/)。

:::

## `IDE`设置要求

本项目目前仅仅考虑使用 [vscode](https://code.visualstudio.com/) 来启动项目。

请下载 vscode。

另外，vscode 是免费软件，不需要付费，也不需要破解。如果你下载了付费软件，那么你就被骗了。

### 赋予 vscode 管理员运行权限

我们要在 vscode 的终端内运行 node 命令，大多数操作都需要管理员权限，请阅读以下文章，按要求设置你的 vscode。

- https://blog.csdn.net/moqidian/article/details/137554066

### 将 vscode 设置成中文

当你第一次使用 vscode 时，他是纯英文的。请按照以下教程完成中文设置。

- https://zhuanlan.zhihu.com/p/263036716

## git 分支操作规范

我们前端组的主分支是 f1 分支。

如果你是后端成员，想单纯的运行本项目，就切换到 f1 分支。

如果你是前端成员，请不要直接在 f1 分支内直接提交，这不符合规范。

## 选择正确的项目根目录

首先你需要在 git 内切换到 f1 分支。

我们前端项目的根目录是 `wms-frontend`，你应该先进入到 `wms-frontend` 文件夹内，在这个文件夹打开 vscode。

当你用 vscode 打开项目时，你的顶部标题应该是这样的：

::: details vscode 顶部标题

![2025-02-26-17-04-09](https://gh-img-store.ruan-cat.com/01s-docs/10wms/2025-02-26-17-04-09.png)

:::

## 为项目准备好必要的 vscode 插件

你并不需要专门去下载这些插件，我们前端组已经为你准备好了一份项目启动所需要的 vscode 插件清单。清单列表如下：

::: details vscode 插件清单

<<< ../.vscode/settings.json

:::

你也并不需要逐个安装，在你第一次用 vscode 打开项目时，你的右下角会弹出弹框，提示你是否要批量安装本项目推荐的插件，你点击是即可。

### 手动批量安装项目推荐插件

假设你不小心错过了这个弹框，你仍旧有办法批量安装插件。

如下图所示：

1. 点击拓展。
2. 输入命令 `@recommended` 。

你逐个点击安装并启用即可。

::: details 本项目推荐的插件

![2025-02-26-16-07-27](https://gh-img-store.ruan-cat.com/01s-docs/10wms/2025-02-26-16-07-27.png)

:::

## 准备 node 环境

我们的 node 环境版本范围在 `20.15.0` 以上。你安装 `20.15.1` 即可。

你并不需要辛苦地去找指定版本的 node 环境去安装，我们有高效率的安装方案。我们推荐你使用 [nvm-desktop](https://github.com/1111mp/nvm-desktop) 来安装、切换、管理你的全部 node 环境。

点击 [releases](https://github.com/1111mp/nvm-desktop/releases)，看情况下载好本工具。

nvm-desktop 看起来应该是这样的：

::: details nvm-desktop

![2025-02-26-16-20-57](https://gh-img-store.ruan-cat.com/01s-docs/10wms/2025-02-26-16-20-57.png)

:::

### 配置 nvm-desktop 的镜像地址

你应该配置成淘宝源，否则你下载 node 环境的速度会非常慢，配置过程请看以下动图：

::: details 配置镜像源

![2025-02-26-16-22-45](https://gh-img-store.ruan-cat.com/01s-docs/10wms/2025-02-26-16-22-45.gif)

:::

### 安装并启用 node 环境

如图所示：

::: details 启用 node 环境

![2025-02-26-16-27-16](https://gh-img-store.ruan-cat.com/01s-docs/10wms/2025-02-26-16-27-16.png)

:::

### 校验 node 是否安装成功

在控制台输入以下命令，显示出对应的 node 版本号，就说明已经安装好对应的 node 环境了。

```bash
node -v
```

::: details 输出 node 版本号

![2025-02-26-16-29-03](https://gh-img-store.ruan-cat.com/01s-docs/10wms/2025-02-26-16-29-03.png)

:::

## 安装项目依赖

在终端内输入以下命令：

```bash
npm i
```

你并不需要担心镜像源的事情，在本项目内已经为你配置好了默认的淘宝镜像源。

::: details .npmrc 包管理器配置

<<< ../.npmrc

:::

::: details 仍旧安装失败？

你应该在保证网络条件能翻墙的情况下，安装依赖。本项目有少数几个依赖不在淘宝源内。

:::

::: warning 选用高性能的 pnpm 作为包管理器

[点此文章](./docs/pnpm.md)专门阅读关于 pnpm 设置的内容。如果你的电脑环境适合安装 pnpm，那么你可以试试看。

:::

## 调出 vscode 的 npm 脚本菜单栏

我们推荐你点击命令，而不是去输入命令。vscode 已经为我们集成好可视化的，可点击的 npm 命令栏了。

::: details 显示出 npm 脚本栏

![2025-02-26-16-42-59](https://gh-img-store.ruan-cat.com/01s-docs/10wms/2025-02-26-16-42-59.png)

:::

你应该要看到该页面：

::: details 本项目的 npm 命令

![2025-02-26-16-45-02](https://gh-img-store.ruan-cat.com/01s-docs/10wms/2025-02-26-16-45-02.png)

:::

## 认识这些命令

如果你是后端成员，你只需要认识这两个命令即可：

### 本地运行

鼠标点击 dev 即可。

![2025-02-26-16-49-00](https://gh-img-store.ruan-cat.com/01s-docs/10wms/2025-02-26-16-49-00.png)

也可以手动运行此命令：

```bash
npm run dev
```

### 打包项目

鼠标点击 build 即可。

![2025-02-26-16-49-55](https://gh-img-store.ruan-cat.com/01s-docs/10wms/2025-02-26-16-49-55.png)

也可以手动运行此命令：

```bash
npm run build
```

### 其他命令

如果你是前端成员，请点击此学习其他的命令。

## 目录结构说明

请[点此链接](./docs/directory-structure-description.md)另外学习。

## 本项目路线图

- 组件库文档
- 组合式 api 文档
- typedoc 生成的文档
