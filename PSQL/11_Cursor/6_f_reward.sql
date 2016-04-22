connect circuitcity;
1234
SET SERVEROUTPUT ON;


CREATE OR REPLACE FUNCTION f_reward
(
	input INTEGER
)
RETURN VARCHAR2
IS
	CURSOR cur_ord_det IS SELECT o.order_id, SUM(od.item_count) AS countz 
		FROM orderx o, ord_det od 
		WHERE o.order_id= od.order_id AND o.order_id= input
		GROUP BY o.order_id;
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
	END LOOP;
	RETURN(p_result);
END f_reward;
/


SELECT  order_id, 
	f_reward(order_id) AS reward
FROM orderx;
