--3
SELECT
	COUNT(position) AS number_professors
FROM staff
WHERE position= 'Professor'


--5
SELECT Round(AVG(salary),2) AS salary_secretary
FROM staff
WHERE position='Secretary'


--6
SELECT
	MIN(salary) AS salary_min,
	MAX(salary) AS salary_max
FROM staff
WHERE position= 'Dept Head'


--7
SELECT
	position,
	COUNT(position) AS number,
	ROUND(AVG(salary),2) AS salary_avg,
	ROUND(STDEV(salary),2) AS salary_stdev
FROM staff
GROUP BY position
ORDER BY position ASC


--8
SELECT
	s.last_name,
	s.first_name,
	s1.last_name AS boss_last_name,
	s1.first_name AS boss_first_name
FROM staff s, staff s1
WHERE s.position !='President' AND
	s.manager_id = s1.staff_id 
ORDER BY last_name ASC


--10
SELECT
	department_id,
	COUNT(department_id),
	AVG(salary) AS salary_avg
FROM staff
GROUP BY department_id
HAVING AVG(salary)>4000.00


--11
SELECT
	position,
	COUNT(position) AS number,
	ROUND(MAX(salary),2) AS salary_max,
	ROUND(MIN(salary),2) AS salary_min
FROM staff
GROUP BY position
HAVING COUNT(position)>=2
ORDER BY position ASC


--12
SELECT
	position,
	COUNT(position) AS number,
	ROUND(MAX(salary),2) AS salary_max,
	ROUND(MIN(salary),2) AS salary_min
FROM staff
WHERE salary>2500.00 AND
	salary<5500.00
GROUP BY position
HAVING COUNT(position)>=2
ORDER BY position ASC