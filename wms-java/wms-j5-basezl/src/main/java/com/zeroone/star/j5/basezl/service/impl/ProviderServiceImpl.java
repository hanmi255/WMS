package com.zeroone.star.j5.basezl.service.impl;

import cn.hutool.core.date.DateTime;
import com.alibaba.excel.util.StringUtils;
import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.baomidou.mybatisplus.core.conditions.update.UpdateWrapper;
import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.zeroone.star.j5.basezl.entity.provider.Provider;
import com.zeroone.star.j5.basezl.entity.provider.ProviderExcel;
import com.zeroone.star.j5.basezl.mapper.ProviderMapper;
import com.zeroone.star.j5.basezl.service.IProviderService;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.project.components.easyexcel.EasyExcelComponent;
import com.zeroone.star.project.components.fastdfs.FastDfsClientComponent;
import com.zeroone.star.project.components.fastdfs.FastDfsFileInfo;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j5.basezl.provider.ProviderAddDTO;
import com.zeroone.star.project.dto.j5.basezl.provider.ProviderDetailDTO;
import com.zeroone.star.project.dto.j5.basezl.provider.ProviderListDTO;
import com.zeroone.star.project.dto.j5.basezl.provider.ProviderModifyDTO;
import com.zeroone.star.project.query.j5.basezl.provider.ProviderQuery;
import com.zeroone.star.project.vo.JsonVO;
import lombok.SneakyThrows;
import org.mapstruct.Mapper;
import org.springframework.http.HttpHeaders;
import org.springframework.http.HttpStatus;
import org.springframework.http.MediaType;
import org.springframework.http.ResponseEntity;
import org.springframework.stereotype.Service;
import org.springframework.web.multipart.MultipartFile;

import javax.annotation.Resource;
import java.io.ByteArrayOutputStream;
import java.util.List;

/**
 * <p>
 * 供应商 服务实现类
 * </p>
 *
 * @author 小赵
 * @since 2025-02-27
 */
@Service
public class ProviderServiceImpl extends ServiceImpl<ProviderMapper, Provider> implements IProviderService {

    @Resource
    private MsProviderMapper msProviderMapper;
    @Resource
    private ProviderMapper mapper;
    @Resource
    private EasyExcelComponent excel;
    @Resource
    FastDfsClientComponent dfs;

    @Override
    public PageDTO<ProviderListDTO> listAll(ProviderQuery query) {
        Page<Provider> page = new Page<>(query.getPageIndex(), query.getPageSize());
        QueryWrapper<Provider> wrapper = new QueryWrapper<>();
        if(StringUtils.isNotBlank(query.getZhongWenQch())){
            wrapper.like("zhong_wen_qch", query.getZhongWenQch());
        }
        if(StringUtils.isNotBlank(query.getGysBianMa())){
            wrapper.like("gys_bian_ma", query.getGysBianMa());
        }
        if(StringUtils.isNotBlank(query.getZhuJiMa())){
            wrapper.like("zhu_ji_ma", query.getZhuJiMa());
        }
        if(StringUtils.isNotBlank(query.getGysJianCheng())){
            wrapper.like("gys_jian_cheng", query.getGysJianCheng());
        }
        Page<Provider> pm = mapper.selectPage(page, wrapper);
        return PageDTO.create(pm, msProviderMapper::providerToProviderListDTO);
    }

    @Override
    public ProviderDetailDTO getDetails(String id) {
        Provider provider = mapper.selectById(id);
        return msProviderMapper.providerToProviderDetailDTO(provider);
    }

    @Override
    public String changeProvider(ProviderModifyDTO dto) {

        UpdateWrapper<Provider> wrapper = new UpdateWrapper<>();
        wrapper.eq("id", dto.getId());
        Provider provider = msProviderMapper.providerModifyDTOToProvider(dto);
        int update = mapper.update(provider, wrapper);
        return String.valueOf(update);
    }

    @Override
    public String addProvider(ProviderAddDTO dto) {
        Provider provider = msProviderMapper.providerAddDTOToProvider(dto);
        int i = mapper.insert(provider);
        return String.valueOf(i);
    }

    @Override
    public JsonVO<String> upload(MultipartFile file) {
        //解析excel文件
        List<ProviderExcel> excels = excel.parseExcel(file,ProviderExcel.class);
        List<Provider> list = msProviderMapper.toProviderList(excels);
        boolean b = this.saveBatch(list);
        if(b){
            return JsonVO.success("上传成功");
        }else {
            return JsonVO.fail("上传失败");
        }
    }

    @SneakyThrows
    @Override
    public ResponseEntity<byte[]> export(List<String> providerIds) {
        //获取数据
        List<Provider> providers = mapper.selectBatchIds(providerIds);
        List<ProviderExcel> data = msProviderMapper.toProviderExcel(providers);
        //导出到输出流
        ByteArrayOutputStream out = new ByteArrayOutputStream();
        excel.export("provider",out, ProviderExcel.class,data);
        //响应文件数据
        String  fileName = "rep-"  + DateTime.now().toString("yyyyMMddHHmmssS") + ".xlsx";
        HttpHeaders headers = new HttpHeaders();
        headers.setContentDispositionFormData("attachment",fileName);
        headers.setContentType(MediaType.APPLICATION_OCTET_STREAM);
        //上传到文件服务器
        //FastDfsFileInfo info = dfs.uploadFile(out.toByteArray(),"xlsx");
        ResponseEntity<byte[]> result = new ResponseEntity<>(out.toByteArray(), headers, HttpStatus.CREATED);
        out.close();
        return result;
    }
}

/**
 *MapperStruct 数据转换
 */
@Mapper(componentModel = "spring")
interface MsProviderMapper {
    ProviderListDTO providerToProviderListDTO(Provider provider);
    ProviderDetailDTO providerToProviderDetailDTO(Provider provider);
    Provider providerAddDTOToProvider(ProviderAddDTO dto);
    Provider providerModifyDTOToProvider(ProviderModifyDTO providerModifyDTO);
    List<ProviderExcel> toProviderExcel(List<Provider> providers);
    List<Provider> toProviderList(List<ProviderExcel> excels);

}
