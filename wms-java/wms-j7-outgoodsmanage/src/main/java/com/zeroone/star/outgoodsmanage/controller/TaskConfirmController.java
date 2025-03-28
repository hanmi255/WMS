package com.zeroone.star.outgoodsmanage.controller;


import com.zeroone.star.outgoodsmanage.channel.RmqPublish;
import com.zeroone.star.outgoodsmanage.service.TaskConfirmService;
import com.zeroone.star.project.dto.j7.taskconfirm.*;
import com.zeroone.star.project.query.j7.taskconfirm.OutboundTaskQuery;
import com.zeroone.star.outgoodsmanage.service.impl.WmOmQmIServiceImpl;
import com.zeroone.star.project.components.easyexcel.EasyExcelComponent;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.j7.taskconfirm.TaskConfirmApis;
import com.zeroone.star.project.j7.taskconfirm.WmOmQmlApis;
import com.zeroone.star.project.vo.JsonVO;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import lombok.SneakyThrows;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.beans.factory.annotation.Qualifier;
import org.springframework.web.bind.annotation.*;

import java.util.List;


/**
 * <p>
 * 描述：任务确认控制器
 * </p>
 *
 * @author LLy
 * @since 2025/2/23
 */
@RestController
@RequestMapping("/task-confirm/")
@Api(tags = "任务确认相关接口")
public class TaskConfirmController implements WmOmQmlApis, TaskConfirmApis {


    @Autowired
    WmOmQmIServiceImpl wmOmQmIService;
    @Autowired
    EasyExcelComponent easyExcelComponent;
    @Autowired
    TaskConfirmService taskConfirmService;
    @Qualifier("rmqPublish")
    @Autowired
    private RmqPublish rmqPublish;

    @ApiOperation(value = "获取出库任务列表（条件+分页）")
    @GetMapping(value = "query-all")
    public JsonVO<PageDTO<OutboundTaskDTO>> queryAll(OutboundTaskQuery outboundTaskQuery) {
        return JsonVO.success(wmOmQmIService.queryAll(outboundTaskQuery));
    }
    @PostMapping("modify-task")
    @ApiOperation(value = "修改任务")
    public JsonVO<ModifyTaskDTO> modifyTask(@RequestBody ModifyTaskDTO modifyTaskDTO) {
        taskConfirmService.modifyTask(modifyTaskDTO);
        return JsonVO.success(modifyTaskDTO);
    }

    @PostMapping("batch-confirmation")
    @ApiOperation(value = "批量设置接收人")
    public JsonVO<Integer> batchSetRecipients(@RequestParam List<String> ids, @RequestParam String receiverName) {
        int state = taskConfirmService.batchSetReceiver(ids, receiverName);
        return JsonVO.success(state);
    }

    @PostMapping("confirm-task")
    @ApiOperation(value = "确认任务(支持批量)")
    public JsonVO<Integer> batchConfirmation(@RequestParam List<String> ids) {
        int state= taskConfirmService.batchConfirmTask(ids);
        return JsonVO.success(state);
    }

    @PostMapping("wave")
    @ApiOperation(value="波次生成")
    public JsonVO waveGene(@RequestBody WaveGenDTO ids){
        wmOmQmIService.genWave(ids);
        return JsonVO.success("生成波次成功");
    }

    @PostMapping("del")
    @ApiOperation(value="删除任务")
    public JsonVO rmMission(@RequestBody WaveGenDTO ids) {
        wmOmQmIService.delMission(ids);
        return JsonVO.success("删除任务成功");
    }

    @SneakyThrows
    @ApiOperation(value = "导出所有任务")
    @GetMapping(value = "export")
    public JsonVO<String> expoExcel(){
        rmqPublish.publish("all");
        return JsonVO.success("已向所有请求该文件的成功建立websocket连接的用户发送fastdfs文件地址");
    }
}
