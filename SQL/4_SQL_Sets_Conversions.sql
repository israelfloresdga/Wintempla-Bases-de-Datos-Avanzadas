--Sets 5
--use city_bank
SELECT c.name AS client,
	ca.account_id AS account,
	a.balance*POWER((1+0.0109),5) AS balance 
FROM account a,
	client c,
	client_account ca
WHERE
	a.account_id = ca.account_id AND
	c.client_id = ca.client_id AND
	a.balance>=0.00
--
UNION
--
SELECT c.name AS client,
	ca.account_id AS account,
	a.balance*POWER((1+0.0541),5) AS balance 
FROM account a,
	client c,
	client_account ca
WHERE
	a.account_id = ca.account_id AND
	c.client_id = ca.client_id AND
	a.balance<0.0
ORDER BY c.name ASC


--Conversion 8
SELECT
	c.name,
	c.addressz,
	c.typez,
	LPAD(TO_CHAR(SUM(a.balance),'$99,999,999.99'),17, '*') as balance --Oracle
FROM client c,
	account a,
	client_account ca
WHERE
	c.client_id= ca.client_id AND
	a.account_id= ca.account_id
GROUP BY c.name, c.addressz, c.typez
ORDER BY c.name ASC


--Conversion 9
SELECT
	c.name,
	c.addressz,
	c.typez,
	'$'+CAST(SUM(a.balance) AS VARCHAR) as balance
	--TO_CHAR(SUM(a.balance),'$99,999,999.99') as balance --Oracle
FROM client c,
	account a,
	client_account ca
WHERE
	c.client_id= ca.client_id AND
	a.account_id= ca.account_id
GROUP BY c.name, c.addressz, c.typez
ORDER BY c.name ASC

