#include <iostream>
#include <vector>
#include <typeinfo>
#include <string.h>

using namespace std;

class Employee{
  public:
  const int id;
  Employee(int id):id(id){}
  virtual ~Employee(){}
};

class BOS:public Employee{
  vector<Employee*> employees;
  
  public:
  
  BOS(int id):Employee(id){}
  
  void add(Employee* e)throw(const char*){
        if(typeid(*e)==typeid(Employee))
            employees.push_back(e);
        else{
            BOS* b=dynamic_cast<BOS*>(e);
            if(b && !myBos(b))
                employees.push_back(e);
            else
                throw "ERROR: BOS circle";
        }
  }
  
  bool myBos(BOS* b){
      if(b==this)
        return true;

      //auto is vector<Employee*>::iterator
      auto it = b->employees.begin();
      bool mb=false;
      while(it!=b->employees.end() && !mb){
        BOS* bb=dynamic_cast<BOS*>(*it);
        if(bb && !mb)
            mb=mb || myBos(bb);
        it++;
      }
      return mb;
  }
};
