#include "stdafx.h"
#include "xiangxixinxiDAO.h"
#include "xaingxixinxiMAPPER.h"
#include <sstream>
#include "id/UuidFacade.h"

//当前日期时间函数
std::string getCurrentDateTime() {
	// 获取当前时间点
	auto now = std::chrono::system_clock::now();
	// 将时间点转换为时间_t类型
	std::time_t currentTime = std::chrono::system_clock::to_time_t(now);
	// 将时间_t类型转换为tm结构体
	std::tm* localTime = std::localtime(&currentTime);

	// 创建一个字符串流对象
	std::ostringstream oss;
	// 设置输出格式
	oss << std::put_time(localTime, "%Y-%m-%d %H:%M:%S");

	// 返回格式化后的字符串
	return oss.str();
}


std::string xiangxixinxiDAO::xiangxixinxiqueryConditionBuilder(const  xiangxixinxiQUERY::Wrapper& query, SqlParams& params)
{
	stringstream sqlCondition;
	sqlCondition << " WHERE 1=1";
	if (query->weiyiid) {

		sqlCondition << " AND `id`=?";
		SQLPARAMS_PUSH(params, "s", std::string, query->weiyiid.getValue(""));  
	}

	return sqlCondition.str();
}


// 通过ID查询数据
std::shared_ptr<BinDO> xiangxixinxiDAO::idchaxun(const xiangxixinxiQUERY::Wrapper& id)
{
	SqlParams params;
	string sql = "SELECT * FROM md_bin";
	sql += xiangxixinxiqueryConditionBuilder(id, params);
	ptrxiangxixinxiMapper mapper;
	return sqlSession->executeQueryOne<std::shared_ptr<BinDO>>(sql, mapper, params);

}



//	单个ID获取一个表单数据
std::vector<string> xiangxixinxiDAO::getdataone(string store_code)
{
	std::vector<string> result;
	stringstream sql;

	sql << "SELECT * FROM md_bin  WHERE id = '" << store_code << "'";
	xiangxixinxiMapper mapper;
	string sql_str = sql.str();
	std::list<BinDO> sql_result = sqlSession->executeQuery<BinDO>(sql_str, mapper);

	if (sql_result.empty())
		return result;

	result.push_back(sql_result.begin()->getBinStore());//仓库
	result.push_back(sql_result.begin()->getKuWeiBianMa());
	result.push_back(sql_result.begin()->getKuWeiTiaoMa());
	result.push_back(sql_result.begin()->getKuWeiLeiXing());
	result.push_back(sql_result.begin()->getKuWeiShuXing());
	result.push_back(sql_result.begin()->getCHPShuXing());//产品属性
	result.push_back(sql_result.begin()->getShangJiaCiXu());
	result.push_back(sql_result.begin()->getQuHuoCiXu());
	result.push_back(sql_result.begin()->getSuoShuKeHu());
	result.push_back(sql_result.begin()->getZuiDaMianJi());//最大面积
	result.push_back(sql_result.begin()->getTiJiDanWei());//体积单位
	result.push_back(sql_result.begin()->getZhongLiangDanWei());
	result.push_back(sql_result.begin()->getMianJiDanWei());//面积单位
	result.push_back(sql_result.begin()->getZuiDaTiJi());
	result.push_back(sql_result.begin()->getZuiDaZhongLiang());
	result.push_back(sql_result.begin()->getZuiDaTuoPan());
	result.push_back(sql_result.begin()->getChang());
	result.push_back(sql_result.begin()->getKuan());
	result.push_back(sql_result.begin()->getGao());
	result.push_back(sql_result.begin()->getTingYong());
	result.push_back(sql_result.begin()->getMingXi());//备注
	result.push_back(sql_result.begin()->getMingXi1());
	result.push_back(sql_result.begin()->getMingXi2());
	result.push_back(sql_result.begin()->getMingXi3());//动线
	result.push_back(sql_result.begin()->getLORABqid());//ID
	result.push_back(sql_result.begin()->getXNode());
	result.push_back(sql_result.begin()->getYNode());
	result.push_back(sql_result.begin()->getZNode());

	return result;
}

//	获取所有表单数据
std::vector<std::vector<std::string>> xiangxixinxiDAO::getdataall()
{
	std::vector<std::vector<std::string>> result;
	std::vector<std::string> header;
	header.insert(header.end(), { ZH_WORDS_GETTER("chuweixiangxixinxi.xinxi.cangku"),ZH_WORDS_GETTER("chuweixiangxixinxi.xinxi.bianma"), ZH_WORDS_GETTER("chuweixiangxixinxi.xinxi.tiaoma"), ZH_WORDS_GETTER("chuweixiangxixinxi.xinxi.leixing"),ZH_WORDS_GETTER("chuweixiangxixinxi.xinxi.shuxing"),    ZH_WORDS_GETTER("chuweixiangxixinxi.xinxi.chanpinshuxing"),        ZH_WORDS_GETTER("chuweixiangxixinxi.xinxi.shangjiacixu"),ZH_WORDS_GETTER("chuweixiangxixinxi.xinxi.quhuocixu"),ZH_WORDS_GETTER("chuweixiangxixinxi.xinxi.kehu"),   ZH_WORDS_GETTER("chuweixiangxixinxi.xinxi.zuidamianji"),   ZH_WORDS_GETTER("chuweixiangxixinxi.xinxi.tiji") });
	header.insert(header.end(), { ZH_WORDS_GETTER("chuweixiangxixinxi.xinxi.zhongliang"),ZH_WORDS_GETTER("chuweixiangxixinxi.xinxi.mianji"),ZH_WORDS_GETTER("chuweixiangxixinxi.xinxi.zuidatiji"),ZH_WORDS_GETTER("chuweixiangxixinxi.xinxi.zuidazhongliang"),ZH_WORDS_GETTER("chuweixiangxixinxi.xinxi.zuidatuopan"),ZH_WORDS_GETTER("chuweixiangxixinxi.xinxi.chang"),ZH_WORDS_GETTER("chuweixiangxixinxi.xinxi.kuan"),ZH_WORDS_GETTER("chuweixiangxixinxi.xinxi.gao") });
	header.insert(header.end(), { ZH_WORDS_GETTER("chuweixiangxixinxi.xinxi.tingyong"),ZH_WORDS_GETTER("chuweixiangxixinxi.xinxi.beizu"),ZH_WORDS_GETTER("chuweixiangxixinxi.xinxi.beizu1"),ZH_WORDS_GETTER("chuweixiangxixinxi.xinxi.beizhu2"),ZH_WORDS_GETTER("chuweixiangxixinxi.xinxi.dongxian"),ZH_WORDS_GETTER("chuweixiangxixinxi.xinxi.ID"),ZH_WORDS_GETTER("chuweixiangxixinxi.xinxi.x"),ZH_WORDS_GETTER("chuweixiangxixinxi.xinxi.y"),ZH_WORDS_GETTER("chuweixiangxixinxi.xinxi.z") });
	result.push_back(header);
	stringstream sql;
	sql << "SELECT  * FROM md_bin ";

	xiangxixinxiMapper mapper;
	string sql_str = sql.str();
	auto sql_result = sqlSession->executeQuery<BinDO>(sql_str, mapper);

	for (auto& item : sql_result) {
		std::vector<std::string> row;
		row.push_back(item.getBinStore());//仓库
		row.push_back(item.getKuWeiBianMa());
		row.push_back(item.getKuWeiTiaoMa());
		row.push_back(item.getKuWeiLeiXing());
		row.push_back(item.getKuWeiShuXing());
		row.push_back(item.getCHPShuXing());//产品属性
		row.push_back(item.getShangJiaCiXu());
		row.push_back(item.getQuHuoCiXu());
		row.push_back(item.getSuoShuKeHu());
		row.push_back(item.getZuiDaMianJi());//最大面积
		row.push_back(item.getTiJiDanWei());//体积单位
		row.push_back(item.getZhongLiangDanWei());
		row.push_back(item.getMianJiDanWei());//面积单位
		row.push_back(item.getZuiDaTiJi());
		row.push_back(item.getZuiDaZhongLiang());
		row.push_back(item.getZuiDaTuoPan());
		row.push_back(item.getChang());
		row.push_back(item.getKuan());
		row.push_back(item.getGao());
		row.push_back(item.getTingYong());
		row.push_back(item.getMingXi());//备注
		row.push_back(item.getMingXi1());
		row.push_back(item.getMingXi2());
		row.push_back(item.getMingXi3());//动线
		row.push_back(item.getLORABqid());//ID
		row.push_back(item.getXNode());
		row.push_back(item.getYNode());
		row.push_back(item.getZNode());

		result.emplace_back(row);
	}

	return result;

}


//导入储位
std::string xiangxixinxiDAO::addchuweiDAO(const BinDO& bindo, const PayloadDTO& payload)
{

	// 创建生成器
	UuidFacade ufid(1);

	// 生产长32的ID
	std::string ids = ufid.genUuid();
	string::iterator it;     //指向string类的迭代器。你可以理解为指针

	int i = 0;
	for (it = ids.begin(); it != ids.end(); it++)
	{
		
		if (*it == '-')
		{
			ids.erase(i,1);          //删除it处的一个字符
		}
		i++;
	}
	
	

	//创建时间
	string sql_time = getCurrentDateTime();


	SqlParams params;
	//33
	string sql = "INSERT INTO md_bin (id, create_name , create_by , create_date, sys_org_code ,sys_company_code ,\
		ku_wei_bian_ma , ku_wei_tiao_ma , ku_wei_lei_xing , ku_wei_shu_xing , shang_jia_ci_xu , qu_huo_ci_xu ,\
	    suo_shu_ke_hu , ti_ji_dan_wei , zhong_liang_dan_wei , mian_ji_dan_wei , zui_da_ti_ji , zui_da_zhong_liang , \
		zui_da_mian_ji , zui_da_tuo_pan , chang , kuan , gao , ting_yong ,\
		ming_xi , CHP_SHU_XING , ming_xi1 , ming_xi2 , ming_xi3 , LORA_bqid , xnode , ynode , znode ) VALUES (?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?)";
	UuidFacade uf;
	auto id = uf.genUuid();
	auto result = sqlSession->executeUpdate(sql, "%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s", \
		ids, payload.getUsername() , payload.getRealname(), sql_time ,payload.getOrgcode(),payload.getCompanycode(), \
		bindo.getKuWeiBianMa(), bindo.getKuWeiTiaoMa(), bindo.getKuWeiLeiXing(), bindo.getKuWeiShuXing(), bindo.getShangJiaCiXu(), bindo.getQuHuoCiXu(), \
		bindo.getSuoShuKeHu() , bindo.getTiJiDanWei(),bindo.getZhongLiangDanWei(), bindo.getMianJiDanWei(), bindo.getZuiDaTiJi(), bindo.getZuiDaZhongLiang(), \
		bindo.getZuiDaMianJi(), bindo.getZuiDaTuoPan(), bindo.getChang(), bindo.getKuan(), bindo.getGao(), bindo.getTingYong(),\
		bindo.getMingXi(),  bindo.getCHPShuXing(), bindo.getMingXi1(), bindo.getMingXi2(), bindo.getMingXi3(), bindo.getLORABqid(), \
		bindo.getXNode(), bindo.getYNode(), bindo.getZNode());
	if (result == -1) {
		return "";
	}
	return id;
	
}


