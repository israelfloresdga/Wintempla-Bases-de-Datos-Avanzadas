CREATE OR REPLACE PROCEDURE p_while
IS
	required_amount CONSTANT NUMBER(10,2):= 5500;
	total NUMBER(10,2):= 0;
	balance NUMBER(10,2):= 500;
BEGIN
	WHILE(total<required_amount)
	LOOP
		total:= total+balance;
		dbms_output.put_line(total);
	END LOOP;
END p_while;
/

SET SERVEROUTPUT ON;
EXECUTE p_while;