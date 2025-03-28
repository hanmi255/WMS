package com.zeroone.star.project.j2.sysmgr;

import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j2.sysmgr.TSNoticeAddDTO;
import com.zeroone.star.project.dto.j2.sysmgr.TSNoticeDTO;
import com.zeroone.star.project.dto.j2.sysmgr.TSNoticeUpdateDTO;
import com.zeroone.star.project.query.PageQuery;
import com.zeroone.star.project.vo.JsonVO;
import javax.servlet.http.HttpServletRequest;
import java.util.List;

/**
 * 系统公告相关接口
 */
public interface AnnouncementApis {


    /**
     * 获取公告列表（分页）
     * @return
     */
    JsonVO<PageDTO<TSNoticeDTO>> getAnnouncementPage(PageQuery pageQuery);


    /**
     *  获取公告详细信息
     * @param dto
     * @return
     */
    JsonVO<TSNoticeDTO> getAnnouncementDetail(TSNoticeDTO dto);

    /**
     * 录入公告
     * @param tsNoticeAddDTO
     *
     * @return
     */
    JsonVO<Boolean> addNotice(TSNoticeAddDTO tsNoticeAddDTO);

    /**
     * 修改公告
     * @param tsNoticeUpdateDTO
     *
     * @return
     */
    JsonVO<Boolean> updateNotice(TSNoticeUpdateDTO tsNoticeUpdateDTO);


    /**
     * 删除公告（支持批量删除）
     * @param ids
     * @return
     */
    JsonVO<Boolean> deleteBatchNotice(List<String> ids);


}
