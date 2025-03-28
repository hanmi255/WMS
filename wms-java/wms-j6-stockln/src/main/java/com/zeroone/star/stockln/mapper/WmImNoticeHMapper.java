package com.zeroone.star.stockln.mapper;

import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j6.stockln.ImportNoticeListDTO;
import com.zeroone.star.project.query.j6.stockln.ImportNoticeQuery;
import com.zeroone.star.stockln.entity.WmImNoticeH;
import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import org.apache.ibatis.annotations.Mapper;
import org.apache.ibatis.annotations.Param;

import java.util.List;

/**
 * <p>
 * 预约进货通知抬头 Mapper 接口
 * </p>
 *
 * @author juhao
 * @since 2025-03-06
 */
@Mapper
public interface WmImNoticeHMapper extends BaseMapper<WmImNoticeH> {

    Page<ImportNoticeListDTO> searchAll(Page<ImportNoticeListDTO> page, @Param("ew")QueryWrapper<WmImNoticeH> wrapper);
}
