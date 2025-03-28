package com.zeroone.star.j5.basezl.utils;

import com.zeroone.star.project.components.fastdfs.FastDfsClientComponent;
import com.zeroone.star.project.components.fastdfs.FastDfsFileInfo;
import org.springframework.beans.factory.annotation.Value;
import org.springframework.http.ResponseEntity;
import org.springframework.stereotype.Component;
import org.springframework.web.multipart.MultipartFile;

import javax.annotation.Resource;


/**
 * <p>
 *  封装附件的上传，下载，删除功能
 * </p>
 *
 * @author 杨芋
 * @since 2025-02-27
 */
@Component
public class FileUtil {
    @Resource
    private FastDfsClientComponent dfs;
    @Value("${fastdfs.nginx-servers}")
    private String fileServerUrl;

    /**
     * 附件的上传
     * @param file 要上传的附件内容
     * @return 上传后文件的信息 格式："group/storageId/文件名.格式"
     */
    public String uploadFile(MultipartFile file) throws Exception {
        String fileSuffix = file.getOriginalFilename().substring(file.getOriginalFilename().lastIndexOf("."));
        FastDfsFileInfo info = dfs.uploadFile(file.getBytes(), fileSuffix);
        return info.getGroup()+"/"+info.getStorageId()+"/"+file.getOriginalFilename();
    }
    /**
     * 附件的下载
     * @param info 文件的信息
     * @return 下载地址
     */
    public String downloadFile(String info) throws Exception {
        return dfs.fetchUrl(makeInfo(info), fileServerUrl, true);
    }
    /**
     * 附件的删除
     * @param info 文件的信息
     * @return 删除结果 0表示删除成功
     */
    public int deleteFile(String info) throws Exception {
        return dfs.deleteFile(makeInfo(info));
    }

    /**
     * 创建FastDfsFileInfo
     * @param info 文件的信息
     * @return 创建对象
     */
    protected FastDfsFileInfo makeInfo(String info) {
        // info内容："group/storageId/文件名.格式"
        //group1/M00/00/01/oYYBAGfTLfSAWPmgAAAYAJ-ulaA88..xls/客户.xls
        int last = info.lastIndexOf("/");
        int first=info.indexOf("/");
        return FastDfsFileInfo.builder()
                .group(info.substring(0,first))
                .storageId(info.substring(first+1,last))
                .build();
    }

}
