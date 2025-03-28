package com.zeroone.star.j5.basezl.entity.rfid;

import com.baomidou.mybatisplus.annotation.FieldFill;
import com.baomidou.mybatisplus.annotation.IdType;
import com.baomidou.mybatisplus.annotation.TableField;
import com.baomidou.mybatisplus.annotation.TableId;
import lombok.Data;

import java.time.LocalDateTime;
import java.util.Date;

@Data
public class RfidBuseExcelDO {
    //主键
    @TableId(value = "id", type = IdType.ASSIGN_ID)
    private String id;
    /**创建人登录名称*/
    //@Excel(name="创建人登录名称")
    private String createName;
    /**创建日期*/
    //@Excel(name="创建日期",format = "yyyy-MM-dd")
    private Date createDate;
    //更新日期
    @TableField(fill = FieldFill.INSERT_UPDATE)
    private LocalDateTime updateDate;
    /**类型*/
    // @Excel(name="类型")
    private String rfidType;
    /**业务编号*/
    //@Excel(name="业务编号")
    private String rfidBuseno;
    /**业务内容*/
    //@Excel(name="业务内容")
    private String rfidBusecont;
    /**RFID1*/
    //@Excel(name="RFID1")
    private String rfidId1;
    /**RFID2*/
    // @Excel(name="RFID2")
    private String rfidId2;
    /**RFID3*/
    //@Excel(name="RFID3")
    private String rfidId3;
}