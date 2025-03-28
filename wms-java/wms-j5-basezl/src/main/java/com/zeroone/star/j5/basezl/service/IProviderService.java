package com.zeroone.star.j5.basezl.service;

import com.zeroone.star.j5.basezl.entity.provider.Provider;
import com.baomidou.mybatisplus.extension.service.IService;
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

/**
 * <p>
 * 供应商 服务类
 * </p>
 *
 * @author 小赵
 * @since 2025-02-27
 */
public interface IProviderService extends IService<Provider> {

    PageDTO<ProviderListDTO> listAll(ProviderQuery query);

    ProviderDetailDTO getDetails(String id);

    String changeProvider(ProviderModifyDTO dto);

    String addProvider(ProviderAddDTO dto);

    JsonVO<String> upload(MultipartFile file);

    ResponseEntity<byte[]> export(List<String> providerIds);
}
