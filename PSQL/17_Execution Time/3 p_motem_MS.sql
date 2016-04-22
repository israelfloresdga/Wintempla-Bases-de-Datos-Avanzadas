USE motorola;
GO

CREATE PROCEDURE p_motem
AS
	DECLARE @p_last_name NVARCHAR(20);
	DECLARE @p_count INT= 1;
	DECLARE @max_value INT= 100000;
	DECLARE @p_start_time CHAR(5)= 0;
	DECLARE @p_end_time CHAR(5)= 0;
	DECLARE @p_duration DECIMAL(10,5)= 0;
BEGIN
	SET @p_start_time= CAST(GETDATE() AS CHAR(5));

	WHILE (@p_count < @max_value)
	BEGIN
		SELECT @p_last_name = last_name
		FROM employee
		WHERE last_name= 'Moonlight';
		SET @p_count= @p_count+1;
	END

	SET @p_end_time= CAST(GETDATE() AS CHAR(5));
	SET @p_duration= CAST(@p_end_time AS DECIMAL(10,5))- CAST(@p_start_time AS DECIMAL(10,5));
	PRINT('Running time is: ' + @p_duration + ' sec.');

END
GO
