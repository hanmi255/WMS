package com.zeroone.star.project.j8.other;

import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j8.other.port.PortAddDTO;
import com.zeroone.star.project.dto.j8.other.port.PortBaseDTO;
import com.zeroone.star.project.dto.j8.other.port.PortModifyDTO;
import com.zeroone.star.project.query.j8.other.port.PortQuery;
import com.zeroone.star.project.vo.JsonVO;
import javax.servlet.http.HttpServletResponse;
import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.bind.annotation.RequestParam;
import org.springframework.web.multipart.MultipartFile;

/**
 * <p>
 * 描述：港口信息相关接口
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 * @author yjq
 * @version 1.0.0
 */
public interface PortApis {
    JsonVO<PageDTO<PortBaseDTO>> queryAll(@RequestBody PortQuery query);
    JsonVO<String> addPort(@RequestBody PortAddDTO dto);
    JsonVO<String> removePort(@RequestParam String id);
    JsonVO<String> modifyPort(@RequestBody PortModifyDTO dto);
    JsonVO<String> importPort(@RequestParam("file") MultipartFile file);
    void exportPort(HttpServletResponse response);


}
