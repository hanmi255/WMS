package com.zeroone.star.outgoodsmanage.entity;

import com.baomidou.mybatisplus.annotation.TableName;
import lombok.Getter;
import lombok.Setter;

import java.io.Serializable;

/**
 * <p>
 * 描述：按单拣货实体类
 * </p>
 *
 * @author chen
 * @since 2025/2/25 21:54
 */

@Getter
@Setter
@TableName()
public class AnDanPickDO implements Serializable {

    //序列码
    private static final long serialVersionUID = 1L;


    private String id;

}
