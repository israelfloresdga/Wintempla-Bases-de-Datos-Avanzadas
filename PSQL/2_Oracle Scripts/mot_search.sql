SET ECHO OFF
SET VERIFY OFF
ACCEPT input_c PROMPT 'Input: '
SELECT e.last_name||', '||e.first_name AS EMPLOYEE
FROM employee e
WHERE e.last_name LIKE '&input_c%' OR
	e.first_name LIKE '&input_c%';
SET ECHO ON
SET VERIFY ON