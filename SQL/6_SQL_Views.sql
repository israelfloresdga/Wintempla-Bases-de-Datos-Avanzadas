--Motorola 3
CREATE or REPLACE VIEW "vw_emp" AS
SELECT e.last_name||', '||e.first_name AS name,
    d.descr AS department,
    s.descr AS skill
    FROM employee e, department d, skill s, emp_skill es
    WHERE e.dept_id = d.dept_id AND
    e.emp_id = es.emp_id AND
    es.skill_id = s.skill_id
    WITH CHECK OPTION

--Como se muestra en Oracle
--CREATE OR REPLACE FORCE VIEW  "vw_emp" ("NAME", "DEPARTMENT", "SKILL") AS
--  SELECT e.last_name||', '||e.first_name AS name,
--    d.descr AS department,
--    s.descr AS skill
--    FROM employee e, department d, skill s, emp_skill es
--    WHERE e.dept_id = d.dept_id AND
--    e.emp_id = es.emp_id AND
--    es.skill_id = s.skill_id
--    WITH CHECK OPTION;



--City Bank 1,3,4
--1
SELECT name, REPLACE(typez,'B','Business') AS typez
FROM client
WHERE typez='B';

CREATE OR REPLACE FORCE VIEW  "vw_buss" ("NAME", "TYPEZ") AS
  SELECT name, REPLACE(typez,'B','Business') AS typez
FROM client
WHERE typez='B';


--2
CREATE VIEW vw_client AS
SELECT c.name AS client,
     a.account_id AS account_id,
     a.balance AS balance
FROM client c, client_account ca, account a
WHERE c.client_id = ca.client_id AND a.account_id = ca.account_id;

create or replace view "vw_client" as
SELECT c.name AS client,
     a.account_id AS account_id,
     a.balance AS balance
FROM client c, client_account ca, account a
WHERE c.client_id = ca.client_id AND a.account_id = ca.account_id;

--4
CREATE VIEW vw_clientz AS
SELECT c.name AS client,
     a.account_id AS account_id,
     REPLACE(REPLACE(a.typez, 'S','Savings'), 'C','Checking') AS typez
FROM client c, client_account ca, account a
WHERE c.client_id = ca.client_id AND a.account_id = ca.account_id;


create or replace view "vw_clientz" as
SELECT c.name AS client,
     a.account_id AS account_id,
     REPLACE(REPLACE(a.typez, 'S','Savings'), 'C','Checking') AS typez
FROM client c, client_account ca, account a
WHERE c.client_id = ca.client_id AND a.account_id = ca.account_id;