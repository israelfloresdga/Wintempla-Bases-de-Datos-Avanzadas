USE circuit_city_avanzada;
GO

alter TRIGGER trigger_insert_ord_det
ON ord_det
AFTER INSERT
AS
BEGIN
	DECLARE @p_order_id AS INT;
	DECLARE cur_order CURSOR READ_ONLY FOR SELECT order_id FROM inserted;
	OPEN cur_ord_det
		FETCH NEXT FROM cur_order INTO @p_order_id
		WHILE(@@FETCH_STATUS= 0)
		BEGIN

			INSERT INTO audit_ord_det(order_id, actionz, time_date) VALUES(@p_order_id, 'INSERT', GETDATE());
			FETCH NEXT FROM cur_order INTO @p_order_id
		END
	CLOSE cur_ord_det;
	DEALLOCATE cur_ord_det;
END
GO

alter TRIGGER trigger_update_ord_det
ON ord_det
AFTER UPDATE
AS
BEGIN
	DECLARE @p_order_id AS INT;
	DECLARE cur_order CURSOR READ_ONLY FOR SELECT order_id FROM updated;
	OPEN cur_ord_det
		FETCH NEXT FROM cur_order INTO @p_order_id
		WHILE(@@FETCH_STATUS= 0)
		BEGIN

			INSERT INTO audit_ord_det(order_id, actionz, time_date) VALUES(@p_order_id, 'UPDATE', GETDATE());
			FETCH NEXT FROM cur_order INTO @p_order_id
		END
	CLOSE cur_ord_det;
	DEALLOCATE cur_ord_det;
END 
GO

alter TRIGGER trigger_delete_ord_det
ON ord_det
AFTER DELETE
AS
BEGIN
	DECLARE @p_order_id AS INT;
	DECLARE cur_order CURSOR READ_ONLY FOR SELECT order_id FROM deleted;
	OPEN cur_ord_det
		FETCH NEXT FROM cur_order INTO @p_order_id
		WHILE(@@FETCH_STATUS= 0)
		BEGIN
			INSERT INTO audit_ord_det(order_id, actionz, time_date) VALUES(@p_order_id, 'UPDATE', GETDATE());
			FETCH NEXT FROM cur_order INTO @p_order_id
		END
	CLOSE cur_ord_det;
	DEALLOCATE cur_ord_det;
END
GO