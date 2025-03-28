package com.zeroone.star.othermana.service;

import com.zeroone.star.othermana.entity.BaPort;
import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j8.other.port.PortAddDTO;
import com.zeroone.star.project.dto.j8.other.port.PortBaseDTO;
import com.zeroone.star.project.dto.j8.other.port.PortModifyDTO;
import com.zeroone.star.project.query.j8.other.port.PortQuery;
import com.zeroone.star.project.vo.JsonVO;
import org.springframework.web.multipart.MultipartFile;

import java.util.List;

/**
 * <p>
 *  服务类
 * </p>
 *
 * @author yjq
 * @since 2025-02-26
 */
public interface IBaPortService extends IService<BaPort> {
    /**
     * 分页查询港口信息
     * @param query 查询条件
     * @return 查询数据
     */
    PageDTO<PortBaseDTO> listPort(PortQuery query);

    /**
     * 新增港口信息
     * @param dto 新增的数据
     * @return 结果，成功or失败
     */
    JsonVO<String> addPort(PortAddDTO dto);

    /**
     * 删除港口信息
     * @param id 删除港口的id
     * @return 结果，成功or失败
     */
    JsonVO<String> removePort(String id);

    /**
     * 修改港口信息
     * @param dto 修改港口的信息
     * @return 结果，成功or失败
     */
    JsonVO<String> updatePort(PortModifyDTO dto);

    /**
     * 导出所有港口信息
     *
     * @param
     * @return 查询数据-excel
     */
    List<BaPort> exportPort();

    /**
     * 导入所有港口信息
     * @param file 港口数据excel
     * @return 结果，成功or失败
     */
    JsonVO<String> importPort(MultipartFile file);
}
