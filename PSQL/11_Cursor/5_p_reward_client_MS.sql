USE circuit_city_avanzada;
GO

CREATE PROCEDURE p_reward_client
AS
	DECLARE cur_ord_det CURSOR READ_ONLY FOR SELECT c.name, od.order_id, SUM(od.item_count) AS countz 
		FROM ord_det od, client c, orderx o 
		WHERE od.order_id=o.order_id AND o.client_id=c.client_id 
		GROUP BY c.client_id, c.name, od.order_id
		ORDER BY order_id ASC;
	--DECLARE @p_count AS INT;
	DECLARE @p_client_name AS NVARCHAR(32);
	DECLARE @p_order_id AS INT;
	DECLARE @p_count AS INT;
	DECLARE @p_result AS NVARCHAR(32);
BEGIN
	--SET @p_count= 0;
	OPEN cur_ord_det
		FETCH NEXT FROM cur_ord_det INTO @p_client_name, @p_order_id, @p_count
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
			
			PRINT(@p_client_name +' -> '+ CAST(@p_order_id AS NVARCHAR)+' wins '+ @p_result +' -> '+ CAST(@p_count AS NVARCHAR) );
			FETCH NEXT FROM cur_ord_det INTO @p_client_name, @p_order_id, @p_count
		END
	CLOSE cur_ord_det;
	DEALLOCATE cur_ord_det;
	--PRINT('The value of p_count is '+CAST(@p_count AS NVARCHAR));
END
GO