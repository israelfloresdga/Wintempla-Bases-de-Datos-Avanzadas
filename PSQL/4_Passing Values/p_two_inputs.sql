CREATE OR REPLACE PROCEDURE p_two_inputs
(
	in_age INTEGER,
	in_weight NUMBER
)
IS
BEGIN
	dbms_output.put_line('Age: ' || in_age);
	dbms_output.put_line('Weight: ' || in_weight);
END p_two_inputs;
/

--EXECUTE p_two_inputs(55,78);