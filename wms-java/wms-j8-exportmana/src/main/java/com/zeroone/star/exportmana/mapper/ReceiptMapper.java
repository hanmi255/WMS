package com.zeroone.star.exportmana.mapper;

import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.zeroone.star.exportmana.entity.Receipt;
import com.zeroone.star.project.query.j8.shipmentmana.receiptmana.ReceiptQuery;

import org.apache.ibatis.annotations.Mapper;

import java.util.List;

/**
 * <p>
 * 回单 Mapper 接口
 * </p>
 *
 * @author asta
 * @since 2025-02-27
 */
@Mapper
public interface ReceiptMapper extends BaseMapper<Receipt> {

    default Page<Receipt> selectByQuery(ReceiptQuery query) {
        //构建分页对象
        Page<Receipt> page = new Page<>(query.getPageIndex(), query.getPageSize());
        //构建查询条件
        QueryWrapper<Receipt> wrapper = new QueryWrapper<>();
        wrapper.select("wm_notice_id","cus_code","beizhu","hd_data")
                .or(i->i.like("wm_notice_id",query.getReceiptId()))
                .or(i->i.like("cus_code",query.getCargoOwner()))
                .or(i->i.like("beizhu",query.getComment()))
                .or(i->i.gt("hd_data",query.getHdBegin()).lt("hd_data",query.getHdEnd()));
        return this.selectPage(page, wrapper);
    }

    default List<Receipt> selectAll(){
        QueryWrapper<Receipt> wrapper = new QueryWrapper<>();
        wrapper.select("create_by","create_date","wm_notice_id","cus_code","beizhu","hd_data");
        return this.selectList(wrapper);
    }
}
