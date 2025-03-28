package com.zeroone.star.j5.basezl.service;

import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.j5.basezl.entity.cusother.CusOtherDO;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j5.basezl.cusother.CusOtherAddDTO;
import com.zeroone.star.project.dto.j5.basezl.cusother.CusOtherListDTO;
import com.zeroone.star.project.dto.j5.basezl.cusother.CusOtherModifyDTO;
import com.zeroone.star.project.query.j5.basezl.cusother.CusOtherQuery;
import com.zeroone.star.project.vo.j5.basezl.CusOtherVO;
import org.springframework.http.ResponseEntity;
import org.springframework.web.multipart.MultipartFile;

import java.util.List;

/**
 * <p>
 * 描述: 第三方客户业户逻辑接口定义
 * </p>
 * <p>版权所有: &copy;枢璇</p>
 *
 * @author 枢璇
 * @Version 1.0.0
 * @since 2025/2/26 15:35
 */
public interface CusOtherService extends IService<CusOtherDO> {
    PageDTO<CusOtherListDTO> listCusOther(CusOtherQuery query);

    CusOtherVO getCusOtherDetail(String keHuBianMa);

    String saveCusOther(CusOtherAddDTO dto);

    String updateCusOther(CusOtherModifyDTO dto);

    void removeByBianMa(List<String> ids);

    ResponseEntity<byte[]> export(List<String> ids);

    void upload(MultipartFile file);
}
