--17
SELECT 
	typez,
	SUM(balance) AS sumz,
	AVG(balance) AS avgz,
	MIN(balance) AS minz,
	MAX(balance) AS maxz
FROM account
GROUP BY typez


--18
SELECT 
	b.name,
	SUM(a.balance) AS sumz,
	AVG(a.balance) AS avgz,
	MIN(a.balance) AS minz,
	MAX(a.balance) AS maxz
FROM account a, branch b
WHERE b.branch_id= a.branch_id
GROUP BY b.name


--19
SELECT 
	c.name,
	COUNT(ac.account_id)
FROM client_account ac, 
	client c
WHERE ac.client_id= c.client_id
GROUP BY c.name
