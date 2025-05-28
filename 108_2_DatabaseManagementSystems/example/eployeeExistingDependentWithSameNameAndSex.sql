-- 擷取眷屬的名字和性別與員工本人相同的員工姓名

select E.Fname, E.Lname
from employee E
where exists (select *
			  from dependent as D
              where D.Dependent_name = E.Fname and
					D.Sex = E.Sex and
                    D.Essn = E.Ssn
			 )
;

-- 沒這個人