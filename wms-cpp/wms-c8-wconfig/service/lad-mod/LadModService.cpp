#include "stdafx.h"
#include "LadModService.h"
#include "../../dao/lad-mod/LadModDao.h"
#include "ExcelComponent.h"
#include <FastDfsClient.h>
#include "NacosClient.h"

LadModPageDTO::Wrapper LadModService::listAll(const LadModQuery::Wrapper& query)
{
	// 构建返回对象
	auto pages = LadModPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	// 查询数据总条数
	LadModDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0)
	{
		return pages;
	}

	// 分页查询数据
	pages->total = count;
	pages->calcPages();
	list<LadModDO> result = dao.selectWithPage(query);
	// 将DO转换成DTO
	for (LadModDO sub : result)
	{
		auto dto = LadModDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, id, Id, code, Code, name,Name);
		pages->addData(dto);
	}
	return pages;
}

uint64_t LadModService::saveData(const LadModAddDTO::Wrapper& dto)
{
	// 组装DO数据
	LadModDO data;
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, Code, code, Name, name);
	// 执行数据添加
	LadModDAO dao;
	return dao.insert(data);
}

bool LadModService::updateData(const LadModDTO::Wrapper& dto)
{
	// 组装DO数据
	LadModDO data;
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, Code, code, Name, name, Id, id);
	// 执行数据修改
	LadModDAO dao;
	return dao.update(data) == 1;
}

bool LadModService::deleteLad(oatpp::UInt64 id)
{
	LadModDAO dao;
	return dao.deleteById(id) == 1;
}

bool LadModService::batchDeleteLad(const BatchDeleteRequestDto::Wrapper& dto)
{
	LadModDAO dao;
	return dao.batchDelete(dto) > 0;
}

string LadModService::exportLad() {
	LadModDAO dao;
	list<LadModDO> result = dao.selectAll();
	std::vector<std::vector<std::string>> data;
	std::vector<std::string> first;
	first.push_back(ZH_WORDS_GETTER("lad.excel.col.first"));
	first.push_back(ZH_WORDS_GETTER("lad.excel.col.second"));
	data.push_back(first);
	for (auto it = result.begin(); it != result.end(); ++it)
	{
		std::vector<std::string> row;
		for (int j = 1; j <= 2; j++)
		{
			if (j == 1)
			{
				row.push_back(it->getCode());
			}
			else
			{
				row.push_back(it->getName());
			}
			
		}
		data.push_back(row);
	}
	// 定义保存数据位置和页签名称
	// 注意：文件件名称和文件路径不能出现中文
	std::string fileName = "./public/lad/export/lad.xlsx";
	// 注意：因为xlnt不能存储非utf8编码的字符，所以中文字需要从配置文件中获取
	std::string sheetName = ZH_WORDS_GETTER("lad.excel.name");

	// 保存到文件
	ExcelComponent excel;
	excel.writeVectorToFile(fileName, sheetName, data);
#ifdef LINUX
	NacosClient ns(ServerInfo::getInstance().getNacosAddr(), ServerInfo::getInstance().getNacosNs());
	// 读取配置数据节点
	auto thirdServerConfig = ns.getConfig("third-services.yaml");
	// 从Nacos配置中心获取FastDFS客户端配置数据
	std::string config = ns.getConfigText("client.conf");
	// 定义客户端对象
	FastDfsClient dfs(config, false);
#else
	// 定义一个Nacos客户端对象，用于获取配置
	NacosClient ns("192.168.220.128:8848", "4833404f-4b82-462e-889a-3c508160c6b4");
	// 读取配置数据节点
	auto thirdServerConfig = ns.getConfig("./conf/third-services.yaml");
	// +FastDFS客户端配置数据
	std::string ipPort = YamlHelper().getString(&thirdServerConfig, "fastdfs.tracker-servers");
	std::string ip = ipPort.substr(0, ipPort.find(":"));
	int port = stoi(ipPort.substr(ipPort.find(":") + 1));
	// 设置客户端对象
	FastDfsClient dfs(ip, port);
#endif
	// 设置url前缀
	string urlPrefix = "http://" + YamlHelper().getString(&thirdServerConfig, "fastdfs.nginx-servers") + "/";
	// 上传文件
	string tmpField = dfs.uploadFile(fileName);
	// 下载地址
	std::string downloadUrl = urlPrefix + tmpField;
	return downloadUrl;
}

int LadModService::importLad(string filePath)
{
	// 注意：因为xlnt不能存储非utf8编码的字符，所以中文字需要从配置文件中获取
	std::string sheetName = ZH_WORDS_GETTER("lad.excel.name");
	// 从文件中读取
	auto readData = ExcelComponent::readIntoVector("./" + filePath, sheetName);
	list<LadModDO> data;
	int i = 1;
	int result = -1;
	for (auto row : readData)
	{
		if (i == 1)
		{
			if (row.size() != 2 || row[0] != ZH_WORDS_GETTER("lad.excel.col.first") || row[1] != ZH_WORDS_GETTER("lad.excel.col.second"))
			{
				return -1;
			}
			result = 0;
			++i;
			continue;
		}
		LadModDO temp;
		int j = 1;
		for (auto value : row)
		{
			if (j == 1)
			{
				temp.setCode(value);
			}
			else if(j == 2)
			{
				temp.setName(value);
			}
			++j;
		}
		data.push_back(temp);
	}
	LadModDAO dao;
	dao.insert(data);
	return result;
}