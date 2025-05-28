create table 6_10_c(
	select Fname, Lname
		from EMPLOYEE E, PROJECT P, WORKS_ON W
		where P.Pname = 'Computerization' and
			  P.Pnumber = W.Pno and
			  W.Essn = E.ssn
);

select * from 6_10_c;