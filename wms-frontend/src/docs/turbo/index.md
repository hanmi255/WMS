# 任务调度工具 turbo

turbo，是一个单仓项目使用的 package.json 命令调度工具，专门用于配置 package.json 命令之间的前驱后继关系。

本项目不属于 monorepo 单仓架构，也很适合使用 turbo 实现任务调度。

- [官网](https://turbo.build/repo/docs)
- [仓库](https://github.com/vercel/turborepo)

## turbo.json

turbo.json，是任务调度的配置文件。任务之间的依赖关系一律使用该配置文件实现。

- [配置任务](https://turbo.build/repo/docs/crafting-your-repository/configuring-tasks)

## 缓存文件忽略

turbo 运行时，会增加很多日志和缓存文件。这些文件不应该添加到 git 仓库内。

- [增加配置](https://turbo.build/repo/docs/getting-started/add-to-existing-repository#edit-gitignore)
