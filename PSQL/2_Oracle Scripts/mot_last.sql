SET ECHO OFF
SET VERIFY OFF
ACCEPT last_name_c PROMPT 'Write some characters from the last name:'
SELECT last_name||', '||first_name AS EMPLOYEE
FROM employee
WHERE last_name LIKE '&last_name_c%';
SET ECHO ON
SET VERIFY ON