CREATE OR REPLACE procedure temp
as
begin
	begin
  		insert into temperature VALUES(15,15);
 		EXCEPTION
 		WHEN OTHERS THEN
		Rollback;
		return;
	end;

	begin
		delete from temperature where temperature_id=15;
	 	EXCEPTION
	 	WHEN OTHERS THEN
	  	Rollback;
	  	return;
	end;
commit;
end;
/


--Otro ejemplo con otra metodología
BEGIN
  SAVEPOINT start_tran;
  INSERT INTO .... ; -- first DML
  UPDATE .... ; -- second DML
  BEGIN ... END; -- some other work
  UPDATE .... ; -- final DML
EXCEPTION
  WHEN OTHERS THEN
    ROLLBACK TO start_tran;
    RAISE;
END;