package com.zeroone.star.stockln.service;

import com.zeroone.star.project.dto.j6.stockln.ToListUpdateDTO;

/**
 * <p>
 * 描述：待上架货物相关服务接口
 * </p>
 *
 * @author [Susu]
 * @version 1.0.0
 */
public interface ToListService {

    /**
     * 修改待上架货物信息
     * @param updateDTO 需要修改的信息
     * @return 是否修改成功
     */
    boolean updateToList(ToListUpdateDTO updateDTO);
}
