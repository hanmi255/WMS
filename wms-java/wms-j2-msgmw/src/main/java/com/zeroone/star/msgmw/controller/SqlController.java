package com.zeroone.star.msgmw.controller;

import com.zeroone.star.msgmw.service.SqlService;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j2.msgmw.SQL.*;
import com.zeroone.star.project.j2.msgmw.SQL.SqlApis;
import com.zeroone.star.project.query.j2.msgmw.SQL.SqlQuery;
import com.zeroone.star.project.vo.JsonVO;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import lombok.extern.slf4j.Slf4j;
import org.springframework.validation.annotation.Validated;
import org.springframework.web.bind.annotation.*;
import javax.annotation.Resource;
import java.util.List;

@RestController
@RequestMapping("/msgmw")
@Api(tags = "业务SQL")
@Slf4j
public class SqlController implements SqlApis {

    @Resource
    private SqlService sqlService;

    /**
     * 获取SQL列表(条件+分页)
     * @param sqlQuery 查询条件
     * @return
     */
    @GetMapping("/query-sql-list")
    @ApiOperation(value = "获取SQL列表(条件+分页)")
    @Override
    public JsonVO<PageDTO<SqlListDTO>> queryAll(@Validated SqlQuery sqlQuery) {
        PageDTO<SqlListDTO> sqlList = sqlService.listSqlList(sqlQuery);
        return JsonVO.success(sqlList);
    }

    /**
     * 获取SQL名称列表
     * @return
     */
    @GetMapping("/query-sql-name-list")
    @ApiOperation(value = "获取SQL名称列表")
    @Override
    public JsonVO<List<SqlNameListDTO>> querySqlNameList() {
        List<SqlNameListDTO> sqlNameList = sqlService.listSqlNameList();
        return JsonVO.success(sqlNameList);
    }


    /**
     * 录入SQL
     * @param sqlAddDTO SQL信息
     * @return
     */

    @PostMapping("/add-sql")
    @ApiOperation(value = "录入SQL")
    @Override
    public JsonVO<String> addSql(@RequestBody SqlAddDTO sqlAddDTO) {
        boolean result = sqlService.saveSql(sqlAddDTO);
        if (result) {
            return JsonVO.success("SQL录入成功");
        } else {
            return JsonVO.fail("SQL录入失败");
        }
    }

    /**
     * 修改SQL
     * @param sqlModifyDTO SQL修改信息
     * @return
     */
    @PutMapping("/modify-sql")
    @ApiOperation(value = "修改SQL")
    public JsonVO<String> modifySql(@RequestBody SqlModifyDTO sqlModifyDTO) {
        boolean result = sqlService.updateSql(sqlModifyDTO);
        if (result) {
            return JsonVO.success("SQL 修改成功");
        } else {
            return JsonVO.fail("SQL 修改失败");
        }
    }

    /**
     * 删除SQL
     * @param sqlDeleteDTO SQL删除信息（包含单个ID或ID列表）
     * @return
     */
    @DeleteMapping("/remove-sql")
    @ApiOperation(value = "删除SQL")
    @Override
    public JsonVO<String> removeSql(@RequestBody SqlDeleteDTO sqlDeleteDTO) {
        log.info("Received SqlDeleteDTO: {}", sqlDeleteDTO);
        boolean result = sqlService.removeSql(sqlDeleteDTO);
        if (result) {
            return JsonVO.success("SQL 删除成功");
        } else {
            return JsonVO.fail("SQL 删除失败");
        }
    }
}