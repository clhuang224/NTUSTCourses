create table 6_10_a (
	select Fname, Lname
	from EMPLOYEE E, PROJECT P, WORKS_ON W
	where E.Dno = 5 and
		  E.Salary > 3000 and
		  P.Pname = 'ProductZ' and P.Pnumber = W.Pno and W.Essn = E.Ssn
);

select * from 6_10_a;