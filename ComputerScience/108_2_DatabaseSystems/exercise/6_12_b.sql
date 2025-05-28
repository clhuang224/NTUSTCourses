create table 6_12_b(
	select Course_name, Instructor
    from COURSE C, SECTION S
    where S.Semester = 'fall' and
		  year = '08' and
          S.Course_number = C.Course_number
);

select * from 6_12_b;