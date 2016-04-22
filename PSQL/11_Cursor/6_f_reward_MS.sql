USE circuit_city_avanzada;
GO

CREATE FUNCTION f_reward
(
	@input INT
)
RETURNS NVARCHAR(32)
AS
BEGIN
	DECLARE cur_ord_det CURSOR READ_ONLY FOR SELECT o.order_id, SUM(od.item_count) AS countz 
		FROM orderx o, ord_det od 
		WHERE o.order_id= od.order_id AND o.order_id= @input
		GROUP BY o.order_id;
	--DECLARE @p_count AS INT;
	DECLARE @p_order_id AS INT;
	DECLARE @p_count AS INT;
	DECLARE @p_result AS NVARCHAR(32);

	--SET @p_count= 0;
	OPEN cur_ord_det
		FETCH NEXT FROM cur_ord_det INTO @p_order_id, @p_count
		WHILE(@@FETCH_STATUS= 0)
		BEGIN
			--SET @p_count= @p_count+1;
			IF(@p_count>15) 
				SET @p_result='Monitor';
			ELSE
				IF(@p_count<=15 AND @p_count>5)
					SET	@p_result='Mouse';
				ELSE
					SET @p_result='nothing';
			FETCH NEXT FROM cur_ord_det INTO @p_order_id, @p_count
		END
	CLOSE cur_ord_det;
	DEALLOCATE cur_ord_det;
	
	RETURN(@p_result);
END
GO


--USE circuit_city_avanzada;

--SELECT  order_id, 
--	dbo.f_reward(order_id) AS reward
--FROM orderx;