USE Kimberly;
GO

ALTER PROCEDURE p_factorial
(
	@in_required_amount INT
)
AS
BEGIN
	DECLARE @p_value DECIMAL= 1;
	DECLARE @p_index INT= 1;
	DECLARE @p_indexj INT= 1;
	DECLARE @p_trans INT= 0;

	BEGIN TRANSACTION
		DELETE FROM factorial_value;
		SELECT @p_trans= COUNT(*) FROM factorial_value;
		IF(@p_trans<>0)
		BEGIN
			ROLLBACK TRANSACTION;
			RETURN 0;
		END

	WHILE (@p_index < @in_required_amount+1)
	BEGIN
		WHILE (@p_indexj < @p_index+1)
		BEGIN
			SET @p_value= @p_value*@p_indexj;
			SET @p_indexj= @p_indexj+1;
		END
		INSERT INTO factorial_value(value_id, value) VALUES(@p_index, @p_value);	
		SET @p_value= 1;
		SET @p_index= @p_index+1;	
		SET @p_indexj= 1;
	END

	COMMIT TRANSACTION;
	RETURN 1;
END;
GO

--EXECUTE p_factorial 10;
--SELECT * FROM factorial_value;
