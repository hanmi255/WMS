package com.zeroone.star.project.vo.j6.stockln;

import com.zeroone.star.project.dto.ExtendPageDTO;
import io.swagger.annotations.ApiModel;
import lombok.Data;

import java.util.List;

/**
 * <p>
 * 描述：待验收货物分页查询结果对象
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 * @author Susu
 * @version 1.0.0
 */
@Data
@ApiModel("待验收货物分页查询结果对象")
public class ToAcceptPageVO extends ExtendPageDTO<ToAcceptVO> {

    /**
     * 默认构造函数
     */
    public ToAcceptPageVO() {
        super();
    }

    /**
     * 根据指定的参数创建分页显示的对象
     * @param rows      记录数据
     * @param pageIndex 当前显示码
     * @param pageSize  当前页最大显示条数
     * @param total     数据总数
     */
    public ToAcceptPageVO(List<ToAcceptVO> rows, long pageIndex, long pageSize, long total) {
        super(rows, pageIndex, pageSize, total);
    }
}