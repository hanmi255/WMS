package com.zeroone.star.stockln.service.impl;

import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.zeroone.star.project.dto.j6.stockln.ImportNoticeDetailDTO;
import com.zeroone.star.project.dto.j6.stockln.ImportNoticeDetailHeadDTO;
import com.zeroone.star.stockln.entity.WmImNoticeH;
import com.zeroone.star.stockln.entity.WmImNoticeI;
import com.zeroone.star.stockln.mapper.WmImNoticeHMapper;
import com.zeroone.star.stockln.mapper.WmImNoticeIMapper;
import com.zeroone.star.stockln.service.IWmImNoticeIService;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import org.mapstruct.Mapper;
import org.springframework.stereotype.Service;

import javax.annotation.Resource;
import java.util.ArrayList;
import java.util.List;

@Mapper(componentModel = "spring")
interface MsWmImNoticeIMapper
{
    ImportNoticeDetailHeadDTO wmImNoticeHToImportNoticeDetailHeadDTO(WmImNoticeH wmImNoticeH);
}



/**
 * <p>
 * 预约进货通知明细 服务实现类
 * </p>
 *
 * @author juhao
 * @since 2025-03-06
 */
@Service
public class WmImNoticeIServiceImpl extends ServiceImpl<WmImNoticeIMapper, WmImNoticeI> implements IWmImNoticeIService {

    @Resource
    WmImNoticeHMapper wmImNoticeHMapper;

    @Resource
    MsWmImNoticeIMapper msWmImNoticeIMapper;

    /**
     * 查询单个预约通知单详细信息
     * @param imNoticeId
     * @return
     */
    public ImportNoticeDetailHeadDTO getDetailsById(String imNoticeId) {
        QueryWrapper<WmImNoticeH> wrapperH = new QueryWrapper<>();
        wrapperH.eq("notice_id", imNoticeId);
        WmImNoticeH wmImNoticeH = wmImNoticeHMapper.selectOne(wrapperH);
        ImportNoticeDetailHeadDTO importNoticeDetailHeadDTO = msWmImNoticeIMapper.wmImNoticeHToImportNoticeDetailHeadDTO(wmImNoticeH);

        QueryWrapper<WmImNoticeI> wrapperI = new QueryWrapper<>();
        wrapperI.eq("im_notice_id",imNoticeId);
        List<WmImNoticeI> wmImNoticeIS = baseMapper.selectList(wrapperI);

        List<ImportNoticeDetailDTO> list = new ArrayList<>();
        if(wmImNoticeIS != null)
            for (WmImNoticeI wmImNoticeI : wmImNoticeIS) {
            ImportNoticeDetailDTO detail = ImportNoticeDetailDTO.builder()
                    .noticeiSta(wmImNoticeI.getNoticeiSta())
                    .binPlan(wmImNoticeI.getBinPlan())
                    .goodsCount(wmImNoticeI.getGoodsCount())
                    .goodsName(wmImNoticeI.getGoodsName())
                    .build();
            list.add(detail);
        }
        importNoticeDetailHeadDTO.setList(list);
        return importNoticeDetailHeadDTO;
    }
}
