USE master;
GO

ALTER PROCEDURE p_exist_kimberly
AS
BEGIN
	DECLARE @db_name AS NVARCHAR(16)=null;

	SELECT @db_name= name
	FROM sysdatabases
	WHERE name= 'Kimberly';

	IF(@db_name='Kimberly')
	BEGIN
		SELECT name FROM sysobjects
		WHERE xtype= 'U'
			OR xtype= 'S';
	END

	ELSE
	BEGIN
		PRINT ('Database: ' + 'Kimberly' + ' not found.');
		RETURN 0;
	END

END 
GO


--USE master;
--EXECUTE p_exist_kimberly;