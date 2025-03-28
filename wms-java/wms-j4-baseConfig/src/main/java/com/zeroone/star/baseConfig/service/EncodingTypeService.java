package com.zeroone.star.baseConfig.service;


import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.baseConfig.entity.EncodingType;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j4.encodingType.EncodingTypeBaseDTO;
import com.zeroone.star.project.dto.j4.encodingType.EncodingTypeListDTO;
import com.zeroone.star.project.dto.j4.encodingType.EncodingTypeNameListDTO;
import com.zeroone.star.project.query.j4.encodingType.EncodingTypeQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.j4.encodingType.EncodingTypeVO;

import java.util.List;

/**
 * <p>
 *  服务类
 * </p>
 *
 * @author bwb
 * @since 2025-02-22
 */
public interface EncodingTypeService extends IService<EncodingType> {


    void saveBatch(List<EncodingTypeVO> importedData) throws Exception;

    /**
     * 获取编码类型列表（条件+分页）
     * @param query 查询条件
     * @return 查询结果
     */
    PageDTO<EncodingTypeListDTO> listAllEncodingType(EncodingTypeQuery query);

    /**
     * 录入编码类型
     * @param dto 录入的编码类型dto
     * @return success 或 null
     */
    String saveEncodingType(EncodingTypeBaseDTO dto);

    /**
     * 修改编码类型
     * @param dto 修改后的编码类型dto
     * @return success 或 null
     */
    String updateEncodingType(EncodingTypeListDTO dto);


    JsonVO<List<EncodingTypeNameListDTO>> encodingTypeNameList(String query);

}

