package com.zeroone.star.baseConfig.service.impl;

import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.baseConfig.entity.SystemParameter;
import com.zeroone.star.baseConfig.mapper.SystemParameterMapper;
import com.zeroone.star.baseConfig.service.SystemParameterService;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j4.systemParameter.SPListDTO;
import com.zeroone.star.project.query.j4.systemParameter.SPPageQuery;
import com.zeroone.star.project.vo.j4.systemParameter.SystemParameterVO;
import org.mapstruct.Mapper;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;
import org.springframework.transaction.annotation.Transactional;

import javax.annotation.Resource;
import java.util.List;

@Mapper(componentModel = "spring")
interface MsSPMapper {
    /**
     * 将Sample转换为SampleDTO
     * @param sample 源对象
     * @return 转换后的对象
     */
    SPListDTO SPToSPDTO(SystemParameter sample);
}

/**
 * <p>
 *  服务实现类
 * </p>
 *
 * @author szq
 * @since 2025-02-23
 */
@Service
public class SysConfServiceImpl extends ServiceImpl<SystemParameterMapper, SystemParameter> implements SystemParameterService {

    @Resource
    MsSPMapper msMapper;

    @Override
    public PageDTO<SPListDTO> listAll(SPPageQuery query) {
        Page<SystemParameter> page = new Page<>(query.getPageIndex(), query.getPageSize());
        // 构建查询条件
        // 使用传进来的query.getName()对Sample表格中的“name”字段进行模糊查询
        QueryWrapper<SystemParameter> wrapper = new QueryWrapper<>();
        wrapper.like(query.getSystemParamType(), query.getKeyword());


        // 查询数据
        Page<SystemParameter> ps = baseMapper.selectPage(page, wrapper);


        return PageDTO.create(ps, msMapper::SPToSPDTO);
    }

    @Autowired
    private SystemParameterMapper systemParameterMapper;
    @Transactional
    @Override
    public void saveBatch(List<SystemParameterVO> importedData) throws Exception {
        for (SystemParameterVO systemParameterVO:importedData) {
            SystemParameter systemParameter = new SystemParameter();
            systemParameter.setSysConfType(systemParameterVO.getSysConfType());
            systemParameter.setSysConfStep(systemParameterVO.getSysConfStep());
            systemParameter.setSysConfOrg(systemParameterVO.getSysConfOrg());
            systemParameter.setSysConfPartner(systemParameterVO.getSysConfPartner());
            systemParameter.setSysPara1(systemParameterVO.getSysPara1());
            systemParameter.setSysPara2(systemParameterVO.getSysPara2());
            systemParameter.setSysPara3(systemParameterVO.getSysPara3());
            systemParameter.setSysConfText(systemParameterVO.getSysConfText());

            systemParameterMapper.insert(systemParameter);
        }
    }
}
