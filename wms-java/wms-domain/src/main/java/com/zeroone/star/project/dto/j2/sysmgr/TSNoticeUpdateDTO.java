package com.zeroone.star.project.dto.j2.sysmgr;

import com.baomidou.mybatisplus.annotation.TableId;
import com.fasterxml.jackson.annotation.JsonFormat;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;
import lombok.Getter;
import lombok.Setter;
import lombok.ToString;

import java.io.Serializable;
import java.util.Date;
import java.util.List;

/**
 * @Author: hjm
 * @Date: 2025/02/22/20:29
 * @Description:
 */
@Getter
@Setter
@ToString
@ApiModel("公告修改数据模型")
public class TSNoticeUpdateDTO implements Serializable {

    /**
     * ID
     */
    @ApiModelProperty(value = "ID", example = "12345678910")
    private String id;
    /**
     * 通知标题
     */
    @ApiModelProperty(value = "通知标题", example = "通知标题")
    private String noticeTitle;

    /**
     * 通知公告内容
     */
    @ApiModelProperty(value = "通知公告内容", example = "通知公告内容")
    private String noticeContent;

    /**
     * 通知公告类型（1：通知，2:公告）
     */
    @ApiModelProperty(value = "通知公告类型（1：通知，2:公告）", example = "1")
    private String noticeType;


    /**
     * 角色ID
     */
    @ApiModelProperty(value = "角色ID", example = "12345678910")
    private List<String> RoleId;

    /**
     * 角色名称
     */
    @ApiModelProperty(value = "角色名称", example = "角色1")
    private String RoleName;

    /**
     * 通告授权级别（1:全员，2：角色，3：用户）
     */
    @ApiModelProperty(value = "通告授权级别（1:全员，2：角色，3：用户）", example = "1")
    private String noticeLevel;

    /**
     * 用户ID
     */
    @ApiModelProperty(value = "用户ID", example = "12345678910")
    private List<String> UserId;

    /**
     * 用户名称
     */
    @ApiModelProperty(value = "用户名称", example = "用户1")
    private String UserName;

    /**
     * 阅读期限
     */
    @ApiModelProperty(value = "阅读期限", example = "2025-02-22")
    @JsonFormat(pattern = "yyyy-MM-dd", timezone = "GMT+8")
    private Date noticeTerm;

    /**
     * 创建者
     */
    @ApiModelProperty(value = "创建者", example = "创建者1")
    private String createUser;

    /**
     * 创建时间
     */
    @ApiModelProperty(value = "创建时间", example = "2025-02-22")
    @JsonFormat(pattern = "yyyy-MM-dd", timezone = "GMT+8")
    private Date createTime;

}
