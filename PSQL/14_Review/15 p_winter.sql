connect circuitcity;
1234


SET SERVEROUTPUT ON;

@C:\TFTP-Root\CircuitCityDB.sql

CREATE OR REPLACE PROCEDURE p_winter
IS
	p_incr CONSTANT NUMBER:= 1.0570;
	p_decr CONSTANT NUMBER:= 0.7750;

	CURSOR cur_item IS
		SELECT item_id,
			f_soldn(item_id) AS item_count
		FROM item
		GROUP BY item_id;
	p_item_id INTEGER;
	p_item_count INTEGER;
	p_cost NUMBER(15,2);
BEGIN
	FOR rec_item IN cur_item
	LOOP
		p_item_id:= rec_item.item_id;
		p_item_count:= rec_item.item_count;
		--p_cost:= rec_item.cost;
		
		IF (p_item_count>5) THEN
			UPDATE item
			SET cost= ROUND(cost*p_incr,2)
			WHERE item_id= p_item_id;
		ELSIF (p_item_count=0) THEN
			UPDATE item
			SET cost= ROUND(cost*p_decr,2)
			WHERE item_id= p_item_id;
		ELSE
			dbms_output.put_line('ERROR at' || rec_item.item_id);
		END IF;
	END LOOP;
END p_winter;
/


SELECT item_id, 
	name,
	cost
FROM item;

EXECUTE p_winter;

SELECT item_id,
	name,
	cost
FROM item;

@C:\TFTP-Root\CircuitCityDB.sql



--SELECT od.item_id,
--	SUM(od.item_count) AS item_count,
--	i.name,
--	i.cost
--FROM ord_det od, item i
--WHERE od.item_id=i.item_id
--GROUP BY od.item_id, i.name, i.cost;