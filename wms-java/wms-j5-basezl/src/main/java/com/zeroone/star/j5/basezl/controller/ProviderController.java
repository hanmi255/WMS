package com.zeroone.star.j5.basezl.controller;

import com.zeroone.star.j5.basezl.service.IProviderService;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j5.basezl.provider.ProviderAddDTO;
import com.zeroone.star.project.dto.j5.basezl.provider.ProviderDetailDTO;
import com.zeroone.star.project.dto.j5.basezl.provider.ProviderListDTO;
import com.zeroone.star.project.dto.j5.basezl.provider.ProviderModifyDTO;
import com.zeroone.star.project.j5.basezl.ProviderApis;
import com.zeroone.star.project.query.j5.basezl.provider.ProviderQuery;
import com.zeroone.star.project.vo.JsonVO;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import lombok.extern.slf4j.Slf4j;
import org.springframework.http.ResponseEntity;
import org.springframework.validation.annotation.Validated;
import org.springframework.web.bind.annotation.*;
import org.springframework.web.multipart.MultipartFile;


import javax.annotation.Resource;
import java.util.ArrayList;
import java.util.List;


/**
 * 功能：
 * 作者：蕉太狼殿下
 * 日期：2025/2/23 14:29
 */
@RestController
@RequestMapping("provider")
@Api(tags = "供应商管理接口实现")
@Slf4j
public class ProviderController implements ProviderApis {
    @Resource
    private IProviderService service;

    @Override
    @ApiOperation("查询供应商信息列表")
    @GetMapping("query-all")
    public JsonVO<PageDTO<ProviderListDTO>> queryAll(@Validated ProviderQuery query) {
        log.info("pageIndex:{}",query.getPageIndex());
        log.info("pageSize:{}",query.getPageSize());
        return JsonVO.success(service.listAll(query));
    }

    @GetMapping("get-details-provider")
    @ApiOperation("获取供应商详细信息")
    @Override
    public JsonVO<ProviderDetailDTO> getDetailsProvider(String id) {
        return JsonVO.success(service.getDetails(id));
    }

    @PostMapping("add-provider")
    @ApiOperation("录入供应商")
    @Override
    public JsonVO<String> addProvider(@RequestBody ProviderAddDTO dto) {
        return JsonVO.success(service.addProvider(dto));
    }

    @PutMapping("change-provider")
    @ApiOperation("修改供应商")
    @Override
    public JsonVO<String> changeProvider(@RequestBody ProviderModifyDTO dto) {
        return JsonVO.success(service.changeProvider(dto));
    }
    @ApiOperation("删除供应商")
    @DeleteMapping("delete-provider")
    @Override
    public JsonVO<String> deleteProvider(@RequestParam List<String> providerIds) {
        boolean b = service.removeByIds(providerIds);
        if(b){
            return JsonVO.success("删除成功");
        }
        return JsonVO.fail("删除失败");
    }
    @ApiOperation("导入供应商")
    @PostMapping("upload")
    @Override
    public JsonVO<String> uploadProvider(MultipartFile file) {
        return service.upload(file);
    }
    @ApiOperation("导出供应商")
    @GetMapping(value = "export",produces = "application/octet-stream")
    @Override
    public ResponseEntity<byte[]> exportProvider(@RequestParam List<String> providerIds) {
        return service.export(providerIds);
    }

    @ApiOperation("获取企业属性")
    @GetMapping("provider-xingYeFenLei")
    @Override
    public JsonVO<List<String>> getXingYeFenLei(){
        ArrayList<String> res = new ArrayList<>();
        res.add("供应商");
        res.add("客户");
        return JsonVO.success(res);
    }

}
