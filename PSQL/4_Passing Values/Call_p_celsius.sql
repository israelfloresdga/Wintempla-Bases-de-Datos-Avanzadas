SET ECHO OFF
SET VERIFY OFF
ACCEPT in_numb PROMPT 'How many fahrenheit? '
EXECUTE p_celsius(&in_numb);
SET ECHO ON
SET VERIFY ON