package com.zeroone.star.sysmanager.controller;

import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j3.sysmg.datadictionary.TypeBaseDTO;
import com.zeroone.star.project.dto.j3.sysmg.datadictionary.TypeListDTO;
import com.zeroone.star.project.dto.j3.sysmg.datadictionary.TypeModifyDTO;
import com.zeroone.star.project.j3.sysmg.TypeApis;
import com.zeroone.star.project.query.j3.sysmg.datadictionary.TypeGroupQuery;
import com.zeroone.star.project.query.j3.sysmg.datadictionary.TypeQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.sysmanager.service.ITypeService;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiImplicitParam;
import io.swagger.annotations.ApiOperation;
import org.springframework.web.bind.annotation.*;

import javax.annotation.Resource;
import javax.validation.Valid;

/**
 * @program: wms-java
 * @description: 字典类型接口实现
 * @author: 骞骧
 **/
@RestController
@RequestMapping("/sysmanager/type")
@Api(tags = "字典类型接口实现")
public class TypeController implements TypeApis {

    @Resource
    ITypeService typeService;

    /**
     * 新增字典类型
     * @param dto 字典类型数据
     */
    @PostMapping("add")
    @ApiOperation(value = "新增字典类型")
    @Override
    public JsonVO<String> addType(@RequestBody TypeBaseDTO dto) {
        typeService.addType(dto);
        return JsonVO.success("新增字典类型成功");
    }

    /**
     * 通过分类编码（字典Code）获取字典类型名称列表
     * @param typegroupCode 分类编码（字典Code）
     */
    @GetMapping("/query-bygroupcode")
    @ApiOperation(value = "通过分类编码（字典Code）获取字典类型名称列表")
    @ApiImplicitParam(name = "typegroupCode", value = "字典分类编码", required = true, paramType = "query")
    public JsonVO<PageDTO<TypeListDTO>> queryByGroupCode(
            @RequestParam("typegroupCode") String typegroupCode) {
        return JsonVO.success(typeService.queryByGroupCode(typegroupCode));
    }

    /**
     * 获取字典类型列表（条件+分页）
     * @param query 查询条件
     */
    @GetMapping("/query")
    @ApiOperation(value = "获取字典类型列表（条件+分页）")
    public JsonVO<PageDTO<TypeListDTO>> queryAll(@Valid TypeQuery query) {
        return JsonVO.success(typeService.queryTypePage(query));
    }

    /**
     * 修改字典类型
     * @param dto 字典类型数据
     */
    @PostMapping("/modify")
    @ApiOperation(value = "修改字典类型")
    @Override
    public JsonVO<String> modifyType(@RequestBody TypeModifyDTO dto) {
        typeService.modifyType(dto);
        return JsonVO.success("修改字典类型成功");
    }

    /**
     * 删除字典类型
     * @param id 字典类型id
     */
    @DeleteMapping("/remove/{id}")
    @ApiOperation(value = "删除字典类型")
    @ApiImplicitParam(name = "id", value = "字典类型ID", required = true, paramType = "path")
    public JsonVO<String> removeType(@PathVariable String id) {
        typeService.removeType(id);
        return JsonVO.success("删除成功");
    }
}
