USE circuit_city_avanzada;
GO

DELETE FROM ord_det_copy;

INSERT INTO ord_det_copy(order_id,item_id,item_count) SELECT order_id,item_id,item_count FROM ord_det;

SELECT * FROM ord_det_copy;