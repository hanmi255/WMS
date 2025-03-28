package com.zeroone.star.sysmanager.controller;

import com.zeroone.star.project.dto.j3.sysmg.catagorymanager.AddCatagoryDTO;
import com.zeroone.star.project.dto.j3.sysmg.catagorymanager.EdgeCatagoryDTO;
import com.zeroone.star.project.dto.j3.sysmg.catagorymanager.RemoveCatagoryDTO;
import com.zeroone.star.project.j3.sysmg.CatagoryApis;
import com.zeroone.star.project.query.j3.sysmg.catagorymanager.CatagoryQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.ResultStatus;
import com.zeroone.star.project.vo.j3.sysmg.catagorymanager.CatagoryTreeVO;
import com.zeroone.star.project.vo.j3.sysmg.catagorymanager.CatagoryVO;


import com.zeroone.star.sysmanager.service.ITSCategoryService;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.*;

import java.util.ArrayList;
import java.util.List;

@RestController
@RequestMapping("sysmanager/catagory")
@Api(tags = "分类管理接口实现")
public class TSCategoryController implements CatagoryApis {

    @Autowired
    ITSCategoryService tsCategoryService;

    @GetMapping("query-catagory-list")
    @ApiOperation(value = "分类列表查询接口")
    @Override
    public JsonVO<ArrayList<CatagoryTreeVO>> queryAll(CatagoryQuery catagoryQuery) {
        return JsonVO.success(tsCategoryService.queryAll(catagoryQuery));
    }

    @GetMapping("query-catagory-tree")
    @ApiOperation(value = "分类名称树查询接口")
    @Override
    public JsonVO<List<CatagoryVO>> queryAllTree() {
        return JsonVO.success(tsCategoryService.queryAllTree());
    }

    @PostMapping("add-catagory")
    @ApiOperation(value = "新增分类接口")
    @Override
    public JsonVO<ResultStatus> addCatagory(@RequestBody AddCatagoryDTO dto) {
        try {
            tsCategoryService.addCatagory(dto);
        }catch (Exception e){
            System.out.println(e);
            return JsonVO.fail(ResultStatus.SERVER_ERROR);
        }
        return JsonVO.success(ResultStatus.SUCCESS);
    }
    @DeleteMapping("remove-catagory")
    @ApiOperation(value = "删除分类接口")
    @Override
    public JsonVO<ResultStatus> removeCatagory(@RequestBody RemoveCatagoryDTO dto) {
        try{
            tsCategoryService.deleteCatagory(dto);
        }catch (Exception e){
            return JsonVO.fail(ResultStatus.SERVER_ERROR);
        }
        return JsonVO.success(ResultStatus.SUCCESS);
    }

    @PutMapping("modify-catagory")
    @ApiOperation(value = "编辑分类接口")
    @Override
    public JsonVO<ResultStatus> modifyCatagory(@RequestBody EdgeCatagoryDTO dto) {
        try{
            tsCategoryService.modifyCatagory(dto);
        }catch (Exception e){
            return JsonVO.fail(ResultStatus.SERVER_ERROR);
        }
        return JsonVO.success(ResultStatus.SUCCESS);
    }
}
