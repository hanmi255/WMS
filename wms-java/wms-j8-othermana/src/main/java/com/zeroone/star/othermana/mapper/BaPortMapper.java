package com.zeroone.star.othermana.mapper;

import com.alibaba.cloud.commons.lang.StringUtils;
import com.baomidou.mybatisplus.core.conditions.query.LambdaQueryWrapper;
import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.zeroone.star.othermana.entity.BaPort;
import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import com.zeroone.star.project.query.j8.other.port.PortQuery;
import org.apache.ibatis.annotations.Mapper;


/**
 * <p>
 *  Mapper 接口
 * </p>
 *
 * @author yjq
 * @since 2025-02-26
 */
@Mapper
public interface BaPortMapper extends BaseMapper<BaPort> {

    default Page<BaPort> selectPageByQuery(Page<BaPort> page, PortQuery query) {
        LambdaQueryWrapper<BaPort> wrapper = new LambdaQueryWrapper<>();

        if (StringUtils.isEmpty(query.getPortZhName()) &&
                StringUtils.isEmpty(query.getPortEnName()) &&
                (query.getPortCode() == null || query.getPortCode().isEmpty()) &&
                (query.getPortThCode() == null || query.getPortThCode().isEmpty())) {
            // 如果没有实际的查询条件，则不调用and方法，wrapper保持为空
        } else {
            if (!StringUtils.isEmpty(query.getPortZhName())) {
                wrapper.like(BaPort::getPortZhName, query.getPortZhName());
            }
            if (!StringUtils.isEmpty(query.getPortEnName())) {
                wrapper.or(w -> w.like(BaPort::getPortEnName, query.getPortEnName()));
            }
            if (query.getPortCode() != null && !query.getPortCode().isEmpty()) {
                wrapper.or(w -> w.eq(BaPort::getPortCode, query.getPortCode()));
            }
            if (query.getPortThCode() != null && !query.getPortThCode().isEmpty()) {
                wrapper.or(w -> w.eq(BaPort::getPortThCode, query.getPortThCode()));
            }
        }

        return this.selectPage(page, wrapper);
    }
}
