USE city_bank;
GO

CREATE PROCEDURE p_two_inputs
(
	@age INT,
	@weight DECIMAL
)
AS
BEGIN
	PRINT('Age: ' +CAST(@age AS NVARCHAR));
	PRINT('Weight: ' +CAST(@weight AS NVARCHAR));
END;
GO

--Ejecución
--USE city_bank;
--EXECUTE p_two_inputs 50,78;