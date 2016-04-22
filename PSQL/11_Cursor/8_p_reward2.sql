connect circuitcity;
1234
SET SERVEROUTPUT ON;


CREATE OR REPLACE PROCEDURE p_reward2
IS
	CURSOR cur_ord_det IS SELECT order_id, f_reward(order_id) AS reward FROM ord_det GROUP BY order_id;
	--p_result VARCHAR2(32);
BEGIN
	FOR rec_ord_det IN cur_ord_det
	LOOP
		dbms_output.put_line(rec_ord_det.order_id || ' wins ' || rec_ord_det.reward);
	END LOOP;
END p_reward2;
/


EXECUTE p_reward2;
