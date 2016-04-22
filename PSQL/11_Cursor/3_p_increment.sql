connect circuitcity;
1234
SET SERVEROUTPUT ON;

CREATE OR REPLACE PROCEDURE p_increment
IS
	CURSOR cur_item IS SELECT * FROM item;
	p_increment NUMBER(8,2):= 0;
BEGIN
	FOR rec_item IN cur_item
	LOOP
		IF(rec_item.cost>100.0) THEN
			p_increment:=rec_item.cost*(1.1);
		ELSE
			p_increment:=rec_item.cost*(1.01);
		END IF;
		dbms_output.put_line(rec_item.name || ': ' || rec_item.cost || ' -> ' || p_increment);
	END LOOP;
END p_increment;
/


EXECUTE p_increment;
