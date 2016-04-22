SELECT temperature_id,
	value,
	to_celsius(value) AS celsius
FROM temperature;