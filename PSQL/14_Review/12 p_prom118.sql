connect circuitcity;
1234


SET SERVEROUTPUT ON;
@C:\TFTP-Root\CircuitCityDB.sql

CREATE OR REPLACE PROCEDURE p_promo128
IS
	p_incr CONSTANT NUMBER:= 2.1875;
	p_decr CONSTANT NUMBER:= 0.9744;

	CURSOR cur_cred_cli IS
			SELECT * FROM credit_client
			FOR UPDATE OF credit;
	p_credit NUMBER(15,2);
BEGIN
	FOR rec_cred_cli IN cur_cred_cli
	LOOP
		p_credit:= rec_cred_cli.credit;
		
		IF (p_credit>2000.0) THEN
			UPDATE credit_client
			SET credit= ROUND(p_credit*p_incr,2)
			WHERE CURRENT OF cur_cred_cli;
		ELSIF (p_credit>0.0 AND p_credit<500.0) THEN
			UPDATE credit_client
			SET credit= ROUND(p_credit*p_decr,2)
			WHERE CURRENT OF cur_cred_cli;
		ELSE
			dbms_output.put_line('ERROR at' || rec_cred_cli.client_id);
		END IF;
	END LOOP;
END p_promo128;
/


SELECT client_id,
	credit
FROM credit_client;

EXECUTE p_promo128;

SELECT client_id,
	credit
FROM credit_client;

