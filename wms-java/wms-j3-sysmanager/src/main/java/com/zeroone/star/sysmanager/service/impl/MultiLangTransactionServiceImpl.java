package com.zeroone.star.sysmanager.service.impl;


import com.baomidou.mybatisplus.core.conditions.update.UpdateWrapper;
import com.zeroone.star.sysmanager.entity.MultiLang;
import com.zeroone.star.sysmanager.entity.MultiLangUpdate;
import com.zeroone.star.sysmanager.exception.MultiLangException;
import com.zeroone.star.sysmanager.mapper.MultiLangMapper;
import com.zeroone.star.sysmanager.mapper.MultiLangUpdateMapper;
import com.zeroone.star.sysmanager.service.MultiLangTransactionService;
import org.springframework.stereotype.Service;
import org.springframework.transaction.annotation.Propagation;
import org.springframework.transaction.annotation.Transactional;

import javax.annotation.Resource;
import java.util.List;

/**
 * @program: wms-java
 * @description: 多语言事务服务, 新建服务实例避免类内部调用以实现代理事务
 * @author: hamhuo
 **/

@Service
public class MultiLangTransactionServiceImpl implements MultiLangTransactionService {

    //注入mapper, 执行数据库操作
    @Resource
    private MultiLangMapper multiLangMapper;

    @Resource
    private MultiLangUpdateMapper multiLangUpdateMapper;

    /**
     * 插入国际化语言记录。
     * <p>
     * 该方法使用悲观锁机制，确保在插入前检查是否已存在相同的语言键，避免重复数据。
     * 如果键值已存在，则抛出 {@link MultiLangException}。
     * </p>
     *
     * @param multiLang 需要插入的国际化语言记录
     * @return {@code true} 表示插入成功，{@code false} 表示插入失败
     * @throws MultiLangException 如果键值已存在
     */
    @Override
    @Transactional(rollbackFor = Exception.class, propagation = Propagation.REQUIRED)
    public Boolean insert(MultiLang multiLang) {
            //执行查询, 悲观锁
            List<MultiLang> existing = multiLangMapper.selectByKeyForUpdate(multiLang.getLangKey());
            if (!existing.isEmpty()) {
                //已存在记录
                throw new MultiLangException("键值已存在");
            }
            //执行插入, 构建 multiLang
            return multiLangMapper.insert(multiLang) > 0;
    }


    /**
     * 删除指定 ID 的多语言记录。
     * <p>
     * 该方法使用悲观锁（FOR UPDATE）查询 ID 对应的记录，
     * 确保在删除时不会有并发修改问题。
     * </p>
     *
     * <p><strong>事务管理：</strong></p>
     * <ul>
     *     <li>@Transactional 事务传播级别为 REQUIRED，保证事务一致性。</li>
     *     <li>rollbackFor = Exception.class 确保发生异常时事务回滚。</li>
     * </ul>
     *
     * @param id 需要删除的多语言记录 ID
     * @return 如果记录存在并删除成功，则返回 true；否则返回 false
     */
    @Override
    @Transactional(rollbackFor = Exception.class, propagation = Propagation.REQUIRED)
    public Boolean delete(String id) {
        MultiLang multiLang = multiLangMapper.selectByIdForUpdate(id);
        if(multiLang != null){
            multiLangMapper.deleteById(id);
            return true;
        }
        return false;
    }

    /**
     * 更新多语言记录。
     *
     * <p>该方法通过悲观锁 (`FOR UPDATE`) 查询 `lang_key` 和 `lang_code` 是否已存在，
     * 以确保数据一致性并避免重复键冲突。如果未找到匹配记录，则执行更新操作。</p>
     *
     * <p>实现步骤：
     * <ul>
     *     <li>使用 `selectForUpdate` 方法查询数据库，获取当前 `lang_key` 和 `lang_code` 对应的记录，并加锁。</li>
     *     <li>如果查询结果为空，表示当前 `lang_key` 和 `lang_code` 不存在，则执行更新操作。</li>
     *     <li>使用 `UpdateWrapper` 构造条件，仅更新 `id` 匹配的记录。</li>
     *     <li>执行 `multiLangUpdateMapper.update()` 方法更新数据库。</li>
     *     <li>如果更新成功，返回 `true`，否则返回 `false`。</li>
     * </ul>
     *
     * <p>注意事项：
     * <ul>
     *     <li>该方法在事务中执行，使用 `@Transactional(rollbackFor = Exception.class, propagation = Propagation.REQUIRED)` 确保事务完整性。</li>
     *     <li>如果 `lang_key` 和 `lang_code` 组合已存在，则不会执行更新操作，直接返回 `false`。</li>
     *     <li>更新时只根据 `id` 进行匹配，不会更改 `lang_key` 和 `lang_code`，以避免唯一性约束冲突。</li>
     * </ul>
     *
     * @param multiLang 待更新的多语言数据对象
     * @return 更新成功返回 `true`，否则返回 `false`
     */
    @Override
    @Transactional(rollbackFor = Exception.class, propagation = Propagation.REQUIRED)
    public Boolean update(MultiLangUpdate multiLang) {
        MultiLang lang = multiLangMapper.selectForUpdate(multiLang.getLangKey(), multiLang.getLangCode());
        if(lang == null){
            UpdateWrapper updateWrapper = new UpdateWrapper();
            updateWrapper.eq("id", multiLang.getId());
            multiLangUpdateMapper.update(multiLang, updateWrapper);
            return true;
        }
        return false;
    }
}