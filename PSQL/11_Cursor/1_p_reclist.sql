connect "CITY BANK";
1234

CREATE OR REPLACE PROCEDURE p_rec_list
IS
	CURSOR cur_client IS SELECT * FROM client;
	p_count NUMBER(3,0):= 0;
BEGIN
	FOR rec_client IN cur_client
	LOOP
		p_count:= p_count+1;
		dbms_output.put_line(rec_client.name);
	END LOOP;

	dbms_output.put_line('The value of count is: ' || p_count);
END p_rec_list;
/

SET SERVEROUTPUT ON;
EXECUTE p_rec_list;
