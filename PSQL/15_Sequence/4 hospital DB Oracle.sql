CONNECT hospital;
1234;


DROP TABLE patient_visit;
DROP TABLE patient;
DROP SEQUENCE seq_patient;
DROP SEQUENCE seq_visit;

CREATE TABLE patient
(
    patient_id INTEGER NOT NULL PRIMARY KEY,
    name VARCHAR2(32) NOT NULL UNIQUE,
    age INTEGER NOT NULL
);

CREATE SEQUENCE seq_patient
START WITH 1000
INCREMENT BY 1;

INSERT INTO patient(patient_id, name, age) VALUES(seq_patient.nextval, 'Henry June', 20);
INSERT INTO patient(patient_id, name, age) VALUES(seq_patient.nextval, 'Mary Johnson', 54);

CREATE TABLE patient_visit
(
    visit_id INTEGER NOT NULL PRIMARY KEY,
    patient_id INTEGER NOT NULL REFERENCES patient(patient_id) ON DELETE CASCADE,
    visit_date DATE DEFAULT SYSDATE NOT NULL
);


CREATE SEQUENCE seq_visit
START WITH 1000
INCREMENT BY 1;


CREATE OR REPLACE PROCEDURE p_insert_patient_visit
(
    in_patient_id IN INTEGER,
    out_patient_visit_id OUT INTEGER
)
IS
    --p_date DATE;
BEGIN
    --p_date:= CURRENT_DATE(); --Otro método
    INSERT INTO patient_visit VALUES(seq_visit.nextval, in_patient_id, SYSDATE);
    
    --SELECT seq_visit.nextval from dual;
    SELECT seq_visit.currval INTO out_patient_visit_id from dual;

    --SET out_patient_visit_id = seq_visit.currval;
END p_insert_patient_visit;
/
