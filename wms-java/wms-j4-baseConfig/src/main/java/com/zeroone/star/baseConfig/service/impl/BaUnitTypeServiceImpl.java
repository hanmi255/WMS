package com.zeroone.star.baseConfig.service.impl;

import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.baseConfig.entity.BaUnitType;
import com.zeroone.star.baseConfig.mapper.BaUnitTypeMapper;
import com.zeroone.star.baseConfig.service.BaUnitTypeService;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j4.unitType.UnitTypeListDTO;
import com.zeroone.star.project.query.j4.unitType.UnitTypeListQuery;
import com.zeroone.star.project.vo.JsonVO;
import org.springframework.stereotype.Service;
import org.springframework.transaction.annotation.Transactional;

import javax.annotation.Resource;
import java.util.List;
import java.util.stream.Collectors;

/**
 * @author 1+5
 * @title
 * @date 2025/2/23 23 11
 * @description
 */

@Service
@Transactional
public class BaUnitTypeServiceImpl extends ServiceImpl<BaUnitTypeMapper, BaUnitType> implements BaUnitTypeService {


    @Resource
    BaUnitTypeMapper mapper;

    @Override
    public JsonVO<List<String>> getUnitTypeNameList() {

        // 设置查询条件
        QueryWrapper<BaUnitType> wrapper = new QueryWrapper<>();

        // 执行查询获取所有记录
        List<BaUnitType> baUnitTypeList = mapper.selectList(wrapper);

        // 提取名称列表
        List<String> nameList = baUnitTypeList.stream()
                .map(BaUnitType::getUnitTypeName)
                .collect(Collectors.toList());

        // 返回
        return JsonVO.success(nameList);
    }
    @Override
    public JsonVO<PageDTO<UnitTypeListDTO>> getUnitTypeList(UnitTypeListQuery unitTypeListQuery) {

        //判断排序条件是否为空
        if (unitTypeListQuery.getOrder() == null){
            PageDTO<UnitTypeListDTO> unitTypeListDTOPageDTO = new PageDTO<>();
            unitTypeListDTOPageDTO.setPageSize(unitTypeListQuery.getPageSize());
            unitTypeListDTOPageDTO.setPageIndex(unitTypeListQuery.getPageIndex());
            JsonVO<PageDTO<UnitTypeListDTO>> fail = JsonVO.fail(unitTypeListDTOPageDTO);
            fail.setMessage("排序条件不能为空");
            return fail;
        }

        //设置查询条件
        QueryWrapper<BaUnitType> wrapper = new QueryWrapper<>();

        if ("asc".equals(unitTypeListQuery.getSort())){
            wrapper.orderByAsc(unitTypeListQuery.getOrder());
        }

        if ("desc".equals(unitTypeListQuery.getSort())){
            wrapper.orderByDesc(unitTypeListQuery.getOrder());
        }

        //设置分页参数
        Page<BaUnitType> page = new Page<>(unitTypeListQuery.getPageIndex(), unitTypeListQuery.getPageSize());

        // 执行分页查询
        Page<BaUnitType> baUnitTypePage = mapper.selectPage(page, wrapper);

        //转换成VO
        PageDTO<UnitTypeListDTO> unitTypeListDTOPageDTO = new PageDTO<UnitTypeListDTO>().create(baUnitTypePage, UnitTypeListDTO.class);

        //返回
        return JsonVO.success(unitTypeListDTOPageDTO);


    }
}
