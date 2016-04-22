create or replace FUNCTION get_cost
(
    input INTEGER
)
RETURN NUMBER
IS
    p_result NUMBER(12,2):=0;
    p_weigth NUMBER(8,2):=0;
    p_material NUMBER(4,2):=0;
    p_density NUMBER(4,2):=0;
    p_cost NUMBER(4,2):=0;

BEGIN
    p_weigth:= get_weight(input);

    SELECT cost, density
    INTO p_cost, p_density
    FROM material m, item i
    WHERE i.made_of= m.material_id AND
        i.item_id= input;

    p_result:= p_weigth*p_density*p_cost;

RETURN (p_result);
END get_cost;


SELECT name, 
	get_weight(item_id) AS get_weight,
	get_cost(item_id) AS cost
FROM item;




-----get_cost2
--mt version
/
CREATE OR REPLACE FUNCTION get_cost2
(
    in_item_id IN INTEGER
)
RETURN NUMBER
IS 
    p_cost NUMBER;
    p_result NUMBER;
BEGIN
    SELECT a.cost
    INTO p_cost
    FROM material a, item b
    WHERE b.item_id=in_item_id

    p_result:=get_weight(in_item_id)*p_cost;
    RETURN(p_result);
END get_cost;
/