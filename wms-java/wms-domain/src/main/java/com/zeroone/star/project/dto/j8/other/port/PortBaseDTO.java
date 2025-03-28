    package com.zeroone.star.project.dto.j8.other.port;

    import com.alibaba.excel.annotation.ExcelProperty;
    import com.fasterxml.jackson.annotation.JsonInclude;
    import io.swagger.annotations.ApiModel;
    import io.swagger.annotations.ApiModelProperty;
    import lombok.AllArgsConstructor;
    import lombok.Data;
    import lombok.NoArgsConstructor;

    @Data
    @NoArgsConstructor
    @AllArgsConstructor
    @JsonInclude(JsonInclude.Include.ALWAYS)
    @ApiModel("港口信息继承数据模型")
    public class PortBaseDTO {
        @ApiModelProperty(value = "港口id", example = "1")
        @ExcelProperty("港口id")
        private String id;
        @ApiModelProperty(value = "港口代码", example = "")
        @ExcelProperty("港口代码")
        private String portCode;
        @ApiModelProperty(value = "中文名称", example = "")
        @ExcelProperty("中文名称")
        private String portZhName;
        @ApiModelProperty(value = "英文名称", example = "")
        @ExcelProperty("英文名称")
        private String portEnName;
        @ApiModelProperty(value = "港口三字代码", example = "")
        @ExcelProperty("港口三字代码")
        private String portThCode;
        @ApiModelProperty(value = "港口UNCODE", example = "")
        @ExcelProperty("港口UNCODE")
        private String portUcode;
        @ApiModelProperty(value = "港口代码1", example = "")
        @ExcelProperty("港口代码1")
        private String portCode1;
        @ApiModelProperty(value = "港口代码2", example = "")
        @ExcelProperty("港口代码2")
        private String portCode2;
        @ApiModelProperty(value = "备注", example = "")
        @ExcelProperty("备注")
        private String portText;
        @ApiModelProperty(value = "停用", example = "")
        @ExcelProperty("停用")
        private String portDel;
    }
