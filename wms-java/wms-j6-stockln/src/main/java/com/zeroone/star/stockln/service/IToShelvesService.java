package com.zeroone.star.stockln.service;

import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j6.stockln.InboundQmIDTO;
import com.zeroone.star.project.dto.j6.stockln.ModifyShelvesDTO;
import com.zeroone.star.project.dto.j6.stockln.ToShelvesDTO;
import com.zeroone.star.project.query.j6.stockln.ToShelvesQuery;
import com.zeroone.star.stockln.entity.ToShelves;

import java.util.List;

/**
 * 待上架服务类
 */
public interface IToShelvesService extends IService<ToShelves> {
    PageDTO<InboundQmIDTO> listall(ToShelvesQuery toShelvesQuery);

    void insertItem(ToShelvesDTO dto);

    boolean deleteById(String id);

    /**
     * 修改待上架货物信息
     *
     * @param dto 包含待上架货物修改信息的 DTO
     * @return 修改是否成功
     */
    boolean modifyShelvesInfo(ModifyShelvesDTO dto);

    boolean batchModifyBin(List<String> ids, String binId);

    InboundQmIDTO myGetById(String id);
}
