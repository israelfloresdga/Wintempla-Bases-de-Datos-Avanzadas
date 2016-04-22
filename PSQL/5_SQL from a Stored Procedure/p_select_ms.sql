USE Kimberly;
GO

CREATE PROCEDURE p_select
AS
DECLARE @p_name AS NVARCHAR(32);
BEGIN
	SELECT @p_name = name
	FROM item
	WHERE height=12;
	--PRINT('No lo imprime');
	PRINT(@p_name + ' has a height of 12.');
END;
GO

--Si todo va en el .sql de creación de db, tables, vies, etc
--Poner antes de cada procedure
--IF EXISTS (SELECT * FROM sys.objects WHERE object_id = OBJECT_ID(N'p_select') AND type in (N'P', N'PC'))
--  DROP PROCEDURE p_select
--GO