-- ----------------------------
--  Change database
-- ----------------------------
USE `zo_wms`;

SET NAMES utf8mb4;
SET FOREIGN_KEY_CHECKS = 0;

-- ----------------------------
-- Records of md_cus
-- ----------------------------
INSERT INTO `md_cus` VALUES ('2c9efaca91697e98019232ea039e1ebb', '管理员', 'admin', '2024-09-27 17:57:30', NULL, NULL, NULL, 'A05', 'A05', 'YYY-有限公司', '33', NULL, '001', NULL, NULL, NULL, '20', '01', NULL, NULL, NULL, NULL, NULL, '20', NULL, NULL, NULL, NULL, '测试地址', NULL, '', '', '', NULL, '', NULL, NULL, NULL, NULL, NULL, '', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, '测试地址', '', '');
INSERT INTO `md_cus` VALUES ('2c9efaca91697e98019269adc242210c', '管理员', 'admin', '2024-10-08 09:10:48', NULL, NULL, NULL, 'A05', 'A05', '大成陶瓷有限公司', '', NULL, '1250', NULL, NULL, NULL, '02', '01', NULL, NULL, NULL, NULL, NULL, '10', NULL, NULL, NULL, NULL, '上海市奉贤区', NULL, '何宗激', '', '18621708083', NULL, '', NULL, NULL, NULL, NULL, NULL, '', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, '', '', '');
INSERT INTO `md_cus` VALUES ('2c9efaca91697e9801926c9200672fed', '管理员', 'admin', '2024-10-08 22:39:21', NULL, NULL, NULL, 'A05', 'A05', '可口可乐饮料有限公司', '', NULL, '710500', NULL, NULL, NULL, '10', '01', NULL, NULL, NULL, NULL, NULL, '10', NULL, NULL, NULL, NULL, '', NULL, '', '', '', NULL, '', NULL, NULL, NULL, NULL, NULL, '', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, '', '', '');
INSERT INTO `md_cus` VALUES ('402880e88e59ab34018e59bdb22e0016', '管理员', 'admin', '2024-03-20 10:43:08', NULL, NULL, NULL, 'A05', 'A05', 'XXXX-KH有限公司', '', NULL, 'X00001', NULL, NULL, NULL, '10', '01', NULL, NULL, NULL, NULL, NULL, '10', NULL, NULL, NULL, NULL, '', NULL, 'X先生', '', '18888888888', NULL, '', NULL, NULL, NULL, NULL, NULL, '', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, '', '', '');

-- ----------------------------
-- Records of md_sup
-- ----------------------------
INSERT INTO `md_sup` VALUES ('2c9efaca91697e9801926ee7b2ff302a', '管理员', 'admin', '2024-10-09 09:32:11', NULL, NULL, NULL, 'A05', 'A05', '大江大河有限公司', NULL, NULL, 'G002', NULL, NULL, NULL, NULL, '02', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, '广州大道北1243号', NULL, '李先生', '020-12345678', '13800138000', NULL, '123456@qq.com', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, '测试供应商1');
INSERT INTO `md_sup` VALUES ('402880e88e59ab34018e59bf114a0019', '管理员', 'admin', '2024-03-20 10:44:38', NULL, NULL, NULL, 'A05', 'A05', 'XXXX-GYS有限公司', NULL, NULL, 'G001', NULL, NULL, NULL, NULL, '02', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, '上海市奉贤区', NULL, 'X先生', '028-1234567', '18621708083', NULL, '123456@qq.com', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, '测试供应商2');

-- ----------------------------
-- Records of md_goods
-- ----------------------------
INSERT INTO `md_goods` VALUES ('2c9efaca91697e98019226fddf2b1c45', '管理员', 'admin', '2024-09-25 10:23:45', NULL, NULL, NULL, 'A05', 'A05', 'X00001', '蔗糖', NULL, '20222', NULL, '', NULL, '日用', '恒温', 'N', '', '', '10', NULL, '', '', '120', '斤', '', '', '', '1', NULL, NULL, NULL, NULL, NULL, NULL, '11', '', '', '', NULL, NULL, '120', '', NULL, '', '', NULL, NULL, '00102', NULL, '', '');
INSERT INTO `md_goods` VALUES ('2c9efaca91697e98019241de7b011f8e', '管理员', 'admin', '2024-09-30 15:39:13', NULL, NULL, NULL, 'A05', 'A05', '001', '小蓝管', NULL, '123456789', NULL, '支', NULL, '日用', '常温', 'N', '', '', '10', NULL, '123456789', 'Nevida', '360', '支', '', '', '', '1', NULL, NULL, NULL, NULL, NULL, NULL, '20.99', '', '', '', NULL, NULL, '360', '123456789', NULL, '', '', NULL, NULL, '2', NULL, '20', '');
INSERT INTO `md_goods` VALUES ('2c9efaca91697e9801926c932a742ff0', '管理员', 'admin', '2024-10-08 22:40:37', NULL, NULL, NULL, 'A05', 'A05', '710500', '可口可乐', NULL, '0000', NULL, '', NULL, '日用', '恒温', 'N', '', '', '10', NULL, '', '', '', '箱', '', '', '', '1', NULL, NULL, NULL, NULL, NULL, NULL, '50', '', '', '', NULL, NULL, '', '', NULL, '', '', NULL, NULL, '', NULL, '', '');
INSERT INTO `md_goods` VALUES ('402880e88e59ab34018e59c05287001b', '管理员', 'admin', '2024-03-20 10:46:00', NULL, NULL, NULL, 'A05', 'A05', 'X00001', '牛羊肉半成品', NULL, 'RL001', NULL, '', NULL, '日用', '冷藏', 'N', '5', '6', '10', NULL, 'RL001', '', '360', '箱', '箱', '125000', '50', '50', NULL, NULL, NULL, NULL, NULL, NULL, '100', '50', '50', '50', NULL, NULL, '240', '', NULL, '', '', NULL, NULL, '', NULL, '50', '');

SET FOREIGN_KEY_CHECKS = 1;