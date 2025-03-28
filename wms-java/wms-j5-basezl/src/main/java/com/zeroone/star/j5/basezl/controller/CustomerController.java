package com.zeroone.star.j5.basezl.controller;
import com.zeroone.star.j5.basezl.service.CustomerService;
import com.zeroone.star.j5.basezl.utils.FileUtil;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j5.basezl.customer.CustomerAddDTO;
import com.zeroone.star.project.dto.j5.basezl.customer.CustomerDetailDTO;
import com.zeroone.star.project.dto.j5.basezl.customer.CustomerListDTO;
import com.zeroone.star.project.dto.j5.basezl.customer.CustomerModifyDTO;
import com.zeroone.star.project.j5.basezl.CustomerApis;
import com.zeroone.star.project.query.j5.basezl.customer.CustomerQuery;
import com.zeroone.star.project.vo.JsonVO;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import lombok.extern.slf4j.Slf4j;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.http.ResponseEntity;
import org.springframework.validation.annotation.Validated;
import org.springframework.web.bind.annotation.*;
import org.springframework.web.multipart.MultipartFile;

import javax.validation.constraints.NotNull;
import java.util.List;

/**
 * <p>
 * 客户信息 前端控制器
 * </p>
 *
 * @author xiaoxia
 * @since 2025-02-28
 */
@RestController
@RequestMapping("/customer")
@Api(tags = "客户管理接口实现")
@Validated
@Slf4j
public class CustomerController implements CustomerApis {
    @Autowired
    private CustomerService service;
    @Autowired
    private FileUtil fileUtil;
    @ApiOperation(value = "查询客户名称列表")
    @GetMapping("customer-name")
    @Override
    public JsonVO<List<String>> queryCustomerNames() {
        //三个属性，no string
        List<String> customerNames =service.selectCustomerNames();
        log.info("查询客户名称列表：{}",customerNames);
        return JsonVO.success(customerNames);
    }

    @ApiOperation(value = "查询所有客户信息")
    @GetMapping("query-all")
    @Override
    public JsonVO<PageDTO<CustomerListDTO>> queryAll(@ModelAttribute @Validated CustomerQuery query) {
        PageDTO<CustomerListDTO> pageDTO =service.selectAllCustomer(query);
        log.info("查询所有客户信息：{}",pageDTO);
        return JsonVO.success(pageDTO);
    }

    @ApiOperation("查询客户详细信息")
    @GetMapping("query-one")
    @Override
    public JsonVO<CustomerDetailDTO> getDetailsCustomer(@NotNull @RequestParam String customerId) {
        CustomerDetailDTO customerDetailDTO=service.getById(customerId);
        log.info("查询客户详细信息：{}",customerDetailDTO);
        if(customerDetailDTO==null)
            return JsonVO.fail(null);
        return JsonVO.success(customerDetailDTO);
    }

    @ApiOperation("添加客户信息")
    @PostMapping("add-customer")
    @Override
    public JsonVO<String> addCustomer(@RequestBody @Validated CustomerAddDTO dto) {
        int i = service.addCustomer(dto);
        log.info("添加客户信息：{}",dto);
        if(i==0)
            return JsonVO.fail("添加失败");
        return JsonVO.success("添加成功");
    }

    @ApiOperation("修改客户信息")
    @PutMapping("modify-customer")
    @Override
    public JsonVO<String> modifyCustomer(@RequestBody @Validated CustomerModifyDTO dto) {
        int i = service.updateCus(dto);
        log.info("修改客户信息：{}",dto);
        if(i>0) {
            return JsonVO.success(null);
        } else {
            return JsonVO.fail(null);
        }
    }

    @ApiOperation("删除客户信息")
    @DeleteMapping("remove-customer")
    @Override
    public JsonVO<String> deleteCustomer(@RequestParam List<String> ids) {
        int i = service.removeCus(ids);
        log.info("删除客户列表：{}",ids);
        if(i>0) {
            return JsonVO.success(null);
        } else {
            return JsonVO.fail(null);
        }

    }

    @ApiOperation("导出客户文件")
    @GetMapping("download")
    @Override
    public ResponseEntity<byte[]> exportCustomer(@RequestParam List<String> ids) {
        log.info("开始导出....");
        return service.exportCus(ids);
    }

    @ApiOperation("导入客户文件")
    @PostMapping("upload")
    @Override
    public JsonVO<String> importCustomer(@RequestParam MultipartFile[] files) {
        log.info("开始导入...");
        StringBuilder sb=new StringBuilder("已上传的文件:");
        for(MultipartFile file:files) {
            if(file.isEmpty()) {
                continue;
            }
            String name = file.getOriginalFilename();
            if(name.endsWith(".xls")||name.endsWith(".xlsx")) {
                if(service.importCus(file)==1)  {
                    sb.append(name+" ");
                }
            }
        }
        return JsonVO.success(sb.toString());

    }
    @ApiOperation("上传附件")
    @PostMapping("upload-file")
    @Override
    public JsonVO<String> uploadFile(MultipartFile file) throws Exception {
        return JsonVO.success(fileUtil.uploadFile(file));
    }

    @ApiOperation("下载附件")
    @PostMapping("download-file")
    @Override
    public JsonVO<String> downloadFile(String info) throws Exception {
        return JsonVO.success(fileUtil.downloadFile(info));
    }

    @ApiOperation("删除文件")
    @PostMapping("delete-file")
    @Override
    public JsonVO<String> deleteFile(String info) throws Exception {
        if(fileUtil.deleteFile(info)==0) {
            return JsonVO.success(null);
        }
        return JsonVO.fail(null);
    }


}
