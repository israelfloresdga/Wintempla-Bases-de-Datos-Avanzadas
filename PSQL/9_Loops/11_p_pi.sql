CREATE OR REPLACE PROCEDURE p_pita
(
	in_required_amount INTEGER
)
IS
	p_value NUMBER:= 0;
	p_index INTEGER:= 0;
	p_result NUMBER:= 0;
BEGIN

	FOR p_index IN 0..(in_required_amount-1)
	LOOP
		IF(MOD(p_index,2)=1) THEN
			p_value:= 1.0/((2.0*p_index)+1.0);
		ELSE
			p_value:= -1.0/((2.0*p_index)+1.0);
		END IF;
		p_result:= p_result+p_value;
	END LOOP;
		p_result:= -4.0*p_result;
	dbms_output.put_line(p_result);
END p_pita;
/
