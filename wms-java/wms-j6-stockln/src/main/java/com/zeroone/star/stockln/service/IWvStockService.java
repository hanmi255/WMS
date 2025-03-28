package com.zeroone.star.stockln.service;

import com.zeroone.star.project.dto.PageDTO;

import com.zeroone.star.project.dto.j6.stockln.WvStockDTO;
import com.zeroone.star.project.query.j6.stockln.WvStockQuery;

import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.stockln.entity.WvStock;

/**
 * <p>
 * VIEW 服务类
 * </p>
 *
 * @author smt
 * @since 2025-03-07
 */
public interface IWvStockService extends IService<WvStock> {
    PageDTO<WvStockDTO> listallStock(WvStockQuery query);
}
