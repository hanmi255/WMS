package com.zeroone.star.sysmgr.mapper;

import com.zeroone.star.project.dto.j2.sysmgr.DepartTreeBaseDTO;
import com.zeroone.star.project.dto.j2.sysmgr.DepartTreeListDTO;
import com.zeroone.star.project.utils.tree.TreeNode;
import com.zeroone.star.project.utils.tree.TreeNodeMapper;

public class DepartTreeNodeMapper implements TreeNodeMapper<DepartTreeListDTO> {
    @Override
    public TreeNode objectMapper(DepartTreeListDTO dto) {
        DepartTreeBaseDTO node = new DepartTreeBaseDTO();
        // 设置节点属性
        node.setTnId(dto.getId());
        node.setTnPid(dto.getParentDepartId());
        node.setDepartName(dto.getDepartName());
        // 转换机构类型为字符串
        node.setType(convertOrgType(dto.getOrgType()));
        return node;
    }

    private String convertOrgType(Integer orgType) {
        switch (orgType) {
            case 1: return "公司";
            case 2: return "组织";
            case 3: return "岗位";
            default: return "未知";
        }
    }
}