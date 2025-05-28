-- create table

create table EMPLOYEE(
	Fname varchar(16),
    Minit varchar(1),
    Lname varchar(16),
    Ssn char(9),
    Bdate date,
    Address varchar(128),
    Sex varchar(1),
    Salary integer,
    Super_ssn char(9),
    Dno integer,
    constraint UC_EMPLOYEE unique(Ssn),
    constraint PK_EMPLOYEE primary key(Ssn)
);

create table DEPARTMENT(
	Dname varchar(32),
    Dnumber integer,
    Mgr_ssn char(9),
    Mgr_start_date date,
    constraint UC_DEPARTMENT unique(Dnumber),
    constraint PK_DEPARTMENT primary key(Dnumber)
);

create table DEPT_LOCATIONS(
	Dnumber integer,
    Dlocation varchar(32),
    constraint PK_DEPT_LOCATIONS primary key(Dnumber, Dlocation)
);

create table PROJECT(
	Pname varchar(32),
    Pnumber integer,
    Plocation varchar(32),
    Dnum integer,
    constraint UC_PROJECT unique(Pnumber),
    constraint PK_PROJECT primary key(Pnumber)
);

create table WORKS_ON(
	Essn char(9),
    Pno integer,
    Hours float,
    constraint PK_WORKS_ON primary key (Essn, Pno)
);

create table DEPENDENT(
	Essn char(9),
    Dependent_name varchar(64),
    Sex varchar(1),
    Bdate date,
    Relationship varchar(16),
    constraint PK_DEPENDENT primary key(Essn, Dependent_name)
);


-- insert data

insert into EMPLOYEE( Fname, Minit, Lname, Ssn, Bdate, Address, Sex, Salary, Super_ssn, Dno)
values('John', 'B', 'Smith', '123456789', '1965-01-09', '731 Fondren, Houston, TX', 'M', 30000, '333445555', 5),
	  ('Franklin', 'T', 'Wong', '333445555', '1955-12-08', '638 Voss, Houston, TX', 'M', 40000, '888665555', 5),
	  ('Alicia', 'J', 'Zelaya', '999887777', '1968-01-19', '3321 Castle, Spring, TX', 'F', 25000, '987654321', 4),
	  ('Jennifer', 'S', 'Wallace', '987654321', '1941-06-20', '291 Berry, Bellaire, TX', 'F', 43000, '888665555', 4),
	  ('Ramesh', 'K', 'Narayan', '666884444', '1962-09-15', '975 Fire Oak, Humble, TX', 'M', 38000, '333445555', 5),
	  ('Joyce', 'A', 'English', '453453453', '1972-07-31', '5631 Rice, Houston, TX', 'F', 25000, '333445555', 5),
	  ('Ahmad', 'V', 'Jabbar', '987987987', '1969-03-29', '980 Dallas, Houston, TX', 'M', 25000, '987654321', 4),
	  ('James', 'E', 'Borg', '888665555', '1937-11-10', '450 Stone, Houston, TX', 'M', 55000, null, 1);

insert into DEPARTMENT( Dname, Dnumber, Mgr_ssn, Mgr_start_date)
values ('Research', 5, '333445555', '1988-05-22'),
	   ('Administration', 4, '987654321', '1995-01-01'),
	   ('Headquarters', 1, '888665555', '1981-06-19');

insert into DEPT_LOCATIONS( Dnumber, Dlocation)
values (1, 'Houston'),
	   (4, 'Stafford'),
	   (5, 'Bellaire'),
	   (5, 'Sugarland'),
	   (5, 'Houston');

insert into PROJECT( Pname, Pnumber, Plocation, Dnum)
values ('ProductX', 1, 'Bellaire', 5),
	   ('ProductY', 2, 'Sugarland', 5),
	   ('ProductZ', 3, 'Houston', 5),
	   ('Computerization', 10, 'Stafford', 4),
	   ('Reorganization', 20, 'Houston', 1),
	   ('Newbenefits', 30, 'Stafford', 4);

insert into WORKS_ON(Essn, Pno, Hours)
values('123456789', 1, 32.5),
	  ('123456789', 2, 7.5),
	  ('666884444', 3, 40),
	  ('453453453', 1, 20),
	  ('453453453', 2, 20),
	  ('333445555', 2, 10),
	  ('333445555', 3, 10),
	  ('333445555', 10, 10),
	  ('333445555', 20, 10),
	  ('999887777', 30, 30),
	  ('999887777', 10, 10),
	  ('987987987', 10, 35),
	  ('987987987', 30, 5),
	  ('987654321', 30, 20),
	  ('987654321', 20, 15),
	  ('888665555', 20, null);
      
insert into DEPENDENT( Essn, Dependent_name, Sex, Bdate, Relationship)
values ('333445555', 'Alice', 'F', '1986-04-05', 'Daughter'),
	   ('333445555', 'Theodore', 'M', '1983-10-15', 'Son'),
	   ('333445555', 'Joy', 'F', '1958-05-03', 'Spouse'),
	   ('987654321', 'Abner', 'M', '1942-02-28', 'Spouse'),
	   ('123456789', 'Michael', 'M', '1988-01-04', 'Son'),
	   ('123456789', 'Alice', 'F', '1988-12-30', 'Daughter'),
	   ('123456789', 'Elizabeth', 'F', '1967-05-05', 'Spouse');


-- FK

alter table EMPLOYEE
	add constraint FK_EMPLOYEE_Super_ssn foreign key(Super_ssn) references EMPLOYEE(Ssn),
    add constraint FK_EMPLOYEE_Dno foreign key(Dno) references DEPARTMENT(Dnumber);

alter table DEPARTMENT
	add constraint FK_DEPARTMENT_Mgr_ssn foreign key(Mgr_ssn) references EMPLOYEE(Ssn);

alter table DEPT_LOCATIONS
	add constraint FK_DEPT_LOCATIONS_Dnumber foreign key(Dnumber) references DEPARTMENT(Dnumber);

alter table PROJECT
	add constraint FK_PROJECT_Dum foreign key(Dnum) references DEPARTMENT(Dnumber);

alter table WORKS_ON
	add constraint FK_WORKS_ON_Essn foreign key(Essn) references EMPLOYEE(Ssn),
    add constraint FK_WORKS_ON_Pno foreign key(Pno) references PROJECT(Pnumber);

alter table DEPENDENT
	add constraint FK_DEPENDENT_Essn foreign key(Essn) references EMPLOYEE(Ssn);