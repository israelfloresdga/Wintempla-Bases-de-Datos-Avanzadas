USE circuit_city_avanzada;

SELECT o.order_id, 
	c.name,
	dbo.f_reward(o.order_id) AS reward 
FROM client c, orderx o 
WHERE o.client_id=c.client_id 
ORDER BY order_id ASC;