#pragma once

class Person
{
protected:
	int age;
	char name[32];

public:
	Person();
	~Person();
	virtual void Say() = 0;
};

class Student : public Person
{
protected:
	char studentNum[11];
	char major[32];
	int schoolYear;

public:
	Student();
	~Student();

	int getAge();
	char* getName();
	void setAge(int age);
	void setName(char* name);

	char* getStudentNum();
	char* getMajor();
	int getSchoolYear();
	void setStudentNum(char* studentNum);
	void setMajor(char* major);
	void setSchoolYear(int year);
	void Say() override;
};

class Professor : public Person
{
protected:
	char professorNum[11];
	char major[32];

public:
	Professor();
	~Professor();
	char* getProfessorNum();
	char* getMajor();
	void setNameAge(char* name, int age);
	void setProfessorNum(char* professorNum);
	void setMajor(char* major);
	void Say() override;
};
