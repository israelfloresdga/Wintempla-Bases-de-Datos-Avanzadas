connect kimberly;
1234
SET SERVEROUTPUT ON;


CREATE OR REPLACE PROCEDURE p_matden
IS
	hiden_incr CONSTANT NUMBER:= 1.021;
	lowden_decr CONSTANT NUMBER:= 0.9547;

	CURSOR cur_material IS
			SELECT * FROM material
			FOR UPDATE OF cost;
	p_cost NUMBER;
BEGIN
	FOR rec_material IN cur_material
	LOOP
		p_cost:= rec_material.cost;
		IF(p_cost>1.0) THEN
			UPDATE material
			SET cost= ROUND(p_cost*hiden_incr,2)
			WHERE CURRENT OF cur_material;
		ELSIF(p_cost>0.0 AND p_cost<=1.0) THEN
			UPDATE material
			SET cost= ROUND(p_cost*lowden_decr,2)
			WHERE CURRENT OF cur_material;
		ELSE
			dbms_output.put_line('ERROR');
		END IF;
	END LOOP;
END p_matden;
/

SELECT * FROM material;
EXECUTE p_matden;
SELECT * FROM material;

--@C:\TFTP-Root\Recover.sql