connect motorola;
1234

CREATE OR REPLACE PROCEDURE p_motem
IS
	p_last_name VARCHAR2(20);
	p_count INTEGER:= 0;
	max_value CONSTANT INTEGER:= 100000;
	p_start_time CHAR(5):= 0;
	p_end_time CHAR(5):= 0;
	p_duration NUMBER(10,5):= 0;
BEGIN
	p_start_time:= TO_CHAR(SYSDATE,'SSSSS');

	FOR p_count IN 1..max_value
	LOOP
		SELECT last_name INTO p_last_name
		FROM employee
		WHERE last_name= 'Moonlight';
	END LOOP;

	p_end_time:= TO_CHAR(SYSDATE,'SSSSS');
	p_duration:= TO_NUMBER(p_end_time)-TO_NUMBER(p_start_time);
	dbms_output.put_line('Running time is: ' || p_duration || ' sec.');

END p_motem;
/
