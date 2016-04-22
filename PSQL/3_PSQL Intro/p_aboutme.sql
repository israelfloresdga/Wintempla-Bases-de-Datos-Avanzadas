CREATE OR REPLACE PROCEDURE p_aboutme
IS
	in_last_name VARCHAR(32);
	in_first_name VARCHAR(32);
	in_age INTEGER;
	in_profession VARCHAR(32);
	BEGIN
		in_last_name:='Last Name: Flores';
		in_first_name:='First Name: Marcos';
		in_age:='Age: 24';
		in_profession:='Student';
		dbms_output.put_line(in_last_name);
		dbms_output.put_line(in_first_name);
		dbms_output.put_line(in_age);
		dbms_output.put_line(in_profession);
	END;
/

--SET SERVEROUTPUT ON;
--EXECUTE p_aboutme;