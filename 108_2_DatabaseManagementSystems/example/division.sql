-- ※DIVISION的SQL語法：

-- 除式、被除式與目標表格不同

-- SELECT 屬性
-- FROM 目標表格
-- WHERE NOT EXISTS (SELECT *
-- 					 FROM  除式表格
-- 					 WHERE 除式限制條件)
-- 						   AND NOT EXISTS (SELECT *
-- 										   FROM 被除式表格
-- 										   WHERE 目標表格.合併屬性1=被除式表格.合併屬性1
-- 												 AND 被除式表格.合併屬性2=除式表格.合併屬性2
-- 												 AND 被除式限制條件)
-- 					)
-- ;

-- 查詢範例：擷取員工所參與的計畫全部都是由4號部門控管的員工姓名

SELECT E.FNAME, E.LNAME
FROM EMPLOYEE AS E
WHERE NOT EXISTS (SELECT P.PNUMBER
				  FROM  PROJECT AS P
				  WHERE P.DNUM=4
						AND NOT EXISTS (SELECT W.PNO
										FROM  WORK_ON AS W
										WHERE E.SSN=W.ESSN
											  AND P.PNUMBER=W.PNO)
				 )
;