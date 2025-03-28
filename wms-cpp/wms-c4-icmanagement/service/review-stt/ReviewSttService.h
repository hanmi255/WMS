#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: qingbingwei
 @Date: 2025/2/26 11:08

*/
#ifndef _REVIEW_STT_SERVICE_
#define _REVIEW_STT_SERVICE_
#include <list>

#include "domain/query/review-stt/ReviewSttQuery.h"
#include "domain/dto/review-stt/ReviewSttDTO.h"
#include "domain/vo/review-stt/ReviewSttVO.h"


/**
 * 盘点管理服务实现
 */
class ReviewSttService
{
public:
	// 分页查询所有数据
	ReviewSttPageDTO::Wrapper listAll(const ReviewSttQuery::Wrapper& query);
	//复盘
	bool updateData(const ReviewSttDTO::Wrapper& dto, const PayloadDTO& payload);
	//导出数据
	std::string exportData(const ReviewSttQuery::Wrapper& query);
	// 通过条件查询单个数据
	//GoodsDiffPostListDTO::Wrapper getByCondition(const GoodsDiffPostQuery::Wrapper& query);
	// 保存数据
	/*uint64_t saveData(const SampleAddDTO::Wrapper& dto);
	// 修改数据
	bool updateData(const SampleDTO::Wrapper& dto);
	// 通过ID删除数据
	bool removeData(uint64_t id);*/
};

#endif // !_REVIEW_STT_SERVICE_
