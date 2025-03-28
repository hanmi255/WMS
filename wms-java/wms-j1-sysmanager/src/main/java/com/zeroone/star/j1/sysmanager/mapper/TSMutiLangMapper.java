package com.zeroone.star.j1.sysmanager.mapper;

import com.zeroone.star.j1.sysmanager.entity.TSMutiLang;
import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import org.apache.ibatis.annotations.Mapper;
import org.apache.ibatis.annotations.Select;

import java.util.List;

/**
 * <p>
 *  Mapper 接口
 * </p>
 *
 * @author qpz
 * @since 2025-03-02
 */
@Mapper
public interface TSMutiLangMapper {

    @Select("SELECT id,lang_key, lang_context,lang_code FROM t_s_muti_lang")
    List<TSMutiLang> selectLangs();
}
