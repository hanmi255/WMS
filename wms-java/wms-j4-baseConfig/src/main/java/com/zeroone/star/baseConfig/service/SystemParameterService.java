package com.zeroone.star.baseConfig.service;

import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.baseConfig.entity.SystemParameter;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j4.systemParameter.SPListDTO;
import com.zeroone.star.project.query.j4.systemParameter.SPPageQuery;
import com.zeroone.star.project.vo.j4.systemParameter.SystemParameterVO;
import org.springframework.stereotype.Service;

import java.util.List;

/**
 * <p>
 *  服务类
 * </p>
 *
 * @author 阿强
 * @since 2025-02-23
 */
@Service
public interface SystemParameterService extends IService<SystemParameter> {
    PageDTO<SPListDTO> listAll(SPPageQuery query);

    //实现excel表格内容的转换
    void saveBatch(List<SystemParameterVO> importedData) throws Exception;

}
