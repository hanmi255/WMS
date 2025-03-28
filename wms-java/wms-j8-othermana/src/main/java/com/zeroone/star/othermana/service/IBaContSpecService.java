package com.zeroone.star.othermana.service;

import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.othermana.entity.BaContSpec;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j8.other.contspec.SpecificationAddDTO;
import com.zeroone.star.project.dto.j8.other.contspec.SpecificationBaseDTO;
import com.zeroone.star.project.dto.j8.other.contspec.SpecificationDeleteDTO;
import com.zeroone.star.project.dto.j8.other.contspec.SpecificationModifyDTO;
import com.zeroone.star.project.query.j8.other.contspec.SpecificationQuery;
import org.springframework.http.ResponseEntity;
import org.springframework.web.multipart.MultipartFile;

import java.util.List;

/**
 * <p>
 *  服务类
 * </p>
 *
 * @author xban
 * @since 2025-02-27
 */
public interface IBaContSpecService extends IService<BaContSpec> {
    /**
     * 查询客户信息列表
     * @param query 查询条件对象
     * @return 返回分页信息和查询结果
     */
    public PageDTO<SpecificationBaseDTO> listAll(SpecificationQuery query);

    /**
     * 查看一个箱规信息
     * @param id 箱规id
     * @return 返回详细箱规信息
     */
    public SpecificationBaseDTO getById(String id);

    /**
     * 新增箱规
     * @param dto 箱规基础数据传输对象
     * @return 返回操作结果
     */
    public int addSpecification(SpecificationAddDTO dto);

    /**
     * 编辑箱规
     * @param dto 箱规基础数据传输对象
     * @return 返回操作结果
     */
    public int putSpecification(SpecificationModifyDTO dto);

    /**
     * 批量删除
     * @param dtos 箱规删除数据传输对象列表
     * @return 返回操作结果
     */
    public int deleteSpecifications(List<SpecificationDeleteDTO> dtos);

    /**
     * 导入数据
     * @param file 需要导入的excel文件
     * @return 导入结果，返回受影响的行数
     */
    public int importExcel(MultipartFile file);

    /**
     * 导出数据
     * @return excel文件字节流
     */
    public ResponseEntity<byte[]> exportExcel();
}
