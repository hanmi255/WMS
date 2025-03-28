package com.zeroone.star.othermana.mapper;


import com.zeroone.star.othermana.entity.BaContType;
import com.zeroone.star.project.dto.j8.other.baconttype.BaContTypeDTO;
import com.zeroone.star.project.vo.j8.other.baconttype.BaContTypeVO;
import org.mapstruct.Mapper;
import org.mapstruct.Mapping;

@Mapper(componentModel="spring")
public interface IBaContTypeMapper {

    @Mapping(source="id",target="id")
    @Mapping(source="contTypeName",target="contTypeName")
    @Mapping(source="contTypeCode",target="contTypeCode")
    BaContType BaconttypeDTOtoDO(BaContTypeDTO dto);

    @Mapping(source="id",target="id")
    @Mapping(source="contTypeName",target="contTypeName")
    @Mapping(source="contTypeCode",target="contTypeCode")
    BaContTypeVO BaconttypeDOtoVO(BaContType dto);

    @Mapping(source="id",target="id")
    @Mapping(source="contTypeName",target="contTypeName")
    @Mapping(source="contTypeCode",target="contTypeCode")
    BaContTypeDTO BaconttypeDOtoDTO(BaContType baContTypeDO);

}
