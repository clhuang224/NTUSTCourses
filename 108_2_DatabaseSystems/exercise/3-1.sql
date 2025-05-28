-- create table

create table STUDENT (
	Name varchar(32),
    Student_number integer,
    Class integer,
    Major varchar(8),
    constraint UC_STUDENT_Student_number unique(Student_number),
    constraint PK_STUDENT primary key(Student_number)
);

create table COURSE (
	Course_name varchar(32),
    Course_number varchar(16),
    Credit_hours integer,
    Department varchar(8),
    constraint UC_COURSE_Course_number unique(Course_number),
    constraint PK_COURSE primary key(Course_number)
);

create table SECTION(
	Section_identifier integer,
    Course_number varchar(16),
    Semester varchar(8),
    Year char(2),
    Instructor varchar(32),
    constraint PK_SECTION primary key(Section_identifier)
);

create table GRADE_REPORT(
	Student_number integer,
    Section_identifier integer,
    Grade varchar(1),
    constraint PK_GRADE_REPORT primary key(Section_identifier, Student_number)
);

create table PREREQUISITE(
	Course_number varchar(16),
    Prerequisite_number varchar(16),
    constraint PK_PREREQUISITE primary key(Course_number, Prerequisite_number)
);


-- insert tuple

insert into STUDENT (Name, Student_number, Class, Major)
values ('Smith', 17, 1, 'CS'),
	   ('Brown', 8, 2, 'CS');

insert into COURSE (Course_name, Course_number, Credit_hours, Department)
values ('Intro to Computer', 'CS1310', 4, 'CS'),
	   ('Data Structures', 'CS3320', 4, 'CS'),
	   ('Discrete Mathematics', 'MATH2410', 3, 'MATH'),
	   ('Database', 'CS3380', 3, 'CS');

insert into SECTION (Section_identifier, Course_number, Semester, Year, Instructor)
values (85, 'MATH2410', 'Fall', '07', 'King'),
	   (92, 'CS1310', 'Fall', '07', 'Anderson'),
	   (102, 'CS3320', 'Spring', '08', 'Knuth'),
	   (112, 'MATH2410', 'Fall', '08', 'Chang'),
	   (119, 'CS1310', 'Fall', '08', 'Anderson'),
	   (135, 'CS3380', 'Fall', '08', 'Stone');

insert into GRADE_REPORT (Student_number, Section_identifier, Grade)
values (17,112,'B'),
	   (17,119,'C'),
	   (8,85,'A'),
	   (8,92,'A'),
	   (8,102,'B'),
	   (8,135,'A');

insert into PREREQUISITE (Course_number, Prerequisite_number)
values ('CS3380', 'CS3320'),
	   ('CS3380', 'MATH2410'),
       ('CS3320', 'CS1310');


-- FK

alter table SECTION
	add constraint FK_SECTION_Course_number foreign key(Course_number) references COURSE(Course_number);

alter table GRADE_REPORT
	add constraint FK_GRADE_REPORT_Student_number foreign key(Student_number) references STUDENT(Student_number),
	add constraint FK_GRADE_REPORT_Section_identifier foreign key(Section_identifier) references SECTION(Section_identifier);

alter table PREREQUISITE
	add constraint FK_PREREQUISITE_Course_number foreign key(Course_number) references COURSE(Course_number),
	add constraint FK_PREREQUISITE_Prerequisite_number foreign key(Prerequisite_number) references COURSE(Course_number);