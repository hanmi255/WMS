package com.zeroone.star.othermana.service.impl;

import cn.hutool.core.date.DateTime;
import com.alibaba.excel.EasyExcel;
import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.othermana.entity.BaContSpec;
import com.zeroone.star.othermana.mapper.BaContSpecMapper;
import com.zeroone.star.othermana.mapper.IBaContSpecMapper;
import com.zeroone.star.othermana.service.IBaContSpecService;
import com.zeroone.star.project.components.easyexcel.EasyExcelComponent;
import com.zeroone.star.project.components.easyexcel.ExcelReadListener;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j8.other.contspec.SpecificationAddDTO;
import com.zeroone.star.project.dto.j8.other.contspec.SpecificationBaseDTO;
import com.zeroone.star.project.dto.j8.other.contspec.SpecificationDeleteDTO;
import com.zeroone.star.project.dto.j8.other.contspec.SpecificationModifyDTO;
import com.zeroone.star.project.query.j8.other.contspec.SpecificationQuery;
import lombok.SneakyThrows;
import org.springframework.http.HttpHeaders;
import org.springframework.http.HttpStatus;
import org.springframework.http.MediaType;
import org.springframework.http.ResponseEntity;
import org.springframework.stereotype.Service;
import org.springframework.web.multipart.MultipartFile;

import javax.annotation.Resource;
import java.io.ByteArrayOutputStream;
import java.io.InputStream;
import java.util.ArrayList;
import java.util.List;


/**
 * <p>
 *  服务实现类
 * </p>
 *
 * @author xban
 * @since 2025-02-27
 */
@Service
public class BaContSpecServiceImpl extends ServiceImpl<BaContSpecMapper, BaContSpec> implements IBaContSpecService {

    @Resource
    IBaContSpecMapper specMapper;

    @Override
    public PageDTO<SpecificationBaseDTO> listAll(SpecificationQuery query) {
        Page<BaContSpec> ps = baseMapper.listAll(query);
        return PageDTO.create(ps,specMapper::specToSpecificationBaseDTO);
    }

    @Override
    public SpecificationBaseDTO getById(String id) {
        BaContSpec spec = baseMapper.selectById(id);
        if (spec == null){
            return null;
        }
        return specMapper.specToSpecificationBaseDTO(spec);
    }

    @Override
    public int addSpecification(SpecificationAddDTO dto) {
        BaContSpec spec = specMapper.specificationAddDtoToSpec(dto);
        return baseMapper.insert(spec);
    }

    @Override
    public int putSpecification(SpecificationModifyDTO dto) {
        BaContSpec spec = specMapper.specificationModifyToSpec(dto);
        return baseMapper.updateById(spec);
    }



    @Override
    public int deleteSpecifications(List<SpecificationDeleteDTO> dtos) {
        int count = 0;
        for (SpecificationDeleteDTO dto :
                dtos) {
            count += baseMapper.deleteById(dto.getId());
        }
        return count;
    }
    @SneakyThrows
    @Override
    public int importExcel(MultipartFile file) {
        InputStream stream = file.getInputStream();
        ExcelReadListener<SpecificationAddDTO> listener = new ExcelReadListener<>();
        EasyExcel.read(stream,SpecificationAddDTO.class,listener).sheet().doRead();
        List<SpecificationAddDTO> dataList = listener.getDataList();

        int count = 0;
        for (SpecificationAddDTO each :
                dataList) {
            int m = baseMapper.insert(specMapper.specificationAddDtoToSpec(each));
            count += m;
        }
        return count;
    }

    @Resource
    EasyExcelComponent excelComponent;

    @SneakyThrows
    @Override
    public ResponseEntity<byte[]> exportExcel() {
        List<BaContSpec> list = baseMapper.selectAll();
        ArrayList<SpecificationAddDTO> data = new ArrayList<>();
        list.forEach(i->data.add(specMapper.specToSpecificationAddDTO(i)));

        ByteArrayOutputStream stream = new ByteArrayOutputStream();
        excelComponent.export("箱规管理",stream,SpecificationAddDTO.class,data);

        String fileName = "spec-" + DateTime.now().toString("yyyyMMddHHmmssS")+".xlsx";
        HttpHeaders headers = new HttpHeaders();
        headers.setContentDispositionFormData("attachment",fileName);
        headers.setContentType(MediaType.APPLICATION_OCTET_STREAM);
        ResponseEntity<byte[]> result = new ResponseEntity<>(stream.toByteArray(), headers, HttpStatus.CREATED);
        stream.close();
        return result;
    }


}
