#include "stdafx.h"	
#include "controller/kuneizhuanyi/MoveGoodsController.h"
#include "service/kuneizhuanyi/MoveGoodsService.h"
<<<<<<< HEAD
=======
#include "ExcelComponent.h"
>>>>>>> 05f7ec7fb45d4bc1f52eea780440c95f076c61f0

MoveGoodsPageJsonVO::Wrapper MoveGoodsController::execQueryMoveGoodsList(const MoveGoodsQuery::Wrapper& query)
{
	MoveGoodsService service;

	auto result = service.listMoveGoodsPage(query);
	auto jvo = MoveGoodsPageJsonVO::createShared();

	jvo->success(result);
	return jvo;
}

StringJsonVO::Wrapper MoveGoodsController::execModifyMoveGoods(const MoveGoodsModifyDTO::Wrapper& dto, const PayloadDTO& payload)
{
	auto jvo = StringJsonVO::createShared();
	MoveGoodsService service;
	auto result = service.updateMoveGoods(dto, payload);

	if (result == "failed")
		jvo->fail(String{ "failed to modify move goods" });
	else
		jvo->success(String{ result });

	return jvo;
}

StringJsonVO::Wrapper MoveGoodsController::execBatchModifyMoveGoods(const MoveGoodsBatchModifyDTO::Wrapper& dto, const PayloadDTO& payload)
{
	auto jvo = StringJsonVO::createShared();
	MoveGoodsService service;
	auto result = service.updateMoveGoodsBatch(dto, payload);

	if (result == "All Updated")
		jvo->success(String{ "all modified successfully" });
	else if (result == "Part Updated")
		jvo->fail(String{ "part modified successfully" });
	else
		jvo->fail(String{ "failed to modify move goods" });

	return jvo;
}



MoveGoodsDetailedJsonVO::Wrapper MoveGoodsController::execQueryDetailedMoveGoods(const String& id)
{
	// ���巵�����ݶ���
	auto jvo = MoveGoodsDetailedJsonVO::createShared();

	// ����У��
	// �ǿ�У��
	if (!id)
	{
		jvo->init(nullptr, RS_PARAMS_INVALID);
		return jvo;
	}

	// ����һ��Service
	MoveGoodsService service;
	// ִ����������
	auto res = service.getDetailedById(id);
	jvo->success(res);

	//��Ӧ���
	return jvo;
}

void WriteToXlsx(string fileName, vector<vector<string>> data) {
	std::string sheetName = ZH_WORDS_GETTER("move-goods.xlsx.sheet.s1");  // ��ȡ����

	// ���� Excel ������
	xlnt::workbook wb;
	xlnt::worksheet ws = wb.active_sheet();
	ws.title(sheetName);

	// ������д�� Excel
	for (size_t row = 0; row < data.size(); ++row) {
		for (size_t col = 0; col < data[row].size(); ++col) {
			ws.cell(static_cast<int>(col + 1), static_cast<int>(row + 1)).value(data[row][col]);
		}
	}

	// ���� Excel �ļ�
	try {
		wb.save(fileName);
	}
	catch (const std::exception& e) {
		std::cerr << "Error saving Excel file: " << e.what() << std::endl;
	}
}

std::shared_ptr<oatpp::web::server::api::ApiController::OutgoingResponse> MoveGoodsController::execDownLoadMoveGoods(const MoveGoodsExcelQuery::Wrapper& ids){
	string filename{ "moveGoods.xlsx" };
	auto export_path = ids.get()->file_path->c_str() + filename;
	vector<string> ids_str;
	string idsStr = ids.get()->ids->c_str();
	if (!idsStr.empty()) {
		std::stringstream ss(idsStr.c_str());
		std::string item;
		while (std::getline(ss, item, ',')) {  // ���ŷָ�
			ids_str.push_back(item.c_str());  // oatpp::String ��Ҫ const char*
		}
	}

	MoveGoodsService service;
	auto res = service.getDownLoadById(ids_str);
	WriteToXlsx(export_path, res);

	auto fstring = String::loadFromFile(export_path.c_str());
	if (!fstring) {
		std::cerr << "Failed to open file: " << std::strerror(errno) << std::endl;
		return createResponse(Status::CODE_404, "File Not Found");
	}

	auto response = createResponse(Status::CODE_200, fstring);
	response->putHeader("Content-Disposition", "attachment; filename=" + filename);
	return response;
}

StringJsonVO::Wrapper MoveGoodsController::execBatchRemoveMoveGoods(const String& id,const PayloadDTO& payload)
{
	// ���巵�����ݶ���
	auto jvo = StringJsonVO::createShared();
	// ����У��
	vector<string> ids_str;
	string idsStr = id->c_str();
	if (!idsStr.empty()) {
		std::stringstream ss(idsStr.c_str());
		std::string item;
		while (std::getline(ss, item, ',')) {  // ���ŷָ�
			ids_str.push_back(item.c_str());  // oatpp::String ��Ҫ const char*
		}
	}

	//��ȡ��ǰ�û�����
	std::string usrName = payload.getUsername();

	// ����һ��Service
	MoveGoodsService service;
	// ִ������ɾ��
	if (service.removeMoveGoods(ids_str,usrName)) {
		jvo->success(id);
	}
	else
	{
		jvo->fail(id);
	}
	// ��Ӧ���
	return jvo;
}