#include "BinDAO.h"
#include <sstream>
#include "dao/keyongchuwei/BinMapper.h"

inline std::string BinDAO::queryConditionBuilder(const BinPageQuery::Wrapper& query, SqlParams& params)
{
	//return std::string();
	stringstream sqlCondition;
	sqlCondition << " WHERE 1=1";
	if (query->bin_store)
	{
		sqlCondition << " AND `bin_store`=?";
		SQLPARAMS_PUSH(params, "s", std::string, query->bin_store.getValue(""));
	}
	if (query->ku_wei_shu_xing)
	{
		sqlCondition << " AND ku_wei_shu_xing=?";
		SQLPARAMS_PUSH(params, "s", std::string, query->ku_wei_shu_xing.getValue(""));
	}
	if (query->ku_wei_bian_ma)
	{
		sqlCondition << " AND ku_wei_bian_ma=?";
		SQLPARAMS_PUSH(params, "s", std::string, query->ku_wei_bian_ma.getValue(""));
	}
	if (query->suo_shu_ke_hu)
	{
		sqlCondition << " AND suo_shu_ke_hu=?";
		SQLPARAMS_PUSH(params, "s", std::string, query->suo_shu_ke_hu.getValue(""));
	}
	if (query->shang_jia_ci_xu)
	{
		sqlCondition << " AND shang_jia_ci_xu=?";
		SQLPARAMS_PUSH(params, "s", std::string, query->shang_jia_ci_xu.getValue(""));
	}
	if (query->gao)
	{
		sqlCondition << " AND gao=?";
		SQLPARAMS_PUSH(params, "s", std::string, query->gao.getValue(""));
	}
	sqlCondition << " AND bin_store <>''";
	sqlCondition << " AND ku_wei_shu_xing <>''";
	sqlCondition << " AND ku_wei_bian_ma <>''";
	sqlCondition << " AND suo_shu_ke_hu <>''";
	sqlCondition << " AND shang_jia_ci_xu <>''";
	sqlCondition << " AND gao <>''";

	sqlCondition << " AND ting_yong=?";
	SQLPARAMS_PUSH(params, "s", std::string, "N");
	return sqlCondition.str();
}

std::list<BinDO> BinDAO::selectWithPage(const BinPageQuery::Wrapper& query)
{
	//return std::list<BinDO>();
	SqlParams params;
	string sql = "SELECT id,bin_store,ku_wei_shu_xing,ku_wei_bian_ma,suo_shu_ke_hu,zui_da_ti_ji,shang_jia_ci_xu,chang,kuan,gao,zui_da_tuo_pan FROM md_bin ";
	sql += queryConditionBuilder(query, params);
	sql += " LIMIT " + std::to_string(((query->pageIndex - 1) * query->pageSize)) + "," + std::to_string(query->pageSize);
	BinMapper mapper;
	return sqlSession->executeQuery<BinDO>(sql, mapper, params);
}

uint64_t BinDAO::count(const BinPageQuery::Wrapper& query)
{
	SqlParams params;
	string sql = "SELECT COUNT(*) FROM md_bin ";
	sql += queryConditionBuilder(query, params);
	return sqlSession->executeQueryNumerical(sql, params);
}

std::vector<std::vector<string>> BinDAO::selectByIds(const vector<string>& ids)
{
	//return std::vector<std::vector<string>>();
	SqlParams params;
	string sql = "SELECT bin_store,ku_wei_shu_xing,ku_wei_bian_ma,suo_shu_ke_hu,zui_da_ti_ji,shang_jia_ci_xu,chang,kuan,gao,zui_da_tuo_pan FROM md_bin WHERE id IN (";
	for (size_t i = 0; i < ids.size(); i++)
	{
		sql += "?";
		if (i < ids.size() - 1)
		{
			sql += ",";
		}
		SQLPARAMS_PUSH(params, "s", std::string, ids[i]);
	}
	sql += ")";
	BinFileMapper mapper;
	auto list = sqlSession->executeQuery<BinDO>(sql, mapper, params);
	std::vector<std::vector<string>> res;
	std::vector<string> sub;
	sub.push_back(ZH_WORDS_GETTER("bin.bin_store"));
	sub.push_back(ZH_WORDS_GETTER("bin.ku_wei_shu_xing"));
	sub.push_back(ZH_WORDS_GETTER("bin.ku_wei_bian_ma"));
	sub.push_back(ZH_WORDS_GETTER("bin.suo_shu_ke_hu"));
	sub.push_back(ZH_WORDS_GETTER("bin.zui_da_ti_ji"));
	sub.push_back(ZH_WORDS_GETTER("bin.shang_jia_ci_xu"));
	sub.push_back(ZH_WORDS_GETTER("bin.chang"));
	sub.push_back(ZH_WORDS_GETTER("bin.kuan"));
	sub.push_back(ZH_WORDS_GETTER("bin.gao"));
	sub.push_back(ZH_WORDS_GETTER("bin.zui_da_tuo_pan"));
	res.push_back(sub);
	for (auto& item : list)
	{
		std::vector<string> sub;
		sub.push_back(item.getBinStore());
		sub.push_back(item.getKuWeiShuXing());
		sub.push_back(item.getKuWeiBianMa());
		sub.push_back(item.getSuoShuKeHu());
		sub.push_back(item.getZuiDaTiJi());
		sub.push_back(item.getShangJiaCiXu());
		sub.push_back(item.getChang());
		sub.push_back(item.getKuan());
		sub.push_back(item.getGao());
		sub.push_back(item.getZuiDaTuoPan());
		res.push_back(sub);
	}
	return res;
}
