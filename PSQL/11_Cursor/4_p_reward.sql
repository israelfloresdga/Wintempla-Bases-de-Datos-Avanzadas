connect circuitcity;
1234
SET SERVEROUTPUT ON;


CREATE OR REPLACE PROCEDURE p_reward
IS
	CURSOR cur_ord_det IS SELECT order_id, 
		SUM(item_count) AS count 
		FROM ord_det GROUP BY order_id;
	p_result VARCHAR2(32);
BEGIN
	FOR rec_ord_det IN cur_ord_det
	LOOP
		IF(rec_ord_det.count>15) THEN
			p_result:='Monitor';
		ELSE
			IF(rec_ord_det.count<=15 AND rec_ord_det.count>5) THEN
				p_result:='Mouse';
			ELSE
				p_result:='nothing';
			END IF;
		END IF;
		dbms_output.put_line(rec_ord_det.order_id || ' wins ' || p_result || ' -> ' || rec_ord_det.count);
	END LOOP;
END p_reward;
/


EXECUTE p_reward;
