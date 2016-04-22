CREATE OR REPLACE PROCEDURE p_beta
IS
	p_a NUMBER(5,2):= 2;
	p_b NUMBER(5,2):= 10;
	p_c NUMBER(5,2):= 12;
BEGIN
	IF(p_a>p_b) THEN
		p_a:= p_a*p_b;
	ELSE
		IF(NOT p_a<p_c) THEN --IF(p_a>=p_c) THEN
			p_a:=p_b/3.0;
		END IF;
		p_b:= p_a/2.0;
	END IF;
	dbms_output.put_line(p_a || ', ' || p_b || ', ' || p_c);
END p_beta;
/