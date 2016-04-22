connect circuitcity;
1234


SET SERVEROUTPUT ON;
@C:\TFTP-Root\CircuitCityDB.sql

CREATE OR REPLACE PROCEDURE p_creinc
IS
	p_incr CONSTANT NUMBER:= 1.20;

	CURSOR cur_cred_cli IS
			SELECT * FROM credit_client
			FOR UPDATE OF credit;
	p_result NUMBER(15,2);
BEGIN
	FOR rec_cred_cli IN cur_cred_cli
	LOOP
		p_result:= rec_cred_cli.credit;
		
		UPDATE credit_client
		SET credit= ROUND(p_result*p_incr,2)
		WHERE CURRENT OF cur_cred_cli;
	END LOOP;
END p_creinc;
/


SELECT client_id,
	credit
FROM credit_client;

EXECUTE p_creinc;

SELECT client_id,
	credit
FROM credit_client;

