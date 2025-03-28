package com.zeroone.star.j5.basezl.entity.rfid;

import java.lang.String;
import java.time.LocalDateTime;

import com.baomidou.mybatisplus.annotation.*;
import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;



/**
 * @author meiqin liu
 * @date 2025/2/26 21:40
 */
@Data
@AllArgsConstructor
@NoArgsConstructor
@TableName("rfid_buse")
public class RfidBuseDO implements java.io.Serializable {
    /**主键*/
    @TableId(value = "id", type = IdType.AUTO)
    private Long id;
    /**
     * 创建人名称
     */
    @TableField(fill = FieldFill.INSERT)
    private String createName;

    /**
     * 创建人登录名称
     */
    @TableField(fill = FieldFill.INSERT)
    private String createBy;

    /**
     * 创建日期
     */
    @TableField(fill = FieldFill.INSERT)
    private LocalDateTime createDate;

    /**
     * 更新人名称
     */
    @TableField(fill = FieldFill.INSERT_UPDATE)
    private String updateName;

    /**
     * 更新人登录名称
     */
    @TableField(fill = FieldFill.INSERT_UPDATE)
    private String updateBy;

    /**
     * 更新日期
     */
    @TableField(fill = FieldFill.INSERT_UPDATE)
    private LocalDateTime updateDate;

    /**
     * 所属部门
     */
    @TableField(fill = FieldFill.INSERT_UPDATE)
    private String sysOrgCode;

    /**
     * 所属公司
     */
    @TableField(fill = FieldFill.INSERT_UPDATE)
    private String sysCompanyCode;
    /**流程状态*/
    private String bpmStatus;
    /**类型*/
    private String rfidType;
    /**业务编号*/
    private String rfidBuseno;
    /**业务内容*/
    private String rfidBusecont;
    /**RFID1*/
    private String rfidId1;
    /**RFID2*/
    private String rfidId2;
    /**RFID3*/
    private String rfidId3;
}

