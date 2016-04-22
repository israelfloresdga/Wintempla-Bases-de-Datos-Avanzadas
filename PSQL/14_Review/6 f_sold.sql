connect circuitcity;
1234


CREATE OR REPLACE FUNCTION f_sold
(
	input INTEGER
)
RETURN INTEGER
IS
	p_result INTEGER;
BEGIN
	
	SELECT SUM(item_count)
	INTO p_result
	FROM ord_det
	GROUP BY item_id
	HAVING item_id= input;

	RETURN(p_result);
END f_sold;
/


SELECT item_id, 
	f_sold(item_id) AS sold
FROM item;

