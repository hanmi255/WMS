package com.zeroone.star.project.j7.zccheck;

import com.zeroone.star.project.dto.j7.zccheck.OneClickReviewDTO;
import com.zeroone.star.project.vo.JsonVO;

import java.util.List;

/**
 * 描述：装车复核接口
 * @author 做了错饭
 */
public interface LoadingReviewApis {
    /**
     * 一键复核
     */
    JsonVO<String> oneClickReview(OneClickReviewDTO oneClickReviewDTO);
}
