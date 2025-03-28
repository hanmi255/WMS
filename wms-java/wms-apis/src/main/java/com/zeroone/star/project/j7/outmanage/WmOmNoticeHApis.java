package com.zeroone.star.project.j7.outmanage;

import com.zeroone.star.project.dto.j7.outmanage.WonhDTO;
import com.zeroone.star.project.query.j7.outbound.WonQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.ResultStatus;
import org.springframework.http.ResponseEntity;

public interface WmOmNoticeHApis {

    /**
     * 删除出库通知单
     * @param id
     * @return
     */
    JsonVO<Long> removeNoticeH(Long id);


    ResponseEntity<byte[]> queryWonh(WonQuery query) throws Exception;
    JsonVO<String> modifyWonh(WonhDTO modify);
    ResponseEntity<byte[]> queryWoni(WonQuery query) throws Exception;
}
