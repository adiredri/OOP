#ifndef SRC_EMPLOYEE_H_
#define SRC_EMPLOYEE_H_
#include <string.h>

class Employee{
	int len;
	char* name;
	double id;
public:
	Employee(const char* name,double id):id(id){
		len=strlen(name);
		this->name=strdup(name);
	}

	const char* getName(){
		return name;
	}

	double getID(){
		return id;
	}
	bool equals(const Employee& e){
		return id==e.id && len==e.len && strcmp(name,e.name)==0;
	}
	virtual ~Employee(){}
};

class Manager:public Employee{
	char level;
public:
	Manager(const char* name,double id,char level):Employee(name,id),level(level){}
	char getLevel(){return level;}
	bool equals(const Manager& m){
		return level==m.level && Employee::equals(m);
	}

};




#endif /* SRC_EMPLOYEE_H_ */
