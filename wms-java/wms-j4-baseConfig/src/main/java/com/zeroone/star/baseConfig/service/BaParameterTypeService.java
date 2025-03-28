package com.zeroone.star.baseConfig.service;

import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.baseConfig.entity.BaParameterType;
import org.springframework.web.multipart.MultipartFile;

import java.util.List;

/**
 * <p>
 *  服务类
 * </p>
 *
 * @author qiaozhi
 * @since 2025-03-07
 */
public interface BaParameterTypeService extends IService<com.zeroone.star.baseConfig.entity.BaParameterType> {

    /**
     * 导入文件
     * @param file
     */
    void importParameterType(MultipartFile file);

    /**
     * 导出文件
     *
     * @return
     */
    List<BaParameterType> exportParameterType();



}
