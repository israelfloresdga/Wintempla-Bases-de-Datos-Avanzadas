USE city_bank;
GO

CREATE FUNCTION tax
(
	@input DECIMAL
)
RETURNS DECIMAL(12,2)
AS
BEGIN
	DECLARE @p_result DECIMAL(12,2)=0;

	IF (@input>1000.0)
		SET @p_result= @input*(25.0/100.0);
	ELSE
		BEGIN
		IF (@input>0.0 and @input<=1000.0)
			SET @p_result= @input*(12.0/100.0);
		ELSE 
			SET @p_result= 10.0;
		END;
RETURN (@p_result);
END;
GO

--SELECT account_id,
--	balance,
--	dbo.tax(balance) AS tax
--FROM account;