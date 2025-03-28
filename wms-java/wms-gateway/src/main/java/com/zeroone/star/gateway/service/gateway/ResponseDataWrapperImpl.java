package com.zeroone.star.gateway.service.gateway;

import com.zeroone.cloud.starter.gateway.service.ResponseDataWrapper;
import com.zeroone.star.project.vo.JsonVO;
import org.springframework.stereotype.Service;

/**
 * <p>
 * 描述：使用JsonVO对下发数据进行包装
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 * @author 阿伟学长
 * @version 1.0.0
 */
@Service
public class ResponseDataWrapperImpl implements ResponseDataWrapper {
    @Override
    public Object executeWrap(String code, String message, Object data) {
        return JsonVO.create(data, Integer.parseInt(code), message);
    }
}
