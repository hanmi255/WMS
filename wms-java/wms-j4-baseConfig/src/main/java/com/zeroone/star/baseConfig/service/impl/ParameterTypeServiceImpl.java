package com.zeroone.star.baseConfig.service.impl;

import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.zeroone.star.baseConfig.entity.BaParameterType;
import com.zeroone.star.baseConfig.mapper.ParameterTypeMapper;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.baseConfig.service.ParameterTypeService;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j4.parameter.ParameterTypeAddDTO;
import com.zeroone.star.project.dto.j4.parameter.ParameterTypeListDTO;
import com.zeroone.star.project.dto.j4.parameter.ParameterTypeNameListDTO;
import com.zeroone.star.project.query.j4.parameter.ParameterTypeQuery;
import org.mapstruct.Mapper;
import org.springframework.stereotype.Service;
import org.springframework.transaction.annotation.Transactional;

import javax.annotation.Resource;
import java.util.ArrayList;
import java.util.List;

/**
 * @author neko
 * #Description：parameterType转DTO接口
 */
@Mapper(componentModel = "spring")
interface MsParameterTypeMapper{
    /**
     * 将parameterType转ParameterTypeListDTO
     * @param parameterType 源对象
     * @return 转换后的对象
     */
    ParameterTypeListDTO parameterTypeToParameterTypeDTO(BaParameterType parameterType);

    /**
     * 将parameterType转ParameterTypeNameListDTO
     * @param parameterType 源对象
     * @return 转换后的对象
     */
    ParameterTypeNameListDTO parameterTypeToParameterTypeNameListDTO(BaParameterType parameterType);

    /**
     * 将parameterTypeAddDTO转BaParameterType
     * @param parameterTypeAddDTO 源对象
     * @return 转换后的对象
     */
    BaParameterType parameterTypeAddDTOToBaParameterType(ParameterTypeAddDTO parameterTypeAddDTO);

}

/**
 * <p>
 *  参数类型服务实现类
 * </p>
 *
 * @author neko
 * @since 2025-03-01
 */
@Service
@Transactional
public class ParameterTypeServiceImpl extends ServiceImpl<ParameterTypeMapper, BaParameterType> implements ParameterTypeService {
    @Resource
    MsParameterTypeMapper msParameterTypeMapper;

    @Resource
    ParameterTypeMapper parameterTypeMapper;

    /**
     * 获取参数类型名称列表服务实现类
     * @return 参数类型名称列表显示数据对象集合
     */
    @Override
    public List<ParameterTypeNameListDTO> listParameterTypeName() {

        List<BaParameterType> parameterTypeList = baseMapper.selectList(null); // 查询参数类型集合

        if (parameterTypeList == null){ // 没有数据
            return null;
        }
        // 有数据
        List<ParameterTypeNameListDTO> ParameterTypeNameListDTO = new ArrayList<>(); // 创建参数类型名称集合
        for (BaParameterType parameterType : parameterTypeList) {
            ParameterTypeNameListDTO parameterTypeNameListDTO = msParameterTypeMapper.parameterTypeToParameterTypeNameListDTO(parameterType); // 转化为nameList
            ParameterTypeNameListDTO.add(parameterTypeNameListDTO);
        }

        return ParameterTypeNameListDTO;
    }

    /**
     * 获取参数类型列表（条件+分页）服务实现类
     * @param query  参数类型查询对象
     * @return 分页结果
     */
    @Override
    public PageDTO<ParameterTypeListDTO> queryAll(ParameterTypeQuery query) {
        // 构建分页对象
        Page<BaParameterType> page = new Page<>(query.getPageIndex(),query.getPageSize());
        // 构建查询条件
        QueryWrapper<BaParameterType> wrapper = new QueryWrapper<>();
        wrapper.like("sysp_type_name",query.getSyspTypeName());
        // 查询数据
        Page<BaParameterType> parameterTypePage = baseMapper.selectPage(page,wrapper);
        return PageDTO.create(parameterTypePage,msParameterTypeMapper::parameterTypeToParameterTypeDTO);
    }

    /**
     * 录入参数类型服务实现类
     * @param dto 参数类型列表录入数据对象
     * @return 结果响应
     */
    @Override
    public String addParameterType(ParameterTypeAddDTO dto) {
        int insert = baseMapper.insert(msParameterTypeMapper.parameterTypeAddDTOToBaParameterType(dto));
        if (insert == 0) return null;
        return Integer.toString(insert);
    }
}
