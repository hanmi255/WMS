package com.zeroone.star.stockln.service.impl;

import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.project.dto.j6.stockln.InNoticeVO;
import com.zeroone.star.project.dto.j6.stockln.ToAcceptDTO;
import com.zeroone.star.project.query.j6.stockln.InNoticeQuery;
import com.zeroone.star.project.vo.j6.stockln.InNoticePageVO;
import com.zeroone.star.stockln.mapper.InNoticeMapper;
import com.zeroone.star.stockln.service.InNoticeService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import java.util.List;
import java.util.stream.Collectors;

/**
 * <p>
 * 描述：入库通知明细服务实现类
 * </p>
 *
 * @author []
 * @version 1.0.0
 */
@Service
public class InNoticeServiceImpl extends ServiceImpl<InNoticeMapper, ToAcceptDTO> implements InNoticeService {

    @Autowired
    private InNoticeMapper inNoticeMapper;

    /**
     * 获取入库通知明细列表，支持条件查询和分页查询
     * @param query 查询条件
     * @param page 页码
     * @param size 每页数量
     * @return 返回分页的入库通知明细列表
     */
    @Override
    public InNoticePageVO getInNoticeItems(InNoticeQuery query, int page, int size) {
        // 创建分页查询对象
        Page<ToAcceptDTO> pageObj = new Page<>(page, size);

        // 构建动态查询条件
        QueryWrapper<ToAcceptDTO> queryWrapper = new QueryWrapper<>();

        // 设置查询条件 - 这里只对 6-7 个常用字段设置条件查询
        if (query.getImNoticeId() != null) {
            queryWrapper.like("im_notice_id", query.getImNoticeId());
        }
        if (query.getCusCode() != null) {
            queryWrapper.like("cus_code", query.getCusCode());
        }
        if (query.getCreateName() != null) {
            queryWrapper.like("create_name", query.getCreateName());
        }
        if (query.getNoticeiSta() != null) {
            queryWrapper.eq("noticei_sta", query.getNoticeiSta());
        }
        if (query.getGoodsCode() != null) {
            queryWrapper.like("goods_code", query.getGoodsCode());
        }
        if (query.getGoodsName() != null) {
            queryWrapper.like("goods_name", query.getGoodsName());
        }
        if (query.getImCusCode() != null) {
            queryWrapper.like("im_cus_code", query.getImCusCode());
        }
        if (query.getGoodsPrdData() != null) {
            queryWrapper.eq("goods_prd_data", query.getGoodsPrdData());
        }

        // 使用 MyBatis-Plus 进行分页查询
        Page<ToAcceptDTO> resultPage = inNoticeMapper.selectPage(pageObj, queryWrapper);

        // 转换 ToAcceptDTO 列表为 InNoticeVO 列表
        List<InNoticeVO> inNoticeVOList = resultPage.getRecords().stream()
                .map(dto -> {
                    // 通过 ToAcceptDTO 构造 InNoticeVO
                    InNoticeVO inNoticeVO = new InNoticeVO();
                    inNoticeVO.setImNoticeId(dto.getImNoticeId());
                    inNoticeVO.setCusCode(dto.getImCusCode()); // 客户编码
                    inNoticeVO.setCusName(dto.getCreateName()); // 客户名称 (这里假设创建人名称即为客户名称)
                    inNoticeVO.setNoticeiSta(dto.getNoticeiSta()); // 通知单状态
                    inNoticeVO.setGoodsCode(dto.getGoodsCode()); // 商品编码
                    inNoticeVO.setGoodsName(dto.getGoodsName()); // 商品名称
                    inNoticeVO.setGoodsCount(dto.getGoodsCount()); // 通知单数量
                    inNoticeVO.setGoodsQmCount(dto.getGoodsQmCount()); // 验收数量
                    inNoticeVO.setGoodsUnit(dto.getGoodsUnit()); // 单位
                    inNoticeVO.setGoodsFvol(dto.getGoodsFvol()); // 体积
                    inNoticeVO.setGoodsWeight(dto.getGoodsWeight()); // 重量
                    inNoticeVO.setImCusCode(dto.getImCusCode()); // 客户订单号
                    inNoticeVO.setBaseGoodscount(dto.getBaseGoodscount()); // 基本单位数量
                    inNoticeVO.setBaseUnit(dto.getBaseUnit()); // 基本单位
                    inNoticeVO.setGoodsPrdData(dto.getGoodsPrdData()); // 生产日期

                    return inNoticeVO;
                })
                .collect(Collectors.toList());

        // 创建并返回 InNoticePageVO
        return new InNoticePageVO(inNoticeVOList, resultPage.getCurrent(), resultPage.getSize(), resultPage.getTotal());
    }
}
