package com.zeroone.star.j1.dashboard.controller;


import com.zeroone.star.j1.dashboard.service.*;
import com.zeroone.star.project.j1.dashboard.DashboardApis;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.ResultStatus;
import com.zeroone.star.project.vo.j1.dashboard.*;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import io.swagger.annotations.ApiParam;
import org.springframework.validation.annotation.Validated;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestParam;
import org.springframework.web.bind.annotation.RestController;

import javax.annotation.Resource;
import javax.validation.constraints.Min;
import java.util.List;

/**
 * <p>
 * 演示示例表 系统首页控制器
 * </p>
 * @author j1-图团
 * @since 2025-02-21
 */
@RestController
@RequestMapping("/dashboard")
@Api(tags = "系统首页接口")
@Validated
public class DashboardController implements DashboardApis {

    @Resource
    IWmImNoticeIService wmImNoticeIService;

    @GetMapping("/query-pend-receipt")
    @ApiOperation(value = "待收货的货物件数-货物待办统计",notes = "该接口属于货物待办模块\n" +
            "此接口利用redis缓存层提高查询效率，请注意，每次测试接口请使用redis可视化客户端，删除云服务器上redis中DASHBOARD目录下的所有key\n"+
            "- 返回：待办货物状态和货物件数")
    @Override
    public JsonVO<GoodsPendingVO> queryPendingReceiptGoodNumber() {
        GoodsPendingVO pendingReceiptGoodNumber = wmImNoticeIService.getReceiptGoodNumber();
        if (pendingReceiptGoodNumber == null){
            throw new RuntimeException("待收货数量查询失败");
        }
        return JsonVO.success(pendingReceiptGoodNumber);
    }
    @Resource
    private IWmInQmIService wmInQmIService;
    @GetMapping("/query-pend-to-up")
    @ApiOperation(value = "待上架的货物件数-货物待办统计",notes = "该接口属于货物待办模块\n" +
            "此接口利用redis缓存层提高查询效率，请注意，每次测试接口请使用redis可视化客户端，删除云服务器上redis中DASHBOARD目录下的所有key\n"+
            "- 返回：待办货物状态和货物件数")
    @Override
    public JsonVO<GoodsPendingVO> queryPendingToUpGoodNumber() {
        GoodsPendingVO toUpGoodNumber = wmInQmIService.getToUpGoodNumber();
        if (toUpGoodNumber == null){
            throw new RuntimeException("待上架数量查询失败");
        }
        return JsonVO.success(toUpGoodNumber);
    }
    @Resource
    private IWmOmQmIService iWmOmQmIService;
    @GetMapping("/query-pend-pick")
    @ApiOperation(value = "待拣货的货物件数-货物待办统计",notes = "该接口属于货物待办模块\n" +
            "此接口利用redis缓存层提高查询效率，请注意，每次测试接口请使用redis可视化客户端，删除云服务器上redis中DASHBOARD目录下的所有key\n"+
            "- 返回：待办货物状态和货物件数")
    @Override
    public JsonVO<GoodsPendingVO> queryPendingPickGoodNumber() {
        GoodsPendingVO pickGoodNumber = iWmOmQmIService.getPickGoodNumber();
        if (pickGoodNumber == null){
            throw new RuntimeException("待拣货数量查询失败");
        }
        return JsonVO.success(pickGoodNumber);
    }

    @GetMapping("/query-cur-pick")
    @ApiOperation(value = "拣货中的货物件数-货物待办统计",notes = "目前线上数据库暂无数据,如需添加测试数据请联系qq:1678599725\n"+"该接口属于货物待办模块\n" +
            "此接口利用redis缓存层提高查询效率，请注意，每次测试接口请使用redis可视化客户端，删除云服务器上redis中DASHBOARD目录下的所有key\n"+
            "- 返回：待办货物状态和货物件数")
    @Override
    public JsonVO<GoodsPendingVO> queryCurrentPickGoodNumber() {
        GoodsPendingVO currentPickGoodNumber = iWmOmQmIService.getCurrentPickGoodNumber();
        if (currentPickGoodNumber == null){
            throw new RuntimeException("拣货中的货物数量查询失败");
        }
        return JsonVO.success(currentPickGoodNumber);
    }

    @Override
    public JsonVO<List<GoodsToUpVO>> queryGoodsToUpNumberTopCount(int count) {
        if (count < 1){
            throw new RuntimeException("请求参数过小");
        }
        if (count > 30){
            throw new RuntimeException("请求参数过大");
        }
        List<GoodsToUpVO> goodsToUpVOList = iWmToUpGoodsService.listTotalGoodsUpNumber(count);
        if (goodsToUpVOList == null){
            throw new RuntimeException("查询失败");
        }
        if (goodsToUpVOList.size() == 0){
            return JsonVO.create(null, ResultStatus.FAIL.getCode(),"查询数据不存在");
        }
        return JsonVO.success(goodsToUpVOList);
    }

    @GetMapping("/query-goods-to-up")
    @ApiOperation(value = "查询上架商品数量Top6，默认返回6位。",
            notes = "此接口利用Redis作为缓存层以提高查询效率。请注意，每次测试调用接口时，请使用redis可视化客户端，删除云服务器上redis中DASHBOARD目录下的所有key\n" +
                    "如果数据库中的数据量少于6条，则返回实际存在的数据。\n" +
                    "- 参数: 可自定义获取多少位的商品\n" +
                    "- 返回: 商品列表，包含商品数量、名称、单位(不是必需项，如果没用单位前端可根据业务需求自行添加单位或不添加)\n"
                   )
    public JsonVO<List<GoodsToUpVO>> queryGoodsUpNumberValidated(
            @ApiParam(value = "查询前count位",example = "6")
            @Min(value = 1, message = "参数不能小于1")
            @RequestParam(defaultValue = "6") int count) {
        return queryGoodsToUpNumberTopCount(count);
    }
    @GetMapping("/query-goods-to-down")
   @ApiOperation(value = "查询下架商品数量Top6，默认返回6位。",
           notes = "此接口利用Redis作为缓存层以提高查询效率。请注意，每次测试接口请使用redis可视化客户端，删除云服务器上redis中DASHBOARD目录下的所有key\n"
           + "如果数据库中的数据量少于6条，则返回实际存在的数据。\n" +
           "- 参数: 可自定义获取多少位的商品\n" +
           "- 返回: 商品列表，包含商品数量、名称、单位(不是必需项，如果没用单位前端可根据业务需求自行添加单位或不添加)\n")
    public JsonVO<List<GoodsToDownVO>> queryGoodsDownNumberValidated(
            @ApiParam(value = "查询前count位",example = "6")
            @Min(value = 1, message = "参数不能小于1")
            @RequestParam(defaultValue = "6") int count) {
        return queryGoodsToDownNumberTopCount(count);
    }

    @GetMapping("/query-goods-to-up-in-recent-days")
   @ApiOperation(value = "查询七天内上架商品数量，默认返回7天",
           notes = "此接口利用redis缓存层提高查询效率，请注意，每次测试接口请使用redis可视化客户端，删除云服务器上redis中DASHBOARD目录下的所有key\n" +
                   "- 缓存过期时间为24小时\n" +
                   "- 参数：获取多少天内的商品数量" +
                   "- 返回：商品列表，包含商品数量，日期")
    public JsonVO<List<GoodsUpInRecentVO>> queryGoodsUpDaysValidated(
            @ApiParam(value = "查询近count天",example = "7")
            @Min(value = 1, message = "参数不能小于1天")
            @RequestParam(defaultValue = "7") int count) {
        return queryGoodsToUpNumberInRecentDays(count);
    }
    @GetMapping("/query-goods-to-down-in-recent-days")
    @ApiOperation(value = "查询七天内下架商品数量，默认返回7天",
            notes = "此接口利用redis缓存层提高查询效率，请注意，每次测试接口请使用redis可视化客户端，删除云服务器上redis中DASHBOARD目录下的所有key\n" +
                    "- 缓存过期时间为24小时\n" +
                    "- 参数：获取多少天内的商品数量\n" +
                    "- 返回：商品列表，包含商品数量，日期")
    public JsonVO<List<GoodsDownInRecentVO>> queryGoodsDownDaysValidated(
            @ApiParam(value = "查询近count天",example = "7")
            @Min(value = 1, message = "参数不能小于1天")
            @RequestParam(defaultValue = "7") int count) {
        return queryGoodsToDownNumberInRecentDays(count);
    }
    @Resource
    private IWmToUpGoodsService iWmToUpGoodsService;
    @Override
    public JsonVO<List<GoodsUpInRecentVO>> queryGoodsToUpNumberInRecentDays(int count) {
        if (count < 1){
            throw new RuntimeException("请求参数过小");
        }
        if (count > 30){
            throw new RuntimeException("请求参数过大");
        }
        List<GoodsUpInRecentVO> goodsUpInRecentVOList = iWmToUpGoodsService.listGoodsToUpNumberInRecentDays(count);
        if (goodsUpInRecentVOList == null){
            throw new RuntimeException("查询失败");
        }
        if (goodsUpInRecentVOList.size() == 0){
            return JsonVO.create(null, ResultStatus.FAIL.getCode(),"查询数据不存在");
        }
        return JsonVO.success(goodsUpInRecentVOList);
    }

    @Override
    public JsonVO<List<GoodsToDownVO>> queryGoodsToDownNumberTopCount(int count) {
        if (count < 1){
            throw new RuntimeException("请求参数过小");
        }
        if (count > 30){
            throw new RuntimeException("请求参数过大");
        }
        List<GoodsToDownVO> goodsToDownVOList = iWmToDownGoodsService.listTotalGoodsDownNumber(count);
        if (goodsToDownVOList == null){
            throw new RuntimeException("查询失败");
        }
        if (goodsToDownVOList.size() == 0){
            return JsonVO.create(null, ResultStatus.FAIL.getCode(),"查询数据不存在");
        }
        return JsonVO.success(goodsToDownVOList);
    }

    @Resource
    private IWmToDownGoodsService iWmToDownGoodsService;
    @Override
    public JsonVO<List<GoodsDownInRecentVO>> queryGoodsToDownNumberInRecentDays(int count) {
        if (count < 1){
            throw new RuntimeException("请求参数过小");
        }
        if (count > 30){
            throw new RuntimeException("请求参数过大");
        }
        List<GoodsDownInRecentVO> goodsDownInRecentVOList = iWmToDownGoodsService.listGoodsDownNumberInRecentDays(count);
        if (goodsDownInRecentVOList == null){
            throw new RuntimeException("查询失败");
        }
        if (goodsDownInRecentVOList.size() == 0){
            return JsonVO.create(null, ResultStatus.FAIL.getCode(),"查询数据不存在");
        }
        return JsonVO.success(goodsDownInRecentVOList);
    }

    @GetMapping("/query-one-day-total-cost-statistics")
    @ApiOperation(value = "近七日内每天的费用合计",notes = "费用合计统计\n" +
            "此接口利用redis缓存层提高查询效率，请注意，每次测试接口请使用redis可视化客户端，删除云服务器上redis中DASHBOARD目录下的所有key\n"+
            "- 参数：获取多少日内费用\n" +
            "- 返回 费用合计列表，包含当天费用，费用日期")
    public JsonVO<List<WmDayCostInRecentVO>> queryOneDayTotalCostValidated(
            @ApiParam(value = "查询近count天",example = "7")
            @Min(value = 1, message = "参数不能小于1天")
            @RequestParam(defaultValue = "7") int count) {
        return queryOneDayTotalCostStatistics(count);
    }
    @Resource
    private IWmDayCostService iWmDayCostService;
    @Override
    public JsonVO<List<WmDayCostInRecentVO>> queryOneDayTotalCostStatistics(int count) {
        if (count < 1){
            throw new RuntimeException("请求参数过小");
        }
        if (count > 90){
            throw new RuntimeException("请求参数过大");
        }
        List<WmDayCostInRecentVO> wmDayCostInRecentVOList = iWmDayCostService.listOneDayTotalCost(count);
        if (wmDayCostInRecentVOList == null){
            throw new RuntimeException("查询失败");
        }
        if (wmDayCostInRecentVOList.size() == 0){
            return JsonVO.create(null, ResultStatus.FAIL.getCode(),"查询的数据不存在");
        }
        return JsonVO.success(wmDayCostInRecentVOList);
    }
}

