CREATE OR REPLACE PROCEDURE p_fill_temp
(
	in_temp NUMBER,
	in_incr NUMBER,
	in_max INTEGER
)
IS
	p_index NUMBER(4,0);
BEGIN
	DELETE FROM temperature;

	--INSERT INTO temperature VALUES(1, in_temp);
	FOR p_index IN 1..in_max
	LOOP
		INSERT INTO temperature VALUES(p_index, in_temp+(in_incr*(p_index-1)));
	END LOOP;
END p_fill_temp;
/


execute p_fill_temp(-40,5,6);

SELECT *
FROM temperature;