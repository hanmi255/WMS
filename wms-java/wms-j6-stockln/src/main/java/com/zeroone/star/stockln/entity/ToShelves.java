package com.zeroone.star.stockln.entity;

import com.baomidou.mybatisplus.annotation.TableName;
import com.fasterxml.jackson.annotation.JsonFormat;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;
import lombok.ToString;

import java.io.Serializable;
import java.time.LocalDateTime;

@Data
@ToString
@ApiModel("待上架货物实体类")
@TableName("wm_in_qm_i")
public class ToShelves implements Serializable {
  @ApiModelProperty(value = "主键id",example = "2c9efaca91697e98019226d963871c19")
  private String id;

  @ApiModelProperty(value = "创建人名字",example = "管理员")
  private String createName;

  @ApiModelProperty(value = "创建人对象",example = "admin")
  private String createBy;

  @ApiModelProperty(value = "创建日期",example = "2024-10-16 10:05:57")
  private LocalDateTime createDate;

  @ApiModelProperty(value = "更新日期",example = "2024-10-16 10:05:57")
  private LocalDateTime updateDate;

  @ApiModelProperty(value = "所属部门",example = "A05")
  private String sysOrgCode;

  @ApiModelProperty(value = "所属公司",example = "XXXX-KH有限公司")
  private String sysCompanyCode;

  @ApiModelProperty(value = "到货通知ID",example = "2c9efaca91697e98019226efea7b1c2e")
  private String imNoticeId;

  @ApiModelProperty(value = "客户",example = "XXXX-KH有限公司")
  private String cusCode;

  @ApiModelProperty(value = "更新人名称")
  private String updateName;

  @ApiModelProperty(value = "更新人登录名称")
  private String updateBy;

  @ApiModelProperty(value = "到货通知行项目")
  private String imNoticeItem;

  @ApiModelProperty(value = "商品编码")
  private String goodsId;

  @ApiModelProperty(value = "到货数量")
  private String imQuat;

  @ApiModelProperty(value = "收货数量")
  private String qmOkQuat;

  @ApiModelProperty(value = "备注")
  private String itemText;

  @ApiModelProperty(value = "生产日期")
  private String proData;

  @ApiModelProperty(value = "托盘")
  private String tinId;

  @ApiModelProperty(value = "单位")
  private String goodsUnit;

  @ApiModelProperty(value = "批次")
  private String goodsBatch;

  @ApiModelProperty(value = "仓位")
  private String binId;

  @ApiModelProperty(value = "体积")
  private String tinTj;

  @ApiModelProperty(value = "重量")
  private String tinZhl;

  @ApiModelProperty(value = "是否已上架")
  private String binSta;

  @ApiModelProperty(value = "温度")
  private String recDeg;

  @ApiModelProperty(value = "基本单位")
  private String baseUnit;

  @ApiModelProperty(value = "基本单位数量")
  private String baseGoodscount;

  @ApiModelProperty(value = "更新人登录名称")
  private String baseQmcount;

  @ApiModelProperty(value = "客户名称")
  private String cusName;

  @ApiModelProperty(value = "货物名字")
  private String goodsName;

  @ApiModelProperty(value = "入库单号")
  private String imCusCode;

  @ApiModelProperty(value = "入库货物数量")
  private String baseInGoodscount;

  @ApiModelProperty(value = "出库货物数量")
  private String baseOutGoodscount;

}
