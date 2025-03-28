#include "ExpirationDateEarlyWarningDAO.h"

#include "ExpirationDateEarlyWarningMapper.h"
#include "stdafx.h"
#include "sstream"

uint64_t ExpirationDateEarlyWarningDAO::count(const ExpirationDateEarlyWarningQuery::Wrapper& query) {
	stringstream ss;
	ss << "SELECT COUNT(*) FROM mv_stock_yj WHERE 1=1";
	if (query->customercode) {
		ss << " AND cus_code=" << string(query->customercode);
	}
	if (query->customername) {
		ss << " AND zhong_wen_qch=" << string(query->customername);
	}
	if (query->customerproductcode) {
		ss << " AND ku_wei_bian_ma=" << string(query->customerproductcode);
	}
	if (query->expirationdate) {
		ss << " AND dqr=" << string(query->expirationdate);
	}
	if (query->productcode) {
		ss << " AND goods_id=" << string(query->productcode);
	}
	if (query->productiondate) {
		ss << " AND goods_pro_data=" << string(query->productiondate);
	}
	if (query->productname) {
		ss << " AND shp_ming_cheng=" << string(query->productname);
	}
	if (query->Thelowervalueoftheremainingratio) {
		ss << " AND guoqibili>" << string(query->Thelowervalueoftheremainingratio);
	}
	if (query->Theuppervalueoftheremainingratio) {
		ss << " AND guoqibili<" << string(query->Theuppervalueoftheremainingratio);
	}
	return sqlSession->executeQueryNumerical(ss.str());
}

std::list<StockYJDO> ExpirationDateEarlyWarningDAO::selectWithPage(const ExpirationDateEarlyWarningQuery::Wrapper& query) {
	stringstream ss;
	ss << "SELECT id,kuctype,goods_id,ku_wei_bian_ma,shp_ming_cheng,\
		base_goodscount,base_unit,cus_code,goods_pro_data,bzhi_qi,\
		dqr,res_date,guoqibili,zhong_wen_qch FROM mv_stock_yj where 1=1";
	if (query->customercode) {
		ss << " AND cus_code=" << string(query->customercode);
	}
	if (query->customername) {
		ss << " AND zhong_wen_qch=" << string(query->customername);
	}
	if (query->customerproductcode) {
		ss << " AND ku_wei_bian_ma=" << string(query->customerproductcode);
	}
	if (query->expirationdate) {
		ss << " AND dqr=" << string(query->expirationdate);
	}
	if (query->productcode) {
		ss << " AND goods_id=" << string(query->productcode);
	}
	if (query->productiondate) {
		ss << " AND goods_pro_data=" << string(query->productiondate);
	}
	if (query->productname) {
		ss << " AND shp_ming_cheng=" << string(query->productname);
	}
	if (query->Thelowervalueoftheremainingratio) {
		ss << " AND guoqibili>" << string(query->Thelowervalueoftheremainingratio);
	}
	if (query->Theuppervalueoftheremainingratio) {
		ss << " AND guoqibili<" << string(query->Theuppervalueoftheremainingratio);
	}
	ss << " LIMIT " << std::to_string(((query->pageIndex - 1) * query->pageSize)) + "," + std::to_string(query->pageSize);
	ExpirationDateEarlyWarningMapper mapper;
	return sqlSession->executeQuery<StockYJDO>(ss.str(), mapper);
}