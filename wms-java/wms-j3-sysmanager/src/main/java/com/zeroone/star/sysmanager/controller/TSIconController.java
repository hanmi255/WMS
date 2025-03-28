package com.zeroone.star.sysmanager.controller;





import com.baomidou.mybatisplus.core.metadata.IPage;
import com.zeroone.star.project.components.fastdfs.FastDfsClientComponent;
import com.zeroone.star.project.components.fastdfs.FastDfsFileInfo;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j3.sysmg.icon.*;
import com.zeroone.star.project.j3.sysmg.iconsApis;
import com.zeroone.star.project.query.j3.sysmg.icon.IconsQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.ResultStatus;
import com.zeroone.star.sysmanager.entity.TSIcon;
import com.zeroone.star.sysmanager.service.ITSIconService;
import com.zeroone.star.sysmanager.service.impl.TSIconServiceImpl;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import lombok.SneakyThrows;
import lombok.extern.slf4j.Slf4j;
import org.springframework.beans.BeanUtils;
import org.springframework.beans.factory.annotation.Value;
import org.springframework.web.bind.annotation.*;
import org.springframework.web.multipart.MultipartFile;

import javax.annotation.Resource;
import java.util.List;

/**
 * <p>
 * 系统图标 前端控制器
 * </p>
 *
 * @author Vast
 * @since 2025-02-21
 */
@Slf4j
@RestController
@RequestMapping("sysmanager/icons")
@Api(tags = "系统图标管理")
public class TSIconController implements iconsApis {

    @Resource
    private ITSIconService tsIconService;

    @Resource
    FastDfsClientComponent dfs;

    @Value("${fastdfs.nginx-servers}")
    private String fileServerUrl;


    @GetMapping("all")
    @ApiOperation(value = "图标列表查询接口")
    @Override
    public JsonVO<IPage<IconsListDTO>> queryAll(IconsQuery query) {
        log.info("查询图标列表,参数为：{}",query);
        IPage<IconsListDTO> page = tsIconService.pageByName(query);
        return JsonVO.success(page);
    }

    @GetMapping("names")
    @ApiOperation(value = "图标名称列表查询接口")
    @Override
    public JsonVO<List<IconsNamesListDTO>> queryNames(int type) {
        log.info("查询图标名称列表,参数为：{}",type);
        List<IconsNamesListDTO> names=tsIconService.queryNames(type);
        return JsonVO.success(names);
    }
    @PostMapping("add")
    @ApiOperation(value = "图标录入接口")
    @Override
    public JsonVO<ResultStatus> addIcons(IconsAddDTO dto) {
        log.info("新增图标，参数为：{}",dto);
        tsIconService.addIcons(dto);
        return JsonVO.success(ResultStatus.SUCCESS);
    }

    @GetMapping("/{id}")
    @ApiOperation("根据id回显图标编辑数据接口")
    @Override
    public JsonVO<IconsModifyDTO> queryById(@PathVariable String id) {
        log.info("根据id回显图标编辑数据,参数为：{}",id);
        IconsModifyDTO iconsModifyDTO = new IconsModifyDTO();
        TSIcon icon = tsIconService.getById(id);
        BeanUtils.copyProperties(icon,iconsModifyDTO);
        String path=icon.getPath();
        String[] split = path.split("/",2);
        String url=dfs.fetchUrl(FastDfsFileInfo.builder().group(split[0]).storageId(split[1]).build(),fileServerUrl,true);
        iconsModifyDTO.setUrl(url);

        return JsonVO.success(iconsModifyDTO);
    }

    @PostMapping("modify")
    @ApiOperation(value = "图标编辑接口")
    @Override
    public JsonVO<ResultStatus> modifyIcons(String id, IconsModifyDTO dto) {
        log.info("根据id编辑图标信息，参数为:{},{}",id,dto);
        tsIconService.modifyIcons(id,dto);
        return JsonVO.success(ResultStatus.SUCCESS);
    }

    @DeleteMapping("delete")
    @ApiOperation(value = "图标删除接口")
    @Override
    public JsonVO<ResultStatus> deleteIcons(String id) {
        log.info("根据id删除图标，参数为:{}",id);
        tsIconService.deleteIcons(id);
        return JsonVO.success(ResultStatus.SUCCESS);
    }
}

