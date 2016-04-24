--10 
--use kimberly oracle
SELECT RPAD(descr,10,'.') AS name, 
	RPAD(cost,10,'.') as cost,
	LTRIM(density) as density
FROM material
ORDER BY cost


--18
--use city bank oracle\mssql\mysql
SELECT name, ssn, REPLACE(ssn,'-','') AS clean_ssn
FROM friend