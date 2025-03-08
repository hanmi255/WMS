#pragma once
#ifndef _WVDO_
#define _WVDO_
#include "domain/GlobalInclude.h"

class WvDO
{
    CC_SYNTHESIZE(string, bin_id, BinId); // 储位编码
    CC_SYNTHESIZE(string, chang, Chang); // 长度
    CC_SYNTHESIZE(string, kuan, Kuan); // 宽度
    CC_SYNTHESIZE(string, gao, Gao); // 高度
    CC_SYNTHESIZE(string, bin_store, BinStore); // 仓库
    CC_SYNTHESIZE(string, xnode, Xnode); // x
    CC_SYNTHESIZE(string, ynode, Ynode); // y
    CC_SYNTHESIZE(string, znode, Znode); // z
    CC_SYNTHESIZE(string, colour, Colour); // colour
    CC_SYNTHESIZE(string, tincount, Tincount); // tincount
public:
    WvDO() {
        bin_id = "";
        chang = "";
        kuan = "";
        gao = "";
        bin_store = "";
        xnode = "";
        ynode = "";
        znode = "";
        colour = "";
        tincount = "";
        
    }
};



#endif // !_WVDO_