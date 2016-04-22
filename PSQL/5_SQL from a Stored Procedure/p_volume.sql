CREATE OR REPLACE PROCEDURE p_volume
(
	in_item_id IN INTEGER
)
IS
	p_item_id NUMBER;
	p_name VARCHAR2(32);
	p_volume NUMBER;
	p_height NUMBER;
	p_width NUMBER;
	p_depth NUMBER;
BEGIN
	SELECT name, height, width, depth
	INTO p_name, p_height, p_width, p_depth
	FROM item
	WHERE item_id= in_item_id;

	p_volume:= p_height*p_width*p_depth;
	dbms_output.put_line('The ' || p_name || ' volume is ' || p_volume);
END p_volume;
/