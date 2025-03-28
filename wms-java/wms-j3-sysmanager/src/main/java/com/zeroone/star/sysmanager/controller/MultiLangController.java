package com.zeroone.star.sysmanager.controller;


import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j3.sysmg.multilang.MultiLangBaseDTO;
import com.zeroone.star.project.dto.j3.sysmg.multilang.MultiLangListDTO;
import com.zeroone.star.project.j3.sysmg.MultiLangApi;
import com.zeroone.star.project.query.j3.sysmg.multilang.MultiLangQuery;
import com.zeroone.star.project.dto.j3.sysmg.multilang.MultiLangBaseDTO;
import com.zeroone.star.project.dto.j3.sysmg.multilang.MultiLangListDTO;
import com.zeroone.star.project.j3.sysmg.MultiLangApi;
import com.zeroone.star.project.query.j3.sysmg.multilang.MultiLangQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.sysmanager.service.MultiLangService;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import io.swagger.annotations.ApiParam;
import lombok.extern.slf4j.Slf4j;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.*;

import static com.zeroone.star.sysmanager.constant.MultiLangConst.EXPIRE_TIME;

/**
 * @program: wms-java
 * @description: 国际化语言 控制器
 * @author: hamhuo
 **/
@Slf4j
@RestController
@RequestMapping("/sysmanager/lang")
@Api(tags = "国际化语言管理")
public class MultiLangController implements MultiLangApi {

    @Autowired
    private MultiLangService multiLangService;

    /**
     * 员工分页/条件查询
     * <p>
     允许数据不一致, 更新最大间隔10分钟
     * </p>
     * @param query 查询条件
     * @return JsonVO<PageDTO<MultiLangListDTO>> Json分页对象
     */
    @PostMapping("multilang")
    @Override
    @ApiOperation(value = "分页/条件查询")
    public JsonVO<PageDTO<MultiLangListDTO>> queryMultiLang(@ApiParam(value = "分页/条件查询参数") @RequestBody MultiLangQuery query) {
        log.info("语言对照分页/条件查询");
        PageDTO<MultiLangListDTO> result = multiLangService.listMultiLang(query);
        return JsonVO.success(result);
    }

    /**
     * 语言对照插入
     * @param multiLangBaseDTO 对照信息
     * @return 插入是否成功
     */
    @PostMapping("addlang")
    @Override
    @ApiOperation(value = "添加语言对照, 传入基础表单录入, 这里的id可以传入空值由后端分配")
    public JsonVO<String> addMultiLang(@ApiParam(value = "语言对照表单参数") @RequestBody MultiLangBaseDTO multiLangBaseDTO) {
        try {
            Boolean b = multiLangService.saveMultiLang(multiLangBaseDTO);
        }catch (Exception e){
            return JsonVO.fail(e.getMessage());
        }
        return JsonVO.success("插入成功");
    }

    /**
     * 语言对照更新
     * @param multiLangBaseDTO 对照信息
     * @return 语言对照更新
     */
    @PostMapping("updatelang")
    @Override
    @ApiOperation(value = "更新语言对照, 传入基础表单更新")
    public JsonVO<String> modifyMultiLang(@ApiParam(value = "语言对照表单参数") @RequestBody MultiLangBaseDTO multiLangBaseDTO) {
        try {
            if(multiLangService.updateMultiLang(multiLangBaseDTO)){
                return JsonVO.success("更新完成, 同步需要: " + EXPIRE_TIME/60 + "分钟");
            }else{
                return JsonVO.fail("系统已经存在该对照");
            }
        }catch (Exception e){
            return JsonVO.fail("更新失败" + e.getMessage());
        }
    }

    /**
     * 语言对照删除
     * @param id 唯一标识
     * @return 删除结果
     */
    @GetMapping("deletelang")
    @Override
    @ApiOperation(value = "删除语言对照, 传入语言对照id删除")
    public JsonVO<String> deleteMultiLang(@ApiParam(value = "语言对照唯一标识") @RequestParam String id) {
        return JsonVO.success(multiLangService.removeMultiLang(id));
    }


    /**
     * 手动刷新缓存
     * @return 结果
     */
    @GetMapping("refresh-cache")
    @Override
    @ApiOperation(value = "手动刷新, 没参数")
    public JsonVO<String> refreshCache() {
        return JsonVO.success(multiLangService.refreshCache());
    }
}