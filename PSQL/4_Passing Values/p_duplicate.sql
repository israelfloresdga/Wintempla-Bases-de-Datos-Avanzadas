CREATE OR REPLACE PROCEDURE p_duplicate
(
	x NUMBER	
)
IS 
BEGIN
	dbms_output.put_line('The double of ' ||x|| ' is ' || 2*x);
END p_duplicate;
/

--EXECUTE p_duplicate(5);