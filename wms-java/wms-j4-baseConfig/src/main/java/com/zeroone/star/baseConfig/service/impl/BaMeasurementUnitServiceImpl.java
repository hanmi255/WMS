package com.zeroone.star.baseConfig.service.impl;

import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.baseConfig.entity.BaMeasurementUnit;
import com.zeroone.star.baseConfig.mapper.BaMeasurementUnitMapper;
import com.zeroone.star.baseConfig.service.BaMeasurementUnitService;
import com.zeroone.star.project.components.user.UserDTO;
import com.zeroone.star.project.components.user.UserHolder;
import com.zeroone.star.project.dto.j4.measurementUnit.MeasurementUnitDTO;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.j4.measurementUnit.MeasurementUnitVO;
import lombok.SneakyThrows;
import org.springframework.beans.BeanUtils;
import org.springframework.stereotype.Service;
import org.springframework.transaction.annotation.Transactional;

import javax.annotation.Resource;
import java.util.ArrayList;
import java.util.Date;
import java.util.List;

/**
 * @author 1+5
 * @title MeasurementUnitServiceImpl
 * @date 2025/2/23 14 44
 * @description 计量单位服务层实现
 */

@Service
@Transactional
public class BaMeasurementUnitServiceImpl extends ServiceImpl<BaMeasurementUnitMapper, BaMeasurementUnit> implements BaMeasurementUnitService {

    /**
     * 从请求头中获取用户信息
     */
    @Resource
    UserHolder userHolder;

    @Resource
    BaMeasurementUnitMapper mapper;

    @SneakyThrows
    @Override
    public JsonVO<MeasurementUnitVO> insertUnit(MeasurementUnitDTO measurementUnitDTO) {

        System.out.println(measurementUnitDTO);

        //插入之前创建时间不能存在 还有 id不能存在
        if(measurementUnitDTO.getCreateDate()!=null ||measurementUnitDTO.getId()!=null){
            JsonVO<MeasurementUnitVO> fail = JsonVO.fail(new MeasurementUnitVO());
            fail.setMessage("插入之前创建时间存在或者id不能存在");
            return fail;
        }

        //为新增用户设置为添加的信息
        UserDTO currentUser = userHolder.getCurrentUser();
        measurementUnitDTO.setCreateName(currentUser.getId().toString());
        measurementUnitDTO.setCreateBy(currentUser.getUsername());
        measurementUnitDTO.setSysCompanyCode(currentUser.getCompanyCode());
        measurementUnitDTO.setSysOrgCode(currentUser.getOrgCode());

        measurementUnitDTO.setCreateDate(new Date());

        //写入属性
        BaMeasurementUnit measurementUnit = new BaMeasurementUnit();
        BeanUtils.copyProperties(measurementUnitDTO, measurementUnit);

        System.out.println(measurementUnit);



        //插入
        int insert = mapper.insert(measurementUnit);

        //返回值
        MeasurementUnitVO measurementUnitVO = new MeasurementUnitVO();
        BeanUtils.copyProperties(measurementUnit, measurementUnitVO);


        System.out.println(measurementUnitVO);


        if (insert > 0) {
            return JsonVO.success(measurementUnitVO);
        } else {
            JsonVO<MeasurementUnitVO> fail = JsonVO.fail(measurementUnitVO);
            fail.setMessage("插入失败");
            return fail;
        }

    }

    @SneakyThrows
    @Override
    public JsonVO<MeasurementUnitVO> updateUnit(MeasurementUnitDTO measurementUnitDTO) {

        //在更新之前， id 不能为空
        if( measurementUnitDTO.getId()==null || measurementUnitDTO.getId().equals("")){
            JsonVO<MeasurementUnitVO> fail = JsonVO.fail(new MeasurementUnitVO());
            fail.setMessage("更新之前，id不能为空");
            return fail;
        }


        //创建数据库操作的实体类
        BaMeasurementUnit baMeasurementUnit = new BaMeasurementUnit();

        //给实体类赋值
		UserDTO currentUser = userHolder.getCurrentUser();
        BeanUtils.copyProperties(measurementUnitDTO,baMeasurementUnit);
        baMeasurementUnit.setUpdateDate(new Date());
        baMeasurementUnit.setUpdateName(currentUser.getId().toString());
        baMeasurementUnit.setUpdateBy(currentUser.getUsername());
        baMeasurementUnit.setSysCompanyCode(currentUser.getCompanyCode());
        baMeasurementUnit.setSysOrgCode(currentUser.getOrgCode());

        //执行更新
        int update = mapper.updateById(baMeasurementUnit);



        //创建返回值
        MeasurementUnitVO measurementUnitVO = new MeasurementUnitVO();

        //返回判断

        if (update > 0){

            BeanUtils.copyProperties(baMeasurementUnit,measurementUnitVO);
            return JsonVO.success(measurementUnitVO);
        }else {
            return JsonVO.fail(measurementUnitVO);
        }

    }

    @Override
    public JsonVO<String> deleteUnit(List<MeasurementUnitDTO> measurementUnitListDTO) {

        //判断是否为空
        if (measurementUnitListDTO.isEmpty()){
            return JsonVO.fail("删除失败,因为要删除的数据为空");
        }

        List<BaMeasurementUnit> baMeasurementUnits = new ArrayList<>();


        //为要删除的实体类进行值拷贝
        for (MeasurementUnitDTO measurementUnitDTO : measurementUnitListDTO) {
            BaMeasurementUnit baMeasurementUnit = new BaMeasurementUnit();
            BeanUtils.copyProperties(measurementUnitDTO,baMeasurementUnit);
            if (measurementUnitDTO.getId()==null || measurementUnitDTO.getId().equals("")){
                return JsonVO.fail("删除失败,因为要删除的某个数据的Id为空");
            }
            baMeasurementUnits.add(baMeasurementUnit);
        }


        //进行删除


        int i = mapper.deleteBatchIds(baMeasurementUnits);


        if (i>0){
            return   JsonVO.success("删除成功");
        }else {
            return   JsonVO.fail("删除失败");
        }

    }
}
