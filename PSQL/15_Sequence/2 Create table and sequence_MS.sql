USE Kimberly;

CREATE TABLE picture
(
	picture_id INT NOT NULL IDENTITY CONSTRAINT picture_pk PRIMARY KEY,
	name NVARCHAR(16) NOT NULL
)
GO

INSERT INTO picture(name) VALUES('Mona Lisa');
INSERT INTO picture(name) VALUES('Luz de Cielo');
INSERT INTO picture(name) VALUES('The Invitation');