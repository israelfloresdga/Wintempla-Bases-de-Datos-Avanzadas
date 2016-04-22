USE Kimberly;
GO

ALTER FUNCTION get_term
(
	@input INT
)
RETURNS DECIMAL(15,12)
AS
BEGIN
	DECLARE @p_num DECIMAL(15,12)= 0.0;
	DECLARE @p_den DECIMAL(15,12)= 0.0;
	DECLARE @p_result DECIMAL(15,12)= 0.0;

	IF(@input%2=0)
	BEGIN
		SET @p_num= @input+2.0;
		SET @p_den= @input+1.0;
	END
	ELSE
	BEGIN
		SET @p_num= @input+1.0;
		SET @p_den= @input+2.0;
	END
	--SET @p_result= CAST(@p_num AS DECIMAL(15,12))/CAST(@p_den AS DECIMAL(15,12));
	SET @p_result= @p_num/@p_den;
	RETURN(@p_result);
END;
GO

--SELECT dbo.get_term(0) FROM DUAL;
