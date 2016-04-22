use city_bank;
GO

CREATE PROCEDURE p_aboutme AS
DECLARE @last_name AS NVARCHAR(32);
DECLARE @first_name AS NVARCHAR(32);
DECLARE @age AS NVARCHAR(32);
DECLARE @profession AS NVARCHAR(32);
BEGIN
	SET @last_name='Last Name: Flores';
	SET @first_name='First Name: Marcos';
	SET @age='Age: 24';
	SET @profession='Profession: Student';
	PRINT(@last_name);
	PRINT(@first_name);
	PRINT(@age);
	PRINT(@profession);
END;
GO