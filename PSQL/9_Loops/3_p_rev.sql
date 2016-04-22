CREATE OR REPLACE PROCEDURE p_rev
(
	in_max NUMBER
)
IS
	p_index NUMBER(4,0);
BEGIN
	FOR p_index IN REVERSE 3..in_max
	LOOP
		dbms_output.put_line(p_index);
	END LOOP;
END p_rev;
/