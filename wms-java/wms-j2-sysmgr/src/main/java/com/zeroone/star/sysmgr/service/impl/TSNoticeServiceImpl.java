package com.zeroone.star.sysmgr.service.impl;

import cn.easyes.core.conditions.LambdaEsQueryWrapper;
import cn.hutool.core.bean.BeanUtil;
import com.baomidou.mybatisplus.core.conditions.query.LambdaQueryWrapper;
import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.github.xiaoymin.knife4j.core.util.Assert;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j2.sysmgr.TSNoticeAddDTO;
import com.zeroone.star.project.dto.j2.sysmgr.TSNoticeDTO;
import com.zeroone.star.project.dto.j2.sysmgr.TSNoticeUpdateDTO;
import com.zeroone.star.project.query.PageQuery;
import com.zeroone.star.sysmgr.entity.*;
import com.zeroone.star.sysmgr.mapper.*;
import com.zeroone.star.sysmgr.mapper.es.TSNoticeEsMapper;
import com.zeroone.star.sysmgr.service.TSNoticeService;
import io.seata.spring.annotation.GlobalTransactional;
import org.redisson.api.RLock;
import org.redisson.api.RedissonClient;
import org.springframework.beans.BeanUtils;
import org.springframework.stereotype.Service;

import javax.annotation.Resource;
import javax.servlet.http.HttpServletRequest;
import java.time.format.DateTimeFormatter;
import java.util.ArrayList;
import java.util.Date;
import java.util.List;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.TimeUnit;


/**
* @author hjm
* @description 针对表【t_s_notice(通知公告表)】的数据库操作Service实现
* @createDate 2025-02-22 00:02:22
*/
@Service
@GlobalTransactional(rollbackFor = Exception.class)
public class TSNoticeServiceImpl extends ServiceImpl<TSNoticeMapper, TSNotice> implements TSNoticeService{
    @Resource
    private TSNoticeMapper tsNoticeMapper;

    @Resource
    private TSUserMapper tsUserMapper;

    @Resource
    private TSNoticeReadUserMapper tsNoticeReadUserMapper;

    @Resource
    private TSNoticeAuthorityRoleMapper tsNoticeAuthorityRoleMapper;

    @Resource
    private TSNoticeAuthorityUserMapper tsNoticeAuthorityUserMapper;

    private ExecutorService executor = Executors.newCachedThreadPool();
    @Resource
    private TSNoticeEsMapper esMapper;

    @Resource
    private TSRoleUserMapper tsRoleUserMapper;



    @Override
    public Boolean addNotice(TSNoticeAddDTO tsNoticeAddDTO) {
        if (tsNoticeAddDTO == null){
            return null;
        }
        TSNotice notice = new TSNotice();
        BeanUtils.copyProperties(tsNoticeAddDTO, notice);
        boolean save = this.save(notice);
        if("1".equals(tsNoticeAddDTO.getNoticeLevel())){
            executor.execute(new Runnable() {
                @Override
                public void run() {
                    QueryWrapper<TSUser> queryWrapper = new QueryWrapper<>();
                    List<TSUser> tsUsers = tsUserMapper.selectList(queryWrapper);
                    for (TSUser tsUser : tsUsers){
                        insertReadUser(tsUser.getId(),notice.getId());


                    }
                    tsUsers.clear();
                }
            });
        }
        if ("2".equals(tsNoticeAddDTO.getNoticeLevel())) {
            List<String> roleId = tsNoticeAddDTO.getRoleId();

            QueryWrapper<TSRoleUser> queryWrapper = new QueryWrapper<>();
            for (String s : roleId) {
                TSNoticeAuthorityRole noticeAuthorityRole = new TSNoticeAuthorityRole();
                noticeAuthorityRole.setNoticeId(notice.getId());
                noticeAuthorityRole.setRoleId(s);

                queryWrapper.eq("roleid", s);
                List<TSRoleUser> tsRoleUsers = tsRoleUserMapper.selectList(queryWrapper);
                //获取和roleid匹配的tsRoleUser
                for(TSRoleUser tsRoleUser : tsRoleUsers){
                    String userid = tsRoleUser.getUserid();
                    if (userid == null){  //说明没有这个用户
                        continue;
                    }
                    insertReadUser(userid,notice.getId());
                }


                tsNoticeAuthorityRoleMapper.insert(noticeAuthorityRole);
            }
        }else {
            if ("3".equals(tsNoticeAddDTO.getNoticeLevel())) {

                List<String> userId = tsNoticeAddDTO.getUserId();
                for (String s : userId) {
                    TSNoticeAuthorityUser noticeAuthorityUser = new TSNoticeAuthorityUser();
                    noticeAuthorityUser.setNoticeId(notice.getId());


                    noticeAuthorityUser.setUserId(s);
                    tsNoticeAuthorityUserMapper.insert(noticeAuthorityUser);


                    insertReadUser(s,notice.getId());

                }

            }
        }
        return save;

    }



    @Override
    public Boolean updateNotice(TSNoticeUpdateDTO tsNoticeUpdateDTO) {
        if (tsNoticeUpdateDTO == null){
            return null;
        }
        TSNotice notice = new TSNotice();
        BeanUtils.copyProperties(notice, tsNoticeUpdateDTO);
        boolean update = this.updateById(notice);



        if("1".equals(tsNoticeUpdateDTO.getNoticeLevel())){
            executor.execute(new Runnable() {
                @Override
                public void run() {
                    QueryWrapper<TSUser> queryWrapper = new QueryWrapper<>();
                    List<TSUser> tsUsers = tsUserMapper.selectList(queryWrapper);
                    for (TSUser tsUser : tsUsers){
                        updateReadUser(tsUser.getId(),notice.getId());


                    }
                    tsUsers.clear();
                }
            });
        }
        if ("2".equals(tsNoticeUpdateDTO.getNoticeLevel())) {
            QueryWrapper<TSRoleUser> queryWrapper = new QueryWrapper<>();
            List<String> roleId = tsNoticeUpdateDTO.getRoleId();
            for (String s : roleId) {
                TSNoticeAuthorityRole noticeAuthorityRole = new TSNoticeAuthorityRole();
                noticeAuthorityRole.setNoticeId(notice.getId());
                noticeAuthorityRole.setRoleId(s);
                tsNoticeAuthorityRoleMapper.updateById(noticeAuthorityRole);

                queryWrapper.eq("roleid", s);
                List<TSRoleUser> tsRoleUsers = tsRoleUserMapper.selectList(queryWrapper);
                for(TSRoleUser tsRoleUser : tsRoleUsers){
                    String userid = tsRoleUser.getUserid();
                    if (userid == null){
                        continue;
                    }
                    updateReadUser(userid, notice.getId());

                }
            }
        }else {
            if ("3".equals(tsNoticeUpdateDTO.getNoticeLevel())) {

                List<String> userId = tsNoticeUpdateDTO.getUserId();
                for (String s : userId) {
                    TSNoticeAuthorityUser noticeAuthorityUser = new TSNoticeAuthorityUser();
                    noticeAuthorityUser.setNoticeId(notice.getId());
                    TSUser tsUser = new TSUser();
                    tsUser.setId(s);
                    noticeAuthorityUser.setUserId(s);
                    tsNoticeAuthorityUserMapper.updateById(noticeAuthorityUser);

                    updateReadUser(s, notice.getId());
                }
            }
        }
        return update;
    }

    /**
     * 向ts_Notice_Read_User表中插入数据
     * @param userId
     * @param noticeId
     */
    public void insertReadUser(String userId, String noticeId){
        QueryWrapper<TSNoticeReadUser> readQueryWrapper = new QueryWrapper<>();
        readQueryWrapper.eq("user_id", userId);
        readQueryWrapper.eq("notice_id", noticeId);
        List<TSNoticeReadUser> tsNoticeReadUsers = tsNoticeReadUserMapper.selectList(readQueryWrapper);
        if (tsNoticeReadUsers == null || tsNoticeReadUsers.isEmpty()){
            TSNoticeReadUser tsNoticeReadUser = new TSNoticeReadUser();
            tsNoticeReadUser.setNoticeId(noticeId);
            tsNoticeReadUser.setUserId(userId);
            tsNoticeReadUser.setCreateTime(new Date());
            tsNoticeReadUserMapper.insert(tsNoticeReadUser);
        }else {
            for(TSNoticeReadUser readUser : tsNoticeReadUsers){
                if (readUser.getDelFlag() == 1){
                    readUser.setDelFlag(0);
                    tsNoticeReadUserMapper.updateById(readUser);
                }
            }
        }
    }

    /**
     * 向ts_Notice_Read_User表中更新数据
     * @param userId
     * @param noticeId
     */
    public void updateReadUser(String userId, String noticeId){
        QueryWrapper<TSNoticeReadUser> readQueryWrapper = new QueryWrapper<>();
        readQueryWrapper.eq("user_id", userId);
        readQueryWrapper.eq("notice_id", noticeId);
        List<TSNoticeReadUser> tsNoticeReadUsers = tsNoticeReadUserMapper.selectList(readQueryWrapper);
        if (tsNoticeReadUsers == null || tsNoticeReadUsers.isEmpty()){
            TSNoticeReadUser tsNoticeReadUser = new TSNoticeReadUser();
            tsNoticeReadUser.setNoticeId(noticeId);
            tsNoticeReadUser.setUserId(userId);
            tsNoticeReadUser.setCreateTime(new Date());
            tsNoticeReadUserMapper.updateById(tsNoticeReadUser);
        }else {
            for(TSNoticeReadUser readUser : tsNoticeReadUsers){
                if (readUser.getDelFlag() == 1){
                    readUser.setDelFlag(0);
                    tsNoticeReadUserMapper.updateById(readUser);
                }
            }
        }
    }

    @Override
    public Boolean deleteBatchNotice(List<String> ids) {
        if (ids == null || ids.isEmpty()) {
            return false;
        }
        QueryWrapper<TSNotice> queryWrapper = new QueryWrapper<>();
        queryWrapper.in("id", ids);
        int deletedCount = tsNoticeMapper.delete(queryWrapper);
        return deletedCount > 0;
    }

    /**
     * 获取公告列表（分页）
     * @return
     */
    @Override
    public PageDTO<TSNoticeDTO> getAnnouncementPage(PageQuery pageQuery) {

        //如果没有传分页参数，则默认为第一页，每页10条数据
        long pageIndex=1;
        long pageSize=10;
        if(pageQuery.getPageIndex()!=0&&pageQuery.getPageSize()!=0){
            pageIndex=pageQuery.getPageIndex();
            pageSize=pageQuery.getPageSize();
        }

        //获取当前时间，用于查询条件
        java.time.LocalDateTime now = java.time.LocalDateTime.now();
        DateTimeFormatter dateTimeFormatter = DateTimeFormatter.ofPattern("yyyy-MM-dd HH:mm:ss");
        String format = dateTimeFormatter.format(now);
        java.time.LocalDateTime localDateTime = java.time.LocalDateTime.parse(format, dateTimeFormatter);


        //首先需要将没过期的数据查找出来
        LambdaQueryWrapper<TSNotice> queryWrapper = new LambdaQueryWrapper<>();
        queryWrapper.ge(TSNotice::getNoticeTerm,localDateTime);

        Page<TSNotice> page = new Page<>(pageIndex, pageSize);
        Page<TSNotice> tsNoticePage = tsNoticeMapper.selectPage(page, queryWrapper);
        List<TSNoticeDTO> tsNoticeDTOS = new ArrayList<>();
        PageDTO<TSNoticeDTO> tsNoticeDTOPageDTO = new PageDTO<>();
        tsNoticePage.getRecords().forEach(s->{
            TSNoticeDTO tsNoticeDTO = new TSNoticeDTO();
            BeanUtil.copyProperties(s,tsNoticeDTO);
            System.out.println(tsNoticeDTO);
            tsNoticeDTOS.add(tsNoticeDTO);
        });
        tsNoticeDTOPageDTO.setRows(tsNoticeDTOS);
        return tsNoticeDTOPageDTO;
    }

    /**
     * 获取公告详细信息
     * @param dto
     * @return
     */
    public TSNotice getAnnouncementDetail(TSNoticeDTO dto) {


        TSNotice tsNotice = new TSNotice();
        BeanUtil.copyProperties(dto,tsNotice);

        //mp查询
        LambdaQueryWrapper<TSNotice> wrapper = new LambdaQueryWrapper<>();
        wrapper.eq(tsNotice.getId()!=null,TSNotice::getId,tsNotice.getId())
                .eq(tsNotice.getNoticeContent()!=null,TSNotice::getNoticeContent,tsNotice.getNoticeContent())
                .eq(tsNotice.getNoticeTitle()!=null,TSNotice::getNoticeTitle,tsNotice.getNoticeTitle())
                .eq(tsNotice.getNoticeType()!=null,TSNotice::getNoticeType,tsNotice.getNoticeType())
                .eq(tsNotice.getNoticeLevel()!=null,TSNotice::getNoticeLevel,tsNotice.getNoticeLevel())
                .eq(tsNotice.getNoticeTerm()!=null,TSNotice::getNoticeTerm,dto.getNoticeTerm());

        TSNotice tsNotice1 = tsNoticeMapper.selectOne(wrapper);

        //如果mysql数据库中没有数据，则从es中查询
        if(dto.getId()!=null&&tsNotice1==null){
            //首先将mysql数据库的数据同步到es中
            syncMysqlToEe();
            tsNotice1=new TSNotice();

            //ee查询
            LambdaEsQueryWrapper<TSNotice> esQueryWrapper = new LambdaEsQueryWrapper<>();
            esQueryWrapper
                    .eq(tsNotice.getId()!=null,TSNotice::getId,tsNotice.getId())
                    .match(tsNotice.getNoticeContent()!=null,TSNotice::getNoticeContent,tsNotice.getNoticeContent())
                    .eq(tsNotice.getNoticeTitle()!=null,TSNotice::getNoticeTitle,tsNotice.getNoticeTitle())
                    .eq(tsNotice.getNoticeType()!=null,TSNotice::getNoticeType,tsNotice.getNoticeType())
                    .eq(tsNotice.getNoticeLevel()!=null,TSNotice::getNoticeLevel,tsNotice.getNoticeLevel())
                    .eq(tsNotice.getNoticeTerm()!=null,TSNotice::getNoticeTerm,dto.getNoticeTerm());

            TSNotice esNotice1 = esMapper.selectOne(esQueryWrapper);


            BeanUtil.copyProperties(esNotice1,tsNotice1);



        }

        String noticeType = tsNotice1.getNoticeType();
        if("1".equals(noticeType)){
            tsNotice1.setNoticeType("通知");
        }else if("2".equals(noticeType)){
            tsNotice1.setNoticeType("公告");
        }

        String noticeLevel = tsNotice1.getNoticeLevel();
        if("1".equals(noticeLevel)){
            tsNotice1.setNoticeLevel("全员");
        }else if("2".equals(noticeLevel)){
            tsNotice1.setNoticeLevel("角色");
        }else if("3".equals(noticeLevel)){
            tsNotice1.setNoticeLevel("用户");
        }


        return tsNotice1;
    }

    @Resource
    private RedissonClient redissonClient;

    /**
     * 同步MySQL数据到Elasticsearch(ES)
     * 该方法用于将MySQL中的数据同步到ES中，以保持数据一致性
     */
    private void syncMysqlToEe() {
        // 创建一个Redisson锁对象，用于实现线程间的同步和互斥操作
        RLock rLock = redissonClient.getLock("lock");
        boolean isLock = false;
        try {

            isLock= rLock.tryLock(1000,  TimeUnit.SECONDS);
            if (!isLock) {
                // 如果获取锁失败，则直接返回，不进行后续操作
                throw new RuntimeException("获取锁失败，请稍后再试");
            }


            //判断索引是否存在，不存在则创建索引
            Boolean eeTsnotice = esMapper.existsIndex("ee_tsnotice");
            if(!eeTsnotice){
                Boolean index = esMapper.createIndex();
                System.out.println(index);
            }




            // 创建一个LambdaEsQueryWrapper对象，用于后续的ES查询
            LambdaEsQueryWrapper<TSNotice> tsLambdaEsQueryWrapper = new LambdaEsQueryWrapper<>();



            // 先删除ES中已有的数据，以确保数据的同步准确性
            esMapper.delete(tsLambdaEsQueryWrapper);


            // 从MySQL中查询所有数据
            List<TSNotice> tsNotices = tsNoticeMapper.selectList(null);


            // 将查询到的数据批量插入到ES中，实现数据同步
            esMapper.insertBatch(tsNotices);

        } catch (Exception e) {
            // 异常处理，将捕获到的异常重新抛出，由调用者决定如何处理
            throw new RuntimeException(e);
        } finally {
            // 释放锁，以便其他线程可以获取锁并进行操作
            rLock.unlock();


        }
    }



}




