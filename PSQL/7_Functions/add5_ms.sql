USE Kimberly;
GO

CREATE FUNCTION add5
(
	@input DECIMAL(10,2)
)
	RETURNS DECIMAL(10,2)
AS
BEGIN
	DECLARE @result AS DECIMAL(10,2);
	SET @result= @input +5.0;
	RETURN (@result);
END;
GO

--USE Kimberly;
--SELECT cost, dbo.add5(cost) AS price
--FROm material;
--GO