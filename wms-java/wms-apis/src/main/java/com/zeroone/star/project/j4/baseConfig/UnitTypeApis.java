package com.zeroone.star.project.j4.baseConfig;


import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j4.unitType.UnitTypeAddDTO;
import com.zeroone.star.project.dto.j4.unitType.UnitTypeListDTO;
import com.zeroone.star.project.dto.j4.unitType.UnitTypeModifyDTO;
import com.zeroone.star.project.query.j4.unitType.UnitTypeListQuery;
import com.zeroone.star.project.query.j4.unitType.UnitTypeQuery;
import com.zeroone.star.project.vo.JsonVO;
import org.springframework.http.ResponseEntity;
import org.springframework.web.multipart.MultipartFile;

import java.util.List;

/**
 * @author qiaozhi
 * @title UnitTypeApis
 * @date 2025/2/21 21:58
 * @description 单位类型apis
 */
public interface UnitTypeApis {


    /**
     * 插入单位类型
     * @param dto 单位类型数据
     * @return 操作结果
     */


    JsonVO<String> AddUnitType(UnitTypeAddDTO dto);

    /**
     * 修改单位类型
     * @param dto 单位类型数据
     * @return 操作结果
     */


    JsonVO<String> updateUnitType(UnitTypeModifyDTO dto);




    /**
     * 批量删除单位类型
     * @param ids 逗号分隔的ID字符串
     * @return 操作结果
     */
    JsonVO<String> deleteBatchUnitType  (List<String> ids);




    /**
     * 导出单位类型数据
     * @param query 导出条件（可选）
     * @return 文件流
     */
    ResponseEntity<byte[]>  exportUnitType(UnitTypeQuery query);

    /**
     * 完成单位类型excel导入
     * @param file 文件
     * @return
     */
    JsonVO<String> importExcel(MultipartFile file);

    /**
     *  获取单位类型名称列表
     * @param
     * @return 响应数据结果
     */
    JsonVO<List<String>> getUnitTypeNameList ();

    /**
     *  获取单位类型列表（条件+分页）
     * @param unitTypeListQuery 单位类型查询
     * @return 响应数据结果
     */
    JsonVO<PageDTO<UnitTypeListDTO>> getUnitTypeList(UnitTypeListQuery unitTypeListQuery);

}
