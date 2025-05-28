-- 列出員工參與的專案數

select E.Fname as Employee, count(*) as ProjectAmount
from employee E, work_on W
where E.Ssn = W.Essn
group by W.PNO;