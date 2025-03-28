package com.zeroone.star.project.j3.daycheck;

import com.zeroone.star.project.dto.j3.daycheck.Arr.YichangDownDTO;
import com.zeroone.star.project.query.j3.daycheck.Arr.YichangDownQuery;
import com.zeroone.star.project.vo.JsonVO;
import org.springframework.http.ResponseEntity;

import java.util.List;

/**
 * 收货未上架 出库异常（下架与复核）
 */
public interface YichangDownApis {


    /**
     * 出库异常
     * @param condition
     * @return
     */
    public JsonVO<List<YichangDownDTO>> getYichangDown(YichangDownQuery condition);

    /**
     * 根据条件生成excel文档
     * @param
     * @return
     */
    public ResponseEntity<byte[]> downLoadYicchang();
}
