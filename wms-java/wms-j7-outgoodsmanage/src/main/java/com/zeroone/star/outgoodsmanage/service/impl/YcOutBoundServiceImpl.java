package com.zeroone.star.outgoodsmanage.service.impl;

import cn.hutool.core.util.StrUtil;
import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.outgoodsmanage.mapper.YcOutBoundMapper;
import com.zeroone.star.outgoodsmanage.service.IYcOutBoundService;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j7.ycoutbound.YcOutBoundDTO;
import com.zeroone.star.project.query.j7.ycoutbound.YcOutBoundQuery;
import org.springframework.stereotype.Service;

/**
 * <p>
 * 异常出库通知 服务实现类
 * </p>
 *
 * @author keyuan
 * @since 2025-03-01
 */
@Service
public class YcOutBoundServiceImpl extends ServiceImpl<YcOutBoundMapper, YcOutBoundDTO> implements IYcOutBoundService {
    /**
     * 获取数据表数据量
     *
     * @return java.lang.Long
     */
    @Override
    public Long getPageSize() {
        return baseMapper.getPageSize();
    }

    /**
     * 分页+条件查询
     * @param query 查询条件
     * @return PageDTO<YcOutBoundDTO> 查询结果
     */
    @Override
    public PageDTO<YcOutBoundDTO> queryAll(YcOutBoundQuery query) {
        Page<YcOutBoundDTO> page = new Page<>(query.getPageIndex(), query.getPageSize());

        QueryWrapper<YcOutBoundDTO> wrapper = new QueryWrapper<>();

        // 动态条件处理
        if (StrUtil.isNotBlank(query.getOmNoticeId())) {
            wrapper.like("h.om_notice_id", query.getOmNoticeId());
        }
        if (StrUtil.isNotBlank(query.getImCusCode())) {
            wrapper.like("h.im_cus_code", query.getImCusCode());
        }
        if (StrUtil.isNotBlank(query.getOcusCode())) {
            wrapper.like("h.ocus_code", query.getOcusCode());
        }
        if (StrUtil.isNotBlank(query.getOcusName())) {
            wrapper.like("h.ocus_name", query.getOcusName());
        }
        if (StrUtil.isNotBlank(query.getOmBeizhu())) {
            wrapper.like("h.om_beizhu", query.getOmBeizhu());
        }
        if (StrUtil.isNotBlank(query.getGoodsId())) {
            wrapper.like("i.goods_id", query.getGoodsId());
        }
        if (StrUtil.isNotBlank(query.getGoodsName())) {
            wrapper.like("i.goods_name", query.getGoodsName());
        }

        //page.setOptimizeCountSql(false);
        // 执行分页查询
        Page<YcOutBoundDTO> resultPage = baseMapper.selectYcOutBoundDTO(page, wrapper);
        return PageDTO.create(resultPage);
    }

}
