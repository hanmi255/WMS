
#include "stdafx.h"
#include "LadModController.h"
#include "../../service/lad-mod/LadModService.h"
#include "../ApiDeclarativeServicesHelper.h"
#include "../lib-common/include/CommonMacros.h"

LadModPageJsonVO::Wrapper LadModController::execQueryAll(const LadModQuery::Wrapper& query)
{
	LadModService service;
	// 查询数据
	auto result = service.listAll(query);
	// 响应结果
	auto jvo = LadModPageJsonVO::createShared();
	jvo->success(result);
	return jvo;
}

Uint64JsonVO::Wrapper LadModController::execAddLad(const LadModAddDTO::Wrapper& dto)
{
	// 定义返回数据对象
	auto jvo = Uint64JsonVO::createShared();
	// 参数校验
	// 非空校验
	if (!dto->code || !dto->name)
	{
		return nullptr;
	}
	// 有效值校验
	if ( dto->code->empty() || dto->name->empty())
	{
		return nullptr;
	}

	// 定义一个Service
	LadModService service;
	// 执行数据新增
	uint64_t id = service.saveData(dto);
	if (id > 0) {
		jvo->success(UInt64(id));
	}
	else
	{
		jvo->fail(UInt64(id));
	}
	//响应结果
	return jvo;
}

Uint64JsonVO::Wrapper LadModController::execModifyLadMod(const LadModDTO::Wrapper& dto)
{
	// 定义返回数据对象
	auto jvo = Uint64JsonVO::createShared();
	// 参数校验
	if (!dto->id || dto->id <= 0)
	{
		return nullptr;
	}
	// 定义一个Service
	LadModService service;
	// 执行数据修改
	if (service.updateData(dto)) {
		jvo->success(dto->id);
	}
	else
	{
		jvo->fail(dto->id);
	}
	// 响应结果
	return jvo;
}

Uint64JsonVO::Wrapper LadModController::execDeleteLad(const oatpp::UInt64& id)
{
	// 定义返回数据对象
	auto jvo = Uint64JsonVO::createShared();
	// 定义一个Service
	LadModService service;
	// 执行数据删除
	if (service.deleteLad(id)) {
		jvo->success(id);
	}
	else
	{
		jvo->fail(id);
	}
	// 响应结果
	return jvo;
}

Uint64JsonVO::Wrapper LadModController::execBatchDeleteLad(const BatchDeleteRequestDto::Wrapper& dto)
{
	// 定义返回数据对象
	auto jvo = Uint64JsonVO::createShared();
	// 定义一个Service
	LadModService service;
	// 执行数据删除
	if (service.batchDeleteLad(dto)) {
		jvo->success(1);
	}
	else
	{
		jvo->fail(-1);
	}
	// 响应结果
	return jvo;
}

StringJsonVO::Wrapper LadModController::execImportLad(std::shared_ptr<IncomingRequest> request)
{
	// 1 初始化
	API_MULTIPART_INIT(container, reader);

	// 2 配置读取器
	API_MULTIPART_CONFIG_MEMO(reader, "file", -1);

	// 3 读取数据
	request->transferBody(&reader);

	// 4 解析数据
	/* 获取文件数据 */
	API_MULTIPART_PARSE_FILE_FIELD(container, "file", file);
	if (file)
	{
		/* 文件名称 */
		string filename = partfile->getFilename().getValue("");
		/* 测试将文件保存到磁盘上面 */
		string fullPath = "public/lad/import/" + filename;

		//判断目录是否存在，不存在创建目录
		auto dir = fullPath.substr(0, fullPath.find_last_of("/") + 1);
		const size_t dirLen = dir.length();
		if (dirLen > 512)
		{
			printf("file path too long\n");
			auto jvo = StringJsonVO::createShared();
			jvo->fail("error");
			return jvo;
		}
		char tmpDirPath[512] = { 0 };
		for (size_t i = 0; i < dirLen; i++)
		{
			tmpDirPath[i] = dir[i];
			if (tmpDirPath[i] == '/')
			{
				if (ACCESS(tmpDirPath, 0) != 0)
				{
					if (MKDIR(tmpDirPath) != 0)
					{
						printf("create dir %s fail\n", tmpDirPath);
						auto jvo = StringJsonVO::createShared();
						jvo->fail("error");
						return jvo;
					}
				}
			}
		}

		file.saveToFile(fullPath.c_str());
		
		LadModService service;
		int result = service.importLad(fullPath);
		auto jvo = StringJsonVO::createShared();
		if (result == -1)
		{
			jvo->fail("error");
			return jvo;
		}
		else if (result == 0)
		{
			jvo->success("success");
			return jvo;
		}
	}
	else {
		// 5 响应结果
		auto jvo = StringJsonVO::createShared();
		jvo->fail("Parameter name must be file");
		return jvo;
	}
}

StringJsonVO::Wrapper LadModController::execExportLad()
{
	LadModService service;
	auto jvo = StringJsonVO::createShared();
	jvo->success(service.exportLad());
	return jvo;
}