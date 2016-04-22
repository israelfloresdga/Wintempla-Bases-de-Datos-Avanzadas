USE circuit_city_avanzada;
GO

CREATE PROCEDURE p_reward2
AS
	DECLARE cur_ord_det CURSOR READ_ONLY FOR SELECT order_id, 
		dbo.f_reward(order_id) AS reward 
		FROM ord_det 
		GROUP BY order_id;
	--DECLARE @p_count AS INT;
	DECLARE @p_order_id AS INT;
	DECLARE @p_reward AS NVARCHAR(32);
BEGIN
	OPEN cur_ord_det
		FETCH NEXT FROM cur_ord_det INTO @p_order_id, @p_reward
		WHILE(@@FETCH_STATUS= 0)
		BEGIN
			PRINT(CAST(@p_order_id AS NVARCHAR)+' wins '+ CAST(@p_reward AS NVARCHAR) );
			FETCH NEXT FROM cur_ord_det INTO @p_order_id, @p_reward
		END
	CLOSE cur_ord_det;
	DEALLOCATE cur_ord_det;
END
GO

--EXECUTE p_reward2;