USE circuit_city_avanzada;
GO

CREATE PROCEDURE p_promo118
AS
	DECLARE @p_incr DECIMAL= 2.1875;
	DECLARE @p_decr DECIMAL= 0.9744;

	DECLARE cur_cred_cli CURSOR FOR 
		SELECT client_id, credit 
		FROM credit_client 
		FOR UPDATE OF credit;

	DECLARE @p_client_id INT;
	DECLARE @p_credit MONEY= 0.0;
			
	DECLARE @p_result MONEY;
BEGIN
	BEGIN TRANSACTION
	OPEN cur_cred_cli
		FETCH NEXT FROM cur_cred_cli INTO @p_client_id, @p_credit
		WHILE(@@FETCH_STATUS= 0)
		BEGIN
			IF(@p_credit>2000.0)
			BEGIN
				UPDATE credit_client
					SET credit= @p_credit*@p_incr
					WHERE CURRENT OF cur_cred_cli;
					FETCH NEXT FROM cur_cred_cli INTO @p_client_id, @p_credit
			END
			ELSE
			BEGIN
				IF(@p_credit>0.0 AND @p_credit<500.0)
				BEGIN
					UPDATE credit_client
						SET credit= @p_credit*@p_decr
						WHERE CURRENT OF cur_cred_cli;
						FETCH NEXT FROM cur_cred_cli INTO @p_client_id, @p_credit
				END
			END
		END
	CLOSE cur_cred_cli;
	DEALLOCATE cur_cred_cli;

	COMMIT TRANSACTION;
	RETURN 1;
END
GO

SELECT client_id,
	credit
FROM credit_client;

EXECUTE p_creinc;

SELECT client_id,
	credit
FROM credit_client;
