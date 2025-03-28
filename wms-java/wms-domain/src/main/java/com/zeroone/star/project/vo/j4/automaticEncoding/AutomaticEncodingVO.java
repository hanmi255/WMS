package com.zeroone.star.project.vo.j4.automaticEncoding;

import com.zeroone.star.project.query.PageQuery;
import lombok.Data;
import lombok.ToString;

/**
 * @ClassName: AutomaticEncodingVO
 * @Description:
 * @Author: lzm
 * @Date: 2025-02-23 00:37
 */
@Data
@ToString
public class AutomaticEncodingVO extends PageQuery {
    /**
     * 编号类型
     */
    private String snroTypeCode;

    /**
     * 组织机构
     */
    private String snroOrg;

    /**
     * 前缀
     */
    private String snroFindex;

    /**
     * 分隔符
     */
    private String snroSplit;

    /**
     * 年位数
     */
    private String snroYear;

    /**
     * 月位数
     */
    private String snroMonth;

    /**
     * 日位数
     */
    private String snroDay;

    /**
     * 序号位数
     */
    private String snroSeri;

    /**
     * 示例号码
     */
    private String snroExp;
}
