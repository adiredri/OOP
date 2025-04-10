#define _CRT_SECURE_NO_WARNINGS

#include <cstring>
#include <iostream>

#ifndef SRC_STUDENT_H_
#define SRC_STUDENT_H_

using namespace std;

#define MAX_NAME_LEN 20

class Student{
    int id;         // id
    char name[MAX_NAME_LEN];     // name non-empty, null terminated string of maximum MAX_NAME_LEN size (including the null)
    float avg;      // total average
    int courses;    // number of courses
    float* grades;  // grade in each course

    // private helper - sets all parameters
    void set(int id, const char *name, int courses, float* grades){
        this->id=id;
        strcpy(this->name, name);
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
    // assuming name is in the correct length
    Student(int id, const char* name, int courses, float* grades){
        set(id,name,courses,grades);
    }
    
    Student(const Student& e){
        set(e.id,e.name,e.courses,e.grades);
    }
    
    void compareTo(const Student& e){
        if(id!=e.id)
            cout<<"wrong id (-5)"<<endl;
        if (!(strcmp(name, e.name) == 0))
            cout << "wrong name (-5)" << endl;
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
    const char* getName() const { return name;}
    int getCourses() const{ return courses;}
    float getAVG() const{return avg;}
    const float* getGrades() const{ return grades;}
    
    ~Student(){
        delete[] grades;
    }
};

#endif