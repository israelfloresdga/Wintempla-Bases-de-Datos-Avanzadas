USE circuit_city_avanzada;
GO


CREATE FUNCTION f_total_cost
(
	@input INT
)
RETURNS DECIMAL(12,2)
AS
BEGIN
	DECLARE @p_result DECIMAL(12,2);

	SELECT @p_result= SUM(od.item_count*i.cost)
	FROM ord_det od, item i
	WHERE od.item_id=i.item_id
	GROUP BY od.order_id
	HAVING od.order_id= @input;

	RETURN(@p_result);
END;
GO


--SELECT  order_id, 
--	dbo.f_total_cost(order_id) AS total
--FROM orderx;

