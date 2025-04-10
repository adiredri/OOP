
#ifndef SRC_STD1_H_
#define SRC_STD1_H_

#include<iostream>
#include <string.h>

using namespace std;
class Student{
    int id;         // id
	char* name;
    float avg;      // total average

    // private helper - sets all parameters
    void set(int id,const char* name, float avg){
        this->id=id;
		this->name=strdup(name);
		this->avg=avg;
    }

    
    public:
    Student(int id, const char* name, float avg){
        set(id,name,avg);
    }
    
    Student(const Student& s){
        set(s.id,s.name,s.avg);
    }
    
    void compareTo(const Student& s){
        if(id!=s.id)
            cout<<"wrong id (-5)"<<endl;
        if(avg!=s.avg)
            cout<<"wrong average (-5)"<<endl;
		if(strcmp(this->name,s.name)!=0)
			cout<<"wrong name (-5)"<<endl;
    }
    
    // getters
    int getID() const{ return id;}
    float getAVG() const{return avg;}
    const char* getName() const{ return name;}
    
    ~Student(){
        delete[] name;
    }
};


class StudentUtil{
    public:
    virtual Student& max(Student& s1, Student& s2)=0;
    virtual Student& min(Student& s1, Student& s2)=0;
    virtual bool areEqual(Student& s1, Student& s2)=0;
};

#endif