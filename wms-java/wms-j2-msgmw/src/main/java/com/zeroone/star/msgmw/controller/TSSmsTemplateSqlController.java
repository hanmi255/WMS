package com.zeroone.star.msgmw.controller;


import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.zeroone.star.msgmw.service.ITSSmsTemplateSqlService;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j2.msgmw.TSSmsTemplateSqlAddDTO;
import com.zeroone.star.project.dto.j2.msgmw.TSSmsTemplateSqlDTO;
import com.zeroone.star.project.j2.msgmw.TSSmsTemplateSqlApis;
import com.zeroone.star.project.query.j2.msgmw.TSSmsTemplateSqlQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.ResultStatus;
import com.zeroone.star.project.vo.j2.msgmw.TSSmsTemplateSqlVO;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import io.swagger.annotations.ApiParam;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.*;

import javax.validation.Valid;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Date;
import java.util.List;
import java.util.stream.Collectors;

/**
 * <p>
 * 消息模板配置 前端控制器
 * </p>
 *
 * @author qunzhong
 * @since 2025-02-21
 */
@RestController
@RequestMapping("/msgmw")
@Api(tags = "业务配置")
public class TSSmsTemplateSqlController implements TSSmsTemplateSqlApis {

    @Autowired
    private ITSSmsTemplateSqlService tSSmsTemplateSqlService;

    /**
     * 添加业务配置数据
     * @param templateSqlAddDTO 业务配置数据传输对象
     * @return 添加结果
     * @author qunzhong
     * @date 2025/2/22
     */
    @Override
    @PostMapping("/add")
    @ApiOperation(value = "录入业务配置")
    public JsonVO<String> add(@Valid @RequestBody TSSmsTemplateSqlAddDTO templateSqlAddDTO){
        try {
            tSSmsTemplateSqlService.add(templateSqlAddDTO);
            return JsonVO.success("泥成功添加业务配置数据");
        } catch (Exception e) {
            return JsonVO.create("添加业务配置失败: " + e.getMessage(), ResultStatus.SERVER_ERROR);
        }
    }

    /**
     * 查询业务配置数据
     * @param templateQuery 业务配置数据查询对象
     * @param page          当前页码
     * @param size          每页展示的条数
     * @return 业务配置数据列表
     * @author qunzhong
     * @date 2025/2/22
     */
    @Override
    @PostMapping("/query")
    @ApiOperation(value = "获取业务配置列表（条件+分页）")
    public JsonVO<PageDTO<TSSmsTemplateSqlVO>> query(
            @RequestBody(required = false) TSSmsTemplateSqlQuery templateQuery,
            @ApiParam(value = "页码,从请求行传", example = "1")
            @RequestParam(defaultValue = "1") int page,  // 默认为第 1 页
            @ApiParam(value = "每页展示的数据条数,从请求行传", example = "10")
            @RequestParam(defaultValue = "10") int size   // 默认为每页 10 条
    ){

        if (page < 1) {
            throw new IllegalArgumentException("页码必须 >= 1");
        }
        if (size < 1 || size > 100) {
            throw new IllegalArgumentException("每页条数必须在 1~100 之间");
        }
        // TODO: 实现业务逻辑，调用服务层，传入分页参数和查询条件
        if(templateQuery == null){
            templateQuery = new TSSmsTemplateSqlQuery();
        }
        PageDTO<TSSmsTemplateSqlVO> result = tSSmsTemplateSqlService.query(templateQuery, page, size);
        return JsonVO.success(result);
/*        // 创建假数据
        List<TSSmsTemplateSqlVO> fakeData = new ArrayList<>();

        TSSmsTemplateSqlVO fake1 = new TSSmsTemplateSqlVO();
        fake1.setId("4028b8815ddbca3a015ddbfc67d1000a");
        fake1.setCode("JKRQ01");
        fake1.setName("入库预约通知");
        fake1.setSqlId("1");
        fake1.setTemplateId("3");
        fake1.setCreateDate(new Date());

        TSSmsTemplateSqlVO fake2 = new TSSmsTemplateSqlVO();
        fake2.setId("4028b8815ddbca3a015ddbfc67d1000b");
        fake2.setCode("JKRQ02");
        fake2.setName("入库预约通知");
        fake2.setSqlId("2");
        fake2.setTemplateId("2");
        fake2.setCreateDate(new Date());

        fakeData.add(fake1);
        fakeData.add(fake2);

        Page<TSSmsTemplateSqlVO> fakePage = new Page<>();
        fakePage.setTotal(fakeData.size());
        fakePage.setRecords(fakeData);
        fakePage.setCurrent(1);
        fakePage.setSize(10);
        fakePage.setPages(1);

        PageDTO<TSSmsTemplateSqlVO> pageDTO = PageDTO.create(fakePage);

        return JsonVO.success(pageDTO);*/
    }

    /**
     * 修改业务配置数据
     * @param templateSqlDTO 业务配置数据传输对象
     * @return 修改结果
     * @author qunzhong
     * @date 2025/2/22
     */
    @Override
    @PutMapping("/update")
    @ApiOperation(value = "修改业务配置")
    public JsonVO<String> update(@Valid @RequestBody TSSmsTemplateSqlDTO templateSqlDTO){
        try {
            tSSmsTemplateSqlService.update(templateSqlDTO);
            return JsonVO.success("泥成功修改业务配置数据");
        } catch (Exception e) {
            return JsonVO.create("添加业务配置失败: " + e.getMessage(), ResultStatus.SERVER_ERROR);
        }
    }

    /**
     * 删除业务配置数据
     * @param  ids 所有要删除的id,用逗号分隔
     * @return 删除结果
     * @author qunzhong
     * @date 2025/2/22
     */
    @Override
    @DeleteMapping("/delete")
    @ApiOperation(value = "删除业务配置（支持批量）")
    public JsonVO<String> delete(@ApiParam(value = "业务配置的ID，多个则用逗号分隔",
            required = true, example = "123,456,789")
             @RequestParam String ids) {
        if (ids == null || ids.isEmpty()) {
            // 处理没有提供 ID 的情况
            return JsonVO.create("请选择要删除的对象", ResultStatus.PARAMS_INVALID);
        }
        // 拆分传递的 ID 字符串
        List<Long> idList = Arrays.stream(ids.split(","))
                .map(Long::parseLong)
                .collect(Collectors.toList());

        try {
            tSSmsTemplateSqlService.delete(idList);
            return JsonVO.success("泥成功删除业务配置数据");
        } catch (Exception e) {
            return JsonVO.create("删除业务配置失败: " + e.getMessage(), ResultStatus.SERVER_ERROR);
        }

    }


}

