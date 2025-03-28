package com.zeroone.star.project.j6.stockln;

import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j6.stockln.ImportNoticeDetailHeadDTO;
import com.zeroone.star.project.dto.j6.stockln.ImportNoticeListDTO;
import com.zeroone.star.project.dto.j6.stockln.ImportNoticeDTO;
import com.zeroone.star.project.query.j6.stockln.ImportNoticeQuery;
import com.zeroone.star.project.vo.JsonVO;
import org.springframework.http.ResponseEntity;
import org.springframework.web.multipart.MultipartFile;

/**
 * 入库通知单管理
 *
 */
public interface ImNoticeHApis {

    /**
     * 查询入库通知单列表
     * @param query 查询条件
     * @return 响应数据结果
     */
    JsonVO<PageDTO<ImportNoticeListDTO>> list(ImportNoticeQuery query);

    /**
     * 上传附件
     * @param multipartFile
     * @return 响应数据结果，地址
     */
    JsonVO<String> upload(MultipartFile multipartFile) throws Exception;

    /**
     * 根据Id查询单个预约通知单详细信息
     * @param id
     * @return
     */
    JsonVO<ImportNoticeDTO> getDetailsById(String id);



    /**
    * 修改入库通知单
    * */
    JsonVO<Object> updateImport(ImportNoticeDTO importNoticeDTO);

    /**
     * 完成入库通知单
     * */
    JsonVO<Object> confirmImport(String id);

    /**
     * 删除入库通知单
     * */
    JsonVO<Object> deleteImport(String id);

    JsonVO<Object> insertImport(ImportNoticeDTO importNoticeDTO);

    /**
    * 导出单个入库单
    * */
    ResponseEntity export(String id);
}
