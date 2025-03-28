-- 创建卸货费视图
CREATE VIEW vw_unloading_fee AS
SELECT '卸货费' AS feiyong,
       wi.create_name,
       wi.create_date,
       wi.im_notice_id,
       wi.goods_id,
       mg.shp_ming_cheng,
       SUM(wi.qm_ok_quat) AS qmcount,
       FORMAT((SUM(wi.qm_ok_quat) * mg.zhl_kg), 2) AS grcount,
       FORMAT((SUM(wi.qm_ok_quat) * mg.zhl_kg * 11 / 1000), 2) AS grcountfy,
       '11' AS danjia
FROM wm_in_qm_i wi
JOIN mv_goods mg ON wi.goods_id = mg.goods_id
WHERE wi.qm_ok_quat > 0
GROUP BY wi.create_name,
         wi.im_notice_id,
         wi.cus_code,
         wi.goods_id;

-- 创建装车费视图
CREATE VIEW vw_loading_fee AS
select
    '装车费' as feiyong,
    wi.create_name,
    wi.create_date,
    wi.order_id,
    wi.goods_id,
    mg.shp_ming_cheng,
    sum(wi.base_goodscount) as qmcount,
    format((sum(wi.base_goodscount) * mg.zhl_kg),
        2) as grcount,
    format((sum(wi.base_goodscount) * mg.zhl_kg * 11 / 1000),
        2) as grcountfy,
    '11'  as  danjia
from
    wm_to_down_goods wi,
    mv_goods mg
where
    wi.goods_id = mg.goods_id
    and wi.base_goodscount > 0
    and wi.order_id <> 'ZY'
group by wi.create_name ,
         wi.order_id ,
         wi.cus_code ,
         wi.goods_id;