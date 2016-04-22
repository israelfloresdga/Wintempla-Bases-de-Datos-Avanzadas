CREATE OR REPLACE FUNCTION wallis_pi
(
	input INTEGER
)
RETURN NUMBER
IS
	p_result NUMBER:= 1;
	p_index INTEGER:= 0;
BEGIN
	FOR p_index IN 0..(input)
	LOOP 
		p_result:= p_result*get_term(p_index);
	END LOOP;
		
	RETURN(2.0*p_result);
END wallis_pi;
/

SELECT wallis_pi(5000) FROM DUAL;
