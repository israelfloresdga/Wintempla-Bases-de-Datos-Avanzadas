USE circuit_city_avanzada;
GO


SELECT  item_id,
	SUM(item_count)
FROM ord_det
GROUP BY item_id
HAVING item_id>=104 AND
	item_id<=110