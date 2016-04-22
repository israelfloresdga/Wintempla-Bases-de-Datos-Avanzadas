USE city_bank;
GO

CREATE FUNCTION impuesto
(
	@input DECIMAL
)
RETURNS DECIMAL(12,2)
AS
BEGIN
	DECLARE @p_result DECIMAL(12,2)=0;

	IF (@input>0.0) 
		SET @p_result= @input*(17.0/100.0);
	ELSE 
		SET @p_result= 0.0;
RETURN (@p_result);
END;
GO

--SELECT account_id, 
--	balance,
--	dbo.impuesto(balance) AS tax
--FROM account;