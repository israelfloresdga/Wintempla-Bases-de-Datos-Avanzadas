connect circuitcity;
1234
SET SERVEROUTPUT ON;


CREATE OR REPLACE PROCEDURE p_gratis
IS
	CURSOR cur_ord_det IS
		SELECT * FROM ord_det_copy
		FOR UPDATE OF item_count;
	p_item_count INT;
BEGIN
	FOR rec_ord_det IN cur_ord_det
	LOOP
		p_item_count:= rec_ord_det.item_count;

		IF(p_item_count>4) THEN
			UPDATE ord_det_copy
			SET item_count= p_item_count+1
			WHERE CURRENT OF cur_ord_det;
		END IF;
	END LOOP;

	COMMIT;
END p_gratis;
/


EXECUTE p_gratis;

SELECT * FROM ord_det_copy;