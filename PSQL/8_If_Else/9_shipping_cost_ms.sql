USE Kimberly;
GO

CREATE FUNCTION shipping_cost
(
	@input INTEGER
)
RETURNS DECIMAL(12,2)
AS
BEGIN
	DECLARE @p_result DECIMAL(12,2)=0.0;
	DECLARE @p_volume DECIMAL(12,2)=0.0;
	DECLARE @p_width DECIMAL(12,2)=0.0;
	DECLARE @p_height DECIMAL(12,2)=0.0;
	DECLARE @p_depth DECIMAL(12,2)=0.0;
	DECLARE @p_dimensions DECIMAL(12,2)=0.0;
	DECLARE @p_density DECIMAL(12,2)=0.0;
	DECLARE @p_weigth  DECIMAL(12,2)=0.0;

	SELECT @p_width= width, 
		@p_height= height,
		@p_depth= depth
	FROM item
	WHERE item_id= @input;

	SET @p_dimensions= @p_width*@p_height*@p_depth;

	IF (@p_dimensions<=15.0)
		SET @p_result= 3.57*@p_dimensions;
	ELSE 
		BEGIN
		SELECT @p_density= density
	    FROM material m, item i
	    WHERE i.made_of= m.material_id AND
	        i.item_id= @input;
	    
		SET @p_weigth= @p_dimensions*@p_density;
	    SET @p_result=0.22*@p_weigth;
		END;

	IF (@p_width>10.0 or @p_weigth>10.0 or @p_depth>10.0)
		SET @p_result= @p_result+5.39;
RETURN (@p_result);
END;
GO


--USE Kimberly;
--GO

--SELECT name,
--	dbo.shipping_cost(item_id) AS shipping_cost
--FROM item;