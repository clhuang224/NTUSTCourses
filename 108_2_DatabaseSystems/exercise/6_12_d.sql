create table 6_12_d(
	select ST.Student_number, Course_name, C.Course_number, Credit_hours, Semester, Year, Grade
    from COURSE C, SECTION SE, STUDENT ST, GRADE_REPORT G
    where ST.Class = 1 and ST.Major = 'MATH'
);

select * from 6_12_d;