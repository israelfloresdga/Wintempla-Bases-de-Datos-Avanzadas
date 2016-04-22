--1 Oracle
DESCRIBE user_tables;


--SELECT * FROM user_tables;


--2 Oracle
SELECT table_name FROM user_tables;


--3 Oracle
SELECT table_name, tablespace_name
FROM user_tables
WHERE table_name NOT LIKE 'DEMO%!_%' escape'!' AND
	table_name NOT LIKE 'APEX$!_%' escape'!';
--'!' Va antes del caracter a ignorar 


--4 
USE city_bank;
GO

SELECT name FROM sysobjects
WHERE xtype= 'U';


--5 Oracle
SELECT object_name
FROM user_procedures;


--6 Oracle
SELECT object_name
FROM user_procedures
WHERE object_name NOT LIKE 'DEMO%!_%' escape'!' AND
	object_name NOT LIKE 'APEX$!_%' escape'!';
--'!' Va antes del caracter a ignorar 


--7
USE city_bank;
GO

SELECT name FROM sysobjects
WHERE xtype= 'P'
	OR  xtype= 'FN';


--8
SELECT constraint_name, table_name
FROM user_constraints
WHERE constraint_name LIKE 'SYS!_%' escape'!';


--9
USE city_bank;
GO

SELECT name FROM sysobjects
WHERE xtype= 'PK' 
	OR xtype= 'C';


--10
SELECT name, dbid 
FROM sysdatabases;


--11
