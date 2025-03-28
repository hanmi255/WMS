#pragma once

#ifndef _CDM_DTO_
#define _CDM_DTO_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 企业基础数据对象
 */
class CdmDTO : public oatpp::DTO
{

	DTO_INIT(CdmDTO,DTO)

	DTO_FIELD(String, id);
	DTO_FIELD(String, cname);
	DTO_FIELD(String, cby);
	DTO_FIELD(String, cdate);
	DTO_FIELD(String, uname);
	DTO_FIELD(String, uby);
	DTO_FIELD(String, udate);
	DTO_FIELD(String, soc);
	DTO_FIELD(String, scc);
	DTO_FIELD(String, cdn);
	DTO_FIELD(String, cdd);
};
class CddDTO : public oatpp::DTO
{
	DTO_INIT(CddDTO, DTO);
	DTO_FIELD(Vector<String>, companyId );
};

/**
 * 企业基础数据对象
 */
class CDMListDTO : public CdmDTO
{
	DTO_INIT(CDMListDTO, CdmDTO);

};

/**
 * 企业属性分页传输对象
 */
class CDMListPageDTO : public PageDTO<CDMListDTO::Wrapper>
{
	DTO_INIT(CDMListPageDTO, PageDTO<CDMListDTO::Wrapper>);
};


#include OATPP_CODEGEN_END(DTO)
#endif // !_SAMPLE_DTO_