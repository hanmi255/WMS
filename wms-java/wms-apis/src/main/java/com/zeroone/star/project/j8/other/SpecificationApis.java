package com.zeroone.star.project.j8.other;

import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j8.other.contspec.SpecificationAddDTO;
import com.zeroone.star.project.dto.j8.other.contspec.SpecificationBaseDTO;
import com.zeroone.star.project.dto.j8.other.contspec.SpecificationDeleteDTO;
import com.zeroone.star.project.dto.j8.other.contspec.SpecificationModifyDTO;
import com.zeroone.star.project.query.j8.other.contspec.SpecificationQuery;
import com.zeroone.star.project.vo.JsonVO;
import org.springframework.http.ResponseEntity;
import org.springframework.web.multipart.MultipartFile;

import java.util.List;

/**
 * <p>
 * 描述：箱规管理接口
 * </p>
 * <p>地址：01星球总部</p>
 * @author xban
 * @version 1.0.0
 */
public interface SpecificationApis {

    /**
     * 查询客户信息列表
     * @param query 查询条件对象
     * @return 返回包含分页信息和查询结果的JsonVO对象
     */
    JsonVO<PageDTO<SpecificationBaseDTO>> querySpecificationList(SpecificationQuery query);

    /**
     * 查看一个箱规信息
     * @param id 箱规id
     * @return 返回包含详细箱规信息的JsonVO对象
     */
    JsonVO<SpecificationBaseDTO> querySpecificationDetails(String id);

    /**
     * 新增箱规
     * @param dto 箱规基础数据传输对象
     * @return 返回操作结果的JsonVO对象
     */
    JsonVO<String> addSpecification(SpecificationAddDTO dto);

    /**
     * 编辑箱规
     * @param dto 箱规基础数据传输对象
     * @return 返回操作结果的JsonVO对象
     */
    JsonVO<String> putSpecification(SpecificationModifyDTO dto);

    /**
     * 批量删除
      * @param dtos 箱规删除数据传输对象列表
     * @return 返回操作结果的JsonVO对象
     */
    JsonVO<String> deleteSpecifications(List<SpecificationDeleteDTO> dtos);

    /**
     * 导出箱规信息为Excel文件
     * @return 返回包含Excel文件下载链接的JsonVO对象
     */
    ResponseEntity<byte[]> exportSpecificationToExcel();

    /**
     * 导入Excel文件中的箱规信息
     * @param file 文件对象，包含Excel文件数据
     * @return 返回导入操作结果的JsonVO对象
     */
    JsonVO<String> importSpecificationFromExcel(MultipartFile file);

}
