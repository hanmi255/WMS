package com.zeroone.star.stockln.controller;

import com.zeroone.star.project.dto.j6.stockln.ToListUpdateDTO;
import com.zeroone.star.project.j6.stockln.ToListApis;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.stockln.service.ToListService;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.*;

/**
 * <p>
 * 描述：待上架货物相关控制器
 * </p>
 *
 * @author []
 * @version 1.0.0
 */
@RestController
@RequestMapping("/stock/tolist")
@Api(tags = "收货登记")
public class ToListController implements ToListApis {

    @Autowired
    private ToListService toListService;

    /**
     * 修改待上架货物信息
     * @param updateDTO 需要修改的信息
     * @return 修改结果
     */
    @PutMapping("/update")
    @ApiOperation(value = "修改待上架货物信息Susu版")
    public JsonVO<String> updateToList(@RequestBody ToListUpdateDTO updateDTO) {
        boolean success = toListService.updateToList(updateDTO);
        return success ? JsonVO.success("修改成功") : JsonVO.fail("修改失败");
    }
}
