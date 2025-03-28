package com.zeroone.star.stockln.service.impl;

import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.project.dto.j6.stockln.ToAcceptDTO;
import com.zeroone.star.project.query.j6.stockln.ToAcceptQuery;
import com.zeroone.star.project.vo.j6.stockln.ToAcceptDetailVO;
import com.zeroone.star.project.vo.j6.stockln.ToAcceptPageVO;
import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.zeroone.star.project.vo.j6.stockln.ToAcceptVO;
import com.zeroone.star.stockln.mapper.ToAcceptMapper;
import com.zeroone.star.stockln.service.ToAcceptService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import java.util.List;
import java.util.stream.Collectors;

@Service
public class ToAcceptServiceImpl extends ServiceImpl<ToAcceptMapper, ToAcceptDTO> implements ToAcceptService {

    @Autowired
    private ToAcceptMapper toAcceptMapper;

    /**
     * 获取待验收货物列表，支持条件查询和分页查询
     * @param query 查询条件
     * @param page 页码
     * @param size 每页数量
     * @return 返回分页的待验收货物列表
     */
    @Override
    public ToAcceptPageVO getAcceptanceItems(ToAcceptQuery query, int page, int size) {
        // 创建分页查询对象
        Page<ToAcceptDTO> pageObj = new Page<>(page, size);

        // 构建动态查询条件
        QueryWrapper<ToAcceptDTO> queryWrapper = new QueryWrapper<>();

        // 设置查询条件 - 这里只对3-4个常用字段设置条件查询
        if (query.getImNoticeId() != null) {
            queryWrapper.like("im_notice_id", query.getImNoticeId());
        }
        if (query.getGoodsCode() != null) {
            queryWrapper.like("goods_id", query.getGoodsCode());
        }
        if (query.getImCusCode() != null) {
            queryWrapper.like("im_cus_code", query.getImCusCode());
        }
        if (query.getGoodsName() != null) {
            queryWrapper.like("goods_name", query.getGoodsName());
        }

        // 使用MyBatis-Plus进行分页查询
        Page<ToAcceptDTO> resultPage = toAcceptMapper.selectPage(pageObj, queryWrapper);

        // 转换 ToAcceptDTO 列表为 ToAcceptVO 列表
        List<ToAcceptVO> toAcceptVOList = resultPage.getRecords().stream()
                .map(dto -> {
                    // 通过 ToAcceptDTO 来构造 ToAcceptVO
                    ToAcceptVO toAcceptVO = new ToAcceptVO();
                    toAcceptVO.setCreateName(dto.getCreateName());
                    toAcceptVO.setCreateDate(dto.getCreateDate());
                    toAcceptVO.setImNoticeId(dto.getImNoticeId());
                    toAcceptVO.setImCusCode(dto.getImCusCode());
                    toAcceptVO.setImBeizhu(dto.getImBeizhu());
                    toAcceptVO.setGoodsCode(dto.getGoodsCode());
                    toAcceptVO.setGoodsName(dto.getGoodsName());
                    toAcceptVO.setGoodsCount(dto.getGoodsCount());
                    toAcceptVO.setGoodsWqmCount(dto.getGoodsWqmCount());
                    toAcceptVO.setGoodsQmCount(dto.getGoodsQmCount());
                    toAcceptVO.setGoodsPrdData(dto.getGoodsPrdData());
                    toAcceptVO.setGoodsBatch(dto.getGoodsBatch());
                    toAcceptVO.setBinPlan(dto.getBinPlan());
                    toAcceptVO.setTinId(dto.getTinId());
                    toAcceptVO.setGoodsUnit(dto.getGoodsUnit());

                    return toAcceptVO;
                })
                .collect(Collectors.toList());

        // 创建并返回 ToAcceptPageVO
        return new ToAcceptPageVO(toAcceptVOList, resultPage.getCurrent(), resultPage.getSize(), resultPage.getTotal());
    }



    @Override
    public ToAcceptDetailVO getAcceptanceItemById(String id) {
        // 使用 MyBatis-Plus 的 selectById 方法查询单个待验收货物
        ToAcceptDTO toAcceptDTO = toAcceptMapper.selectById(id);

        // 如果查询结果为空，返回 null
        if (toAcceptDTO == null) {
            return null;
        }

        // 创建 ToAcceptDetailVO 对象
        ToAcceptDetailVO toAcceptDetailVO = new ToAcceptDetailVO();

        // 映射字段
        toAcceptDetailVO.setImNoticeId(toAcceptDTO.getImNoticeId());  // 到货通知单编号
        toAcceptDetailVO.setGoodsCode(toAcceptDTO.getGoodsCode());      // 商品编码
        toAcceptDetailVO.setBinPlan(toAcceptDTO.getBinPlan());          // 储位

        // 你可以继续添加其他需要的字段映射

        // 如果你有更多的字段可以映射，可以继续在这里进行
        // 例如：
        // toAcceptDetailVO.setGoodsName(toAcceptDTO.getGoodsName());
        // toAcceptDetailVO.setGoodsUnit(toAcceptDTO.getGoodsUnit());
        // toAcceptDetailVO.setItemText(toAcceptDTO.getItemText());

        // 返回详细展示对象
        return toAcceptDetailVO;
    }

}
