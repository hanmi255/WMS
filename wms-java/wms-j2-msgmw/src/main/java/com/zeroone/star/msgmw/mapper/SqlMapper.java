package com.zeroone.star.msgmw.mapper;

import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.zeroone.star.msgmw.entity.SqlEntity;
import com.zeroone.star.project.dto.j2.msgmw.SQL.SqlListDTO;
import com.zeroone.star.project.dto.j2.msgmw.SQL.SqlNameListDTO;
import com.zeroone.star.project.query.j2.msgmw.SQL.SqlQuery;
import org.apache.ibatis.annotations.*;

import java.util.List;

@Mapper
public interface SqlMapper extends BaseMapper<SqlEntity> {

    @Select("SELECT sql_name as sqlName FROM t_s_sms_sql")
    List<SqlNameListDTO> selectSqlNameList();

    Page<SqlListDTO> selectSqlList(Page<SqlListDTO> page, @Param("query") SqlQuery sqlQuery);

    @Insert("INSERT INTO t_s_sms_sql (id, sql_name, sql_content, create_date, create_by, create_name, update_date, update_by, update_name) " +
            "VALUES (#{id}, #{sqlName}, #{sqlContent}, #{createDate}, #{createBy}, #{createName}, #{updateDate}, #{updateBy}, #{updateName})")
    @Options(useGeneratedKeys = false)
    int insertSql(SqlEntity sqlEntity);

}
