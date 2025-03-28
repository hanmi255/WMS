/*
 Copyright Zero One Star. All rights reserved.

 @Author: blue
 @Date: 2025/02/24 11:37:57

 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at

	  https://www.apache.org/licenses/LICENSE-2.0

 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.
*/
#include"stdafx.h"
#include"ComNameListController.h"
#include "service/companyattribute/CompanyNameService.h"


CompanyNameJsonVO::Wrapper ComNameListController::execQueryForList()
{
	auto jvo = CompanyNameJsonVO::createShared();
	CompanyNameService service;
	auto res = CompanyNameDTO::createShared();
	try {
		res = service.getCompanyName();
		jvo->success(res);
	}
	catch (const exception ep)
	{
		std::cout << "Exception : " << ep.what() << std::endl;
		jvo->fail(res);
	}


	return jvo;
}