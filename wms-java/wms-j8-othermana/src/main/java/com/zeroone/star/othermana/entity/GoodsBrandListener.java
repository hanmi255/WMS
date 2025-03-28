package com.zeroone.star.othermana.entity;

import com.alibaba.excel.context.AnalysisContext;
import com.alibaba.excel.event.AnalysisEventListener;
import com.zeroone.star.project.vo.j8.other.goodsbrand.GoodsBrandVO;
import lombok.Data;

import java.util.ArrayList;
import java.util.List;

@Data
public class GoodsBrandListener extends AnalysisEventListener<GoodsBrandVO> {
    private List<GoodsBrandVO> list = new ArrayList<>();

    @Override
    public void invoke(GoodsBrandVO goodsBrandVO, AnalysisContext analysisContext) {
        list.add(goodsBrandVO);
    }

    @Override
    public void doAfterAllAnalysed(AnalysisContext analysisContext) {
        System.out.println("解析结束");
    }


}
