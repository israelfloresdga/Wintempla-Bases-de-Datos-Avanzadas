SET ECHO OFF
SET VERIFY OFF
ACCEPT clientID PROMPT 'Enter value for client_id: '
SELECT name AS CLIENT
FROM client
WHERE client_id= &clientID;
SET ECHO ON
SET VERIFY ON