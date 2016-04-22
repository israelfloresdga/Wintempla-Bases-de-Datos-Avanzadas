connect circuitcity;
1234
SET SERVEROUTPUT ON;


CREATE OR REPLACE PROCEDURE p_reward_client
IS
	CURSOR cur_ord_det IS SELECT c.name, od.order_id, SUM(od.item_count) AS countz 
		FROM ord_det od, client c, orderx o 
		WHERE od.order_id=o.order_id AND o.client_id=c.client_id 
		GROUP BY c.client_id, c.name, od.order_id
		ORDER BY order_id ASC;
	p_result VARCHAR2(32);
BEGIN
	FOR rec_ord_det IN cur_ord_det
	LOOP
		IF(rec_ord_det.countz>15) THEN
			p_result:='Monitor';
		ELSE
			IF(rec_ord_det.countz<=15 AND rec_ord_det.countz>5) THEN
				p_result:='Mouse';
			ELSE
				p_result:='nothing';
			END IF;
		END IF;
		dbms_output.put_line(rec_ord_det.name || ' -> ' || rec_ord_det.order_id || ' wins ' || p_result || ' -> ' || rec_ord_det.countz);
	END LOOP;
END p_reward_client;
/


EXECUTE p_reward_client;
