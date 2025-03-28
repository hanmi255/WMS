package com.zeroone.star.project.j3.sysmg;

import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j3.sysmg.multilang.MultiLangBaseDTO;
import com.zeroone.star.project.dto.j3.sysmg.multilang.MultiLangListDTO;
import com.zeroone.star.project.query.j3.sysmg.multilang.MultiLangQuery;
import com.zeroone.star.project.vo.JsonVO;

/**
 * @program: wms-java
 * @description: 系统管理-国际化语言Api
 * @author: hamhuo
 **/
public interface MultiLangApi {

    /**
     * 查询语言对照列表
     * @param query 查询条件
     * @return 响应结果
     */
    JsonVO<PageDTO<MultiLangListDTO>> queryMultiLang(MultiLangQuery query);

    /**
     * 录入语言对照
     * @param multiLangBaseDTO 对照信息
     * @return 响应结果
     */
    JsonVO<String> addMultiLang(MultiLangBaseDTO multiLangBaseDTO);

    /**
     * 更新语言对照
     * @param multiLangBaseDTO 对照信息
     * @return 响应结果
     */
    JsonVO<String> modifyMultiLang(MultiLangBaseDTO multiLangBaseDTO);

    /**
     * 删除语言对照
     * @param id 唯一标识
     * @return 响应结果
     */
    JsonVO<String> deleteMultiLang(String id);

    /**
     * 手动刷新缓存
     * @return 刷新结果
     */
    JsonVO<String> refreshCache();


}