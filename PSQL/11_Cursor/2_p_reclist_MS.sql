USE city_bank;
GO

CREATE PROCEDURE p_reclist
AS
	DECLARE cur_client CURSOR READ_ONLY FOR SELECT client_id, name FROM client;
	DECLARE @p_count AS INT;
	DECLARE @p_client_id AS INT;
	DECLARE @p_name AS NVARCHAR(16);
BEGIN
	SET @p_count= 0;
	OPEN cur_client
		FETCH NEXT FROM cur_client INTO @p_client_id, @p_name
		WHILE(@@FETCH_STATUS= 0)
		BEGIN
			SET @p_count= @p_count+1;
			PRINT(CAST(@p_client_id AS NVARCHAR)+'~ '+@p_name);
			FETCH NEXT FROM cur_client INTO @p_client_id, @p_name
		END
	CLOSE cur_client;
	DEALLOCATE cur_client;
	PRINT('The value of p_count is '+CAST(@p_count AS NVARCHAR));
END
GO


--USE city_bank;
--EXECUTE p_reclist;