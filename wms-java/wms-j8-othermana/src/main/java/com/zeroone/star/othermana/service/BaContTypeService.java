package com.zeroone.star.othermana.service;

import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.othermana.entity.BaContType;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j8.other.baconttype.BaContTypeDTO;
import com.zeroone.star.project.query.j8.other.baconttype.BaContTypeQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.j8.other.baconttype.BaContTypeVO;
import org.springframework.http.ResponseEntity;
import org.springframework.web.multipart.MultipartFile;

import java.util.List;

public interface BaContTypeService extends IService<BaContType> {
    /**
     * 分页查询箱型
     * @param  baContTypeQuery 查询数据
     * @return 箱型列表查询结果
     */
    PageDTO<BaContTypeVO> pageQuery(BaContTypeQuery baContTypeQuery);

    /**
     * 查询箱型详情
     * @param id 查询数据
     * @return 箱型查询结果
     */
    JsonVO<BaContTypeVO> queryBaContType(String id);

    /**
     * 添加箱型
     * @param dto 添加数据
     * @return 箱型添加结果
     */
    void addBaContType(BaContTypeDTO dto);

    /**
     * 修改箱型
     * @param dto 修改数据
     * @return 箱型修改结果
     */
    void updateById(BaContTypeDTO dto);

    /**
     * 删除箱型
     * @param ids 删除数据
     * @return 箱型删除结果
     */
    void removeBaContType(List<String> ids);

    /**
     * 导出箱型excel表
     * @return
     */
    ResponseEntity<byte[]> exportExcel();

    /**
     * 导入箱型excel表
     * @param file excel表
     */
    void importExcel(MultipartFile file);
}