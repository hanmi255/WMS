package com.zeroone.star.sysmanager.service.impl;

import com.baomidou.mybatisplus.core.conditions.query.LambdaQueryWrapper;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.project.components.user.UserHolder;
import com.zeroone.star.project.dto.j3.sysmg.catagorymanager.AddCatagoryDTO;
import com.zeroone.star.project.dto.j3.sysmg.catagorymanager.EdgeCatagoryDTO;
import com.zeroone.star.project.dto.j3.sysmg.catagorymanager.RemoveCatagoryDTO;
import com.zeroone.star.project.query.j3.sysmg.catagorymanager.CatagoryQuery;
import com.zeroone.star.project.utils.tree.TreeNode;
import com.zeroone.star.project.utils.tree.TreeNodeMapper;
import com.zeroone.star.project.vo.ResultStatus;
import com.zeroone.star.project.vo.j3.sysmg.catagorymanager.CatagoryTreeVO;
import com.zeroone.star.project.vo.j3.sysmg.catagorymanager.CatagoryVO;
import com.zeroone.star.sysmanager.entity.Company;
import com.zeroone.star.sysmanager.entity.TSCategory;
import com.zeroone.star.sysmanager.mapper.TSCategoryMapper;
import com.zeroone.star.sysmanager.service.ITSCategoryService;
import org.springframework.beans.BeanUtils;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;
import org.springframework.util.StringUtils;

import javax.annotation.Resource;
import java.sql.Timestamp;
import java.util.*;

//用来实现objectMapper的类，用于查询分类名称树
class TSCategoryTreeMapper implements TreeNodeMapper<TSCategory> {

    @Override
    public TreeNode objectMapper(TSCategory tsCategory) {
        CatagoryVO catagoryVO = new CatagoryVO();
        catagoryVO.setCategoryId(tsCategory.getId());
        catagoryVO.setTnId(tsCategory.getId());
        if (StringUtils.isEmpty(tsCategory.getParentId())) {
            catagoryVO.setTnPid(null);
            catagoryVO.setParentId(null);
        } else {
            catagoryVO.setTnPid(tsCategory.getParentId());
            catagoryVO.setParentId(tsCategory.getParentId());
        }
        catagoryVO.setName(tsCategory.getName());
        catagoryVO.setChildren(new ArrayList<>());

        return catagoryVO;
    }
}

@Service
public class TSCategoryServiceImpl extends ServiceImpl<TSCategoryMapper, TSCategory> implements ITSCategoryService {


    @Autowired
    TSCategoryMapper tsCategoryMapper;

    @Resource
    private UserHolder userHolder;

    //分类列表查询
    @Override
    public ArrayList<CatagoryTreeVO> queryAll(CatagoryQuery catagoryQuery) {
        ArrayList<CatagoryTreeVO> list = new ArrayList<>();
        List<TSCategory> tsCategories;

        if (Objects.isNull(catagoryQuery.getCatagoryId())) {
            LambdaQueryWrapper<TSCategory> lambdaQueryWrapper = new LambdaQueryWrapper<>();
            lambdaQueryWrapper.isNull(TSCategory::getParentId)
                    .or()
                    .eq(TSCategory::getParentId, "");
            tsCategories = baseMapper.selectList(lambdaQueryWrapper);
        } else {
            LambdaQueryWrapper<TSCategory> lambdaQueryWrapper = new LambdaQueryWrapper<>();
            lambdaQueryWrapper.eq(TSCategory::getParentId, catagoryQuery.getCatagoryId());
            tsCategories = baseMapper.selectList(lambdaQueryWrapper);
        }

        for (TSCategory t : tsCategories) {
            CatagoryTreeVO catagoryTreeVO = new CatagoryTreeVO();
            BeanUtils.copyProperties(t, catagoryTreeVO);
            list.add(catagoryTreeVO);
        }
        return list;
    }

    //获取分类名称树
    @Override
    public List<CatagoryVO> queryAllTree() {

        List<TSCategory> categoryList = baseMapper.selectList(null);
        TSCategoryTreeMapper mapper = new TSCategoryTreeMapper();

        List<CatagoryVO> catagoryVOList = new ArrayList<>();
        for (TSCategory category : categoryList) {
            catagoryVOList.add((CatagoryVO) mapper.objectMapper(category));
        }
        List<CatagoryVO> rootCategories = new ArrayList<>();
        Map<String, CatagoryVO> categoryMap = new HashMap<>();
        for (CatagoryVO catagoryVO : catagoryVOList) {
            categoryMap.put(catagoryVO.getCategoryId(), catagoryVO);
        }
        for (CatagoryVO catagoryVO : catagoryVOList) {
            if (catagoryVO.getParentId() == null) {
                rootCategories.add(catagoryVO);
            } else {
                CatagoryVO parentCategory = categoryMap.get(catagoryVO.getParentId());
                if (parentCategory != null) {
                    parentCategory.getChildren().add(catagoryVO);
                }
            }
        }
        for (CatagoryVO catagoryVO : catagoryVOList) {
            catagoryVO.setHaveChildren(!catagoryVO.getChildren().isEmpty());
        }
        return rootCategories;
    }

    //新增分类
    public ResultStatus addCatagory(AddCatagoryDTO dto) throws Exception {
        Timestamp createDate = new Timestamp(System.currentTimeMillis());
        Timestamp updateDate = new Timestamp(System.currentTimeMillis());

        //String id = String.valueOf(userHolder.getCurrentUser().getId());
        //WmsAppUser wmsAppUser = tsCategoryMapper.selectUserInfo(id);
//        TSRoleOrg tsRoleOrg = tsCategoryMapper.selectOrg(id);
//        TSUserOrg tsUserOrg = tsCategoryMapper.selectCompany(id);
        // TODO 继续改
        String createName = userHolder.getCurrentUser().getUsername(); //创建人名称
        Company company = tsCategoryMapper.getCompany(createName);
        String createBy = company.getCreateBy(); //创建人登录名称
        String code = String.valueOf(UUID.randomUUID().toString().replace("-", ""));
        String sysOrgCode = company.getSysOrgCode(); //机构
        String sysCompanyCode = company.getSysCompanyCode(); //公司

        tsCategoryMapper.add(dto, code, createName, createBy, createDate, updateDate, sysOrgCode, sysCompanyCode);
        return ResultStatus.SUCCESS;
    }

    //删除分类
    public ResultStatus deleteCatagory(RemoveCatagoryDTO dto) {
        tsCategoryMapper.delete(dto);
        return ResultStatus.SUCCESS;
    }

    //编辑分类
    public ResultStatus modifyCatagory(EdgeCatagoryDTO dto) {
        tsCategoryMapper.modify(dto);
        return ResultStatus.SUCCESS;
    }


}
