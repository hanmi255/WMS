package com.zeroone.star.j5.basezl.service.impl;

import com.alibaba.cloud.commons.lang.StringUtils;
import com.baomidou.mybatisplus.core.conditions.query.LambdaQueryWrapper;
import com.baomidou.mybatisplus.core.conditions.update.LambdaUpdateWrapper;
import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.j5.basezl.entity.MdCus;
import com.zeroone.star.j5.basezl.entity.customer.CustomerDO;
import com.zeroone.star.j5.basezl.entity.customer.CustomerExcel;
import com.zeroone.star.j5.basezl.mapper.CustomerMapper;
import com.zeroone.star.j5.basezl.service.CustomerService;
import com.zeroone.star.project.components.easyexcel.EasyExcelComponent;
import com.zeroone.star.project.components.fastdfs.FastDfsClientComponent;
import com.zeroone.star.project.components.fastdfs.FastDfsFileInfo;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j5.basezl.customer.CustomerAddDTO;
import com.zeroone.star.project.dto.j5.basezl.customer.CustomerDetailDTO;
import com.zeroone.star.project.dto.j5.basezl.customer.CustomerListDTO;
import com.zeroone.star.project.dto.j5.basezl.customer.CustomerModifyDTO;
import com.zeroone.star.project.query.j5.basezl.customer.CustomerQuery;
import lombok.extern.slf4j.Slf4j;
import org.mapstruct.Mapper;
import org.mapstruct.Mapping;
import org.mapstruct.Named;
import org.springframework.beans.factory.annotation.Value;
import org.springframework.http.HttpHeaders;
import org.springframework.http.HttpStatus;
import org.springframework.http.MediaType;
import org.springframework.http.ResponseEntity;
import org.springframework.stereotype.Service;
import org.springframework.web.multipart.MultipartFile;

import javax.annotation.Resource;
import java.io.ByteArrayOutputStream;
import java.time.LocalDateTime;
import java.time.format.DateTimeFormatter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Iterator;
import java.util.List;
import java.util.stream.Collectors;


@Mapper(componentModel = "spring")
interface MsCustomerMapper {
    /**
     * 客户详细数据模型
     * @param entity
     * @return
     */
    @Mapping(source = "zuZhiJiGou",target = "zuZhiJiGou",qualifiedByName = "stringToList")
    CustomerDetailDTO customerDetailDOtoCustomerDTO(CustomerDO entity);
    /**
     * 单个DO转DTO
     * @param entity 数据对象
     * @return DTO对象
     */
    CustomerListDTO customerDOToCustomerListDTO(CustomerDO entity);


    /**
     * CustomerAddDTO 变为 CustomerDO
     * @param dto 源对象
     * @return 转化后的对象
     */
    @Mapping(source = "zuZhiJiGou",target = "zuZhiJiGou",qualifiedByName = "listToString")
    CustomerDO customerAddDtoToCustomerDo(CustomerAddDTO dto);
    /**
     * CustomerModifyDTO 变为 CustomerDO
     * @param dto 源对象
     * @return 转化后的对象
     */
    @Mapping(source = "zuZhiJiGou",target = "zuZhiJiGou",qualifiedByName = "listToString")
    CustomerDO customerModifyDtoToCustomerDo(CustomerModifyDTO dto);
    /**
     * CustomerDO 变为 CustomerExcel
     * @param cusDO 源对象
     * @return 转化后的对象
     */
    CustomerExcel customerDOToCustomerExcel(CustomerDO cusDO);
    List<CustomerExcel> customerDOToCustomerExcelList(List<CustomerDO> customerDOList);
    /**
     * CustomerExcel 变为 CustomerDO
     * @param cusExcel 源对象
     * @return 转化后的对象
     */
    CustomerDO customerExcelToCustomerDO(CustomerExcel cusExcel);
    List<CustomerDO> customerExcelToCustomerDOList(List<CustomerExcel> cusExcelList);

    @Named("stringToList")
    static List<String> StringToList(String zuZhiJiGou) {
        if (zuZhiJiGou == null || zuZhiJiGou.isEmpty()) {
            return new ArrayList<>();
        }
        return Arrays.asList(zuZhiJiGou.split(","));
    }
    @Named("listToString")
    default String listToString(List<String> list) {
        return list == null ? null : String.join(", ", list);
    }

}

@Service
@Slf4j
public class CustomerServiceImpl extends ServiceImpl<CustomerMapper, CustomerDO> implements CustomerService {

    /**
     * 查询客户名称列表
     * @param
     * @return
     */

    @Override
    public List<String> selectCustomerNames() {
        return baseMapper.selectList(null)
                .stream()
                .map(cus -> cus.getKeHuBianMa() + "-" + cus.getZhongWenQch())
                .collect(Collectors.toList());
    }

    /**
     * 查询所有客户信息
     * @param query
     * @return
     */
    @Override
    public PageDTO<CustomerListDTO> selectAllCustomer(CustomerQuery query) {
        // 构建分页条件
        Page<CustomerDO> page = new Page<>(query.getPageIndex(), query.getPageSize());

        // 构建查询条件
        LambdaQueryWrapper<CustomerDO> wrapper = new LambdaQueryWrapper<>();

        //匹配名称和客户编码
        if(query.getCustomerName()!=null)
            wrapper.like(CustomerDO::getZhongWenQch, query.getCustomerName());
        if(query.getCustomerCode()!=null)
            wrapper.like(CustomerDO::getKeHuBianMa, query.getCustomerCode());
        // 执行分页查询
        Page<CustomerDO> doPage = baseMapper.selectPage(page, wrapper);

        return PageDTO.create(doPage, customerDO -> {
            // 调用单个对象转换方法
            return msMapper.customerDOToCustomerListDTO(customerDO);
        });
    }

    /**
     * 查询客户详细信息
     * @param customerId 客户id
     * @return
     */
    @Override
    public CustomerDetailDTO getById(String customerId) {
        // 根据ID查询实体
        CustomerDO customerDO = baseMapper.selectById(customerId);
        if (customerDO == null) {
            throw new RuntimeException("客户不存在");
        }
        // 转换为详细DTO
        return msMapper.customerDetailDOtoCustomerDTO(customerDO);
    }

    /**
     * 添加客户信息
     * @param dto 客户信息
     * @return
     */
    @Override
    public int addCustomer(CustomerAddDTO dto) {
        dto.setXingYeFenLei("01");
        LambdaQueryWrapper<CustomerDO> wrapper = new LambdaQueryWrapper<>();
        wrapper.eq(CustomerDO::getKeHuBianMa, dto.getKeHuBianMa());
        List<CustomerDO> customerDOS = mapper.selectList(wrapper);
        if(!customerDOS.isEmpty()) {
            throw new IllegalArgumentException("该客户编码已存在！");
        }
        CustomerDO customerDO = msMapper.customerAddDtoToCustomerDo(dto);
        customerDO.setCreateDate(LocalDateTime.now());
        int insert = baseMapper.insert(customerDO);
        return insert;
    }
 /* <p>
 *  客户 服务实现类
 * </p>c
 *
 * @author 杨芋
 * @since 2025-02-27
 */
    @Resource
    CustomerMapper mapper;

    @Resource
    MsCustomerMapper msMapper;

    @Resource
    EasyExcelComponent excel;


    @Override
    public int updateCus(CustomerModifyDTO dto) {
        CustomerDO exist = mapper.selectById(dto.getId());
        if(exist==null) throw new RuntimeException("客户不存在");
        LambdaUpdateWrapper<CustomerDO> updateWrapper = new LambdaUpdateWrapper<>();
        updateWrapper.eq(CustomerDO::getId, dto.getId());
        CustomerDO customerDO = msMapper.customerModifyDtoToCustomerDo(dto);
        return mapper.update(customerDO, updateWrapper);
    }

    @Override
    public int removeCus(List<String> cusIds) {
        return mapper.deleteBatchIds(cusIds);
    }

    @Override
    public ResponseEntity<byte[]> exportCus(List<String> cusIds) {
        List<CustomerDO> customerDOS = mapper.selectBatchIds(cusIds);
        List<CustomerExcel> customerExcels = msMapper.customerDOToCustomerExcelList(customerDOS);
        //将excel写入内存中
        try(ByteArrayOutputStream out=new ByteArrayOutputStream()) {
            excel.export("客户信息",out,CustomerExcel.class,customerExcels);
            //创建响应头部
            HttpHeaders httpHeaders = new HttpHeaders();
            //设置响应体的mime类型为xlsx类型
            httpHeaders.setContentType(MediaType.valueOf("application/vnd.openxmlformats-officedocument.spreadsheetml.sheet"));
            // 获取当前时间
            LocalDateTime now = LocalDateTime.now();
            // 定义时间格式（例如：20250304_153045）
            DateTimeFormatter formatter = DateTimeFormatter.ofPattern("yyyyMMdd_HHmmss");
            String timestamp = now.format(formatter);
            // 文件名模板
            String fileName = "customer_file_" + timestamp + ".xlsx";
            httpHeaders.setContentDispositionFormData("attachment",fileName);
            byte[] bytes = out.toByteArray();
            return new ResponseEntity<>(bytes,httpHeaders, HttpStatus.CREATED);
        } catch (Exception e) {
            throw new RuntimeException("导出客户信息失败");
        }
    }


    @Override
    public int importCus(MultipartFile file) {
        List<CustomerExcel> customerExcels = excel.parseExcel(file, CustomerExcel.class);
        List<CustomerDO> customerDOS = msMapper.customerExcelToCustomerDOList(customerExcels);
        //导入的客户要保证客户编码唯一
        Iterator<CustomerDO> iterator = customerDOS.iterator();
        while (iterator.hasNext()) {
            CustomerDO next = iterator.next();
            LambdaQueryWrapper<CustomerDO> wrapper = new LambdaQueryWrapper<>();
            wrapper.eq(CustomerDO::getKeHuBianMa, next.getKeHuBianMa());
            List<CustomerDO> exist = mapper.selectList(wrapper);
            if(!exist.isEmpty()) {
                iterator.remove();
            }
        }
        boolean b = this.saveBatch(customerDOS);
        if(b) {
            return 1;
        }
        return 0;
    }
}


