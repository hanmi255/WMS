package com.zeroone.star.sysmanager.service.impl;

import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.project.components.user.UserHolder;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j3.sysmg.multilang.MultiLangBaseDTO;
import com.zeroone.star.project.dto.j3.sysmg.multilang.MultiLangListDTO;
import com.zeroone.star.project.query.j3.sysmg.multilang.MultiLangQuery;
import com.zeroone.star.sysmanager.constant.MultiLangParseStrategy;
import com.zeroone.star.sysmanager.entity.MultiLang;
import com.zeroone.star.sysmanager.entity.MultiLangUpdate;
import com.zeroone.star.sysmanager.constant.OrderType;
import com.zeroone.star.sysmanager.exception.MultiLangException;
import com.zeroone.star.sysmanager.mapper.MultiLangMapper;
import com.zeroone.star.sysmanager.service.MultiLangService;
import com.zeroone.star.sysmanager.service.MultiLangTransactionService;
import lombok.extern.slf4j.Slf4j;
import org.mapstruct.Mapper;
import org.springframework.data.redis.core.RedisTemplate;
import org.springframework.stereotype.Service;
import javax.annotation.Resource;
import java.sql.Timestamp;
import java.util.*;
import java.util.concurrent.TimeUnit;

import static com.zeroone.star.sysmanager.constant.MultiLangParseStrategy.INSERT;
import static com.zeroone.star.sysmanager.constant.MultiLangParseStrategy.UPDATE;
import static com.zeroone.star.sysmanager.constant.MultiLangConst.*;

/**
 * 映射器, 将表实体转换为 DTO实体, 这里使用Mapstruct映射器插件
 */
@Mapper(componentModel = "spring")
interface MsLangMapper{
    MultiLangListDTO lang2Dto(MultiLang lang);
    MultiLangUpdate lang2Update(MultiLang lang);
}


/**
 * @program: wms-java
 * @description: 多语言实现类
 * @author: hamhuo(或者火腿肠)
 **/
@Slf4j
@Service
public class MultiLangServiceImpl extends ServiceImpl<MultiLangMapper, MultiLang> implements MultiLangService {

    //装配映射器
    @Resource
    private MsLangMapper msLangMapper;

    //装配Redis客户端
    @Resource
    private RedisTemplate<String, Object> redisTemplate;

    //装配DAO
    @Resource
    private MultiLangMapper multiLangMapper;

    //装配事务服务
    @Resource
    private MultiLangTransactionService multiLangTransactionService;

    //装配用户信息
    @Resource
    private UserHolder userHolder;


    /**
     * 生成 Redis 缓存 Key，用于多语言查询的缓存命中判断。
     * <p>
     * 生成逻辑如下：
     * </p>
     * <ol>
     *     <li>如果 {@code langKey} 和 {@code langContext} 均不为空，则格式化为 {@code langKey:langContext:order:sort}</li>
     *     <li>如果仅 {@code langKey} 不为空，则格式化为 {@code :langKey:order:sort}</li>
     *     <li>如果仅 {@code langContext} 不为空，则格式化为 {@code langContext:order:sort}</li>
     *     <li>如果都为空，则默认返回 {@code plain:order:sort}</li>
     * </ol>
     *
     * @param multiLangQuery 查询条件对象，包含语言 Key、上下文、排序方式等参数
     * @return 生成的 Redis Key，格式化后用于缓存查询
     */
    private static String genKey(MultiLangQuery multiLangQuery) {
        String r = multiLangQuery.getLangKey();
        String l = multiLangQuery.getLangContext();
        String order = multiLangQuery.getOrder();
        String sort = multiLangQuery.getSort();
        // 两个条件拼接
        if (!r.isEmpty() && !l.isEmpty()) {
            return TAGCODE + ":" + r + ":" + l + ":" + order + ":" + sort;
        }
        // 一个条件, 拼接为key
        else if (!r.isEmpty()) {
            return TAGCODE + ":" + r + ":" + order + ":" + sort;
        } else if (!l.isEmpty()) {
            return TAGCODE + ":" + l + ":" + order + ":" + sort;
        }
        //无条件, 普通分页
        return TAGCODE + ":" + PLAIN + order + ":" + sort;
    }

    /**
     * 多语言数据的分页查询，支持缓存机制，减少数据库查询压力。
     * <p>
     * 查询逻辑：
     * </p>
     * <ol>
     *     <li>根据查询条件 {@link MultiLangQuery} 生成 Redis 缓存 Key。</li>
     *     <li>尝试从 Redis 获取分页数据，若命中则直接返回。</li>
     *     <li>若缓存未命中，则查询 MySQL 并回写到 Redis 以供后续使用。</li>
     * </ol>
     * <p>
     * Redis 缓存策略：读时回写, 允许短时不一致
     * </p>
     * <ul>
     *     <li>缓存 Key 由查询条件决定，确保不同查询条件缓存分离。</li>
     *     <li>数据存入 Redis 的有序集合（ZSet），保证分页查询的顺序性。</li>
     *     <li>MySQL 查询后，数据逐条写入 Redis，按索引作为排序分数（score）。</li>
     * </ul>
     *
     * @param query 查询条件，包括分页索引、大小、排序方式等
     * @return 分页数据，包含 {@link MultiLangListDTO} 数据列表
     */
    @Override
    public PageDTO<MultiLangListDTO> listMultiLang(MultiLangQuery query) {
        //构建Redis Key
        String key = genKey(query);
        // 分页插件构建分页, 用于传入mapper拼接sql
        Page<MultiLang> page = new Page<>(query.getPageIndex(), query.getPageSize());
        // redis 分页参数
        long start = page.getCurrent() - 1;
        long end = start + page.getSize();
        //查询 Redis
        List<MultiLang> result = getRecords(key, start, end);
        //是否命中
        if (result != null) {
            page.setRecords(result)
                    .setTotal(result.size());
            return PageDTO.create(page, msLangMapper::lang2Dto);
        }
        //执行查询
        log.info("缓存未命中, 执行MySQL查询");
        //未命中, 构造wrapper
        QueryWrapper<MultiLang> wrapper = getWrapper(query);
        Page<MultiLang> multiLangPage = baseMapper.selectPage(page, wrapper);

        // 记录为空不再回写Redis, 直接返回
        if (multiLangPage.getRecords() == null) {
            return PageDTO.create(page, msLangMapper::lang2Dto);
        }

        //  回写redis 将分页记录放到 redis 里
        List<MultiLang> records = multiLangPage.getRecords();
        for (int i = 0; i < records.size(); i++) {
            MultiLang record = records.get(i);
            log.info("回写 Redis - Key: {}, Context: {}", record.getLangKey(), record.getLangContext());
            redisTemplate.opsForZSet().add(key, record, i);
            //允许短时不一致, 非手动刷新间隔10分钟
            redisTemplate.expire(key, EXPIRE_TIME, TimeUnit.SECONDS);
        }

        //在分页DTO创建时执行映射回调
        return PageDTO.create(multiLangPage, msLangMapper::lang2Dto);
    }

    /**
     * 保存国际化语言记录。
     * <p>
     * 该方法将 {@link MultiLangBaseDTO} 解析为 {@link MultiLang} 实体对象，并执行插入操作。
     * </p>
     *
     * @param multiLangBaseDTO 国际化语言的基础 DTO，包含语言键、语言内容和语言代码
     * @return {@code true} 表示保存成功，{@code false} 表示保存失败
     * @throws Exception 如果解析过程或数据库插入操作出现异常
     */
    @Override
    public Boolean saveMultiLang(MultiLangBaseDTO multiLangBaseDTO) throws Exception {
        MultiLang multiLang = parse(multiLangBaseDTO, INSERT);
        log.info("构造完毕,{}", multiLang.getLangKey() + " " + multiLang.getLangContext() + " " + multiLang.toString() + " " + multiLang.getCreateName());
        return multiLangTransactionService.insert(multiLang);
    }

    /**
     * 更新多语言记录。
     *
     * <p>此方法首先检查传入的 DTO 是否包含 ID，如果 ID 为空，则抛出异常。</p>
     * <p>由于 DTO 中缺少用户身份上下文和时间信息，因此不会直接映射，而是通过 `parse` 方法进行解析，
     * 以确保数据完整性和正确性。</p>
     * <p>解析完成后，将 `MultiLang` 对象转换为 `MultiLangUpdate`，并调用事务服务进行更新操作。</p>
     *
     * <p>注意事项：
     * <ul>
     *     <li>更新操作必须确保 ID 存在，否则会抛出异常。</li>
     *     <li>更新时会补全必要的系统字段，如更新时间、更新人等。</li>
     *     <li>事务由 `multiLangTransactionService.update` 处理，确保数据一致性。</li>
     * </ul>
     *
     * @param multiLangBaseDTO 包含更新内容的 DTO
     * @return 更新是否成功
     * @throws MultiLangException 如果未传入 ID
     * @throws Exception 其他异常，如解析失败或数据库更新失败
     */
    @Override
    public boolean updateMultiLang(MultiLangBaseDTO multiLangBaseDTO) throws Exception {
        if (multiLangBaseDTO.getId() == null) {
            throw new MultiLangException("无传入id");
        }
        //这里不直接映射的原因是需要用户身份上下文和时间, dto里没有这个字段
        //根据使用策略写入相应字段
        MultiLang multiLang = parse(multiLangBaseDTO, UPDATE);
        //补全字段, 执行映射
        MultiLangUpdate multiLangUpdate = msLangMapper.lang2Update(multiLang);
        //开启事务
        return multiLangTransactionService.update(multiLangUpdate);

}

    /**
     * 删除指定 ID 的多语言记录，并返回延迟生效的提示信息。
     * <p>
     * 由于数据存储在缓存中，并且缓存的过期时间为 {@code EXPIRE_TIME} 秒，
     * 删除操作不会立即同步到缓存，而是允许一定时间的延迟生效。
     * </p>
     *
     * <p><strong>逻辑说明：</strong></p>
     * <ul>
     *     <li>调用 {@code multiLangTransactionService.delete(id)} 执行删除操作。</li>
     *     <li>如果删除成功，则返回提示："修改将在 X 分钟后生效"。</li>
     *     <li>如果数据不存在，返回提示："数据不存在，请检查输入是否正确或等待 X 分钟后生效"。</li>
     *     <li>TODO: 未来可以通过查询当前分页缓存的 Key，更精确地计算过期时间。</li>
     * </ul>
     *
     * @param id 需要删除的多语言记录 ID
     * @return 删除操作的提示信息，说明变更将在何时生效
     */
    @Override
    public String removeMultiLang(String id){
        Boolean delete = multiLangTransactionService.delete(id);
        // todo 这里可以再次查询获取当前分页的缓存key 来更精确的拿到过期时间
        return delete ? "修改将在: " + EXPIRE_TIME/60 + "分钟后生效" : "数据不存在, 请检查输入是否正确或等待: " + EXPIRE_TIME/60 + "分钟后生效";
    }

    /**
     * 刷新 Redis 缓存。
     *
     * <p>此方法查找所有以指定前缀（TAGCODE）开头的缓存 Key，并将其删除，以确保缓存数据的最新性。</p>
     *
     * <p>实现步骤：
     * <ul>
     *     <li>调用 `scanKeys(TAGCODE + ":*")` 方法，匹配所有符合条件的缓存 Key。</li>
     *     <li>如果找到符合条件的 Key，记录日志，并批量删除这些 Key。</li>
     *     <li>返回刷新完成的信息。</li>
     * </ul>
     *
     * <p>注意事项：
     * <ul>
     *     <li>该方法会删除所有匹配的 Key，请确保调用时不会影响正常业务。</li>
     *     <li>日志记录仅在缓存非空时输出，避免冗余日志信息。</li>
     * </ul>
     *
     * @return 刷新状态信息
     */
    @Override
    public String refreshCache() {
        Set<String> keysToDelete = scanKeys(TAGCODE + ":*");
        if (!keysToDelete.isEmpty()) {
            log.info("缓存非空");
            redisTemplate.delete(keysToDelete);
        }
        return "刷新完成";
    }

    /**
     * 使用 SCAN 命令匹配所有符合模式的 Key
     * @param pattern Redis Key 模式，如 "multilang:*"
     * @return 符合条件的 Key 集合
     */
    private Set<String> scanKeys(String pattern) {
        Set<String> keys = redisTemplate.keys(pattern);
        return keys;
    }

    /**
     * 解析并转换 {@link MultiLangBaseDTO} 为 {@link MultiLang} 实体对象。
     * <p>
     * 该方法用于将传入的 DTO 数据转换为数据库存储的多语言实体，并补充创建时间和创建人信息。
     * <br>
     * TODO 拓展性不好, 后期把解析组件解耦改成策略模式, 流程: 1.解析并验证字段合法, 2.写入基础字段, 3.根据策略组合其他的特定字段解析器
     * </p>
     *
     * @param multiLangBaseDTO 多语言基础 DTO，包含 key、上下文和语言编码等信息
     * @return {@link MultiLang} 转换后的多语言实体对象，包含完整的数据库字段信息
     * @throws Exception 可能抛出的异常，通常在用户信息获取失败时发生
     */
    public MultiLang parse(MultiLangBaseDTO multiLangBaseDTO, MultiLangParseStrategy strategy) throws Exception {
        //当前时间
        Timestamp currentTime = new Timestamp(System.currentTimeMillis());
        //新建表记录
        MultiLang multiLang = new MultiLang();
        multiLang.setLangKey(multiLangBaseDTO.getLangKey());
        multiLang.setLangContext(multiLangBaseDTO.getLangContext());
        multiLang.setLangCode(multiLangBaseDTO.getKeyCode());

        if(strategy == UPDATE){
            multiLang.setId(multiLangBaseDTO.getId());
            multiLang.setUpdateDate(currentTime);
            multiLang.setUpdateBy(userHolder.getCurrentUser().getId().toString());
            multiLang.setUpdateName(userHolder.getCurrentUser().getUsername());
        }
        else if(strategy == INSERT){
            multiLang.setCreateDate(currentTime);
            multiLang.setCreateBy(userHolder.getCurrentUser().getId().toString());
            multiLang.setCreateName(userHolder.getCurrentUser().getUsername());
        }
        return multiLang;
    }


    /**
     * 查询 MySQL 以获取多语言数据（如果未命中 Redis 缓存）。
     * <p>
     * 查询逻辑如下：
     * </p>
     * <ul>
     *     <li>传入两个条件：
     *         <pre>{@code
     *         SELECT * FROM t_s_multi_lang
     *         WHERE lang_key = 'lang_key' AND lang_context = 'lang_context'
     *         ORDER BY query.getSort() ASC/DESC
     *         LIMIT query.getPage
     *         }</pre>
     *     </li>
     *     <li>传入一个条件：
     *         <pre>{@code
     *         SELECT * FROM t_s_multi_lang
     *         WHERE lang_key = 'lang_key' OR lang_context = 'lang_context'
     *         ORDER BY query.getSort() ASC/DESC
     *         LIMIT query.getPage
     *         }</pre>
     *     </li>
     *     <li>无条件：
     *         <pre>{@code
     *         SELECT * FROM t_s_multi_lang
     *         ORDER BY query.getSort() ASC/DESC
     *         LIMIT query.getPage
     *         }</pre>
     *     </li>
     * </ul>
     *
     * @return 分页查询结果
     */
    public QueryWrapper<MultiLang> getWrapper(MultiLangQuery multiLangQuery) {

        String langKey = multiLangQuery.getLangKey();
        String langContext = multiLangQuery.getLangContext();
        String order = multiLangQuery.getOrder();
        String sort = multiLangQuery.getSort();
        //动态构造查询
        QueryWrapper<MultiLang> wrapper = new QueryWrapper<>();

        //两个条件
        if (!langContext.isEmpty() && !langKey.isEmpty()) {
            wrapper.like("lang_key", langKey)
                    .like("lang_context", langContext)
                    .orderBy(true, OrderType.isAsc(order), sort);
        }
        //lang_key
        else if (!langKey.isEmpty()) {
            wrapper.like("lang_key", langKey)
                    .orderBy(true, OrderType.isAsc(order), sort);
        }
        //lang_context
        else if (!langContext.isEmpty()) {
            wrapper.like("lang_context", langContext)
                    .orderBy(true, OrderType.isAsc(order), sort);
        }
        //final
        else {
            wrapper.orderBy(true, OrderType.isAsc(order), sort);
        }
        log.info("构建wrapper {}", wrapper);
        return wrapper;
    }

    /**
     * 从 Redis 获取多语言分页数据，如果缓存未命中，则返回 {@code null}。
     * <p>
     * 查询逻辑如下：
     * </p>
     * <ol>
     *     <li>构建 Redis Key：{@code genKey(langKey, langContext, order, sort)}</li>
     *     <li>使用 {@code redisTemplate.opsForZSet().range(key, start, end)} 获取缓存数据</li>
     *     <li>如果缓存命中：
     *         <ul>
     *             <li>转换 {@code Set<Object>} 为 {@code List<MultiLang>}</li>
     *             <li>返回转换后的分页数据</li>
     *         </ul>
     *     </li>
     *     <li>如果缓存未命中，返回 {@code null}</li>
     * </ol>
     *
     * @param key       查询条件, set键值
     * @param start       分页起始索引
     * @param end         分页结束索引
     * @return 多语言分页数据列表，缓存未命中时返回 {@code null}
     */
    public List<MultiLang> getRecords(String key, long start, long end) {
        // 执行缓存查询
        log.info("执行Redis查询");
        Set<Object> result = redisTemplate.opsForZSet().range(key, start, end);
        //缓存击中
        assert result != null;
        if (!result.isEmpty()) {
            List<MultiLang> records = new ArrayList<>();
            // set 转分页记录
            for (Object o :  result) {
                MultiLang lang = (MultiLang) o;
                records.add(lang);
            }
            return records;
        }
        //未击中
        return null;
    }
}