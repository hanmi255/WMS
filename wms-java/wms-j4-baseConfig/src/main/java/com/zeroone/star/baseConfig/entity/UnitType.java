package com.zeroone.star.baseConfig.entity;

import com.baomidou.mybatisplus.annotation.IdType;
import com.baomidou.mybatisplus.annotation.TableId;
import com.baomidou.mybatisplus.annotation.TableName;
import lombok.Getter;
import lombok.Setter;

import java.io.Serializable;
import java.time.LocalDateTime;

/**
 * <p>
 * 计量单位类型
 * </p>
 *
 * @author Dorain
 * @since 2025-02-22
 */
    @Getter
    @Setter
    @TableName("ba_unit_type")
    public class UnitType implements Serializable {

        private static final long serialVersionUID = 1L;

        @TableId(type = IdType.ASSIGN_UUID)
        private String id;

        /**
         * 创建人名称
         */
        private String createName;

        /**
         * 创建人登录名称
         */

        private String createBy;

        /**
         * 创建日期
         */

        private LocalDateTime createDate;

        /**
         * 更新人名称
         */

        private String updateName;

        /**
         * 更新人登录名称
         */

        private String updateBy;

        /**
         * 更新日期
         */
        private LocalDateTime updateDate;

        /**
         * 所属部门
         */
        private String sysOrgCode;

        /**
         * 所属公司
         */
        private String sysCompanyCode;

        /**
         * 单位类型代码
         */
        private String unitTypeCode;

        /**
         * 单位类型名称
         */
        private String unitTypeName;


    }
