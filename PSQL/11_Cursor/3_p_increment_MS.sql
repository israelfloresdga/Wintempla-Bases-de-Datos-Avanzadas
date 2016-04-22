USE circuit_city_avanzada;
GO

CREATE PROCEDURE p_increment
AS
	DECLARE cur_item CURSOR READ_ONLY FOR SELECT item_id, name, cost FROM item;
	--DECLARE @p_count AS INT;
	DECLARE @p_item_id AS INT;
	DECLARE @p_name AS NVARCHAR(16);
	DECLARE @p_cost AS MONEY;
	DECLARE @p_increment AS MONEY;
BEGIN
	--SET @p_count= 0;
	OPEN cur_item
		FETCH NEXT FROM cur_item INTO @p_item_id, @p_name, @p_cost
		WHILE(@@FETCH_STATUS= 0)
		BEGIN
			--SET @p_count= @p_count+1;
			IF(@p_cost>100.0)
				SET @p_increment=@p_cost*(1.1);
			ELSE
				SET @p_increment=@p_cost*(1.01);
			PRINT(CAST(@p_name AS NVARCHAR)+': '+ CAST(@p_cost AS NVARCHAR)+' -> '+ CAST(@p_increment AS NVARCHAR) );
			FETCH NEXT FROM cur_item INTO @p_item_id, @p_name, @p_cost
		END
	CLOSE cur_item;
	DEALLOCATE cur_item;
	--PRINT('The value of p_count is '+CAST(@p_count AS NVARCHAR));
END
GO

--USE circuit_city_avanzada;
--EXECUTE p_increment;