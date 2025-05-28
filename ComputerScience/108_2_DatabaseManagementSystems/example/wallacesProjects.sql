-- 列出 Wallace 參與的專案及負責部門的專案

SELECT P.Pname
FROM project P, employee E, works_on W
WHERE E.Ssn = W.Essn and P.Pnumber = W.Pno and E.Lname = "Wallace"
UNION
SELECT P.Pname
FROM project P, department D, employee E
WHERE P.Dnum = D.Dnumber and D.Mgr_ssn = E.Ssn and E.Lname = "Wallace"
;
