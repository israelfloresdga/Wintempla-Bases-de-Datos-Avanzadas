USE Kimberly;
GO

CREATE PROCEDURE p_volume
(
	@in_item_id INTEGER
)
AS
	DECLARE @p_item_id INT;
	DECLARE @p_name NVARCHAR(32);
	DECLARE @p_volume DECIMAL;
	DECLARE @p_height DECIMAL;
	DECLARE @p_width DECIMAL;
	DECLARE @p_depth DECIMAL;
BEGIN
	SELECT @p_name= name,
	 @p_height= height, 
	 @p_width= width, 
	 @p_depth= depth
	FROM item
	WHERE item_id= @in_item_id;

	SET @p_volume= @p_height*@p_width*@p_depth;
	PRINT('The ' + @p_name + ' volume is ' + CAST(@p_volume AS NVARCHAR));
END;
GO