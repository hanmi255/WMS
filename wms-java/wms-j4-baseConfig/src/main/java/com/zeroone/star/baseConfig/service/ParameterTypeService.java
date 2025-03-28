package com.zeroone.star.baseConfig.service;

import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.baseConfig.entity.BaParameterType;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j4.parameter.ParameterTypeAddDTO;
import com.zeroone.star.project.dto.j4.parameter.ParameterTypeListDTO;
import com.zeroone.star.project.dto.j4.parameter.ParameterTypeNameListDTO;
import com.zeroone.star.project.query.j4.parameter.ParameterTypeQuery;

import java.util.List;

/**
 * <p>
 *  参数类型服务类
 * </p>
 *
 * @author neko
 * @since 2025-03-01
 */
public interface ParameterTypeService extends IService<BaParameterType> {

    /**
     * 获取参数类型名称列表服务接口
     * @return 参数类型名称列表显示数据对象集合
     */
    List<ParameterTypeNameListDTO> listParameterTypeName();

    /**
     * 获取参数类型列表（条件+分页）服务接口
     * @param query  参数类型查询对象
     * @return 分页结果
     */
    PageDTO<ParameterTypeListDTO> queryAll(ParameterTypeQuery query);

    /**
     * 录入参数类型服务接口
     * @param dto 参数类型列表录入数据对象
     * @return 结果响应
     */
    String addParameterType(ParameterTypeAddDTO dto);
}
