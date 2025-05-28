-- 使用巢狀查詢 Research 及 Administration 部門的員工資料

select *
from employee E
where Dno in (select D.Dnumber
			 from department D
			 where D.Dname = "Research" or D.Dname = "Administration")
-- where Dno in (4,5)
;

-- 傳回一個選項的時候可以用 =
-- 多個選項要用 in (陣列的感覺)

