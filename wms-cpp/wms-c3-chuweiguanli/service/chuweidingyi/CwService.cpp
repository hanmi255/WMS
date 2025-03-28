#include "stdafx.h"
#include "CwService.h"
#include "dao/chuweidingyi/CwDAO.h"
#include "domain/GlobalInclude.h"

string GetTimeStr() {
	auto now = std::chrono::system_clock::now();
	auto now_c = std::chrono::system_clock::to_time_t(now);
	std::stringstream ss;
	ss << std::put_time(std::localtime(&now_c), "%Y-%m-%d %H:%M:%S");
	return ss.str();
}

string CwService::addCW(const AddCWDTO::Wrapper dto, const PayloadDTO& payload)
{
	BinDO data;
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto,
		BinStore, bin_store,          // DTO的bin_store字段映射到DO
		SuoShuKeHu, suo_shu_ke_hu,     // 所属客户
		KuWeiBianMa, ku_wei_bian_ma,   // 库位编码
		KuWeiTiaoMa, ku_wei_tiao_ma,   // 库位条码
		KuWeiLeiXing, ku_wei_lei_xing, // 库位类型
		KuWeiShuXing, ku_wei_shu_xing, // 库位属性
		ShangJiaCiXu, shang_jia_ci_xu, // 上架次序
		QuHuoCiXu, qu_huo_ci_xu,       // 取货次序
		CHPShuXing, CHP_SHU_XING,      // 产品属性
		XNode, xnode,                  // X坐标
		YNode, ynode,                  // Y坐标
		ZNode, znode                   // Z坐标
	);
	data.setCreateName(payload.getRealname());
	data.setCreateBy(payload.getUsername());
	data.setSysOrgCode(payload.getOrgcode());
	data.setSysCompanyCode(payload.getCompanycode());
	data.setCreateDate(GetTimeStr());
	CwDAO dao;
	return dao.add(data);
}