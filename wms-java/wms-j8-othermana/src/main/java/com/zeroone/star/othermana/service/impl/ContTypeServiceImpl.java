package com.zeroone.star.othermana.service.impl;

import cn.hutool.core.date.DateTime;
import com.alibaba.excel.EasyExcel;
import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.othermana.entity.BaContType;
import com.zeroone.star.othermana.mapper.ContTypeMapper;
import com.zeroone.star.othermana.mapper.IBaContTypeMapper;
import com.zeroone.star.othermana.service.BaContTypeService;
import com.zeroone.star.project.components.easyexcel.EasyExcelComponent;
import com.zeroone.star.project.components.easyexcel.ExcelReadListener;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j8.other.baconttype.BaContTypeDTO;
import com.zeroone.star.project.query.j8.other.baconttype.BaContTypeQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.j8.other.baconttype.BaContTypeVO;
import lombok.SneakyThrows;
import org.apache.poi.ss.usermodel.Row;
import org.apache.poi.ss.usermodel.Sheet;
import org.apache.poi.xssf.usermodel.XSSFWorkbook;
import org.springframework.beans.BeanUtils;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.http.HttpHeaders;
import org.springframework.http.HttpStatus;
import org.springframework.http.MediaType;
import org.springframework.http.ResponseEntity;
import org.springframework.stereotype.Component;
import org.springframework.transaction.annotation.Transactional;
import org.springframework.web.multipart.MultipartFile;

import javax.annotation.Resource;
import java.io.ByteArrayOutputStream;
import java.io.InputStream;
import java.util.ArrayList;
import java.util.List;

@Component
public class ContTypeServiceImpl extends ServiceImpl<ContTypeMapper, BaContType> implements BaContTypeService {

    @Autowired
    private ContTypeMapper contShapeMapper;

    @Resource
    EasyExcelComponent excel;

    @Resource
    IBaContTypeMapper iBaContTypeMapper;


    @Override
    public PageDTO<BaContTypeVO> pageQuery(BaContTypeQuery baContTypeQuery) {
        Page<BaContType> baContTypeDOPage = baseMapper.selectByQuery(baContTypeQuery);
        return PageDTO.create(baContTypeDOPage,iBaContTypeMapper::BaconttypeDOtoVO);
    }

    @Override
    public JsonVO<BaContTypeVO> queryBaContType(String id) {
        BaContType baCostTypeDO = baseMapper.selectById(id);
        BaContTypeVO baContTypeVO =iBaContTypeMapper.BaconttypeDOtoVO(baCostTypeDO);
        return JsonVO.success(baContTypeVO);
    }

    @Override
    public void addBaContType(BaContTypeDTO dto) {
        BaContType baContTypeDO=iBaContTypeMapper.BaconttypeDTOtoDO(dto);
        baseMapper.insert(baContTypeDO);
    }

    @Override
    public void updateById(BaContTypeDTO dto) {
        BaContType baContTypeDO=iBaContTypeMapper.BaconttypeDTOtoDO(dto);
        baseMapper.updateById(baContTypeDO);
    }

    @Override
    public void removeBaContType(List<String> ids) {
        for (String id : ids) {
            baseMapper.deleteById(id);
        }

    }


    @SneakyThrows
    @Override
    @Transactional
    public ResponseEntity<byte[]> exportExcel() {
        //获取导出数据
        List<BaContType> res = baseMapper.selectAll();
        List<BaContTypeDTO> date=new ArrayList<>();
        res.forEach(i->date.add(iBaContTypeMapper.BaconttypeDOtoDTO(i)));
        //导出到输出流
        ByteArrayOutputStream out=new ByteArrayOutputStream();
        excel.export("箱型管理",out, BaContTypeDTO.class,date);
        //响应文件数据
        String filename="contType-"+ DateTime.now().toString("yyyyMMddHHmmssS")+".xlsx";
        HttpHeaders headers=new HttpHeaders();
        headers.setContentDispositionFormData("contType",filename);
        headers.setContentType(MediaType.APPLICATION_OCTET_STREAM);
        ResponseEntity<byte[]> result=new ResponseEntity<>(out.toByteArray(),headers, HttpStatus.CREATED);
        out.close();
        return result;
    }

    @SneakyThrows
    @Override
    @Transactional
    public void importExcel(MultipartFile file) {
        InputStream in = file.getInputStream();
        ExcelReadListener<BaContTypeDTO> listener = new ExcelReadListener<>();
        EasyExcel.read(in, BaContTypeDTO.class,listener).sheet().doRead();
        List<BaContTypeDTO> dataList = listener.getDataList();
        //写入数据到数据库
        //int affList = 0;//插入数据条数
        for (BaContTypeDTO i : dataList) {
            int aff = baseMapper.insert(iBaContTypeMapper.BaconttypeDTOtoDO(i));
            //affList += aff;
        }

    }

}