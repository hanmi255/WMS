package com.zeroone.star.stockln.controller;

import com.zeroone.star.project.j6.stockln.AcceptApis;
import com.zeroone.star.project.dto.j6.stockln.AcceptRequestDTO;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.stockln.service.AcceptService;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.*;

/**
 * 描述：验收操作的控制器层
 * 处理来自前端的验收请求
 */
@RestController
@RequestMapping("/stock/bulk_receipt/acceptance")
@Api(tags = "批量验收")
public class AcceptController implements AcceptApis {

    @Autowired
    private AcceptService acceptService;  // 注入服务层

    /**
     * 提交验收数据
     * 该方法会调用服务层处理验收操作
     * @param id 待验收货物的ID
     * @param requestDTO 包含待验收货物的详细信息及用户填写的字段
     * @return 验收操作是否成功
     */
    @Override
    @PutMapping("/items/{id}/accept")
    @ApiOperation(value = "验收货物", notes = "根据 ID 进行验收")
    public JsonVO<String> acceptItem(@PathVariable String id, @RequestBody AcceptRequestDTO requestDTO) {
        // 调用服务层处理验收操作
        boolean success = acceptService.processAcceptance(requestDTO);

        if (success) {
            return JsonVO.success("验收成功");
        } else {
            return JsonVO.fail("验收失败");
        }
    }
}
