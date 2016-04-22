CREATE OR REPLACE FUNCTION get_term
(
	input INTEGER
)
RETURN NUMBER
IS
	p_num NUMBER:= 0;
	p_den NUMBER:= 0;
	p_result NUMBER:= 0;
BEGIN
	--IF(input=0) THEN
	--	p_num:= 2.0;
	--	p_den:= 1.0;
	IF(MOD(input,2)=0) THEN
		p_num:= input+2.0;
		p_den:= input+1.0;
	ELSE
		p_num:= input+1.0;
		p_den:= input+2.0;
	END IF;
	p_result:= p_num/p_den;
	--dbms_output.put_line(p_num || '/ ' || p_den);
	RETURN(p_result);
END get_term;
/

SELECT get_term(0) FROM DUAL;
