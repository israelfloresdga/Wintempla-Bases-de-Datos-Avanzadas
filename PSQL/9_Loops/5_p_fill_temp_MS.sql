USE Kimberly;
GO

ALTER PROCEDURE p_fill_temp
(
	@in_temp DECIMAL,
	@in_incr DECIMAL,
	@in_max INTEGER
)
AS
BEGIN
	DECLARE @p_index INT=0;
	DECLARE @transaction INT=0;

	BEGIN TRANSACTION;
	DELETE FROM temperature;
	--SET @transaction=@@ROWCOUNT;
	--IF (@transaction<>1) BEGIN
	
	--IF (@@ROWCOUNT<0) 
	SELECT @transaction= COUNT(*) FROM temperature;
	IF(@transaction<>0)
	BEGIN
		ROLLBACK TRANSACTION;
		RETURN 0;
	END
	
	WHILE (@p_index < @in_max)
	BEGIN
		INSERT INTO temperature VALUES(@p_index+1, @in_temp+(@in_incr*(@p_index-1)));
		IF (@@ROWCOUNT<>1) 
		BEGIN
			ROLLBACK TRANSACTION;
			RETURN 0;
		END
		SET @p_index= @p_index+1;
	END

	COMMIT TRANSACTION;
	RETURN 1;
END;
GO

--EXECUTE p_fill_temp -40, 5, 6;

--SELECT * FROM temperature;