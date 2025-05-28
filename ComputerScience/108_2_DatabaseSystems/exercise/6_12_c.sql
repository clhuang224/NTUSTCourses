create table 6_12_c(
	select Course_number, Semester, Year, ST.Student_number
    from SECTION SE, STUDENT ST, GRADE_REPORT G
    where SE.Instructor = 'Anderson' and
		  ST.Student_number = G.Student_number and
          SE.Section_identifier = G.Section_identifier
);

select * from 6_12_c;