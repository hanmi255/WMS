#ifndef _BAGOODSTYPE_DO_
#define _BAGOODSTYPE_DO_
#include "../DoInclude.h"

/**
 * 工作状态实体类
 */
class BaGoodsTypeDO
{
	// 编号
	CC_SYNTHESIZE(string, id, Id);
	// 创建人名称
	CC_SYNTHESIZE(string, create_name, CreateName);
	// 创建人登录名称
	CC_SYNTHESIZE(string, create_by, CreateBy);
	// 创建日期
	CC_SYNTHESIZE(string, create_date, CreateDate);
	// 更新人名称
	CC_SYNTHESIZE(string, update_name, UpdateName);
	//更新人登录名称
	CC_SYNTHESIZE(string, update_by, UpdateBy);
	//更新日期
	CC_SYNTHESIZE(string, update_date, UpdateDate);
	//所属部门
	CC_SYNTHESIZE(string, sys_org_code, SysOrgCode);
	//所属公司
	CC_SYNTHESIZE(string, sys_company_code, SysCompanyCode);
	//产品属性代码
	CC_SYNTHESIZE(string, goods_type_code, GoodsTypeCode);
	//产品属性名称
	CC_SYNTHESIZE(string, goods_type_name, GoodsTypeName);

public:
	BaGoodsTypeDO() {
		id = "0";
		create_name = "";
		create_by = "";
		create_date = "";
		update_name = "";
		update_by = "";
		update_date = "";
		sys_org_code = "";
		sys_company_code = "";
		goods_type_code = "";
		goods_type_name = "";
	}
};

// 给SampleDO智能指针设定一个别名方便使用
typedef std::shared_ptr<BaGoodsTypeDO> PtrBaGoodsTypeDO;
#endif // !_SAMPLE_DO_