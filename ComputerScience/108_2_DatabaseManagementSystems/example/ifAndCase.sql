-- if 和 case 的應用

-- 減薪兩成 但低於25000者為25000

select fname, lname, salary, if(salary*0.8<25000,25000,salary*0.8) as new_salary
from employee;

-- 將薪水分級

SELECT fname, lname, salary, CASE WHEN salary > 42000 THEN 'A'
								  WHEN salary > 32000 THEN 'B'
								  ELSE 'C'
								  END
							 AS salaryLevel
FROM employee;


-- 將薪水分級並加上各等級的平均和全距

select E.FNAME, E.LNAME, E.salary, T.salaryLevel, T.salaryAverage, T.salaryRange
from
(SELECT salaryLevel, max(salary)-min(salary) as salaryRange, avg(salary) as salaryAverage 
from
	(SELECT fname, lname, salary, CASE WHEN salary > 42000 THEN 'A'
									  WHEN salary > 32000 THEN 'B'
									  ELSE 'C'
									  END
								 AS salaryLevel
	FROM employee) as A
group by salaryLevel) as T,
(SELECT fname, lname, salary, CASE WHEN salary > 42000 THEN 'A'
								  WHEN salary > 32000 THEN 'B'
								  ELSE 'C'
								  END
							 AS salaryLevel
FROM employee) as E
where E.salaryLevel = T.salaryLevel
order by T.salaryLevel;