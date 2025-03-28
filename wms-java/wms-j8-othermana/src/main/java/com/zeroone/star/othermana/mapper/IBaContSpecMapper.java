package com.zeroone.star.othermana.mapper;

import com.zeroone.star.othermana.entity.BaContSpec;
import com.zeroone.star.project.dto.j8.other.contspec.SpecificationAddDTO;
import com.zeroone.star.project.dto.j8.other.contspec.SpecificationBaseDTO;
import com.zeroone.star.project.dto.j8.other.contspec.SpecificationModifyDTO;
import org.mapstruct.Mapper;
import org.mapstruct.Mapping;

@Mapper(componentModel = "spring")
public interface IBaContSpecMapper {
    @Mapping(source = "contSpecId",target = "contSpecCode")
    @Mapping(source = "contSpecName",target = "contSpecName")
    BaContSpec specificationBaseDtoToSpec(SpecificationBaseDTO dto);

    @Mapping(source = "contSpecId",target = "contSpecCode")
    @Mapping(source = "contSpecName",target = "contSpecName")
    @Mapping(source = "createName",target = "createName")
    @Mapping(source = "createBy",target = "createBy")
    @Mapping(source = "createDate",target = "createDate")
    @Mapping(source = "sysOrgCode",target = "sysOrgCode")
    @Mapping(source = "sysCompanyCode",target = "sysCompanyCode")
    BaContSpec specificationAddDtoToSpec(SpecificationAddDTO dto);

    @Mapping(source = "id",target = "id")
    @Mapping(source = "contSpecId",target = "contSpecCode")
    @Mapping(source = "contSpecName",target = "contSpecName")
    @Mapping(source = "updateName",target = "updateName")
    @Mapping(source = "updateBy",target = "updateBy")
    @Mapping(source = "updateDate",target = "updateDate")
    @Mapping(source = "sysOrgCode",target = "sysOrgCode")
    @Mapping(source = "sysCompanyCode",target = "sysCompanyCode")
    BaContSpec specificationModifyToSpec(SpecificationModifyDTO dto);

    @Mapping(source = "contSpecCode",target = "contSpecId")
    @Mapping(source = "contSpecName",target = "contSpecName")
    SpecificationBaseDTO specToSpecificationBaseDTO(BaContSpec spec);
    @Mapping(source = "contSpecCode",target = "contSpecId")
    @Mapping(source = "contSpecName",target = "contSpecName")
    @Mapping(source = "createName",target = "createName")
    @Mapping(source = "createBy",target = "createBy")
    @Mapping(source = "createDate",target = "createDate")
    @Mapping(source = "sysOrgCode",target = "sysOrgCode")
    @Mapping(source = "sysCompanyCode",target = "sysCompanyCode")
    SpecificationAddDTO specToSpecificationAddDTO(BaContSpec spec);

}