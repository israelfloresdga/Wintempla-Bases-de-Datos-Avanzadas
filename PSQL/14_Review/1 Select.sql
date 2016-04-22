USE circuit_city_avanzada;
GO

SELECT item_id, SUM(item_count)
FROM ord_det
GROUP BY item_id;
