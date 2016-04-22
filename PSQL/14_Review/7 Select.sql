USE circuit_city_avanzada;
GO

SELECT item_id,
	name,
	 dbo.f_sold(item_id)
FROM item;
