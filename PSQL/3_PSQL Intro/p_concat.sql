CREATE OR REPLACE PROCEDURE p_concat
IS
in_weight NUMBER(4,0);
in_age INtEGER;
BEGIN
	in_weight:=36;
	in_age:=169;
	dbms_output.put_line('Age: '||in_age);
	dbms_output.put_line('Weight: '||in_weight);
END p_concat;
/