USE Kimberly;
GO

CREATE FUNCTION to_celsius
(
	@input DECIMAL
)
RETURNS DECIMAL
AS
BEGIN
	DECLARE @p_result DECIMAL(9,2)=0;
	SET @p_result= (5.0/9.0)*(@input-32.0);
RETURN (@p_result);
END;
GO

--USE Kimberly;
--SELECT value AS farenheit,
--	dbo.to_celsius(value) AS celsius 
--FROM temperature;
--GO