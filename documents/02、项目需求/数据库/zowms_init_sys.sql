-- ----------------------------
--  Change database
-- ----------------------------
USE `zo_wms`;

SET NAMES utf8mb4;
SET FOREIGN_KEY_CHECKS = 0;

-- ----------------------------
-- Records of t_s_function
-- ----------------------------
-- INSERT INTO `t_s_function` VALUES ('2c90ac564c9d1734014c9d6f4e370024', NULL, 1, 'menu.graph.configuration', '4', 'jformGraphreportHeadController.do?jformGraphreportHead', '8a8ab0b246dc81120146dc8180ce0019', '8a8ab0b246dc81120146dc8180460000', '8a8ab0b246dc81120146dc8180dd001e', 0, NULL, NULL, NULL, NULL, NULL, NULL, NULL);
-- TODO 需要后续补充

-- ----------------------------
-- Records of t_s_operation
-- ----------------------------
-- INSERT INTO `t_s_operation` VALUES ('2c9221a471e7ec49017207089d2611bb', 'delinqm', NULL, '删除', 0, '4028b8815e5272f8015e527538d80001', '8a8ab0b246dc81120146dc8180460000', 0);
-- TODO 需要后续补充

-- ----------------------------
-- Records of t_s_depart
-- ----------------------------
INSERT INTO `t_s_depart` VALUES ('2c9221a470adc6fc0170ecef9dd4029e', '厦门境图智能科技有限公司', '', NULL, 'A05', '1', '', '', '', NULL);
INSERT INTO `t_s_depart` VALUES ('40289fe393dddaa90193de2cb61a0004', '零壹星球', '零壹星球', NULL, 'A07', '1', '', '', '', NULL);
INSERT INTO `t_s_depart` VALUES ('40289fe393dddaa90193de2d15600006', '成都总部', '', '40289fe393dddaa90193de2cb61a0004', 'A07A01', '2', '', '', '', NULL);
INSERT INTO `t_s_depart` VALUES ('40289fe393dddaa90193de2d53f10008', '上海总部', '', '40289fe393dddaa90193de2cb61a0004', 'A07A02', '2', '', '', '', NULL);
INSERT INTO `t_s_depart` VALUES ('40289fe393dddaa90193de2e15d9000a', '研发总监', '', '40289fe393dddaa90193de2d15600006', 'A07A01A01', '3', '', '', '', NULL);
INSERT INTO `t_s_depart` VALUES ('40289fe393dddaa90193de2eb5b8000c', '远程助理', '', '40289fe393dddaa90193de2d15600006', 'A07A01A02', '3', '', '', '', NULL);
-- TODO 需要后续补充

-- ----------------------------
-- Records of t_s_base_user
-- ----------------------------
INSERT INTO `t_s_base_user` VALUES ('2c9221a4717bb44c01717d01c6ff0540', NULL, NULL, '33beb63a7f11dbd2', '管理员', NULL, 1, '管理员', 'admin', NULL, 0, NULL);
INSERT INTO `t_s_base_user` VALUES ('2c9efaca91697e9801927b9e64a64df4', NULL, NULL, '1d0e59dd06ac82c5', '', NULL, 1, '测试', '123', NULL, 1, NULL);
INSERT INTO `t_s_base_user` VALUES ('402880d38e31819a018e31b1bfa8001f', NULL, NULL, '5c380ff69c5ca5a5a6ed9f0898b7197a', '财务', NULL, 1, '财务', 'caiwu001', NULL, 0, NULL);
INSERT INTO `t_s_base_user` VALUES ('402880d38e31819a018e31b2a9430023', NULL, NULL, 'e45e1f91dba1dd6252934ad6f735fe20', '仓库', NULL, 1, '仓管', 'cangku001', NULL, 1, NULL);
INSERT INTO `t_s_base_user` VALUES ('402880d38e31819a018e31b35caa0027', NULL, NULL, '78b751224eba2b51c61c91c907a337a9', '运营', NULL, 1, '管理员', 'yunying001', NULL, 0, NULL);
-- TODO 需要后续补充

-- ----------------------------
-- Records of t_s_role
-- ----------------------------
INSERT INTO `t_s_role` VALUES ('2c9221a4717bb44c01717ce20ca00411', 'cs', '测试', NULL, NULL, NULL, '初始', '2020-04-15 16:08:41', 'admin');
INSERT INTO `t_s_role` VALUES ('2c9221a4717bb44c01717ced1eb70425', 'ckjl', '仓库经理', '初始', '2020-04-15 16:22:26', 'admin', NULL, NULL, NULL);
INSERT INTO `t_s_role` VALUES ('2c9221a4717bb44c01717cf9cc2a04e6', 'cg', '仓管', '初始', '2020-04-15 16:37:26', 'admin', NULL, NULL, NULL);
INSERT INTO `t_s_role` VALUES ('4028804072de5db40172df63e359001d', 'KH', '客户', NULL, NULL, NULL, '管理员', '2020-06-23 12:16:05', 'admin');
INSERT INTO `t_s_role` VALUES ('402880d38e31819a018e31acabd0000a', 'cw', '财务', NULL, NULL, NULL, '管理员', '2024-03-12 15:59:44', 'admin');
INSERT INTO `t_s_role` VALUES ('8a8ab0b246dc81120146dc8181870050', 'gly', '管理员', '初始', '2020-04-15 16:33:39', 'admin', NULL, NULL, NULL);

-- ----------------------------
-- Records of t_s_role_function
-- ----------------------------
-- INSERT INTO `t_s_role_function` VALUES ('2c9221a4717bb44c01717ce52282041f', NULL, NULL, '402880e74d75c4dd014d75d3c5f40001', NULL);
-- TODO 需要后续补充

-- ----------------------------
-- Records of t_s_role_org
-- ----------------------------
INSERT INTO `t_s_role_org` VALUES ('40289fe393dddaa90193def804c00010', '2c9221a470adc6fc0170ecef9dd4029e', '4028804072de5db40172df63e359001d');

-- ----------------------------
-- Records of t_s_role_user
-- ----------------------------
INSERT INTO `t_s_role_user` VALUES ('2c9221a4717bb44c01717d01c7140542', '8a8ab0b246dc81120146dc8181870050', '2c9221a4717bb44c01717d01c6ff0540');
INSERT INTO `t_s_role_user` VALUES ('2c9efaca91697e9801927b9ea5c44df9', '2c9221a4717bb44c01717ce20ca00411', '2c9efaca91697e9801927b9e64a64df4');
INSERT INTO `t_s_role_user` VALUES ('402880d38e31819a018e31b1bfb20021', '402880d38e31819a018e31acabd0000a', '402880d38e31819a018e31b1bfa8001f');
INSERT INTO `t_s_role_user` VALUES ('402880d38e31819a018e31b2a94e0025', '2c9221a4717bb44c01717cf9cc2a04e6', '402880d38e31819a018e31b2a9430023');
INSERT INTO `t_s_role_user` VALUES ('402880d38e31819a018e355af7e00242', '8a8ab0b246dc81120146dc8181870050', '402880d38e31819a018e31b35caa0027');

-- ----------------------------
-- Records of t_s_user
-- ----------------------------
INSERT INTO `t_s_user` VALUES ('2c9221a4717bb44c01717d01c6ff0540', '', '', '', NULL, '管理员', '2024-03-21 09:09:03', 'admin', '黄文平', '2020-04-15 16:43:21', 'hwp', '4');
INSERT INTO `t_s_user` VALUES ('2c9efaca91697e9801927b9e64a64df4', '', '', '', NULL, '管理员', '2024-10-16 14:14:52', 'admin', '管理员', '2024-10-11 20:47:11', 'admin', '4');
INSERT INTO `t_s_user` VALUES ('402880d38e31819a018e31b1bfa8001f', '', '', '', NULL, '管理员', '2024-12-17 00:48:38', 'admin', '管理员', '2024-03-12 16:05:16', 'admin', '4');
INSERT INTO `t_s_user` VALUES ('402880d38e31819a018e31b2a9430023', '', '', '', NULL, '管理员', '2024-10-10 22:58:40', 'admin', '管理员', '2024-03-12 16:06:16', 'admin', '4');
INSERT INTO `t_s_user` VALUES ('402880d38e31819a018e31b35caa0027', '', '', '', NULL, '管理员', '2024-09-25 16:09:30', 'admin', '管理员', '2024-03-12 16:07:02', 'admin', '4');

-- ----------------------------
-- Records of t_s_user_org
-- ----------------------------
INSERT INTO `t_s_user_org` VALUES ('2c9221a4717bb44c01717d01c70c0541', '2c9221a4717bb44c01717d01c6ff0540', '2c9221a470adc6fc0170ecef9dd4029e');
INSERT INTO `t_s_user_org` VALUES ('402880d38e31819a018e31b1bfae0020', '402880d38e31819a018e31b1bfa8001f', '2c9221a470adc6fc0170ecef9dd4029e');
INSERT INTO `t_s_user_org` VALUES ('402880d38e31819a018e31b2a94a0024', '402880d38e31819a018e31b2a9430023', '2c9221a470adc6fc0170ecef9dd4029e');
INSERT INTO `t_s_user_org` VALUES ('402880d38e31819a018e355af7d70241', '402880d38e31819a018e31b35caa0027', '2c9221a470adc6fc0170ecef9dd4029e');
INSERT INTO `t_s_user_org` VALUES ('40289fe393dddaa90193df14c5ab0012', '2c9efaca91697e9801927b9e64a64df4', '40289fe393dddaa90193de2cb61a0004');

-- Records of t_s_type
-- ----------------------------
INSERT INTO `t_s_type` VALUES ('297e201047e95ee30147e9baab5c000b', '1', 'common.company', NULL, '297e201047e95ee30147e9ba56ce0009', '2016-09-04 22:19:12', '管理员');
INSERT INTO `t_s_type` VALUES ('297e201047e95ee30147e9baef97000d', '2', 'common.department', NULL, '297e201047e95ee30147e9ba56ce0009', '2016-09-04 22:19:12', '管理员');
INSERT INTO `t_s_type` VALUES ('297e201047e95ee30147e9bb1210000f', '3', 'common.position', NULL, '297e201047e95ee30147e9ba56ce0009', '2016-09-04 22:19:12', '管理员');
INSERT INTO `t_s_type` VALUES ('2c90ac564c9d1734014c9db1e025002d', 'Y', '是', NULL, '2c90ac564c9d1734014c9db1a167002b', '2016-09-04 22:19:12', '管理员');
INSERT INTO `t_s_type` VALUES ('2c90ac564c9d1734014c9db20b0d002f', 'N', '否', NULL, '2c90ac564c9d1734014c9db1a167002b', '2016-09-04 22:19:12', '管理员');
INSERT INTO `t_s_type` VALUES ('2c9221a470adc6fc0170fb1e93860369', 'test', 'test', NULL, '2c9221a470adc6fc0170fb1e61930367', '2020-03-21 11:24:10', '初始');
INSERT INTO `t_s_type` VALUES ('4028804074beadae0174f72733a4140a', '已确认', '已确认', NULL, '402881886017fd0801601ad37a230023', '2020-10-05 13:06:16', '管理员');
INSERT INTO `t_s_type` VALUES ('402880884883eff4014884180bf80029', '1', '蔷薇七村', NULL, '402880884883eff401488415cbb60027', '2016-09-04 22:19:12', '管理员');
INSERT INTO `t_s_type` VALUES ('402880cd4dbd4baa014dbd9c184f0003', 'WXTP', '图片', NULL, 'jglongjbtstypegourp2015060400001', '2016-09-04 22:19:12', '管理员');
INSERT INTO `t_s_type` VALUES ('402881885ee7c2e4015eec89d19e01e8', 'I', '初始', NULL, '2c90ac564c9d1734014c9db1a167002b', '2017-10-05 20:36:49', 'admin');
INSERT INTO `t_s_type` VALUES ('402881885f117b37015f152b5197006e', '良品', '良品', NULL, '402881885f117b37015f152afeb4006c', '2017-10-13 17:58:01', 'admin');
INSERT INTO `t_s_type` VALUES ('402881885f117b37015f152b6c530070', '不良品', '不良品', NULL, '402881885f117b37015f152afeb4006c', '2017-10-13 17:58:08', 'admin');
INSERT INTO `t_s_type` VALUES ('402881886017fd0801601ad3bad60025', '计划中', '计划中', NULL, '402881886017fd0801601ad37a230023', '2017-12-03 13:22:52', 'admin');
INSERT INTO `t_s_type` VALUES ('402881886017fd0801601ad3dbac0027', '已完成', '已完成', NULL, '402881886017fd0801601ad37a230023', '2017-12-03 13:23:00', 'admin');
INSERT INTO `t_s_type` VALUES ('402881886017fd0801601ad414ae0029', '已过帐', '已过帐', NULL, '402881886017fd0801601ad37a230023', '2017-12-03 13:23:15', 'admin');
INSERT INTO `t_s_type` VALUES ('402881886017fd0801601ad4460f002b', '库存不足', '库存不足', NULL, '402881886017fd0801601ad37a230023', '2017-12-03 13:23:27', 'admin');
INSERT INTO `t_s_type` VALUES ('402881886017fd0801601ad4a814002d', '储位不存在', '储位不存在', NULL, '402881886017fd0801601ad37a230023', '2017-12-03 13:23:52', 'admin');
INSERT INTO `t_s_type` VALUES ('402881886017fd0801601ad675c0002f', '已删除', '已删除', NULL, '402881886017fd0801601ad37a230023', '2017-12-03 13:25:51', 'admin');
INSERT INTO `t_s_type` VALUES ('402881a151f1af7c0151f1bb1b520004', 'cigong', '辞工', NULL, '402881a151f1af7c0151f1b9d7f50002', '2016-09-04 22:19:12', '管理员');
INSERT INTO `t_s_type` VALUES ('402881a151f1af7c0151f1bc55b10006', 'jicigong', '急辞工', NULL, '402881a151f1af7c0151f1b9d7f50002', '2016-09-04 22:19:12', '管理员');
INSERT INTO `t_s_type` VALUES ('402881a151f1af7c0151f1bca0680008', 'citui', '辞退', NULL, '402881a151f1af7c0151f1b9d7f50002', '2016-09-04 22:19:12', '管理员');
INSERT INTO `t_s_type` VALUES ('402881a151f1af7c0151f1bcbf62000a', 'kaichu', '开除', NULL, '402881a151f1af7c0151f1b9d7f50002', '2016-09-04 22:19:12', '管理员');
INSERT INTO `t_s_type` VALUES ('402881a151f1af7c0151f1bce839000c', 'zidonglizhi', '自动离职', NULL, '402881a151f1af7c0151f1b9d7f50002', '2016-09-04 22:19:12', '管理员');
INSERT INTO `t_s_type` VALUES ('402881e44df713f5014df73ef09a003d', 'table', 'form.db.type.table', NULL, '402881e44df713f5014df738349c002f', '2016-09-04 22:19:12', '管理员');
INSERT INTO `t_s_type` VALUES ('402881e44df713f5014df73f1436003f', 'sql', 'form.db.type.sql', NULL, '402881e44df713f5014df738349c002f', '2016-09-04 22:19:12', '管理员');
INSERT INTO `t_s_type` VALUES ('402881e44df713f5014df73f3f830041', 'clazz', 'form.db.type.clazz', NULL, '402881e44df713f5014df738349c002f', '2016-09-04 22:19:12', '管理员');
INSERT INTO `t_s_type` VALUES ('402881e54dcb624a014dcbf65e5a0010', 'bdfl_ptbd', '普通表单', NULL, '402881e54dcb624a014dcbf4912b000e', '2016-09-04 22:19:12', '管理员');
INSERT INTO `t_s_type` VALUES ('402881e54dcb624a014dcbf6a4620012', 'bdfl_fzbd', '复杂表单', NULL, '402881e54dcb624a014dcbf4912b000e', '2016-09-04 22:19:12', '管理员');
INSERT INTO `t_s_type` VALUES ('402881e54dce16ba014dce17990c0001', 'bdfl_vipbd', 'VIP表单', NULL, '402881e54dcb624a014dcbf4912b000e', '2016-09-04 22:19:12', '管理员');
INSERT INTO `t_s_type` VALUES ('402881e55af64f07015af683bd930006', 'text', '单行文本输入框', NULL, '402881e55af64f07015af68356550004', '2017-03-22 22:55:13', '管理员');
INSERT INTO `t_s_type` VALUES ('402881e55af64f07015af683f8910008', 'textarea', '多行文本输入框', NULL, '402881e55af64f07015af68356550004', '2017-03-22 22:55:28', '管理员');
INSERT INTO `t_s_type` VALUES ('402881e55af64f07015af6866f2f000a', 'select', '下拉菜单', NULL, '402881e55af64f07015af68356550004', '2017-03-22 22:58:10', '管理员');
INSERT INTO `t_s_type` VALUES ('402881e55af64f07015af686a8ca000c', 'radios', '单选框', NULL, '402881e55af64f07015af68356550004', '2017-03-22 22:58:25', '管理员');
INSERT INTO `t_s_type` VALUES ('402881e55af64f07015af686eb55000e', 'checkboxs', '复选框', NULL, '402881e55af64f07015af68356550004', '2017-03-22 22:58:42', '管理员');
INSERT INTO `t_s_type` VALUES ('402881e55af64f07015af689cf09001a', 'button', 'Button按钮控件', NULL, '402881e55af64f07015af68356550004', '2017-03-22 23:01:51', '管理员');
INSERT INTO `t_s_type` VALUES ('402881e55b05c578015b060cbe480009', 'timeText', '时间控件精确秒', NULL, '402881e55af64f07015af68356550004', '2017-03-25 23:19:10', '管理员');
INSERT INTO `t_s_type` VALUES ('402881e55b05c578015b060d087f000b', 'dateText', '时间控件精确天', NULL, '402881e55af64f07015af68356550004', '2017-03-25 23:19:29', '管理员');
INSERT INTO `t_s_type` VALUES ('402881e64ca6fd1b014ca7052d930006', 'spline', '曲线图', NULL, '402881e64ca6fd1b014ca7044c370004', '2016-09-04 22:19:12', '管理员');
INSERT INTO `t_s_type` VALUES ('402881e64ca6fd1b014ca705b2b40008', 'column', '柱状图', NULL, '402881e64ca6fd1b014ca7044c370004', '2016-09-04 22:19:12', '管理员');
INSERT INTO `t_s_type` VALUES ('402881e64ca6fd1b014ca7061fb7000a', 'pie', '饼图', NULL, '402881e64ca6fd1b014ca7044c370004', '2016-09-04 22:19:12', '管理员');
INSERT INTO `t_s_type` VALUES ('402881e946e71f5f0146e736c4e80008', 'en', 'common.english', NULL, '402881e946e71f5f0146e73619bb0002', '2016-09-04 22:19:12', '管理员');
INSERT INTO `t_s_type` VALUES ('402881e946e71f5f0146e740dcad0012', 'zh-cn', 'common.chinese', NULL, '402881e946e71f5f0146e73619bb0002', '2016-09-04 22:19:12', '管理员');
INSERT INTO `t_s_type` VALUES ('402882ec69f490a30169f4ae73210004', '自提', '自提', NULL, '402882ec69f490a30169f4ae4f960002', '2019-04-07 06:04:27', '初始');
INSERT INTO `t_s_type` VALUES ('402882ec69f490a30169f4ae8fe80006', '送达', '送达', NULL, '402882ec69f490a30169f4ae4f960002', '2019-04-07 06:04:35', '初始');
INSERT INTO `t_s_type` VALUES ('402882ec69f490a30169f4af5650000a', '是', '是', NULL, '402882ec69f490a30169f4af32250008', '2019-04-07 06:05:25', '初始');
INSERT INTO `t_s_type` VALUES ('402882ec69f490a30169f4af6c49000c', '否', '否', NULL, '402882ec69f490a30169f4af32250008', '2019-04-07 06:05:31', '初始');
INSERT INTO `t_s_type` VALUES ('4028838850c35b6a0150c372e3b10005', '*', '非空', NULL, '4028838850c35b6a0150c37251e00002', '2016-09-04 22:19:12', '管理员');
INSERT INTO `t_s_type` VALUES ('4028838850c35b6a0150c3abef800019', 'n', '数字', NULL, '4028838850c35b6a0150c37251e00002', '2016-09-04 22:19:12', '管理员');
INSERT INTO `t_s_type` VALUES ('4028838850c35b6a0150c3ac17f9001b', 's', '字母', NULL, '4028838850c35b6a0150c37251e00002', '2016-09-04 22:19:12', '管理员');
INSERT INTO `t_s_type` VALUES ('4028838850d2666a0150d267a61e0001', 'p', '邮政编码', NULL, '4028838850c35b6a0150c37251e00002', '2016-09-04 22:19:12', '管理员');
INSERT INTO `t_s_type` VALUES ('4028838850d2666a0150d267d5c10003', 'm', '手机号码', NULL, '4028838850c35b6a0150c37251e00002', '2016-09-04 22:19:12', '管理员');
INSERT INTO `t_s_type` VALUES ('4028838850d2666a0150d26812d40005', 'e', '电子邮件', NULL, '4028838850c35b6a0150c37251e00002', '2016-09-04 22:19:12', '管理员');
INSERT INTO `t_s_type` VALUES ('4028838850d2666a0150d26850210007', 'url', '网址', NULL, '4028838850c35b6a0150c37251e00002', '2016-09-04 22:19:12', '管理员');
INSERT INTO `t_s_type` VALUES ('4028838850d2666a0150d268ae510009', '*6-16', '6到16位任意字符', NULL, '4028838850c35b6a0150c37251e00002', '2016-09-04 22:19:12', '管理员');
INSERT INTO `t_s_type` VALUES ('4028838850d2666a0150d268e229000b', 'n6-16', '6到16位数字', NULL, '4028838850c35b6a0150c37251e00002', '2016-09-04 22:19:12', '管理员');
INSERT INTO `t_s_type` VALUES ('4028838850d2666a0150d26912e2000d', 's6-18', '6到18位字符串', NULL, '4028838850c35b6a0150c37251e00002', '2016-09-04 22:19:12', '管理员');
INSERT INTO `t_s_type` VALUES ('402889f647f797e30147f79ec3760005', '1', '待提交', NULL, '402889f647f797e30147f79e7ca60003', '2017-02-23 15:17:53', '管理员');
INSERT INTO `t_s_type` VALUES ('402889f647f797e30147f79f28de0007', '2', '处理中', NULL, '402889f647f797e30147f79e7ca60003', '2017-02-23 15:17:53', '管理员');
INSERT INTO `t_s_type` VALUES ('402889f647f797e30147f79fa724000b', '3', '已完成', NULL, '402889f647f797e30147f79e7ca60003', '2017-02-23 15:17:53', '管理员');
INSERT INTO `t_s_type` VALUES ('402892816b0e30e8016b0e3824fe0003', 'FEDX', 'FEDX', NULL, '402892816b0e30e8016b0e38001c0001', '2019-05-31 22:08:09', '初始');
INSERT INTO `t_s_type` VALUES ('402892816b0e30e8016b0e3848fc0005', 'DHL', 'DHL', NULL, '402892816b0e30e8016b0e38001c0001', '2019-05-31 22:08:18', '初始');
INSERT INTO `t_s_type` VALUES ('402892816b0e30e8016b0e3862c40007', 'EMS', 'EMS', NULL, '402892816b0e30e8016b0e38001c0001', '2019-05-31 22:08:25', '初始');
INSERT INTO `t_s_type` VALUES ('402892816b0e30e8016b0e38937d0009', 'SAL船运', 'SAL船运', NULL, '402892816b0e30e8016b0e38001c0001', '2019-05-31 22:08:37', '初始');
INSERT INTO `t_s_type` VALUES ('402892816b0e30e8016b0e38b1f4000b', '黑猫', '黑猫', NULL, '402892816b0e30e8016b0e38001c0001', '2019-05-31 22:08:45', '初始');
INSERT INTO `t_s_type` VALUES ('402892816b0e30e8016b0e38d186000d', '福山', '福山', NULL, '402892816b0e30e8016b0e38001c0001', '2019-05-31 22:08:53', '初始');
INSERT INTO `t_s_type` VALUES ('402892816b0e30e8016b0e38f13c000f', '佐川急便', '佐川急便', NULL, '402892816b0e30e8016b0e38001c0001', '2019-05-31 22:09:01', '初始');
INSERT INTO `t_s_type` VALUES ('402892816b0e30e8016b0e3913970011', '西浓', '西浓', NULL, '402892816b0e30e8016b0e38001c0001', '2019-05-31 22:09:10', '初始');
INSERT INTO `t_s_type` VALUES ('402892816b0e30e8016b0e393fed0013', '送货', '送货', NULL, '402892816b0e30e8016b0e38001c0001', '2019-05-31 22:09:21', '初始');
INSERT INTO `t_s_type` VALUES ('402892816b0e30e8016b0e395ba40015', '自取', '自取', NULL, '402892816b0e30e8016b0e38001c0001', '2019-05-31 22:09:28', '初始');
INSERT INTO `t_s_type` VALUES ('40289a817da9f3cc017da9f6515b0003', 'A库区', 'A库区', NULL, '40289a817da9f3cc017da9f6215c0001', '2021-12-11 22:47:12', '管理员');
INSERT INTO `t_s_type` VALUES ('4028b881533ac16a01533adf65370003', 'Pie2D', '2D饼图', NULL, '4028b881533ac16a01533adb50460001', '2016-09-04 22:19:12', '管理员');
INSERT INTO `t_s_type` VALUES ('4028b881533ac16a01533ae0363d0005', 'Pie3D', '3D饼图', NULL, '4028b881533ac16a01533adb50460001', '2016-09-04 22:19:12', '管理员');
INSERT INTO `t_s_type` VALUES ('4028b881533ac16a01533ae2d2a50007', 'Column2D', '2D柱状图', NULL, '4028b881533ac16a01533adb50460001', '2016-09-04 22:19:12', '管理员');
INSERT INTO `t_s_type` VALUES ('4028b881533ac16a01533ae305340009', 'Column3D', '3D柱状图', NULL, '4028b881533ac16a01533adb50460001', '2016-09-04 22:19:12', '管理员');
INSERT INTO `t_s_type` VALUES ('4028b881533ac16a01533ae45759000b', 'Bar2D', '条状图', NULL, '4028b881533ac16a01533adb50460001', '2016-09-04 22:19:12', '管理员');
INSERT INTO `t_s_type` VALUES ('4028b881533ac16a01533ae4c6de000d', 'Area2D', '面积图', NULL, '4028b881533ac16a01533adb50460001', '2016-09-04 22:19:12', '管理员');
INSERT INTO `t_s_type` VALUES ('4028b881533ac16a01533ae50a67000f', 'LineBasic2D', '折线图', NULL, '4028b881533ac16a01533adb50460001', '2016-09-04 22:19:12', '管理员');
INSERT INTO `t_s_type` VALUES ('4028b8815ddbaf03015ddbc2f311000a', '01', '占用', NULL, '4028b8815ddbaf03015ddbc2be500008', '2017-08-13 21:22:53', '管理员');
INSERT INTO `t_s_type` VALUES ('4028b8815ddbaf03015ddbc31596000c', '02', '空闲', NULL, '4028b8815ddbaf03015ddbc2be500008', '2017-08-13 21:23:02', '管理员');
INSERT INTO `t_s_type` VALUES ('4028b8815e7baaf9015e7bc698bc0012', 'test1', 'test1', NULL, '4028b8815e7baaf9015e7bc640560010', '2017-09-13 23:06:06', 'admin');
INSERT INTO `t_s_type` VALUES ('4028b8815e7baaf9015e7bc6ba0c0014', 'test2', 'test2', NULL, '4028b8815e7baaf9015e7bc640560010', '2017-09-13 23:06:15', 'admin');
INSERT INTO `t_s_type` VALUES ('4028b8815e7baaf9015e7bc7987c0016', 'test3', 'test3', NULL, '4028b8815e7baaf9015e7bc640560010', '2017-09-13 23:07:12', 'admin');
INSERT INTO `t_s_type` VALUES ('4028ef8154753f2601547546bb620007', '1', '单选', NULL, '4028ef8154753f2601547546249f0005', '2016-09-04 22:19:12', '管理员');
INSERT INTO `t_s_type` VALUES ('4028ef8154753f2601547546d3d60009', '2', '多选', NULL, '4028ef8154753f2601547546249f0005', '2016-09-04 22:19:12', '管理员');
INSERT INTO `t_s_type` VALUES ('8a1c7ee54e3e2ca9014e3e520bdc0010', 'spring', 'java.enhance.type.spring', NULL, '8a1c7ee54e3e2ca9014e3e4b78f90009', '2016-09-04 22:19:12', '管理员');
INSERT INTO `t_s_type` VALUES ('8a1c7ee54e3e2ca9014e3e524b560012', 'class', 'java.enhance.type.class', NULL, '8a1c7ee54e3e2ca9014e3e4b78f90009', '2016-09-04 22:19:12', '管理员');
INSERT INTO `t_s_type` VALUES ('8a71b40e4a38319b014a3859a2c1001a', '1', 'common.smsAlertsModel', NULL, '8a71b40e4a38319b014a3858fca40018', '2016-09-04 22:19:12', '管理员');
INSERT INTO `t_s_type` VALUES ('8a71b40e4a38319b014a385a01d1001c', '2', 'common.emailAlertsModel', NULL, '8a71b40e4a38319b014a3858fca40018', '2016-09-04 22:19:12', '管理员');
INSERT INTO `t_s_type` VALUES ('8a71b40e4a38319b014a385d30300020', '1', 'common.smsAlerts', NULL, '8a71b40e4a38319b014a385cb115001e', '2016-09-04 22:19:12', '管理员');
INSERT INTO `t_s_type` VALUES ('8a71b40e4a38319b014a385d86c30022', '2', 'common.emailAlerts', NULL, '8a71b40e4a38319b014a385cb115001e', '2016-09-04 22:19:12', '管理员');
INSERT INTO `t_s_type` VALUES ('8a71b40e4a38319b014a385dc1370024', '3', 'common.sysAlerts', NULL, '8a71b40e4a38319b014a385cb115001e', '2016-09-04 22:19:12', '管理员');
INSERT INTO `t_s_type` VALUES ('8a71b40e4a38319b014a3860603f0028', '1', 'common.didNotSend', NULL, '8a71b40e4a38319b014a386022bd0026', '2016-09-04 22:19:12', '管理员');
INSERT INTO `t_s_type` VALUES ('8a71b40e4a38319b014a38608d98002a', '2', 'common.sendSuccess', NULL, '8a71b40e4a38319b014a386022bd0026', '2016-09-04 22:19:12', '管理员');
INSERT INTO `t_s_type` VALUES ('8a71b40e4a38319b014a3860b181002c', '3', 'common.failToSend', NULL, '8a71b40e4a38319b014a386022bd0026', '2016-09-04 22:19:12', '管理员');
INSERT INTO `t_s_type` VALUES ('8a8ab0b246dc81120146dc8181f30060', '2', 'menu.icon', NULL, '8a8ab0b246dc81120146dc8181aa0056', '2016-09-04 22:19:12', '管理员');
INSERT INTO `t_s_type` VALUES ('8a8ab0b246dc81120146dc8181f70061', '1', 'system.icon', NULL, '8a8ab0b246dc81120146dc8181aa0056', '2016-09-04 22:19:12', '管理员');
INSERT INTO `t_s_type` VALUES ('8a8ab0b246dc81120146dc8181fa0062', 'files', 'common.attachment', NULL, '8a8ab0b246dc81120146dc8181ca005e', '2016-09-04 22:19:12', '管理员');
INSERT INTO `t_s_type` VALUES ('8a8ab0b246dc81120146dc8181fe0063', '1', 'lang.excellent.order', NULL, '8a8ab0b246dc81120146dc8181b10057', '2016-09-04 22:19:12', '管理员');
INSERT INTO `t_s_type` VALUES ('8a8ab0b246dc81120146dc8182010064', '2', 'lang.normal.order', NULL, '8a8ab0b246dc81120146dc8181b10057', '2016-09-04 22:19:12', '管理员');
INSERT INTO `t_s_type` VALUES ('8a8ab0b246dc81120146dc8182050065', '1', 'lang.contract.customer', NULL, '8a8ab0b246dc81120146dc8181b50058', '2016-09-04 22:19:12', '管理员');
INSERT INTO `t_s_type` VALUES ('8a8ab0b246dc81120146dc8182080066', '2', 'lang.normal.customer', NULL, '8a8ab0b246dc81120146dc8181b50058', '2016-09-04 22:19:12', '管理员');
INSERT INTO `t_s_type` VALUES ('8a8ab0b246dc81120146dc81820b0067', '1', 'lang.special.servcie', NULL, '8a8ab0b246dc81120146dc8181b90059', '2016-09-04 22:19:12', '管理员');
INSERT INTO `t_s_type` VALUES ('8a8ab0b246dc81120146dc8182100068', '2', 'lang.normal.service', NULL, '8a8ab0b246dc81120146dc8181b90059', '2016-09-04 22:19:12', '管理员');
INSERT INTO `t_s_type` VALUES ('8a8ab0b246dc81120146dc8182130069', 'single', 'common.single.condition.query', NULL, '8a8ab0b246dc81120146dc8181bc005a', '2016-09-04 22:19:12', '管理员');
INSERT INTO `t_s_type` VALUES ('8a8ab0b246dc81120146dc818216006a', 'group', 'common.scope.query', NULL, '8a8ab0b246dc81120146dc8181bc005a', '2016-09-04 22:19:12', '管理员');
INSERT INTO `t_s_type` VALUES ('8a8ab0b246dc81120146dc81821a006b', 'Y', 'common.yes', NULL, '8a8ab0b246dc81120146dc8181c0005b', '2016-09-04 22:19:12', '管理员');
INSERT INTO `t_s_type` VALUES ('8a8ab0b246dc81120146dc81821d006c', 'N', 'common.no', NULL, '8a8ab0b246dc81120146dc8181c0005b', '2016-09-04 22:19:12', '管理员');
INSERT INTO `t_s_type` VALUES ('8a8ab0b246dc81120146dc818221006d', 'Integer', 'common.db.integer', NULL, '8a8ab0b246dc81120146dc8181c3005c', '2016-09-04 22:19:12', '管理员');
INSERT INTO `t_s_type` VALUES ('8a8ab0b246dc81120146dc818224006e', 'Date', 'common.db.date', NULL, '8a8ab0b246dc81120146dc8181c3005c', '2016-09-04 22:19:12', '管理员');
INSERT INTO `t_s_type` VALUES ('8a8ab0b246dc81120146dc818227006f', 'String', 'common.db.string', NULL, '8a8ab0b246dc81120146dc8181c3005c', '2016-09-04 22:19:12', '管理员');
INSERT INTO `t_s_type` VALUES ('8a8ab0b246dc81120146dc81822b0070', 'Long', 'common.db.long', NULL, '8a8ab0b246dc81120146dc8181c3005c', '2016-09-04 22:19:12', '管理员');
INSERT INTO `t_s_type` VALUES ('8a8ab0b246dc81120146dc81822f0071', 'act', 'common.workflow.engine.table', NULL, '8a8ab0b246dc81120146dc8181c6005d', '2016-09-04 22:19:12', '管理员');
INSERT INTO `t_s_type` VALUES ('8a8ab0b246dc81120146dc8182320072', 't_s', 'common.system.table', NULL, '8a8ab0b246dc81120146dc8181c6005d', '2016-09-04 22:19:12', '管理员');
INSERT INTO `t_s_type` VALUES ('8a8ab0b246dc81120146dc8182350073', 't_b', 'common.business.table', NULL, '8a8ab0b246dc81120146dc8181c6005d', '2016-09-04 22:19:12', '管理员');
INSERT INTO `t_s_type` VALUES ('8a8ab0b246dc81120146dc8182390074', 't_p', 'common.customer.engine.table', NULL, '8a8ab0b246dc81120146dc8181c6005d', '2016-09-04 22:19:12', '管理员');
INSERT INTO `t_s_type` VALUES ('8a8ab0b246dc81120146dc81823c0075', 'news', 'common.news', NULL, '8a8ab0b246dc81120146dc8181ca005e', '2016-09-04 22:19:12', '管理员');
INSERT INTO `t_s_type` VALUES ('8a8ab0b246dc81120146dc8182400076', '0', 'common.male', NULL, '8a8ab0b246dc81120146dc8181cd005f', '2016-09-04 22:19:12', '管理员');
INSERT INTO `t_s_type` VALUES ('8a8ab0b246dc81120146dc8182430077', '1', 'common.female', NULL, '8a8ab0b246dc81120146dc8181cd005f', '2016-09-04 22:19:12', '管理员');
INSERT INTO `t_s_type` VALUES ('8a8ab0ba487c527201487c7863ec001b', 'oracle', 'common.oracle', NULL, '8a8ab0ba487c527201487c7732790019', '2016-09-04 22:19:12', '管理员');
INSERT INTO `t_s_type` VALUES ('8a8ab0ba487c527201487c78aefc001d', 'sqlserver2008', 'common.sqlserver2008', NULL, '8a8ab0ba487c527201487c7732790019', '2016-09-04 22:19:12', '管理员');
INSERT INTO `t_s_type` VALUES ('8a8ab0ba487c527201487c78fbb5001f', 'mysql', 'common.mysql', NULL, '8a8ab0ba487c527201487c7732790019', '2016-09-04 22:19:12', '管理员');
INSERT INTO `t_s_type` VALUES ('f852d85d47ed64a40147ed71f6b40005', '>', '大于', NULL, 'f852d85d47ed64a40147ed70894c0003', '2016-09-04 22:19:12', '管理员');
INSERT INTO `t_s_type` VALUES ('f852d85d47ed64a40147ed72a9dc0007', '>=', '大于等于', NULL, 'f852d85d47ed64a40147ed70894c0003', '2016-09-04 22:19:12', '管理员');
INSERT INTO `t_s_type` VALUES ('f852d85d47ed64a40147ed750e1c0009', '<', '小于', NULL, 'f852d85d47ed64a40147ed70894c0003', '2016-09-04 22:19:12', '管理员');
INSERT INTO `t_s_type` VALUES ('f852d85d47ed64a40147ed753b6f000b', '<=', '小于等于', NULL, 'f852d85d47ed64a40147ed70894c0003', '2016-09-04 22:19:12', '管理员');
INSERT INTO `t_s_type` VALUES ('f852d85d47ed64a40147ed75afe5000d', '=', '等于', NULL, 'f852d85d47ed64a40147ed70894c0003', '2016-09-04 22:19:12', '管理员');
INSERT INTO `t_s_type` VALUES ('f852d85d47ed64a40147ed75ed62000f', 'IN', '包含', NULL, 'f852d85d47ed64a40147ed70894c0003', '2016-09-04 22:19:12', '管理员');
INSERT INTO `t_s_type` VALUES ('f852d85d47ed64a40147ed7638b20011', 'LIKE', '模糊', NULL, 'f852d85d47ed64a40147ed70894c0003', '2016-09-04 22:19:12', '管理员');
INSERT INTO `t_s_type` VALUES ('f852d85d47ed64a40147ed767c240013', '!=', '不等于', NULL, 'f852d85d47ed64a40147ed70894c0003', '2016-09-04 22:19:12', '管理员');
INSERT INTO `t_s_type` VALUES ('ff80808151399d0d015139b0e0b80003', 'hour', '小时', NULL, '4028ab8c5134f1ed0151350f08d90003', '2016-09-04 22:19:12', '管理员');
INSERT INTO `t_s_type` VALUES ('ff80808151399d0d015139b1609d0006', 'day', '天', NULL, '4028ab8c5134f1ed0151350f08d90003', '2016-09-04 22:19:12', '管理员');
INSERT INTO `t_s_type` VALUES ('ff80808151399d0d015139b283a10008', 'perday', '天/人', NULL, '4028ab8c5134f1ed0151350f08d90003', '2016-09-04 22:19:12', '管理员');
INSERT INTO `t_s_type` VALUES ('ff80808151399d0d015139b29550000a', 'permoney', '元/人', NULL, '4028ab8c5134f1ed0151350f08d90003', '2016-09-04 22:19:12', '管理员');
INSERT INTO `t_s_type` VALUES ('ff80808151399d0d015139b2a6e5000c', 'money', '元', NULL, '4028ab8c5134f1ed0151350f08d90003', '2016-09-04 22:19:12', '管理员');
INSERT INTO `t_s_type` VALUES ('ff80808151399d0d015139b2bab4000e', 'age', '岁', NULL, '4028ab8c5134f1ed0151350f08d90003', '2016-09-04 22:19:12', '管理员');
INSERT INTO `t_s_type` VALUES ('ff80808151399d0d015139b2c9ce0010', 'class', '课时', NULL, '4028ab8c5134f1ed0151350f08d90003', '2016-09-04 22:19:12', '管理员');
INSERT INTO `t_s_type` VALUES ('ff80808169d3b6720169d3b828ad0005', '4', '当前用户权限', NULL, 'ff80808169d3b6720169d3b7e1b00003', '2019-03-31 20:27:35', '初始');
INSERT INTO `t_s_type` VALUES ('ff80808169d3b6720169d3b86f3a0007', '3', '公司权限', NULL, 'ff80808169d3b6720169d3b7e1b00003', '2019-03-31 20:27:54', '初始');
INSERT INTO `t_s_type` VALUES ('ff80808169d3b6720169d3b8a0a10009', '1', '系统用户', NULL, 'ff80808169d3b6720169d3b7e1b00003', '2019-03-31 20:28:06', '初始');
INSERT INTO `t_s_type` VALUES ('ff80808169d3b6720169d3b8c28e000b', '2', '接口用户', NULL, 'ff80808169d3b6720169d3b7e1b00003', '2019-03-31 20:28:15', '初始');
INSERT INTO `t_s_type` VALUES ('jglongjbtstype201506041030000001', 'WXGZYD', '关注引导', NULL, 'jglongjbtstypegourp2015060400001', '2016-09-04 22:19:12', '管理员');
INSERT INTO `t_s_type` VALUES ('jglongjbtstype201506041030000002', 'WXNRQ', '内容区', NULL, 'jglongjbtstypegourp2015060400001', '2016-09-04 22:19:12', '管理员');
INSERT INTO `t_s_type` VALUES ('jglongjbtstype201506041030000003', 'WXYWYD', '原文引导', NULL, 'jglongjbtstypegourp2015060400001', '2016-09-04 22:19:12', '管理员');
INSERT INTO `t_s_type` VALUES ('jglongjbtstype201506041030000004', 'WXBT', '标题', NULL, 'jglongjbtstypegourp2015060400001', '2016-09-04 22:19:12', '管理员');
INSERT INTO `t_s_type` VALUES ('jglongjbtstype201506041030000005', 'WXFGX', '分隔线', NULL, 'jglongjbtstypegourp2015060400001', '2016-09-04 22:19:12', '管理员');
INSERT INTO `t_s_type` VALUES ('jglongjbtstype201506041030000006', 'WXHTZH', '互推账号', NULL, 'jglongjbtstypegourp2015060400001', '2016-09-04 22:19:12', '管理员');
INSERT INTO `t_s_type` VALUES ('jglongjbtstype201506041030000007', 'WXQT', '其他', NULL, 'jglongjbtstypegourp2015060400001', '2016-09-04 22:19:12', '管理员');
INSERT INTO `t_s_type` VALUES ('jglongjbtstype201506041030000008', 'WXWDYS', '我的样式', NULL, 'jglongjbtstypegourp2015060400001', '2016-09-04 22:19:12', '管理员');
-- TODO 需要后续补充

-- ----------------------------
-- Records of t_s_typegroup
-- ----------------------------
INSERT INTO `t_s_typegroup` VALUES ('297e201047e95ee30147e9ba56ce0009', 'orgtype', 'common.org.type', '2016-09-04 22:19:12', '管理员');
INSERT INTO `t_s_typegroup` VALUES ('2c90ac564c9d1734014c9db1a167002b', 'sf_yn', '是否YN', '2016-09-04 22:19:12', '管理员');
INSERT INTO `t_s_typegroup` VALUES ('2c9221a470adc6fc0170fb1e61930367', 'test', '测试', '2020-03-21 11:23:57', '初始');
INSERT INTO `t_s_typegroup` VALUES ('402880884883eff401488415cbb60027', 'smsTplType', '模板类型', '2016-09-04 22:19:12', '管理员');
INSERT INTO `t_s_typegroup` VALUES ('402881885f117b37015f152afeb4006c', 'sf_lp', '品质', '2017-10-13 17:57:40', 'admin');
INSERT INTO `t_s_typegroup` VALUES ('402881886017fd0801601ad37a230023', 'move_sta', '转移', '2017-12-03 13:22:35', 'admin');
INSERT INTO `t_s_typegroup` VALUES ('402881a151f1af7c0151f1b9d7f50002', 'outType', '离职方式', '2016-09-04 22:19:12', '管理员');
INSERT INTO `t_s_typegroup` VALUES ('402881e44df713f5014df738349c002f', 'formDbType', 'form.db.type', '2016-09-04 22:19:12', '管理员');
INSERT INTO `t_s_typegroup` VALUES ('402881e54dcb624a014dcbf4912b000e', 'bdfl', '表单分类', '2016-09-04 22:19:12', '管理员');
INSERT INTO `t_s_typegroup` VALUES ('402881e55af64f07015af68356550004', 'widgetType', '控件类型', '2017-03-22 22:54:47', '管理员');
INSERT INTO `t_s_typegroup` VALUES ('402881e64ca6fd1b014ca7044c370004', 'tblx', '图表类型', '2016-09-04 22:19:12', '管理员');
INSERT INTO `t_s_typegroup` VALUES ('402881e946e71f5f0146e73619bb0002', 'lang', 'common.mutilang', '2016-09-04 22:19:12', '管理员');
INSERT INTO `t_s_typegroup` VALUES ('402882ec69f490a30169f4ae4f960002', 'tms_thfs', '送货方式', '2019-04-07 06:04:18', '初始');
INSERT INTO `t_s_typegroup` VALUES ('402882ec69f490a30169f4af32250008', 'sf_tz', 'tms是否等通知', '2019-04-07 06:05:16', '初始');
INSERT INTO `t_s_typegroup` VALUES ('4028838850c35b6a0150c37251e00002', 'dataType', '校验规则', '2016-09-04 22:19:12', '管理员');
INSERT INTO `t_s_typegroup` VALUES ('402889f647f797e30147f79e7ca60003', 'bpm_status', '业务BPM流转状态', '2017-02-23 15:17:53', '管理员');
INSERT INTO `t_s_typegroup` VALUES ('402892816b0e30e8016b0e38001c0001', 'tms_kd', '快递公司', '2019-05-31 22:08:00', '初始');
INSERT INTO `t_s_typegroup` VALUES ('40289a817da9f3cc017da9f6215c0001', 'area_type', '预约库区', '2021-12-11 22:47:00', '管理员');
INSERT INTO `t_s_typegroup` VALUES ('4028ab8c5134f1ed0151350f08d90003', 'units', '常用单位', '2016-09-04 22:19:12', '管理员');
INSERT INTO `t_s_typegroup` VALUES ('4028b881533ac16a01533adb50460001', 'graphType', '动态图表类型', '2016-09-04 22:19:12', '管理员');
INSERT INTO `t_s_typegroup` VALUES ('4028b8815ddbaf03015ddbc2be500008', 'plat_oper', '月台操作', '2017-08-13 21:22:39', '管理员');
INSERT INTO `t_s_typegroup` VALUES ('4028b8815e7baaf9015e7bc640560010', 'assgin', '任务接收人', '2017-09-13 23:05:44', 'admin');
INSERT INTO `t_s_typegroup` VALUES ('4028ef8154753f2601547546249f0005', 'pop_retype', 'POP返回类型', '2016-09-04 22:19:12', '管理员');
INSERT INTO `t_s_typegroup` VALUES ('4028efa25219c9f0015219d1d2720004', 'leaveType', '请假类别', '2016-09-04 22:19:12', '管理员');
INSERT INTO `t_s_typegroup` VALUES ('8a1c7ee54e3e2ca9014e3e4b78f90009', 'enhanceType', 'java.enhance.type', '2016-09-04 22:19:12', '管理员');
INSERT INTO `t_s_typegroup` VALUES ('8a71b40e4a38319b014a3858fca40018', 'msgTplType', '消息模板分类', '2016-09-04 22:19:12', '管理员');
INSERT INTO `t_s_typegroup` VALUES ('8a71b40e4a38319b014a385cb115001e', 'msgType', '消息类别', '2016-09-04 22:19:12', '管理员');
INSERT INTO `t_s_typegroup` VALUES ('8a71b40e4a38319b014a386022bd0026', 'msgStatus', '消息发送状态', '2016-09-04 22:19:12', '管理员');
INSERT INTO `t_s_typegroup` VALUES ('8a8ab0b246dc81120146dc8181aa0056', 'icontype', 'common.icon.type', '2016-09-04 22:19:12', '管理员');
INSERT INTO `t_s_typegroup` VALUES ('8a8ab0b246dc81120146dc8181b10057', 'order', 'lang.order.type', '2016-09-04 22:19:12', '管理员');
INSERT INTO `t_s_typegroup` VALUES ('8a8ab0b246dc81120146dc8181b50058', 'custom', 'lang.customer.type', '2016-09-04 22:19:12', '管理员');
INSERT INTO `t_s_typegroup` VALUES ('8a8ab0b246dc81120146dc8181b90059', 'service', 'lang.service.item.type', '2016-09-04 22:19:12', '管理员');
INSERT INTO `t_s_typegroup` VALUES ('8a8ab0b246dc81120146dc8181bc005a', 'searchmode', 'common.query.module', '2016-09-04 22:19:12', '管理员');
INSERT INTO `t_s_typegroup` VALUES ('8a8ab0b246dc81120146dc8181c0005b', 'yesorno', 'common.logic.condition', '2016-09-04 22:19:12', '管理员');
INSERT INTO `t_s_typegroup` VALUES ('8a8ab0b246dc81120146dc8181c3005c', 'fieldtype', 'field.type', '2016-09-04 22:19:12', '管理员');
INSERT INTO `t_s_typegroup` VALUES ('8a8ab0b246dc81120146dc8181c6005d', 'database', 'common.data.table', '2016-09-04 22:19:12', '管理员');
INSERT INTO `t_s_typegroup` VALUES ('8a8ab0b246dc81120146dc8181ca005e', 'fieltype', 'common.document.category', '2016-09-04 22:19:12', '管理员');
INSERT INTO `t_s_typegroup` VALUES ('8a8ab0b246dc81120146dc8181cd005f', 'sex', 'common.sex.type', '2016-09-04 22:19:12', '管理员');
INSERT INTO `t_s_typegroup` VALUES ('8a8ab0ba487c527201487c7732790019', 'dbtype', 'common.dbtype', '2016-09-04 22:19:12', '管理员');
INSERT INTO `t_s_typegroup` VALUES ('f852d85d47ed64a40147ed70894c0003', 'rulecon', '规则条件', '2016-09-04 22:19:12', '管理员');
INSERT INTO `t_s_typegroup` VALUES ('ff80808169d3b6720169d3b7e1b00003', 'user_type', '用户类型', '2019-03-31 20:27:17', '初始');
INSERT INTO `t_s_typegroup` VALUES ('jglongjbtstypegourp2015060400001', 'weixin', '微信模板类型', '2016-09-04 22:19:12', '管理员');
-- TODO 需要后续补充

SET FOREIGN_KEY_CHECKS = 1;