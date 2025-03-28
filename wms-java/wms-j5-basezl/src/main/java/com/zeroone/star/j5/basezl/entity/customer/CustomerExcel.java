package com.zeroone.star.j5.basezl.entity.customer;

import com.alibaba.excel.annotation.ExcelProperty;
import lombok.Data;

import java.time.LocalDateTime;

/**
 * <p>
 * 描述: 用于Excel报表导入导出
 * </p>
 * <p>版权所有: &copy;杨芋</p>
 *
 * @author 杨芋
 * @Version 1.0.0
 * @since 2025/2/28
 */
@Data
public class CustomerExcel {
    @ExcelProperty(value = "客户名称", index = 0)
    private String zhongWenQch;

    @ExcelProperty(value = "客户编码", index = 1)
    private String keHuBianMa;

    @ExcelProperty(value = "客户简称", index = 2)
    private String keHuJianCheng;

    @ExcelProperty(value = "客户英文名称", index = 3)
    private String keHuYingWen;

    @ExcelProperty(value = "客户状态", index = 4)
    private String keHuZhuangTai;

    @ExcelProperty(value = "企业属性", index = 5)
    private String xingYeFenLei;

    @ExcelProperty(value = "客户等级", index = 6)
    private String keHuDengJi;

    @ExcelProperty(value = "所属行业", index = 7)
    private String suoShuXingYe;

    @ExcelProperty(value = "首签日期", index = 8)
    private LocalDateTime shouQianRiQi;

    @ExcelProperty(value = "终止合作时间", index = 9)
    private LocalDateTime zhongZhiHeShiJian;

    @ExcelProperty(value = "申请时间", index = 10)
    private LocalDateTime shenQingShiJian;

    @ExcelProperty(value = "客户属性", index = 11)
    private String keHuShuXing;

    @ExcelProperty(value = "地址", index = 12)
    private String diZhi;

    @ExcelProperty(value = "邮政编码", index = 13)
    private String youZhengBianMa;

    @ExcelProperty(value = "主联系人", index = 14)
    private String zhuLianXiRen;

    @ExcelProperty(value = "电话", index = 15)
    private String dianHua;

    @ExcelProperty(value = "手机", index = 16)
    private String shouJi;

    @ExcelProperty(value = "传真", index = 17)
    private String chuanZhen;

    @ExcelProperty(value = "Email 地址", index = 18)
    private String emaildiZhi;

    @ExcelProperty(value = "法人代表", index = 19)
    private String faRenDaiBiao;

    @ExcelProperty(value = "法人身份证号", index = 20)
    private String faRenShenFen;

    @ExcelProperty(value = "注册资金（万元）", index = 21)
    private String zhuCeZiJin;

    @ExcelProperty(value = "币别", index = 22)
    private String biBie;

    @ExcelProperty(value = "营业执照号", index = 23)
    private String yingYeZhiZhao;

    @ExcelProperty(value = "税务登记证号", index = 24)
    private String shuiWuDeng;

    @ExcelProperty(value = "组织机构代码证", index = 25)
    private String zuZhiJiGou;

    @ExcelProperty(value = "道路运输经营许可证", index = 26)
    private String daoLuYunShu;

    @ExcelProperty(value = "主营业务", index = 27)
    private String zhuYingYeWu;

    @ExcelProperty(value = "合作意向", index = 28)
    private String heYiXiang;

    @ExcelProperty(value = "批准机关", index = 29)
    private String piZhunJiGuan;

    @ExcelProperty(value = "批准文号", index = 30)
    private String piZhunWenHao;

    @ExcelProperty(value = "注册日期", index = 31)
    private LocalDateTime zhuCeRiQi;

    @ExcelProperty(value = "备注", index = 32)
    private String beiZhu;

    @ExcelProperty(value = "联系人1", index = 33)
    private String zhuLianXiRen1;

    @ExcelProperty(value = "电话1", index = 34)
    private String dianHua1;
}
