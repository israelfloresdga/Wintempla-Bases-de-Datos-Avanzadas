USE Kimberly;
GO

ALTER FUNCTION wallis_pi
(
	@input INT
)
RETURNS DECIMAL(15,12)
AS
BEGIN
	DECLARE @p_result DECIMAL(15,12)= 1.0;
	DECLARE @p_index INT= 0;

	WHILE (@p_index < @input)
	BEGIN
		SET @p_result= @p_result*dbo.get_term(@p_index);
		SET @p_index= @p_index+1;
	END
		
	RETURN(2.0*@p_result);
END;
GO

--SELECT dbo.wallis_pi(5000) FROM DUAL;