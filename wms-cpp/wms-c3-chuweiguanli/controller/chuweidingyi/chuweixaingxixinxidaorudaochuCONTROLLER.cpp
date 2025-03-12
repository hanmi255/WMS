#include "stdafx.h"
#include "chuweixaingxixinxidaorudaochuCONTROLLER.h"
#include "../../service/chuweidingyi/xaingxixinxiSERVICE.h"
#include "ServerInfo.h"
#include "NacosClient.h"
#include "FastDfsClient.h"
#include "SimpleDateTimeFormat.h"
#include "../../../lib-common/include/ExcelComponent.h"
//详细
//																	
//xiangxixinxiJsonVO::Wrapper apixiangxixinxi::execXiangXiXinXiZhanShi(const xiangxixinxiQUERY::Wrapper& weiyiid)
//{
//	// 定义一个Service
//	xiangxixinxiSERVICE service;
//	// 查询数据
//	auto result = service.getById(weiyiid);
//	// 响应结果
//	auto jvo = xiangxixinxiJsonVO::createShared();
//	jvo->success(result);
//	
//	return jvo;
//
//}

//查询详细数据
xiangxixinxiJsonVO::Wrapper apixiangxixinxi::execXiangXiXinXiZhanShi(const xiangxixinxiQUERY::Wrapper& query, const PayloadDTO& payload)
{
	// 定义一个Service
	xiangxixinxiSERVICE service;
	// 查询数据
	auto result = service.getById(query);
	// 响应结果
	auto jvo = xiangxixinxiJsonVO::createShared();
	jvo->success(result);
	
	return jvo;
	
}



//导出储位----文件下载---返回下载路径
StringJsonVO::Wrapper apixiangxixinxi::execDaoChuChuWei(const daochuchuweiDTO::Wrapper& id_zhi, const PayloadDTO& payload)
{
	//	构建响应结果
	auto jvo = StringJsonVO::createShared();

	if (payload.getCode() != PayloadCode::SUCCESS) {
		return {};
	}
	else {
		//	Service层
		xiangxixinxiSERVICE service;
		auto res = service.daochuchuweiCONTROLLER(id_zhi->biaoshi);
		jvo->init("download_url: " + res, RS_SUCCESS);
	}

	return jvo;

}





//储位导入--单文件
StringJsonVO::Wrapper apixiangxixinxi::execDaoRuWenJianOne(std::shared_ptr<IncomingRequest> request, const PayloadDTO& payload)
{

	//  初始化-----容器名字，读取容器变量名
	API_MULTIPART_INIT(container, reader);

	//  配置读取器----------读取器，-1默认读取全部
	API_MULTIPART_CONFIG_MEMO_DEFAULT(reader, -1);

	//  读取数据
	request->transferBody(&reader);

	int con = container->count();
	
	for (int file_i = 0; file_i < con; file_i++)
	{
		string filename = "file";
		filename += std::to_string(file_i);
	
		
		//解析数据
		/* 获取文件数据 */
		API_MULTIPART_PARSE_FILE_FIELD(container, filename, file);


		std::vector<std::vector<std::string>> data = ExcelComponent::readIntoVector(file->c_str(), file->size(), ZH_WORDS_GETTER("bin.xlsx.sheet.s1"));

		int i = 0;
		string s = "";
		for (auto& row : data) {
			if (i > 2)
			{
				//创建dto类型接收数据
				auto jsdto = xiangxixinxiDTO::createShared();
				//dto设置数据

				jsdto->cangku = row[0];
				jsdto->bianma = row[1];
				jsdto->tiaoma = row[2];
				jsdto->leixing = row[3];
				jsdto->shuxing = row[4];
				jsdto->chanpinshuxing = row[5];
				jsdto->shangjiacixu = row[6];
				jsdto->quhuocixu = row[7];
				jsdto->kehu = row[8];
				jsdto->zuidamianji = row[9];
				jsdto->tiji = row[10];
				jsdto->zhongliang = row[11];
				jsdto->mianji = row[12];
				jsdto->zuidatiji = row[13];
				jsdto->zuidazhongliang = row[14];
				jsdto->zuidatuopan = row[15];
				jsdto->chang = row[16];
				jsdto->kuan = row[17];
				jsdto->gao = row[18];
				jsdto->tingyong = row[19];
				jsdto->beizhu = row[20];
				jsdto->beizhu1 = row[21];
				jsdto->beizhu2 = row[22];
				jsdto->dongxian = row[23];
				jsdto->ID = row[24];
				jsdto->x = row[25];
				jsdto->y = row[26];
				jsdto->z = row[27];


				//service传输数据
				xiangxixinxiSERVICE sev;
				s = sev.addchuweiSERVICE(jsdto, payload);
			}
			i++;
		}
		if (s == "")
		{
			return {};
		}
	}
	auto jvo = StringJsonVO::createShared();
	jvo->success("OK");
	return jvo;
}





