USE city_bank;
GO

ALTER PROCEDURE p_balance
(
	@in_name NVARCHAR
)
AS
	DECLARE @p_balance AS MONEY;
	DECLARE @p_client AS NVARCHAR(32);
BEGIN
	SELECT @p_client= name
	FROM client
	WHERE name LIKE '%'+@in_name+'%';

	SELECT
		@p_balance= SUM(a.balance) 
	FROM client c, client_account ca, account a
	WHERE c.client_id = ca.client_id AND a.account_id = ca.account_id
			AND c.name = @p_client;

	PRINT('The balance of '+@p_client+' is '+CAST(@p_balance AS NVARCHAR));
END;


--USE city_bank;
--execute p_balance 'We';

-- IF EXISTS (SELECT * FROM sys.objects WHERE object_id = OBJECT_ID(N'p_balan') AND type in (N'P', N'PC'))
-- DROP PROCEDURE p_balan
-- GO
-- CREATE PROCEDURE p_balan
-- (
    -- @p_name VARCHAR(32)
-- )
-- AS
-- DECLARE @p_balan AS FLOAT;
-- BEGIN
    -- SELECT @p_balan= SUM(a.balance)
    -- FROM account a, branch b, client c, client_account ca
        -- WHERE a.branch_id = b.branch_id
        -- AND a.account_id = ca.account_id
        -- AND c.client_id = ca.client_id
        -- AND c.name LIKE '%'+@p_name+'%'
        
        -- PRINT('The balance of ' + @p_name + ', is $ ' + CAST(@p_balan AS VARCHAR));
-- END
-- GO