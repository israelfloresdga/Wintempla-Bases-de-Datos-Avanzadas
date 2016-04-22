USE Kimberly;
GO

CREATE PROCEDURE p_matden
AS
	DECLARE @hiden_incr DECIMAL= 1.021;
	DECLARE @lowden_decr DECIMAL= 0.9547;

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
			IF(@p_cost>1.0)
			BEGIN
				UPDATE material
				SET cost= ROUND(@p_cost*@hiden_incr,2)
				WHERE CURRENT OF cur_material;
			END
			ELSE
			BEGIN
				IF(@p_cost>0.0 AND @p_cost<1.0)
				BEGIN
					UPDATE material
					SET cost= ROUND(@p_cost*@lowden_decr,2)
					WHERE CURRENT OF cur_material;
				END
				ELSE
					PRINT('ERROR');
			END		
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