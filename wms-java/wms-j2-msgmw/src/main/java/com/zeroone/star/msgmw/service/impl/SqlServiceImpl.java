package com.zeroone.star.msgmw.service.impl;

import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.zeroone.star.msgmw.entity.SqlEntity;
import com.zeroone.star.msgmw.mapper.SqlMapper;
import com.zeroone.star.msgmw.service.SqlService;
import com.zeroone.star.project.components.user.UserDTO;
import com.zeroone.star.project.components.user.UserHolder;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j2.msgmw.SQL.*;
import com.zeroone.star.project.query.j2.msgmw.SQL.SqlQuery;
import lombok.RequiredArgsConstructor;
import lombok.extern.slf4j.Slf4j;
import org.springframework.beans.BeanUtils;
import org.springframework.stereotype.Service;
import java.util.Date;
import java.util.List;

@Service
@RequiredArgsConstructor
@Slf4j
public class SqlServiceImpl implements SqlService {


    private final SqlMapper sqlMapper;

   private final UserHolder userHolder;
    @Override
    public List<SqlNameListDTO> listSqlNameList() {
        return sqlMapper.selectSqlNameList();
    }

    @Override
    public PageDTO<SqlListDTO> listSqlList(SqlQuery sqlQuery) {
        Page<SqlListDTO> page = new Page<>(sqlQuery.getPageIndex(), sqlQuery.getPageSize());
        Page<SqlListDTO> resultPage = sqlMapper.selectSqlList(page, sqlQuery);
        return PageDTO.create(resultPage);
    }

    @Override
    public boolean saveSql(SqlAddDTO sqlAddDTO) {
        SqlEntity sqlEntity = new SqlEntity();
        BeanUtils.copyProperties(sqlAddDTO, sqlEntity);
        // 设置创建时间和更新时间
        Date now = new Date();
        sqlEntity.setCreateDate(now);
        sqlEntity.setUpdateDate(now);

        try {
            // 获取当前登录用户信息
            UserDTO userDTO = userHolder.getCurrentUser();
            if (userDTO != null) {
                sqlEntity.setCreateBy(userDTO.getId());
                sqlEntity.setCreateName(userDTO.getUsername());
                sqlEntity.setUpdateBy(userDTO.getId());
                sqlEntity.setUpdateName(userDTO.getUsername());
            }
        } catch (Exception e) {
            // 处理异常，例如记录日志
            e.printStackTrace();
            return false;
        }

        int result = sqlMapper.insertSql(sqlEntity);
        return result > 0;
    }

    @Override
    public boolean updateSql(SqlModifyDTO sqlModifyDTO) {
        if (sqlModifyDTO.getSqlId() == null) {
            log.error("SqlModifyDTO 的 sqlId 为 null，无法进行更新操作");
            return false;
        }
        SqlEntity existingEntity = sqlMapper.selectById(sqlModifyDTO.getSqlId());
        if (existingEntity == null) {
            log.error("数据库中不存在 sqlId 为 {} 的记录，无法进行更新操作", sqlModifyDTO.getSqlId());
            return false;
        }
        SqlEntity sqlEntity = new SqlEntity();
        BeanUtils.copyProperties(sqlModifyDTO, sqlEntity);
        sqlEntity.setId(sqlModifyDTO.getSqlId());
        Date now = new Date();
        sqlEntity.setUpdateDate(now);
        try {
            UserDTO userDTO = userHolder.getCurrentUser();
            if (userDTO != null) {
                sqlEntity.setUpdateBy(userDTO.getId());
                sqlEntity.setUpdateName(userDTO.getUsername());
            }
        } catch (Exception e) {
            log.error("获取当前用户信息时出现异常", e);
            return false;
        }
        int result = sqlMapper.updateById(sqlEntity);
        log.info("更新 SQL 记录，结果：{}", result > 0 ? "成功" : "失败");
        return result > 0;
    }

    @Override
    public boolean removeSql(SqlDeleteDTO sqlDeleteDTO) {
        if (sqlDeleteDTO.getSqlId() != null) {
            // 单个删除
            int result = sqlMapper.deleteById(sqlDeleteDTO.getSqlId());
            return result > 0;
        } else if (sqlDeleteDTO.getSqlIdList() != null && !sqlDeleteDTO.getSqlIdList().isEmpty()) {
            // 批量删除
            int result = sqlMapper.deleteBatchIds(sqlDeleteDTO.getSqlIdList());
            return result > 0;
        }
        return false;
    }
}
