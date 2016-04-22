CREATE OR REPLACE PROCEDURE p_tax
(
	input DECIMAL
)
IS
	p_result DECIMAL(12,2):=0;
BEGIN
	IF (input<10000.00) THEN
		p_result:= input*(15.0/100.0);
	ELSE
		p_result:= input*(20.0/100.0);
	END IF;
	dbms_output.put_line('For a income of ' || TO_CHAR(input, '$9,999,999.99') || ' your taxes are ' || TO_CHAR(p_result,'$9,999,999.99'));

END p_tax;
/


SET SERVEROUTPUT ON;
EXECUTE p_tax(5250);

EXECUTE p_tax(22543);