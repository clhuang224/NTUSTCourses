-- 沒有員工參與的專案

select P.Pname
from project P
where not exists (select W.Pno
				  from works_on W
				 )
;

-- 每個專案都有員工