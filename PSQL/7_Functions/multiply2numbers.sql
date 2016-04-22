CREATE OR REPLACE FUNCTION multiply2numbers
(
	inputA NUMBER,
	inputB NUMBER
)
RETURN NUMBER
IS
	p_result NUMBER(9,2):=0;
BEGIN
	p_result:= inputA * inputB;
RETURN (p_result);
END multiply2numbers;
/

--SELECT name,
--	multiply2numbers(width, height) AS product
--FROM item;
	