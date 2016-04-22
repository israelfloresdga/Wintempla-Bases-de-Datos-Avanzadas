DROP TABLE pi_value;

CREATE TABLE factorial_value
(
	value_id INTEGER NOT NULL,
	value NUMBER
);


CREATE OR REPLACE PROCEDURE p_factorial
(
	in_required_amount INTEGER
)
IS
	p_value NUMBER:= 1;
	p_index INTEGER:= 1;
	p_indexj INTEGER:= 1;
BEGIN
	DELETE FROM factorial_value;	

	FOR p_index IN 1..(in_required_amount)
	LOOP
		FOR p_indexj IN 1..p_index
		LOOP
			p_value:= p_value*p_indexj;
		END LOOP;
		INSERT INTO factorial_value(value_id, value) VALUES(p_index, p_value);	
		p_value:= 1;
	END LOOP;

END p_factorial;
/

EXECUTE p_factorial(10);

SELECT * FROM factorial_value;
