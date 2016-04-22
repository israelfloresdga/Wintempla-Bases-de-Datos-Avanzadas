USE Kimberly;
GO

CREATE FUNCTION get_weight
(
	@input INT
)
RETURNS DECIMAL
AS
BEGIN
	DECLARE @p_result DECIMAL(12,2)=0;
	DECLARE @p_width DECIMAL(4,2)=0;
	DECLARE @p_height DECIMAL(4,2)=0;
	DECLARE @p_depth DECIMAL(4,2)=0;

	SELECT @p_width= width, 
		@p_height= height, 
		@p_depth= depth
	FROM item
	WHERE item_id= @input;

	SET @p_result= @p_width*@p_height*@p_depth;

RETURN (@p_result);
END;
GO



--USE Kimberly;
--GO
--SELECT name, width, height, depth,
--	dbo.get_weight(item_id) AS get_weight
--FROM item;
--GO