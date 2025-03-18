#pragma once
#ifndef _CANGKUNAMELIST_MAPPER_H_
#define _CANGKUNAMELIST_MAPPER_H_

#include "Mapper.h"
#include "../../domain/do/StoreDO.h"

class CangkuNameListMapper : public Mapper<StoreDO> {
public:
	StoreDO mapper(ResultSet* result) const override {
		StoreDO data;
		data.setId(result->getString(1));
		data.setStoreCode(result->getString(2));
		data.setStoreName(result->getString(3));
		
		return data;
	}
};

class CangkuBaseInfoMapper : public Mapper<StoreDO> {
public:
	StoreDO mapper(ResultSet* result) const override {
		StoreDO data;
		data.setStoreCode(result->getString(1));
		data.setStoreName(result->getString(2));
		data.setStoreText(result->getString(3));
		return data;
	}
};

#endif // !_CANGKUNAMELIST_MAPPER_H_
