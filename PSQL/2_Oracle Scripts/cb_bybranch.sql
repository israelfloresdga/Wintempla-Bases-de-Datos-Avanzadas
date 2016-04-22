SET ECHO OFF
SET VERIFY OFF
ACCEPT branch PROMPT 'What branch? '
SELECT c.name AS CLIENT,
	b.name AS BRANCH
FROM client c, client_account ca, account a, branch b
WHERE c.client_id=ca.client_id AND
	ca.account_id=a.account_id AND
	a.branch_id=b.branch_id AND
	b.name LIKE '&branch%';
SET ECHO ON
SET VERIFY ON