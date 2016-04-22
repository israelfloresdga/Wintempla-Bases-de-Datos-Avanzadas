connect motorola;
1234

CREATE OR REPLACE PROCEDURE p_emp
IS
	p_last_name VARCHAR2(20);
	p_count INTEGER:= 0;
	max_value CONSTANT INTEGER:= 10000;
BEGIN
	FOR p_count IN 1..max_value
	LOOP
		SELECT last_name INTO p_last_name
		FROM employee
		WHERE last_name= 'Moonlight';
	END LOOP;
END p_emp;
/
