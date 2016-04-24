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



--Conversion 2
--use aeromexico oracle
SELECT destination || ' is in ' || NVL(city, 'UNKNOWN') || ' for ' || NVL(flight_cost, 500)
FROM mexico


--Conversion 6
--use ford oracle
SELECT name, phone AS current_phone,(SUBSTR(phone,0,3)+55)||(SUBSTR(phone,4)) AS new_phone
FROM store

--use ford mssql
SELECT name, 
	phone AS current_phone,
	CAST((SUBSTRING(phone,1,3)+55) AS nvarchar)+(SUBSTRING(phone,4,12)) AS new_phone
FROM store

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

