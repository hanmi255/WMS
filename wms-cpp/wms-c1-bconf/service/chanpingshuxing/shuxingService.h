#pragma once
#include"../../domain/dto/chanpingshuxingdto/ShuxingDTO.h"
#include"../../domain/GlobalInclude.h"

#include "Macros.h"
#include "ExcelComponent.h"
class  ShuxingService {
public:
	//修改数据
	bool modify_data(const ShuxingDTO::Wrapper& dto, const PayloadDTO& payload);
	//删除数据
	bool delete_data(const ShuxingShanChuDTO::Wrapper& dto);
	//导出数据
	vector<array<string,2>>upload_data();
	//导入数据
	bool load_data(const ShuxingDaoruDTO& dto);
};