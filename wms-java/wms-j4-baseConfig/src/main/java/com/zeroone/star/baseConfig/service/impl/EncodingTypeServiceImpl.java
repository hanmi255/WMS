package com.zeroone.star.baseConfig.service.impl;


import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.baseConfig.entity.EncodingType;
import com.zeroone.star.baseConfig.mapper.EncodingTypeMapper;
import com.zeroone.star.baseConfig.service.EncodingTypeService;
import com.zeroone.star.project.components.user.UserDTO;
import com.zeroone.star.project.components.user.UserHolder;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j4.encodingType.EncodingTypeBaseDTO;
import com.zeroone.star.project.dto.j4.encodingType.EncodingTypeListDTO;
import com.zeroone.star.project.dto.j4.encodingType.EncodingTypeNameListDTO;
import com.zeroone.star.project.query.j4.encodingType.EncodingTypeQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.j4.encodingType.EncodingTypeVO;
import lombok.SneakyThrows;
import lombok.extern.slf4j.Slf4j;
import org.mapstruct.Mapper;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;
import org.springframework.web.bind.annotation.RequestBody;

import javax.annotation.Resource;
import java.time.LocalDateTime;
import java.util.List;

@Mapper(componentModel = "spring")
interface MsEncodingTypeMapper {
    /**
     * 将 EncodingTypeDO 转换为 EncodingTypeBaseDTO
     * @param encodingType 源对象
     * @return 转换后的对象
     */
    EncodingTypeListDTO encodingTypeDOToEncodingTypeListDTO(EncodingType encodingType);
}

/**
 * <p>
 *  服务实现类
 * </p>
 *
 * @author bwb
 * @since 2025-02-22
 */
@Service
@Slf4j
public class EncodingTypeServiceImpl extends ServiceImpl<EncodingTypeMapper, EncodingType> implements EncodingTypeService {
    @Autowired
    private EncodingTypeMapper encodingTypeMapper;
    @Resource
    private UserHolder userHolder;


    @Override
    public void saveBatch(List<EncodingTypeVO> importedData) throws Exception {
        UserDTO userDTO = userHolder.getCurrentUser();
        for(EncodingTypeVO encodingTypeVO:importedData){
            EncodingType baSnroType = new EncodingType();
            baSnroType.setCreateBy(userDTO.getUsername());
            baSnroType.setCreateName(userDTO.getRealname());
            baSnroType.setCreateDate(LocalDateTime.now());
            baSnroType.setUpdateBy(userDTO.getUsername());
            baSnroType.setUpdateName(userDTO.getRealname());
            baSnroType.setUpdateDate(LocalDateTime.now());
            baSnroType.setSysCompanyCode(userDTO.getCompanyCode());
            baSnroType.setSysOrgCode(userDTO.getOrgCode());
            baSnroType.setSnroTypeCode(encodingTypeVO.getSnroTypeCode());
            baSnroType.setSnroTypeName(encodingTypeVO.getSnroTypeName());

            encodingTypeMapper.insert(baSnroType);
        }

    }





    @Resource
    MsEncodingTypeMapper msEncodingTypeMapper;


    @Override
    public PageDTO<EncodingTypeListDTO> listAllEncodingType(EncodingTypeQuery query) {
        //构建分页对象
        Page<EncodingType> page = new Page<>(query.getPageIndex(),query.getPageSize());
        //构建查询条件
        QueryWrapper<EncodingType> wrapper = new QueryWrapper<>();
        String code=query.getSnroTypeCode();
        String name=query.getSnroTypeName();
        if(code==null) code="";
        if(name==null) name="";
        wrapper.like("snro_type_code",code);
        wrapper.like("snro_type_name",name);
        //查询数据
        Page<EncodingType> ps = baseMapper.selectPage(page, wrapper);
        return PageDTO.create(ps,msEncodingTypeMapper::encodingTypeDOToEncodingTypeListDTO);
    }

    @SneakyThrows
    @Override
    public String saveEncodingType(@RequestBody EncodingTypeBaseDTO dto) {
        EncodingType typeDO = new EncodingType();
        typeDO.setSnroTypeName(dto.getSnroTypeName());
        typeDO.setSnroTypeCode(dto.getSnroTypeCode());
        UserDTO userDTO = userHolder.getCurrentUser();
        typeDO.setCreateBy(userDTO.getUsername());
        typeDO.setCreateDate(LocalDateTime.now());
        typeDO.setCreateName(userDTO.getRealname());
        typeDO.setSysCompanyCode(userDTO.getCompanyCode());
        typeDO.setSysOrgCode(userDTO.getOrgCode());
        int insert = baseMapper.insert(typeDO);
        if(insert>0){
            return "success";
        }else{
            return null;
        }
    }

    @SneakyThrows
    @Override
    public String updateEncodingType(@RequestBody EncodingTypeListDTO dto) {
        EncodingType typeDO = new EncodingType();
        typeDO.setId(dto.getId());
        typeDO.setSnroTypeName(dto.getSnroTypeName());
        typeDO.setSnroTypeCode(dto.getSnroTypeCode());
        UserDTO userDTO = userHolder.getCurrentUser();
        typeDO.setUpdateBy(userDTO.getUsername());
        typeDO.setUpdateDate(LocalDateTime.now());
        typeDO.setUpdateName(userDTO.getRealname());
        int update = baseMapper.updateById(typeDO);
        if(update>0){
            return "success";
        }else{
            return null;
        }
    }



    @Override
    public JsonVO<List<EncodingTypeNameListDTO>> encodingTypeNameList(String query) {
        try {
            List<EncodingTypeNameListDTO> list = encodingTypeMapper.encodingTypeNameList(query);
            if (list == null || list.isEmpty()) {
                log.warn("未查询到数据");
                return JsonVO.success(list);
            }
            return JsonVO.success(list);
        } catch (Exception e) {
            log.error("查询编码类型名称列表失败", e);
            return JsonVO.fail(null);
        }
    }
}