CREATE OR REPLACE FUNCTION get_weight
(
	input INTEGER
)
RETURN NUMBER
IS
	p_result NUMBER(12,2):=0;
	p_width NUMBER(4,2):=0;
	p_height NUMBER(4,2):=0;
	p_depth NUMBER(4,2):=0;

BEGIN
	SELECT width, height, depth
	INTO p_width, p_height, p_depth
	FROM item
	WHERE item_id= input;

	p_result:= p_width*p_height*p_depth;

RETURN (p_result);
END get_weight;
/



SELECT name, width, height, depth,
	get_weight(item_id) AS get_weight
FROM item;