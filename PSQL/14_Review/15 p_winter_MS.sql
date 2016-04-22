USE circuit_city_avanzada;
GO

CREATE PROCEDURE p_winter
AS
	DECLARE @p_incr DECIMAL= 1.0570;
	DECLARE @p_decr DECIMAL= 0.7750;

	DECLARE cur_item CURSOR READ_ONLY FOR 
		SELECT item_id,
			dbo.f_soldn(item_id) AS item_count
		FROM item
		GROUP BY item_id;
	DECLARE @p_item_id INT;
	DECLARE @p_item_count INT;
BEGIN
	OPEN cur_item
	FETCH NEXT FROM cur_item INTO @p_item_id, @p_item_count
	WHILE(@@FETCH_STATUS= 0)
	BEGIN
		IF (@p_item_count>5)
		BEGIN
			UPDATE item
			SET cost= ROUND(cost*@p_incr,2)
			WHERE item_id= @p_item_id;
		END
		ELSE
		BEGIN
			IF(@p_item_count=0)
			BEGIN
				UPDATE item
				SET cost= ROUND(cost*@p_decr,2)
				WHERE item_id= @p_item_id;
			END
			ELSE
				PRINT('ERROR at' + @p_item_id);
		END
	END
	CLOSE cur_item;
	DEALLOCATE cur_item;
END
GO

--SELECT item_id, 
--	name,
--	cost
--FROM item;

--EXECUTE p_winter;

--SELECT item_id,
--	name,
--	cost
--FROM item;