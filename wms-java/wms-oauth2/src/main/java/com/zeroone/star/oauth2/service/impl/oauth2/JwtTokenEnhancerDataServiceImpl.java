package com.zeroone.star.oauth2.service.impl.oauth2;

import com.zeroone.cloud.oauth2.entity.SecurityUser;
import com.zeroone.cloud.starter.oauth2.service.JwtTokenEnhancerDataService;
import com.zeroone.star.oauth2.entity.TSBaseUser;
import com.zeroone.star.oauth2.mapper.TSDataLogMapper;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import java.util.HashMap;
import java.util.Map;

/**
 * <p>
 * 描述：Jwt Token增强数据处理服务实现
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 * @author 阿伟学长
 * @version 1.0.0
 */
@Service
public class JwtTokenEnhancerDataServiceImpl implements JwtTokenEnhancerDataService {

    @Autowired
    TSDataLogMapper dataLogMapper;

    @Override
    public Map<String, Object> enhance(SecurityUser securityUser) {
        // 获取数据库用户DO对象
        //TSUser user = (TSUser) securityUser.getExtendsObject();
        TSBaseUser baseUser = (TSBaseUser) securityUser.getExtendsObject();
        Map<String, Object> info = new HashMap<>(1);
        // FIXME: 如果要扩展凭证中的负载数据,需要修改这里的代码
        String orgCode = dataLogMapper.selectOrgCodeByUserRealanme(baseUser.getUsername());
        String companyCode = dataLogMapper.selectCompanyCodeByUserRealname(baseUser.getUsername());
        // 把用户ID设置到JWT中
        info.put("id", baseUser.getId()); // 用户id
        info.put("orgCode", orgCode); // 用户所属部门
        info.put("companyCode", companyCode); // 用户所属公司
        info.put("realname", baseUser.getRealname()); // 登录的用户真实姓名
        return info;
    }
}
