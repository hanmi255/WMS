package com.zeroone.star.sysmanager.service.impl;


import cn.hutool.core.date.DateTime;
import com.baomidou.mybatisplus.core.conditions.query.LambdaQueryWrapper;
import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.baomidou.mybatisplus.core.metadata.IPage;
import com.baomidou.mybatisplus.core.toolkit.StringUtils;
//import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.zeroone.star.project.components.fastdfs.FastDfsClientComponent;
import com.zeroone.star.project.components.fastdfs.FastDfsFileInfo;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j3.sysmg.icon.*;
import com.zeroone.star.project.query.j3.sysmg.icon.IconsQuery;
import com.zeroone.star.sysmanager.entity.TSIcon;
import com.zeroone.star.sysmanager.mapper.TSIconMapper;
import com.zeroone.star.sysmanager.service.ITSIconService;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import lombok.SneakyThrows;
import org.springframework.beans.BeanUtils;
import org.springframework.beans.factory.annotation.Value;
import org.springframework.http.HttpHeaders;
import org.springframework.http.HttpStatus;
import org.springframework.http.MediaType;
import org.springframework.http.ResponseEntity;
import org.springframework.stereotype.Service;
import org.springframework.transaction.annotation.Transactional;

import org.springframework.web.multipart.MultipartFile;

import javax.annotation.Resource;
import java.sql.Blob;
import java.util.List;
import java.util.UUID;
import java.util.stream.Collectors;

/**
 * <p>
 * 系统图标 服务实现类
 * </p>
 *
 * @author Vast
 * @since 2025-02-21
 */
@Service
public class TSIconServiceImpl extends ServiceImpl<TSIconMapper, TSIcon> implements ITSIconService {
    @Resource
    TSIconMapper tSIconMapper;

    @Resource
    FastDfsClientComponent dfs;

    @Value("${fastdfs.nginx-servers}")
    private String fileServerUrl;

    /**
     * 查询图标名称列表实现方法
     * @param type
     * @return
     */
    @Override
    public List<IconsNamesListDTO> queryNames(int type) {
        QueryWrapper<TSIcon> queryWrapper = new QueryWrapper<>();
        queryWrapper.select("id", "name", "iconclas").eq("type", type);
        List<TSIcon> tsIcons = tSIconMapper.selectList(queryWrapper);
        return tsIcons.stream().map(tsIcon -> {
            IconsNamesListDTO dto = new IconsNamesListDTO();
            dto.setId(tsIcon.getId());
            dto.setName(tsIcon.getName());
            dto.setIconclas(tsIcon.getIconclas());
            return dto;
        }).collect(Collectors.toList());
    }

    /**
     * 增加图标
     * @param dto
     */
    @SneakyThrows
    @Override
    public void addIcons(IconsAddDTO dto) {
        TSIcon tsIcon = new TSIcon();
        BeanUtils.copyProperties(dto,tsIcon);
        MultipartFile file = dto.getFile();//拿到图标文件
        String filename = file.getOriginalFilename();//拿到图标文件名
        assert filename!=null;
        String extend=filename.substring(filename.lastIndexOf(".")+1);//图标后缀
        FastDfsFileInfo fastDfsFileInfo = dfs.uploadFile(file.getBytes(), extend);//上传文件
//        dfs.fetchUrl(fastDfsFileInfo,fileServerUrl,true);
        if (fastDfsFileInfo == null) {//上传失败
            throw new RuntimeException("上传失败");
        }
        String path=fastDfsFileInfo.getGroup()+"-"+fastDfsFileInfo.getStorageId();
        tsIcon.setPath(path);
        tsIcon.setExtend(extend);
        String id=UUID.randomUUID().toString().replace("-","");
        tsIcon.setId(id);

        tSIconMapper.insert(tsIcon);
    }

    /**
     * 分页查询图标列表
     * @param query
     * @return
     */
    @Override

    public IPage<IconsListDTO> pageByName(IconsQuery query) {
        Page<TSIcon> page = new Page<>(query.getPageIndex(), query.getPageSize());

        LambdaQueryWrapper<TSIcon> queryWrapper = new LambdaQueryWrapper<>();
        queryWrapper.like(StringUtils.isNotBlank(query.getName()), TSIcon::getName, query.getName());

        // 执行分页查询
        Page<TSIcon> resultPage = tSIconMapper.selectPage(page, queryWrapper);

        //手动转换实体分页到DTO分页
        return resultPage.convert(tsIcon -> {
            IconsListDTO dto = new IconsListDTO();
            BeanUtils.copyProperties(tsIcon, dto);
            String path = tsIcon.getPath();
            String[] split = path.split("-",2);
            String url=dfs.fetchUrl(FastDfsFileInfo.builder().group(split[0]).storageId(split[1]).build(),fileServerUrl,true);
            dto.setUrl(url);
            return dto;
        });
    }

    /**
     * 根据id编辑图标信息
     * @param id
     * @param dto
     */
    @SneakyThrows
    @Override
    public void modifyIcons(String id, IconsModifyDTO dto) {
        TSIcon tsIcon = new TSIcon();
        BeanUtils.copyProperties(dto,tsIcon);
        MultipartFile file = dto.getFile();//拿到图标文件
        String filename = file.getOriginalFilename();//拿到图标文件名
        assert filename!=null;
        String extend=filename.substring(filename.lastIndexOf(".")+1);//图标后缀
        FastDfsFileInfo fastDfsFileInfo = dfs.uploadFile(file.getBytes(), extend);//上传文件
        if (fastDfsFileInfo == null) {//上传失败
            throw new RuntimeException("上传失败");
        }
        String path = fastDfsFileInfo.getGroup() + "-" + fastDfsFileInfo.getStorageId();
        tsIcon.setPath(path);
        tsIcon.setExtend(extend);
        tsIcon.setId(id);

        tSIconMapper.updateById(tsIcon);
    }

    /**
     * 根据id删除图标
     * @param id
     */
    @SneakyThrows
    @Override
    public void deleteIcons(String id) {

        TSIcon icon = tSIconMapper.selectById(id);
        String path = icon.getPath();
        String[] split = path.split("-");
        int i = dfs.deleteFile(FastDfsFileInfo.builder().group(split[0]).storageId(split[1]).build());
        if (i == 0) {//删除成功
            tSIconMapper.deleteById(id);
            return;
        }
        throw new RuntimeException("删除失败");

    }
}
