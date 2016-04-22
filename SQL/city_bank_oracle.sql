drop TABLE friend;
drop TABLE client_account;
drop TABLE account;
drop TABLE branch;
drop TABLE client;

--~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
CREATE TABLE client
(
    client_id NUMBER NOT NULL PRIMARY KEY,
    name VARCHAR(32) NOT NULL,
    addressz VARCHAR(32) NOT NULL,
    typez CHAR(1) NOT NULL
);
--GO
--SET IDENTITY_INSERT client ON;
INSERT INTO client(client_id, name, addressz, typez) VALUES(2345, 'Sigal, Tobias',    '56 Clayton Road',        'B');
INSERT INTO client(client_id, name, addressz, typez) VALUES(2346, 'Vega, Adam',        '275 Evergreen Road',    'F');
INSERT INTO client(client_id, name, addressz, typez) VALUES(2347, 'Nayer, Julia',    '56 Diablo Blvd',        'B');
INSERT INTO client(client_id, name, addressz, typez) VALUES(7654, 'Colmena, Karen', '4323 Oak Road',        'F');
INSERT INTO client(client_id, name, addressz, typez) VALUES(7655, 'Volman, Shanta', '4323 Sky Road',        'F');
INSERT INTO client(client_id, name, addressz, typez) VALUES(8764, 'Weiss, Matthew', 'AV Trabajo 5',            'B');
INSERT INTO client(client_id, name, addressz, typez) VALUES(8765, 'Mourgos, Kevin', 'Hidalgo 74',            'B');
--GO
--SET IDENTITY_INSERT client OFF;


CREATE TABLE branch
(
    branch_id NUMBER NOT NULL PRIMARY KEY,
    name VARCHAR(32) NOT NULL,
    addressz VARCHAR(32) NOT NULL,
    manager_id NUMBER NOT NULL
);
--GO
INSERT INTO branch(branch_id, name, addressz, manager_id) VALUES(100, 'Centro',        '45 Main St',    9823);
INSERT INTO branch(branch_id, name, addressz, manager_id) VALUES(101, 'Bellavista', '23 Treat Blvd', 1768);
--GO


CREATE TABLE account
(
    account_id NUMBER NOT NULL PRIMARY KEY,
    balance    NUMBER NOT NULL,
    typez CHAR(1) NOT NULL,
    branch_id NUMBER NOT NULL REFERENCES branch(branch_id)
);
--GO
INSERT INTO account(account_id, balance, typez, branch_id) VALUES(120768, 234.56,    'S', 100);
INSERT INTO account(account_id, balance, typez, branch_id) VALUES(348973, 12756.56,    'C', 100);
INSERT INTO account(account_id, balance, typez, branch_id) VALUES(348974, -1756.56,    'S', 100);
INSERT INTO account(account_id, balance, typez, branch_id) VALUES(678453, -456.78,    'C', 100);
INSERT INTO account(account_id, balance, typez, branch_id) VALUES(678454, 2456.78,    'C', 100);
INSERT INTO account(account_id, balance, typez, branch_id) VALUES(745363, 1223.67,    'S', 101);
INSERT INTO account(account_id, balance, typez, branch_id) VALUES(745368, 323.97,    'S', 101);
INSERT INTO account(account_id, balance, typez, branch_id) VALUES(987654, 89.65,    'S', 101);
INSERT INTO account(account_id, balance, typez, branch_id) VALUES(987692, 2789.65,    'S', 101);
--GO

CREATE TABLE client_account
(
    client_id NUMBER NOT NULL REFERENCES client(client_id),
    account_id NUMBER NOT NULL REFERENCES account(account_id),
    PRIMARY KEY(client_id, account_id)
);
--GO
INSERT INTO client_account(client_id,account_id) VALUES(2345,120768);
INSERT INTO client_account(client_id,account_id) VALUES(2345,348973);
INSERT INTO client_account(client_id,account_id) VALUES(2346,348974);
INSERT INTO client_account(client_id,account_id) VALUES(2347,987692);
INSERT INTO client_account(client_id,account_id) VALUES(7654,987654);
INSERT INTO client_account(client_id,account_id) VALUES(7655,678454);
INSERT INTO client_account(client_id,account_id) VALUES(8764,348973);
INSERT INTO client_account(client_id,account_id) VALUES(8764,678453);
INSERT INTO client_account(client_id,account_id) VALUES(8764,745363);
INSERT INTO client_account(client_id,account_id) VALUES(8765,745368);
--GO


CREATE TABLE friend
(
    friend_id NUMBER NOT NULL PRIMARY KEY,
    name VARCHAR(32) NOT NULL,
    addressz VARCHAR(32) NOT NULL,
    birth_date DATE NULL,
    ssn VARCHAR(11) NOT NULL
);
--GO
INSERT INTO friend(friend_id,name,addressz,birth_date,ssn) VALUES(3211, 'Robert, Joseph',    '22 Daiblo Blvd',    '',                '234-45-5688');
INSERT INTO friend(friend_id,name,addressz,birth_date,ssn) VALUES(3432, 'Ledesma, Roberto',    '453 Main St',        to_date('1960-03-05','yyyy-mm-dd'),    '255-45-5688');
INSERT INTO friend(friend_id,name,addressz,birth_date,ssn) VALUES(5234, 'Mark, Nancy',        '232 Concord Road',    '',                '234-77-5688');
INSERT INTO friend(friend_id,name,addressz,birth_date,ssn) VALUES(5634, 'Kenny, Tom',        '123 Oak Road',        to_date('1972-01-12','yyyy-mm-dd'),    '134-65-9288');
--GO