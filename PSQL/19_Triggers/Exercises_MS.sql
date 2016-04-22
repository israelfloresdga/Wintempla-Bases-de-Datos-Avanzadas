USE circuit_city_avanzada;
GO

--1
DROP TABLE audit_ord_det;

CREATE TABLE audit_ord_det
(
	audit_ord_det_id INT NOT NULL IDENTITY CONSTRAINT [audit_ord_det_id] PRIMARY KEY,
	order_id INT NOT NULL REFERENCES orderx(order_id),
	actionz NVARCHAR(8) NOT NULL CHECK(actionz= 'DELETE' OR actionz= 'UPDATE' OR actionz= 'INSERT'),
	time_date DATE NOT NULL
);
GO