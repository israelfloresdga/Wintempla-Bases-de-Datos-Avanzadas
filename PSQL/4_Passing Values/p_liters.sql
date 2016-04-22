--in_gallons is an input variable
--p_liters is a procedure variable
CREATE OR REPLACE PROCEDURE p_liters
(
	in_gallons NUMBER
)
IS
p_liters NUMBER(6,2);
BEGIN
	p_liters:=in_gallons*3.7854;
	dbms_output.put_line(in_gallons || ' gallons are ' || p_liters || 'Lt');
END p_liters;
/