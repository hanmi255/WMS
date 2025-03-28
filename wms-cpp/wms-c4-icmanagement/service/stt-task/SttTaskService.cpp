#include "stdafx.h"
#include "SttTaskService.h"
#include "domain/dto/stt-on-move/SttOnMoveDTO.h"
#include "../../dao/stt-task/SttTaskDAO.h"
#include "domain/do/goods-manage/wm_stt_in_goodsDO.h"


uint64_t SttTaskService::insert(const SttOnMoveDetailDTO::Wrapper& sttOnMoveDetailDTO, const PayloadDTO& payload)
{
	// 组装DO数据
	Wm_Stt_In_GoodsDO data;
	// 基本数据，源自动碰盘
	ZO_STAR_DOMAIN_DTO_TO_DO(data, sttOnMoveDetailDTO,BinId,bin_id,TinId,tin_id,GoodsId,goods_id,GoodsName,goods_name,GoodsQua,goods_qua,BaseUnit,base_unit,GoodsProDate,goods_pro_data,CusName,cus_name,CusCode,cus_code,SttSta,stt_sta, SysOrgCode,sys_org_code,SysCompanyCode, sys_company_code);

	// 组装DO其他数据
	// 生成create_date
	std::time_t now = std::time(nullptr);
	std::tm tm_now = *std::localtime(&now);
	std::stringstream ssCreateTime;
	ssCreateTime << std::put_time(&tm_now, "%Y-%m-%d %H:%M:%S ");

	data.setCreateDate(ssCreateTime.str());

	// 生成stt_id
	std::stringstream ssSttId;
	ssSttId << std::put_time(&tm_now, "%Y-%m-%d %H:%M ");

	data.setSttId(ssSttId.str());

	// 创建人名称
	data.setCreateBy(payload.getUsername());

	// 创建人昵称realname
	data.setCreateName(payload.getRealname());
	
	// 所属公司、部门
	data.setSysCompanyCode(payload.getCompanycode());
	data.setSysOrgCode(payload.getOrgcode());

	// 盘点状态，设置为计划中
	data.setSttSta(ZH_WORDS_GETTER("sttTask.val.inPlan"));

	// 盘点类型
	data.setSttType("01");
	
	// 传给DAO层执行插入操作
	SttTaskDAO dao;
	return dao.insert(data);
}

uint64_t SttTaskService::delData(const string& id, const PayloadDTO& payload)
{
	// 组装DO数据
	Wm_Stt_In_GoodsDO data;

	// 匹配标识符
	data.setId(id);
	//更改盘点状态为已删除
	data.setSttSta(ZH_WORDS_GETTER("sttTask.val.deleted"));
	// 更新相关信息
	// 生成update_date
	std::time_t now = std::time(nullptr);
	std::tm tm_now = *std::localtime(&now);
	std::stringstream ssUpdateDate;
	ssUpdateDate << std::put_time(&tm_now, "%Y-%m-%d %H:%M:%S ");

	data.setUpdateDate(ssUpdateDate.str());

	// 修改update_by
	data.setUpdateBy(payload.getUsername());

	// 修改update_name
	data.setUpdateName(payload.getRealname());

	SttTaskDAO dao;
	
	return dao.modifySttSta(data);
}
