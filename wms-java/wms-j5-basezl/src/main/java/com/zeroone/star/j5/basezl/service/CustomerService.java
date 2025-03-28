package com.zeroone.star.j5.basezl.service;
import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.j5.basezl.entity.MdCus;
import com.zeroone.star.j5.basezl.entity.customer.CustomerDO;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j5.basezl.customer.CustomerAddDTO;
import com.zeroone.star.project.dto.j5.basezl.customer.CustomerDetailDTO;
import com.zeroone.star.project.dto.j5.basezl.customer.CustomerListDTO;
import com.zeroone.star.project.query.j5.basezl.customer.CustomerQuery;
import com.zeroone.star.project.dto.j5.basezl.customer.CustomerModifyDTO;
import org.springframework.http.ResponseEntity;
import org.springframework.web.multipart.MultipartFile;

import java.util.List;

/**
 * <p>
<<<<<<< HEAD
 * 客户信息 服务类
 * </p>
 *
 * @author xiaoxia
 * @since 2025-02-28
 */
public interface CustomerService extends IService<CustomerDO> {

    /**
     * 查询客户名称列表
     * @param
     * @return
     */
    List<String> selectCustomerNames();

    /**
     * 查询所有客户信息
     * @param query
     * @return
     */
    PageDTO<CustomerListDTO> selectAllCustomer(CustomerQuery query);

    /**
     * 查询客户详细信息
     * @param customerId 客户id
     * @return 客户详细信息
     */
    CustomerDetailDTO getById(String customerId);

    /**
     * 添加客户
     * @param dto 客户信息
     * @return 添加结果
     */
    int addCustomer(CustomerAddDTO dto);
/*  客户 服务类
 * </p>
 *
 * @author 杨芋
 * @since 2025-02-27
 */
    /**
     * 修改客户
     * @param dto 用户信息
     * @return 修改结果
     */
    int updateCus(CustomerModifyDTO dto);
    /**
     * 删除客户
     * @param cusIds 用户id
     * @return 删除结果
     */
    int removeCus(List<String> cusIds);
    /**
     * 导出客户
     * @param cusIds 用户id
     * @return 导出结果
     */
    ResponseEntity<byte[]> exportCus(List<String> cusIds);

    /**
     * 导入客户
     * @param file 导入的excel文件
     * @return 导入结果
     */
    int importCus(MultipartFile file);
}
