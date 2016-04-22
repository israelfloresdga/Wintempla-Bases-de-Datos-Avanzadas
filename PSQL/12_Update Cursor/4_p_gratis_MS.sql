USE circuit_city_avanzada;
GO

CREATE PROCEDURE p_gratis
AS
BEGIN
	DECLARE cur_ord_det CURSOR FOR
		SELECT * FROM ord_det_copy
		FOR UPDATE OF item_count;
	DECLARE @p_order_id INT;
	DECLARE @p_item_id INT;
	DECLARE @p_item_count INT;

	BEGIN TRANSACTION
	OPEN cur_ord_det
		FETCH NEXT FROM cur_ord_det INTO @p_order_id, @p_item_id, @p_item_count
		WHILE(@@FETCH_STATUS= 0)
		BEGIN
			IF(@p_item_count>4)
			BEGIN
				UPDATE ord_det_copy
				SET item_count= @p_item_count+1
				WHERE CURRENT OF cur_ord_det;
			END
			FETCH NEXT FROM cur_ord_det INTO @p_order_id, @p_item_id, @p_item_count
		END
	CLOSE cur_ord_det;
	DEALLOCATE cur_ord_det;

	COMMIT TRANSACTION;
	RETURN 1;
END
GO