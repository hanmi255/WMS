package com.zeroone.star.stockln.controller;


import cn.hutool.core.bean.BeanUtil;
import cn.hutool.json.JSONUtil;
import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.baomidou.mybatisplus.core.conditions.update.UpdateWrapper;

import com.zeroone.star.project.components.fastdfs.FastDfsClientComponent;
import com.zeroone.star.project.components.fastdfs.FastDfsFileInfo;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j6.stockln.ImportNoticeDetailHeadDTO;
import com.zeroone.star.project.dto.j6.stockln.ImportNoticeListDTO;
import com.zeroone.star.project.dto.j6.stockln.ImportNoticeDTO;
import com.zeroone.star.project.dto.j6.stockln.ImportNoticeItemDTO;
import com.zeroone.star.project.j6.stockln.ImNoticeHApis;
import com.zeroone.star.project.query.j6.stockln.ImportNoticeQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.stockln.entity.ImNoticeH;
import com.zeroone.star.stockln.entity.ImNoticeI;
import com.zeroone.star.stockln.service.*;
import com.zeroone.star.stockln.service.impl.ImNoticeHServiceImpl;
import com.zeroone.star.stockln.service.impl.ImNoticeIServiceImpl;
import com.zeroone.star.stockln.service.impl.ImNoticeServiceImpl;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiModelProperty;
import io.swagger.annotations.ApiOperation;
import lombok.SneakyThrows;
import lombok.extern.slf4j.Slf4j;
import org.springframework.beans.factory.annotation.Value;
import org.springframework.http.HttpHeaders;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.*;
import org.springframework.web.multipart.MultipartFile;

import javax.annotation.Resource;
import java.io.UnsupportedEncodingException;
import java.net.URLEncoder;
import java.nio.charset.StandardCharsets;
import java.util.Iterator;
import java.util.LinkedList;
import java.util.List;

@Api(tags = "入库通知单管理")
@RestController
@RequestMapping("/stock/imNotice-manage")
@Slf4j
public class ImNoticeHController implements ImNoticeHApis  {

    @Resource
    private IImNoticeHService imNoticeHService;
    @Resource
    private IImNoticeIService imNoticeIService;
    @Resource
    private IImNoticeService imNoticeService;

    @Resource
    IWmImNoticeHService iWmImNoticeHService;

    @Resource
    FastDfsClientComponent dfs;

    @Value("${fastdfs.nginx-servers}")
    private String fileServerUrl;

    @Resource
    IWmImNoticeIService iWmImNoticeIService;


    /**
     * 查询入库通知单列表
     * @param query 查询条件
     * @return 响应数据结果
     */
    @ApiOperation("查询入库通知单列表")
    @GetMapping("/list")
    public JsonVO<PageDTO<ImportNoticeListDTO>> list(ImportNoticeQuery query) {
        log.info("查询入库通知单列表 {}",query);
        return JsonVO.success(iWmImNoticeHService.listAll(query));
    }

    /**
     * 根据Id查询单个预约通知单详细信息
     * @param imNoticeId
     * @return
     */
    @GetMapping("/detail/{imNoticeId}")
    @ApiOperation("单个预约通知单详细信息")
    public JsonVO<ImportNoticeDTO> getDetailsById(@PathVariable String imNoticeId) {
        log.info("查询单个预约通知单详细信息 {}",imNoticeId);
//        return JsonVO.success(iWmImNoticeIService.getDetailsById(imNoticeId));
        return JsonVO.success(imNoticeService.searchImport(imNoticeId));
    }



    /**
     * 上传附件
     * @param file
     * @return 响应数据结果，地址
     */
    @SneakyThrows
    @PostMapping("/upload")
    @ApiOperation("上传附件")
    public JsonVO<String> upload(@RequestBody MultipartFile file) throws Exception {
        String filename = file.getOriginalFilename();
        assert filename != null;
        String suffix = filename.substring(filename.lastIndexOf(".") + 1);
        FastDfsFileInfo fastDfsFileInfo = dfs.uploadFile(file.getBytes(), suffix);
        if (fastDfsFileInfo != null) {
            return JsonVO.success(dfs.fetchUrl(fastDfsFileInfo, fileServerUrl, true));
        }
        return JsonVO.fail(null);
    }


    @ApiOperation("完成入库单")
    @PostMapping("/confirm")
    public JsonVO<Object> confirmImport(String notice_id) {
        imNoticeHService.update(new UpdateWrapper<ImNoticeH>()
                .set("im_sta" ,"已完成")
                .eq("notice_id",notice_id));
        return JsonVO.success("成功");
    }

    @ApiOperation("修改入库单")
    @PostMapping("/update")
    public JsonVO<Object> updateImport(@RequestBody ImportNoticeDTO importNoticeDTO) {
        imNoticeService.updateImport(importNoticeDTO);
        return JsonVO.success("成功");
    }

    @ApiOperation("删除入库单")
    @PostMapping("/delete")
    public JsonVO<Object> deleteImport(String  noticeId) {
        imNoticeHService.remove(new QueryWrapper<ImNoticeH>()
                .eq("notice_id",noticeId)
        );
        imNoticeIService.remove(new QueryWrapper<ImNoticeI>()
                .eq("im_notice_id",noticeId)
        );
        return JsonVO.success("成功");
    }

    @ApiOperation("录入入库单")
    @PostMapping("/insert")
    @Override
    public JsonVO<Object> insertImport(@RequestBody ImportNoticeDTO importNoticeDTO) {
        imNoticeService.insertImport(importNoticeDTO);
        return JsonVO.success("成功");
    }

    //为什么用流不行，用字节码可以;
    @ApiOperation("导出入库单")
    @GetMapping("/export")
    public ResponseEntity export(String id){
        return imNoticeService.export(id);
    }

}
