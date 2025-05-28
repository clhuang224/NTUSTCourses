
-- left substr right instr

-- 針對 9-Jan-55 這種格式來取年月日
-- Houston,X 來取 houston

select left(bdate,instr(bdate,'-')-1) as b_day,
	   substr(bdate,instr(bdate,'-')+1,3) as b_mon,
       right(bdate,2) as b_year,
       left(address, instr(address,',')-1) as address_town
from employee;