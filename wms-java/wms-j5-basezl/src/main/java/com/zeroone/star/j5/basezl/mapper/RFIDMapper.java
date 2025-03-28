package com.zeroone.star.j5.basezl.mapper;

import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import com.zeroone.star.j5.basezl.entity.rfid.RfidBuseDO;
import com.zeroone.star.j5.basezl.entity.rfid.RfidBuseExcelDO;
import org.apache.ibatis.annotations.Delete;
import org.apache.ibatis.annotations.Mapper;
import org.apache.ibatis.annotations.Select;

import java.util.List;

@Mapper
public interface RFIDMapper extends BaseMapper<RfidBuseDO>{
    //根据rfid id删除
    @Delete("delete from zo_wms.rfid_buse where id = #{id}")
    void deleteByid(Long id);

    List<RfidBuseExcelDO> selectAll();

    @Select("select create_name,create_date,rfid_type,rfid_buseno,rfid_busecont,rfid_id1,rfid_id2,rfid_id3 from zo_wms.rfid_buse where id = #{id}")
    List<RfidBuseExcelDO> selectByRfiId(Long id);


//    void insertRfid(Long id,RFIDAddDTO rfidAddDTO);
}


    //查询所有
    /*@Select("select create_name,create_date,rfid_type,rfid_buseno,rfid_busecont,rfid_id1,rfid_id2,rfid_id3 from zo_wms.rfid_buse")*/

//我这好像导入游问题 ，其他两个没问题