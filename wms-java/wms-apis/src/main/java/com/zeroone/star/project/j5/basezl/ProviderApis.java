package com.zeroone.star.project.j5.basezl;

import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j5.basezl.provider.ProviderAddDTO;
import com.zeroone.star.project.dto.j5.basezl.provider.ProviderDetailDTO;
import com.zeroone.star.project.dto.j5.basezl.provider.ProviderListDTO;
import com.zeroone.star.project.dto.j5.basezl.provider.ProviderModifyDTO;
import com.zeroone.star.project.query.j5.basezl.provider.ProviderQuery;
import com.zeroone.star.project.vo.JsonVO;
import org.springframework.http.ResponseEntity;
import org.springframework.web.multipart.MultipartFile;

import java.util.List;

public interface ProviderApis {

    /**
     * 查询供应商信息列表
     * @param query 查询条件
     * @return 响应数据结果
     */
    JsonVO<PageDTO<ProviderListDTO>> queryAll(ProviderQuery query);
    /**
     * 获取供应商详细信息
     * @param id 供应商的id
     * @return 响应数据结果
     */
    JsonVO<ProviderDetailDTO> getDetailsProvider(String id);
  /**
     * 录入供应商
     * @param dto 录入的供应商信息
     * @return 响应数据结果
     */
    JsonVO<String> addProvider(ProviderAddDTO dto);
    /**
     * 修改供应商
     * @param dto 修改后的的供应商信息
     * @return 响应数据结果
     */
    JsonVO<String> changeProvider(ProviderModifyDTO dto);
    /**
     * 删除供应商(支持批量删除)
     * @param providerIds 供应商id号
     * @return 响应数据结果
     */
    JsonVO<String> deleteProvider(List<String> providerIds);

    /**
     * 导入供应商
     * @param file 导入文件
     * @return 响应数据结果
     */
    public JsonVO<String> uploadProvider(MultipartFile file);

    /**
     * 导出供应商
     * @param providerIds 需要导出的供应商id
     * @return 响应数据结果
     */
    ResponseEntity<byte[]> exportProvider(List<String> providerIds);

    /**
     * 获取企业属性
     * @return
     */
    JsonVO<List<String>> getXingYeFenLei();
}
