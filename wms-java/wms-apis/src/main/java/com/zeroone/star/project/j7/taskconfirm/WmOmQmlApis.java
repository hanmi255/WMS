package com.zeroone.star.project.j7.taskconfirm;

import com.zeroone.star.project.dto.j7.taskconfirm.WaveGenDTO;
import com.zeroone.star.project.vo.JsonVO;
import org.springframework.web.bind.annotation.RequestBody;

/**
 * @Author LongLive
 * 描述: 任务删除(支持批量)、波次生成(支持批量)、导出数据
 */
public interface WmOmQmlApis {
    /**
     * 波次生成
     * @param ids 波次生成的id集合
     * @return 状态
     */
    public JsonVO waveGene( WaveGenDTO ids);

    /**
     * 任务删除
     * @param ids 波次生成的id集合
     * @return
     */
    public JsonVO rmMission(WaveGenDTO ids);

    /**
     * 导出数据
     * //todo 后期可能会需要传入用户标识的id来进行websocket的单播发送文件(目前是广播)
     * @return
     */
    public JsonVO<String> expoExcel();
}
