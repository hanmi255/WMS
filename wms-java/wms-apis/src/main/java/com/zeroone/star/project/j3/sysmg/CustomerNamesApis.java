package com.zeroone.star.project.j3.sysmg;
import com.zeroone.star.project.vo.JsonVO;

import java.util.List;

/**
 * 查询客户名称列表数据接口
 */
public interface CustomerNamesApis {

    /**
     * 查询客户名称列表
     * @param
     * @return
     */
    JsonVO<List<String>> queryCustomerNames();
}
