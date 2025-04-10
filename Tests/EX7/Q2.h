#include <iostream>
#include <fstream>

using namespace std;

class Student{
  
  int id;
  float average;
  
  public:
  Student(int id, float average){
      this->id=id;
      this->average=average;
  }
  
  int getID() const{ return id;}
  float getAverage() const{ return average;}
  
  Student(ifstream& in){
      in>>id>>average;
  }
  
  
  void save(ofstream& out){
      out<<id<<" "<<average<<" ";
      saveAdditions(out);
  }
  
  void load(ifstream& in){
      in>>id>>average;
      loadAdditions(in);
  }


  protected:  
  virtual void saveAdditions(ofstream& out) const =0;
  virtual void loadAdditions(ifstream& in)=0;
  
};

class UnderGradStudent: public virtual Student{
    int year; // 1,2 or 3
    public:
    
    int getYear() const{
        return year;
    }
    
    UnderGradStudent(int id, float average,int year):Student(id, average){
        this->year=year;
    }
    
    UnderGradStudent(ifstream& in):Student(in){
        loadAdditions(in);
    };
    
  virtual void saveAdditions(ofstream& out) const{
      out<<year<<" ";
  }
  virtual void loadAdditions(ifstream& in){
    in>>year;  
  }
    
};

class GradStudent: public virtual Student{
    double salary;
    public:
    
    double getSalary() const{
        return salary;
    }

    GradStudent(int id, float average,double salary):Student(id, average){
        this->salary=salary;
    }
    
    GradStudent(ifstream& in):Student(in){
        loadAdditions(in);
    };
    
  virtual void saveAdditions(ofstream& out) const{
      out<<salary<<" ";
  }
  virtual void loadAdditions(ifstream& in){
      in>>salary;  
  }
    
};

class DirectStudent: public UnderGradStudent, public GradStudent{
    public:
    DirectStudent(int id, float average,char year, double salary):Student(id, average),UnderGradStudent(id,average,year), GradStudent(id,average,salary){}
    
    DirectStudent(ifstream& in):Student(in),UnderGradStudent(in),GradStudent(in){};
    
  virtual void saveAdditions(ofstream& out) const{
      UnderGradStudent::saveAdditions(out);
      GradStudent::saveAdditions(out);
  }
  virtual void loadAdditions(ifstream& in){
      UnderGradStudent::loadAdditions(in);
      GradStudent::loadAdditions(in);
  }
};
