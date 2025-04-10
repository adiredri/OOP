

#ifndef SRC_COVID19_H_
#define SRC_COVID19_H_
#include <iostream>
using namespace std;

class Employee{
	bool positive;
public:
	Employee(){
		positive=false;
	}

	void setCovid19(){
		positive=true;
	}
	bool test(){
		return positive;
	}
	virtual ~Employee(){

	}
};

class Manager:public Employee{
	Employee** emps;
	size_t empSize;

public:
	void setEmps(Employee** emps,size_t empSize){
		this->emps=emps;
		this->empSize=empSize;
	}

	Employee** getEmps(){
		return emps;
	}

	size_t getEmpSize(){
		return empSize;
	}

	virtual ~Manager(){
		for(size_t i=0;i<empSize;i++)
			delete emps[i];
		delete[] emps;
	}
};



class Covid19{
	int id;
	static int cnt;
public:
	Covid19(int id):id(id){cnt++;}
	int getID()const{return id;}
	int getCount()const{return cnt;}
	virtual ~Covid19(){}
};
int Covid19::cnt=0;

#endif /* SRC_COVID19_H_ */
