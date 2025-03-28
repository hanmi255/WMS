package com.zeroone.star.msgmw.mapper;

import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.msgmw.entity.TSSmsTemplateSql;
import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import com.zeroone.star.msgmw.service.ITSSmsTemplateSqlService;
import org.apache.ibatis.annotations.Mapper;

/**
 * <p>
 * 消息模板配置 Mapper 接口
 * </p>
 *
 * @author qunzhong
 * @since 2025-02-21
 */
@Mapper
public interface TSSmsTemplateSqlMapper extends BaseMapper<TSSmsTemplateSql> {

}
