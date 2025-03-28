package com.zeroone.star.sysmgr.service;

import com.zeroone.star.project.dto.j2.sysmgr.DepartTreeBaseDTO;
import com.zeroone.star.project.dto.j2.sysmgr.DepartTreeListDTO;
import com.zeroone.star.project.query.j2.sysmgr.DepartTreeQuery;
import com.zeroone.star.project.query.j2.sysmgr.OrgExportQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.sysmgr.entity.Depart;
import org.springframework.web.multipart.MultipartFile;

import java.io.IOException;
import java.util.List;

public interface DepartService {
    JsonVO<List<DepartTreeBaseDTO>> queryTree();

    // 根据查询条件查询部门列表
    JsonVO<List<DepartTreeListDTO>> queryList(DepartTreeQuery query);


    public List<Depart> ListDepartExcel();
    public JsonVO<String> exportSelected( OrgExportQuery query);


    public JsonVO<String> exportAll(String operatorName);

    /**
     * 导入组织数据
     * @param file Excel文件
     * @return 成功或失败提示
     */
    JsonVO<String> importOrganization(MultipartFile file);

}
