create table 6_12_a(
	select Course_name
    from COURSE
    where upper(Department) like upper('cs')
);

select * from 6_12_a;