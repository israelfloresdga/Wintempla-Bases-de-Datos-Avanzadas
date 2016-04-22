﻿USE circuit_city_avanzada;
GO

SELECT name,
	dbo.f_sold(item_id) AS item_count
FROM item
WHERE dbo.f_sold(item_id) IN
	(
		--MAX\MIN
		SELECT MIN(dbo.f_sold(item_id))
		FROM item
	)