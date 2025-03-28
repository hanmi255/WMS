package com.zeroone.star.project.j4.baseConfig;

import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j4.parameter.*;
import com.zeroone.star.project.query.j4.parameter.ParameterTypeModifyQuery;
import com.zeroone.star.project.query.j4.parameter.ParameterTypeQuery;
import com.zeroone.star.project.vo.JsonVO;
import org.springframework.http.ResponseEntity;
import org.springframework.web.multipart.MultipartFile;

import java.util.List;

/**
 * @author qiaozhi
 * @title ParameterTypeApis
 * @date 2025/2/21 21:57
 * @description 参数类型apis
 */
public interface ParameterTypeApis {
    /**
     * 修改参数类型
     * @param query 修改条件
     * @return 响应修改结果
     */
    JsonVO<ParameterTypeModifyQuery> modifyOne(ParameterTypeModifyQuery query);


    /**
     * 删除一条或多条数据
     * @param ids
     * @return 响应删除结果
     */
    JsonVO<String> deleteMore(String[] ids);


    /**
     * 导出参数类型数据
     * @param query 导出文件
     * @return 文件流
     */
    ResponseEntity<byte[]> downloadParameterType(ParameterTypeFileDTO query);

    /**
     * 导入参数类型数据
     * @param file 导入文件
     * @return 文件流
     */
    JsonVO<String> uploadParameterType(MultipartFile file);

    /**
     * 获取参数类型名称列表
     * @return 响应数据结果
     */
    JsonVO<List<ParameterTypeNameListDTO>> listParameterTypeName(String query);

    /**
     * 获取参数类型列表
     * @param query 查询条件
     * @return 响应数据结果
     */
    JsonVO<PageDTO<ParameterTypeListDTO>> queryAll(ParameterTypeQuery query);

    /**
     * 录入获取参数类型信息
     * @param dto 参数类型信息
     * @return 响应数据结果
     */
    JsonVO<String> addParameterType(ParameterTypeAddDTO dto);


}
