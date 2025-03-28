package com.zeroone.star.sysmgr.service.impl;

import com.alibaba.excel.EasyExcel;
import com.alibaba.excel.ExcelWriter;
import com.alibaba.excel.write.handler.AbstractSheetWriteHandler;
import com.alibaba.excel.write.metadata.WriteSheet;
import com.alibaba.excel.write.metadata.holder.WriteSheetHolder;
import com.alibaba.excel.write.metadata.holder.WriteTableHolder;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.project.dto.j2.sysmgr.DepartBaseDTO;
import com.zeroone.star.project.query.j2.sysmgr.OrgExportQuery;
import com.zeroone.star.sysmgr.entity.DepartADM;
import com.zeroone.star.sysmgr.mapper.DepartADMMapper;
import com.zeroone.star.sysmgr.service.DepartADMService;
import org.apache.poi.ss.usermodel.Sheet;
import org.apache.poi.ss.util.CellRangeAddress;
import com.zeroone.star.project.components.easyexcel.EasyExcelComponent;
import com.zeroone.star.project.components.fastdfs.FastDfsClientComponent;
import com.zeroone.star.project.components.fastdfs.FastDfsFileInfo;
import com.zeroone.star.project.dto.j2.sysmgr.DepartTreeBaseDTO;
import com.zeroone.star.project.dto.j2.sysmgr.DepartTreeListDTO;
import com.zeroone.star.project.query.j2.sysmgr.DepartTreeQuery;
import com.zeroone.star.project.utils.tree.TreeUtils;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.sysmgr.entity.Depart;
import com.zeroone.star.sysmgr.mapper.DepartMapper;
import com.zeroone.star.sysmgr.mapper.DepartTreeNodeMapper;
import com.zeroone.star.sysmgr.service.DepartService;
import org.mapstruct.Mapper;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.beans.factory.annotation.Value;
import org.springframework.stereotype.Service;
import org.springframework.transaction.annotation.Transactional;
import org.springframework.web.multipart.MultipartFile;
import com.zeroone.star.project.components.easyexcel.ExcelReadListener;
import java.io.File;
import java.util.*;
import java.util.function.Function;
import java.util.regex.Matcher;
import java.util.regex.Pattern;
import java.util.stream.Collectors;

import javax.annotation.Resource;
import java.io.ByteArrayOutputStream;
import java.io.IOException;
import java.util.Arrays;
import java.util.ArrayList;
import java.util.List;



@Mapper(componentModel = "spring")
interface DdDepartMapper {
    /**
     * detail to detailDTO
     *
     * @param departADM 源对象
     * @return 转换后的对象
     * @author 刘骏
     */
    DepartBaseDTO detailToDetailDTO(DepartADM departADM);
}

@Service

public class DepartServiceImpl extends ServiceImpl<DepartADMMapper, DepartADM> implements DepartService, DepartADMService {
    @Autowired
    private DepartMapper departMapper;

    @Resource
    private EasyExcelComponent excel;

    @Resource
    private FastDfsClientComponent dfs;

    @Value("${fastdfs.nginx-servers}")
    private String fileServerUrl;

    /**
     * 查询部门树
     * @return 部门树
     */
    @Override
    public JsonVO<List<DepartTreeBaseDTO>> queryTree() {
        // 查询所有部门数据
        List<DepartTreeListDTO> departList = departMapper.selectAllDeparts();
        // 转换为树形结构
        List<DepartTreeBaseDTO> tree = TreeUtils.listToTree(departList, new DepartTreeNodeMapper());
        // 返回成功结果
        return JsonVO.success(tree);
    }

    /**
     * 查询部门列表
     * @param query 查询参数
     * @return 部门列表
     */
    @Override
    public JsonVO<List<DepartTreeListDTO>> queryList(DepartTreeQuery query) {
        List<DepartTreeListDTO> departList;
        if (query.getParentDepartId() == null || query.getParentDepartId().isEmpty()) {
            // parentDepartId 为空，查询根级节点，包含是否有子节点
            departList = departMapper.selectRootDepartmentsWithChildren();
        } else {
            // parentDepartId 不为空，查询指定父部门下的子节点，包含是否有子节点
            departList = departMapper.selectChildDepartmentsWithChildren(query.getParentDepartId());
        }
        return JsonVO.success(departList);
    }

    /**
     * 获取所有部门数据
     *
     * @return 所有部门数据
     */
    @Override
    public List<Depart> ListDepartExcel() {
        return departMapper.selectListDeparts();
    }

    /**
     * 导出选中的部门数据
     *
     * @param query 导出参数
     * @return url地址
     */
    @Override
    public JsonVO<String> exportSelected(OrgExportQuery query) {
        List<Depart> departSelectedList = departMapper.selectByIds(query.getDepartIds());
        return exportTemplate(query.getOperatorName(), departSelectedList);
    }

    /**
     * 导出模板或数据,用 easyexcel 和 fastDFS 实现
     *
     * @param operatorName 操作人名称
     * @param dataList     要导出的数据列表，如果为空则只导出模板
     * @return 文件下载地址
     */
    public JsonVO<String> exportTemplate(String operatorName, List<Depart> dataList) {
        try {
            // 创建 Excel 工作簿
            ByteArrayOutputStream out = new ByteArrayOutputStream();
            // 创建自定义的合并单元格处理器
            MergeHandler mergeHandler = new MergeHandler();
            ExcelWriter excelWriter = EasyExcel.write(out).registerWriteHandler(mergeHandler).build();

            // 创建要写入的 sheet
            WriteSheet sheet1 = EasyExcel.writerSheet("DepartExcel").build();

            // 设置合并的单元格范围
            List<CellRangeAddress> mergedRegions = new ArrayList<>();
            mergedRegions.add(new CellRangeAddress(0, 0, 0, 6));  // 第一行合并7列
            mergedRegions.add(new CellRangeAddress(1, 1, 0, 6));  // 第二行合并7列
            // 将合并区域信息传递给处理器
            mergeHandler.setMergedRegions(mergedRegions);

            // 设置表头
            List<List<String>> head = Arrays.asList(Arrays.asList("组织机构表列表"),  // 第一行内容
                    Arrays.asList("导出人: " + operatorName)  // 第二行内容
                                                   );

            // 设置列标题
            List<List<String>> columnHead = Arrays.asList(Arrays.asList("部门名称", "部门描述", "机构编码", "机构类型编码", "电话", "传真",
                    "地址"));

            // 写入头部和列标题
            excelWriter.write(head, sheet1);  // 写入头部信息
            excelWriter.write(columnHead, sheet1);  // 写入列标题

            // 写入数据
            if (dataList != null && !dataList.isEmpty()) {
                List<List<String>> dataRows = new ArrayList<>();
                for (Depart depart : dataList) {
                    dataRows.add(Arrays.asList(depart.getDepartName(), depart.getDescription(), depart.getOrgCode(),
                            depart.getOrgType(), depart.getMobile(), depart.getFax(), depart.getAddress()));
                }
                excelWriter.write(dataRows, sheet1);
            }

            // 完成写入并上传
            excelWriter.finish();

            // 获取文件字节并上传到 FastDFS
            byte[] fileBytes = out.toByteArray();
            String suffix = "xlsx";
            FastDfsFileInfo fastDfsFileInfo = dfs.uploadFile(fileBytes, suffix);
            if (fastDfsFileInfo != null) {
                String fileUrl = dfs.fetchUrl(fastDfsFileInfo, fileServerUrl, true);
                return JsonVO.success(fileUrl);
            }
            return JsonVO.fail("文件上传失败");
        } catch (Exception e) {
            e.printStackTrace();
            return JsonVO.fail("导出报表失败：" + e.getMessage());
        }
    }

    /**
     * 导出全部数据
     *
     * @param operatorName 操作人名称
     * @return 文件下载地址
     */
    @Override
    public JsonVO<String> exportAll(String operatorName) {
        List<Depart> allData = ListDepartExcel();
        return exportTemplate(operatorName, allData);
    }

    // 自定义合并单元格处理器
    static class MergeHandler extends AbstractSheetWriteHandler {
        private List<CellRangeAddress> mergedRegions;

        public void setMergedRegions(List<CellRangeAddress> mergedRegions) {
            this.mergedRegions = mergedRegions;
        }

        public void afterSheetCreate(WriteSheetHolder writeSheetHolder, WriteTableHolder writeTableHolder) {
            Sheet sheet = writeSheetHolder.getSheet();
            if (mergedRegions != null) {
                for (CellRangeAddress region : mergedRegions) {
                    // 实际执行合并单元格操作
                    sheet.addMergedRegion(region);
                }
            }
        }
    }

    /**
     * 添加/更新父部门ID
     * <p>
     * 从数据库查询所有部门数据，根据 org_code 计算父部门 ID，更新记录。
     * </p>
     */
    private void handleParentDepartId() {
        // 从数据库中获取所有部门数据
        List<DepartTreeListDTO> departDTOList = departMapper.getDeparDTOList();
        if (departDTOList == null || departDTOList.isEmpty()) {
            return;
        }

        // 构建 org_code 到部门 DTO 的映射
        Map<String, DepartTreeListDTO> dtoMap = departDTOList.stream()
                .collect(Collectors.toMap(DepartTreeListDTO::getOrgCode, Function.identity()));

        // 正则表达式匹配父部门 org_code
        Pattern pattern = Pattern.compile("^(.*?)([A-Z]\\d+)$");

        // 更新每条记录的父部门 ID
        departDTOList.forEach(dto -> {
            String orgCode = dto.getOrgCode();
            if (orgCode != null && !orgCode.trim().isEmpty()) {
                Matcher matcher = pattern.matcher(orgCode);
                if (matcher.matches()) {
                    String parentOrgCode = matcher.group(1);
                    DepartTreeListDTO parentDto = dtoMap.get(parentOrgCode);
                    if (parentDto != null) {
                        dto.setParentDepartId(parentDto.getId());
                    }
                }
            }
        });

        // 更新数据库
        departDTOList.stream()
                .filter(dto -> dto.getParentDepartId() != null && !dto.getParentDepartId().trim().isEmpty())
                .forEach(departMapper::update);
    }

    /**
     * 导入组织结构
     * @param file Excel文件
     * @return 操作结果
     */
    @Override
    public JsonVO<String> importOrganization(MultipartFile file) {
        File tempFile = null;
        try {
            // 将上传文件保存到临时文件中
            tempFile = File.createTempFile("org_import", ".xlsx");
            file.transferTo(tempFile);

            // 读取 Excel 文件内容
            ExcelReadListener<Depart> listener = new ExcelReadListener<>();
            EasyExcel.read(tempFile, Depart.class, listener).sheet().doRead();
            List<Depart> departList = listener.getDataList();

            if (departList == null || departList.size() < 3) {
                return JsonVO.fail("文件数据不足");
            }

            // 跳过前3行，转换为 DTO 列表
            List<DepartTreeListDTO> dtoList = departList.subList(3, departList.size()).stream().map(d -> {
                DepartTreeListDTO dto = new DepartTreeListDTO();
                dto.setParentDepartId(d.getParentDepartId());
                dto.setDepartName(d.getDepartName());
                dto.setDescription(d.getDescription());
                dto.setOrgCode(d.getOrgCode());
                dto.setOrgType(parseInteger(d.getOrgType()));
                dto.setMobile(d.getMobile());
                dto.setFax(d.getFax());
                dto.setAddress(d.getAddress());
                dto.setId(UUID.randomUUID().toString().replaceAll("-", ""));
                return dto;
            }).collect(Collectors.toList());

            // 构建 org_code 到 DTO 的映射
            Map<String, DepartTreeListDTO> dtoMap = dtoList.stream()
                    .collect(Collectors.toMap(DepartTreeListDTO::getOrgCode, Function.identity()));

            // 补充父部门 ID 信息
            dtoList.forEach(dto -> {
                if (dto.getParentDepartId() == null || dto.getParentDepartId().trim().isEmpty()) {
                    String orgCode = dto.getOrgCode();
                    if (orgCode != null && !orgCode.isEmpty() && orgCode.charAt(0) != 'A') {
                        String parentOrgCode = (char) (orgCode.charAt(0) - 1) + orgCode.substring(1);
                        DepartTreeListDTO parentDto = dtoMap.get(parentOrgCode);
                        if (parentDto != null) {
                            dto.setParentDepartId(parentDto.getId());
                            parentDto.setDescription((parentDto.getDescription() == null ? "" : parentDto.getDescription())
                                    + " " + (dto.getDescription() == null ? "" : dto.getDescription()));
                        }
                    }
                }
            });

            // 检查数据库中已存在记录
            List<String> orgCodes = dtoList.stream().map(DepartTreeListDTO::getOrgCode).collect(Collectors.toList());
            Map<String, Depart> existingMap = Optional.ofNullable(departMapper.selectByOrgCodes(orgCodes))
                    .orElseGet(ArrayList::new).stream()
                    .collect(Collectors.toMap(Depart::getOrgCode, d -> d));

            // 分离新记录和需更新记录
            List<DepartTreeListDTO> newList = dtoList.stream()
                    .filter(dto -> !existingMap.containsKey(dto.getOrgCode()))
                    .collect(Collectors.toList());
            List<DepartTreeListDTO> updateList = dtoList.stream()
                    .filter(dto -> existingMap.containsKey(dto.getOrgCode()))
                    .collect(Collectors.toList());

            // 批量插入新记录
            if (!newList.isEmpty()) {
                departMapper.savedepartList(newList);
            }

            // 更新已有记录
            updateList.forEach(departMapper::update);

            handleParentDepartId();
            return JsonVO.success("导入成功");
        } catch (IOException e) {
            return JsonVO.fail("文件处理异常：" + e.getMessage());
        } catch (Exception e) {
            return JsonVO.fail("导入异常：" + e.getMessage());
        } finally {
            if (tempFile != null && tempFile.exists()) {
                tempFile.delete();
            }
        }
    }

    private Integer parseInteger(String value) {
        try {
            return value != null ? Integer.valueOf(value) : null;
        } catch (NumberFormatException e) {
            return null;
        }
    }


    /**
     *
     * @param departAdd 组织机构信息
     * @return
     */

    @Override
    @Transactional
    public boolean addDepart(DepartBaseDTO departAdd) {
        DepartADM da = new DepartADM();
        da.setDepartName(departAdd.getDepartName());
        da.setDescription(departAdd.getDescription());
        da.setOrgCode(departAdd.getOrgCode());
        da.setOrgType(departAdd.getOrgType());
        da.setMobile(departAdd.getMobile());
        da.setFax(departAdd.getFax());
        da.setAddress(departAdd.getAddress());
        da.setParentId(departAdd.getParentId());
        return save(da);
    }

    @Override
    @Transactional
    public boolean deleteDepart(String id) {
        return removeById(id);

    }

    @Resource
    private DdDepartMapper ddMapper;

    @Override
    @Transactional
    public DepartBaseDTO getDepartDetailById(String departId) {
        DepartADM departDetail = baseMapper.selectById(departId);
        return ddMapper.detailToDetailDTO(departDetail);
    }

    @Override
    public boolean updateDepart(DepartBaseDTO dto) {
        DepartADM dm = new DepartADM();
        dm.setId(dto.getId());
        dm.setDepartName(dto.getDepartName());
        dm.setDescription(dto.getDescription());
        dm.setOrgCode(dto.getOrgCode());
        dm.setOrgType(dto.getOrgType());
        dm.setMobile(dto.getMobile());
        dm.setFax(dto.getFax());
        dm.setAddress(dto.getAddress());
        dm.setDepartOrder(dto.getDepartOrder());
        dm.setParentId(dto.getParentId());
        return updateById(dm);
    }

}