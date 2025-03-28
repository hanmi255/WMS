package com.zeroone.star.outgoodsmanage.entity;

import com.baomidou.mybatisplus.annotation.TableName;
import java.io.Serializable;
import lombok.Getter;
import lombok.Setter;

/**
 * <p>
 * VIEW
 * </p>
 *
 * @author PingShui
 * @since 2025-03-11
 */
@Getter
@Setter
@TableName("mv_cus")
public class MvCus implements Serializable {

    private static final long serialVersionUID = 1L;

    /**
     * 主键
     */
    private String id;

    /**
     * 客户编码
     */
    private String cusCode;

    private String cusName;


}
