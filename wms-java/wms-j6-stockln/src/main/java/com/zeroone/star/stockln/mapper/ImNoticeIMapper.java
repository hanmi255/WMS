package com.zeroone.star.stockln.mapper;


import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import com.zeroone.star.project.dto.j6.stockln.UpdateImNoticeIDTO;
import com.zeroone.star.stockln.entity.ImNoticeI;
import org.apache.ibatis.annotations.Insert;
import org.apache.ibatis.annotations.Mapper;
import org.apache.ibatis.annotations.Param;

import java.util.List;

/**
 * <p>
 * 预约进货通知明细 Mapper 接口
 * </p>
 *
 * @author Backa
 * @since 2025-03-04
 */
@Mapper
public interface ImNoticeIMapper extends BaseMapper<ImNoticeI> {

    int updateImNoticeItem(@Param("dtos") List<UpdateImNoticeIDTO> updateImNoticeIDTO,@Param("imNoticeId") String imNoticeId);
}
