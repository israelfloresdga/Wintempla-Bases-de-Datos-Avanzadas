USE master;
GO

IF EXISTS(SELECT * FROM sysdatabases WHERE name='aeromexico')
BEGIN 
	RAISERROR('Dropping existing aeromexico database...', 0, 1)
	DROP DATABASE aeromexico;
END
GO

CREATE DATABASE aeromexico;
GO

USE aeromexico;
GO

IF db_name() <>'aeromexico'
BEGIN 
	RAISERROR('Use database failed...', 22, 127) WITH LOG
	DROP DATABASE aeromexico;
END
GO

CREATE TABLE mexico
(
	mexico_id INT NOT NULL PRIMARY KEY,
	destination NVARCHAR(32) NOT NULL,
	city NVARCHAR(32) NULL,
	state_name NVARCHAR(32) NOT NULL,
	flight_cost MONEY NULL
);
GO
INSERT INTO mexico(mexico_id, destination, city, state_name) VALUES(10 , 'TeotiHUAcan', 'Mexico', 'EM');
INSERT INTO mexico(mexico_id, destination, city, state_name, flight_cost) VALUES(11 , 'MONTE alban', 'Oaxaca', 'Oax', 872.30);
INSERT INTO mexico(mexico_id, destination, city, state_name, flight_cost) VALUES(12 , 'seven volcanos', 'Valle de Santiago', 'Gto', 1200.52);
INSERT INTO mexico(mexico_id, destination, state_name, flight_cost) VALUES(13 , 'las MOMIAS', 'Gto', 988.00);
GO