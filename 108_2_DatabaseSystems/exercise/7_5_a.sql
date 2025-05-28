create table 7_5_a(
	select Dname, count(*)
    from DEPARTMENT D, EMPLOYEE E
    where D.Dnumber = E.Dno
    group by Dname
    having avg(E.Salary) > 30000
);

select * from 7_5_a;