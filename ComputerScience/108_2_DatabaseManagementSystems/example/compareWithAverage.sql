-- 列出員工姓,名,薪資,全公司平均薪資與各人薪資與全公司薪資的差異

-- 解法1

select E.FNAME, E.LNAME, E.SALARY, AVG(G.SALARY) as AVG_SALARY, E.SALARY - AVG(G.salary) as diff_salary
from employee E, employee G
group by E.fname, E.lname, E.salary;

-- 解法2

select FNAME, LNAME, SALARY, (select AVG(SALARY)  from employee)as AVG_SALARY, SALARY - (select AVG(SALARY)  from employee) as diff_salary
from employee
group by fname, lname, salary;

-- 解法3

select E.FNAME, E.LNAME, E.SALARY, AVG_SALARY, E.SALARY - AVG_SALARY as diff_salary
from employee E, (select AVG(SALARY) as AVG_SALARY from employee) as temp
group by E.fname, E.lname, E.salary;