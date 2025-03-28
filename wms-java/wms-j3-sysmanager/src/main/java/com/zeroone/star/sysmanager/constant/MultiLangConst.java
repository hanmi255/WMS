package com.zeroone.star.sysmanager.constant;

/**
 * @program: wms-java
 * @description: 常量存储,TODO 该包下常量后续放到common模块最好
 * @author: hamhuo
 **/
public interface MultiLangConst {
    //Redis缓存键前缀定义
     static final String TAGCODE = "sys_multi_lang_";
    //普通分页标签
     static final String PLAIN = "plain";
    //@Value(redis.j3.sys.multi.expireTime), 缓存过期时间
     static final long EXPIRE_TIME = 60*10L;
}