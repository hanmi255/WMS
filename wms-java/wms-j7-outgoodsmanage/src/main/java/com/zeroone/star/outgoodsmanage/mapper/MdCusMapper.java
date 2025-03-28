package com.zeroone.star.outgoodsmanage.mapper;

import com.zeroone.star.outgoodsmanage.entity.MdCus;
import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import com.zeroone.star.outgoodsmanage.entity.WmOmNoticeI;
import org.apache.ibatis.annotations.Mapper;
import org.apache.ibatis.annotations.Select;

import java.util.List;

/**
 * <p>
 *  Mapper 接口
 * </p>
 *
 * @author qiuye
 * @since 2025-02-23
 */
@Mapper
public interface MdCusMapper extends BaseMapper<MdCus> {
    @Select("SELECT zhong_wen_qch " +
            "FROM md_cus " +
            "WHERE ke_hu_bian_ma =#{cusCode}")
    MdCus queryByCode(String cusCode);
}
