connect circuitcity;
1234


SET SERVEROUTPUT ON;
@C:\TFTP-Root\CircuitCityDB.sql


CREATE OR REPLACE PROCEDURE p_sales1745
IS
	p_incr CONSTANT NUMBER:= 1.1745;

	CURSOR cur_item IS
			SELECT item_id, name, cost FROM item
			FOR UPDATE OF cost;
	p_result NUMBER(15,2);
BEGIN
	FOR rec_item IN cur_item
	LOOP
		p_result:= rec_item.cost;
		
		UPDATE item
		SET cost= ROUND(p_result*p_incr,2)
		WHERE CURRENT OF cur_item;
	END LOOP;
END p_sales1745;
/


SELECT item_id,
	cost
FROM item;

EXECUTE p_sales1745;

SELECT item_id,
	cost
FROM item;
@C:\TFTP-Root\CircuitCityDB.sql
