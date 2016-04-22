USE Kimberly;
GO

CREATE FUNCTION multiply2numbers
(
	@inputA DECIMAL(4,2),
	@inputB DEcIMAL(4,2)
)
RETURNS DECIMAL
AS
BEGIN
	DECLARE @p_result DECIMAL(9,2)= 0.0;
	SET @p_result= @inputA * @inputB;
RETURN (@p_result);
END;
GO

--USE Kimberly;
--SELECT name, dbo.multiply2numbers(width, height) AS product
--FROm item;
--GO