package com.zeroone.star.project.j2.sysmgr;

import com.zeroone.star.project.dto.j2.sysmgr.DepartBaseDTO;
import com.zeroone.star.project.dto.j2.sysmgr.DepartTreeBaseDTO;
import com.zeroone.star.project.dto.j2.sysmgr.DepartTreeListDTO;

import com.zeroone.star.project.query.j2.sysmgr.DepartTreeQuery;
import com.zeroone.star.project.query.j2.sysmgr.OrgExportQuery;
import com.zeroone.star.project.vo.JsonVO;
import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.bind.annotation.RequestParam;
import org.springframework.web.multipart.MultipartFile;

import java.util.List;

/**
 * <p>
 * 描述：组织基础数据相关接口
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 * @author TWTW
 * @version 1.0.0
 */
public interface DepartApis {


    /**
     * 获取组织树形结构
     * @return 树形结构数据（包含完整层级）
     */
    public JsonVO<List<DepartTreeBaseDTO>> queryTree();

    /**
     * 获取层级组织列表
     * @param query 包含父部门ID的查询参数
     * @return 当前层级的扁平化列表
     */
    JsonVO<List<DepartTreeListDTO>> queryList(@RequestBody DepartTreeQuery query);

    /**
     * 导出选中组织数据
     * @param  query 包含部门ID列表的查询参数
     * @return 包含下载URL的响应
     */
    JsonVO<String> exportSelected(@RequestBody OrgExportQuery query) throws Exception;

    /**
     * 导出全部组织数据
     * UserHolder 中获取操作人的信息（通过请求头传递）
     * @return 包含下载URL的响应
     */
    JsonVO<String> exportAll() throws Exception;

    /**
     * 导入组织数据
     * @param file 上传的Excel文件
     * @return 导入结果
     */
    JsonVO<String > importOrgData(@RequestParam("file") MultipartFile file);

    /**
     * 新增组织机构信息
     *
     * @param dto 新增组织机构的信息数据传输对象
     * @return 操作结果字符串
     * @author 刘骏
     */
    JsonVO<String> addOrg(DepartBaseDTO dto);

    /**
     * 删除组织机构信息
     *
     * @param id 组织结果
     * @return 操作结果字符串
     * @author 刘骏
     */
    JsonVO<String> removeOrg(String id);

    /**
     * 修改组织机构信息
     *
     * @param dto 修改组织机构的信息数据传输对象
     * @return 操作结果字符串
     * @author 刘骏
     */
    JsonVO<String> modifyOrg(DepartBaseDTO dto);

    /**
     * 查询选中组织机构信息
     *
     * @param id 修改组织机构信息的id
     * @return 操作结果字符串
     * @author 刘骏
     */
    JsonVO<DepartBaseDTO> queryOrgById(String id);


    /**
     * 修改组织机构是否存在人员
     *
     * @param departOrder 人员存在情况
     * @return JsonVO<String>
     * @author 刘骏
     */

    JsonVO<String> modifyDepartOrder(String departOrder);
}
