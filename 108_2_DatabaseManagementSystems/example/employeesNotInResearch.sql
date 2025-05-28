-- 不在 research 部門工作的員工

select *
from employee E, department D
where E.Dno = D.Dnumber and D.Dname <> 'Research';

-- != 也可以