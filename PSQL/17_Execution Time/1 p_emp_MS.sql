USE motorola;
GO

CREATE PROCEDURE p_emp
AS
	DECLARE @p_last_name NVARCHAR(25);
	DECLARE @p_count INT= 1;
	DECLARE @max_value INT= 10000;
BEGIN
	WHILE (@p_count<@max_value)
	BEGIN
		SELECT @p_last_name = last_name
		FROM employee
		WHERE last_name = 'Moonlight';
		SET @p_count= @p_count+1;
	END;
END
GO