-- 列出 Smith 參與的所有專案名稱

select project.Pname
from employee, works_on, project
where employee.Ssn = works_on.Essn and project.Pnumber = works_on.Pno and employee.Lname = "Smith"
;