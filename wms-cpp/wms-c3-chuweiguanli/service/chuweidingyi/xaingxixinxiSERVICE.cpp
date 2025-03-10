#include "stdafx.h"
#include "xaingxixinxiSERVICE.h"
#include "../../dao/chuweidingyi/xiangxixinxiDAO.h"
#include "../../../lib-common/include/ExcelComponent.h"
#include "../../../lib-common/include/FastDfsClient.h"
#include "../../../lib-common/include/NacosClient.h"
#include "../../Macros.h"

xiangxixinxiDTO::Wrapper xiangxixinxiSERVICE::getById(const xiangxixinxiQUERY::Wrapper& id)
{
	 //查询数据
	xiangxixinxiDAO dao;
	auto res = dao.idchaxun(id);

	// 没有查询到数据 
	if (!res) {
		cout << "没有查询到数据" << endl;
		return nullptr;
	}
	// 查询到数据转换成DTO
	auto dto = xiangxixinxiDTO::createShared();
	//dto,do
	ZO_STAR_DOMAIN_DO_TO_DTO_1(dto, res, cangku, KuWeiMingCheng, kehu, SuoShuKeHu, bianma, KuWeiBianMa, tiaoma, KuWeiTiaoMa, leixing, KuWeiLeiXing, shuxing, KuWeiShuXing, chanpinshuxing, CHPShuXing, shangjiacixu, ShangJiaCiXu, quhuocixu, QuHuoCiXu);
	ZO_STAR_DOMAIN_DO_TO_DTO_1(dto, res, zuidazhongliang, ZuiDaZhongLiang, zuidatuopan, ZuiDaTuoPan, chang, Chang, kuan, Kuan, gao, Gao, tingyong, TingYong, zuidatiji,ZuiDaTiJi,beizhu, MingXi, beizhu1, MingXi1, beizhu2, MingXi2, dongxian, MingXi3);
	ZO_STAR_DOMAIN_DO_TO_DTO_1(dto, res, ID, LORABqid, x, XNode, y, YNode, z, ZNode, tiji, TiJiDanWei, zhongliang, ZhongLiangDanWei, mianji, MianJiDanWei, zuidamianji, ZuiDaMianJi);
	return dto;

}


//	通过储位id列表导出仓库信息,返回下载链接
string xiangxixinxiSERVICE::daochuchuweiCONTROLLER(oatpp::List<oatpp::String>& chuwei) {

	ExcelComponent excel;
	xiangxixinxiDAO dao;

	//	根据仓库ID读取所需数据
	std::vector<std::vector<std::string>> data;
	if (chuwei->empty()) {
		data = dao.getdataall();
	}
	else {
		std::vector<std::string> header;
		header.insert(header.end(), { ZH_WORDS_GETTER("chuweixiangxixinxi.xinxi.cangku"),ZH_WORDS_GETTER("chuweixiangxixinxi.xinxi.bianma"), ZH_WORDS_GETTER("chuweixiangxixinxi.xinxi.tiaoma"), ZH_WORDS_GETTER("chuweixiangxixinxi.xinxi.leixing"),ZH_WORDS_GETTER("chuweixiangxixinxi.xinxi.shuxing"),    ZH_WORDS_GETTER("chuweixiangxixinxi.xinxi.chanpinshuxing"),        ZH_WORDS_GETTER("chuweixiangxixinxi.xinxi.shangjiacixu"),ZH_WORDS_GETTER("chuweixiangxixinxi.xinxi.quhuocixu"),ZH_WORDS_GETTER("chuweixiangxixinxi.xinxi.kehu"),   ZH_WORDS_GETTER("chuweixiangxixinxi.xinxi.zuidamianji"),   ZH_WORDS_GETTER("chuweixiangxixinxi.xinxi.tiji") });
		header.insert(header.end(), { ZH_WORDS_GETTER("chuweixiangxixinxi.xinxi.zhongliang"),ZH_WORDS_GETTER("chuweixiangxixinxi.xinxi.mianji"),ZH_WORDS_GETTER("chuweixiangxixinxi.xinxi.zuidatiji"),ZH_WORDS_GETTER("chuweixiangxixinxi.xinxi.zuidazhongliang"),ZH_WORDS_GETTER("chuweixiangxixinxi.xinxi.zuidatuopan"),ZH_WORDS_GETTER("chuweixiangxixinxi.xinxi.chang"),ZH_WORDS_GETTER("chuweixiangxixinxi.xinxi.kuan"),ZH_WORDS_GETTER("chuweixiangxixinxi.xinxi.gao") });
		header.insert(header.end(), { ZH_WORDS_GETTER("chuweixiangxixinxi.xinxi.tingyong"),ZH_WORDS_GETTER("chuweixiangxixinxi.xinxi.beizu"),ZH_WORDS_GETTER("chuweixiangxixinxi.xinxi.beizu1"),ZH_WORDS_GETTER("chuweixiangxixinxi.xinxi.beizhu2"),ZH_WORDS_GETTER("chuweixiangxixinxi.xinxi.dongxian"),ZH_WORDS_GETTER("chuweixiangxixinxi.xinxi.ID"),ZH_WORDS_GETTER("chuweixiangxixinxi.xinxi.x"),ZH_WORDS_GETTER("chuweixiangxixinxi.xinxi.y"),ZH_WORDS_GETTER("chuweixiangxixinxi.xinxi.z") });
		data.push_back(header);

		for (auto code : *chuwei) {
			data.emplace_back(dao.getdataone(code));
		}
	}

	//	将数据上传到文件服务器中
	auto buff = excel.writeVectorToBuff("sheet1", data);
	const char* tsData = reinterpret_cast<const char*>(buff.data());

#ifdef LINUX
	ZO_CREATE_DFS_CLIENT_URL(dfs_client, pre_url);
	std::string url = dfs_client.uploadFile(tsData, buff.size(), "xlsx");
	return pre_url + url;
#else
	ZO_CREATE_DFS_CLIENT_URL(dfs, pre_url);
	std::string res = dfs.uploadFile(tsData, buff.size(), "xlsx");
	return  pre_url + res;
#endif
	return {};
}


//导入储位
std::string xiangxixinxiSERVICE::addchuweiSERVICE(const  xiangxixinxiDTO::Wrapper& drdto,const PayloadDTO& payload)
{
	xiangxixinxiDAO dao;
	BinDO servicedo;
	ZO_STAR_DOMAIN_DTO_TO_DO(servicedo, drdto, KuWeiBianMa, bianma, KuWeiTiaoMa, tiaoma, KuWeiLeiXing, leixing, KuWeiShuXing, shuxing, ShangJiaCiXu, shangjiacixu, QuHuoCiXu, quhuocixu, SuoShuKeHu, kehu );
	ZO_STAR_DOMAIN_DTO_TO_DO(servicedo, drdto, TiJiDanWei, tiji, ZhongLiangDanWei, zhongliang, MianJiDanWei, mianji, ZuiDaTiJi, zuidatiji, ZuiDaZhongLiang, zuidazhongliang);
	ZO_STAR_DOMAIN_DTO_TO_DO(servicedo, drdto, ZuiDaMianJi, zuidamianji, ZuiDaTuoPan, zuidatuopan, Chang, chang, Kuan, kuan, Gao, gao, TingYong, tingyong, MingXi, beizhu);
	ZO_STAR_DOMAIN_DTO_TO_DO(servicedo, drdto,  CHPShuXing, chanpinshuxing, MingXi1, beizhu1, MingXi2, beizhu2, MingXi3, dongxian, LORABqid, ID, XNode, x, YNode, y, ZNode, z);
	
	auto result = dao.addchuweiDAO(servicedo,payload);
	return result;
	
}