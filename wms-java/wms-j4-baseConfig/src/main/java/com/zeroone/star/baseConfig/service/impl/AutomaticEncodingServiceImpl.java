package com.zeroone.star.baseConfig.service.impl;

import cn.hutool.core.date.DateTime;
import com.alibaba.excel.EasyExcel;
import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.baseConfig.entity.AutomaticEncoding;
import com.zeroone.star.baseConfig.mapper.AutomaticEncodingMapper;
import com.zeroone.star.baseConfig.mapper.ExcelAutomaticEncodingMapper;
import com.zeroone.star.baseConfig.service.AutomaticEncodingService;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j4.automaticEncoding.AutomaticEncodingDTO;
import com.zeroone.star.project.dto.j4.automaticEncoding.DeleteEncodingDTO;
import com.zeroone.star.project.query.j4.automaticEncoding.AutomaticEncodingQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.j4.automaticEncoding.DeleteEncodingVO;
import com.zeroone.star.project.vo.j4.automaticEncoding.ExportExcelVO;
import lombok.SneakyThrows;
import org.mapstruct.Mapper;
import org.springframework.http.HttpHeaders;
import org.springframework.http.HttpStatus;
import org.springframework.http.MediaType;
import org.springframework.http.ResponseEntity;
import org.springframework.stereotype.Service;
import org.springframework.web.bind.annotation.RequestBody;

import javax.annotation.Resource;
import java.io.ByteArrayOutputStream;
import java.io.OutputStream;
import java.util.*;
import java.util.stream.Collectors;

@Mapper(componentModel = "spring")
interface MsAutomaticEncodingMapper {
    /**
     * 将AutomaticEncoding对象转换为AutomaticEncodingDTO对象
     *
     * @param automaticEncoding
     * @return
     */
    AutomaticEncodingDTO AutomaticEncodingToAutomaticEncodingDTO(AutomaticEncoding automaticEncoding);

    /**
     * 将AutomaticEncodingDTO对象转换为AutomaticEncoding对象
     * @param dto
     * @return
     */
    AutomaticEncoding AutomaticEncodingDTOToAutomaticEncoding(AutomaticEncodingDTO dto);
}

/**
 * <p>
 * 服务实现类
 * </p>
 *
 * @author lzm
 * @since 2025-02-22
 */
@Service
public class AutomaticEncodingServiceImpl extends ServiceImpl<AutomaticEncodingMapper, AutomaticEncoding> implements AutomaticEncodingService {

    @Resource
    MsAutomaticEncodingMapper msMapper;

    @Override
    public PageDTO<AutomaticEncodingDTO> queryAll(AutomaticEncodingQuery condition) {
        // 构建分页对象
        Page<AutomaticEncoding> page = new Page<>(condition.getPageIndex(), condition.getPageSize());
        // 构建查询条件
        QueryWrapper<AutomaticEncoding> wrapper = new QueryWrapper<>();

        // 按编号类型查
        if (condition.getSnroTypeCode() != null) {
            wrapper.like("snro_type_code", condition.getSnroTypeCode());
        }
        // 按组织机构查
        if (condition.getSnroOrg()!= null) {
            wrapper.like("snro_org", condition.getSnroOrg());
        }
        // 查询结果
        Page<AutomaticEncoding> ps = baseMapper.selectPage(page, wrapper);
        return PageDTO.create(ps, msMapper::AutomaticEncodingToAutomaticEncodingDTO);
    }

    @Override
    public AutomaticEncodingDTO doSaveOrUpdate(AutomaticEncodingDTO dto) {
        AutomaticEncoding automaticEncoding = msMapper.AutomaticEncodingDTOToAutomaticEncoding(dto);
        try {
            this.saveOrUpdate(automaticEncoding);
        }catch (Exception e){
            throw new RuntimeException("操作失败");
        }

        return dto;
    }


    @Resource
    AutomaticEncodingMapper automaticEncodingMapper;

    @Override
    public void saveBatch(List<ExcelAutomaticEncodingMapper> importedData) {

    }
    @Override
    public JsonVO<List<DeleteEncodingVO>> deleteEncoding(@RequestBody DeleteEncodingDTO dto) {
        // 判断传入的 DTO 是否为空
        if (dto == null || dto.getIds() == null || dto.getIds().isEmpty()) {
            return JsonVO.fail( Collections.emptyList());
        }

        List<DeleteEncodingVO> resultList = new ArrayList<>(); // 用于存储删除结果
        List<String> successIds = new ArrayList<>(); // 成功删除的 ID 列表
        List<String> failIds = new ArrayList<>();    // 删除失败的 ID 列表

        // 遍历要删除的 ID 列表
        for (String id : dto.getIds()) {
            DeleteEncodingVO vo = new DeleteEncodingVO();
            vo.setId(id);

            // 检查 ID 是否为空
            if (id == null || id.trim().isEmpty()) {
                vo.setCreate_by("系统");
                vo.setCreate_date(new Date().toString());
                vo.setUpdate_by("系统");
                vo.setUpdate_date(new Date().toString());
                vo.setSnro_exp("N/A");
                vo.setSnro_type_code("N/A");
                vo.setSnro_org("N/A");
                vo.setSnro_findex("N/A");
                vo.setSnro_split("N/A");
                vo.setSnro_year(0);
                vo.setSnro_month(0);
                vo.setSnro_day(0);
                vo.setSnro_seri(0);
                vo.setSys_org_code("N/A");
                vo.setSys_company_code("N/A");
                vo.setCreate_name("系统");
                vo.setUpdate_name("系统");
                failIds.add(id);
                resultList.add(vo);
                continue;
            }

            // 查询要删除的记录
            AutomaticEncoding encoding = automaticEncodingMapper.selectById(id);
            if (encoding == null) {
                // 如果记录不存在，填充默认值
                vo.setCreate_by("系统");
                vo.setCreate_date(new Date().toString());
                vo.setUpdate_by("系统");
                vo.setUpdate_date(new Date().toString());
                vo.setSnro_exp("N/A");
                vo.setSnro_type_code("N/A");
                vo.setSnro_org("N/A");
                vo.setSnro_findex("N/A");
                vo.setSnro_split("N/A");
                vo.setSnro_year(0);
                vo.setSnro_month(0);
                vo.setSnro_day(0);
                vo.setSnro_seri(0);
                vo.setSys_org_code("N/A");
                vo.setSys_company_code("N/A");
                vo.setCreate_name("系统");
                vo.setUpdate_name("系统");
                failIds.add(id);
                resultList.add(vo);
                continue;
            }
            // 执行删除操作
            int result = automaticEncodingMapper.deleteById(id);
            if (result > 0) {
                successIds.add(id);
            } else {
                failIds.add(id);
            }
            resultList.add(vo);
        }

        // 根据删除结果返回响应
        if (failIds.isEmpty()) {
            return JsonVO.success(resultList);
        } else if (successIds.isEmpty()) {
            return JsonVO.fail( resultList);
        } else {
            return JsonVO.success(resultList);
        }
    }
    @Override
    @SneakyThrows
    public ResponseEntity<byte[]> exportExcel(
            String create_name,
            String endDate,
            String[] ids,
            String startDate,
            String exportDTO) {

        // 1. 构建查询条件
        QueryWrapper<AutomaticEncoding> queryWrapper = new QueryWrapper<>();
        if (create_name != null && !create_name.isEmpty()) {
            queryWrapper.eq("create_name", create_name);
        }
        if (startDate != null && !startDate.isEmpty() && endDate != null && !endDate.isEmpty()) {
            queryWrapper.between("create_date", startDate, endDate);
        }
        if (ids != null && ids.length > 0) {
            queryWrapper.in("id", Arrays.asList(ids));
        }

        // 2. 查询数据
        List<AutomaticEncoding> data = automaticEncodingMapper.selectList(queryWrapper);

        // 3. 转换为导出数据格式
        List<ExportExcelVO> exportData = data.stream()
                .map(this::convertToExportFormat)
                .collect(Collectors.toList());

        // 4. 生成 Excel 文件
        ByteArrayOutputStream out = new ByteArrayOutputStream();
        exportToExcel("AutomaticEncoding", out, ExportExcelVO.class, exportData);

        // 5. 设置响应头
        String filename = "AutomaticEncoding-" + DateTime.now().toString("yyyyMMddHHmmssS") + ".xlsx";
        HttpHeaders headers = new HttpHeaders();
        headers.setContentDispositionFormData("attachment", filename);
        headers.setContentType(MediaType.APPLICATION_OCTET_STREAM);

        // 6. 返回文件流
        return new ResponseEntity<>(out.toByteArray(), headers, HttpStatus.CREATED);
    }

    /**
     * 将数据库实体类转换为导出格式
     *
     * @param encoding 数据库实体类
     * @return 导出格式
     */
    /**
     * 将数据库实体类转换为导出格式
     *
     * @param encoding 数据库实体类
     * @return 导出格式
     */
    private ExportExcelVO convertToExportFormat(AutomaticEncoding encoding) {
        ExportExcelVO exportData = new ExportExcelVO();

        // 字段映射
        exportData.setId(encoding.getId());
        exportData.setCreate_name(encoding.getCreateName()); // 注意字段名称映射
        exportData.setCreate_by(encoding.getCreateBy());
        exportData.setCreate_date(encoding.getCreateDate() != null ? encoding.getCreateDate().toString() : null);
        exportData.setUpdate_name(encoding.getUpdateName());
        exportData.setUpdate_by(encoding.getUpdateBy());
        exportData.setUpdate_date(encoding.getUpdateDate() != null ? encoding.getUpdateDate().toString() : null);
        exportData.setSys_org_code(encoding.getSysOrgCode());
        exportData.setSys_company_code(encoding.getSysCompanyCode());
        exportData.setSnro_type_code(encoding.getSnroTypeCode());
        exportData.setSnro_org(encoding.getSnroOrg());
        exportData.setSnro_findex(encoding.getSnroFindex());
        exportData.setSnro_split(encoding.getSnroSplit());
        exportData.setSnro_year(encoding.getSnroYear() != null ? Integer.parseInt(encoding.getSnroYear()) : null);
        exportData.setSnro_month(encoding.getSnroMonth() != null ? Integer.parseInt(encoding.getSnroMonth()) : null);
        exportData.setSnro_day(encoding.getSnroDay() != null ? Integer.parseInt(encoding.getSnroDay()) : null);
        exportData.setSnro_seri(encoding.getSnroSeri() != null ? Integer.parseInt(encoding.getSnroSeri()) : null);
        exportData.setSnro_exp(encoding.getSnroExp());

        return exportData;
    }

    /**
     * 导出数据到 Excel
     *
     * @param sheetName 工作表名称
     * @param out       输出流
     * @param clazz     数据类
     * @param data      数据列表
     * @param <T>       泛型
     */
    private <T> void exportToExcel(String sheetName, OutputStream out, Class<T> clazz, List<T> data) {
        EasyExcel.write(out, clazz)
                .sheet(sheetName)
                .doWrite(data);
    }
}
