package com.zeroone.star.daycheck.service.impl;

import cn.hutool.core.date.DateTime;
import cn.hutool.core.lang.UUID;
import com.alibaba.excel.EasyExcel;
import com.alibaba.excel.read.builder.ExcelReaderBuilder;
import com.alibaba.excel.read.builder.ExcelReaderSheetBuilder;
import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.daycheck.Listener.TemperatureListener;
import com.zeroone.star.daycheck.entity.Temperature;
import com.zeroone.star.daycheck.mapper.TemperatureMapper;
import com.zeroone.star.daycheck.service.ITemperatureService;
import com.zeroone.star.project.components.easyexcel.EasyExcelComponent;
import com.zeroone.star.project.components.user.UserDTO;
import com.zeroone.star.project.components.user.UserHolder;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j3.daycheck.tem.TemperatureDTO;
import com.zeroone.star.project.dto.j3.daycheck.tem.TemperatureUpdateDTO;
import com.zeroone.star.project.query.j3.daycheck.tem.TemperaturePageQuery;
import com.zeroone.star.project.vo.j3.daycheck.tem.TemperatureVO;
import lombok.SneakyThrows;
import org.apache.poi.util.StringUtil;
import org.springframework.beans.BeanUtils;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.http.HttpHeaders;
import org.springframework.http.HttpStatus;
import org.springframework.http.MediaType;
import org.springframework.http.ResponseEntity;
import org.springframework.stereotype.Service;
import org.springframework.util.StringUtils;
import org.springframework.web.multipart.MultipartFile;

import javax.annotation.Resource;
import java.io.ByteArrayOutputStream;
import java.time.LocalDateTime;
import java.util.List;
import java.util.stream.Collectors;

@Service
public class TemperatureServiceImpl extends ServiceImpl<TemperatureMapper,Temperature> implements ITemperatureService{

    @Resource
    private UserHolder userHolder;

    @Autowired
    private TemperatureMapper temperatureMapper;

    @Resource
    EasyExcelComponent excel;

    /**
     * 录入温度
     *
     * @param temperatureDTO
     */
    @SneakyThrows
    @Override
    public void saveTemp(TemperatureDTO temperatureDTO) { //保存信息
        // 将前端传来的数据封装到temperature实体类中
        Temperature temperature = new Temperature();
        BeanUtils.copyProperties(temperatureDTO, temperature);
        UserDTO currentUser = userHolder.getCurrentUser();
        if (currentUser == null) {
            throw new IllegalStateException("当前用户信息为空，请先登录！");
        }
        // 通过UUID生成主键id
        temperature.setId(UUID.randomUUID().toString());
        // 创建人名称
        temperature.setCreateName(currentUser.getRealname());
        // 创建人登录名称
        temperature.setCreateBy(currentUser.getUsername());
        // 创建日期
        temperature.setCreateDate(LocalDateTime.now());
        // 更新人名称
        temperature.setUpdateName(currentUser.getRealname());
        // 更新人登录名称
        temperature.setUpdateBy(currentUser.getUsername());
        // 更新日期
        temperature.setUpdateDate(LocalDateTime.now());
        // 所属部门
        temperature.setSysOrgCode(currentUser.getOrgCode());
        // 所属公司
        temperature.setSysCompanyCode(currentUser.getCompanyCode());
        // 流程状态
        temperature.setBpmStatus(currentUser.getIsEnabled().toString());

        temperatureMapper.saveTemp(temperature);
    }

    /**
     * 删除温度
     * @param ids
     */
    @Override
    public void deleteTemps(List<String> ids) {
        temperatureMapper.deleteTemps(ids);
    }

    /**
     * 修改温度
     * @param temperatureUpdateDTO
     */
    @SneakyThrows
    @Override
    public void updateTemp(TemperatureUpdateDTO temperatureUpdateDTO) {
        //获取当前用户
        UserDTO currentUser = userHolder.getCurrentUser();
        if (currentUser == null) {
            throw new IllegalStateException("当前用户信息为空，请先登录！");
        }
        // 将前端传来的数据封装到temperature实体类中
        Temperature temperature = new Temperature();
        BeanUtils.copyProperties(temperatureUpdateDTO, temperature);

        // TODO 获取当前登录用户信息, 并封装到temperature中（暂时未实现， 拿到token，用openFeign向j1的用户功能发送请求，获取用户数据）
        // 更新人名称
        temperature.setUpdateName(currentUser.getRealname());
        // 更新人登录名称
        temperature.setUpdateBy(currentUser.getUsername());
        // 更新日期
        temperature.setUpdateDate(LocalDateTime.now());

        temperatureMapper.updateTemp(temperature);
    }

    /**
     * 根据id查询温度信息
     * @param id
     * @return
     */
    @Override
    public TemperatureVO temperatureById(String id) {
        // 根据id查询温度信息
        Temperature temperature = temperatureMapper.TemperatureById(id);

        // 将查询到的温度信息封装到temperatureDetailVo中
        TemperatureVO temperatureVO = new TemperatureVO();
        BeanUtils.copyProperties(temperature, temperatureVO);

        return temperatureVO;
    }

    @Override
    public PageDTO<TemperatureVO> pageQueryAll(TemperaturePageQuery query) {
        // 利用分页插件开始分页
        Page<Temperature> page = Page.of(query.getPageIndex(), query.getPageSize());

        //从数据库里面查
        Page<Temperature> p = this.page(page);

        //DO->Vo
        List<TemperatureVO> list = p.getRecords().stream().map(e -> {
            TemperatureVO temperatureVO = new TemperatureVO();
            BeanUtils.copyProperties(e, temperatureVO);
            return temperatureVO;
        }).collect(Collectors.toList());
        //封装数据
        Page<TemperatureVO> page1 = new Page<>();
        BeanUtils.copyProperties(p,page1);
        page1.setRecords(list);
        //调用组件，统一返回数据格式
        PageDTO<TemperatureVO> pageResult = PageDTO.create(page1);
        return pageResult;
    }

    @SneakyThrows
    @Override
    public ResponseEntity<byte[]> exportTemperature() {
        //解析Excel文件
        List<Temperature> data = temperatureMapper.selectAll();
        //导出到输出流
        ByteArrayOutputStream outputStream = new ByteArrayOutputStream();
        excel.export("temperature", outputStream, Temperature.class, data);
        //响应文件数据
        String fileName = "rep-" + DateTime.now().toString("yyyyMMddHHmmssS") + ".xlsx";
        HttpHeaders headers = new HttpHeaders();
        headers.setContentDispositionFormData("attachment", fileName);
        headers.setContentType(MediaType.APPLICATION_OCTET_STREAM);
        ResponseEntity<byte[]> result = new ResponseEntity<>(outputStream.toByteArray(), headers, HttpStatus.CREATED);
        outputStream.close();
        return result;
    }

    @SneakyThrows
    @Override
    public List<Temperature> importTemperature(MultipartFile file, Class head, TemperatureListener listener) {
        //解析Excel文件
        //拿到当前用户
        UserDTO currentUser = userHolder.getCurrentUser();
        if (currentUser == null) {
            throw new IllegalStateException("当前用户信息为空，请先登录！");
        }
        //获得工作簿
        ExcelReaderBuilder readBook = EasyExcel.read(file.getInputStream(),head,listener);
        //获得sheet
        ExcelReaderSheetBuilder sheet = readBook.sheet();
        //获得Excel中的数据
        List<Temperature> data = sheet.doReadSync();
        for(Temperature temperature : data){
            // 通过UUID生成主键id
            temperature.setId(UUID.randomUUID().toString());
            // 创建人名称
            temperature.setCreateName(currentUser.getRealname());
            // 创建人登录名称
            temperature.setCreateBy(currentUser.getUsername());
            // 创建日期
            temperature.setCreateDate(LocalDateTime.now());
            // 更新人名称
            temperature.setUpdateName(currentUser.getRealname());
            // 更新人登录名称
            temperature.setUpdateBy(currentUser.getUsername());
            // 更新日期
            temperature.setUpdateDate(LocalDateTime.now());
            // 所属部门
            temperature.setSysOrgCode(currentUser.getOrgCode());
            // 所属公司
            temperature.setSysCompanyCode(currentUser.getCompanyCode());
            // 流程状态
            temperature.setBpmStatus(currentUser.getIsEnabled().toString());
        }
        temperatureMapper.saveBatch(data);
        return data;
    }
}
