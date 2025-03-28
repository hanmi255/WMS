package com.zeroone.star.stockln.mapper;

import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import com.zeroone.star.project.dto.j6.stockln.ToAcceptDTO;
import org.apache.ibatis.annotations.Mapper;
import org.springframework.stereotype.Repository;

/**
 * <p>
 * 描述：入库通知明细数据访问层
 * </p>
 *
 * @author [Susu]
 * @version 1.0.0
 */
@Repository
@Mapper
public interface InNoticeMapper extends BaseMapper<ToAcceptDTO> {
}
