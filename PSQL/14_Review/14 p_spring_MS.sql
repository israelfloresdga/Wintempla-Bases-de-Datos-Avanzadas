USE circuit_city_avanzada;
GO


CREATE PROCEDURE p_spring
AS
	DECLARE @p_incr DECIMAL= 1.1255;
	DECLARE @p_decr DECIMAL= 0.7500;

	DECLARE cur_item CURSOR READ_ONLY FOR 
			SELECT item_id, name, cost FROM item
			FOR UPDATE OF cost;
	DECLARE @p_item_id NUMBER(9,0);
	DECLARE @p_name NVARCHAR(32);
	DECLARE @p_cost NUMBER(15,2);

BEGIN
	OPEN cur_item
	FETCH NEXT FROM cur_item INTO @p_item_id, @p_name, @p_cost
	WHILE(@@FETCH_STATUS= 0)
	BEGIN
		IF (@p_cost>300.0) 
		BEGIN
			UPDATE item
			SET cost= ROUND(@p_cost*@p_incr,2)
			WHERE CURRENT OF cur_item;
		END
		ELSE
		BEGIN
			IF(@p_cost>0.0 AND @p_cost<100.0)
			BEGIN
				UPDATE item
				SET cost= ROUND(@p_cost*@p_decr,2)
				WHERE CURRENT OF cur_item;
			END
			ELSE
				PRINT('ERROR at' + @item_id)
		END
		FETCH NEXT FROM cur_item INTO @p_item_id, @p_name, @p_cost
	END
	CLOSE cur_item;
	DEALLOCATE cur_item;
END
GO


--SELECT item_id, 
--	name,
--	cost
--FROM item;

--EXECUTE p_spring;

--SELECT item_id,
--	name,
--	cost
--FROM item;

