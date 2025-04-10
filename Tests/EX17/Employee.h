
#ifndef SRC_Emp1_H_
#define SRC_Emp1_H_

#include<iostream>
using namespace std;
class Employee{
    int id;         // id
    float avg;      // total average
    int courses;    // number of courses
    float* grades;  // grade in each course

    // private helper - sets all parameters
    void set(int id, int courses, float* grades){
        this->id=id;
        this->grades=new float[courses];
        this->courses=courses;
        avg=0;
        for(int i=0;i<courses;i++){
            this->grades[i]=grades[i];
            avg+=grades[i];
        }
        avg/=courses;
    }

    
    public:
    Employee(int id, int courses, float* grades){
        set(id,courses,grades);
    }
    
    Employee(const Employee& e){
        set(e.id,e.courses,e.grades);
    }
    
    void compareTo(const Employee& e){
        if(id!=e.id)
            cout<<"wrong id (-5)"<<endl;
        if(courses!=e.courses)
            cout<<"wrong number of courses (-5)"<<endl;
        if(avg!=e.avg)
            cout<<"wrong average (-5)"<<endl;
        
        for(int i=0;i<courses;i++){
            if(i>=e.courses || e.grades[i]!=grades[i])
                cout<<"wrong grade (-1)"<<endl;
        }
    }
    
    // getters
    int getID() const{ return id;}
    int getCourses() const{ return courses;}
    float getAVG() const{return avg;}
    const float* getGrades() const{ return grades;}
    
    ~Employee(){
        delete[] grades;
    }
};

#endif