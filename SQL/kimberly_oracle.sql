DROP TABLE item;
DROP TABLE material;

CREATE TABLE material
(
	material_id CHAR(2) NOT NULL PRIMARY KEY,
	descr VARCHAR(15) NOT NULL,
	cost NUMBER NOT NULL,
	density NUMBER(6,2) NOT NULL
);
INSERT INTO material(material_id, descr, cost, density) VALUES('ME', 'Metal',	9.87, 5.52);
INSERT INTO material(material_id, descr, cost, density) VALUES('PA', 'Paper',	1.50, 0.57);
INSERT INTO material(material_id, descr, cost, density) VALUES('PL', 'Plastic', 2.50, 1.82);
INSERT INTO material(material_id, descr, cost, density) VALUES('WL', 'Wool',	7.50, 0.28);
INSERT INTO material(material_id, descr, cost, density) VALUES('WO', 'Wood',	3.53, 0.79);


CREATE TABLE item
(
	item_id NUMBER NOT NULL PRIMARY KEY,
	name VARCHAR(32) NOT NULL,
	height NUMBER(6,4) NOT NULL,
	width NUMBER(6,4) NOT NULL,
	depth NUMBER(6,4) NOT NULL,
	made_of CHAR(2) NOT NULL REFERENCES material(material_id),
	in_stock NUMBER NOT NULL
);
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