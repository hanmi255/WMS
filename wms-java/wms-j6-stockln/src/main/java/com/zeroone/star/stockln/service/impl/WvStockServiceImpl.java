package com.zeroone.star.stockln.service.impl;

import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.zeroone.star.project.dto.PageDTO;

import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.project.dto.j6.stockln.WvStockDTO;
import com.zeroone.star.project.query.j6.stockln.WvStockQuery;
import com.zeroone.star.stockln.entity.WvStock;
import com.zeroone.star.stockln.mapper.WvStockMapper;
import com.zeroone.star.stockln.service.IWvStockService;
import org.mapstruct.Mapper;
import org.springframework.stereotype.Service;

import javax.annotation.Resource;

@Mapper(componentModel = "spring")
interface MsWvStockMapper{
    WvStockDTO MsWvStockToWvStockDTO(WvStock wvStock);
}
/**
 * <p>
 * VIEW 服务实现类
 * </p>
 *
 * @author smt
 * @since 2025-03-07
 */
@Service
public class WvStockServiceImpl extends ServiceImpl<WvStockMapper, WvStock> implements IWvStockService {
    @Resource
    MsWvStockMapper msMapper;
    @Override
    public PageDTO<WvStockDTO> listallStock(WvStockQuery query) {
        //分页对象
        Page<WvStock> page = new Page<>(query.getPageIndex(), query.getPageSize());
        //查询对象
        QueryWrapper<WvStock> wrapper = new QueryWrapper<>();
        wrapper.like("kuWeiBianMa",query.getKuWeiBianMa()).or()
                .like("binId",query.getBinId()).or()
                .like("cusCode",query.getCusCode()).or()
                .like("zhongWenQch",query.getZhongWenQch()).or()
                .like("goodsCode",query.getGoodsCode()).or()
                .like("shpMingCheng",query.getShpMingCheng());
        Page<WvStock> ps = baseMapper.selectPage(page, wrapper);
        return PageDTO.create(ps,msMapper::MsWvStockToWvStockDTO);
    }
}
