package com.zeroone.star.outgoodsmanage.mapper;

import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import com.zeroone.star.outgoodsmanage.entity.WmOmQmI;
import org.apache.ibatis.annotations.Mapper;
import org.apache.ibatis.annotations.Param;
import org.apache.ibatis.annotations.Select;

import java.util.List;

/**
 * <p>
 * 出库任务 Mapper 接口
 * </p>
 *
 * @author Longlive
 * @since 2025-02-21
 */
@Mapper
public interface WmOmQmIMapper extends BaseMapper<WmOmQmI> {
     public void waveGen(@Param("ids") List<String> ids,@Param("WaveId") String WaveId,
                         @Param("realname")String realname,@Param("username")String userId,
                         @Param("updateTime")String updateTime);
     @Select("select realname from t_s_base_user where username=#{username}")
     public String getRealName(@Param("username") String username);

     public void delMission(@Param("ids")List<String> ids);

     public List<WmOmQmI> expoAll();

     public WmOmQmI selectByNoticeId(String omNoticeId);
}
