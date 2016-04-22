CREATE OR REPLACE FUNCTION impuesto
(
	input NUMBER
)
RETURN NUMBER
IS
	p_result NUMBER(12,2):=0;

BEGIN
	IF (input>0.0) THEN
		p_result:= input*(17.0/100.0);
	ELSE 
		p_result:= 0.0;
	END IF;
RETURN (p_result);
END impuesto;
/

SELECT account_id,
	balance,
	impuesto(balance) as tax
FROM account;