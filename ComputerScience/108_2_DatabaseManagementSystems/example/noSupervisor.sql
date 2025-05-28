-- 誰沒有上司？

SELECT E.Ssn, E.Fname, E.Lname, E.Super_ssn, S.Ssn, S.Fname, S.Lname
FROM EMPLOYEE AS E LEFT JOIN EMPLOYEE as S
on E.Super_ssn = S.Ssn
-- WHERE E.Fname = "John"
WHERE E.Super_ssn is null
;

-- left join 只要左邊有東西 就會列出來 右邊沒有資料就會是 null
-- right join 相反
-- equal join 兩邊都有才有