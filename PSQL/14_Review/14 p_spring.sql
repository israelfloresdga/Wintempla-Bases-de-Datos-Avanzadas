connect circuitcity;
1234


SET SERVEROUTPUT ON;
@C:\TFTP-Root\CircuitCityDB.sql


CREATE OR REPLACE PROCEDURE p_spring
IS
	p_incr CONSTANT NUMBER:= 1.1255;
	p_decr CONSTANT NUMBER:= 0.7500;

	CURSOR cur_item IS
			SELECT item_id, name, cost FROM item
			FOR UPDATE OF cost;
	p_cost NUMBER(15,2);
BEGIN
	FOR rec_item IN cur_item
	LOOP
		p_cost:= rec_item.cost;
		
		IF (p_cost>300.0) THEN
			UPDATE item
			SET cost= ROUND(p_cost*p_incr,2)
			WHERE CURRENT OF cur_item;
		ELSIF (p_cost>0.0 AND p_cost<100.0) THEN
			UPDATE item
			SET cost= ROUND(p_cost*p_decr,2)
			WHERE CURRENT OF cur_item;
		ELSE
			dbms_output.put_line('ERROR at' || rec_item.item_id);
		END IF;
	END LOOP;
END p_spring;
/


SELECT item_id, 
	name,
	cost
FROM item;

EXECUTE p_spring;

SELECT item_id,
	name,
	cost
FROM item;

@C:\TFTP-Root\CircuitCityDB.sql
