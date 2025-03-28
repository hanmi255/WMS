package com.zeroone.star.project.j3.sysmg;


import com.baomidou.mybatisplus.core.metadata.IPage;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j3.sysmg.icon.*;
import com.zeroone.star.project.query.j3.sysmg.icon.IconsQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.ResultStatus;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.bind.annotation.RequestParam;
import org.springframework.web.multipart.MultipartFile;
import springfox.documentation.spring.web.json.Json;

import java.util.List;

/**
 * @author Vast
 * @version 1.0
 * @function:系统图标管理接口
 */
@SuppressWarnings({"all"})
public interface iconsApis {
    /**
     * 分页查询图标列表
     * @param query
     * @return 响应数据结果
     */
    JsonVO<IPage<IconsListDTO>> queryAll(IconsQuery query);

    /**
     * 查询图标名称列表
     * @param query
     * @return 响应数据结果
     */
    JsonVO<List<IconsNamesListDTO>> queryNames(int type);

    /**
     * 图标录入
     * @param dto
     * @return 响应数据结果
     */
    JsonVO<ResultStatus> addIcons(IconsAddDTO  dto);

    /**
     * 根据id回显修改信息
     * @param id
     * @return 响应数据结果
     */
    JsonVO<IconsModifyDTO> queryById(String id);
    /**
     * 图标编辑
     * @param id
     * @param dto
     * @return 响应数据结果
     */
    JsonVO<ResultStatus> modifyIcons(String id, IconsModifyDTO dto);

    /**
     * 根据id图标删除
     * @param dto
     * @return 响应数据结果
     */
    JsonVO<ResultStatus> deleteIcons(String id);
}
