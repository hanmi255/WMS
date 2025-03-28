package com.zeroone.star.sysmanager.mapper;

import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import com.zeroone.star.project.dto.j3.sysmg.catagorymanager.AddCatagoryDTO;
import com.zeroone.star.project.dto.j3.sysmg.catagorymanager.EdgeCatagoryDTO;
import com.zeroone.star.project.dto.j3.sysmg.catagorymanager.RemoveCatagoryDTO;
import com.zeroone.star.sysmanager.entity.*;

import org.apache.ibatis.annotations.*;

import java.sql.Timestamp;

@Mapper
public interface TSCategoryMapper extends BaseMapper<TSCategory> {
    @Insert("insert into t_s_category (id, icon_id, code, name, create_name, create_by, create_date," +
            " update_date, parent_id, sys_org_code, sys_company_code) " +
            "values (#{dto.id},#{dto.iconId},#{code},#{dto.name},#{createName},#{createBy},#{createDate}," +
            "#{updateDate},#{dto.parentId},#{sysOrgCode},#{sysCompanyCode});")
    void add(AddCatagoryDTO dto, String code, String createName, String createBy, Timestamp createDate, Timestamp updateDate, String sysOrgCode, String sysCompanyCode);

    @Delete("delete from t_s_category where id = #{id}")
    void delete(RemoveCatagoryDTO dto);

    @Update("update t_s_category set icon_id = #{iconId},name = #{name},parent_id = #{parentId} where id = #{id}")
    void modify(EdgeCatagoryDTO dto);

    @Select("select * from wms_app_user where id = #{id}")
    WmsAppUser selectUserInfo(String id);

    @Select("select * from t_s_role_org where id = #{id}")
    TSRoleOrg selectOrg(String id);

    @Select("select * from t_s_user_org where id = #{id}")
    TSUserOrg selectCompany(String id);

    @Select("select * from ba_comp where create_name = #{createName}")
    Company getCompany(String createName);
}
