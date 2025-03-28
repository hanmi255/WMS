package com.zeroone.star.project.vo.j2.sysmgr;

import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j2.sysmgr.UserDTO;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;

import java.util.List;

/**
 * @author Henry
 */
@Data
@ApiModel(value = "ListUser")
@AllArgsConstructor
@NoArgsConstructor
public class ListUserVO {
    @ApiModelProperty(value = "成员列表")
    private PageDTO<UserDTO> userDTOList;
}
