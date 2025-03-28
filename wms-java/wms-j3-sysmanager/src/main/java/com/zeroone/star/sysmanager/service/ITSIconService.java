package com.zeroone.star.sysmanager.service;

import com.baomidou.mybatisplus.core.metadata.IPage;
import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j3.sysmg.icon.*;
import com.zeroone.star.project.query.j3.sysmg.icon.IconsQuery;
import com.zeroone.star.sysmanager.entity.TSIcon;
import com.baomidou.mybatisplus.extension.service.IService;
import org.springframework.web.multipart.MultipartFile;

import java.util.List;

/**
 * <p>
 * 系统图标 服务类
 * </p>
 *
 * @author Vast
 * @since 2025-02-21
 */
public interface ITSIconService extends IService<TSIcon> {
    /**
     * 查询图标名称列表
     * @param type
     * @return
     */
    List<IconsNamesListDTO> queryNames(int type);

    /**
     * 增加图标
     * @param dto
     */
    void addIcons(IconsAddDTO dto);

    /**
     * 分页查询图标列表
     * @param query
     * @return
     */
    IPage<IconsListDTO> pageByName(IconsQuery query);

    /**
     * 根据id编辑图标信息
     * @param id
     * @param dto
     */
    void modifyIcons(String id, IconsModifyDTO dto);

    /**
     * 根据id删除图标信息
     * @param id
     */
    void deleteIcons(String  id);
}
