SET ECHO OFF
SET VERIFY OFF
ACCEPT dept PROMPT 'What skill?'
SELECT e.last_name||', '||e.first_name AS EMPLOYEE,
	s.descr AS DEPARTAMENT
FROM employee e, skill s, emp_skill es
WHERE e.emp_id=es.emp_id AND
	s.skill_id= es.skill_id AND
	s.descr = '&dept';
SET ECHO ON
SET VERIFY ON