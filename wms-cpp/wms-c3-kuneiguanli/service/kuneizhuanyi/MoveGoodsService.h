<<<<<<< HEAD
#pragma once

=======

#pragma once
#ifndef _MOVEGOODS_SERVICE_
#define _MOVEGOODS_SERVICE_
>>>>>>> 05f7ec7fb45d4bc1f52eea780440c95f076c61f0
#include <list>
#include "domain/vo/kuneizhuanyi/MoveGoodsVO.h"
#include "domain/query/kuneizhuanyi/MoveGoodsQuery.h"
#include "domain/dto/kuneizhuanyi/MoveGoodsDTO.h"

<<<<<<< HEAD
class MoveGoodsService {
public:
	// ��ҳ��ȡת����������
	MoveGoodsPageDTO::Wrapper listMoveGoodsPage(const MoveGoodsQuery::Wrapper& query);

	// �޸�ת������
	std::string updateMoveGoods(const MoveGoodsModifyDTO::Wrapper& dto, const PayloadDTO& payload);

	// ����ת������
	std::string updateMoveGoodsBatch(const MoveGoodsBatchModifyDTO::Wrapper& dto, const PayloadDTO& payload);
};
=======
/**
 * ʾ������ʵ�֣���ʾ������ʾ������ʵ��
 */
class MoveGoodsService
{
public:
	
	// ͨ��ID��ѯ��ϸת��������Ϣ
	MoveGoodsDetailedDTO::Wrapper getDetailedById(const oatpp::String queryID);
	// ͨ��IDɾ������
	bool removeMoveGoods(const vector<string> id,const string usrName);
	// ͨ��ID��ѯ����ת��������Ϣ
	vector<vector<string>> getDownLoadById(const vector<string>& ids);
};

#endif // !_MOVEGOODS_SERVICE_
>>>>>>> 05f7ec7fb45d4bc1f52eea780440c95f076c61f0
