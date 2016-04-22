--circuitcity

DROP TABLE ord_det_copy;

CREATE TABLE ord_det_copy
(
	order_id INTEGER NOT NULL REFERENCES orderx(order_id),
	item_id INTEGER NOT NULL REFERENCES item(item_id),
	item_count INTEGER NOT NULL,
	PRIMARY KEY(order_id, item_id)
);

DELETE FROM ord_det_copy;

INSERT INTO ord_det_copy(order_id,item_id,item_count) 
	SELECT order_id,item_id,item_count FROM ord_det;

SELECT * FROM ord_det_copy;
