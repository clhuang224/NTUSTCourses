create table 6_10_b (
	select Fname, Lname
	from EMPLOYEE
	where Address like '%Houston%TX%' and
          Super_ssn = '333445555'
);

select * from 6_10_b;