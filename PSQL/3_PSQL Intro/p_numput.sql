CREATE OR REPLACE PROCEDURE p_numput
IS
in_weight NUMBER(4,0);
in_age INtEGER;
BEGIN
	in_weight:=36;
	in_age:=169;
	dbms_output.put('Age: ');
	dbms_output.put_line(in_age);
	dbms_output.put('Weight: ');
	dbms_output.put_line(in_weight);
END p_numput;
/