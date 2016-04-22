SET ECHO OFF
SET VERIFY OFF
ACCEPT dept PROMPT 'What department?'
SELECT e.last_name||', '||e.first_name AS EMPLOYEE,
	d.descr AS DEPARTAMENT
FROM employee e, department d
WHERE e.dept_id=d.dept_id AND
	d.descr = '&dept';
SET ECHO ON
SET VERIFY ON