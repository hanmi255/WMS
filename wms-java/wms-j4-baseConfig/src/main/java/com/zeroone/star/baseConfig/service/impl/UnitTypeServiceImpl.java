package com.zeroone.star.baseConfig.service.impl;

import cn.hutool.core.bean.BeanUtil;
import com.alibaba.cloud.commons.lang.StringUtils;
import com.alibaba.excel.EasyExcel;
import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.baseConfig.entity.UnitType;
import com.zeroone.star.baseConfig.mapper.UnitTypeMapper;
import com.zeroone.star.baseConfig.service.UnitTypeService;
import com.zeroone.star.project.components.easyexcel.ExcelReadListener;
import com.zeroone.star.project.dto.j4.unitType.UnitTypeAddDTO;
import com.zeroone.star.project.dto.j4.unitType.UnitTypeFileDTO;
import com.zeroone.star.project.dto.j4.unitType.UnitTypeModifyDTO;
import com.zeroone.star.project.query.j4.unitType.UnitTypeQuery;
import com.zeroone.star.project.vo.JsonVO;
import lombok.RequiredArgsConstructor;
import lombok.extern.slf4j.Slf4j;
import org.springframework.beans.BeanUtils;
import org.springframework.stereotype.Service;
import org.springframework.transaction.annotation.Transactional;
import org.springframework.web.multipart.MultipartFile;

import javax.annotation.Resource;
import java.time.LocalDateTime;
import java.util.List;

/**
 * <p>
 * 计量单位类型 服务实现类
 * </p>
 *
 * @author Dorain
 * @since 2025-02-22
 */
@Service
@RequiredArgsConstructor
@Slf4j
public class UnitTypeServiceImpl extends ServiceImpl<UnitTypeMapper, UnitType> implements UnitTypeService {

    @Resource
    private final UnitTypeMapper unitTypeMapper;

//    @Resource
//    private UserHolder userHolder;


    @Override
    @Transactional(rollbackFor = Exception.class)

    public JsonVO<String> addUnitType(UnitTypeAddDTO dto) {
        try {

            UnitType entity = new UnitType();
            BeanUtil.copyProperties(dto, entity);
//            UserDTO user = userHolder.getCurrentUser(); fixme 暂时注释这块，因为没有登录获取不到user
//            log.info("当前用户信息：{}", user);
//            entity.setCreateName(user.getRealName());// realname 对应 create_name
//            entity.setUpdateName(user.getRealName());
//            entity.setCreateBy(user.getUsername()); // username 对应 create_by
//            entity.setUpdateBy(user.getUsername());
//            entity.setSysOrgCode(user.getOrgCode());
//            entity.setSysCompanyCode(user.getCompanyCode());
            LocalDateTime now = LocalDateTime.now();
            entity.setCreateDate(now);
            entity.setUpdateDate(now);

            boolean isSaved = save(entity);
            return isSaved ? JsonVO.success("操作成功") : JsonVO.fail("操作失败");

        } catch (Exception e) {
            log.error(e.getMessage());
            return JsonVO.fail("操作失败");
        }


    }

    @Override
    @Transactional(rollbackFor = Exception.class)
    public JsonVO<String> updateUnitType(UnitTypeModifyDTO dto) {
        try {
            UnitType entity = getById(dto.getId());
            if (entity == null) {
                return JsonVO.fail("获取对象信息失败");
            }
//            UserDTO user = userHolder.getCurrentUser(); fixme 无登录无法获取user
//            log.info("当前用户信息：{}", user);
//            BeanUtil.copyProperties(dto, entity);
//            entity.setUpdateName(user.getRealName());
//            entity.setUpdateBy(user.getUsername());
            LocalDateTime now = LocalDateTime.now();
            entity.setUpdateDate(now);
            boolean isUpdated = updateById(entity);
            return isUpdated ? JsonVO.success("操作成功") : JsonVO.fail("操作失败");
        } catch (Exception e) {
            log.error(e.getMessage());
            return JsonVO.fail("操作失败");
        }
    }


    @Override
    @Transactional(rollbackFor = Exception.class)
    public JsonVO<String> deleteBatchUnitType(List<String> ids) {
        return removeByIds(ids) ?
                JsonVO.success("批量删除成功") :
                JsonVO.fail("批量删除失败");
    }

    @Override
    public List<UnitType> queryUnitTypes(UnitTypeQuery query) {

        QueryWrapper<UnitType> wrapper = new QueryWrapper<>();

        // 单位类型代码模糊查询
        if (StringUtils.isNotBlank(query.getUnitTypeCode())) {
            wrapper.like("unit_type_code", query.getUnitTypeCode().trim());
        }

        // 单位类型名称模糊查询
        if (StringUtils.isNotBlank(query.getUnitTypeName())) {
            wrapper.like("unit_type_name", query.getUnitTypeName().trim());
        }

        // 可添加排序条件（按需）
        wrapper.orderByAsc("update_date");

        return unitTypeMapper.selectList(wrapper);


    }


   /* private UnitTypeVO convertToVO(UnitType entity) {
        UnitTypeVO vo = new UnitTypeVO();
        BeanUtil.copyProperties(entity, vo);
        return vo;
    }*/

    @Override
    public void importParameterType(MultipartFile file) {
        // 使用EasyExcel读取上传的Excel文件并处理
        try {
            ExcelReadListener<UnitTypeFileDTO> listener = new ExcelReadListener<>();
            EasyExcel.read(file.getInputStream(), UnitTypeFileDTO.class, listener).sheet().doRead();
            // 将读取到的数据插入到数据库
            //获取当前登录用户
//            UserDTO currentUser = userHolder.getCurrentUser();fixme 后续解开获取用户信息注释
            listener.getDataList().forEach(data -> {
                UnitType unitType = new UnitType();
                BeanUtils.copyProperties(data, unitType);
//                unitType.setCreateBy(currentUser.getUsername());fixme 有点问题，解析数据是错的
//                unitType.setUpdateBy(currentUser.getUsername());
                unitTypeMapper.insert(unitType);
            });
        } catch (Exception e) {
            throw new RuntimeException(e);
        }
    }
}
