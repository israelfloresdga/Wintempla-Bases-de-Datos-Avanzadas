CREATE OR REPLACE FUNCTION to_celsius
(
	input NUMBER
)
RETURN NUMBER
IS
	p_result NUMBER(9,2):=0;
BEGIN
	p_result:= (5.0/9.0)*(input-32.0);
RETURN (p_result);
END to_celsius;
/

--SELECT value, to_celsius(value) AS to_celsius
--FROM temperature;