package com.zeroone.star.project.j5.basezl;

import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j5.basezl.customer.CustomerAddDTO;
import com.zeroone.star.project.dto.j5.basezl.customer.CustomerDetailDTO;
import com.zeroone.star.project.dto.j5.basezl.customer.CustomerListDTO;
import com.zeroone.star.project.dto.j5.basezl.customer.CustomerModifyDTO;
import com.zeroone.star.project.query.j5.basezl.customer.CustomerQuery;
import com.zeroone.star.project.vo.JsonVO;
import io.swagger.annotations.ApiOperation;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.ModelAttribute;
import org.springframework.web.multipart.MultipartFile;

import javax.validation.constraints.NotNull;
import java.util.List;

/**
 * <p>
 * 描述：客户管理接口
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 * @author 小夏
 * @version 1.0.0
 */
public interface CustomerApis {


    /**
     * 查询客户名称列表
     * @param  无参查询，例如客户名称的关键字
     * @return 响应数据结果
     */
    JsonVO<List<String>> queryCustomerNames( );
    /**
     * 查询客户信息列表
     * @param query 查询条件
     * @return 响应数据结果
     */
    JsonVO<PageDTO<CustomerListDTO>> queryAll(CustomerQuery query);

    /**
     * 获取客户详细信息
     * @param customerId 的id
     * @return 响应数据结果
     */
    JsonVO<CustomerDetailDTO> getDetailsCustomer(@NotNull String customerId);
    /**
     * 录入客户信息
     * @param dto 录入的供应商信息
     * @return 响应数据结果
     */
    JsonVO<String> addCustomer(CustomerAddDTO dto);
    /**
     * 修改客户
     * @param dto 修改后的的客户信息
     * @return 响应数据结果
     */
    JsonVO<String> modifyCustomer(CustomerModifyDTO dto);
    /**
     * 删除供应商（支持批量删除）
     * @param ids 要删除的id的列表
     * @return 响应数据结果
     */
    JsonVO<String> deleteCustomer(List<String> ids);
    /**
     * 导出客户
     * @param ids 要导出的id的列表
     * @return 响应结果
     */
    ResponseEntity<byte[]> exportCustomer(List<String> ids);
    /**
     * 导入客户
     * @param files 要导入的excel文件
     * @return 响应数据结果
     */
    JsonVO<String> importCustomer(MultipartFile[] files);

    /**
     * 上传文件
     * @param file 要上传的文件
     * @return 返回文件存储的信息 格式："group/storageId/文件名.格式"
     */
    JsonVO<String> uploadFile(MultipartFile file) throws Exception;

    /**
     * 下载文件
     * @param info 文件存储的信息
     * @return 返回此文件的下载地址
     */
    JsonVO<String> downloadFile(String info) throws Exception;

    /**
     * 删除文件
     * @param info 文件存储的信息
     * @return 响应结果
     */
    JsonVO<String> deleteFile(String info) throws Exception;


}
