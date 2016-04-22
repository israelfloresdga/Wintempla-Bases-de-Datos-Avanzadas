USE circuit_city_avanzada;
GO

CREATE PROCEDURE p_sales1745
AS
	DECLARE @p_incr DECIMAL= 1.1745;

	DECLARE cur_item CURSOR FOR 
		SELECT item_id, cost 
		FROM item
		FOR UPDATE OF cost;

	DECLARE @p_item_id INT;
	DECLARE @p_cost MONEY= 0.0;
			
	DECLARE @p_result MONEY;
BEGIN
	BEGIN TRANSACTION
	OPEN cur_item
		FETCH NEXT FROM cur_item INTO @p_item_id, @p_cost
		WHILE(@@FETCH_STATUS= 0)
		BEGIN
			UPDATE item
				SET cost= @p_cost*@p_incr
				WHERE CURRENT OF cur_item;
				FETCH NEXT FROM cur_item INTO @p_item_id, @p_cost
		END
	CLOSE cur_item;
	DEALLOCATE cur_item;

	COMMIT TRANSACTION;
	RETURN 1;
END
GO

SELECT client_id,
	credit
FROM credit_client;

EXECUTE p_creinc;

SELECT client_id,
	credit
FROM credit_client;