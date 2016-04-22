CREATE OR REPLACE FUNCTION add5
(
	input NUMBER
)
RETURN NUMBER
IS
	p_result NUMBER(5,2):=0;
BEGIN
	p_result:= input +5;
RETURN (p_result);
END add5;
/

--SELECT cost, add5(cost) FROM material;
--SELECT add5(10) FROm dual;