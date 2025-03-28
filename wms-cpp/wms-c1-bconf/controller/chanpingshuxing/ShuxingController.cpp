#include "stdafx.h"
#include "ShuxingController.h"


StringJsonVO::Wrapper ShuxingController::XiugaiShuxing(const ShuxingDTO::Wrapper& dto,const PayloadDTO& payload)
{
    auto ans = StringJsonVO::createShared();
    //判断参数是否合法
    if (  !dto->goods_type_code || !dto->goods_type_name) {
        ans->init(ZH_WORDS_GETTER("shuxing.xiugaishibai"), RS_PARAMS_INVALID);
        return ans;
    }
    if ( 
         !dto->goods_type_code->size() || !dto->goods_type_name->size()) {
        
        ans->init(ZH_WORDS_GETTER("shuxing.xiugaishibai"), RS_PARAMS_INVALID);
        return ans;
    }
     
    ShuxingService service;
    auto id = service.modify_data(dto,payload);
    if (id) {
        ans->success(ZH_WORDS_GETTER("shuxing.xiugaichenggong"));
    }
    else {
        ans->fail(ZH_WORDS_GETTER("shuxing.xiugaishibai"));
    }
    return ans;

}

StringJsonVO::Wrapper ShuxingController::ShanchuShuxing(const ShuxingShanChuDTO::Wrapper& dto)
{
    auto ans = StringJsonVO::createShared();
     //空值检查
    if(!dto->ids || !dto->ids->size()){
        ans->init(ZH_WORDS_GETTER("shuxing.shanchushibai"), RS_PARAMS_INVALID);
        return ans;
    }
    ShuxingService service;
    auto id = service.delete_data(dto);
    if (id) {
        ans->success(ZH_WORDS_GETTER("shuxing.shanchuchenggong"));
    }
    else {
        ans->fail(ZH_WORDS_GETTER("shuxing.shanchushibai"));
    }
    return ans;
}
#define TEST_EXCEL_FN "_ba_goods_types.xlsx"
#define TEST_EXCEL_SN ZH_WORDS_GETTER("shuxing.excel")
std::shared_ptr<oatpp::web::server::api::ApiController::OutgoingResponse> ShuxingController::DaochuShuxing( )
{
    ShuxingService service;
    auto ans =service.upload_data();
    vector<vector<string>>data;
     
    data.push_back({ ZH_WORDS_GETTER("shuxing.daochu.lieming1"),
        ZH_WORDS_GETTER("shuxing.daochu.lieming2") });
    for (auto& i : ans) {
        data.push_back({ i[0],i[1] });
    }
    std::string fileName = TEST_EXCEL_FN;
    // 注意：因为xlnt不能存储非utf8编码的字符，所以中文字需要从配置文件中获取
    std::string sheetName = TEST_EXCEL_SN;

    // 保存到文件
    ExcelComponent excel;
    //excel.writeVectorToFile(fileName, sheetName, data);
    auto buff=excel.writeVectorToBuff(sheetName, data);
    const char* tsdata = reinterpret_cast<const char*>(buff.data());
    String fstring = String(tsdata, buff.size());

    if (!fstring)
    {
        std::cerr << "Failed to open file: " << std::strerror(errno) << std::endl;
        return createResponse(Status::CODE_404, "File Not Found");
    }

    // 创建响应头
    auto response = createResponse(Status::CODE_200, fstring);

    // 设置响应头信息
    response->putHeader("Content-Disposition",
        "attachment; filename=" + fileName);

    // 影响成功结果
    return response;
}

StringJsonVO::Wrapper ShuxingController::DaoruShuxing(std::shared_ptr<IncomingRequest> request, const PayloadDTO& payload)
{


    // 1 初始化
    API_MULTIPART_INIT(container, reader);
    // 2 配置读取器
    API_MULTIPART_CONFIG_MEMO_DEFAULT(reader, -1);
    // 3 读取数据
    request->transferBody(&reader);
    //4获取数据
    /*API_MULTIPART_PARSE_FORM_FIELD_STR(container, "create_name", create_name);
    API_MULTIPART_PARSE_FORM_FIELD_STR(container, "create_by", create_by);*/
   /* API_MULTIPART_PARSE_FORM_FIELD_STR(container, "sys_org_code", sys_org_code);
    API_MULTIPART_PARSE_FORM_FIELD_STR(container, "sys_company_code", sys_company_code);*/
    String create_name = String(payload.getUsername().c_str());
    String create_by = String(payload.getId().c_str());
    String sys_org_code = String(payload.getOrgcode().c_str());
    String sys_company_code = String(payload.getCompanycode().c_str());
    API_MULTIPART_PARSE_FORM_FIELD_STR(container, "sheet_name", sheet_name);
    API_MULTIPART_PARSE_FILE_FIELD(container, "file", file);
    auto jvo = StringJsonVO::createShared();
    if (!file->size()|| !create_name->size() || !sys_org_code->size() 
        || !sys_company_code->size() || !create_by->size()||!sheet_name->size())
    {
        jvo->fail("cuowu");
 
    }
    else {
       
        ShuxingDaoruDTO dto;
        dto.create_name = create_name;
        dto.create_by = create_by;
        dto.sys_org_code = sys_org_code;
        dto.sys_company_code = sys_company_code;
        dto.sheet_name = sheet_name;
        dto.file = file;
        ShuxingService service;
        if (service.load_data(dto)) {
            jvo->success(ZH_WORDS_GETTER("shuxing.daoruchenggong"));
        }
        else {
            jvo->fail(ZH_WORDS_GETTER("shuxing.daorushibai"));
        }
    }
    
    return jvo;
}


