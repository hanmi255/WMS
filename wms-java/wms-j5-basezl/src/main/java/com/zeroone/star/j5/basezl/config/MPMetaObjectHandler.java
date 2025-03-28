package com.zeroone.star.j5.basezl.config;

import com.baomidou.mybatisplus.core.handlers.MetaObjectHandler;
import com.zeroone.star.project.components.user.UserDTO;
import com.zeroone.star.project.components.user.UserHolder;
import org.apache.ibatis.reflection.MetaObject;
import org.mybatis.spring.annotation.MapperScan;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.context.annotation.Configuration;
import java.time.LocalDateTime;

/**
 * <p>
 * 描述: 公共字段自动写入配置
 * </p>
 * <p>版权所有: &copy;枢璇</p>
 *
 * @author 枢璇
 * @Version 1.0.0
 * @since 2025/2/23 11:25
 */
@Configuration
@MapperScan("com.zeroone.star.j5.basezl.mapper")
public class MPMetaObjectHandler implements MetaObjectHandler {

    @Autowired
    UserHolder userHolder;
    @Override
    public void insertFill(MetaObject metaObject) {
        UserDTO dto = null;
        try {
            dto = userHolder.getCurrentUser();
        } catch (Exception e) {
            e.printStackTrace();
        }
        this.setFieldValByName("createDate", LocalDateTime.now(), metaObject);
        this.setFieldValByName("updateDate", LocalDateTime.now(), metaObject);
        if(dto!=null) {
            this.setFieldValByName("createName", dto.getRealname(), metaObject);
            this.setFieldValByName("createBy", dto.getUsername(), metaObject);
            this.setFieldValByName("updateName", dto.getRealname(), metaObject);
            this.setFieldValByName("updateBy", dto.getUsername(), metaObject);
            this.setFieldValByName("sysOrgCode",dto.getOrgCode(), metaObject);
            this.setFieldValByName("sysCompanyCode",dto.getCompanyCode(), metaObject);
        }
    }

    @Override
    public void updateFill(MetaObject metaObject) {
        UserDTO dto = null;
        try {
            dto = userHolder.getCurrentUser();
        } catch (Exception e) {
            e.printStackTrace();
        }
        this.setFieldValByName("updateDate", LocalDateTime.now(), metaObject);
        if(dto!=null) {
            this.setFieldValByName("updateName", dto.getRealname(), metaObject);
            this.setFieldValByName("updateBy", dto.getUsername(), metaObject);
            this.setFieldValByName("sysOrgCode",dto.getOrgCode(), metaObject);
            this.setFieldValByName("sysCompanyCode",dto.getCompanyCode(), metaObject);
        }
    }
}