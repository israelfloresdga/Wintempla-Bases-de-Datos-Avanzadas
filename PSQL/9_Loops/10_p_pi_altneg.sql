CREATE OR REPLACE PROCEDURE p_pi_altneg
(
	in_required_amount INTEGER
)
IS
	p_value NUMBER:= 0;
	p_index INTEGER:= 0;
	--p_trans INTEGER:= 0;
BEGIN
	--BEGIN
		DELETE FROM pi_value;	
	--	SELECT COUNT(*) INTO p_trans FROM temperature; 
	--	IF(p_trans<>0) THEN
	--		ROLLBACK;
	--		return;
	--	END IF;
	--END;

	FOR p_index IN 0..(in_required_amount-1)
	LOOP
		IF(MOD(p_index,2)=1) THEN
			p_value:= 1.0/((2.0*p_index)+1.0);
		ELSE
			p_value:= -1.0/((2.0*p_index)+1.0);
		END IF;
		
		INSERT INTO pi_value(value_id, value) VALUES(p_index+1, p_value);	
	END LOOP;

	--COMMIT;
END p_pi_altneg;
/


execute p_pi_altneg(10);

select * from pi_value;