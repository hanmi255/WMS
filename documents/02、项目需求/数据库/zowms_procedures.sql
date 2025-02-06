-- ----------------------------
--  Change database
-- ----------------------------
USE `zo_wms`;

-- ----------------------------
--  Create procedures
-- ----------------------------

-- Procedure structure for delete_jeecgDemo_createDate
DROP PROCEDURE IF EXISTS `delete_jeecgDemo_createDate`;
delimiter ;;
CREATE PROCEDURE `delete_jeecgDemo_createDate`(IN `createDate` date)
BEGIN
  delete from jeecg_demo where create_date >= createDate;
END
;;
delimiter ;

-- Procedure structure for formDataList
DROP PROCEDURE IF EXISTS `formDataList`;
delimiter ;;
CREATE PROCEDURE `formDataList`(tableName varchar(50),dbFields varchar(500),whereSql varchar(1000))
BEGIN
	declare exe_sql varchar(2000);
	SET exe_sql = CONCAT("select ",dbFields," from ",tableName,whereSql);
	set @v_sql=exe_sql;
	prepare stmt from @v_sql;
	EXECUTE stmt;
	deallocate prepare stmt;
END
;;
delimiter ;

-- Procedure structure for replaceOrgCode
DROP PROCEDURE IF EXISTS `replaceOrgCode`;
delimiter ;;
CREATE PROCEDURE `replaceOrgCode`()
BEGIN
DECLARE code_length int DEFAULT 0 ;
DECLARE new_code VARCHAR(500);
DECLARE org_id VARCHAR(500);
DECLARE old_code VARCHAR(500);
DECLARE code_length_index int DEFAULT 1;
DECLARE b int default 0;
DECLARE pro CURSOR for select id,org_code,LENGTH(org_code) from t_s_depart;
DECLARE CONTINUE HANDLER FOR NOT FOUND SET b = 1;
OPEN pro;
FETCH pro into org_id,old_code,code_length;
 while b<>1 do
   set code_length_index=1;
	 set new_code='';
	 while code_length_index<code_length do
     set new_code=CONCAT(new_code,'A',SUBSTR(old_code,code_length_index,2));
     set code_length_index=code_length_index+2;
   end while;
    update t_s_depart set org_code=new_code where id=org_id;
  FETCH pro into org_id,old_code,code_length;
end while;
close pro;
end
;;
delimiter ;

-- Procedure structure for update_rp_period_in_out
DROP PROCEDURE IF EXISTS `update_rp_period_in_out`;
delimiter ;;
CREATE PROCEDURE `update_rp_period_in_out`(IN datefrom VARCHAR(45), IN dateto VARCHAR(45), IN username VARCHAR(45))
BEGIN

delete from  `rp_period_in_out` where  username = username;



INSERT INTO  `rp_period_in_out`

(

`create_by`,

`date_period`,

`username`,

`goods_id`,

`goods_name`,

`goods_unit`,

`goods_guige`,

`goods_qc`,

`goods_in`,

`goods_out`,

`goods_qm`,

`sup_code`,

`sup_name`,

`goods_now`



)

 SELECT   username, CONCAT(datefrom,'~',dateto),username,wv.goods_id,wv.shp_ming_cheng,wv.shl_dan_wei,wv.shp_gui_ge,

(SELECT

            SUM(IFNULL(iwm.base_goodscount,0)   )

        FROM

             mv_down_and_up iwm

        WHERE

            TO_DAYS(iwm.create_date) < TO_DAYS(datefrom)

                  AND iwm.goods_id = wv.goods_id),

  (SELECT

            SUM(IFNULL(iwm.base_goodscount,0)  )

        FROM

             wm_to_up_goods iwm

        WHERE

            TO_DAYS(iwm.create_date) >= TO_DAYS(datefrom) AND TO_DAYS(iwm.create_date) <= TO_DAYS(dateto)

                  AND iwm.order_id <> 'ZY' AND iwm.goods_id = wv.goods_id)  ,

(SELECT

            SUM(IFNULL(ABS(iwm.base_goodscount),0)   )

        FROM

             wm_to_down_goods iwm

        WHERE

            TO_DAYS(iwm.create_date) >= TO_DAYS(datefrom) AND TO_DAYS(iwm.create_date) <= TO_DAYS(dateto)

               AND iwm.order_id <> 'ZY'  AND iwm.goods_id = wv.goods_id),

(SELECT

            SUM(IFNULL( iwm.base_goodscount,0)   )

        FROM

             mv_down_and_up iwm

        WHERE

            TO_DAYS(iwm.create_date) <= TO_DAYS(dateto)

                  AND iwm.goods_id = wv.goods_id),

(select sup_code from wm_im_notice_h where notice_id in  (SELECT order_id FROM wms.wm_to_up_goods where goods_id= wv.goods_id   ) limit 1)  ,

         (select sup_name from wm_im_notice_h where notice_id in (SELECT order_id FROM wms.wm_to_up_goods where goods_id= wv.goods_id   )    limit 1)  ,

IFNULL(SUM(IFNULL(base_goodscount,0)) ,0) FROM wv_stock wv GROUP BY wv.goods_id;

END
;;
delimiter ;

-- Procedure structure for update_wm_his_stock
DROP PROCEDURE IF EXISTS `update_wm_his_stock`;
delimiter ;;
CREATE PROCEDURE `update_wm_his_stock`(IN `wmdate` VARCHAR(45))
BEGIN

delete from wm_his_stock where his_date = wmdate;
delete from wm_his_stock_ku where his_date = wmdate;
delete  FROM wm_day_cost where day_cost_yj = 0;
INSERT INTO wm_his_stock (
  `id` ,
  `his_date` ,
  `cus_code` ,
  `ku_wei_bian_ma` ,
  `bin_id` ,
  `goods_id` ,
  `count` ,
  `base_unit`
)
SELECT
    concat(mdp.id,wmdate,
            mdp.cus_code,
            mdp.ku_wei_bian_ma,
            mdp.bin_id,
            mdp.goods_id) as id,
    wmdate as his_date,
    mdp.cus_code,
    mdp.ku_wei_bian_ma,
    mdp.bin_id,
    mdp.goods_id,
    sum(base_goodscount) as count,
    mdp.base_unit

FROM
    mv_down_and_up mdp
where
    (mdp.leixing = 'S'
        and to_days(mdp.create_date) <= to_days(wmdate))
        or (mdp.order_id <> 'ZY'
        and mdp.leixing = 'H'
        and to_days(mdp.create_date) < to_days(wmdate))
        or (mdp.order_id = 'ZY'
        and mdp.leixing = 'H'
        and to_days(mdp.create_date) <= to_days(wmdate))
group by mdp.cus_code , mdp.ku_wei_bian_ma , mdp.bin_id
having sum(base_goodscount) <> 0 and id is not null
order by cus_code , create_date;


INSERT INTO wm_his_stock_ku (
  `id` ,
  `his_date` ,
  `cus_code` ,
  `ku_wei_bian_ma` ,
  `bin_id` ,
  `goods_id` ,
  `count` ,
  `base_unit`
)
SELECT
    concat(mdp.id,wmdate,
            mdp.cus_code,
            mdp.ku_wei_bian_ma,
            mdp.bin_id,
            mdp.goods_id) as id,
    wmdate as his_date,
    mdp.cus_code,
    mdp.ku_wei_bian_ma,
    mdp.bin_id,
    mdp.goods_id,
    sum(base_goodscount) as count,
    mdp.base_unit

FROM
    mv_down_and_up mdp
where
    (mdp.leixing = 'S'
        and to_days(mdp.create_date) <= to_days(wmdate))
        or (mdp.leixing = 'H'
        and to_days(mdp.create_date) <= to_days(wmdate))

group by mdp.cus_code , mdp.ku_wei_bian_ma , mdp.bin_id,mdp.goods_id
having sum(base_goodscount) <> 0 and id is not null
order by cus_code , create_date;

call update_wm_last_day_stock(wmdate);

END
;;
delimiter ;

-- Procedure structure for update_wm_last_day_stock
DROP PROCEDURE IF EXISTS `update_wm_last_day_stock`;
delimiter ;;
CREATE PROCEDURE `update_wm_last_day_stock`(IN `wmdate` VARCHAR(45))
BEGIN

delete from wm_his_stock_data;


INSERT INTO wm_his_stock_data (
  `id` ,
  `his_date` ,
  `cus_code` ,
  `ku_wei_bian_ma` ,
  `bin_id` ,
  `goods_id` ,
  `count` ,
  `base_unit`,
	`pro_data`
)
SELECT
    concat(mdp.id,wmdate,
            mdp.cus_code,
            mdp.ku_wei_bian_ma,
            mdp.bin_id,
            mdp.goods_id,mdp.goods_pro_data) as id,
    wmdate as his_date,
    mdp.cus_code,
    mdp.ku_wei_bian_ma,
    mdp.bin_id,
    mdp.goods_id,
    sum(base_goodscount) as count,
    mdp.base_unit,
goods_pro_data

FROM
    mv_down_and_up mdp
where
    (mdp.leixing = 'S'
        and to_days(mdp.create_date) <= to_days(wmdate))
        or (mdp.leixing = 'H'
        and to_days(mdp.create_date) <= to_days(wmdate))

group by mdp.cus_code , mdp.ku_wei_bian_ma , mdp.bin_id,mdp.goods_id,mdp.goods_pro_data
having sum(base_goodscount) <> 0 and id is not null
order by cus_code , create_date;
END
;;
delimiter ;