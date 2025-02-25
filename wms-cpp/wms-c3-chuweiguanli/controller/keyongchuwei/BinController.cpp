#include "stdafx.h"
#include "BinController.h"
#include "service/keyongchuwei/BinService.h"
#include "ExcelComponent.h"

void WriteToXlsx(string fileName,vector<vector<string>> data) {
	std::string sheetName = ZH_WORDS_GETTER("bin.xlsx.sheet.s1");  // 获取表名

	// 创建 Excel 工作簿
	xlnt::workbook wb;
	xlnt::worksheet ws = wb.active_sheet();
	ws.title(sheetName);

	// 将数据写入 Excel
	for (size_t row = 0; row < data.size(); ++row) {
		for (size_t col = 0; col < data[row].size(); ++col) {
			ws.cell(static_cast<int>(col + 1), static_cast<int>(row + 1)).value(data[row][col]);
		}
	}

	// 保存 Excel 文件
	try {
		wb.save(fileName);
	}
	catch (const std::exception& e) {
		std::cerr << "Error saving Excel file: " << e.what() << std::endl;
	}
}

std::shared_ptr<oatpp::web::server::api::ApiController::OutgoingResponse> BinController::execExportBinXlsx(const BinExcelQuery::Wrapper& ids) {
	//return {};
	//auto export_path = ids.get()->file_path->c_str() + ZH_WORDS_GETTER("bin.xlsx.filename");
	string filename{ "usefulBins.xlsx" };
	auto export_path = ids.get()->file_path->c_str() + filename;
	vector<string> ids_str;
	string idsStr = ids.get()->ids->c_str();
	if (!idsStr.empty()) {
		std::stringstream ss(idsStr.c_str());
		std::string item;
		while (std::getline(ss, item, ',')) {  // 逗号分隔
			ids_str.push_back(item.c_str());  // oatpp::String 需要 const char*
		}
	}

	BinService service;
	auto res = service.querybyids(ids_str);
	WriteToXlsx(export_path,res);

	auto fstring = String::loadFromFile(export_path.c_str());
	if (!fstring) {
		std::cerr << "Failed to open file: " << std::strerror(errno) << std::endl;
		return createResponse(Status::CODE_404, "File Not Found");
	}

	auto response = createResponse(Status::CODE_200, fstring);
	response->putHeader("Content-Disposition", "attachment; filename=" + filename);
	return response;
}

BinPageJsonVO::Wrapper BinController::execQueryBinList(const BinPageQuery::Wrapper& query) {
	BinService service;
	auto res = service.querylist(query);
	auto jvo = BinPageJsonVO::createShared();
	jvo->success(res);
	return jvo;
}