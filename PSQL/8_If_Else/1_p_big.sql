CREATE OR REPLACE PROCEDURE p_big
(
	input INTEGER
)
IS
BEGIN
	IF (input>5) THEN
		dbms_output.put_line(input || ' is bigger than 5.');
	ELSE
		dbms_output.put_line(input || ' is not bigger than 5.');
	END IF;
END p_big;
/