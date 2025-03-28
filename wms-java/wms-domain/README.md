# 工程简介
定义给个领域模型需要的实体，除了do层的领域模型，其它层的领域模型都需要定义在这里
# 扩展说明
## 包命名规则
包名由小写字母组成（如果多个单词要写成多个包或者用单词缩写），基础包名为`com.zeroone.star.project.[dto|query|vo]`。子包第一个包名用小组名命名，然后下级包名是模块名称，后续以此类推，下面列举一些例子：
* j1组开发系统主页的相关领域模型，包名可以命名为：
  * Dto模型包名：`com.zeroone.star.project.dto.j1.homepage`
  * Query模型包名：`com.zeroone.star.project.query.j1.homepage`
  * Vo模型包名：`com.zeroone.star.project.vo.j1.homepage`
* j2组开发系统设置的相关领域模型，包名可以命名为：
  * Dto模型包名：`com.zeroone.star.project.dto.j2.sys`
  * Query模型包名：`com.zeroone.star.project.query.j2.sys`
  * Vo模型包名：`com.zeroone.star.project.vo.j2.sys`