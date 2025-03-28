#include "stdafx.h"
#include "GoodsService.h"








CombineGoodsDTO::Wrapper GoodsService::getData()
{
	GoodsDao dao;
	auto res_dto = CombineGoodsDTO::createShared();
	uint64_t count = dao.countAll();
	if (count <= 0) {
		return res_dto;
	}
	res_dto->total = count;
	list<GoodsDo> doList = dao.getAll();
	for (const GoodsDo& i : doList) {
		auto dto = GoodsDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, i, id, ID, category_code, Category_code, \
			category_name, Category_name, category_level, Category_level, pid, PID, top_node, Top_node);
		res_dto->addData(dto);
	}
	return res_dto;
}

CombineGoodsDTO::Wrapper GoodsService::getTOP()
{
	GoodsDao dao;
	auto res_dto = CombineGoodsDTO::createShared();
	//
	uint64_t count = dao.countAll();
	//
	if (count <= 0) {
		return res_dto;
	}
	res_dto->total = count;
	list<GoodsDo> doList = dao.getTop();
	for (const GoodsDo& i : doList) {
		auto dto = GoodsDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, i, id, ID, category_code, Category_code, \
			category_name, Category_name, category_level, Category_level,pid,PID, top_node, Top_node);
		res_dto->addData(dto);
	}
	return res_dto;

}

CombineGoodsDTO::Wrapper GoodsService::getById(uint64_t id)
{
	GoodsDao dao;
	auto dto = dao.getById(id);

	auto res_dto = CombineGoodsDTO::createShared();
	auto Temdto = GoodsDTO::createShared();
	ZO_STAR_DOMAIN_DO_TO_DTO(Temdto, dto, id, ID, category_code, Category_code, \
		category_name, Category_name, category_level, Category_level,pid,PID,top_node,Top_node);
	res_dto->addData(Temdto);
	res_dto->total = 1;
	return res_dto;
}

std::vector<std::vector<std::string>> GoodsService::getVectorData()
{
	GoodsDao dao;
	auto res = dao.getAll();
	std::vector<std::vector<string>> vec;
	for (auto& i : res) {
		vec.emplace_back(std::vector<std::string>{i.getCategory_code(), i.getCategory_name() \
			, std::to_string(i.getCategory_level()), std::to_string(i.getPID()), i.getTop_node()});
	}


	return vec;
}


bool GoodsService::uploadData(const std::vector<std::vector<std::string>>& data, const PayloadDTO& payload)
{
		// 检查数据是否为空
		if (data.empty()) {
			OATPP_LOGE("GoodsService", "No data found in Excel file");
			return false;
		}

		// 遍历 Excel 数据
		for (size_t i = 1; i < data.size(); i++) { // 跳过表头
			const auto& row = data[i];
			// 将 Excel 数据转换为 DO 对象
			GoodsDo doo;
			try {
				//doo.setID(std::stoi(row[0]));
				doo.setCreate_name(payload.getUsername());
				doo.setCreate_by(payload.getId());;
				doo.setSys_org_code(payload.getOrgcode());
				doo.setCategory_code(row[0]);
				doo.setCategory_name(row[1]);
				doo.setCategory_level(std::stoi(row[2]));
				doo.setPID(std::stoi(row[3]));
				doo.setTop_node(row[4]);
			}
			catch (const std::exception& e) {
				OATPP_LOGE("GoodsService", "Failed to parse data in row %zu: %s", i, e.what());
				continue;
			}

			

			// 调用 DAO 层插入数据
			GoodsDao dao;
			if (dao.insert(doo) == -1) {
				OATPP_LOGE("GoodService", "insert error");
			}
			
		}
		return true;
}
