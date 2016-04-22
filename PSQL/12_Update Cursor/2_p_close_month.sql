USE circuit_city_avanzada;
GO

CREATE PROCEDURE p_close_month
AS
BEGIN
	DECLARE @p_value DECIMAL= 1;
	DECLARE @p_index INT= 1;
	DECLARE @p_indexj INT= 1;
	DECLARE @p_trans INT= 0;
	DECLARE @p_trans1 INT= 0;

	BEGIN TRANSACTION
		DELETE FROM ord_det_copy;
		SELECT @p_trans= COUNT(*) FROM ord_det_copy;
		IF(@p_trans<>0)
		BEGIN
			ROLLBACK TRANSACTION;
			RETURN 0;
		END

	INSERT INTO ord_det_copy(order_id,item_id,item_count) SELECT order_id,item_id,item_count FROM ord_det;
	SELECT @p_trans1= COUNT(*) FROM ord_det;
		IF(@p_trans<>@p_trans1)
		BEGIN
			ROLLBACK TRANSACTION;
			RETURN 0;
		END

	DELETE FROM ord_det;
	SELECT @p_trans1= COUNT(*) FROM ord_det;
		IF(@p_trans<>@p_trans1)
		BEGIN
			ROLLBACK TRANSACTION;
			RETURN 0;
		END

	COMMIT TRANSACTION;
	RETURN 1;
END
GO


--USE circuit_city_avanzada;
--GO

--EXECUTE p_close_month;

--SELECT * FROM ord_det_copy;
--SELECT * FROM ord_det;