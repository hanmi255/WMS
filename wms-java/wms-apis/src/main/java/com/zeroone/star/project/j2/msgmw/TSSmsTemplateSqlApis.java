package com.zeroone.star.project.j2.msgmw;

import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j2.msgmw.TSSmsTemplateSqlAddDTO;
import com.zeroone.star.project.dto.j2.msgmw.TSSmsTemplateSqlDTO;
import com.zeroone.star.project.query.j2.msgmw.TSSmsTemplateSqlQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.j2.msgmw.TSSmsTemplateSqlVO;

public interface TSSmsTemplateSqlApis {
    /**
     * 添加业务配置数据
     * @param templateSqlAddDTO 业务配置数据传输对象
     * @return 添加结果
     * @author qunzhong
     * @date 2025/2/22
     */
    JsonVO<String> add(TSSmsTemplateSqlAddDTO templateSqlAddDTO);

    /**
     * 修改业务配置数据
     * @param templateSqlDTO 业务配置数据传输对象
     * @return 修改结果
     * @author qunzhong
     * @date 2025/2/22
     */

    JsonVO<String> update(TSSmsTemplateSqlDTO templateSqlDTO);
    /**
     * 删除业务配置数据
     * @param  ids 所有要删除的id,用逗号分隔
     * @return 删除结果
     * @author qunzhong
     * @date 2025/2/22
     */

    JsonVO<String> delete(String ids);
    /**
     * 查询业务配置数据
     * @param templateQuery 业务配置数据查询对象
     * @return 业务配置数据列表
     * @author qunzhong
     * @date 2025/2/22
     */
    JsonVO<PageDTO<TSSmsTemplateSqlVO>> query(TSSmsTemplateSqlQuery templateQuery, int page , int size);
}
