#pragma once
#ifndef _CANGKUDINGYISERVICE_H_
#define _CANGKUDINGYISERVICE_H_

#include<list>
#include "domain/dto/cangkudingyi/deleteCangkuDTO.h"
#include "domain/dto/cangkudingyi/CangkuNameListDTO.h"

class CangKuDingYiService {
public:
	//	获取仓库名称列表(无参)
	oatpp::List<CangkuNameListDTO::Wrapper> getCangkuNameList();
	//	通过仓库ID删除仓库(支持批量)
	bool deleteCangkuById_List(oatpp::List<oatpp::String>& id_list);
	//	通过仓库ID列表导出仓库信息, 返回文件路径
	string getpath_exportCangkuByCodeList(oatpp::List<oatpp::String>& code_list);

};


#endif