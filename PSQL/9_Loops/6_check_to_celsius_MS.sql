USE Kimberly;
GO

SELECT temperature_id,
	value AS farenheit,
	dbo.to_celsius(value) AS celsius
FROM temperature;