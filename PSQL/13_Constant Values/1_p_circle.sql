connect kimberly;
1234

SET SERVEROUTPUT ON;

CREATE OR REPLACE PROCEDURE p_circle
(
	radius NUMBER,
	label VARCHAR2
)
IS
	PI CONSTANT NUMBER:= 3.14159;
	p_diameter NUMBER;
	p_circumference NUMBER;
	p_area NUMBER;
BEGIN
	p_diameter:= 2.0*radius;
	p_circumference:= 2.0*radius*PI;
	p_area:= radius*radius*PI;

	dbms_output.put_line('Diameter: ' || p_diameter || ' ' || label);
	dbms_output.put_line('Circumference: ' || p_circumference || ' ' || label);
	dbms_output.put_line('Area: ' || p_area || ' sq-' || label);
END p_circle;
/

EXECUTE p_circle(10, 'cm');
EXECUTE p_circle(20, 'ft');