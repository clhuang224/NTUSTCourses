-- 1.列出公司所有男員工平均薪水。（5 分） 

select avg(SALARY)
from employee
where SEX = 'M';

-- 2.對於沒有參與任何一項計畫的員工列出這些工程師的名字及部門名稱。（5 分） 

select E.FNAME, E.LNAME, D.DNAME
from employee E, department D
where E.SSN not in (select W.ESSN
					from work_on W) and
	  E.DNO = D.DNUMBER;

-- 3.姓氏是S開頭的員工，減薪15%，減薪後低於25000元就以25000元計（5 分）

select *, (case when LNAME like 'S%' 
					then if(SALARY > 25000, SALARY * .85, 25000)
				else SALARY
		   end) as NEW_SALARY
from employee;


-- 4.列出如下列結果的SQL語法(Diff_salary = Salary – avg_salary) (10%)

select E.Fname, E.Lname, E.Salary, D.Dname, T.Max_salary, T.Min_salary, T.avg_salary, (E.SALARY - T.avg_salary) as Diff_salary
from employee E, (select DNO, max(SALARY) as Max_salary, min(SALARY) as Min_salary, round(avg(SALARY)) as avg_salary
				  from employee
                  group by DNO
				 ) as T, department D
where E.DNO = D.DNUMBER and
      D.DNUMBER = T.DNO;