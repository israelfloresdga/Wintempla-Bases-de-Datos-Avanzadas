USE Kimberly;
GO

ALTER PROCEDURE p_pi_altneg
(
	@in_required_amount INT
)
AS
BEGIN
	DECLARE @p_value DECIMAL(12,9)= 0.0;
	DECLARE @p_index INT= 0;
	DECLARE @p_trans INT= 0;
	
	BEGIN TRANSACTION
		DELETE FROM pi_value;	
		SELECT @p_trans= COUNT(*) FROM pi_value;
		IF(@p_trans<>0)
		BEGIN
			ROLLBACK TRANSACTION;
			RETURN 0;
		END

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
						
			INSERT INTO pi_value(value_id, value) VALUES(@p_index+1, @p_value);
			IF (@@ROWCOUNT<>1) 
			BEGIN
				ROLLBACK TRANSACTION;
				RETURN 0;
			END
			SET @p_index= @p_index+1;	
		END

	COMMIT TRANSACTION;
	RETURN 1;
END;
GO


--EXECUTE p_pi_altneg 1000;
--GO

--SELECT * FROM pi_value
--WHERE value_id <22;