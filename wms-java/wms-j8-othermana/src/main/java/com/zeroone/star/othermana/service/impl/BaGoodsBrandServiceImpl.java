package com.zeroone.star.othermana.service.impl;

import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.othermana.mapper.BaGoodsBrandMapper;
import com.zeroone.star.othermana.service.BaGoodsBrandService;
import com.zeroone.star.project.components.fastdfs.FastDfsClientComponent;
import com.zeroone.star.project.components.fastdfs.FastDfsFileInfo;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j8.other.goodsbrand.GoodsBrandDTO;
import com.zeroone.star.project.query.j8.other.goodsbrand.GoodsBrandQuery;
import com.zeroone.star.project.vo.j8.other.goodsbrand.GoodsBrandAddReqVO;
import com.zeroone.star.project.vo.j8.other.goodsbrand.GoodsBrandUpdateOprationRespVO;
import com.zeroone.star.project.vo.j8.other.goodsbrand.GoodsBrandVO;
import lombok.SneakyThrows;
import org.springframework.beans.factory.annotation.Value;
import org.springframework.stereotype.Service;
import org.springframework.web.multipart.MultipartFile;

import javax.annotation.Resource;
import java.util.List;
import java.util.UUID;

/**
 * @author 陈尚益
 * @description 针对表【ba_goods_brand(品牌信息)】的数据库操作Service实现
 * @createDate 2025-03-08 11:38:45
 */
@Service
public class BaGoodsBrandServiceImpl extends ServiceImpl<BaGoodsBrandMapper, GoodsBrandVO>
        implements BaGoodsBrandService {

    @Resource
    private BaGoodsBrandMapper baGoodsBrandMapper;

    @Resource
    private FastDfsClientComponent dfs;

    @Value("${fastdfs.nginx-servers}")
    private String urlPrefix;

    @Override
    public PageDTO<GoodsBrandVO> queryGoodsBrandPage(GoodsBrandQuery query) {
        Page<GoodsBrandVO> page = new Page<>(query.getPageIndex(), query.getPageSize());
        QueryWrapper<GoodsBrandVO> wrapper = new QueryWrapper<>();
        if (query.getGoodsBrandName() != null && !query.getGoodsBrandName().equals("")) {
            wrapper.like("goods_brand_name", query.getGoodsBrandName());
        }
        if (query.getGoodsBrandCode() != null && !query.getGoodsBrandCode().equals("")) {
            wrapper.like("goods_brand_code", query.getGoodsBrandCode());
        }
        if (query.getOrder() != null && !query.getOrder().equals("")&& query.getSort() != null && !query.getSort().equals("")) {
            wrapper.orderBy(true, query.getOrder().equals("asc"), query.getSort());
        }
        Page<GoodsBrandVO> result = baseMapper.selectPage(page, wrapper);
        return PageDTO.create(result, GoodsBrandVO.class);
    }

    @SneakyThrows
    @Override
    public boolean addGoodsBrand(GoodsBrandAddReqVO goodsBrandAddReqVO) {
        GoodsBrandDTO goodsBrandDTO = new GoodsBrandDTO();
        // 处理图片上传
        MultipartFile goodsBrandPic = goodsBrandAddReqVO.getGoodsBrandPic();
        String originalFilename = goodsBrandPic.getOriginalFilename();
        String suffix = originalFilename.substring(originalFilename.lastIndexOf(".")+1);
        FastDfsFileInfo info = dfs.uploadFile(goodsBrandPic.getBytes(), suffix);
        if (info != null) {
            String s = dfs.fetchUrl(info, urlPrefix, true);
            goodsBrandDTO.setGoodsBrandPic(s);
        }
        goodsBrandDTO.setGoodsBrandCode(goodsBrandAddReqVO.getGoodsBrandCode());
        goodsBrandDTO.setGoodsBrandName(goodsBrandAddReqVO.getGoodsBrandName());
        goodsBrandDTO.setGoodsBrandWww(goodsBrandAddReqVO.getGoodsBrandWww());
        goodsBrandDTO.setGoodsBrandText(goodsBrandAddReqVO.getGoodsBrandText());
        goodsBrandDTO.setGoodsBrandDel(goodsBrandAddReqVO.getGoodsBrandDel());
        goodsBrandDTO.setId(UUID.randomUUID().toString());
        return baGoodsBrandMapper.addGoodsBrand(goodsBrandDTO);
    }

    @Override
    public GoodsBrandUpdateOprationRespVO oprationGetById(String id) {
        GoodsBrandVO goodsBrandVO = baseMapper.selectById(id);
        GoodsBrandUpdateOprationRespVO goodsBrandUpdateOprationRespVO = new GoodsBrandUpdateOprationRespVO();
        goodsBrandUpdateOprationRespVO.setId(goodsBrandVO.getId());
        goodsBrandUpdateOprationRespVO.setGoodsBrandCode(goodsBrandVO.getGoodsBrandCode());
        goodsBrandUpdateOprationRespVO.setGoodsBrandName(goodsBrandVO.getGoodsBrandName());
        goodsBrandUpdateOprationRespVO.setGoodsBrandWww(goodsBrandVO.getGoodsBrandWww());
        goodsBrandUpdateOprationRespVO.setGoodsBrandPic(goodsBrandVO.getGoodsBrandPic());
        goodsBrandUpdateOprationRespVO.setGoodsBrandText(goodsBrandVO.getGoodsBrandText());
        goodsBrandUpdateOprationRespVO.setGoodsBrandDel(goodsBrandVO.getGoodsBrandDel());
        return goodsBrandUpdateOprationRespVO;
    }

    @Override
    public boolean saveAll(List<GoodsBrandVO> list) {
        for (GoodsBrandVO goodsBrandVO : list) {
            baseMapper.insert(goodsBrandVO);
        }
        return true;
    }
}




