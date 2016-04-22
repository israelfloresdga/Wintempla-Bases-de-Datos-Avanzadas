--Para Oracle las fechas se restan directamente
--además para considerar el año bisiesto se divide entre 365.25

--14
SELECT 
	name, 
	birth_date, 
	DATEPART(year, GETDATE()) AS year_t, 
	DATENAME(year, birth_date) AS year_n, 
	DATEPART(year, GETDATE()) - DATENAME(year, birth_date) AS age
FROM employee


--15
SELECT employee_id, 
	CAST(DATEDIFF(day, contract_date, '2007-12-31') * 7 AS MONEY) AS fund
	--CAST Formato de fecha
FROM employee


--16
SELECT name, 
	DATEPART(year, GETDATE()) - DATENAME(year, birth_date) AS year
FROM employee
WHERE (DATEPART(year, GETDATE()) - DATENAME(year, birth_date) > 50)


--17
SELECT e.name, 
	p.descr, 
	d.name AS department, 
	pr.salary, 
	pr.eff_date AS trans_date
FROM employee AS e INNER JOIN
    payroll AS pr ON e.employee_id = pr.employee_id INNER JOIN
    position AS p ON pr.position_id = p.position_id INNER JOIN
    division AS d ON pr.division_id = d.division_id
WHERE (e.employee_id = 50)


--18
SELECT e.name, 
	p.descr, 
	d.name AS department, 
	pr.salary, 
	pr.eff_date AS trans_date
FROM employee AS e INNER JOIN
    payroll AS pr ON e.employee_id = pr.employee_id INNER JOIN
    position AS p ON pr.position_id = p.position_id INNER JOIN
    division AS d ON pr.division_id = d.division_id
WHERE (pr.eff_date =
    	(SELECT        MAX(eff_date) AS Expr1
    	FROM            payroll
        WHERE        (employee_id = 50)))


--19
SELECT e.name, 
	p.descr, 
	d.name AS department, 
	pr.salary, 
	pr.eff_date AS trans_date
FROM employee AS e INNER JOIN
    payroll AS pr ON e.employee_id = pr.employee_id INNER JOIN
    position AS p ON pr.position_id = p.position_id INNER JOIN
    division AS d ON pr.division_id = d.division_id
WHERE (pr.eff_date =
        (SELECT        MAX(eff_date) AS Expr1
        FROM            payroll
        WHERE        (employee_id = 50)))