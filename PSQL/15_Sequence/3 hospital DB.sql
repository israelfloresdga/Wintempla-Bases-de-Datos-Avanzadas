USE master;
GO

IF EXISTS(SELECT * FROM sysdatabases WHERE name='hospital')
BEGIN 
	RAISERROR('Dropping existing hospital database...', 0, 1)
	DROP DATABASE hospital;
END
GO

CREATE DATABASE hospital;
GO

USE hospital;
GO

IF db_name() <>'hospital'
BEGIN 
	RAISERROR('Use database failed...', 22, 127) WITH LOG
	DROP DATABASE hospital;
END
GO

CREATE TABLE patient
(
	patient_id INT NOT NULL IDENTITY PRIMARY KEY,
	name NVARCHAR(32) NOT NULL UNIQUE,
	age INT NOT NULL
);
GO
INSERT INTO patient(name, age) VALUES('Henry June', 20);
INSERT INTO patient(name, age) VALUES('Mary Johnson', 54);
GO

CREATE TABLE patient_visit
(
	visit_id INT NOT NULL IDENTITY PRIMARY KEY,
	patient_id INT NOT NULL	REFERENCES patient(patient_id) ON DELETE CASCADE,
	visit_date SMALLDATETIME NOT NULL DEFAULT GETDATE()
);
GO

CREATE PROCEDURE p_insert_patient_visit
	@in_patient_id INT,
	@out_patient_visit_id INT OUTPUT
AS
	INSERT INTO patient_visit(patient_id) VALUES(@in_patient_id);
	SET @out_patient_visit_id = SCOPE_IDENTITY();
	RETURN 0;
GO