package com.zeroone.star.stockln.service.impl;

import cn.hutool.core.bean.BeanUtil;
import cn.hutool.json.JSONUtil;
import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.baomidou.mybatisplus.core.conditions.update.UpdateWrapper;
import com.baomidou.mybatisplus.core.toolkit.IdWorker;
import com.zeroone.star.project.dto.j6.stockln.ImNoticeDTO;
import com.zeroone.star.project.dto.j6.stockln.ImportNoticeDTO;
import com.zeroone.star.project.dto.j6.stockln.ImportNoticeItemDTO;
import com.zeroone.star.project.dto.j6.stockln.UpdateImNoticeIDTO;
import com.zeroone.star.stockln.entity.ImNoticeH;
import com.zeroone.star.stockln.entity.ImNoticeI;
import com.zeroone.star.stockln.entity.MdGoods;
import com.zeroone.star.stockln.mapper.ImNoticeHMapper;
import com.zeroone.star.stockln.mapper.ImNoticeIMapper;
import com.zeroone.star.stockln.mapper.MdGoodsMapper;
import com.zeroone.star.stockln.service.IImNoticeHService;
import com.zeroone.star.stockln.service.IImNoticeIService;
import com.zeroone.star.stockln.service.IImNoticeService;
import org.mapstruct.Mapper;
import org.springframework.http.HttpHeaders;
import org.springframework.http.ResponseEntity;
import org.springframework.stereotype.Component;
import org.springframework.stereotype.Service;
import org.springframework.transaction.annotation.Transactional;

import javax.annotation.Resource;
import java.io.UnsupportedEncodingException;
import java.net.URLEncoder;
import java.nio.charset.StandardCharsets;
import java.time.LocalDateTime;
import java.time.ZoneOffset;
import java.time.format.DateTimeFormatter;
import java.util.Iterator;
import java.util.LinkedList;
import java.util.List;
import java.util.UUID;

@Mapper(componentModel = "spring")
interface ImNoticeMapper{
    ImNoticeH imNoticeDTOToImNoticeH(ImportNoticeDTO importNoticeDTO);
    ImNoticeI imNoticeDTOToImNoticeI(ImportNoticeItemDTO importNoticeItemDTO);

    ImportNoticeDTO  imNoticeHToImNoticeDTO(ImNoticeH imNoticeH);
    ImportNoticeItemDTO  imNoticeHToImNoticeItemDTO(ImNoticeI imNoticeI);
}

@Service
public class ImNoticeServiceImpl implements IImNoticeService {
    @Resource
    private ImNoticeMapper imNoticeMapper;
    @Resource
    private IImNoticeHService imNoticeHService;
    @Resource
    private IImNoticeIService imNoticeIService;
    @Resource
    private MdGoodsMapper mdGoodsMapper;
    @Resource
    private ImNoticeIMapper imNoticeIMapper;

    @Override
    public ResponseEntity export(String id) {
        ImNoticeH imNoticeH = imNoticeHService.getById(id);
        List<ImNoticeI> imNoticeI = imNoticeIService.list(new QueryWrapper<ImNoticeI>()
                .eq("im_notice_id",id)
        );
        ImportNoticeDTO importNoticeDTO = BeanUtil.copyProperties(imNoticeH,ImportNoticeDTO.class);
        Iterator iterator = imNoticeI.iterator();
        List<ImportNoticeItemDTO> imDTOList = new LinkedList<>();
        while(iterator.hasNext()){
            imDTOList.add(BeanUtil.copyProperties(iterator.next(), ImportNoticeItemDTO.class));
        }
        importNoticeDTO.setImportNoticeItemDTOList(imDTOList);

        String csvContent = JSONUtil.toJsonStr(importNoticeDTO);
        byte[] fileContent = csvContent.getBytes(StandardCharsets.UTF_8);


        //根据id查找对应的记录

        //根据记录生成对应的pdf

        //设置响应头
        HttpHeaders headers = new HttpHeaders();
        headers.add(HttpHeaders.CONTENT_TYPE,"application/octet-stream");
        // 设置响应头，使用URLEncoder对中文文件名进行URL编码
        String encodedFileName=null;
        try {
            encodedFileName = URLEncoder.encode("入库通知单.txt", "UTF-8").replaceAll("\\+", "%20");
        } catch (UnsupportedEncodingException e) {
            throw new RuntimeException(e);
        }
//        headers.add(HttpHeaders.CONTENT_DISPOSITION,"attachment;filename*UTF-8' '"+encodedFileName);//有bug，ai教的应该是错的
        headers.add(HttpHeaders.CONTENT_DISPOSITION,"attachment;filename="+encodedFileName);


        return ResponseEntity
                .ok()
                .headers(headers)
                .body(fileContent);
    }

    @Transactional
    @Override
    public void updateImport(ImportNoticeDTO importNoticeDTO) {
        ImNoticeH imNoticeH = BeanUtil.copyProperties(importNoticeDTO,ImNoticeH.class);
        imNoticeHService.update(imNoticeH,new QueryWrapper<ImNoticeH>().eq("notice_id",imNoticeH.getNoticeId()));
        List<ImportNoticeItemDTO> imDTOList = importNoticeDTO.getImportNoticeItemDTOList();
        List<ImNoticeI> imNoticeIList = new LinkedList<>();
        Iterator<ImportNoticeItemDTO> iterator = imDTOList.iterator();
        String noticeId = imNoticeH.getNoticeId();

        List<UpdateImNoticeIDTO> list = new LinkedList<>();
        while(iterator.hasNext()){
            ImportNoticeItemDTO importNoticeItemDTO = iterator.next();
            String goodsCode = importNoticeItemDTO.getGoodsCode();


            UpdateImNoticeIDTO updateImNoticeIDTO = new UpdateImNoticeIDTO();
            String countS = importNoticeItemDTO.getGoodsCount();
            String binPlan = importNoticeItemDTO.getBinPlan();
            String binPre = importNoticeItemDTO.getBinPre();
            updateImNoticeIDTO.setGoodsCode(goodsCode);
            updateImNoticeIDTO.setBinPlan(binPlan);
            updateImNoticeIDTO.setBinPre(binPre);
            updateImNoticeIDTO.setGoodsCount(countS);

            MdGoods mdGoods = mdGoodsMapper.selectOne(new QueryWrapper<MdGoods>()
                    .eq("shp_bian_ma",goodsCode));
            if(mdGoods==null)continue;

            if(countS!=null&&!countS.equals("")){
                Long count = Long.parseLong(countS);
                String fvolS = mdGoods.getTiJiCm();
                if(fvolS!=null&&!fvolS.equals("")){
                    Long fvol = Long.parseLong(fvolS);
                    Long goodsFvol = count*fvol;
                    updateImNoticeIDTO.setGoodsFvol(String.valueOf(goodsFvol));
                }
                String weightS = mdGoods.getZhlKg();
                if(weightS!=null&&!weightS.equals("")){
                    Long weight = Long.parseLong(mdGoods.getZhlKg());
                    Long goodsWeight = count*weight;
                    updateImNoticeIDTO.setGoodsWeight(String.valueOf(goodsWeight));
                }
            }
            list.add(updateImNoticeIDTO);
        }
        imNoticeIMapper.updateImNoticeItem(list,noticeId);
    }

    @Transactional
    @Override
    public void insertImport(ImportNoticeDTO importNoticeDTO) {
        //生成主键
        LocalDateTime now = LocalDateTime.now();
        String data = now.format(DateTimeFormatter.ofPattern("yyyyMMdd"));
        String uuid = UUID.randomUUID().toString().replace("-", ""); // 32 位
        String shortUuid = uuid.substring(0, 10); // 截取前 10 位
        String noticeId=shortUuid+data;

        String hId = String.valueOf(IdWorker.getId());
        String iId = String.valueOf(IdWorker.getId());
        //封装通知单抬头
        ImNoticeH imNoticeH = imNoticeMapper.imNoticeDTOToImNoticeH(importNoticeDTO);
        imNoticeH.setId(hId);
        imNoticeH.setNoticeId(noticeId);
        imNoticeHService.save(imNoticeH);
        //封装通知单项
        List<ImportNoticeItemDTO> importNoticeItemDTOList = importNoticeDTO.getImportNoticeItemDTOList();
        Iterator<ImportNoticeItemDTO> iterator = importNoticeItemDTOList.iterator();
        List<ImNoticeI> list = new LinkedList();
        while(iterator.hasNext()){
            ImNoticeI imNoticeI = imNoticeMapper.imNoticeDTOToImNoticeI(iterator.next());
            imNoticeI.setId(iId);
            imNoticeI.setImNoticeId(noticeId);
            imNoticeI.setImNoticeItem(hId);
            MdGoods mdGoods = mdGoodsMapper.selectOne(new UpdateWrapper<MdGoods>()
                    .eq("shp_bian_ma",imNoticeI.getGoodsCode()));
            if(mdGoods==null)break;
            imNoticeI.setSysOrgCode(mdGoods.getSysOrgCode());
            imNoticeI.setSysCompanyCode(mdGoods.getSysCompanyCode());
            imNoticeI.setGoodsUnit(mdGoods.getShlDanWei());
            imNoticeI.setBaseUnit(mdGoods.getJshDanWei());
            imNoticeI.setGoodsName(mdGoods.getShpMingCheng());
            imNoticeI.setImBeizhu(imNoticeH.getImBeizhu());
            imNoticeI.setChpShuXing(mdGoods.getChpShuXing());

            String countS = imNoticeI.getGoodsCount();
            if(countS!=null&&!countS.equals("")){
                Long count = Long.parseLong(countS);
                String fvolS = mdGoods.getTiJiCm();
                if(fvolS!=null&&!fvolS.equals("")){
                    Long fvol = Long.parseLong(fvolS);
                    Long goodsFvol = count*fvol;
                    imNoticeI.setGoodsFvol(goodsFvol.toString());
                }
                String weightS = mdGoods.getZhlKg();
                if(weightS!=null&&!weightS.equals("")){
                    Long weight = Long.parseLong(mdGoods.getZhlKg());
                    Long goodsWeight = count*weight;
                    imNoticeI.setGoodsWeight(goodsWeight.toString());
                }
            }
            list.add(imNoticeI);
        }
        imNoticeIService.saveBatch(list);
    }

    @Override
    public ImportNoticeDTO searchImport(String imNoticeId) {
        ImNoticeH imNoticeH = imNoticeHService.getOne(new QueryWrapper<ImNoticeH>()
                .eq("notice_id",imNoticeId));
        ImportNoticeDTO imNoticeDTO = imNoticeMapper.imNoticeHToImNoticeDTO(imNoticeH);
        List<ImNoticeI> list = imNoticeIMapper.selectList(new QueryWrapper<ImNoticeI>()
                .eq("im_notice_id",imNoticeId));
        Iterator<ImNoticeI> iterator = list.iterator();
        List<ImportNoticeItemDTO> list_ = new LinkedList();
        while(iterator.hasNext()){
            ImportNoticeItemDTO importNoticeItemDTO = imNoticeMapper
                    .imNoticeHToImNoticeItemDTO(iterator.next());
            list_.add(importNoticeItemDTO);
        }
        imNoticeDTO.setImportNoticeItemDTOList(list_);
        return imNoticeDTO;
    }
}
