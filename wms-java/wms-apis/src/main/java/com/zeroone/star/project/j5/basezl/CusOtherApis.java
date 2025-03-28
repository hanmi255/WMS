package com.zeroone.star.project.j5.basezl;

import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j5.basezl.cusother.CusOtherAddDTO;
import com.zeroone.star.project.dto.j5.basezl.cusother.CusOtherListDTO;
import com.zeroone.star.project.dto.j5.basezl.cusother.CusOtherModifyDTO;
import com.zeroone.star.project.query.j5.basezl.cusother.CusOtherQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.j5.basezl.CusOtherVO;
import org.springframework.http.ResponseEntity;
import org.springframework.web.multipart.MultipartFile;

import java.util.List;

/**
 * <p>
 * 描述: 第三方客户管理接口
 * </p>
 * <p>版权所有: &copy;枢璇</p>
 *
 * @author 枢璇
 * @Version 1.0.0
 * @since 2025/2/23 22:15
 */
public interface CusOtherApis {

    /**
     * 查询第三方客户信息列表
     * @param query 查询条件
     * @return 第三方客户信息列表
     */
    JsonVO<PageDTO<CusOtherListDTO>> queryAll(CusOtherQuery query);

    /**
     * 单查询
     * @param keHuBianMa 客户编码
     * @return 查询到的第三方客户的VO
     */
    JsonVO<CusOtherVO> queryOne(String keHuBianMa);

    /**
     * 新增第三方客户信息
     * @param dto 客户信息
     * @return 新增结果状态
     */
    JsonVO<String> addCusOther(CusOtherAddDTO dto);

    /**
     * 删除第三方客户信息
     * @param @param ids 第三方客户id列表
     * @return 删除结果状态
     */
    JsonVO<String> removeCusOther(List<String> ids);

    /**
     * 修改第三方客户信息
     * @param dto 客户信息
     * @return 修改结果状态
     */
    JsonVO<String> modifyCusOther(CusOtherModifyDTO dto);

    /**
     * 通过Excel表格导入列表数据
     * @param file Excel表格文件
     * @return 录入结果状态
     */
    JsonVO<String> uploadCusOther(MultipartFile file);

    /**
     * 通过Excel表格导出列表数据
     * @param ids 第三方客户id列表
     * @return
     */
    ResponseEntity<byte[]> exportCusOther(List<String> ids);
}



