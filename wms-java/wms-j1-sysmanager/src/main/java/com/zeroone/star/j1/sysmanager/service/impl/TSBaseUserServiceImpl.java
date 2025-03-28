package com.zeroone.star.j1.sysmanager.service.impl;

import com.baomidou.mybatisplus.core.metadata.IPage;
import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.query.j1.sysmanager.rolemanager.RoleUserQuery;
import com.zeroone.star.project.query.j1.sysmanager.rolemanager.UserQuery;
import com.zeroone.star.project.vo.j1.sysmanager.rolemanager.RoleUserVO;
import com.zeroone.star.project.vo.j1.sysmanager.rolemanager.UserVO;
import com.zeroone.star.j1.sysmanager.entity.TSBaseUser;
import com.zeroone.star.j1.sysmanager.mapper.TSBaseUserMapper;
import com.zeroone.star.j1.sysmanager.service.ITSBaseUserService;
import lombok.extern.slf4j.Slf4j;
import org.springframework.stereotype.Service;

import javax.annotation.Resource;

/**
 * <p>
 * 系统用户 服务实现类
 * </p>
 *
 * @author liyunyi
 * @since 2025-02-19
 */
@Service
@Slf4j
public class TSBaseUserServiceImpl extends ServiceImpl<TSBaseUserMapper, TSBaseUser> implements ITSBaseUserService {

    @Resource
    private TSBaseUserMapper baseUserMapper;

    @Override
    public PageDTO<UserVO> queryUserList(UserQuery userQuery) {

        // Integer limit = (int) ((userQuery.getPageIndex() - 1) * userQuery.getPageSize());
        // Integer offset = (int) userQuery.getPageSize();

        //构建分页对象
        IPage<UserVO> page = new Page<>(userQuery.getPageIndex(),userQuery.getPageSize());

        //使用mp分页插件，xml形式查询
        IPage<UserVO> result = baseUserMapper.getUserList(page, userQuery);

        //此处手动转换 不使用提供的PageDTO.create();
        PageDTO<UserVO> pageResult = new PageDTO<>();
        pageResult.setTotal(result.getTotal());
        pageResult.setRows(result.getRecords());
        pageResult.setPageIndex(result.getCurrent());
        pageResult.setPageSize(result.getSize());
        pageResult.setPages(result.getPages());

        return pageResult;
    }

    @Override
    public PageDTO<RoleUserVO> queryRoleUserList(RoleUserQuery roleUserQuery) {

       // Integer limit = (int) ((roleUserQuery.getPageIndex() - 1) * roleUserQuery.getPageSize());
       // Integer offset = (int) roleUserQuery.getPageSize();

        //构建分页对象
        IPage<RoleUserVO> page = new Page<>(roleUserQuery.getPageIndex(), roleUserQuery.getPageSize());

        //使用mp分页插件，xml形式查询
        IPage<RoleUserVO> result = baseUserMapper.getUserList2(page, roleUserQuery);

        //此处手动转换 不使用提供的PageDTO.create();
        PageDTO<RoleUserVO> pageResult = new PageDTO<>();
        pageResult.setTotal(result.getTotal());
        pageResult.setRows(result.getRecords());
        pageResult.setPageIndex(result.getCurrent());
        pageResult.setPageSize(result.getSize());
        pageResult.setPages(result.getPages());

        return pageResult;
    }
}
