package com.zeroone.star.project.j4.baseConfig;


import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j4.automaticEncoding.AutomaticEncodingDTO;
import com.zeroone.star.project.dto.j4.automaticEncoding.DeleteEncodingDTO;
import com.zeroone.star.project.query.j4.automaticEncoding.AutomaticEncodingQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.j4.automaticEncoding.DeleteEncodingVO;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.bind.annotation.RequestParam;
import org.springframework.web.multipart.MultipartFile;

import java.util.List;

/**
 * @author qiaozhi
 * @title AutomaticEncodingApis
 * @date 2025/2/21 22:00
 * @description 自动编码apis
 */
public interface AutomaticEncodingApis {
    /**
     * 分页查询
     * @param condition 查询条件
     * @return 查询结果
     */
    JsonVO<PageDTO<AutomaticEncodingDTO>> queryAll(AutomaticEncodingQuery condition);

    /**
     * 新增
     * @param dto
     * @return
     */
    JsonVO<AutomaticEncodingDTO> save(AutomaticEncodingDTO dto);

    /**
     * 修改
     * @param dto
     * @return
     */
    JsonVO<AutomaticEncodingDTO> update(AutomaticEncodingDTO dto);


    JsonVO<List<DeleteEncodingVO>> deleteEncoding(@RequestBody DeleteEncodingDTO dto);
    /**
     * 导出自动编码规则制表(支持批量删除)
     * @param  exportDTO 自动编码信息集合(一个或多个)
     * @return 响应数据结果
     */
    ResponseEntity<byte[]> exportExcel(
            @RequestParam String create_name,
            @RequestParam String endDate,
            @RequestParam String[] ids,
            @RequestParam String startDate,
            @RequestParam String exportDTO);
    /**
     * 导入自动编码规则数据
     * @param  file 文件
     * @return 导入结果
     */
    ResponseEntity<String> importExcel(MultipartFile file);

}
