package com.zeroone.star.sysmgr.mapper;

import com.zeroone.star.project.dto.j2.sysmgr.DepartTreeListDTO;
import com.zeroone.star.sysmgr.entity.Depart;
import org.apache.ibatis.annotations.Insert;
import org.apache.ibatis.annotations.Mapper;
import org.apache.ibatis.annotations.Param;

import java.util.List;



@Mapper
public interface DepartMapper {
    /**
     * 查询所有部门
     * @return
     */
    List<DepartTreeListDTO> selectAllDeparts();

    // 查询根级节点，包含是否有子节点
    List<DepartTreeListDTO> selectRootDepartmentsWithChildren();

    // 查询指定父部门下的子节点，包含是否有子节点
    List<DepartTreeListDTO> selectChildDepartmentsWithChildren(String parentDepartId);

    // 查询所有部门，包含是否有子节点
    List<Depart> selectListDeparts();

    // 根据 id 查询部门
    List<Depart> selectByIds(List<String> departIds);

    /**
     * 根据 org_code 查询记录（只查询必要字段）
     * @param orgCodes 机构编码集合
     * @return 对应的 Depart 列表
     */
    List<Depart> selectByOrgCodes(@Param("orgCodes") List<String> orgCodes);

    /**
     * 批量插入部门记录，参数类型为 DepartTreeListDTO
     * @param departList 待插入记录列表
     */
    void savedepartList(@Param("list") List<DepartTreeListDTO> departList);

    /**
     * 批量更新部门记录
     * @param departList 待更新记录列表
     */
    void updateBatch(@Param("list") List<DepartTreeListDTO> departList);

    /**
     * 单条更新部门记录
     * @param dto 部门数据传输对象
     */
    void update(DepartTreeListDTO dto);

    /**
     * 获取所有部门信息
     * @return List<DepartTreeListDTO>数据列表
     */
    List<DepartTreeListDTO> getDeparDTOList();
}