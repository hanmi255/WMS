package com.zeroone.star.project.dto.j4.automaticEncoding;

import io.swagger.annotations.ApiModel;
import lombok.Getter;
import lombok.Setter;
import lombok.ToString;

import java.util.List;

/**
 * @title NumberingTypeDTO
 * @date 2025/2/24
 * @description 编号类型 DTO
 */

@ToString
@Getter
@Setter
@ApiModel("删除编码(支持批量删除)")
public class DeleteEncodingDTO {
    private List<String> ids;  // 批量删除时使用的 ID 列表
}
