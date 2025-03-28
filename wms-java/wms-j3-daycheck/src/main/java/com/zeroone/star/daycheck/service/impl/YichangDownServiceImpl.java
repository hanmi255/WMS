package com.zeroone.star.daycheck.service.impl;

import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.zeroone.star.daycheck.entity.YichangDown;
import com.zeroone.star.daycheck.mapper.YichangDownMapper;
import com.zeroone.star.daycheck.service.YichangDownService;
import com.zeroone.star.project.dto.j3.daycheck.Arr.YichangDownDTO;
import com.zeroone.star.project.query.j3.daycheck.Arr.YichangDownQuery;
import org.springframework.beans.BeanUtils;
import org.springframework.stereotype.Service;

import javax.annotation.Resource;
import java.util.*;

/**
 * @author aaa
 * @version 1.0
 * @description TODO
 * @date 2025/2/24 09:14
 */
@Service
public class YichangDownServiceImpl implements YichangDownService {

    @Resource
    YichangDownMapper yichangDownMapper;

    Map<String,List<YichangDown>> data ;

    @Override
    public List<YichangDownDTO> getYichangDownPage(YichangDownQuery condition) {
        data = new HashMap<>();
        Page<YichangDown> page = new Page<>(condition.getPageIndex(), condition.getPageSize());
        // 调用分页查询方法
        Page<YichangDown> yichangDownPage = yichangDownMapper.getYichangDownPage(page, condition);
// 创建 DTO 列表
        ArrayList<YichangDownDTO> result = new ArrayList<>();

// 处理分页后的结果
        for (YichangDown yichangDown : yichangDownPage.getRecords()) {
            YichangDownDTO yichangDownDTO = new YichangDownDTO();
            BeanUtils.copyProperties(yichangDown, yichangDownDTO);
            yichangDownDTO.setBin_id(yichangDown.getBin_id_from());
            result.add(yichangDownDTO);
        }
        data.put("a1",yichangDownPage.getRecords());
        return result;
    }

    @Override
    public List<YichangDown> getYichangDownDate() {
        return data.get("a1");
    }
}
