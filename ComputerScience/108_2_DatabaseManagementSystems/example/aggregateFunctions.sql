-- 列出所有員工的最高 最低 總和 平均薪水 及樣本筆數

select max(Salary), min(Salary), count(Salary), sum(Salary), avg(Salary)
from employee;

-- 列出薪水大於平均薪水的員工

select E.Fname, E.Lname, E.Salary
from employee E
where E.Salary > (select avg(Salary)
				  from employee
				 )
;