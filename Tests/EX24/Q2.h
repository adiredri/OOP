#define _CRT_SECURE_NO_WARNINGS

#ifndef SRC_Q2_H_
#define SRC_Q2_H_

#include <fstream>
#include "Student.h"

using namespace std;
    

template<class T>
void write(ofstream& out, T t){
    out.write((char*)& t,sizeof(T));
}
template<class T>
void read(ifstream& in, T& t){
    in.read((char*)& t,sizeof(T));
}

void save(const char* filename, Student& e){
    ofstream out(filename);
    write(out,e.getID());
    out.write(e.getName(), MAX_NAME_LEN);
    write(out,e.getCourses());
    for(int i=0;i<e.getCourses();i++)
        write(out,e.getGrades()[i]);
    
    out.close();
}

Student load(const char* filename){
    ifstream in(filename);
    int id, courses;
    char name[MAX_NAME_LEN];
    float* grades;
    read(in,id);
    in.read(name,MAX_NAME_LEN);
    read(in,courses);
    grades=new float[courses];
    for(int i=0;i<courses;i++)
        read(in,grades[i]);
    in.close();
    Student e(id,name,courses,grades);
    delete[] grades;
    return e;
}

#endif /* SRC_Q2_H_ */