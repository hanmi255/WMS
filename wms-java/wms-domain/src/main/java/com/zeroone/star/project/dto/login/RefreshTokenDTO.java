package com.zeroone.star.project.dto.login;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

/**
 * <p>
 * 描述：凭证刷新请求数据对象
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 * @author 阿伟学长
 * @version 1.0.0
 */
@ApiModel("凭证刷新请求数据对象")
@Data
public class RefreshTokenDTO {
    /**
     * 访问令牌
     */
    @ApiModelProperty(value = "授权令牌", required = true, example = "eyJhbGciOiJSUzI1NiIsInR5cCI6IkpXVCJ9.eyJ1c2VyX25hbWUiOiJhZG1pbiIsInNjb3BlIjpbImFsbCJdLCJpZCI6MSwiZXhwIjoxNjAwNzU4NjEzLCJhdXRob3JpdGllcyI6WyJBRE1JTiJdLCJqdGkiOiI2ZWY3MTkzNS04Yjk0LTQ0YzQtOGRhNC0wODhhMTVmOGQ5NzkiLCJjbGllbnRfaWQiOiJoZWFsdGgtY2xpZW50In0.RY6Eu9O35SRbtxOKrP0Db-kl7A9QK8XBr7KCP2Qnx1bGCoHm9v3OnXbOgZ95QMuo117wS3t8KyCAHIhclrDykl5kf_sV2_FrnrzZWYb8kSDB6pPKSSJLTWTud1eN9W07K2OKh9DHtDEW3CdnHXeV9I3yGJhIYuSaWcmq4pqOSd3UFktEcvUIQewcbdppsgT_CWngaXn88wNCmHjClvBuFuXL9r67_QwvWqJr1iCMrF9tOo993PzxP1P2zDkRwnINy9lRxly7lIkJ4Um5w7v4eeJmYo5e3VliagACKM-MOKqB6cy8nqUMkLW5r-t_74h_yxcjKdan0jRcjcpCXcHsrA")
    private String token;

    /**
     * 刷新令牌
     */
    @ApiModelProperty(value = "刷新令牌", required = true, example = "eyJhbGciOiJSUzI1NiIsInR5cCI6IkpXVCJ9.eyJ1c2VyX25hbWUiOiJhZG1pbiIsInNjb3BlIjpbImFsbCJdLCJhdGkiOiI2ZWY3MTkzNS04Yjk0LTQ0YzQtOGRhNC0wODhhMTVmOGQ5NzkiLCJpZCI6MSwiZXhwIjoxNjAwODQxNDEzLCJhdXRob3JpdGllcyI6WyJBRE1JTiJdLCJqdGkiOiJlMjU3ZDFjNi02Mzk0LTRkODItYmIxOC1mY2I4ZDBkOTczNzciLCJjbGllbnRfaWQiOiJoZWFsdGgtY2xpZW50In0.I2kxj_sOJZ2Ui2Hd8aPCPzCE-vP8kq4L6WXjBgrFUXahismN2ipRuqaMTzxC_sWBPaSjTSsElmYiN5q95ktm_QwLZbQkPb0wi2l9CggVKWSOpoz6QorIfpCh63Tc_GR3vPT6W9M2tdBiDtX477O5ddAmgAoXf62foOL-AjcCxSryTLrdICGbBq2ZArOGvKhF5NInF7BHX2LYTJF5Yt9B0y5YMdKdmIoMJwQLgPWwxktfHOjx2s-DordJEKjKSmLWkq9qa6MgxgYJQM7Ex-8obEtoxkEDDloC3SAZK_53YffnO14kY4025cWLH4N0p_RbrGPPz9bBthVO8YOog9nfGA")
    private String refreshToken;
}
