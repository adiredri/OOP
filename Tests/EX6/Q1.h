#include <iostream>
#include <list>
#include <algorithm>
#include "employee.h"

using namespace std;


class Manager: public Employee{
    list<Employee*> employees;
    double level;
    public:
    Manager(int id,double level):Employee(id){
        this->level=level;
    }
    Manager& addEmployee(Employee* e){
        employees.push_back(e);
        return *this;
    }
    virtual void printDetails(ostream& out){
        out<<"Manager ID: "<<getID()<<" Level: "<<level<<endl;
        for_each(employees.begin(),employees.end(),[&out](Employee* e){
            e->printDetails(out);
        });
    }
    
    ~Manager(){
        for_each(employees.begin(),employees.end(),[](Employee* e){delete e;});
    }
};

class Engineer: public Employee{
    int degree;
    public:
    Engineer(int id,int degree):Employee(id){
        this->degree=degree;
    }
    virtual void printDetails(ostream& out){
        out<<"Engineer ID: "<<getID()<<" Degree: "<<degree<<endl;
    }
};

