package com.zeroone.star.stockln.mapper;

import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import com.zeroone.star.project.dto.j6.stockln.InboundQmIDTO;
import com.zeroone.star.stockln.entity.ToShelves;
import org.apache.ibatis.annotations.Delete;
import org.apache.ibatis.annotations.Insert;
import org.apache.ibatis.annotations.Mapper;
import org.apache.ibatis.annotations.Param;


@Mapper
public interface ToShelvesMapper extends BaseMapper<ToShelves> {
//    @Insert("INSERT INTO wm_in_qm_i (im_notice_id, goods_id, qm_ok_quat, pro_data, binId, goodsBatch, recDeg, itemText, tinId, tinZhl) " +
//            "VALUES (#{dto.im_notice_id}, #{dto.goods_id}, #{dto.qm_ok_quat}, #{dto.pro_data}, #{dto.binId}, #{dto.goodsBatch}, #{dto.recDeg}, #{dto.itemText}, #{dto.tinId}, #{dto.tinZhl})")
//    int insert(@Param("dto") InboundQmIDTO dto);
}
