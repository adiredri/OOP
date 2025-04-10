#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <string.h>
using namespace std;

class Student{
	char name;
	int age;
public:
	Student(const char name, int age){
		this->name = name;
		this->age = age;
	}
	Student(const Student& s){
		this->name = s.name;
		this->age = s.age;
	}

	void setAge(int age){ this->age = age; }
	int getAge()const { return age; }
	char getName()const { return name; }

	virtual void print(ostream& out){
		out << "name: " << name << endl;
		out << "age: " << age << endl;
	}

	virtual ~Student(){

	}
};

#endif