#pragma once

#ifndef _LADMOD_SERVICE_
#define _LADMOD_SERVICE_
#include <list>
#include "domain/vo/lad-mod/LadModVO.h"
#include "domain/query/lad-mod/LadModQuery.h"
#include "domain/dto/lad-mod/LadModDTO.h"
#include "../../domain/dto/lad-mod/BatchDeleteRequestDto.h"

/**
 * 示例提货方式服务实现
 */
class LadModService
{
public:
	// 分页查询所有数据
	LadModPageDTO::Wrapper listAll(const LadModQuery::Wrapper& query);
	// 保存数据
	uint64_t saveData(const LadModAddDTO::Wrapper& dto);
	// 修改数据
	bool updateData(const LadModDTO::Wrapper& dto);
	// 通过ID删除提货方式
	bool deleteLad(oatpp::UInt64 id);
	// 批量删除提货方式
	bool batchDeleteLad(const BatchDeleteRequestDto::Wrapper& dto);
	// 导出提货方式（返回文件地址）
	string exportLad();
	// 导入提货方式
	int importLad(string filePath);
};

#endif // !_SAMPLE_SERVICE_

