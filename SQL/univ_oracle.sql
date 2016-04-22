DROP TABLE student;
DROP TABLE staff;
DROP TABLE department;

CREATE TABLE department
(
    department_id CHAR NOT NULL PRIMARY KEY,
    descr VARCHAR(64) NOT NULL
);
INSERT INTO department(department_id, descr) VALUES('C', 'Computer Engineering');
INSERT INTO department(department_id, descr) VALUES('E', 'Electrical Engineering');
INSERT INTO department(department_id, descr) VALUES('M', 'Mechanical Engineering');
INSERT INTO department(department_id, descr) VALUES('P', 'Principal');

CREATE TABLE student
(
    student_id NUMBER NOT NULL PRIMARY KEY,
    first_name VARCHAR(32) NOT NULL,
    last_name VARCHAR(32) NOT NULL,
    department_id CHAR NOT NULL REFERENCES department(department_id)
);
INSERT INTO student(student_id, first_name, last_name, department_id) VALUES(1, 'Jorge',     'López',     'E');
INSERT INTO student(student_id, first_name, last_name, department_id) VALUES(2, 'Julian',     'Martínez', 'C');
INSERT INTO student(student_id, first_name, last_name, department_id) VALUES(3, 'Rosa',     'Pérez',     'E');
INSERT INTO student(student_id, first_name, last_name, department_id) VALUES(4, 'Noe',         'Razo',     'E');
INSERT INTO student(student_id, first_name, last_name, department_id) VALUES(5, 'Marcela',     'Pinales',     'M');

CREATE TABLE staff
(
    staff_id NUMBER NOT NULL PRIMARY KEY,
    last_name VARCHAR(32) NOT NULL,
    first_name VARCHAR(32) NOT NULL,
    manager_id NUMBER NULL REFERENCES staff(staff_id),
    position VARCHAR(16) NOT NULL,
    department_id CHAR NOT NULL REFERENCES department(department_id),
    salary NUMBER(7,2) NOT NULL
);
INSERT INTO staff(staff_id, last_name, first_name, position, department_id, salary) VALUES(10, 'Smith', 'Henry', 'President', 'P', 8800.00);
INSERT INTO staff(staff_id, last_name, first_name, manager_id, position, department_id, salary) VALUES(11, 'Heffes', 'Louis',     10, 'Dept Head', 'P', 5800.00);
INSERT INTO staff(staff_id, last_name, first_name, manager_id, position, department_id, salary) VALUES(12, 'Hanes', 'Thomas',     10, 'Dept Head', 'E', 4800.00);
INSERT INTO staff(staff_id, last_name, first_name, manager_id, position, department_id, salary) VALUES(13, 'Smith', 'Mary',     10, 'Dept Head', 'C', 5100.00);
INSERT INTO staff(staff_id, last_name, first_name, manager_id, position, department_id, salary) VALUES(14, 'Hee', 'Henry',         11, 'Professor', 'M', 3800.00);
INSERT INTO staff(staff_id, last_name, first_name, manager_id, position, department_id, salary) VALUES(15, 'Aguilar', 'Sergio', 11, 'Professor', 'M', 3900.00);
INSERT INTO staff(staff_id, last_name, first_name, manager_id, position, department_id, salary) VALUES(16, 'Visual', 'Bill',     11, 'Professor', 'M', 2800.00);
INSERT INTO staff(staff_id, last_name, first_name, manager_id, position, department_id, salary) VALUES(17, 'Smith', 'Nancy',     12, 'Professor', 'E', 3899.00);
INSERT INTO staff(staff_id, last_name, first_name, manager_id, position, department_id, salary) VALUES(18, 'López', 'Teresa',     12, 'Professor', 'E', 3553.00);
INSERT INTO staff(staff_id, last_name, first_name, manager_id, position, department_id, salary) VALUES(19, 'Lynch', 'Paul',     13, 'Professor', 'C', 3656.00);
INSERT INTO staff(staff_id, last_name, first_name, manager_id, position, department_id, salary) VALUES(20, 'Ferry', 'Peter',     13, 'Professor', 'C', 3978.00);
INSERT INTO staff(staff_id, last_name, first_name, manager_id, position, department_id, salary) VALUES(21, 'Red', 'Henry',         13, 'Professor', 'C', 5000.00);
INSERT INTO staff(staff_id, last_name, first_name, manager_id, position, department_id, salary) VALUES(22, 'Sky', 'Susan',         13, 'Professor', 'C', 5200.00);
INSERT INTO staff(staff_id, last_name, first_name, manager_id, position, department_id, salary) VALUES(23, 'Smith', 'Jorge',     13, 'Professor', 'C', 4900.00);
INSERT INTO staff(staff_id, last_name, first_name, manager_id, position, department_id, salary) VALUES(24, 'Cate', 'John',         13, 'Professor', 'C', 4100.00);
INSERT INTO staff(staff_id, last_name, first_name, manager_id, position, department_id, salary) VALUES(25, 'Cannon', 'Kate',     11, 'Secretary', 'M', 2200.00);
INSERT INTO staff(staff_id, last_name, first_name, manager_id, position, department_id, salary) VALUES(26, 'Allen', 'Liz',         12, 'Secretary', 'E', 2800.00);
INSERT INTO staff(staff_id, last_name, first_name, manager_id, position, department_id, salary) VALUES(27, 'Blue', 'Jennifer',  13, 'Secretary', 'C', 2500.00);
INSERT INTO staff(staff_id, last_name, first_name, manager_id, position, department_id, salary) VALUES(28, 'Wood', 'Albert',     10, 'Secretary', 'P', 2800.00);