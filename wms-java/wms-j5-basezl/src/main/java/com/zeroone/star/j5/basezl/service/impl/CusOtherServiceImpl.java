package com.zeroone.star.j5.basezl.service.impl;

import cn.hutool.core.bean.BeanUtil;
import cn.hutool.core.util.StrUtil;
import com.alibaba.excel.EasyExcel;
import com.baomidou.mybatisplus.core.conditions.query.LambdaQueryWrapper;
import com.baomidou.mybatisplus.core.conditions.update.LambdaUpdateWrapper;
import com.baomidou.mybatisplus.core.toolkit.support.SFunction;
import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.j5.basezl.entity.cusother.CusOther4Excel;
import com.zeroone.star.j5.basezl.entity.cusother.CusOtherDO;
import com.zeroone.star.j5.basezl.mapper.CusOtherMapper;
import com.zeroone.star.j5.basezl.service.CusOtherService;
import com.zeroone.star.project.components.easyexcel.EasyExcelComponent;
import com.zeroone.star.project.components.easyexcel.ExcelReadListener;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j5.basezl.cusother.CusOtherAddDTO;
import com.zeroone.star.project.dto.j5.basezl.cusother.CusOtherListDTO;
import com.zeroone.star.project.dto.j5.basezl.cusother.CusOtherModifyDTO;
import com.zeroone.star.project.query.j5.basezl.cusother.CusOtherQuery;
import com.zeroone.star.project.vo.j5.basezl.CusOtherVO;
import lombok.extern.slf4j.Slf4j;
import org.springframework.beans.BeanUtils;
import org.springframework.http.HttpHeaders;
import org.springframework.http.HttpStatus;
import org.springframework.http.MediaType;
import org.springframework.http.ResponseEntity;
import org.springframework.stereotype.Service;
import org.springframework.transaction.annotation.Transactional;
import org.springframework.web.multipart.MultipartFile;

import javax.annotation.Resource;
import java.io.ByteArrayOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.util.ArrayList;
import java.util.List;
import java.util.stream.Collectors;

/**
 * <p>
 * 描述: 第三方客户业户逻辑接口实现类
 * </p>
 * <p>版权所有: &copy;枢璇</p>
 *
 * @author 枢璇
 * @Version 1.0.0
 * @since 2025/2/26 15:37
 */
@Slf4j
@Service("cusOtherService")
public class CusOtherServiceImpl extends ServiceImpl<CusOtherMapper, CusOtherDO> implements CusOtherService {

    @Resource
    private EasyExcelComponent easyExcelComponent;
    /**
     * 获取第三方客户列表
     * @param query 查询参数
     * @return 分页查询结果
     */
    @Override
    public PageDTO<CusOtherListDTO> listCusOther(CusOtherQuery query) {
        LambdaQueryWrapper<CusOtherDO> queryWrapper = new LambdaQueryWrapper<>();
        // 动态构建查询条件
        addEqualIfPresent(queryWrapper, CusOtherDO::getKeHuBianMa, query.getKeHuBianMa());
        addEqualIfPresent(queryWrapper, CusOtherDO::getSuoShuKeHu, query.getSuoShuKeHu());
        addEqualIfPresent(queryWrapper, CusOtherDO::getZhongWenQch, query.getZhongWenQch());

        // 构建分页对象
        Page<CusOtherDO> page = new Page<>(query.getPageIndex(), query.getPageSize());

        // 进行分页查询
        page(page, queryWrapper);

        return PageDTO.create(page, CusOtherListDTO.class);
    }

    /**
     * 获取客户编码对应的第三方客户的详细信息
     * @param keHuBianMa 客户编码
     * @return 客户详细信息VO
     */
    @Override
    public CusOtherVO getCusOtherDetail(String keHuBianMa) {
        LambdaQueryWrapper<CusOtherDO> queryWrapper = new LambdaQueryWrapper<>();
        if(StrUtil.isBlank(keHuBianMa)) {
            log.info("客户编码为空!");
            throw new IllegalArgumentException("客户编码为空");
        }
        queryWrapper.eq(CusOtherDO::getKeHuBianMa, keHuBianMa);

        return BeanUtil.copyProperties(baseMapper.selectOne(queryWrapper), CusOtherVO.class);
    }

    /**
     * 录入第三方客户
     * @param dto 第三方客户信息
     * @return 录入结果
     */
    @Override
    public String saveCusOther(CusOtherAddDTO dto) {
        String keHuBianMa = dto.getKeHuBianMa();
        if(StrUtil.isBlank(keHuBianMa)) {
            log.info("客户编码为空!");
            throw new IllegalArgumentException("客户编码为空");
        }
        LambdaQueryWrapper<CusOtherDO> queryWrapper = new LambdaQueryWrapper<>();
        queryWrapper.eq(CusOtherDO::getKeHuBianMa, keHuBianMa);
        CusOtherDO cusOtherDO = baseMapper.selectOne(queryWrapper);
        if(cusOtherDO != null) {
            log.info("客户已存在!");
            throw new IllegalArgumentException("客户已存在");
        }
        CusOtherDO toSave = BeanUtil.copyProperties(dto, CusOtherDO.class);

        int result = baseMapper.insert(toSave);

        return result == 0 ? "录入失败" : "录入成功";
    }

    /**
     * 修改第三方客户
     * @param dto 第三方客户信息
     * @return 修改结果
     */
    @Override
    public String updateCusOther(CusOtherModifyDTO dto) {
        // 验证输入数据
        if (dto == null || StrUtil.isBlank(dto.getKeHuBianMa())) {
            log.info("客户不存在!");
            throw new IllegalArgumentException("客户不存在");
        }
        LambdaUpdateWrapper<CusOtherDO> updateWrapper = new LambdaUpdateWrapper<>();
        updateWrapper.eq(CusOtherDO::getKeHuBianMa, dto.getKeHuBianMa());
        int result = baseMapper.update(BeanUtil.copyProperties(dto, CusOtherDO.class), updateWrapper);

        return result == 0 ? "修改失败" : "修改成功";

    }


    /**
     * 动态添加查询条件
     * @param wrapper 条件构造器
     * @param column 字段
     * @param value 字段值
     * @param <T> DO类
     */
    private <T> void addEqualIfPresent(LambdaQueryWrapper<T> wrapper, SFunction<T, ?> column, String value) {
        if (StrUtil.isNotBlank(value)) {
            wrapper.eq(column, value);
        }
    }


    @Transactional
    @Override
    public void removeByBianMa(List<String> ids) {
        int row = baseMapper.deleteBatchIds(ids);
        if(row != ids.size()){
            throw new RuntimeException("删除失败");
        }
    }

    @Override
    public ResponseEntity<byte[]> export(List<String> ids) {
        String filename = "CusOther.xlsx";
        HttpHeaders headers = new HttpHeaders();
        headers.setContentDispositionFormData("attachment", filename);
        headers.setContentType(MediaType.APPLICATION_OCTET_STREAM);
        List<CusOther4Excel> cusOther4ExcelList = null;
        //ids为空，则导出空表
        if(ids.isEmpty()){
            cusOther4ExcelList = new ArrayList<>();
            cusOther4ExcelList.add(new CusOther4Excel());
        }else{
            //查询要导出的数据
            List<CusOtherDO> cusOtherDOList = baseMapper.selectBatchIds(ids);
            //将List<CusOtherDO>转换为List<CusOther4Excel>
            cusOther4ExcelList = cusOtherDOList.stream().map(cusOtherDO -> {
                CusOther4Excel cusOther4Excel = new CusOther4Excel();
                BeanUtils.copyProperties(cusOtherDO, cusOther4Excel);
                return cusOther4Excel;
            }).collect(Collectors.toList());
        }

        //将数据导入到输出流，转换为字节数组
        byte[] byteArray = null;
        try (ByteArrayOutputStream outputStream = new ByteArrayOutputStream()){
            easyExcelComponent.export("导出信息",outputStream,CusOther4Excel.class,cusOther4ExcelList);
            byteArray = outputStream.toByteArray();
        } catch (IOException e) {
            throw new RuntimeException("导出失败",e);
        }

        return new ResponseEntity<>(byteArray, headers, HttpStatus.CREATED);
    }

    @Transactional
    @Override
    public void upload(MultipartFile file) {
        //从excel中读取数据到List<CusOther4Excel>
        List<CusOther4Excel> cusOther4ExcelList;
        try (InputStream inputStream = file.getInputStream()){
            ExcelReadListener<CusOther4Excel> listener = new ExcelReadListener<>();
            EasyExcel.read(inputStream, CusOther4Excel.class, listener).sheet().doRead();
            cusOther4ExcelList = listener.getDataList();
        } catch (IOException e) {
            throw new RuntimeException("导入失败",e);
        }
        //将List<CusOther4Excel>转换为List<CusOtherDO>
        List<CusOtherDO> cusOtherDOList = cusOther4ExcelList.stream().map(cusOther4Excel -> {
            CusOtherDO cusOtherDO = new CusOtherDO();
            BeanUtils.copyProperties(cusOther4Excel, cusOtherDO);
            return cusOtherDO;
        }).collect(Collectors.toList());
        //插入数据
        boolean result = this.saveBatch(cusOtherDOList);
        if(!result){
            throw new RuntimeException("导入失败");
        }
    }
}

