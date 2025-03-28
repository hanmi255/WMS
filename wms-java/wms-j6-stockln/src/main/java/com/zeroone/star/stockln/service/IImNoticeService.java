package com.zeroone.star.stockln.service;

import com.zeroone.star.project.dto.j6.stockln.ImportNoticeDTO;
import org.springframework.http.ResponseEntity;

public interface IImNoticeService {

    void updateImport(ImportNoticeDTO importNoticeDTO);

    void insertImport(ImportNoticeDTO importNoticeDTO);

    //查询入库通知单详细信息
    ImportNoticeDTO searchImport(String imNoticeId);

    ResponseEntity export(String id);
}
