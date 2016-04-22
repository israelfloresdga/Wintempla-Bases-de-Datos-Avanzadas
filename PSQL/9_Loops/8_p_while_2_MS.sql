USE Kimberly;
GO

CREATE PROCEDURE p_while_2
AS
BEGIN
	DECLARE @required_amount DECIMAL(10,2)= 5500;
	DECLARE @total DECIMAL(10,2)= 0;
	DECLARE @balance DECIMAL(10,2)= 500;

	WHILE(@total<@required_amount)
	BEGIN
		SET @total= @total+@balance;
		PRINT(@total);
	END;
END;
GO