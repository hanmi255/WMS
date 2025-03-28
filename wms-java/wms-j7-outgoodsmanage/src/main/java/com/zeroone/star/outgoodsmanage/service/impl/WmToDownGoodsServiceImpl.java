package com.zeroone.star.outgoodsmanage.service.impl;


import cn.hutool.core.util.StrUtil;
import com.alibaba.excel.EasyExcel;
import com.alibaba.excel.ExcelWriter;
import com.alibaba.excel.write.builder.ExcelWriterBuilder;
import com.alibaba.excel.write.handler.WorkbookWriteHandler;
import com.alibaba.excel.write.metadata.WriteSheet;
import com.alibaba.excel.write.metadata.holder.WriteWorkbookHolder;
import com.alibaba.excel.write.style.HorizontalCellStyleStrategy;
import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.baomidou.mybatisplus.core.metadata.IPage;
import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.outgoodsmanage.entity.MvCus;
import com.zeroone.star.outgoodsmanage.entity.WmToDownGoods;
import com.zeroone.star.outgoodsmanage.mapper.MvCusMapper;
import com.zeroone.star.outgoodsmanage.mapper.WmToDownGoodsMapper;
import com.zeroone.star.outgoodsmanage.service.IWmToDownGoodsService;
import com.zeroone.star.outgoodsmanage.util.ExcelStyleUtils;
import com.zeroone.star.project.components.easyexcel.EasyExcelComponent;
import com.zeroone.star.project.components.user.UserDTO;
import com.zeroone.star.project.components.user.UserHolder;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j7.adpick.AdPickExportDTO;
import com.zeroone.star.project.dto.j7.adpick.AdPickModifyBaseDTO;
import com.zeroone.star.project.dto.j7.adpick.AdPickModifyDTO;
import com.zeroone.star.project.dto.j7.adpick.AdPickPageDTO;
import com.zeroone.star.project.dto.j7.downgoods.DownGoodsDTO;
import com.zeroone.star.project.dto.j7.zccheck.CheckListDTO;
import com.zeroone.star.project.query.j7.adpick.AdPickQuery;
import com.zeroone.star.project.query.j7.zccheck.ZcCheckQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.j7.adPick.AdPickDeatilVO;
import com.zeroone.star.project.vo.j7.adPick.AdPickVO;
import org.apache.poi.ss.usermodel.*;
import com.alibaba.nacos.client.naming.utils.CollectionUtils;
import org.apache.poi.ss.util.CellRangeAddress;
import org.mapstruct.Mapper;
import org.springframework.beans.BeanUtils;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.http.*;
import org.springframework.stereotype.Service;
import org.springframework.transaction.annotation.Transactional;

import java.util.ArrayList;
import javax.annotation.Resource;
import java.io.ByteArrayOutputStream;
import java.io.IOException;
import java.io.OutputStream;
import java.util.List;
import java.util.Map;
import java.util.Set;
import java.util.stream.Collectors;

/**
 * <p>
 * 商品下架 服务实现类
 * </p>
 *
 * @author rocklin
 * @since 2025-02-23
 */
@Service
public class WmToDownGoodsServiceImpl extends ServiceImpl<WmToDownGoodsMapper, WmToDownGoods> implements IWmToDownGoodsService {

    @Resource
    WmToDownGoodsMapper wmToDownGoodsMapper;
    @Autowired
    private MvCusMapper mvCusMapper;


    @Resource
    EasyExcelComponent easyExcelComponent;

    @Override
    public JsonVO<AdPickDeatilVO> setectOneDeatil(String id) {
        WmToDownGoods wmToDownGoods = wmToDownGoodsMapper.selectById(id);
        AdPickDeatilVO adPickDeatilVO=new AdPickDeatilVO();
        BeanUtils.copyProperties(wmToDownGoods,adPickDeatilVO);
        return JsonVO.success(adPickDeatilVO);
    }

    @Override
    public JsonVO<PageDTO<AdPickVO>> selectPage(AdPickPageDTO adPickPageDTO) {
        System.out.println("查询参数："+adPickPageDTO);
        IPage<WmToDownGoods> page = new Page<>();
        page.setCurrent(adPickPageDTO.getPageIndex());
        page.setSize(adPickPageDTO.getPageSize());
        QueryWrapper<WmToDownGoods> queryWrapper = new QueryWrapper<>();
        queryWrapper
                .eq(adPickPageDTO.getOrderId() != null, "order_id", adPickPageDTO.getOrderId())
                .eq(adPickPageDTO.getGoodsId() != null, "goods_id", adPickPageDTO.getGoodsId())
                .eq(adPickPageDTO.getGoodsName() != null, "goods_name", adPickPageDTO.getGoodsName())
                .eq(adPickPageDTO.getImCusCode() != null, "im_cus_code", adPickPageDTO.getImCusCode())
                .eq(adPickPageDTO.getOmBeiZhu() != null, "om_bei_zhu", adPickPageDTO.getOmBeiZhu())
                .eq(adPickPageDTO.getCusCode() != null, "cus_code", adPickPageDTO.getCusCode())
                .eq(adPickPageDTO.getBinIdTo() != null, "bin_id_to", adPickPageDTO.getBinIdTo())
                .eq(adPickPageDTO.getBinIdFrom()!=null, "bin_id_from", adPickPageDTO.getBinIdFrom());
        System.out.println("查询条件："+queryWrapper.getSqlSegment());
        Page<WmToDownGoods> wmToDownGoodsIPage = (Page<WmToDownGoods>) wmToDownGoodsMapper.selectPage(page, queryWrapper);
        List<WmToDownGoods> records = wmToDownGoodsIPage.getRecords();
//
        System.out.println("查询记录数："+records);
//        获取所有号主的编码：
        Set<String> cusCodes = records.stream()
                .map(wmToDownGoods -> wmToDownGoods.getCusCode())
                .collect(Collectors.toSet());
        System.out.println("货主编码："+cusCodes);
//        拿到相关货主的姓名
        QueryWrapper<MvCus> queryMvCusWrapper = new QueryWrapper<>();
        queryMvCusWrapper.in("cus_code", cusCodes);
        System.out.println("测试的sql语句：======="+queryMvCusWrapper.getSqlSegment());
        List<MvCus> mvCusInfo = mvCusMapper.selectList(queryMvCusWrapper);
        Map<String, String> cusNames = mvCusInfo
                .stream()
                .collect(Collectors.toMap(MvCus::getCusCode, MvCus::getCusName));

//        把分页查询的WmToDownGoods转化为AdPickVO
        List<AdPickVO> collect = records.stream().map(wmToDownGoods -> {
            AdPickVO adPickVO = new AdPickVO();
            adPickVO.setOrderId(wmToDownGoods.getOrderId());
            adPickVO.setGoodsId(wmToDownGoods.getGoodsId());
            adPickVO.setGoodsName(wmToDownGoods.getGoodsName());
            adPickVO.setImCusCode(wmToDownGoods.getImCusCode());
            adPickVO.setOmBeiZhu(wmToDownGoods.getOmBeiZhu());
            adPickVO.setGoodsQua(wmToDownGoods.getGoodsQua());
            adPickVO.setGoodsQuaok(wmToDownGoods.getGoodsQuaok());
            adPickVO.setBaseGoodscount(wmToDownGoods.getBaseGoodscount());
            adPickVO.setBaseUnit(wmToDownGoods.getBaseUnit());
            adPickVO.setGoodsProData(wmToDownGoods.getGoodsProData());
            adPickVO.setBinIdFrom(wmToDownGoods.getBinIdFrom());
            adPickVO.setKuWeiBianMa(wmToDownGoods.getKuWeiBianMa());
            adPickVO.setCusCode(wmToDownGoods.getCusCode());
            adPickVO.setCusName(cusNames.get(wmToDownGoods.getCusCode()));
            return adPickVO;
        }).collect(Collectors.toList());
//        创建adpickVO 的page分页
        Page<AdPickVO> adPickVOPage = new Page();
        adPickVOPage.setCurrent(wmToDownGoodsIPage.getCurrent());
        adPickVOPage.setSize(wmToDownGoodsIPage.getSize());
        adPickVOPage.setTotal(wmToDownGoodsIPage.getTotal());
        adPickVOPage.setPages(wmToDownGoodsIPage.getPages());
        adPickVOPage.setRecords(collect);


        return JsonVO.success(PageDTO.create(adPickVOPage));
    }

    // 批量修改下架商品信息
    @Override
    public int batchUpdateDownGoods(List<DownGoodsDTO> downGoodsDTOList) {
        return wmToDownGoodsMapper.batchUpdateDownGoods(downGoodsDTOList);
    }

    // 下架商品
    @Override
    public int downGoods(List<String> ids) {
        return wmToDownGoodsMapper.downGoods(ids);
    }

    // 删除下架任务
    @Override
    public int removeDownGoods(String id) {
        return wmToDownGoodsMapper.deleteDownGoods(id);
    }


    //导出下架数据
    @Override
    public ResponseEntity<byte[]> exportDownGoods(List<String> ids) {
        ByteArrayOutputStream outputStream = new ByteArrayOutputStream();
        ResponseEntity<byte[]> responseEntity = null;
        try {
            if (ids.size() != 0) {
                //首先将数据从数据库查询出来
                List<WmToDownGoods> wmToDownGoods = wmToDownGoodsMapper.selectBatchIds(ids);
                export("下架任务", outputStream, WmToDownGoods.class, wmToDownGoods);

                HttpHeaders httpHeaders = new HttpHeaders();
                httpHeaders.setContentType(MediaType.parseMediaType("application/vnd.ms-excel"));
                // 设置文件名
                ContentDisposition contentDisposition = ContentDisposition.builder("attachment")
                        .filename("下架任务.xls", java.nio.charset.StandardCharsets.UTF_8)
                        .build();
                httpHeaders.setContentDisposition(contentDisposition);

                byte[] byteArray = outputStream.toByteArray();
                responseEntity = new ResponseEntity<>(byteArray, httpHeaders, HttpStatus.CREATED);


            }
        } catch (Exception e) {
            e.printStackTrace();
        } finally {
            try {
                //关闭流
                outputStream.close();
            } catch (IOException e) {
                throw new RuntimeException(e);
            }

        }

        return responseEntity;

    }

    private static final int MAX_COUNT_PER_SHEET = 5000;
    @Resource
    private UserHolder userHolder;


    /**
     * 导出到输出流
     *
     * @param sheetName sheet名称
     * @param os        输出流
     * @param clazz     导出数据类型
     * @param dataList  导出的数据集
     * @param <T>       生成元素实体类类型
     * @throws IOException IO异常
     */
    private <T> void export(String sheetName, OutputStream os, Class<T> clazz, List<T> dataList) throws IOException {
        HorizontalCellStyleStrategy horizontalCellStyleStrategy = new HorizontalCellStyleStrategy(ExcelStyleUtils.getHeadStyle(), ExcelStyleUtils.getContentStyle());

        //通过工具类设置表头样式
        ExcelWriterBuilder builder = EasyExcel.write(os, clazz).registerWriteHandler(
                        new WorkbookWriteHandler() {

                            public void afterWorkbookDispose(WriteWorkbookHolder writeWorkbookHolder) {
                                // 获取当前 Sheet
                                Sheet sheet = writeWorkbookHolder.getWorkbook().getSheetAt(0);

                                // 创建标题行
                                Row titleRow = sheet.createRow(0);
                                Cell titleCell = titleRow.createCell(0);

                                String username = null;
                                try {
                                    UserDTO currentUser = userHolder.getCurrentUser();
                                    username = currentUser.getUsername();
                                } catch (Exception e) {
                                    username = "管理人";
                                }

                                //创建管理人行
                                Row secondRow = sheet.createRow(1);
                                Cell secondCell = secondRow.createCell(0);
                                secondCell.setCellValue("导出人:" + username);

                                //设置第二行的样式
                                CellStyle secondStyle = sheet.getWorkbook().createCellStyle();
                                Font secondFront = sheet.getWorkbook().createFont();
                                secondFront.setFontName("Arial");
                                secondFront.setFontHeightInPoints((short) 10);
                                secondStyle.setFont(secondFront);
                                secondStyle.setAlignment(HorizontalAlignment.RIGHT);
                                secondCell.setCellStyle(secondStyle);

                                // 设置标题内容和样式
                                titleCell.setCellValue("下架任务导出列表");
                                CellStyle titleStyle = sheet.getWorkbook().createCellStyle();
                                Font titleFont = sheet.getWorkbook().createFont();
                                titleFont.setFontName("Arial");
                                titleFont.setBold(true); // 加粗
                                titleFont.setFontHeightInPoints((short) 12); // 字体大小
                                titleStyle.setFont(titleFont);
                                titleStyle.setAlignment(HorizontalAlignment.CENTER); // 居中
                                titleCell.setCellStyle(titleStyle);

                                // 合并单元格（如果需要）
                                sheet.addMergedRegion(new CellRangeAddress(0, 0, 0, 27)); // 合并第 1 行的第 1 列到第 28 列
                                sheet.addMergedRegion(new CellRangeAddress(1, 1, 0, 27));


                            }
                        }
                )

                .registerWriteHandler(horizontalCellStyleStrategy);


        ExcelWriter writer = builder.build();
        //计算总页数
        int sheetCount = dataList.size() / MAX_COUNT_PER_SHEET;
        sheetCount = dataList.size() % MAX_COUNT_PER_SHEET == 0 ? sheetCount : sheetCount + 1;
        //循环构建分页


        for (int i = 0; i < sheetCount; i++) {
            //创建一个页签
            WriteSheet sheet = new WriteSheet();
            sheet.setSheetNo(i);
            sheet.setSheetName(sheetName + (i + 1));
            //设置数据起始位置
            int start = i * MAX_COUNT_PER_SHEET;
            int end = (i + 1) * MAX_COUNT_PER_SHEET;
            end = Math.min(end, dataList.size());

            //从第三行开始写数据
            sheet.setRelativeHeadRowIndex(2);

            //写入数据到页签
            writer.write(dataList.subList(start, end), sheet);


        }
        writer.finish();
        os.close();
    }

    @Autowired
    MsZcCheckMapper msZcCheckMapper;

    /**
     * 装车复核分页+条件查询
     * @param query 查询条件
     * @return PageDTO<CheckListDTO> 查询结果
     */
    @Override
    public PageDTO<CheckListDTO> queryAll(ZcCheckQuery query) {
        //分页对象
        Page<WmToDownGoods> page = new Page<>(query.getPageIndex(), query.getPageSize());
        //查询条件
        QueryWrapper<WmToDownGoods> wrapper = new QueryWrapper<>();
        if(StrUtil.isNotBlank(query.getOrderId())){
            wrapper.like("order_id", query.getOrderId());
        }
        if(StrUtil.isNotBlank(query.getGoodsId())){
            wrapper.like("goods_id", query.getGoodsId());
        }
        if(StrUtil.isNotBlank(query.getGoodsName())){
            wrapper.like("goods_name", query.getGoodsName());
        }
        if(StrUtil.isNotBlank(query.getImCusCode())){
            wrapper.like("im_cus_code", query.getImCusCode());
        }
        if(StrUtil.isNotBlank(query.getOmBeiZhu())){
            wrapper.like("om_bei_zhu", query.getOmBeiZhu());
        }
        if(StrUtil.isNotBlank(query.getBinIdFrom())){
            wrapper.like("bin_id_from", query.getBinIdFrom());
        }
        if(StrUtil.isNotBlank(query.getKuWeiBianMa())){
            wrapper.like("ku_wei_bian_ma", query.getKuWeiBianMa());
        }
        if(StrUtil.isNotBlank(query.getCusCode())){
            wrapper.like("cus_code", query.getCusCode());
        }
        if(StrUtil.isNotBlank(query.getBinIdTo())){
            wrapper.like("bin_id_to", query.getBinIdTo());
        }
        //查询结果
        Page<WmToDownGoods> ps = baseMapper.selectPage(page, wrapper);
        return PageDTO.create(ps, msZcCheckMapper::WmToDownGoodsToCheckListDTO);
    }


    @Override
    public boolean modifyAdPick(AdPickModifyDTO adPickModifyDTO) {
        int affectedRows = wmToDownGoodsMapper.updateByGoodsAndOrder(adPickModifyDTO);
        return affectedRows > 0;
    }
    @Override
    @Transactional(rollbackFor = Exception.class)
    public boolean modifyAdPickList(List<AdPickModifyBaseDTO> dtos) {
        if (CollectionUtils.isEmpty(dtos)) {
            return false;
        }
        // 执行批量更新
        int totalRows = wmToDownGoodsMapper.updateBatchByGoodsAndOrder(dtos);
        return totalRows >= dtos.size();
    }
    @Override
    public List<AdPickExportDTO> queryExportData(List<AdPickQuery> queries) {
        List<AdPickExportDTO> adPickExportDTOS = new ArrayList<>();
        for (AdPickQuery query : queries) {
            // 1. 参数校验
            if (query == null) {
                throw new IllegalArgumentException("查询参数不能为空");
            }
            // 2. 执行动态查询
            List<AdPickExportDTO> adPickExportDTO = wmToDownGoodsMapper.selectExportData(query);
            for (AdPickExportDTO dto : adPickExportDTO) {
                adPickExportDTOS.add(dto);
            }
        }
        return adPickExportDTOS;
    }
}

/**
 * <p>
 *  描述：转换 复刻数据库Entity -> 复刻列表DTO
 * </p>
 *
 * @author keyuan
 * @since 2025-02-28
 */
@Mapper(componentModel = "spring")
interface MsZcCheckMapper {
    /**
     * 将WmToDownGoods转换为CheckListDTO
     *
     * @param wmToDownGoods 源对象
     * @return 转换后的对象
     */
    CheckListDTO WmToDownGoodsToCheckListDTO(WmToDownGoods wmToDownGoods);
}
