//#pragma once
//#ifndef _ROW_LIST_DTO_
//#define _ROW_LIST_DTO_
//#include "oatpp/core/macro/codegen.hpp"
//#include "oatpp/core/Types.hpp"
//
//#include OATPP_CODEGEN_BEGIN(DTO)
//
///**
// * 仅包含数据列表的实体
// */
//template <class T>
//class RowListDTO : public oatpp::DTO
//{
//    // 初始化
//    DTO_INIT(RowListDTO, DTO);
//
//    /**
//     * 数据列表
//     */
//    DTO_FIELD(List<T>, rows) = {};
//    DTO_FIELD_INFO(rows) {
//#ifndef LINUX
//        info->description = u8"数据列表";
//#else
//        info->description = "data list";
//#endif
//    }
//
//public:
//    // 添加一条数据
//    void addData(T one) {
//        this->rows->push_back(one);
//    }
//};
//
//#include OATPP_CODEGEN_END(DTO)
//#endif // !_ROW_LIST_DTO_