package com.zeroone.star.daycheck;

import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.zeroone.star.daycheck.entity.YichangDown;
import com.zeroone.star.daycheck.mapper.YichangDownMapper;
import com.zeroone.star.project.dto.j3.daycheck.Arr.YichangDownDTO;
import com.zeroone.star.project.query.j3.daycheck.Arr.YichangDownQuery;
import org.junit.jupiter.api.Test;
import org.springframework.beans.BeanUtils;
import org.springframework.boot.test.context.SpringBootTest;

import javax.annotation.Resource;
import java.util.ArrayList;

/**
 * @author aaa
 * @version 1.0
 * @description TODO
 * @date 2025/2/24 09:17
 */
@SpringBootTest
public class test {
    @Resource
    YichangDownMapper yichangDownMapper;

    @Test
    public void test1(){
        YichangDownQuery query = new YichangDownQuery();
      //  query.setBin_id("BIN014");
       // query.setZhong_wen_qch("大成陶瓷有限公司");
        //query.setKu_wei_bian_ma("KW129");
//        Page<Object> page = new Page<>(query.getPageIndex(), query.getPageSize());
//
//        ArrayList<YichangDownDTO> result = new ArrayList<>();
//        List<YichangDown> yichangDowns = yichangDownMapper.getYichangDown(query);
//        for(YichangDown yichangDown : yichangDowns){
//            if(!yichangDown.getGoods_qua().equals(yichangDown.getGoods_quaok())){
//                YichangDownDTO yichangDownDTO = new YichangDownDTO();
//                BeanUtils.copyProperties(yichangDown, yichangDownDTO);
//                yichangDownDTO.setBin_id(yichangDown.getBin_id_from());
//                yichangDownDTO.setZhong_wen_qch(yichangDown.getZhong_wen_qch());
//                System.out.println(yichangDown);
//                result.add(yichangDownDTO);
//            }
//        }
//        System.out.println();
//        for(YichangDownDTO yichangDownDTO : result){
//            System.out.println(yichangDownDTO);
//        }
    }

    @Test
    public void test2(){
        YichangDownQuery query = new YichangDownQuery();
        query.setPageIndex(1);
        query.setPageSize(2);
        Page<YichangDown> page = new Page<>(query.getPageIndex(), query.getPageSize());

// 调用分页查询方法
        Page<YichangDown> yichangDownPage = yichangDownMapper.getYichangDownPage(page, query);
// 创建 DTO 列表
        ArrayList<YichangDownDTO> result = new ArrayList<>();

// 处理分页后的结果
        for (YichangDown yichangDown : yichangDownPage.getRecords()) {
                YichangDownDTO yichangDownDTO = new YichangDownDTO();
                BeanUtils.copyProperties(yichangDown, yichangDownDTO);
                yichangDownDTO.setBin_id(yichangDown.getBin_id_from());
                //yichangDownDTO.setZhong_wen_qch(yichangDown.getZhong_wen_qch());
                result.add(yichangDownDTO);
        }

// 打印输出结果
        for (YichangDownDTO yichangDownDTO : result) {
            System.out.println(yichangDownDTO);
        }

    }
}
