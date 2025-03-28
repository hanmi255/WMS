package com.zeroone.star.project.j4.baseConfig;


import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j4.systemParameter.SPAddDTO;
import com.zeroone.star.project.dto.j4.systemParameter.SPListDTO;
import com.zeroone.star.project.dto.j4.systemParameter.SPModifyDTO;
import com.zeroone.star.project.query.j4.systemParameter.SPPageQuery;
import com.zeroone.star.project.vo.JsonVO;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.bind.annotation.RequestParam;
import org.springframework.web.multipart.MultipartFile;

import java.util.List;

/**
 * @author 阿强
 * @title SystemParameterApis
 * @date 2025/2/21 21:57
 * @description 系统参数apis
 */
public interface SystemParameterApis {

    /**
     * 查询系统参数列表
     * @param query
     * @return
     */
    JsonVO<PageDTO<SPListDTO>> queryAll(SPPageQuery query);

    /**
     * 添加系统参数
     * @param spAddDTO
     * @return
     */
    JsonVO<String> addSP(SPAddDTO spAddDTO);

    /**
     * 修改系统参数
     * @param spModifyDTO
     * @return
     */
    JsonVO<String> modifySP(SPModifyDTO spModifyDTO);


    /**
     * 删除系统参数
     * @param ids
     * @return
     */
    JsonVO<String> deleteByIds(@RequestBody List<String> ids);



    /**
     * 导出参数
     * @param query
     * @return
     */
    ResponseEntity<byte[]> exportexcel(SPPageQuery query);


    /**
     * 导入参数
     * @param file
     * @return
     */
    ResponseEntity<String> importExcel(@RequestParam("file") MultipartFile file);

}
