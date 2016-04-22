use city_bank;
GO

CREATE PROCEDURE p_numeric AS
DECLARE @weight AS DECIMAL(4,0);
DECLARE @age AS INTEGER;
BEGIN
	SET @weight=169;
	SET @age=36;
	PRINT('Age: '+ CAST(@age AS NVARCHAR));
	PRINT('Weight: '+ CAST(@weight AS NVARCHAR));
END;
GO