package com.zeroone.star.project.j7.zccheck;

import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.query.j7.zccheck.ZcCheckQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.dto.j7.zccheck.CheckListDTO;

/**
 * @Author: keyuan
 * @Description: 1.获取装车复核列表
 *               2. 应该需要结合 zccherk包内的主接口
 * @Version: v1.0.0
 * @Date: 2025/2/25 下午 9:37
 **/
public interface CheckApis {
    /**
     * 分页获取装车复核列表
     * @param  zcCheckQuery 查询条件
     * @return 响应数据结果
     */
    JsonVO<PageDTO<CheckListDTO>> queryAll(ZcCheckQuery zcCheckQuery);
}
