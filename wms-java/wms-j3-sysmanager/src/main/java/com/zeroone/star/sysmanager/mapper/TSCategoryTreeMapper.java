//package com.zeroone.star.sysmanager.mapper;
//
//import com.zeroone.star.project.utils.tree.TreeNode;
//import com.zeroone.star.project.utils.tree.TreeNodeMapper;
//import com.zeroone.star.project.vo.j3.sysmg.catagorymanager.CatagoryVO;
//import com.zeroone.star.sysmanager.entity.TSCategory;
//import org.springframework.util.StringUtils;
//
//import java.util.ArrayList;
//
////用来实现objectMapper的类，用于查询分类名称树
//public class TSCategoryTreeMapper implements TreeNodeMapper<TSCategory> {
//
//    @Override
//    public TreeNode objectMapper(TSCategory tsCategory) {
//
//        CatagoryVO catagoryVO = new CatagoryVO();
//        catagoryVO.setCategoryId(tsCategory.getId());
//        catagoryVO.setTnId(tsCategory.getId());
//
//        if (StringUtils.isEmpty(tsCategory.getParentId())) {
//            catagoryVO.setTnPid(null);
//        } else {
//            catagoryVO.setTnPid(tsCategory.getParentId());
//        }
//        catagoryVO.setName(tsCategory.getName());
//        catagoryVO.setChildren(new ArrayList<>());
//
//        return catagoryVO;
//    }
//}