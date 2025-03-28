package com.zeroone.star.outgoodsmanage.entity;

import com.baomidou.mybatisplus.annotation.TableName;
import lombok.Getter;
import lombok.Setter;

import java.io.Serializable;

@Getter
@Setter
@TableName("zo_wms.tms_yw_dingdan")
public class TransportOrderDetailDO implements Serializable {

    private String fahuoren;

    private String fadh;

    private String jiage;

    private String ywddbz;

}
