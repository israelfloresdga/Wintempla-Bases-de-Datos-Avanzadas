USE city_bank;
GO

CREATE PROCEDURE p_duplicate
(
	@x DECIMAL
)
AS
BEGIN
	PRINT('The double of ' +CAST(@x AS NVARCHAR) + ' is ' + CAST(2*@x AS NVARCHAR));
END;
GO

--Ejecución
--USE city_bank;
--EXECUTE p_duplicate 10;