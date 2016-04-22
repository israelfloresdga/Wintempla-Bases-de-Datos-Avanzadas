USE circuit_city_avanzada;
GO

SELECT c.name,
	o.order_id, 
	dbo.f_total_cost(o.order_id) AS total
FROM orderx o, client c
WHERE o.client_id= c.client_id;
