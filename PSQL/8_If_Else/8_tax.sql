CREATE OR REPLACE FUNCTION tax
(
	input NUMBER
)
RETURN NUMBER
IS
	p_result NUMBER(12,2):=0;

BEGIN
	IF (input>1000.0) THEN
		p_result:= input*(25.0/100.0);
	ELSIF (input>0.0 and input<=1000.0) THEN
		p_result:= input*(12.0/100.0);
	ELSE 
		p_result:= 10.0;
	END IF;
RETURN (p_result);
END tax;
/


SELECT account_id,
	balance,
	tax(balance) AS tax
FROM account;