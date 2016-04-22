USE Kimberly;
GO

CREATE FUNCTION get_cost
(
	@input INT
)
RETURNS DECIMAL
AS
BEGIN
	DECLARE @p_result DECIMAL(12,2)=0;
	DECLARE @p_weigth DECIMAL(8,2)=0;
	DECLARE @p_material DECIMAL(4,2)=0;
	DECLARE @p_density DECIMAL(4,2)=0;
	DECLARE @p_cost DECIMAL(4,2)=0;

	SET @p_weigth= dbo.get_weight(@input);

	SELECT @p_cost= cost, 
		@p_density= density
	FROM material m, item i
	WHERE i.made_of= m.material_id AND 
		i.item_id= @input;

	SET @p_result= @p_weigth*@p_density*@p_cost;

RETURN (@p_result);
END;
GO


--USE Kimberly;
--GO
--SELECT name, 
--	dbo.get_weight(item_id) AS get_weight,
--	dbo.get_cost(item_id) AS cost
--FROM item;
--GO