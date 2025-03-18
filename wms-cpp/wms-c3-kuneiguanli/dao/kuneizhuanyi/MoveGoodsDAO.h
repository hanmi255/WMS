#pragma once
<<<<<<< HEAD

#include "BaseDAO.h"
#include "domain/do/kuneizhuanyi/MoveGoodsDO.h"
#include "domain/query/kuneizhuanyi/MoveGoodsQuery.h"

class MoveGoodsDAO : public BaseDAO {
private:
	/**
	 * @brief ��ѯ����������
	 * @param query ��ѯ����
	 * @param params SQL����
	 * @return ��ѯ����SQL���
	 * @note �÷������ڹ����ѯ����SQL��䣬����������䵽SQL�����б���
	 */
	inline std::string queryConditionBuilder(const MoveGoodsQuery::Wrapper& query, SqlParams& params);

public:
	// ͳ����������
	uint64_t count(const MoveGoodsQuery::Wrapper& query);

	// ��ҳ��ѯת������
	std::list<MoveGoodsDO> selectWithPage(const MoveGoodsQuery::Wrapper& query);

	// �޸�ת������
	std::string updateMoveGoods(const MoveGoodsDO& moveGoods);

	// ����ת������
	std::string updateMoveGoodsBatch(const std::vector<MoveGoodsDO>& moveGoodsList);
};
=======
#ifndef _MOVEGOODS_DAO_
#define _MOVEGOODS_DAO_
#include "BaseDAO.h"
#include "../../domain/do/MoveGoodsDO.h"
#include "../../domain/query/kuneizhuanyi/MoveGoodsQuery.h"


class MoveGoodsDAO : public BaseDAO
{
private:
	//************************************
	// Method:      queryConditionBuilder
	// FullName:    SampleDAO::queryConditionBuilder
	// Access:      private 
	// Returns:     std::string ��������SQL��䣬��WHERE���ֵ����
	// Parameter:   const SampleQuery::Wrapper& query ��ѯ���ݶ���
	// Parameter:   SqlParams& params ��Ų�ѯ���ݵĲ�������
	// Description: ��ѯ����������������SampleQuery����̬������ѯ������ز���
	//************************************
	inline std::string queryConditionBuilder(const MoveGoodsQuery::Wrapper& query, SqlParams& params);
public:
	// ͨ��ID��ѯת��������ϸ����
	PtrMoveGoodsDO selectDetailedById(const oatpp::String  queryID);
	// ͨ��ID��ѯת�����񵼳�����
	std::vector<std::vector<string>> selectDownLoadById(const vector<string>& ids);
	// ͨ��IDɾ������
	int deleteById(const vector<string> id,const string usrName);
};
#endif // !_MOVEGOODS_DAO_
>>>>>>> 05f7ec7fb45d4bc1f52eea780440c95f076c61f0
