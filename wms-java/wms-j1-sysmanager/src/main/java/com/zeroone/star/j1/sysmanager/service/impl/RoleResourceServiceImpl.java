package com.zeroone.star.j1.sysmanager.service.impl;

import com.zeroone.star.j1.sysmanager.entity.*;
import com.zeroone.star.j1.sysmanager.mapper.*;
import com.zeroone.star.j1.sysmanager.service.RoleResourseService;
import com.zeroone.star.project.dto.j1.sysmanager.rolemanager.RoleFunctionAssignmentDTO;
import com.zeroone.star.project.dto.j1.sysmanager.rolemanager.RoleFunctionDTO;
import com.zeroone.star.project.vo.j1.sysmanager.rolemanager.RoleFunctionVO;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import org.springframework.stereotype.Service;
import org.springframework.transaction.annotation.Transactional;

import javax.annotation.Resource;
import java.util.*;
import java.util.stream.Collectors;

/**
 * <p>
 * InnoDB free: 600064 kB; (`parentfunctionid`) REFER `jeecg/t_s_function` 服务实现类
 * </p>
 *
 * @author qpz
 * @since 2025-03-02
 */
@Service
public class RoleResourceServiceImpl implements RoleResourseService {

    private static final Logger logger = LoggerFactory.getLogger(RoleResourceServiceImpl.class);

    @Resource
    private TSFunctionMapper tsFunctionMapper;

    @Resource
    private TSMutiLangMapper tsMutiLangMapper;

    @Resource
    private TSIconMapper tsIconMapper;

    @Resource
    private TSRoleMapper tsRoleMapper;

    @Resource
    private TSRoleFunctionMapper tsRoleFunctionMapper;

    @Override
    public RoleFunctionAssignmentDTO getRoleFunction(String langType) {
        // 1. 查询数据库获取数据
        List<RoleFunctionVO> functionList = tsFunctionMapper.selectFunctions();

        // 2. 读取语言映射
        List<TSMutiLang> langList = tsMutiLangMapper.selectLangs();
        Map<String, String> langMap = new HashMap<>();
        if (langList != null) {
            for (TSMutiLang lang : langList) {
                if (lang != null && lang.getLangCode() != null && lang.getLangCode().equals(langType)) {
                    langMap.put(lang.getLangKey(), lang.getLangContext());
                }
            }
        }

        // 3. 构建图标映射，存储iconPath
        Map<String,String> iconMap = new HashMap<>();
        List<TSIcon> iconList = tsIconMapper.selectIcons();
        logger.info("查询到的图标列表: {}", iconList != null ? iconList : "null");
        if (iconList != null) {
            for (TSIcon icon : iconList) {
                if (icon != null) {
                    iconMap.put(icon.getId(), icon.getPath());
                }
            }
        }

        // 4. 组装 DTO，存入 map 以便后续使用
        Map<String, RoleFunctionDTO> dtoMap = new HashMap<>();
        if (functionList != null) {
            for (RoleFunctionVO function : functionList) {
                if (function == null) {
                    logger.warn("在功能列表中发现空记录");
                    continue;
                }
                if (function.getId() == null) {
                    logger.error("发现无ID的功能项: {}", function);
                    continue;
                }
                RoleFunctionDTO dto = new RoleFunctionDTO();
                //设置id
                dto.setId(function.getId());
                // 处理菜单名称的多语言支持
                String functionName = function.getFunctionName();
                dto.setFunctionName(langMap.getOrDefault(functionName, functionName != null ? functionName : "未命名"));
                dto.setFunctionUrl(function.getFunctionUrl());
                // 处理图标
                String iconId = function.getIconId();
                dto.setImagePath(iconMap.get(iconId));
                dto.setSubItems(new ArrayList<>());
                dto.setFlag("0");
                dtoMap.put(function.getId(), dto);
            }
        }

        // 5. 处理菜单的父子层级关系
        List<RoleFunctionDTO> rootList = new ArrayList<>(); // 存多个根菜单
        if (functionList != null) {
            for (RoleFunctionVO function : functionList) {
                if (function == null) {
                    logger.warn("在功能列表中发现空记录");
                    continue;
                }
                if (function.getParentFunctionId() == null) {
                    RoleFunctionDTO root = dtoMap.get(function.getId());
                    if (root != null) {
                        rootList.add(root);
                    } else {
                        logger.warn("未找到根菜单的 DTO，功能 ID: {}", function.getId());
                    }
                } else {
                    RoleFunctionDTO parent = dtoMap.get(function.getParentFunctionId());
                    if (parent != null) {
                        RoleFunctionDTO child = dtoMap.get(function.getId());
                        if (child != null) {
                            parent.getSubItems().add(child);
                        } else {
                            logger.warn("未找到子菜单的 DTO，功能 ID: {}", function.getId());
                        }
                    } else {
                        logger.warn("未找到父菜单的 DTO，功能 ID: {}", function.getParentFunctionId());
                    }
                }
            }
        }

        // 6. 组装最终 DTO
        RoleFunctionAssignmentDTO assignmentDTO = new RoleFunctionAssignmentDTO();
        assignmentDTO.setRoleCode("admin");
        assignmentDTO.setLangType(langType);
        assignmentDTO.setRoleFunctionAssignment(rootList);

        logger.info("返回的 assignmentDTO: {}", assignmentDTO);
        return assignmentDTO;
    }

    @Override
    public RoleFunctionAssignmentDTO getRoleFunctionAssignment(String roleCode, String langType) {
        RoleFunctionAssignmentDTO assignmentDTO = new RoleFunctionAssignmentDTO();
        assignmentDTO.setRoleCode(roleCode); // 使用传入的 roleCode
        assignmentDTO.setLangType(langType);
        // 1. 查询角色是否存在
        TSRole role = tsRoleMapper.selectByRoleCode(roleCode);
        if (role == null) {
            logger.warn("角色不存在: {}", roleCode);
            assignmentDTO.setError("ROLE_NOT_FOUND", "Role does not exist");
            return assignmentDTO; // 直接返回带错误信息的DTO
        }

        // 2. 查询数据库获取所有功能
        List<RoleFunctionVO> functionList = tsFunctionMapper.selectFunctions();
        System.out.println(functionList);

        // 3. 查询角色的功能权限
        List<TSRoleFunction> roleFunctions = tsRoleFunctionMapper.selectByRoleId(role.getId());
        Map<String, TSRoleFunction> roleFunctionMap = roleFunctions.stream()
                .collect(Collectors.toMap(TSRoleFunction::getFunctionid,roleFunction -> roleFunction));

        // 4. 读取多语言映射
        List<TSMutiLang> langList = tsMutiLangMapper.selectLangs();
        logger.info("查询到的语言列表: {}", langList != null ? langList : "null");
        Map<String, String> langMap = new HashMap<>();
        if (langList != null) {
            for (TSMutiLang lang : langList) {
                if (lang != null && lang.getLangCode() != null && lang.getLangCode().equals(langType)) {
                    langMap.put(lang.getLangKey(), lang.getLangContext());
                }
            }
        }

        // 5. 构建图标映射，存储iconPath
        Map<String,String> iconMap = new HashMap<>();
        List<TSIcon> iconList = tsIconMapper.selectIcons();
        logger.info("查询到的图标列表: {}", iconList != null ? iconList : "null");
        if (iconList != null) {
            for (TSIcon icon : iconList) {
                if (icon != null) {
                    iconMap.put(icon.getId(), icon.getPath());
                }
            }
        }

        // 6. 组装 DTO，存入 map 以便后续使用
        Map<String, RoleFunctionDTO> dtoMap = new HashMap<>();
        if (functionList != null) {
            for (RoleFunctionVO function : functionList) {
                if (function == null) {
                    logger.warn("在功能列表中发现空记录");
                    continue;
                }
                RoleFunctionDTO dto = new RoleFunctionDTO();

                dto.setId(function.getId());

                // 处理菜单名称的多语言支持
                String functionName = function.getFunctionName();
                dto.setFunctionName(langMap.getOrDefault(functionName, functionName != null ? functionName : "未命名"));
                dto.setFunctionUrl(function.getFunctionUrl());

                // 处理图标
                String iconId = function.getIconId();
                if (iconId != null) {
                    dto.setImagePath(iconMap.get(iconId));
                } else {
                    dto.setImagePath("https://example.com/default-icon.png");
                    logger.warn("未找到IconID");
                }
                // 设置权限标志，根据角色功能权限设置 flag
                String functionId = function.getId();
                TSRoleFunction roleFunction = roleFunctionMap.get(functionId);
                dto.setFlag(roleFunction != null ? "1" : "0");
                dto.setSubItems(new ArrayList<>());
                dtoMap.put(functionId, dto);
            }
        }

        // 7. 处理菜单的父子层级关系
        List<RoleFunctionDTO> rootList = new ArrayList<>(); // 存多个根菜单
        if (functionList != null) {
            for (RoleFunctionVO function : functionList) {
                if (function == null) {
                    logger.warn("在功能列表中发现空记录");
                    continue;
                }
                if (function.getParentFunctionId() == null) {
                    RoleFunctionDTO root = dtoMap.get(function.getId());
                    if (root != null) {
                        rootList.add(root);
                    } else {
                        logger.warn("未找到根菜单的 DTO，功能 ID: {}", function.getId());
                    }
                } else {
                    RoleFunctionDTO parent = dtoMap.get(function.getParentFunctionId());
                    if (parent != null) {
                        RoleFunctionDTO child = dtoMap.get(function.getId());
                        if (child != null) {
                            parent.getSubItems().add(child);
                        } else {
                            logger.warn("未找到子菜单的 DTO，功能 ID: {}", function.getId());
                        }
                    } else {
                        logger.warn("未找到父菜单的 DTO，功能 ID: {}", function.getParentFunctionId());
                    }
                }
            }
        }

        // 8. 组装最终 DTO
        assignmentDTO.setRoleFunctionAssignment(rootList);

        logger.info("返回的 assignmentDTO: {}", assignmentDTO);
        return assignmentDTO;
    }

    @Override
    @Transactional(rollbackFor = Exception.class) // 确保事务性操作
    public String setRoleFunction(RoleFunctionAssignmentDTO roleFunctionAssignmentDTO) {
        try {
            // 1. 验证输入参数
            if (roleFunctionAssignmentDTO.getRoleCode() == null) {
                logger.warn("角色编码为空");
                return "失败：角色编码不能为空";
            }

            String roleCode = roleFunctionAssignmentDTO.getRoleCode();

            List<RoleFunctionDTO> roleFunctionAssignmentList = roleFunctionAssignmentDTO.getRoleFunctionAssignment();

            // 2. 根据 roleCode 查询角色
            TSRole role = tsRoleMapper.selectByRoleCode(roleCode);
            if (role == null) {
                logger.warn("未找到对应 roleCode 的角色: {}", roleCode);
                return "没有这个角色";
            }

            String roleId = role.getId();
            logger.debug("查询到的 roleId: {}", roleId);

            // 3. 清空当前角色的所有权限
            tsRoleFunctionMapper.deleteByRoleId(roleId);
            logger.info("已清空 roleId 为 {} 的现有角色功能权限", roleId);

            // 4. 遍历功能树，设置权限
            if (roleFunctionAssignmentList != null) {
                for (RoleFunctionDTO inputDTO : roleFunctionAssignmentList) {
                    processInputFunctionDTO(inputDTO, roleId);
                }
            }

            logger.info("成功为 roleCode: {} 设置角色功能权限", roleCode);
            return "成功：角色功能权限设置完成";

        } catch (Exception e) {
            logger.error("设置角色功能权限失败: ", e);
            return "失败：设置角色功能权限出错，" + e.getMessage();
        }
    }

    private void processInputFunctionDTO(RoleFunctionDTO inputDTO, String roleId) {
        if (inputDTO == null) {
            logger.warn("输入的功能 DTO 无效");
            return;
        }
        String inputFunctionId = inputDTO.getId();
        String inputFunctionUrl = inputDTO.getFunctionUrl();
            if ("1".equals(inputDTO.getFlag())) {
                TSRoleFunction roleFunction = new TSRoleFunction();
                roleFunction.setId(UUID.randomUUID().toString().replace("-", ""));
                roleFunction.setRoleid(roleId);
                roleFunction.setFunctionid(inputFunctionId);
                roleFunction.setOperation(inputFunctionUrl);
                //roleFunction.setDatarule("default_data_rule");
                tsRoleFunctionMapper.insert(roleFunction);
                logger.info("插入角色-功能映射: roleId={}, functionId={}", roleId, inputFunctionId);
            } else {
                logger.debug("flag 不为 1，跳过插入: functionName={}, flag={}", inputDTO.getFunctionName(), inputDTO.getFlag());
            }

        // 递归处理子项
        List<RoleFunctionDTO> inputSubItems = inputDTO.getSubItems();
        if (inputSubItems != null) {
            for (RoleFunctionDTO subDTO : inputSubItems) {
                processInputFunctionDTO(subDTO, roleId);
            }
        }
    }
    //废弃版
//    private void processInputFunctionDTO(RoleFunctionDTO inputDTO, String roleId) {
//        if (inputDTO == null) {
//            logger.warn("输入的功能 DTO 无效");
//            return;
//        }
//        String inputFunctionUrl = inputDTO.getFunctionUrl();
//        String inputParentId = inputDTO.getParentId();
//        String inputOrder = inputDTO.getFunctionOrder();
//
//        // 如果 functionUrl 和 parentId 都为空或空字符串，则跳过当前功能，但继续处理子项
//        boolean isEmptyFunction = (inputFunctionUrl == null || inputFunctionUrl.trim().isEmpty()) &&
//                (inputParentId == null || inputParentId.trim().isEmpty());
//
//        if (!isEmptyFunction) {
//            // 使用 functionUrl 和 parentId 查找匹配的 functionId
//            String matchedFunctionId = tsFunctionMapper.selectIdByFunctionUrlAndParentId(inputFunctionUrl, inputOrder,inputParentId);
//            if (matchedFunctionId == null) {
//                logger.warn("未找到匹配的功能，functionUrl: {}, parentId: {}", inputFunctionUrl, inputParentId);
//            } else if ("1".equals(inputDTO.getFlag())) {
//                TSRoleFunction roleFunction = new TSRoleFunction();
//                roleFunction.setId(UUID.randomUUID().toString().replace("-", ""));
//                roleFunction.setRoleid(roleId);
//                roleFunction.setFunctionid(matchedFunctionId);
//                roleFunction.setOperation(inputFunctionUrl);
//                roleFunction.setDatarule("default_data_rule");
//                tsRoleFunctionMapper.insert(roleFunction);
//                logger.info("插入角色-功能映射: roleId={}, functionId={}", roleId, matchedFunctionId);
//            } else {
//                logger.debug("flag 不为 1，跳过插入: functionName={}, flag={}", inputDTO.getFunctionName(), inputDTO.getFlag());
//            }
//        } else {
//            logger.debug("functionUrl 和 parentId 均为空，跳过当前功能设置: functionName={}", inputDTO.getFunctionName());
//        }
//
//        // 递归处理子项
//        List<RoleFunctionDTO> inputSubItems = inputDTO.getSubItems();
//        if (inputSubItems != null) {
//            for (RoleFunctionDTO subDTO : inputSubItems) {
//                processInputFunctionDTO(subDTO, roleId);
//            }
//        }
//    }
}