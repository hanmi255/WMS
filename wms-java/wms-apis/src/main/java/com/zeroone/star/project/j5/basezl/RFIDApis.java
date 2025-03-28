package com.zeroone.star.project.j5.basezl;

import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j5.basezl.customer.CustomerAddDTO;
import com.zeroone.star.project.dto.j5.basezl.customer.CustomerListDTO;
import com.zeroone.star.project.dto.j5.basezl.rfid.RFIDAddDTO;
import com.zeroone.star.project.dto.j5.basezl.rfid.RFIDDetailDTO;
import com.zeroone.star.project.dto.j5.basezl.rfid.RFIDListDTO;
import com.zeroone.star.project.dto.j5.basezl.rfid.RFIDModifyDTO;
import com.zeroone.star.project.query.j5.basezl.customer.CustomerQuery;
import com.zeroone.star.project.query.j5.basezl.rfid.RFIDQuery;
import com.zeroone.star.project.vo.JsonVO;
import org.springframework.http.ResponseEntity;
import org.springframework.web.multipart.MultipartFile;

import java.util.List;


/**
 * <p>
 * 描述：RFID数据接口
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 * @author j5-双巾
 * @version 1.0.0
 */
public interface RFIDApis {
  /*  *//**
     * 查询客户信息列表
     * @param query 查询条件
     * @return 响应数据结果
     *//*
    JsonVO<PageDTO<CustomerListDTO>> queryAll(CustomerQuery query);

    *//**
     * 新增客户信息
     * @param dto 客户信息
     * @return 响应数据结果
     *//*
    JsonVO<String> addCus(CustomerAddDTO dto);
*/
    /**
     * 查询RFID信息列表
     * @param rfidQuery 查询条件
     * @return 响应数据结果
     */
    JsonVO<PageDTO<RFIDListDTO>>  queryRFIDAll(RFIDQuery rfidQuery);

    /**
     * 获取RFID相信信息列表
     * @param rfid RFID号
     * @return 响应数据结果
     */
    JsonVO<RFIDDetailDTO>  queryRFIDDetail(String rfid);

    /**
     * 新增RFID
     * @param rfidAddDTO RFID信息
     * @return 响应数据结果
     */
    JsonVO<String> addRfid(RFIDAddDTO rfidAddDTO);

    /**
     * 新增RFID
     * @param rfidModifyDTO RFID修改信息
     * @return 响应数据结果
     */
    JsonVO<String> modifyRfid(RFIDModifyDTO rfidModifyDTO);

    /**
     * 删除RFID(支持批量删除)
     * @param rfidList RFID号
     * @return 响应数据结果
     */
    JsonVO<String> deleteRfid(List<Long> rfidList);

    /**
     * 导入RFID
     * @param file 导入文件
     * @return 响应数据结果
     */
    public JsonVO<String> uploadFile(MultipartFile file);

    /**
     * 导出RFID
     * @return 响应数据结果
     */
    public ResponseEntity<byte[]> expoExcel(Long id);

}
