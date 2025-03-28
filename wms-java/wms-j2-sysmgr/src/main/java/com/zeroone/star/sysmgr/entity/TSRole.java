package com.zeroone.star.sysmgr.entity;

import com.baomidou.mybatisplus.annotation.TableName;
import lombok.Data;

import java.io.Serializable;
import java.util.Date;

@Data
@TableName("t_s_role")
public class TSRole  implements Serializable {
    private static final long serialVersionUID = 1L;
    /**
     * 主键
     */
    private String id;
    /**
     * 角色编码
     */
    private String rolecode;
    /**
     * 角色名字
     */
    private String rolename;
    /**
     * 修改人
     */
    private String updatedname;
    /**
     * 修改时间
     */
    private Date updateDate;
    /**
     * 修改人id
     */
    private String updateBy;
    /**
     * 创建人
     */
    private String createName;
    /**
     * 创建时间
     */
    private String createDate;
    /**
     * 创建人id
     */
    private String createBy;
}
