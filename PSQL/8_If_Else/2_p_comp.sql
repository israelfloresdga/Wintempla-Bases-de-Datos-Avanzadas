CREATE OR REPLACE PROCEDURE p_comp
IS
	p_a NUMBER(5,2):= 22;
	p_b NUMBER(5,2):= 15;
BEGIN
	IF (p_a<p_b) THEN
		p_a:=72;
	ELSE
		p_a:= p_b/3;
		p_b:= p_a/2;
	END IF;
		dbms_output.put_line(p_a || ', ' || p_b);
END p_comp;
/