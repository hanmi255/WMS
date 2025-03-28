package com.zeroone.star.j5.basezl.service;

import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.j5.basezl.entity.rfid.RfidBuseDO;
import com.zeroone.star.j5.basezl.entity.rfid.RfidBuseExcelDO;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j5.basezl.rfid.RFIDAddDTO;
import com.zeroone.star.project.dto.j5.basezl.rfid.RFIDDetailDTO;
import com.zeroone.star.project.dto.j5.basezl.rfid.RFIDListDTO;
import com.zeroone.star.project.dto.j5.basezl.rfid.RFIDModifyDTO;
import com.zeroone.star.project.query.j5.basezl.rfid.RFIDQuery;

import java.util.List;
public interface RFIDService extends IService<RfidBuseDO> {
     PageDTO<RFIDListDTO> queryRFIDAll(RFIDQuery rfidQuery);
     RFIDDetailDTO queryRFIDDetail(String rfid);
     String addRfid(RFIDAddDTO rfidAddDTO);
     String modifyRfid(RFIDModifyDTO rfidModifyDTO);
     void deleteRfid(List<Long> rfidList);

     //用于excel到出库,从数据库中查询所有数据
     List<RfidBuseExcelDO> selectAll();

     //用于excel到出库,从数据库中查询单条数据
     List<RfidBuseExcelDO> selectById(Long id);
}
