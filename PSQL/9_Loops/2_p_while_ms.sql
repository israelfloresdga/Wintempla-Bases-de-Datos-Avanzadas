USE Kimberly;
GO

CREATE PROCEDURE p_while
(
	@in_max DECIMAL
)
AS
	DECLARE @p_index DECIMAL(4,0)=0;
BEGIN
	WHILE (@p_index < @in_max)
	BEGIN
		PRINT(@p_index+1);
		SET @p_index= @p_index+1;
	END;
END;
GO


--EXECUTE p_while 5;