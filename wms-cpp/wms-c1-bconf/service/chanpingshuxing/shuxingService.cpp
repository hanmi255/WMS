#include "stdafx.h"
#include "shuxingService.h"
#include"../../domain/do/chanpingshuxing/ShuxingDO.h"
#include"../../dao/chanpingshuxing/ShuxingDAO.h"
bool  ShuxingService::modify_data(const ShuxingDTO::Wrapper& dto, const PayloadDTO& payload)
{
	ShuxingDO sdo;
	ZO_STAR_DOMAIN_DTO_TO_DO(sdo, dto,  
		Goods_type_code, goods_type_code, Goods_type_name, goods_type_name,Id,id);
	sdo.setUpdate_by(payload.getId());
	sdo.setUpdate_name(payload.getUsername());
	ShuxingDAO sdao;
	return sdao.update(sdo) == 1;
}

bool ShuxingService::delete_data(const ShuxingShanChuDTO::Wrapper& dto)
{
	
	vector<ShuxingDO>sdos;
	for (int i = 0; i < dto->ids->size(); i++) {
		ShuxingDO tempdo;
		tempdo.setId(dto->ids[i]);
		sdos.push_back(tempdo);
	}
	ShuxingDAO sdao;
	return sdao.delete_data(sdos);
}

vector<array<string,2>> ShuxingService::upload_data()
{
	ShuxingDAO sdao;
	vector<array<string, 2>>v;
	auto ans = sdao.upload_data();
	for (auto& i : ans) {
		//cout << i.getGoods_type_code() << "-----" << i.getGoods_type_name() << "\n";
		v.push_back({ i.getGoods_type_code() ,i.getGoods_type_name() });
	}
	

	return  v;
}

bool ShuxingService::load_data(const ShuxingDaoruDTO& dto)
{
	ShuxingDAO dao;
	int ans = 0;
	ExcelComponent excel;
	auto data=excel.readIntoVector(dto.file->c_str(), dto.file->size(), dto.sheet_name);
	for (int i = 1; i < data.size(); i++) {
		ShuxingDO sdo;
		sdo.setCreate_by(dto.create_by);
		sdo.setCreate_name(dto.create_name);
		sdo.setGoods_type_name(data[i][0]);
		sdo.setGoods_type_code(data[i][1]);
		sdo.setSys_org_code(dto.sys_org_code);
		sdo.setSys_company_code(dto.sys_company_code);
		ans+=dao.load_data(sdo);
	}
	
	
	return ans;
}
