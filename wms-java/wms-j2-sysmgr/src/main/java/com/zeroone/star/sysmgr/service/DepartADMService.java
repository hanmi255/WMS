/**
 * @ClassName : Depart  //类名
 * @Description : 增删改接口  //描述
 * @Author : 全息主角 //作者
 * @Date: 2025/3/1  16:10
 */

package com.zeroone.star.sysmgr.service;

import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.project.dto.j2.sysmgr.DepartBaseDTO;
import com.zeroone.star.sysmgr.entity.DepartADM;

public interface DepartADMService extends IService<DepartADM> {
    /**
     * 添加组织机构
     *
     * @param departAdd 组织机构信息
     * @return 是否添加成功
     */
    boolean addDepart(DepartBaseDTO departAdd);
    /**
     * 删除组织机构
     *
     * @param id 组织机构id
     * @return 是否删除成功
     */
    boolean deleteDepart(String id);
    /**
     * 根据id获取对应组织机构的数据
     * @param  departId 组织结构id
     * @author 刘骏
     * @return DepartDetailDTO 组织机构DTO
     */

    DepartBaseDTO getDepartDetailById(String departId);
    /**
     * 修改组织机构信息
     *
     * @param dto 修改组织机构信息
     * @return DepartModifyDTO
     * @author 刘骏
     */
    boolean updateDepart(DepartBaseDTO dto);
}
