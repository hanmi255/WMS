package com.zeroone.star.daycheck.service;


import com.zeroone.star.daycheck.entity.YichangDown;
import com.zeroone.star.project.dto.j3.daycheck.Arr.YichangDownDTO;
import com.zeroone.star.project.query.j3.daycheck.Arr.YichangDownQuery;

import java.util.List;

public interface YichangDownService {

    List<YichangDownDTO> getYichangDownPage(YichangDownQuery condition);

    List<YichangDown> getYichangDownDate();
}
