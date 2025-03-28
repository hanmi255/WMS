package com.zeroone.star.sysmanager.mapper;


import com.zeroone.star.sysmanager.entity.MultiLang;
import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import org.apache.ibatis.annotations.Mapper;
import org.apache.ibatis.annotations.Param;
import org.apache.ibatis.annotations.Select;

import java.util.List;

/**
 * @program: wms-java
 * @description: 多语言mapper
 * @author: hamhuo
 **/

@Mapper
public interface MultiLangMapper extends BaseMapper<MultiLang> {
    /**
     * 悲观锁, 查询对表加锁等待事务提交
     * @param langKey 需要插入的键值
     * @return MultiLang 记录, 若非空则拒绝插入
     */
    @Select("SELECT * FROM t_s_muti_lang WHERE lang_key = #{langKey} FOR UPDATE")
    List<MultiLang> selectByKeyForUpdate(@Param("langKey") String langKey);

    @Select("SELECT * FROM t_s_muti_lang WHERE id = #{id} FOR UPDATE")
    MultiLang selectByIdForUpdate(@Param("id") String id);

    @Select("SELECT * FROM t_s_muti_lang WHERE lang_key = #{langKey} AND lang_code = #{langCode} FOR UPDATE")
    MultiLang selectForUpdate(@Param("langKey") String langKey, @Param("langCode") String langCode);


}