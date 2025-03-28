package com.zeroone.star.project.vo.j5.basezl;

import io.swagger.annotations.ApiModelProperty;
import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;

import javax.validation.constraints.NotBlank;


/**
 * <p>
 * 描述: 第三方客户单查VO
 * </p>
 * <p>版权所有: &copy;枢璇</p>
 *
 * @author 枢璇
 * @Version 1.0.0
 * @since 2025/2/23 10:58
 */
@Data
@AllArgsConstructor
@NoArgsConstructor
public class CusOtherVO {

    @ApiModelProperty(value = "客户状态", example = "正常")
    private String keHuZhuangTai;

    @ApiModelProperty(value = "终止合作时间", example = "2025-02-22 21:47:17")
    private String zhongZhiHeShiJian;

    @ApiModelProperty(value = "批准机关", example = "北京市工商局")
    private String piZhunJiGuan;

    @ApiModelProperty(value = "批准文号", example = "京工商批字[2025]第0001号")
    private String piZhunWenHao;

    @ApiModelProperty(value = "首签日期", example = "2025-02-22 21:46:17")
    private String shouQianRiQi;

    @ApiModelProperty(value = "申请时间", example = "2025-02-22 21:47:17")
    private String shenQingShiJian;

    @ApiModelProperty(value = "所属客户", example = "客户A")
    private String suoShuKeHu;

    @ApiModelProperty(value = "中文全称", example = "零壹星球")
    private String zhongWenQch;

    @ApiModelProperty(value = "助记码", example = "01STAR")
    private String zhuJiMa;

    @ApiModelProperty(value = "客户简称", example = "01星球")
    private String keHuJianCheng;

    @NotBlank(message = "客户编码不能为空")
    @ApiModelProperty(value = "客户编码", example = "01")
    private String keHuBianMa;

    @ApiModelProperty(value = "客户英文名称", example = "01star")
    private String keHuYingWen;

    @ApiModelProperty(value = "曾用企业代码", example = "01star666")
    private String zengYongQi;

    @ApiModelProperty(value = "曾用企业名称", example = "零壹星球有限公司")
    private String zengYongQiYe;

    @ApiModelProperty(value = "企业属性", example = "集体企业")
    private String xingYeFenLei;

    @ApiModelProperty(value = "客户等级", example = "优先")
    private String keHuDengJi;

    @ApiModelProperty(value = "所属行业", example = "教培")
    private String suoShuXingYe;

    @ApiModelProperty(value = "客户属性", example = "教培")
    private String keHuShuXing;

    @ApiModelProperty(value = "归属组织代码", example = "ORG001")
    private String guiShuZuZh;

    @ApiModelProperty(value = "归属省份代码", example = "SHENG001")
    private String guiShuSheng;

    @ApiModelProperty(value = "归属市代码", example = "SHI001")
    private String guiShuShiDai;

    @ApiModelProperty(value = "归属县区代码", example = "XIAN001")
    private String guiShu;

    @ApiModelProperty(value = "地址", example = "PRC")
    private String diZhi;

    @ApiModelProperty(value = "邮政编码", example = "441000")
    private String youZhengBianMa;

    @ApiModelProperty(value = "主联系人", example = "张三")
    private String zhuLianXiRen;

    @ApiModelProperty(value = "电话", example = "010-12345678")
    private String dianHua;

    @ApiModelProperty(value = "手机", example = "13800000000")
    private String shouJi;

    @ApiModelProperty(value = "传真", example = "010-87654321")
    private String chuanZhen;

    @ApiModelProperty(value = "Email地址", example = "example@example.com")
    private String emaildiZhi;

    @ApiModelProperty(value = "网页地址", example = "http://www.example.com")
    private String wangYeDiZhi;

    @ApiModelProperty(value = "法人代表", example = "70牢登")
    private String faRenDaiBiao;

    @ApiModelProperty(value = "法人身份证号", example = "110101199001011234")
    private String faRenShenFen;

    @ApiModelProperty(value = "注册资金万元", example = "1000")
    private String zhuCeZiJin;

    @ApiModelProperty(value = "币别", example = "CNY")
    private String biBie;

    @ApiModelProperty(value = "营业执照号", example = "123456789012345678")
    private String yingYeZhiZhao;

    @ApiModelProperty(value = "税务登记证号", example = "1234567890")
    private String shuiWuDeng;

    @ApiModelProperty(value = "组织机构代码证", example = "1234567890")
    private String zuZhiJiGou;

    @ApiModelProperty(value = "道路运输经营许可证", example = "1234567890")
    private String daoLuYunShu;

    @ApiModelProperty(value = "主营业务", example = "信息技术服务")
    private String zhuYingYeWu;

    @ApiModelProperty(value = "合作意向", example = "长期合作")
    private String heYiXiang;

    @ApiModelProperty(value = "备注", example = "无")
    private String beiZhu;

    @ApiModelProperty(value = "联系人1", example = "王五")
    private String zhuLianXiRen1;

    @ApiModelProperty(value = "电话1", example = "010-12345678")
    private String dianHua1;
}
