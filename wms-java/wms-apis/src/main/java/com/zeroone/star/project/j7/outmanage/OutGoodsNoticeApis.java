package com.zeroone.star.project.j7.outmanage;

import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j7.outmanage.FileInfoDTO;
import com.zeroone.star.project.dto.j7.outmanage.OutGoodsNoticeFormDTO;
import com.zeroone.star.project.dto.j7.outmanage.OutNoticeItemDTO;
import com.zeroone.star.project.dto.j7.outmanage.OutNoticeListDTO;
import com.zeroone.star.project.query.j7.outnotice.OutGoodNoticeQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.ResultStatus;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.bind.annotation.RequestParam;

import io.swagger.annotations.ApiOperation;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.multipart.MultipartFile;

import java.util.List;

/**
 * 描述：出货通知接口
 * @author 做了错饭
 */
public interface OutGoodsNoticeApis {

    /**
     * 获取出货通知列表(分页+条件查询)
     * @param outGoodNoticeQuery 条件查询对象
     * @return
     */
    JsonVO<PageDTO<OutNoticeListDTO>> getGoodsNoticeList(OutGoodNoticeQuery outGoodNoticeQuery);

    /**
     * 获取出货通知
     * @param omNoticeId 出货单号
     * @return
     */
    JsonVO<OutNoticeItemDTO> getGoodsItem(String omNoticeId);

    /**
     * 上传附件
     * @param upFile 上传文件
     * @return
     */
    JsonVO<FileInfoDTO> uploadFuJan(MultipartFile upFile, String omNoticeId);

    /**
     * @Author: ayuan
     * @Date: 2025/3/1
     * @Description: 录入出库通知单
     **/
    JsonVO<ResultStatus> addOutGoodsNotice(OutGoodsNoticeFormDTO outGoodsNoticeFormDTO);

    /**
     * @Author: ayuan
     * @Date: 2025/3/1
     * @Description: 打印拣货单——pdf
     **/
    ResponseEntity<byte[]> queryPickingList(String id);

    /**
     * @Author: ayuan
     * @Date: 2025/3/1
     * @Description: 打印出库单——pdf
     **/
    ResponseEntity<byte[]> queryOutGoodsList(String id);
}