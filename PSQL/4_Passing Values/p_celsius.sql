CREATE OR REPLACE PROCEDURE p_celsius
(
	in_farenheit NUMBER
)
IS
p_celsius NUMBER(6,2);
BEGIN
	p_celsius:=(in_farenheit-32)*(5/9);
	dbms_output.put_line(in_farenheit || ' °F are ' || p_celsius || '°C');
END p_celsius;
/