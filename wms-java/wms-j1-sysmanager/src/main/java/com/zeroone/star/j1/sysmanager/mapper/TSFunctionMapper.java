package com.zeroone.star.j1.sysmanager.mapper;

import com.zeroone.star.j1.sysmanager.entity.TSFunction;
import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import com.zeroone.star.j1.sysmanager.entity.TSRoleFunction;
import com.zeroone.star.project.vo.j1.sysmanager.rolemanager.RoleFunctionVO;
import org.apache.ibatis.annotations.Insert;
import org.apache.ibatis.annotations.Mapper;
import org.apache.ibatis.annotations.Param;
import org.apache.ibatis.annotations.Select;
import org.apache.ibatis.annotations.Update;

import java.util.List;

/**
 * <p>
 * InnoDB free: 600064 kB; (`parentfunctionid`) REFER `jeecg/t_ Mapper 接口
 * </p>
 *
 * @author qpz
 * @since 2025-03-02
 */
@Mapper
public interface TSFunctionMapper extends BaseMapper<TSFunction> {

    @Select("SELECT * FROM t_s_function")
    List<TSFunction> getAllMenus();
    @Select("SELECT * FROM t_s_function WHERE parentfunctionid = #{menuId}")
    List<TSFunction> getAllMenusHavaparent(String menuId);

    @Select("SELECT * FROM t_s_function WHERE ID = #{menuId}")
    TSFunction getMenuById(String menuId) ;

    /**
     * 修改菜单数据
     * @param ts 菜单数据
     * @return 响应数据结果
     */
    int update(TSFunction ts);

    /**
     * 插入菜单
     * @param ts
     */
    @Insert("INSERT INTO t_s_function (ID,functionname,functiontype,functionlevel,parentfunctionid,functionurl,create_by, create_name,create_date) " +
            "VALUES (#{id}, #{functionname}, #{functiontype}, #{functionlevel}, #{parentfunctionid}, #{functionurl},  #{createBy}, #{createName}, #{createDate})")
    void insertMenu(TSFunction ts);

    @Select("SELECT ID, functionname, functionurl, functionlevel, parentfunctionid, iconid ,functionorder FROM t_s_function ORDER BY functionorder ASC")
    List<RoleFunctionVO> selectFunctions();

    @Select("SELECT id " +
            "FROM t_s_function " +
            "WHERE functionurl = #{functionUrl} " +
            "AND functionorder = #{functionOrder} " +
            "AND parentfunctionid = #{parentId}")
    String selectIdByFunctionUrlAndParentId(@Param("functionUrl") String functionUrl,
                                            @Param("functionOrder") String functionOrder,
                                            @Param("parentId") String parentId);

    @Update("update t_s_role_function set functionid = #{functionid} where id = #{id}")
    Integer updateRoleFunction(TSRoleFunction tsRoleFunction);

    @Select("select * from t_s_role_function where t_s_role_function.functionid = #{id}")
    List<TSRoleFunction> selectList(String id);

    /**
     * 更新父菜单id
     * @param menuId 菜单id
     */
    @Update("update t_s_function set parentfunctionid = null where id = #{menuId}")
    void updateParentId(String menuId);

    @Select("select functionname from t_s_function where id = #{parentfunctionid}")
    String selectParentName(String parentfunctionid);
    @Select("select * from t_s_function where parentfunctionid = #{menuId}")
    List<TSFunction> selectisParent(String menuId);

    @Select("select * from t_s_function where functionlevel = 0 ")
    List<TSFunction> getFirstMenus();

    @Select("select * from t_s_function where parentfunctionid = #{id}")
    List<TSFunction> selectChild(String id);
}

