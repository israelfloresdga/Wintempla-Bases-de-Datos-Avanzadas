USE circuit_city_avanzada;
GO

--SELECT od.item_id, od.item_count*i.cost AS item_cost
--FROM ord_det od, item i;


--SELECT SUM(od.item_count*i.cost) AS total
--FROM ord_det od, item i
--WHERE od.item_id=i.item_id
--	AND od.order_id=2000
----
--UNION
----
--SELECT od.item_count*i.cost AS total
--FROM ord_det od, item i
--WHERE od.item_id=i.item_id
--	AND od.order_id=2003;


SELECT od.order_id, SUM(od.item_count*i.cost) AS total
FROM ord_det od, item i
WHERE od.item_id=i.item_id
GROUP BY od.order_id
HAVING od.order_id=2000
--
UNION
--
SELECT od.order_id, od.item_count*i.cost AS total
FROM ord_det od, item i
WHERE od.item_id=i.item_id
	AND od.order_id=2003;
