USE city_bank;
GO

CREATE PROCEDURE p_celsius
(
	@farenheit DECIMAL
)
AS
DECLARE @p_celsius AS DECIMAL(6,2);
BEGIN
	SET @p_celsius=(@farenheit-32)*(5.0/9.0);
	PRINT(CAST(@farenheit AS NVARCHAR) + ' °F are ' + CAST(@p_celsius AS NVARCHAR) + '°C');
END;
GO

--EXECUTE p_celsius -40;
--EXECUTE p_celsius 32;
--EXECUTE p_celsius 68;
--EXECUTE p_celsius 212;