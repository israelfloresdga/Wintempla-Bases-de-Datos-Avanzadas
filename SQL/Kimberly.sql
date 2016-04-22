USE master;
GO

IF EXISTS(SELECT * FROM sysdatabases WHERE name='Kimberly')
BEGIN 
	RAISERROR('Dropping existing Kimberly database...', 0, 1)
	DROP DATABASE Kimberly;
END
GO

CREATE DATABASE Kimberly;
GO

USE Kimberly;
GO

IF db_name() <>'Kimberly'
BEGIN 
	RAISERROR('Use database failed...', 22, 127) WITH LOG
	DROP DATABASE Kimberly;
END
GO

CREATE TABLE material
(
	material_id CHAR(2) NOT NULL PRIMARY KEY,
	descr NVARCHAR(15) NOT NULL,
	cost MONEY NOT NULL,
	density DECIMAL(6,2) NOT NULL
);
GO
INSERT INTO material(material_id, descr, cost, density) VALUES('ME', 'Metal',	9.87, 5.52);
INSERT INTO material(material_id, descr, cost, density) VALUES('PA', 'Paper',	1.50, 0.57);
INSERT INTO material(material_id, descr, cost, density) VALUES('PL', 'Plastic', 2.50, 1.82);
INSERT INTO material(material_id, descr, cost, density) VALUES('WL', 'Wool',	7.50, 0.28);
INSERT INTO material(material_id, descr, cost, density) VALUES('WO', 'Wood',	3.53, 0.79);
GO

CREATE TABLE item
(
	item_id INT NOT NULL PRIMARY KEY,
	name NVARCHAR(32) NOT NULL,
	height DECIMAL(6,4) NOT NULL,
	width DECIMAL(6,4) NOT NULL,
	depth DECIMAL(6,4) NOT NULL,
	made_of CHAR(2) NOT NULL REFERENCES material(material_id),
	in_stock INT NOT NULL
);
GO
INSERT INTO item(item_id, name, height, width, depth, made_of, in_stock) VALUES (13, 'Bed',		1, 12, 9, 'WL', 121);
INSERT INTO item(item_id, name, height, width, depth, made_of, in_stock) VALUES (10, 'Book',	3, 2, 0.5, 'PA', 50);
INSERT INTO item(item_id, name, height, width, depth, made_of, in_stock) VALUES (16, 'CD',		5, 6, 0.5, 'PL', 58);
INSERT INTO item(item_id, name, height, width, depth, made_of, in_stock) VALUES (12, 'Chair',	8, 4, 4, 'WO', 77);
INSERT INTO item(item_id, name, height, width, depth, made_of, in_stock) VALUES (15, 'Computer', 2, 1, 11, 'ME', 553);
INSERT INTO item(item_id, name, height, width, depth, made_of, in_stock) VALUES (18, 'Picture', 10, 12, 0.1, 'PA', 92);
INSERT INTO item(item_id, name, height, width, depth, made_of, in_stock) VALUES (17, 'Printer', 2.2, 1.6, 1.4, 'PL', 5);
INSERT INTO item(item_id, name, height, width, depth, made_of, in_stock) VALUES (19, 'Speaker', 2, 1.5, 4.7, 'WO', 145);
INSERT INTO item(item_id, name, height, width, depth, made_of, in_stock) VALUES (14, 'Table', 12, 3, 4, 'WO', 12);
INSERT INTO item(item_id, name, height, width, depth, made_of, in_stock) VALUES (11, 'TV', 2, 7, 5, 'PL', 100);
GO