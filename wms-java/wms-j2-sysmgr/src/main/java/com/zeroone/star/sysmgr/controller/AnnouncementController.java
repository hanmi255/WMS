package com.zeroone.star.sysmgr.controller;

import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j2.sysmgr.TSNoticeAddDTO;
import com.zeroone.star.project.dto.j2.sysmgr.TSNoticeDTO;
import com.zeroone.star.project.dto.j2.sysmgr.TSNoticeUpdateDTO;
import com.zeroone.star.project.j2.sysmgr.AnnouncementApis;
import com.zeroone.star.project.query.PageQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.sysmgr.entity.TSNotice;
import com.zeroone.star.sysmgr.service.TSNoticeService;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import io.swagger.annotations.ApiParam;
import lombok.SneakyThrows;
import org.springframework.web.bind.annotation.*;

import javax.annotation.Resource;
import javax.servlet.http.HttpServletRequest;
import java.util.List;

@RestController
@RequestMapping("/sysmgr/announcement")
@Api(tags = "系统公告相关接口")
public class AnnouncementController implements AnnouncementApis{
    @Resource
    private TSNoticeService tsNoticeService;

    @GetMapping("/page-anno")
    @ApiOperation("获取公告列表（分页）")
    public JsonVO getAnnouncementPage(PageQuery pageQuery) {

        try {
            PageDTO<TSNoticeDTO> announcementPage = tsNoticeService.getAnnouncementPage(pageQuery);
            JsonVO<PageDTO<TSNoticeDTO>> success = JsonVO.success(announcementPage);
            return success;
        } catch (Exception e) {
            return JsonVO.fail(e.toString());
        }


    }

    @GetMapping("/detail-anno")
    @ApiOperation("获取公告详细信息")
    public JsonVO getAnnouncementDetail(TSNoticeDTO dto) {

        try {
            TSNotice announcementDetail = tsNoticeService.getAnnouncementDetail(dto);
            return JsonVO.success(announcementDetail);
        } catch (Exception e) {

            String string = e.toString();
            return JsonVO.fail(string);


        }

    }

    @Override
    @PostMapping("/add")
    @ApiOperation(value = "录入公告接口")
    public JsonVO<Boolean> addNotice(@RequestBody TSNoticeAddDTO tsNoticeAddDTO) {
        if(tsNoticeAddDTO == null){
            return JsonVO.fail(false);
        }
        Boolean save = tsNoticeService.addNotice(tsNoticeAddDTO);
        return JsonVO.success(save);
    }

    @Override
    @PostMapping("/update")
    @ApiOperation(value = "修改公告接口")
    public JsonVO<Boolean> updateNotice(@RequestBody TSNoticeUpdateDTO tsNoticeUpdateDTO) {
        if (tsNoticeUpdateDTO == null){
            return JsonVO.fail(false);
        }
        Boolean updated = tsNoticeService.updateNotice(tsNoticeUpdateDTO);
        return JsonVO.success(updated);
    }

    @Override
    @PostMapping("/deleteBatch")
    @ApiOperation(value = "删除公告（支持批量删除）接口")
    public JsonVO<Boolean> deleteBatchNotice(@RequestBody @ApiParam("公告id列表") List<String> ids) {
        if (ids == null){
            return JsonVO.fail(false);
        }
        Boolean deleted = tsNoticeService.deleteBatchNotice(ids);
        return JsonVO.success(deleted);
    }
}
