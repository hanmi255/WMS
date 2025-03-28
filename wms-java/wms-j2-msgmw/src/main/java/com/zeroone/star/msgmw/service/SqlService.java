package com.zeroone.star.msgmw.service;

import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j2.msgmw.SQL.*;
import com.zeroone.star.project.query.j2.msgmw.SQL.SqlQuery;

import java.util.List;

public interface SqlService {
    List<SqlNameListDTO> listSqlNameList();

    PageDTO<SqlListDTO> listSqlList(SqlQuery sqlQuery);

    boolean saveSql(SqlAddDTO sqlAddDTO);

    boolean updateSql(SqlModifyDTO sqlModifyDTO);

    boolean removeSql(SqlDeleteDTO sqlDeleteDTO);
}
