package com.zeroone.star.sysmanager.controller;

import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j3.sysmg.datadictionary.TypeGroupAddDTO;
import com.zeroone.star.project.dto.j3.sysmg.datadictionary.TypeGroupListDTO;
import com.zeroone.star.project.dto.j3.sysmg.datadictionary.TypeGroupModifyDTO;
import com.zeroone.star.project.j3.sysmg.TypeGroupApis;
import com.zeroone.star.project.query.j3.sysmg.datadictionary.TypeGroupQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.sysmanager.service.TypeGroupService;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import lombok.extern.slf4j.Slf4j;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.*;

/**
 * @program: wms-java
 * @description: 字典分类接口实现
 * @author: Hao
 **/
@RestController
@RequestMapping("sysmanager/typegroup")
@Slf4j
@Api(tags = "字典分类接口实现")
public class TypeGroupController implements TypeGroupApis {
    @Autowired
    private TypeGroupService typeGroupService;

    @GetMapping("query")
    @ApiOperation(value="获取字典分类列表(条件+分页)")
    @Override
    public JsonVO<PageDTO<TypeGroupListDTO>> queryAll(TypeGroupQuery query) {
        log.info("分页查询数据:{}",query);
        PageDTO<TypeGroupListDTO> page = typeGroupService.list(query);
        return JsonVO.success(page);
    }

    @PostMapping("add")
    @ApiOperation(value="录入字典分类")
    @Override
    public JsonVO<String> addTypeGroup(@RequestBody TypeGroupAddDTO dto) {
        typeGroupService.save(dto);
        return JsonVO.success("录入成功");
    }

    @PutMapping("modify")
    @ApiOperation(value="修改字典分类")
    @Override
    public JsonVO<String> modifyTypeGroup(@RequestBody TypeGroupModifyDTO dto) {
        typeGroupService.update(dto);
        return JsonVO.success("修改成功");
    }

    @DeleteMapping("remove/{id}")
    @ApiOperation(value="删除字典分类")
    @Override
    public JsonVO<String> removeTypeGroup(@PathVariable String id) {
        typeGroupService.remove(id);
        return JsonVO.success("删除成功");
    }
}
