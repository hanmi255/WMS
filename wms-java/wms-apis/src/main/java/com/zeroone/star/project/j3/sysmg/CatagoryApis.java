package com.zeroone.star.project.j3.sysmg;

import com.zeroone.star.project.dto.j3.sysmg.catagorymanager.AddCatagoryDTO;
import com.zeroone.star.project.dto.j3.sysmg.catagorymanager.EdgeCatagoryDTO;
import com.zeroone.star.project.dto.j3.sysmg.catagorymanager.RemoveCatagoryDTO;
import com.zeroone.star.project.query.j3.sysmg.catagorymanager.CatagoryQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.ResultStatus;
import com.zeroone.star.project.vo.j3.sysmg.catagorymanager.CatagoryTreeVO;
import com.zeroone.star.project.vo.j3.sysmg.catagorymanager.CatagoryVO;


import java.util.ArrayList;
import java.util.List;

/**
 *
 */
public interface CatagoryApis {
    //查询分类列表
    JsonVO<ArrayList<CatagoryTreeVO>> queryAll(CatagoryQuery catagoryQuery);

    //获取分类名称树
    JsonVO<List<CatagoryVO>> queryAllTree();

    //新增分类
    JsonVO<ResultStatus> addCatagory(AddCatagoryDTO dto);

    //删除分类
    JsonVO<ResultStatus> removeCatagory(RemoveCatagoryDTO dto);

    //编辑分类
    JsonVO<ResultStatus> modifyCatagory(EdgeCatagoryDTO dto);

}
