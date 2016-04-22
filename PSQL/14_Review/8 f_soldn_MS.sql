USE circuit_city_avanzada;
GO

CREATE FUNCTION f_soldn
(
	@input INT
)
RETURNS INTEGER
AS
BEGIN
	DECLARE @p_result INT=0;
	
	DECLARE cur_ord_det CURSOR READ_ONLY FOR 
		SELECT item_id, item_count 
		FROM ord_det 
		WHERE item_id= @input;
	--DECLARE @p_count AS INT;
	DECLARE @p_item_id INT= 0;
	DECLARE @p_item_count INT= 0;

	OPEN cur_ord_det
		FETCH NEXT FROM cur_ord_det INTO @p_item_id, @p_item_count
		WHILE(@@FETCH_STATUS= 0)
		BEGIN
			SET @p_item_count= @p_item_count;

			SET @p_result= @p_result + @p_item_count;
			FETCH NEXT FROM cur_ord_det INTO @p_item_id, @p_item_count
		END
	CLOSE cur_ord_det;
	DEALLOCATE cur_ord_det;

	RETURN(@p_result);
END
GO


SELECT item_id, 
	dbo.f_soldn(item_id) AS sold
FROM item;
