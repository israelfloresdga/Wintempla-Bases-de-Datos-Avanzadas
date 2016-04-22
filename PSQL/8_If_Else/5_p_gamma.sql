CREATE OR REPLACE PROCEDURE p_gamma
(
	input NUMBER
)
IS
BEGIN
	IF(input>10.0) THEN
		dbms_output.put_line(input || ' is bigger than 10.0');
	ELSIF(input<2) THEN
		dbms_output.put_line(input || ' is smaller than 2.0');
	ELSIF(input=5) THEN
		dbms_output.put_line(input || ' is equal to 5.0');
	ELSE
		dbms_output.put_line('Hola');
	END IF;
	dbms_output.put_line('Default');
END p_gamma;
/