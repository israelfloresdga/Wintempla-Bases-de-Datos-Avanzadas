connect circuitcity;
1234

--1
DROP TABLE audit_ord_det;

CREATE TABLE audit_ord_det
(
	audit_ord_det_id INTEGER NOT NULL PRIMARY KEY,
	order_id INTEGER NOT NULL REFERENCES orderx(order_id),
	action VARCHAR2(12) NOT NULL CHECK(action= 'DELETE' OR action= 'UPDATE' OR action= 'INSERT'),
	time_date DATE NOT NULL
);

CREATE SEQUENCE seq_audit_ord_det START WITH 1 INCREMENT BY 1;



--2
CREATE OR REPLACE TRIGGER trigger_insert_ord_det
AFTER INSERT
ON ord_det
FOR EACH ROW
BEGIN
	INSERT INTO audit_ord_det VALUES(seq_audit_ord_det.nextval, :new.order_id, 'INSERT', CURRENT_DATE);
END trigger_insert_ord_det;
/

CREATE OR REPLACE TRIGGER trigger_update_ord_det
AFTER UPDATE
ON ord_det
FOR EACH ROW
BEGIN
	INSERT INTO audit_ord_det VALUES(seq_audit_ord_det.nextval, :old.order_id, 'UPDATE', CURRENT_DATE);
END trigger_update_ord_det;
/

CREATE OR REPLACE TRIGGER trigger_delete_ord_det
AFTER DELETE
ON ord_det
FOR EACH ROW
BEGIN
	INSERT INTO audit_ord_det VALUES(seq_audit_ord_det.nextval, :old.order_id, 'DELETE', CURRENT_DATE);
END trigger_delete_ord_det;
/