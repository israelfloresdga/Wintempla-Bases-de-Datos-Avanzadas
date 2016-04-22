USE circuit_city_avanzada;
GO


CREATE FUNCTION f_sold
(
	@input INT
)
RETURNS INT
AS
BEGIN
	DECLARE @p_result INT;

	SELECT @p_result= SUM(item_count)
	FROM ord_det
	GROUP BY item_id
	HAVING item_id= @input

	RETURN(@p_result);
END
GO


--SELECT item_id, 
--	dbo.f_sold(item_id) AS sold
--FROM item;