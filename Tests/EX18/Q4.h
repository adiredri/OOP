
#ifndef SRC_Q4_H_
#define SRC_Q4_H_

#include "Student.h"

class StudentAVGUtil:public StudentUtil{
    public:
    virtual Student& max(Student& s1, Student& s2){
        return (s1.getAVG()>s2.getAVG()?s1:s2);
    }
    virtual Student& min(Student& s1, Student& s2){
        return (s1.getAVG()>s2.getAVG()?s2:s1);
    }
    virtual bool areEqual(Student& s1, Student& s2){
        return s1.getAVG()==s2.getAVG();
    }
};

class StudentNameUtil:public StudentUtil{
    public:
    virtual Student& max(Student& s1, Student& s2){
        if(strcmp(s1.getName(),s2.getName())>=0)
            return s1;
        return s2;
    }
    virtual Student& min(Student& s1, Student& s2){
        if(strcmp(s1.getName(),s2.getName())<=0)
            return s1;
        return s2;
    }
    virtual bool areEqual(Student& s1, Student& s2){
        return strcmp(s1.getName(),s2.getName())==0;
    }
};

#endif