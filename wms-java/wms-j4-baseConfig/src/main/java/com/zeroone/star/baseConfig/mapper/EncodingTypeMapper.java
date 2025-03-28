package com.zeroone.star.baseConfig.mapper;



import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import com.zeroone.star.baseConfig.entity.EncodingType;
import com.zeroone.star.project.dto.j4.encodingType.EncodingTypeNameListDTO;
import org.apache.ibatis.annotations.Mapper;

import java.util.List;

/**
 * <p>
 *  Mapper 接口
 * </p>
 *
 * @author bwb
 * @since 2025-02-22
 */
@Mapper
public interface EncodingTypeMapper extends BaseMapper<EncodingType> {

    void removeAll(List<String> ids);

    List<EncodingTypeNameListDTO> encodingTypeNameList(String query);

}