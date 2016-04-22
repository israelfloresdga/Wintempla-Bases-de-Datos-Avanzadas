USE Kimberly;
GO

ALTER PROCEDURE p_while_rev
(
	@in_max DECIMAL
)
AS
	DECLARE @p_index DECIMAL(4,0)=2;
BEGIN
	WHILE (@p_index < @in_max AND @p_index>0)
	BEGIN
		PRINT(@in_max);
		SET @in_max= @in_max-1;
	END;
END;
GO