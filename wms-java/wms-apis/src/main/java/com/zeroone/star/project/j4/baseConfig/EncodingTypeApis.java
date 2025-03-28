package com.zeroone.star.project.j4.baseConfig;


import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j4.encodingType.EncodingTypeBaseDTO;
import com.zeroone.star.project.dto.j4.encodingType.EncodingTypeListDTO;
import com.zeroone.star.project.dto.j4.encodingType.EncodingTypeNameListDTO;
import com.zeroone.star.project.query.j4.encodingType.EncodingTypeQuery;
import com.zeroone.star.project.vo.JsonVO;
import org.springframework.http.ResponseEntity;
import org.springframework.web.multipart.MultipartFile;

import java.io.IOException;
import java.util.List;

/**
 * @author bxc
 * @title EncodingTypeApis
 * @date 2025/2/21 21:59
 * @description 编码类型apis
 */
public interface EncodingTypeApis {

    /**
     * 查询编码类型列表
     * @param query 查询条件
     * @return 响应数据结果
     */
    JsonVO<PageDTO<EncodingTypeListDTO>> queryAllEncodingType(EncodingTypeQuery query);

    /**
     * 新增编码类型
     *
     * @param dto 编码类型信息
     * @return 相应数据结果
     */
    JsonVO<String> addEncodingType(EncodingTypeBaseDTO dto);

    /**
     * 修改编码类型
     * @param dto 编码类型信息
     * @return 响应数据结果
     */
    JsonVO<String> modifyEncodingType(EncodingTypeListDTO dto);



    /**批量删除编码类型接口
     * @param ids
     * 根据传来的id批量(或单一)删除编码类型
     * @return
     */
    JsonVO<String> deleteByIds(List<String>ids);

    /**
     * 完成编码类型excel导出
     * @return
     * @throws IOException
     */
    ResponseEntity<byte[]> exportexcel(EncodingTypeQuery query);
    /**
     * 完成编码类型excel导入
     * @param file
     * @return
     */
    ResponseEntity<String> importExcel(MultipartFile file);

    /**
     * 获取编码类型名称列表
     * @param query 编码类型名称
     * @return
     */
    JsonVO<List<EncodingTypeNameListDTO>> encodingTypeNameList(String query);

}
