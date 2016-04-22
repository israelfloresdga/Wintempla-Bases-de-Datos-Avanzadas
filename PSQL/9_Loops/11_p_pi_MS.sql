USE Kimberly;
GO

ALTER PROCEDURE p_pita
(
	@in_required_amount INT
)
AS
BEGIN
	DECLARE @p_value DECIMAL(15,12)= 0;
	DECLARE @p_index INT= 0;
	DECLARE @p_result DECIMAL(15,12)= 0;

	WHILE (@p_index < @in_required_amount)
	BEGIN
		IF(@p_index%2=1)
		BEGIN
			SET @p_value= 1.0/((2.0*CAST(@p_index AS DECIMAL))+1.0);
		END
		ELSE
		BEGIN
			SET @p_value= -1.0/((2.0*CAST(@p_index AS DECIMAL))+1.0);
		END

		SET @p_result= @p_result+@p_value;
		SET @p_index= @p_index+1;
	END
		SET @p_result= -4.0*@p_result;
	PRINT(@p_result);
END;
GO


--EXECUTE p_pita 1000;
--GO