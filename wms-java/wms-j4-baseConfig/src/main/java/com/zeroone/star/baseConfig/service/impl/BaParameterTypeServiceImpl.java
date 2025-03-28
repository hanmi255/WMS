package com.zeroone.star.baseConfig.service.impl;

import com.alibaba.excel.EasyExcel;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.baseConfig.entity.BaParameterType;
import com.zeroone.star.baseConfig.mapper.BaParameterTypeMapper;
import com.zeroone.star.project.components.easyexcel.ExcelReadListener;
import com.zeroone.star.project.components.user.UserHolder;
import com.zeroone.star.project.dto.j4.parameter.ParameterTypeDTO;
import com.zeroone.star.project.dto.j4.parameter.ParameterTypeFileDTO;
import org.mapstruct.Mapper;
import org.springframework.beans.BeanUtils;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;
import org.springframework.web.multipart.MultipartFile;

import javax.annotation.Resource;
import java.util.List;


@Mapper(componentModel = "spring")
interface MssParameterTypeMapper {
    /**
     * 将ParameterTypeDTO转换为SampleDTO
     * @param parameterType 源对象
     * @return 转换后的对象
     */
    ParameterTypeDTO parameterTypeToParameterTypeDTO(BaParameterType parameterType);
}

/**
 * <p>
 *  服务实现类
 * </p>
 *
 * @author qiaozhi
 * @since 2025-03-07
 */
@Service
public class BaParameterTypeServiceImpl extends ServiceImpl<com.zeroone.star.baseConfig.mapper.BaParameterTypeMapper, com.zeroone.star.baseConfig.entity.BaParameterType> implements com.zeroone.star.baseConfig.service.BaParameterTypeService {

    @Autowired
    BaParameterTypeMapper baParameterTypeMapper;
    @Resource
    private UserHolder userHolder;


    @Override
    public void importParameterType(MultipartFile file) {
        // 使用EasyExcel读取上传的Excel文件并处理
        try {
            ExcelReadListener<ParameterTypeFileDTO> listener = new ExcelReadListener<>();
            EasyExcel.read(file.getInputStream(), ParameterTypeFileDTO.class, listener).sheet().doRead();
            // 将读取到的数据插入到数据库
            //获取当前登录用户
//            UserDTO currentUser = userHolder.getCurrentUser();
            listener.getDataList().forEach(data -> {
                BaParameterType baParameterType = new BaParameterType();
                BeanUtils.copyProperties(data, baParameterType);
//                baParameterType.setCreateBy(currentUser.getUsername());
//                baParameterType.setUpdateBy(currentUser.getUsername());
                baParameterTypeMapper.insert(baParameterType);
            });
        } catch (Exception e) {
            throw new RuntimeException(e);
        }
    }

    @Override
    public List<BaParameterType> exportParameterType() {
        // 查找数据
        List<BaParameterType> parameterTypeList = baParameterTypeMapper.selectList(null);
        return parameterTypeList;
    }
}
