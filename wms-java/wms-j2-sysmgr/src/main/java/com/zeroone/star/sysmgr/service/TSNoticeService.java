package com.zeroone.star.sysmgr.service;

import com.zeroone.star.project.dto.j2.sysmgr.TSNoticeAddDTO;
import com.zeroone.star.project.dto.j2.sysmgr.TSNoticeUpdateDTO;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j2.sysmgr.TSNoticeDTO;
import com.zeroone.star.project.query.PageQuery;
import com.zeroone.star.sysmgr.entity.TSNotice;
import com.baomidou.mybatisplus.extension.service.IService;

import javax.servlet.http.HttpServletRequest;
import java.util.List;

/**
* @author hjm
* @description 针对表【t_s_notice(通知公告表)】的数据库操作Service
* @createDate 2025-02-22 00:02:22
*/
public interface TSNoticeService extends IService<TSNotice> {

    /**
<<<<<<< HEAD
     * 录入公告
     * @param tsNoticeAddDTO
     * @return
     */
    Boolean addNotice(TSNoticeAddDTO tsNoticeAddDTO);

    /**
     * 修改公告
     * @param tsNoticeUpdateDTO
     *
     * @return
     */
    Boolean updateNotice(TSNoticeUpdateDTO tsNoticeUpdateDTO);

    /**
     * 删除公告（支持批量删除）
     * @param ids
     */
    Boolean deleteBatchNotice(List<String> ids);

    /**
     * 获取公告列表（分页）
     * @return
     */
    PageDTO<TSNoticeDTO> getAnnouncementPage(PageQuery pageQuery);

    /**
     *
     * @param dto
     * @return
     */
    TSNotice getAnnouncementDetail(TSNoticeDTO dto);
}
