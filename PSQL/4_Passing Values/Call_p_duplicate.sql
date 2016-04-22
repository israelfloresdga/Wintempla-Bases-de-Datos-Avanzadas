SET ECHO OFF
SET VERIFY OFF
ACCEPT in_numb PROMPT 'What is the number?'
EXECUTE p_duplicate(&in_numb);
SET ECHO ON
SET VERIFY ON