CREATE OR REPLACE PROCEDURE p_for
(
	in_max NUMBER
)
IS
	p_index NUMBER(4,0);
BEGIN
	FOR p_index IN 1..in_max
	LOOP
		dbms_output.put_line(p_index);
	END LOOP;
END p_for;
/