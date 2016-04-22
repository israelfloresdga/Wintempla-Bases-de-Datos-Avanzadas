connect kimberly;
1234
SET SERVEROUTPUT ON;


CREATE OR REPLACE PROCEDURE p_matinc
IS
	price_increment CONSTANT NUMBER:= 1.034;

	CURSOR cur_material IS
			SELECT * FROM material
			FOR UPDATE OF cost;
	p_cost NUMBER;
BEGIN
	FOR rec_material IN cur_material
	LOOP
		p_cost:= rec_material.cost;

		UPDATE material
		SET cost= ROUND(p_cost*price_increment,2)
		WHERE CURRENT OF cur_material;
		
	END LOOP;
END p_matinc;
/


EXECUTE p_matinc;
SELECT * FROM material;

