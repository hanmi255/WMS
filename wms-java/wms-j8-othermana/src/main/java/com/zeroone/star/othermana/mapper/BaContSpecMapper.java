package com.zeroone.star.othermana.mapper;

import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.zeroone.star.othermana.entity.BaContSpec;
import com.zeroone.star.project.query.j8.other.contspec.SpecificationQuery;
import org.apache.ibatis.annotations.Mapper;

import java.util.List;

/**
 * <p>
 *  Mapper 接口
 * </p>
 *
 * @author xban
 * @since 2025-02-27
 */
@Mapper
public interface BaContSpecMapper extends BaseMapper<BaContSpec> {
    default Page<BaContSpec> listAll(SpecificationQuery query){
        Page<BaContSpec> page = new Page<>(query.getPageIndex(), query.getPageSize());
        QueryWrapper<BaContSpec> wrapper = new QueryWrapper<>();
        if (query.getSpecificationId() != null) {
            wrapper.eq("cont_spec_code", query.getSpecificationId());
        }
        if (query.getSpecificationName() != null) {
            wrapper.eq("cont_spec_name", query.getSpecificationName());
        }
        return this.selectPage(page,wrapper);
    }
    default List<BaContSpec> selectAll(){
        QueryWrapper<BaContSpec> wrapper = new QueryWrapper<>();
        wrapper.select("create_name","create_by","create_date","sys_org_code","sys_company_code","cont_spec_code","cont_spec_name");
        return this.selectList(wrapper);
    }
}
