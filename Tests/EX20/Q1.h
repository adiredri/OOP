#ifndef SRC_Q1_H_
#define SRC_Q1_H_
#include <typeinfo>
#include <fstream>
#include "exam.h"
using namespace std;

class StudentEmployee: public Student, public Employee{
    public:
    StudentEmployee(int id):Person(id),Student(id),Employee(id){}
    void save(const char* filename) {
        ofstream out(filename);
        out.write((char*)(&id), sizeof(id));
        int grade = Student::getGrade();
        out.write((char*)(&grade), sizeof(grade));
        int workHours = Employee::getWorkHours();
        out.write((char*)(&workHours), sizeof(workHours));
        out.close();
    }

    static StudentEmployee load(const char* filename){
        ifstream in(filename);
        int id,grade,workhours;
        in.read((char*)(&id),sizeof(id));
        in.read((char*)(&grade),sizeof(grade));
        in.read((char*)(&workhours),sizeof(workhours));
        in.close();
        StudentEmployee s(id);
        s.setGrade(grade);
        s.setWorkHours(workhours);
        return s;
    }
};



#endif /* SRC_Q1_H_ */