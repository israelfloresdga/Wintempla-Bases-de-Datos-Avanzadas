USE city_bank;
GO

--@gallons is an input variable
--@liters is a procedure variable
CREATE PROCEDURE p_liters
(
	@gallons DECIMAL
)
AS
DECLARE @p_liters AS DECIMAL(6,2);
BEGIN
	SET @p_liters=@gallons*3.7854;
	PRINT(CAST(@gallons AS NVARCHAR) + ' gallons are ' + CAST(@p_liters AS NVARCHAR) + 'Lt');
END;
GO

--USE city_bank;
--EXECUTE p_liters 10;