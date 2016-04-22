USE master;
GO

IF EXISTS(SELECT * FROM sysdatabases WHERE name='dental')
BEGIN
	RAISERROR('Dropping existing dental database...',0,1)
	DROP DATABASE dental;
END
GO

CREATE DATABASE dental
GO

USE dental
GO

IF db_name()<>'dental'
BEGIN
	RAISERROR('Use database failed...',22,127) WITH LOG
	DROP DATABASE dental;
END
GO

CREATE TABLE userz 
(     
	userz_id INT IDENTITY NOT NULL PRIMARY KEY,
	username NVARCHAR(16) UNIQUE NOT NULL,     
	first_name NVARCHAR(32) NOT NULL,
	last_name NVARCHAR(32) NOT NULL,     
	--passwordz NVARCHAR(16) NOT NULL CONSTRAINT userz_passwordz_ck 
		--CHECK (passwordz LIKE '___%'),     
	passwordz NVARCHAR(16) NOT NULL,
    email NVARCHAR(32) NOT NULL CONSTRAINT userz_email_ck 
    	CHECK (email LIKE '%@%'),
    is_active BIT NOT NULL,
    has_access_patient_info BIT NOT NULL, --Table: patient
    has_access_users BIT NOT NULL, --Table: userz
    has_access_payments BIT NOT NULL, --Table: transactionz with transaction_type = Paymeny, Discount or Consolidation
    has_access_patient_chart BIT NOT NULL, --Table: transactionz with trnsation_type = Dental procedure
    has_access_dental_procedure_setup BIT NOT NULL --Table: dental_procedure
);
GO
INSERT INTO userz(username, first_name, last_name, passwordz, email, is_active, has_access_patient_info, has_access_users, has_access_payments, has_access_patient_chart, has_access_dental_procedure_setup) VALUES('tommy', 'Tom', 'Martínez', 'abc', 'tommy@live.com', 1, 1, 1, 1, 1, 1);
INSERT INTO userz(username, first_name, last_name, passwordz, email, is_active, has_access_patient_info, has_access_users, has_access_payments, has_access_patient_chart, has_access_dental_procedure_setup) VALUES('july', 'Julia', 'Williams', 'hola', 'julia@yahoo.com', 1, 1, 1, 1, 0, 0);
INSERT INTO userz(username, first_name, last_name, passwordz, email, is_active, has_access_patient_info, has_access_users, has_access_payments, has_access_patient_chart, has_access_dental_procedure_setup) VALUES('marco', 'Mark', 'Perez', '123', 'mark91@hotmail.com', 1, 1, 0, 1, 0, 0);

CREATE TABLE tooth
(
	tooth_id INT NOT NULL CONSTRAINT tooth_pk PRIMARY KEY IDENTITY,
	tooth_code NVARCHAR(2) UNIQUE NOT NULL,
	position SMALLINT NOT NULL,
	is_adult_tooth BIT NOT NULL,
	is_top_tooth BIT NOT NULL,
	descr NVARCHAR(32) NOT NULL,
	is_molar BIT NOT NULL
);
GO
--This tooth is used for transaction without teeth
INSERT INTO tooth(tooth_code, position, is_adult_tooth, is_top_tooth, descr, is_molar) VALUES('0', 0, 0, 0, 'No tooth', 0);
INSERT INTO tooth(tooth_code, position, is_adult_tooth, is_top_tooth, descr, is_molar) VALUES('1', 1, 1, 1, '3rd molar (wisdom tooth)', 1);
INSERT INTO tooth(tooth_code, position, is_adult_tooth, is_top_tooth, descr, is_molar) VALUES('2', 2, 1, 1, '2nd molar (12-yr molar)', 1);
INSERT INTO tooth(tooth_code, position, is_adult_tooth, is_top_tooth, descr, is_molar) VALUES('3', 3, 1, 1, '1st molar (6-yr molar)', 1);
INSERT INTO tooth(tooth_code, position, is_adult_tooth, is_top_tooth, descr, is_molar) VALUES('4', 4, 1, 1, '2nd bicuspid (2nd premolar)', 1);
INSERT INTO tooth(tooth_code, position, is_adult_tooth, is_top_tooth, descr, is_molar) VALUES('5', 5, 1, 1, '1st bicuspid (1st premolar)', 1);
INSERT INTO tooth(tooth_code, position, is_adult_tooth, is_top_tooth, descr, is_molar) VALUES('6', 6, 1, 1, 'Cuspid (canine/eye tooth)', 0);
INSERT INTO tooth(tooth_code, position, is_adult_tooth, is_top_tooth, descr, is_molar) VALUES('7', 7, 1, 1, 'lateral incisor', 0);
INSERT INTO tooth(tooth_code, position, is_adult_tooth, is_top_tooth, descr, is_molar) VALUES('8', 8, 1, 1, 'central incisor', 0);
INSERT INTO tooth(tooth_code, position, is_adult_tooth, is_top_tooth, descr, is_molar) VALUES('9', 9, 1, 1, 'central incisor', 0);
INSERT INTO tooth(tooth_code, position, is_adult_tooth, is_top_tooth, descr, is_molar) VALUES('10', 10, 1, 1, 'lateral incisor', 0);
INSERT INTO tooth(tooth_code, position, is_adult_tooth, is_top_tooth, descr, is_molar) VALUES('11', 11, 1, 1, 'Cuspid (canine/eye tooth)', 0);
INSERT INTO tooth(tooth_code, position, is_adult_tooth, is_top_tooth, descr, is_molar) VALUES('12', 12, 1, 1, '1st bicuspid (1st premolar)', 1);
INSERT INTO tooth(tooth_code, position, is_adult_tooth, is_top_tooth, descr, is_molar) VALUES('13', 13, 1, 1, '2nd bicuspid (2nd premolar)', 1);
INSERT INTO tooth(tooth_code, position, is_adult_tooth, is_top_tooth, descr, is_molar) VALUES('14', 14, 1, 1, '1st molar (6-yr molar)', 1);
INSERT INTO tooth(tooth_code, position, is_adult_tooth, is_top_tooth, descr, is_molar) VALUES('15', 15, 1, 1, '2nd molar (12-yr molar)', 1);
INSERT INTO tooth(tooth_code, position, is_adult_tooth, is_top_tooth, descr, is_molar) VALUES('16', 16, 1, 1, '3rd molar (wisdom tooth)', 1);
GO
INSERT INTO tooth(tooth_code, position, is_adult_tooth, is_top_tooth, descr, is_molar) VALUES('17', 17, 1, 0, '3rd molar (wisdom tooth)', 1);
INSERT INTO tooth(tooth_code, position, is_adult_tooth, is_top_tooth, descr, is_molar) VALUES('18', 18, 1, 0, '2nd molar (12-yr molar)', 1);
INSERT INTO tooth(tooth_code, position, is_adult_tooth, is_top_tooth, descr, is_molar) VALUES('19', 19, 1, 0, '1st molar (6-yr molar)', 1);
INSERT INTO tooth(tooth_code, position, is_adult_tooth, is_top_tooth, descr, is_molar) VALUES('20', 20, 1, 0, '2nd bicuspid (2nd premolar)', 1);
INSERT INTO tooth(tooth_code, position, is_adult_tooth, is_top_tooth, descr, is_molar) VALUES('21', 21, 1, 0, '1st bicuspid (1st premolar)', 1);
INSERT INTO tooth(tooth_code, position, is_adult_tooth, is_top_tooth, descr, is_molar) VALUES('22', 22, 1, 0, 'Cuspid (canine/eye tooth)', 0);
INSERT INTO tooth(tooth_code, position, is_adult_tooth, is_top_tooth, descr, is_molar) VALUES('23', 23, 1, 0, 'lateral incisor', 0);
INSERT INTO tooth(tooth_code, position, is_adult_tooth, is_top_tooth, descr, is_molar) VALUES('24', 24, 1, 0, 'central incisor', 0);
INSERT INTO tooth(tooth_code, position, is_adult_tooth, is_top_tooth, descr, is_molar) VALUES('25', 25, 1, 0, 'central incisor', 0);
INSERT INTO tooth(tooth_code, position, is_adult_tooth, is_top_tooth, descr, is_molar) VALUES('26', 26, 1, 0, 'lateral incisor', 0);
INSERT INTO tooth(tooth_code, position, is_adult_tooth, is_top_tooth, descr, is_molar) VALUES('27', 27, 1, 0, 'Cuspid (canine/eye tooth)', 0);
INSERT INTO tooth(tooth_code, position, is_adult_tooth, is_top_tooth, descr, is_molar) VALUES('28', 28, 1, 0, '1st bicuspid (1st premolar)', 1);
INSERT INTO tooth(tooth_code, position, is_adult_tooth, is_top_tooth, descr, is_molar) VALUES('29', 29, 1, 0, '2nd bicuspid (2nd premolar)', 1);
INSERT INTO tooth(tooth_code, position, is_adult_tooth, is_top_tooth, descr, is_molar) VALUES('30', 30, 1, 0, '1st molar (6-yr molar)', 1);
INSERT INTO tooth(tooth_code, position, is_adult_tooth, is_top_tooth, descr, is_molar) VALUES('31', 31, 1, 0, '2nd molar (12-yr molar)', 1);
INSERT INTO tooth(tooth_code, position, is_adult_tooth, is_top_tooth, descr, is_molar) VALUES('32', 32, 1, 0, '3rd molar (wisdom tooth)', 1);
GO
INSERT INTO tooth(tooth_code, position, is_adult_tooth, is_top_tooth, descr, is_molar) VALUES('A', 4, 0, 1, 'Second molar', 1);
INSERT INTO tooth(tooth_code, position, is_adult_tooth, is_top_tooth, descr, is_molar) VALUES('B', 5, 0, 1, 'First molar', 1);
INSERT INTO tooth(tooth_code, position, is_adult_tooth, is_top_tooth, descr, is_molar) VALUES('C', 6, 0, 1, 'Canine (cuspid)', 0);
INSERT INTO tooth(tooth_code, position, is_adult_tooth, is_top_tooth, descr, is_molar) VALUES('D', 7, 0, 1, 'Lateral incisor', 0);
INSERT INTO tooth(tooth_code, position, is_adult_tooth, is_top_tooth, descr, is_molar) VALUES('E', 8, 0, 1, 'Central incisor', 0);
INSERT INTO tooth(tooth_code, position, is_adult_tooth, is_top_tooth, descr, is_molar) VALUES('F', 9, 0, 1, 'Central incisor', 0);
INSERT INTO tooth(tooth_code, position, is_adult_tooth, is_top_tooth, descr, is_molar) VALUES('G', 10, 0, 1, 'Lateral incisor', 0);
INSERT INTO tooth(tooth_code, position, is_adult_tooth, is_top_tooth, descr, is_molar) VALUES('H', 11, 0, 1, 'Canine (cuspid)', 0);
INSERT INTO tooth(tooth_code, position, is_adult_tooth, is_top_tooth, descr, is_molar) VALUES('I', 12, 0, 1, 'First molar', 1);
INSERT INTO tooth(tooth_code, position, is_adult_tooth, is_top_tooth, descr, is_molar) VALUES('J', 13, 0, 1, 'Second molar', 1);
GO
INSERT INTO tooth(tooth_code, position, is_adult_tooth, is_top_tooth, descr, is_molar) VALUES('K', 20, 0, 0, 'Second molar', 1);
INSERT INTO tooth(tooth_code, position, is_adult_tooth, is_top_tooth, descr, is_molar) VALUES('L', 21, 0, 0, 'First molar', 1);
INSERT INTO tooth(tooth_code, position, is_adult_tooth, is_top_tooth, descr, is_molar) VALUES('M', 22, 0, 0, 'Canine (cuspid)', 0);
INSERT INTO tooth(tooth_code, position, is_adult_tooth, is_top_tooth, descr, is_molar) VALUES('N', 23, 0, 0, 'Lateral incisor', 0);
INSERT INTO tooth(tooth_code, position, is_adult_tooth, is_top_tooth, descr, is_molar) VALUES('O', 24, 0, 0, 'Central incisor', 0);
INSERT INTO tooth(tooth_code, position, is_adult_tooth, is_top_tooth, descr, is_molar) VALUES('P', 25, 0, 0, 'Central incisor', 0);
INSERT INTO tooth(tooth_code, position, is_adult_tooth, is_top_tooth, descr, is_molar) VALUES('Q', 26, 0, 0, 'Lateral incisor', 0);
INSERT INTO tooth(tooth_code, position, is_adult_tooth, is_top_tooth, descr, is_molar) VALUES('R', 27, 0, 0, 'Canine (cuspid)', 0);
INSERT INTO tooth(tooth_code, position, is_adult_tooth, is_top_tooth, descr, is_molar) VALUES('S', 28, 0, 0, 'First molar', 1);
INSERT INTO tooth(tooth_code, position, is_adult_tooth, is_top_tooth, descr, is_molar) VALUES('T', 29, 0, 0, 'Second molar', 1);
GO

CREATE TABLE patient
(
	patient_id INT NOT NULL PRIMARY KEY IDENTITY,
	first_name NVARCHAR(32) NOT NULL,
	last_name NVARCHAR(32) NOT NULL,
	birth_date DATE NOT NULL,
	email NVARCHAR(64) NOT NULL CONSTRAINT patient_email_ck
		CHECK (email LIKE '%@%')
);
GO
INSERT INTO patient(first_name, last_name, birth_date, email) VALUES('Rafael', 'Smith', '1990-04-28', 'rafa@gmail.com');
INSERT INTO patient(first_name, last_name, birth_date, email) VALUES('Jose', 'Macias', '1987-02-22', 'jose@gmail.com');
INSERT INTO patient(first_name, last_name, birth_date, email) VALUES('Mary', 'Thompson', '1965-9-9', 'mary2000@outlook.com');
GO

CREATE TABLE dental_procedure
(
	dental_procedure_id INT NOT NULL PRIMARY KEY IDENTITY,
	descr NVARCHAR(32) NOT NULL,
	estimated_cost MONEY NOT NULL,
	--____________Root
	root_line_color_red INT NOT NULL,
	root_line_color_green INT NOT NULL,
	root_line_color_blue INT NOT NULL,
	--
	root_fill_color_red INT NOT NULL,
	root_fill_color_green INT NOT NULL,
	root_fill_color_blue INT NOT NULL,
	--____________Body
	body_line_color_red INT NOT NULL,
	body_line_color_green INT NOT NULL,
	body_line_color_blue INT NOT NULL,
	--
	body_fill_color_red INT NOT NULL,
	body_fill_color_green INT NOT NULL,
	body_fill_color_blue INT NOT NULL
);
GO
--This procedure is used for: Payment, Discount and Consolidation
INSERT INTO dental_procedure(descr, estimated_cost, 
	root_line_color_red, root_line_color_green, root_line_color_blue,
	root_fill_color_red, root_fill_color_green, root_fill_color_blue,
	body_line_color_red, body_line_color_green, body_line_color_blue,
	body_fill_color_red, body_fill_color_green, body_fill_color_blue) 
VALUES('None', 0.0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
INSERT INTO dental_procedure(descr, estimated_cost, 
	root_line_color_red, root_line_color_green, root_line_color_blue,
	root_fill_color_red, root_fill_color_green, root_fill_color_blue,
	body_line_color_red, body_line_color_green, body_line_color_blue,
	body_fill_color_red, body_fill_color_green, body_fill_color_blue) 
VALUES('Extraction', 90.0, 255, 0, 0, 255, 180, 180, 255, 0, 0, 255, 180, 180);
INSERT INTO dental_procedure(descr, estimated_cost, 
	root_line_color_red, root_line_color_green, root_line_color_blue,
	root_fill_color_red, root_fill_color_green, root_fill_color_blue,
	body_line_color_red, body_line_color_green, body_line_color_blue,
	body_fill_color_red, body_fill_color_green, body_fill_color_blue) 
VALUES('Endodoncy', 556.20, 0, 180, 0, 180, 255, 180, 0, 0, 255, 180, 180, 255);
INSERT INTO dental_procedure(descr, estimated_cost, 
	root_line_color_red, root_line_color_green, root_line_color_blue,
	root_fill_color_red, root_fill_color_green, root_fill_color_blue,
	body_line_color_red, body_line_color_green, body_line_color_blue,
	body_fill_color_red, body_fill_color_green, body_fill_color_blue) 
VALUES('Filling', 89.50, 180, 180, 0, 255, 255, 180, 255, 180, 255, 255, 180, 255);
GO

CREATE TABLE transaction_type
(
	transaction_type_id INT NOT NULL PRIMARY KEY IDENTITY,
	descr NVARCHAR(32) NOT NULL
);
GO
INSERT INTO transaction_type(descr) VALUES('Dental Procedure');
INSERT INTO transaction_type(descr) VALUES('Payment');
GO

CREATE TABLE transactionz
(
	transactionz_id INT NOT NULL PRIMARY KEY IDENTITY,
	transaction_type_id INT NOT NULL REFERENCES transaction_type(transaction_type_id),
	transaction_date DATE NOT NULL DEFAULT GETDATE(),
	patient_id INT NOT NULL REFERENCES patient(patient_id),
	dental_procedure_id INT NOT NULL REFERENCES dental_procedure(dental_procedure_id),
	tooth_id INT NOT NULL REFERENCES tooth(tooth_id),
	amount MONEY NOT NULL, 
	userz_id INT NOT NULL REFERENCES userz(userz_id),
	comment NVARCHAR(100) NULL
);
GO
--Dental Procedure
INSERT INTO transactionz(transaction_type_id, patient_id, dental_procedure_id, tooth_id, amount, userz_id) VALUES(1, 1, 2, 32, 100.0, 1);
--Payment
INSERT INTO transactionz(transaction_type_id, patient_id, dental_procedure_id, tooth_id, amount, userz_id) VALUES(2, 1, 1, 1, 40.0, 2);
--Payment
INSERT INTO transactionz(transaction_type_id, patient_id, dental_procedure_id, tooth_id, amount, userz_id) VALUES(2, 1, 1, 1, 60.0, 3);
--Dental Procedure
INSERT INTO transactionz(transaction_type_id, patient_id, dental_procedure_id, tooth_id, amount, userz_id) VALUES(1, 2, 2, 6, 500.0, 1);
--Dental Procedure
INSERT INTO transactionz(transaction_type_id, patient_id, dental_procedure_id, tooth_id, amount, userz_id) VALUES(1, 2, 3, 7, 411.0, 1);
GO

CREATE FUNCTION f_to_yesno
(
	@input BIT
)
RETURNS NVARCHAR(4)
AS
BEGIN
	DECLARE @result AS NVARCHAR(4);
	IF(@input=1)
		SET @result= 'yes';
	ELSE 
		SET @result= 'no';
	RETURN (@result);
END
GO

CREATE FUNCTION f_to_access
(
	@input BIT
)
RETURNS NVARCHAR(8)
AS
BEGIN
	DECLARE @result AS NVARCHAR(8);
	IF (@input=1)
		SET @result= 'access';
	ELSE
		SET @result= 'deny';
	RETURN (@result);
END
GO

CREATE VIEW vw_dental_procedure
AS
SELECT dental_procedure_id, 
	descr, 
	estimated_cost, 
	'('+CAST(body_line_color_red AS NVARCHAR)+', '+CAST(body_line_color_green AS NVARCHAR)+', '+CAST(body_line_color_blue AS NVARCHAR)+')' AS body_line_color,
	'('+CAST(body_fill_color_red AS NVARCHAR)+', '+CAST(body_fill_color_green AS NVARCHAR)+', '+CAST(body_fill_color_blue AS NVARCHAR)+')' AS body_fill_color,
	'('+CAST(root_line_color_red AS NVARCHAR)+', '+CAST(root_line_color_green AS NVARCHAR)+', '+CAST(root_line_color_blue AS NVARCHAR)+')' AS root_line_color,
	'('+CAST(root_fill_color_red AS NVARCHAR)+', '+CAST(root_fill_color_green AS NVARCHAR)+', '+CAST(root_fill_color_blue AS NVARCHAR)+')' AS root_fill_color
FROM dental_procedure;
GO

CREATE VIEW vw_transaction
AS
SELECT t.transactionz_id AS transaction_id,
	tt.transaction_type_id AS transaction_type_id,
	dp.dental_procedure_id AS dental_procedure_id,
	tt.descr AS transaction_type,
	t.transaction_date,
	p.patient_id AS patient_id,
	p.last_name+', '+p.first_name AS patient_name,
	dp.descr AS dental_procedure,
	t.tooth_id AS tooth_id,
	th.tooth_code AS tooth_code,
	t.amount AS amount,
	t.userz_id AS user_id,
	u.username AS username,
	t.comment AS comment,
	--
	dp.root_line_color_red AS root_line_color_red,
	dp.root_line_color_green AS root_line_color_green,
	dp.root_line_color_blue AS root_line_color_blue,
	dp.root_fill_color_red AS root_fill_color_red,
	dp.root_fill_color_green AS root_fill_color_green,
	dp.root_fill_color_blue AS root_fill_color_blue,
	--
	dp.body_line_color_red AS body_line_color_red,
	dp.body_line_color_green AS body_line_color_green,
	dp.body_line_color_blue AS body_line_color_blue,
	dp.body_fill_color_red AS body_fill_color_red,
	dp.body_fill_color_green AS body_fill_color_green,
	dp.body_fill_color_blue AS body_fill_color_blue
FROM transactionz t,
	transaction_type tt,
	userz u,
	patient p,
	dental_procedure dp,
	tooth th
WHERE t.transaction_type_id= tt.transaction_type_id AND
	t.userz_id= u.userz_id AND
	t.patient_id= p.patient_id AND
	t.dental_procedure_id= dp.dental_procedure_id AND
	t.tooth_id= th.tooth_id;
GO