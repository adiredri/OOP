#ifndef SRC_Q2_H_
#define SRC_Q2_H_

#include <fstream>
#include "Employee.h"

using namespace std;
    

template<class T>
void write(ofstream& out, T t){
    out.write((char*)& t,sizeof(T));
}
template<class T>
void read(ifstream& in, T& t){
    in.read((char*)& t,sizeof(T));
}

void save(const char* filename, Employee& e){
    ofstream out(filename);
    write(out,e.getID());
    write(out,e.getCourses());
    for(int i=0;i<e.getCourses();i++)
        write(out,e.getGrades()[i]);
    
    out.close();
}

Employee load(const char* filename){
    ifstream in(filename);
    int id, courses;
    float* grades;
    read(in,id);
    read(in,courses);
    grades=new float[courses];
    for(int i=0;i<courses;i++)
        read(in,grades[i]);
    in.close();
    Employee e(id,courses,grades);
    delete[] grades;
    return e;
}

#endif /* SRC_Q2_H_ */