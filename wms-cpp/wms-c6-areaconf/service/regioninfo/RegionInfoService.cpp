#include "stdafx.h"
#include "RegionInfoService.h"
#include "dao/regioninfo/RegionInfoDAO.h"
#include <chrono>
#include <ctime>
#include "SimpleDateTimeFormat.h"
#include "id/SnowFlake.h"
std::string getCurrentTimeAsString() {
	// 获取当前时间点
	auto now = std::chrono::system_clock::now();

	// 将时间点转换为 time_t（表示从 epoch 开始的秒数）
	std::time_t now_time_t = std::chrono::system_clock::to_time_t(now);

	// 将 time_t 转换为本地时间
	std::tm now_tm = *std::localtime(&now_time_t);

	// 使用 stringstream 格式化时间为字符串
	std::ostringstream oss;
	oss << std::put_time(&now_tm, "%Y-%m-%d %H:%M:%S");

	// 返回格式化后的字符串
	return oss.str();
}

uint64_t RegionInfoService::saveData(const RegionInfoDTO::Wrapper& dto, const PayloadDTO& payload)
{
	//获取当前时间
	std::string currentTime = getCurrentTimeAsString();
	//获取uuid
	SnowFlake ls(1, 1);
	string id = std::to_string(ls.nextId());
	// 组装DO数据
	RegionInfoDO data;
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, Region_code, region_code, Region_name, region_name, Region_rdata, region_rdata);
	data.setId(id);
	data.setCreate_name(payload.getUsername());
	data.setCreate_by(payload.getRealname());
	data.setCreate_date(currentTime);
	data.setUpdate_by(payload.getRealname());
	data.setUpdate_name(payload.getUsername());
	data.setSys_org_code(payload.getOrgcode());
	data.setSys_company_code(payload.getCompanycode());
	data.setUpdate_date(currentTime);
	// 执行数据添加
	RegionInfoDAO dao;
	return dao.insert(data);
}

bool RegionInfoService::removeData(std::string region_code)
{
	RegionInfoDAO dao;
	return dao.remove(region_code) == 1;
}

bool RegionInfoService::updateData(const RegionModifyDTO::Wrapper& dto, const PayloadDTO& payload)
{
	//获取当前时间
	std::string currentTime = getCurrentTimeAsString();
	// 组装DO数据
	RegionInfoDO data;
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, Region_code, region_code, Region_name, region_name, Region_rdata, region_rdata, Id, id);
	data.setUpdate_by(payload.getRealname());
	data.setUpdate_name(payload.getUsername());
	data.setUpdate_date(currentTime);
	// 执行数据添加
	RegionInfoDAO dao;
	return dao.update(data);
	}

void RegionInfoService::import(std::vector<std::vector<std::string>> vec, const PayloadDTO& payload)
{
	std::list<RegionInfoDO> obj;
	std::string currentTime = getCurrentTimeAsString();
	SnowFlake sf(1, 1);
	std::string name = payload.getUsername();
	std::string by = payload.getRealname();
	std::string date = SimpleDateTimeFormat::format();
	std::string org = payload.getOrgcode();
	std::string company = payload.getCompanycode();
	for (auto sub : vec)
	{
		if (sub[0] == "" || sub[1] == "" || sub[2] == "")
		{
			continue;
		}
		RegionInfoDO data;
		data.setId(std::to_string(sf.nextId()));
		data.setCreate_by(by);
		data.setCreate_date(date);
		data.setCreate_name(name);
		data.setUpdate_by(by);
		data.setUpdate_date(date);
		data.setUpdate_name(name);
		data.setSys_org_code(org);
		data.setSys_company_code(company);
		data.setRegion_code(sub[0]);
		data.setRegion_name(sub[1]);
		data.setRegion_rdata(double(std::stod(sub[2])));
		obj.push_back(data);
	}
	
	RegionInfoDAO dao;
	dao.insert(obj);
}

oatpp::Vector<RegionNameDTO::Wrapper> RegionInfoService::getByName()
{
	// 查询数据
	RegionInfoDAO dao;
	auto res = dao.selectByName();
	// 查询到数据转换成DTO
	auto dtoList = oatpp::Vector<RegionNameDTO::Wrapper>::createShared();
	for (const auto& item : res) {
		auto dto = RegionNameDTO::createShared();
		dto->area_name = item.getName();
		dto->id = item.getId();
		std::cout << item.getId();
		dtoList->push_back(dto);
	}
	return dtoList;
}
