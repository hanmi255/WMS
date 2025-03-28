package com.zeroone.star.othermana.service.impl;

import com.alibaba.excel.EasyExcel;
import com.alibaba.excel.read.listener.PageReadListener;
import com.baomidou.mybatisplus.core.toolkit.CollectionUtils;
import com.baomidou.mybatisplus.core.toolkit.IdWorker;
import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.zeroone.star.othermana.mapper.BaPortMapper;
import com.zeroone.star.othermana.service.IBaPortService;
import com.zeroone.star.othermana.entity.BaPort;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j8.other.port.PortAddDTO;
import com.zeroone.star.project.dto.j8.other.port.PortBaseDTO;
import com.zeroone.star.project.dto.j8.other.port.PortModifyDTO;
import com.zeroone.star.project.query.j8.other.port.PortQuery;
import com.zeroone.star.project.vo.JsonVO;
import org.mapstruct.Mapper;
import org.mapstruct.Mapping;
import org.springframework.stereotype.Service;
import org.springframework.web.multipart.MultipartFile;

import javax.annotation.Resource;
import java.io.IOException;
import java.time.LocalDateTime;
import java.util.List;

/**
 * <p>
 * 描述：mapstruct映射接口
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 * @author yjq
 * @version 1.0.0
 */
@Mapper(componentModel = "spring")
interface MsPortMapper {
    @Mapping(source = "id", target = "id")
    PortBaseDTO BaPortToPortBaseDTO(BaPort port);
    @Mapping(source = "id", target = "id")
    BaPort PortAddDTOToBaPort(PortAddDTO dto);
    @Mapping(source = "id", target = "id")
    BaPort PortModifyDTOToBaPort(PortModifyDTO dto);
}
/**
 * <p>
 *  服务实现类
 * </p>
 *
 * @author yjq
 * @since 2025-02-26
 */
@Service
public class BaPortServiceImpl extends ServiceImpl<BaPortMapper, BaPort> implements IBaPortService {
    @Resource
    MsPortMapper msPortMapper;
    @Resource
    BaPortMapper baPortMapper;
    @Override
    public PageDTO<PortBaseDTO> listPort(PortQuery query) {
        // 构建分页对象
        Page<BaPort> page = new Page<>(query.getPageIndex(), query.getPageSize());
        // 查询数据
        Page<BaPort> ps = baseMapper.selectPageByQuery(page, query);
        // 转换结果
        return PageDTO.create(ps, msPortMapper::BaPortToPortBaseDTO);
    }

    @Override
    public JsonVO<String> addPort(PortAddDTO dto) {
        // 将DTO转换为实体类
        BaPort port = msPortMapper.PortAddDTOToBaPort(dto);
        // 使用MyBatis-Plus提供的IdWorker生成雪花ID
        Long generatedId = IdWorker.getId();
        // 设置生成的ID到实体类
        port.setId(generatedId.toString());
        // 执行插入操作
        Integer num =baseMapper.insert(port);
        if (num > 0) {
            return JsonVO.success("添加成功");
        }
        return JsonVO.fail("添加失败");
    }

    @Override
    public JsonVO<String> removePort(String id) {
        int result =baseMapper.deleteById(id);
        if (result > 0) {
            return JsonVO.success("删除成功");
        }
        return JsonVO.fail("删除失败");
    }

    @Override
    public JsonVO<String> updatePort(PortModifyDTO dto) {
        // 验证港口是否存在
        BaPort port = baseMapper.selectById(dto.getId());
        if (port == null) {
            return JsonVO.fail("修改失败,没有此港口！");
        }
        port =msPortMapper.PortModifyDTOToBaPort(dto);
        port.setUpdateDate(String.valueOf(LocalDateTime.now()));
        // 保存更新
        int result = baseMapper.updateById(port);
        if (result > 0) {
            return JsonVO.success("修改成功");
        } else {
            return JsonVO.fail("修改失败");
        }
    }

    @Override
    public List<BaPort> exportPort() {
        return baPortMapper.selectList(null);
    }

    @Override
    public JsonVO<String> importPort(MultipartFile file) {
        try {
            EasyExcel.read(file.getInputStream(), BaPort.class, new PageReadListener<BaPort>(dataList -> {
                if (!CollectionUtils.isEmpty(dataList)) {
                    // 调用当前实例的 saveBatch 方法进行批量插入
                    boolean result = this.saveBatch(dataList);
                    if (!result) {
                        throw new RuntimeException("批量插入失败");
                    }
                }
            })).sheet().doRead();
            return JsonVO.success("成功导入");
        } catch (IOException e) {
            return JsonVO.fail("Excel导入失败: " + e.getMessage());
        }
    }
}
