connect circuitcity;
1234


CREATE OR REPLACE FUNCTION f_total_cost
(
	input INTEGER
)
RETURN NUMBER
IS
	p_result NUMBER(12,2);
BEGIN
	SELECT SUM(od.item_count*i.cost) AS total
	INTO p_result
	FROM ord_det od, item i
	WHERE od.item_id=i.item_id
	GROUP BY od.order_id
	HAVING od.order_id= input;

	RETURN(p_result);
END f_total_cost;
/


SELECT  order_id, 
	f_total_cost(order_id) AS total
FROM orderx;

