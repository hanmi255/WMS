package com.zeroone.star.daycheck.entity;

import com.baomidou.mybatisplus.annotation.IdType;
import com.baomidou.mybatisplus.annotation.TableField;
import com.baomidou.mybatisplus.annotation.TableId;
import com.baomidou.mybatisplus.annotation.TableName;
import lombok.Data;
import lombok.Getter;
import lombok.Setter;
import lombok.ToString;


import java.time.LocalDateTime;

@Data
@ToString
@Getter
@Setter
@TableName("wm_im_notice_h")
public class Delay {
    @TableId(value = "id", type = IdType.AUTO)
    private String id;

    @TableField("create_name")
    private String createName;

    @TableField("create_date")
    private LocalDateTime createDate;

    @TableField("sup_name")
    private String supName;

    @TableField("im_data")
    private LocalDateTime imData;

    @TableField("im_car_dri")
    private String imCarDri;

    @TableField("im_car_mobile")
    private String imCarMobile;

    @TableField("im_beizhu")
    private String imBeizhu;

    @TableField("im_car_no")
    private String imCarNo;

    @TableField("im_sta")
    private String imSta;

    @TableField("notice_id")
    private String noticeId;
}