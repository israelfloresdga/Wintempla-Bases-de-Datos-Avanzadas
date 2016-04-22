--1
USE city_bank;
GO

GRANT SELECT ON friend TO andrew;

--2
USE city_bank;
GO

GRANT SELECT, UPDATE ON friend TO andrew;

--3
USE city_bank;
GO

GRANT ALL ON friend TO andrew;


--4
USE city_bank;
GO

REVOKE SELECT ON friend TO andrew;


--5
USE city_bank;
GO

GRANT SELECT ON friend TO PUBLIC;


--6
USE city_bank;
GO

REVOKE ALL ON friend TO PUBLIC;