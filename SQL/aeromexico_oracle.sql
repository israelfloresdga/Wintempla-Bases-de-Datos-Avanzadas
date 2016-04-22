DROP TABLE mexico;

CREATE TABLE mexico
(
	mexico_id NUMBER NOT NULL PRIMARY KEY,
	destination VARCHAR(32) NOT NULL,
	city VARCHAR(32) NULL,
	state_name VARCHAR(32) NOT NULL,
	flight_cost NUMBER(6,2) NULL
);
INSERT INTO mexico(mexico_id, destination, city, state_name) VALUES(10 , 'TeotiHUAcan', 'Mexico', 'EM');
INSERT INTO mexico(mexico_id, destination, city, state_name, flight_cost) VALUES(11 , 'MONTE alban', 'Oaxaca', 'Oax', 872.30);
INSERT INTO mexico(mexico_id, destination, city, state_name, flight_cost) VALUES(12 , 'seven volcanos', 'Valle de Santiago', 'Gto', 1200.52);
INSERT INTO mexico(mexico_id, destination, state_name, flight_cost) VALUES(13 , 'las MOMIAS', 'Gto', 988.00);