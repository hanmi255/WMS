package com.zeroone.star.othermana.mapper;

import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.zeroone.star.othermana.entity.BaContType;

import com.zeroone.star.project.dto.j8.other.baconttype.BaContTypeDTO;
import com.zeroone.star.project.query.j8.other.baconttype.BaContTypeQuery;
import org.apache.ibatis.annotations.Delete;
import org.apache.ibatis.annotations.Insert;
import org.apache.ibatis.annotations.Mapper;
import org.apache.ibatis.annotations.Select;

import java.util.List;

@Mapper
public interface ContTypeMapper extends BaseMapper<BaContType> {

    default Page<BaContType> selectByQuery(BaContTypeQuery query){
        Page<BaContType> page=new Page<>(query.getPageIndex(), query.getPageSize());
        QueryWrapper<BaContType> wrapper=new QueryWrapper<>();
        wrapper.select("id","cont_type_code","cont_type_name")
                .or(i->i.like("id",query.getId()))
                .or(i->i.like("cont_type_code",query.getContTypeCode()))
                .or(i->i.like("cont_type_name",query.getContTypeName()));
        return this.selectPage(page,wrapper);
    }

    default List<BaContType> selectAll(){
        QueryWrapper<BaContType> wrapper=new QueryWrapper<>();
        wrapper.select("id","cont_type_code","cont_type_name");
        return this.selectList(wrapper);
    }
}
