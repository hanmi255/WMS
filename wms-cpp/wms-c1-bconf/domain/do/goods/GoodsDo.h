#ifndef _GOODSDO_H_
#define _GOODSDO_H_
#include "../../..//Macros.h"
#include <string>



class GoodsDo {
	CC_SYNTHESIZE(int, id, ID);
	CC_SYNTHESIZE(std::string, create_name, Create_name);
	CC_SYNTHESIZE(std::string, create_by, Create_by);
	CC_SYNTHESIZE(std::string, create_time, Create_time);
	CC_SYNTHESIZE(std::string, update_name, Update_name);
	CC_SYNTHESIZE(std::string, update_by, Update_by);
	CC_SYNTHESIZE(std::string, update_time, Update_time);
	CC_SYNTHESIZE(std::string, sys_org_code, Sys_org_code);
	CC_SYNTHESIZE(std::string, category_code, Category_code);
	CC_SYNTHESIZE(std::string, category_name, Category_name);
	CC_SYNTHESIZE(int, category_level, Category_level);
	CC_SYNTHESIZE(int, pid, PID);
	CC_SYNTHESIZE(std::string, top_node, Top_node);
public:
	GoodsDo() :id(0),create_name(""),create_by(""), create_time(""), update_name(""),update_by(""),update_time(""), sys_org_code(""), \
		category_code(""), category_name(""), category_level(-1), pid(-1), top_node("") {}
};
//using PtrGoodsDo = std::shared_ptr<GoodsDo>;

#endif //_GOODSDO_H_
