package com.zeroone.star.j5.basezl.controller;

import com.zeroone.star.j5.basezl.service.CusOtherService;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j5.basezl.cusother.CusOtherAddDTO;
import com.zeroone.star.project.dto.j5.basezl.cusother.CusOtherListDTO;
import com.zeroone.star.project.dto.j5.basezl.cusother.CusOtherModifyDTO;
import com.zeroone.star.project.j5.basezl.CusOtherApis;
import com.zeroone.star.project.query.j5.basezl.cusother.CusOtherQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.j5.basezl.CusOtherVO;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.*;
import org.springframework.web.multipart.MultipartFile;

import java.util.List;

/**
 * <p>
 * 描述: 第三方客户相关接口实现
 * </p>
 * <p>版权所有: &copy;枢璇</p>
 *
 * @author 枢璇
 * @Version 1.0.0
 * @since 2025/2/23 12:09
 */
@RestController
@RequestMapping("/cus-other")
@Api(tags = "第三方客户相关接口实现")
public class CusOtherController implements CusOtherApis {
    @Autowired
    private CusOtherService service;

    @GetMapping("query-all")
    @ApiOperation(value = "获取第三方客户列表接口")
    @Override
    public JsonVO<PageDTO<CusOtherListDTO>> queryAll(CusOtherQuery query) {
        return JsonVO.success(service.listCusOther(query));
    }

    @GetMapping("query-one")
    @ApiOperation(value = "获取客户编码对应的第三方客户的详细信息")
    @Override
    public JsonVO<CusOtherVO> queryOne(String keHuBianMa) {
        return JsonVO.success(service.getCusOtherDetail(keHuBianMa));
    }

    @PostMapping ("add-cus")
    @ApiOperation(value = "录入第三方客户记录")
    @Override
    public JsonVO<String> addCusOther(@RequestBody CusOtherAddDTO dto) {
        return JsonVO.success(service.saveCusOther(dto));
    }

    @DeleteMapping ("remove-cus")
    @ApiOperation(value = "移除第三方客户记录")
    @Override
    public JsonVO<String> removeCusOther(@RequestParam("ids") List<String> ids) {
        service.removeByBianMa(ids);
        return JsonVO.success(null);
    }

    @PostMapping ("modify-cus")
    @ApiOperation(value = "修改第三方客户记录")
    @Override
    public JsonVO<String> modifyCusOther(@RequestBody CusOtherModifyDTO dto) {
        return JsonVO.success(service.updateCusOther(dto));
    }

    @PostMapping("upload")
    @ApiOperation(value = "导入第三方客户记录")
    @Override
    public JsonVO<String> uploadCusOther(@RequestBody MultipartFile file) {
        service.upload(file);
        return JsonVO.success(null);
    }

    @GetMapping(value = "export",produces = "application/octet-stream")
    @ApiOperation(value = "导出第三方客户Excel表格")
    @Override
    public ResponseEntity<byte[]> exportCusOther(@RequestParam(value = "ids", required = false, defaultValue = "") List<String> ids) {
        ResponseEntity<byte[]> data = service.export(ids);
        return data;
    }

}
