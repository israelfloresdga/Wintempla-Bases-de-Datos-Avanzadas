USE city_bank;
GO

--This program display a message on the console using a variable
CREATE PROCEDURE p_variable
AS
DECLARE @greetings AS NVARCHAR(20);
BEGIN
	SET @greetings='Hello World';
	print(@greetings);
END;
GO

--USE city_bank;
--EXECUTE p_variable;