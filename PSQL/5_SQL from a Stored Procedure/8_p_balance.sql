CREATE OR REPLACE PROCEDURE p_balance
(
	in_name IN VARCHAR2
)
IS
	p_balance NUMBER;
	p_client VARCHAR2(32);
BEGIN
	SELECT name INTO p_client
	FROM client
	WHERE name LIKE '%'||in_name||'%';

	SELECT
		SUM(a.balance) 
		INTO p_balance
	FROM client c, client_account ca, account a
	WHERE c.client_id = ca.client_id AND a.account_id = ca.account_id
			AND c.name = p_client;

	dbms_output.put_line('The balance of ' || p_client || ' is ' || p_balance);

END p_balance;
/

--O también se puede realizar

--CREATE OR REPLACE PROCEDURE p_balance
--(
--	in_name IN VARCHAR2
--)
--IS
--	p_balance NUMBER;
--	p_client VARCHAR2(32);
--BEGIN
--	SELECT
--		SUM(a.balance) 
--		INTO p_balance
--	FROM client c, client_account ca, account a
--	WHERE c.client_id = ca.client_id AND a.account_id = ca.account_id
--			AND c.name LIKE '%'||in_name||'%';

--	SELECT name INTO p_client
--	FROM client
--	WHERE name LIKE '%'||in_name||'%';

--	dbms_output.put_line('The balance of ' || p_client || ' is ' || p_balance);

--END p_balance;
--/