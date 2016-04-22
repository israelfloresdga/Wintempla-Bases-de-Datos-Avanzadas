connect circuitcity;
1234


CREATE OR REPLACE FUNCTION f_soldn
(
	input INTEGER
)
RETURN INTEGER
IS
	p_result INTEGER:=0;
	CURSOR cur_ord_det IS 
		SELECT item_id, item_count 
		FROM ord_det 
		WHERE item_id= input;
	p_item_count INTEGER:=0;
BEGIN
	FOR rec_ord_det IN cur_ord_det
	LOOP
		p_item_count:= rec_ord_det.item_count;

		p_result:= p_result + p_item_count;
	END LOOP;

	RETURN(p_result);
END f_soldn;
/


SELECT item_id, 
	f_soldn(item_id) AS sold
FROM item;

