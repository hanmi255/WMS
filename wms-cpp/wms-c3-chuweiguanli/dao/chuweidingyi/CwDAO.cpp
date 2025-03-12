#include "stdafx.h"
#include "CwDAO.h"
#include "id/UuidFacade.h"

string get_Id()
{
	UuidFacade uf(1);
	return uf.genUuid();
}

string CwDAO::add(const BinDO& obj)
{
	string Id = get_Id();
	string sql = "INSERT INTO `md_bin` \
		(`id`,`bin_store`,`suo_shu_ke_hu`, `ku_wei_bian_ma`, `ku_wei_tiao_ma`,\
		`ku_wei_lei_xing`, `ku_wei_shu_xing`, `CHP_SHU_XING`,  \
		`shang_jia_ci_xu`,`qu_huo_ci_xu`, `zui_da_zhong_liang`,`zui_da_tuo_pan`,\
		`chang`,`kuan`,`gao`,`zui_da_ti_ji`,`ting_yong`,`ming_xi`,`ming_xi1`,\
		`ming_xi2`,`ming_xi3`,`LORA_bqid`,`ti_ji_dan_wei`,`zhong_liang_dan_wei`,\
		`mian_ji_dan_wei`,`zui_da_mian_ji`,`xnode`,`ynode`,`znode`)\
		VALUES(? , ? , ? , ? , ? , ? , ? , ? , ?,?,? , ? , ? , ? , ? , ? , ? , ? , ?,?,\
		? , ? , ? , ? , ? , ? , ? , ? , ?)";
	auto res = sqlSession->executeUpdate(sql,
		"%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s",
		Id,
		obj.getBinStore(),
		obj.getSuoShuKeHu(),
		obj.getKuWeiBianMa(),
		obj.getKuWeiTiaoMa(),
		obj.getKuWeiLeiXing(),
		obj.getKuWeiShuXing(),
		obj.getCHPShuXing(),
		obj.getShangJiaCiXu(),
		obj.getQuHuoCiXu(),
		obj.getZuiDaZhongLiang(),
		obj.getZuiDaTuoPan(),
		obj.getChang(),
		obj.getKuan(),
		obj.getGao(),
		obj.getZuiDaTiJi(),
		obj.getTingYong(),
		obj.getMingXi(),
		obj.getMingXi1(),
		obj.getMingXi2(),
		obj.getMingXi3(),
		obj.getLORABqid(),
		obj.getTiJiDanWei(),
		obj.getZhongLiangDanWei(),
		obj.getMianJiDanWei(),
		obj.getZuiDaMianJi(),
		obj.getXNode(),
		obj.getYNode(),
		obj.getZNode());
	if (res > 0)
	{
		return Id;
	}
	return string{ "failed" };
}
