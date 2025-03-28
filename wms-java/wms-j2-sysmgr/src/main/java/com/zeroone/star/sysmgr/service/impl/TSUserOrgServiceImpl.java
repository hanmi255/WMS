package com.zeroone.star.sysmgr.service.impl;

import com.baomidou.mybatisplus.core.conditions.query.LambdaQueryWrapper;
import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j2.sysmgr.UserDTO;
import com.zeroone.star.project.query.j2.sysmgr.AddUserQuery;
import com.zeroone.star.project.query.j2.sysmgr.DeleteUserQuery;
import com.zeroone.star.project.query.j2.sysmgr.ListUserQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.ResultStatus;
import com.zeroone.star.project.vo.j2.sysmgr.ListUserVO;
import com.zeroone.star.sysmgr.entity.TSBaseUser;
import com.zeroone.star.sysmgr.entity.TSUserOrg;
import com.zeroone.star.sysmgr.mapper.TSBaseUserMapper;
import com.zeroone.star.sysmgr.mapper.TSUserOrgMapper;
import com.zeroone.star.sysmgr.service.ITSUserOrgService;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import lombok.RequiredArgsConstructor;
import org.springframework.stereotype.Service;

import javax.annotation.Resource;
import java.util.ArrayList;
import java.util.List;
import java.util.function.Consumer;

/**
 * <p>
 * 服务实现类
 * </p>
 *
 * @author henry
 * @since 2025-02-21
 */
@Service
@RequiredArgsConstructor
public class TSUserOrgServiceImpl extends ServiceImpl<TSUserOrgMapper, TSUserOrg> implements ITSUserOrgService {

    //    @Resource
//    private TSUserOrgMapper mapper;
    private final TSUserOrgMapper userOrgMapper;

    private final TSBaseUserMapper baseUserMapper;

    @Override
    public ListUserVO listUser(ListUserQuery userQuery) {
        // 先查出该组织机构中有哪些组织成员
        LambdaQueryWrapper<TSUserOrg> lambdaUser = new LambdaQueryWrapper<>();
        lambdaUser.eq(TSUserOrg::getOrgId,userQuery.getId());
        List<TSUserOrg> tsUserOrgs = userOrgMapper.selectList(lambdaUser);

        List<String> list = new ArrayList<>();
        tsUserOrgs.forEach(tsUserOrg -> list.add(tsUserOrg.getUserId()));

        // 再根据用户账号和账号名称进行模糊匹配
        LambdaQueryWrapper<TSBaseUser> lambdaBase = new LambdaQueryWrapper<>();
        lambdaBase.in(TSBaseUser::getId,list)
                .like(TSBaseUser::getUsername,userQuery.getUsername())
                .eq(TSBaseUser::getRealname,userQuery.getRealname());

        // 最后返回分页查询结果
        Page<TSBaseUser> page = new Page<>(userQuery.getPageIndex(),userQuery.getPageSize());
        Page<TSBaseUser> tsBaseUserPage = baseUserMapper.selectPage(page, lambdaBase);

        return new ListUserVO(PageDTO.create(tsBaseUserPage, UserDTO.class));
    }

    @Override
    public int deleteUser(DeleteUserQuery userQuery) {
        // 查询组织成员的id
        LambdaQueryWrapper<TSBaseUser> lambdaUser = new LambdaQueryWrapper<>();
        lambdaUser.eq(TSBaseUser::getUsername, userQuery.getUsername());
        TSBaseUser tsBaseUser = baseUserMapper.selectOne(lambdaUser);

        // 根据组织机构id和组织成员id查出表中对应行的id，进行删除
        LambdaQueryWrapper<TSUserOrg> lambdaQueryWrapper = new LambdaQueryWrapper<>();
        lambdaQueryWrapper.eq(TSUserOrg::getOrgId,userQuery.getId())
                .eq(TSUserOrg::getUserId,tsBaseUser.getId());

        return userOrgMapper.delete(lambdaQueryWrapper);
    }

    @Override
    public boolean addUser(AddUserQuery userQuery) {

        List<String> usernameList = userQuery.getUsernameList();
        List<TSUserOrg> list = new ArrayList<>();
        usernameList.forEach(s -> {
            LambdaQueryWrapper<TSBaseUser> lambdaQueryWrapper = new LambdaQueryWrapper<>();
            lambdaQueryWrapper.eq(TSBaseUser::getUsername,s);
            TSBaseUser tsBaseUser = baseUserMapper.selectOne(lambdaQueryWrapper);
            TSUserOrg temp = new TSUserOrg();
            temp.setOrgId(userQuery.getId());
            temp.setUserId(tsBaseUser.getId());
            list.add(temp);
        });
        IService<TSUserOrg> service = new ServiceImpl<>();
        return service.saveBatch(list);
    }
}
