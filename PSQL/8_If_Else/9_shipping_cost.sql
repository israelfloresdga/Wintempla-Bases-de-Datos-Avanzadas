CREATE OR REPLACE FUNCTION shipping_cost
(
	input NUMBER
)
RETURN NUMBER
IS
	p_result NUMBER(12,2):=0.0;
	p_volume NUMBER(12,2):=0.0;
	p_width NUMBER(12,2):=0.0;
	p_height NUMBER(12,2):=0.0;
	p_depth NUMBER(12,2):=0.0;
	p_dimensions NUMBER(12,2):=0.0;
	p_density NUMBER(12,2):=0.0;
	p_weigth  NUMBER(12,2):=0.0;
BEGIN
	SELECT width, height, depth
	INTO p_width, p_height, p_depth
	FROM item
	WHERE item_id= input;

	p_dimensions:= p_width*p_height*p_depth;

	IF (p_dimensions<=15.0) THEN
		p_result:= 3.57*p_dimensions;
	ELSE 
		BEGIN
		SELECT density
	    INTO p_density
	    FROM material m, item i
	    WHERE i.made_of= m.material_id AND
	        i.item_id= input;
	    p_weigth:= p_dimensions*p_density;
	    p_result:=0.22*p_weigth;
		END;
	END IF;

	IF (p_width>10.0 or p_weigth>10.0 or p_depth>10.0) THEN
		p_result:=p_result+5.39;
	END IF;
RETURN (p_result);
END shipping_cost;
/


SELECT name,
	shipping_cost(item_id) AS shipping_cost
FROm item;