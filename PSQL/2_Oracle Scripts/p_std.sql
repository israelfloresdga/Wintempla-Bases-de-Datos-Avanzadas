SET ECHO OFF
SET VERIFY OFF
ACCEPT in_state PROMPT 'What is the state?'
SELECT name, state_n
FROM store
	where state_n='&in_state';
SET ECHO ON
SET VERIFY ON