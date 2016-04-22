connect motorola;
1234
--NO FUNCIONA PROCEDIMIENTO

CREATE OR REPLACE PROCEDURE p_mot_emp
IS
BEGIN

	CREATE INDEX index_employee_last_name
	ON employee(last_name);
	
	TIMING START;
	EXECUTE p_emp;
	TIMING STOP;

	DROP INDEX index_employee_last_name;
	TIMING START;
	EXECUTE p_emp;
	TIMING STOP;

END p_mot_emp;
/
