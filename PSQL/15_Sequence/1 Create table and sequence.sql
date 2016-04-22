connect kimberly;
1234


DROP TABLE picture;
DROP SEQUENCE seq_picture;

CREATE TABLE picture
(
	picture_id NUMBER(5,0) PRIMARY KEY NOT NULL,
	name VARCHAR2(15) NOT NULL	
);

CREATE SEQUENCE seq_picture
START WITH 1000
MAXVALUE 9999;

INSERT INTO picture VALUES(seq_picture.nextval, 'Mona Lisa');
INSERT INTO picture VALUES(seq_picture.nextval, 'Luz de Cielo');
INSERT INTO picture VALUES(seq_picture.nextval, 'The Invitation');


SELECT * FROM picture;
