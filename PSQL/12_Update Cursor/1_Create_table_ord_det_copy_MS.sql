USE circuit_city_avanzada;
GO

DROP TABLE ord_det_copy;
GO

CREATE TABLE ord_det_copy
(
	order_id INTEGER NOT NULL REFERENCES orderx(order_id),
	item_id INTEGER NOT NULL REFERENCES item(item_id),
	item_count INTEGER NOT NULL,
	PRIMARY KEY(order_id, item_id)
);
GO