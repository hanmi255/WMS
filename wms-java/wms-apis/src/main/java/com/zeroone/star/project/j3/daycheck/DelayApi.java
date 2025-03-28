package com.zeroone.star.project.j3.daycheck;



import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j3.daycheck.delay.WaringAllDTO;
import com.zeroone.star.project.vo.JsonVO;

/**
 * <p>
 * 描述：进货延时接口
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 * @author 阿伟学长
 * @version 1.0.0
 */

public interface DelayApi {
    /**
     * 展示进货延时列表
     * 没有查询条件只有展示功能
     * @return 响应数据结果
     */
    JsonVO<PageDTO<WaringAllDTO>> queryAll(Integer pageIndex, Integer pageSize);

}
