package com.zeroone.star.project.j6.stockln;

import com.zeroone.star.project.dto.j6.stockln.ToListUpdateDTO;
import com.zeroone.star.project.vo.JsonVO;
import org.springframework.web.bind.annotation.RequestBody;

/**
 * <p>
 * 描述：修改待上架货物相关接口
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 *
 * @version 1.0.0
 */
public interface ToListApis {

    /**
     * 修改待上架货物
     *
     * @param ToListUpdateDTO 包含待验收货物的详细信息及用户填写的字段
     * @return 验收操作是否成功的状态信息
     */
    JsonVO<String> updateToList(@RequestBody ToListUpdateDTO updateDTO);

}
