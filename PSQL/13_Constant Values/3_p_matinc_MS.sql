USE Kimberly;
GO

CREATE PROCEDURE p_matinc
AS
	DECLARE @price_increment DECIMAL= 1.034;

	DECLARE cur_material CURSOR FOR
		SELECT * FROM ord_material
		FOR UPDATE OF cost;
	DECLARE @p_material_id CHAR(2);
	DECLARE @p_descr NVARCHAR(16);
	DECLARE @p_cost MONEY;
	DECLARE @p_density DECIMAL(5,2);

BEGIN
	BEGIN TRANSACTION
	OPEN cur_material
		FETCH NEXT FROM cur_material INTO @p_material_id, @p_descr, @p_cost, @p_density
		WHILE(@@FETCH_STATUS= 0)
		BEGIN
			UPDATE material
			SET cost= ROUND(@p_cost*@price_increment,2)
			WHERE CURRENT OF cur_material;
			
			FETCH NEXT FROM cur_material INTO @p_material_id, @p_descr, @p_cost, @p_density
		END
	CLOSE cur_ord_det;
	DEALLOCATE cur_ord_det;

	COMMIT TRANSACTION;
	RETURN 1;
END
GO


--EXECUTE p_matinc;
--SELECT * FROM material;

