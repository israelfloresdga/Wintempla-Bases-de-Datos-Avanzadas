USE master;
GO

IF EXISTS(SELECT * FROM sysdatabases WHERE name='circuit_city_avanzada')
BEGIN 
	RAISERROR('Dropping existing circuit_city_avanzada database...', 0, 1)
	DROP DATABASE circuit_city_avanzada;
END
GO

CREATE DATABASE circuit_city_avanzada;
GO

USE circuit_city_avanzada;
GO

IF db_name() <>'circuit_city_avanzada'
BEGIN 
	RAISERROR('Use database failed...', 22, 127) WITH LOG
	DROP DATABASE circuit_city_avanzada;
END
GO

CREATE TABLE client
(
	client_id INT NOT NULL PRIMARY KEY,
	name NVARCHAR(32) NOT NULL,
	company NVARCHAR(32) NOT NULL
);
GO
INSERT INTO client(client_id, name, company) VALUES(5000, 'Smith, Tony', 'Microsoft');
INSERT INTO client(client_id, name, company) VALUES(5001, 'Smith, Julie', 'IBM');
INSERT INTO client(client_id, name, company) VALUES(5002, 'Fry, Kevin', 'IBM');
INSERT INTO client(client_id, name, company) VALUES(5003, 'Flana, Fran', 'Microsoft');
INSERT INTO client(client_id, name, company) VALUES(5004, 'Belleza, Ana', 'Canon');
INSERT INTO client(client_id, name, company) VALUES(5005, 'DiTore, Mike', 'Microsoft');
INSERT INTO client(client_id, name, company) VALUES(5006, 'Ferry, Jim', 'HP');
INSERT INTO client(client_id, name, company) VALUES(5007, 'Lynch, Tim', 'DELL');
INSERT INTO client(client_id, name, company) VALUES(5008, 'Frunch, Ken', 'Pacific Bell');
GO


CREATE TABLE item
(
	item_id INT NOT NULL PRIMARY KEY,
	name NVARCHAR(32) NOT NULL,
	cost MONEY
);
GO
INSERT INTO item(item_id, name, cost) VALUES(100, 'Monitor X8',		200.50);
INSERT INTO item(item_id, name, cost) VALUES(101, 'Monitor X2',		399.50);
INSERT INTO item(item_id, name, cost) VALUES(102, 'Monitor S3',		453.50);
INSERT INTO item(item_id, name, cost) VALUES(103, 'Hard Drive 15G', 80.99);
INSERT INTO item(item_id, name, cost) VALUES(104, 'Hard Drive 80G', 280.00);
INSERT INTO item(item_id, name, cost) VALUES(105, 'Printer U9',		550.50);
INSERT INTO item(item_id, name, cost) VALUES(106, 'CD ROM',			39.50);
INSERT INTO item(item_id, name, cost) VALUES(107, 'CD Burner',		99.78);
INSERT INTO item(item_id, name, cost) VALUES(108, 'RAM 255M',		54.50);
INSERT INTO item(item_id, name, cost) VALUES(109, 'RAM 512M',		80.99);
INSERT INTO item(item_id, name, cost) VALUES(110, 'Keyboard',		20.00);
INSERT INTO item(item_id, name, cost) VALUES(111, 'Mouse',			15.68);
GO


CREATE TABLE credit_client
(
	client_id INT NOT NULL REFERENCES client(client_id) ON DELETE CASCADE, --PRIMARY KEY IDENTITY, --REFERENCES client(client_id) ON DELETE CASCADE,
	credit MONEY NOT NULL
);
GO
INSERT INTO credit_client (client_id, credit) VALUES(5000, 1000.00);
INSERT INTO credit_client (client_id, credit) VALUES(5001, 3000.00);
INSERT INTO credit_client (client_id, credit) VALUES(5002, 400.00);
INSERT INTO credit_client (client_id, credit) VALUES(5003, 500.00);
INSERT INTO credit_client (client_id, credit) VALUES(5004, 7000.00);
INSERT INTO credit_client (client_id, credit) VALUES(5005, 8000.00);
INSERT INTO credit_client (client_id, credit) VALUES(5008, 90.00);	
GO


CREATE TABLE orderx
(
	order_id INT NOT NULL PRIMARY KEY,
	client_id INT NOT NULL REFERENCES client(client_id) ON DELETE CASCADE
);
GO
INSERT INTO orderx (order_id, client_id) VALUES(2000, 5000);
INSERT INTO orderx (order_id, client_id) VALUES(2001, 5008);
INSERT INTO orderx (order_id, client_id) VALUES(2002, 5005);
INSERT INTO orderx (order_id, client_id) VALUES(2003, 5001);
INSERT INTO orderx (order_id, client_id) VALUES(2004, 5008);
INSERT INTO orderx (order_id, client_id) VALUES(2005, 5001);
GO


CREATE TABLE ord_det --LINKING TABLE
(
	order_id INT NOT NULL REFERENCES orderx(order_id) ON DELETE CASCADE, --PRIMARY KEY IDENTITY, --REFERENCES orderx(order_id) ON DELETE CASCADE,
	item_id INT NOT NULL REFERENCES item(item_id) ON DELETE CASCADE,
	item_count INT NOT NULL,
	PRIMARY KEY (order_id, item_id)
);
GO
INSERT INTO ord_det(order_id,item_id,item_count) VALUES(2000 ,100 ,4);
INSERT INTO ord_det(order_id,item_id,item_count) VALUES(2000 ,104 ,5);
INSERT INTO ord_det(order_id,item_id,item_count) VALUES(2001 ,105 ,1);
INSERT INTO ord_det(order_id,item_id,item_count) VALUES(2001 ,106 ,3);
INSERT INTO ord_det(order_id,item_id,item_count) VALUES(2001 ,109 ,2);
INSERT INTO ord_det(order_id,item_id,item_count) VALUES(2002 ,102 ,5);
INSERT INTO ord_det(order_id,item_id,item_count) VALUES(2002 ,103 ,2);
INSERT INTO ord_det(order_id,item_id,item_count) VALUES(2002 ,110 ,4);
INSERT INTO ord_det(order_id,item_id,item_count) VALUES(2002 ,111 ,12);
INSERT INTO ord_det(order_id,item_id,item_count) VALUES(2003 ,107 ,5);
INSERT INTO ord_det(order_id,item_id,item_count) VALUES(2004 ,103 ,2);
INSERT INTO ord_det(order_id,item_id,item_count) VALUES(2004 ,104 ,2);
INSERT INTO ord_det(order_id,item_id,item_count) VALUES(2005 ,102 ,2);
GO