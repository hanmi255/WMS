package com.zeroone.star.j5.basezl.entity.cusother;

import com.alibaba.excel.annotation.ExcelProperty;
import lombok.Data;

import javax.validation.constraints.NotBlank;
import java.util.Date;

/**
 * <p>
 * 描述: 用于Excel报表导入导出
 * </p>
 * <p>版权所有: &copy;枢璇</p>
 *
 * @author 枢璇
 * @Version 1.0.0
 * @since 2025/2/23 12:31
 */
@Data
public class CusOther4Excel {

    @ExcelProperty(value = "所属客户", index = 0)
    private String suoShuKeHu;

    @ExcelProperty(value = "中文全称", index = 1)
    private String zhongWenQch;

    @ExcelProperty(value = "助记码", index = 2)
    private String zhuJiMa;

    @ExcelProperty(value = "客户简称", index = 3)
    private String keHuJianCheng;

    @NotBlank(message = "客户编码不能为空")
    @ExcelProperty(value = "客户编码", index = 4)
    private String keHuBianMa;

    @ExcelProperty(value = "客户英文名称", index = 5)
    private String keHuYingWen;

    @ExcelProperty(value = "曾用企业代码", index = 6)
    private String zengYongQi;

    @ExcelProperty(value = "曾用企业名称", index = 7)
    private String zengYongQiYe;

    @ExcelProperty(value = "客户状态", index = 8)
    private String keHuZhuangTai;

    @ExcelProperty(value = "企业属性", index = 9)
    private String xingYeFenLei;

    @ExcelProperty(value = "客户等级", index = 10)
    private String keHuDengJi;

    @ExcelProperty(value = "所属行业", index = 11)
    private String suoShuXingYe;

    @ExcelProperty(value = "首签日期", index = 12)
    private Date shouQianRiQi;

    @ExcelProperty(value = "终止合作时间", index = 13)
    private Date zhongZhiHeShiJian;

    @ExcelProperty(value = "申请时间", index = 14)
    private Date shenQingShiJian;

    @ExcelProperty(value = "客户属性", index = 15)
    private String keHuShuXing;

    @ExcelProperty(value = "归属组织代码", index = 16)
    private String guiShuZuZh;

    @ExcelProperty(value = "归属省份代码", index = 17)
    private String guiShuSheng;

    @ExcelProperty(value = "归属市代码", index = 18)
    private String guiShuShiDai;

    @ExcelProperty(value = "归属县区代码", index = 19)
    private String guiShu;

    @ExcelProperty(value = "地址", index = 20)
    private String diZhi;

    @ExcelProperty(value = "邮政编码", index = 21)
    private String youZhengBianMa;

    @ExcelProperty(value = "主联系人", index = 22)
    private String zhuLianXiRen;

    @ExcelProperty(value = "电话", index = 23)
    private String dianHua;

    @ExcelProperty(value = "手机", index = 24)
    private String shouJi;

    @ExcelProperty(value = "传真", index = 25)
    private String chuanZhen;

    @ExcelProperty(value = "Email地址", index = 26)
    private String emaildiZhi;

    @ExcelProperty(value = "网页地址", index = 27)
    private String wangYeDiZhi;

    @ExcelProperty(value = "法人代表", index = 28)
    private String faRenDaiBiao;

    @ExcelProperty(value = "法人身份证号", index = 29)
    private String faRenShenFen;

    @ExcelProperty(value = "注册资金万元", index = 30)
    private String zhuCeZiJin;

    @ExcelProperty(value = "币别", index = 31)
    private String biBie;

    @ExcelProperty(value = "营业执照号", index = 32)
    private String yingYeZhiZhao;

    @ExcelProperty(value = "税务登记证号", index = 33)
    private String shuiWuDeng;

    @ExcelProperty(value = "组织机构代码证", index = 34)
    private String zuZhiJiGou;

    @ExcelProperty(value = "道路运输经营许可证", index = 35)
    private String daoLuYunShu;

    @ExcelProperty(value = "主营业务", index = 36)
    private String zhuYingYeWu;

    @ExcelProperty(value = "合作意向", index = 37)
    private String heYiXiang;

    @ExcelProperty(value = "批准机关", index = 38)
    private String piZhunJiGuan;

    @ExcelProperty(value = "批准文号", index = 39)
    private String piZhunWenHao;

    @ExcelProperty(value = "注册日期", index = 40)
    private Date zhuCeRiQi;

    @ExcelProperty(value = "备注", index = 41)
    private String beiZhu;

    @ExcelProperty(value = "联系人1", index = 42)
    private String zhuLianXiRen1;

    @ExcelProperty(value = "电话1", index = 43)
    private String dianHua1;

}
