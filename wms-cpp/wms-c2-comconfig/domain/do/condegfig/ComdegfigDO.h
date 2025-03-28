#ifndef _COMDEGFIG_DO_
#define _COMDEGFIG_DO_
#include "../DoInclude.h"

/**
 * 示例数据库实体类
 */
class ComdegfigDO
{
	// 唯一代码
	CC_SYNTHESIZE(string, id, Id);
	//创建人名称
	CC_SYNTHESIZE(string, createname, CreateName);
	//创建人登录名称
	CC_SYNTHESIZE(string, createby, CreateBy);
	// 所属部门
	CC_SYNTHESIZE(string, orgcode, OrgCode);
	// 所属公司
	CC_SYNTHESIZE(string, companycode, CompanyCode);
	//创建时间
	CC_SYNTHESIZE(string,createdate, CreateDate)
	// 企业等级代码
	CC_SYNTHESIZE(string, degcode, DegCode);
	// 企业等级名称
	CC_SYNTHESIZE(string, degname, DegName);
	// 企业等级停用
	CC_SYNTHESIZE(string, degdel, DegDel);
public:
	ComdegfigDO(){}
	ComdegfigDO(string id, string createname,string createby,string orgcode,string companycode,string degcode,string degname,string degdel) {
		this->id = id;
		this->createname = createname;
		this->createby = createby;
		this->orgcode = orgcode;
		this->companycode = companycode;
		this->degcode = degcode;
		this->degname = degname;
		this->degdel;
	}
};

// 给ComdegfigDO智能指针设定一个别名方便使用
typedef std::shared_ptr<ComdegfigDO> PtrComdegfigDO;
#endif 