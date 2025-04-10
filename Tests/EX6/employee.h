#include <iostream>
using namespace std;

class Check{
  int sum,org;
  public:
  Check(){
      sum=rand()%100;
      org=sum;
  }
  bool areAllFree(){return sum==org;}
  
  friend class Employee;
};

Check check;

class Employee{
    int id;    
    public:
    Employee(int id){
        this->id=id;
        check.sum+=id;
    }
    
    int getID(){return id;}
    
    virtual void printDetails(ostream& out)=0;
    
    virtual ~Employee(){
        check.sum-=id;
    }
};