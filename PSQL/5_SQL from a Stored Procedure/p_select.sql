CREATE OR REPLACE PROCEDURE p_select
IS
	p_name VARCHAR2(32);
BEGIN
	SELECT name INTO p_name 
	FROM item
	WHERE height=12;

	dbms_output.put_line(p_name||' has a height of 12.');
END p_select;
/