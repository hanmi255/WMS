package com.zeroone.star.sysmanager.service;

import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j3.sysmg.multilang.MultiLangBaseDTO;
import com.zeroone.star.project.dto.j3.sysmg.multilang.MultiLangListDTO;
import com.zeroone.star.project.query.j3.sysmg.multilang.MultiLangQuery;
import com.zeroone.star.sysmanager.entity.MultiLang;

/**
 * @program: wms-java
 * @description: 国际化语言 服务接口
 * @author: hamhuo
 **/
public interface MultiLangService extends IService<MultiLang> {
    /**
     * 分页/条件查询, 根据query携带参数进行条件/分页查询
     * @return 分页对象
     */
    PageDTO<MultiLangListDTO> listMultiLang(MultiLangQuery query);

    /**
     * 插入语言对照, 禁止插入重复键值
     * @param multiLangBaseDTO 语言基础DTO
     * @return boolean 成功/失败
     */
    Boolean saveMultiLang(MultiLangBaseDTO multiLangBaseDTO) throws Exception;


    /**
     * 更新语言对照
     * @param multiLangBaseDTO 更新表单对象
     * @return boolean 正确与否
     * @throws Exception 事务回滚
     */
    boolean updateMultiLang(MultiLangBaseDTO multiLangBaseDTO) throws Exception;

    /**
     * 根据id删除语言对照,
     * @param id 语言id
     * @return String 回传信息
     */
    String removeMultiLang(String id);

    /**
     * 手动失效缓存
     * @return 结果
     */
    String refreshCache();
}
