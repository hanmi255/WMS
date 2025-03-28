package com.zeroone.star.sysmanager.service;

import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.project.dto.j3.sysmg.catagorymanager.AddCatagoryDTO;
import com.zeroone.star.project.dto.j3.sysmg.catagorymanager.EdgeCatagoryDTO;
import com.zeroone.star.project.dto.j3.sysmg.catagorymanager.RemoveCatagoryDTO;
import com.zeroone.star.project.query.j3.sysmg.catagorymanager.CatagoryQuery;
import com.zeroone.star.project.vo.ResultStatus;
import com.zeroone.star.project.vo.j3.sysmg.catagorymanager.CatagoryTreeVO;
import com.zeroone.star.project.vo.j3.sysmg.catagorymanager.CatagoryVO;
import com.zeroone.star.sysmanager.entity.TSCategory;


import java.util.ArrayList;
import java.util.List;


public interface ITSCategoryService extends IService<TSCategory> {

    //获取分类列表
    ArrayList<CatagoryTreeVO> queryAll(CatagoryQuery catagoryQuery);

    //获取分类名称树
    List<CatagoryVO> queryAllTree();

    //新增分类
    ResultStatus addCatagory(AddCatagoryDTO dto) throws Exception;

    //删除分类
    ResultStatus deleteCatagory(RemoveCatagoryDTO dto);

    //编辑分类
    ResultStatus modifyCatagory(EdgeCatagoryDTO dto);


}
