USE city_bank;
GO

ALTER PROCEDURE p_tax
(
	@input DECIMAL
)
AS
BEGIN
	DECLARE @p_result DECIMAL(12,2)=0;

	IF (@input<10000.00)
		SET @p_result= @input*(15.0/100.0);
	ELSE
		SET @p_result= @input*(20.0/100.0);

	PRINT('For a income of ' + '$' + CONVERT(NVARCHAR(32),CAST(@input AS MONEY),1) + ' your taxes are ' + + '$' + CONVERT(NVARCHAR(32),CAST(@p_result AS MONEY),1));
END;
GO

--USE city_bank;
--GO

--EXECUTE p_tax 5250;