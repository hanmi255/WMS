package com.zeroone.star.project.j8.other;

import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j8.other.baconttype.BaContTypeDTO;
import com.zeroone.star.project.query.j8.other.baconttype.BaContTypeQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.ResultStatus;
import com.zeroone.star.project.vo.j8.other.baconttype.BaContTypeVO;
import org.springframework.http.ResponseEntity;
import org.springframework.web.multipart.MultipartFile;

import java.util.List;

public interface BaContTypeApis {

    /**
     * 分页查询箱型列表
     * @param dto
     * @return 箱型分页查询列表
     */
    JsonVO<PageDTO<BaContTypeVO>> query(BaContTypeQuery dto);
    /**
     *查询箱型详情
     * @param id
     * @return 箱型详细信息
     */
    JsonVO<BaContTypeVO> queryBaContType(String id);

    /**
     * 添加箱型
     * @param dto
     * @return
     */
    JsonVO<ResultStatus> addBaContType(BaContTypeDTO dto);

    /**
     *修改箱型数据
     * @param dto
     * @return
     */
    JsonVO<ResultStatus> modifyBaContType(BaContTypeDTO dto);

    /**
     * 删除箱型
     * @param ids
     * @return
     */
    JsonVO<ResultStatus> removeCont_shape(List<String> ids);

    /**
     * 导出箱型excel表
     * @return
     */
    ResponseEntity<byte[]> exportExcel();

    /**
     * 导入箱型excel表
     * @param file
     * @return
     */
    JsonVO<ResultStatus> importExcel(MultipartFile file);

}
