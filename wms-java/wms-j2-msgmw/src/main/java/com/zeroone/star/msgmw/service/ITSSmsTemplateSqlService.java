package com.zeroone.star.msgmw.service;

import com.zeroone.star.msgmw.entity.TSSmsTemplateSql;
import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j2.msgmw.TSSmsTemplateSqlAddDTO;
import com.zeroone.star.project.dto.j2.msgmw.TSSmsTemplateSqlDTO;
import com.zeroone.star.project.query.j2.msgmw.TSSmsTemplateSqlQuery;
import com.zeroone.star.project.vo.j2.msgmw.TSSmsTemplateSqlVO;


import java.util.List;

/**
 * <p>
 * 消息模板配置 服务类
 * </p>
 *
 * @author qunzhong
 * @since 2025-02-21
 */
public interface ITSSmsTemplateSqlService extends IService<TSSmsTemplateSql> {
    void add(TSSmsTemplateSqlAddDTO templateSqlAddDTO) throws Exception;

    void update(TSSmsTemplateSqlDTO templateSqlDTO) throws Exception;

    void delete(List<Long> idList);

    PageDTO<TSSmsTemplateSqlVO> query(TSSmsTemplateSqlQuery templateQuery, int page, int size);
}
