package com.zeroone.star.project.j2.msgmw.SQL;

import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j2.msgmw.SQL.*;
import com.zeroone.star.project.query.j2.msgmw.SQL.SqlQuery;
import com.zeroone.star.project.vo.JsonVO;

import java.util.List;

public interface SqlApis {

    /**
     * 获取SQL列表(条件+分页)
     * @param sqlQuery 查询条件
     * @return 分页后的SQL列表数据
     */
    JsonVO<PageDTO<SqlListDTO>> queryAll(SqlQuery sqlQuery);

    /*
     * 获取SQL名称列表
     */
    JsonVO<List<SqlNameListDTO>> querySqlNameList();

    /**
     * 录入SQL
     * @param sqlAddDTO SQL信息
     * @return 操作结果
     */
    JsonVO<String> addSql(SqlAddDTO sqlAddDTO);

    /**
     * 修改SQL
     * @param sqlModifyDTO SQL修改信息
     * @return 操作结果
     */
    JsonVO<String> modifySql(SqlModifyDTO sqlModifyDTO);

    /**
     * 删除SQL（支持单个或批量）
     * @param sqlDeleteDTO SQL删除信息（包含单个ID或ID列表）
     * @return 操作结果
     */
    JsonVO<String> removeSql(SqlDeleteDTO sqlDeleteDTO);

}