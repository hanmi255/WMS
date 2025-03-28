package com.zeroone.star.sysmanager.service;


import com.zeroone.star.sysmanager.entity.MultiLang;
import com.zeroone.star.sysmanager.entity.MultiLangUpdate;

public interface MultiLangTransactionService {
    /**
     * 插入一条数据, 方法内部加上用户身份上下文, 时间等 策略: 悲观锁
     * @param  multiLang 数据插入实体
     * @return boolean 插入结果
     */
    public Boolean insert(MultiLang multiLang);

    /**
     * 删除一条数据, 查询结果为空则返回false, 不为空就执行删除
     * @param id 语言对照id
     * @return 是否存在对照
     */
    public Boolean delete(String id);

    /**
     * 更新
     * @param multiLang 多语言更新
     * @return 更新成功与否
     */
    public Boolean update(MultiLangUpdate multiLang);
}
