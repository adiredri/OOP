#include <typeinfo>
#include "Student.h"

class UndergradStudent:virtual public Student{
    public:
    UndergradStudent(int id):Student(id){}

    virtual bool help(Student& s){
        return (typeid(s)==typeid(UndergradStudent));
    }
    
};
class PhDStudent:virtual public Student{
    
    public:
    PhDStudent(int id):Student(id){}
    
    virtual bool help(Student& s){
        return true;
    }
    
};
class MAStudent:virtual public Student{
    
    public:
    MAStudent(int id):Student(id){}
    virtual bool help(Student& s){
        return (typeid(s)==typeid(UndergradStudent) || typeid(s)==typeid(MAStudent));
    }
    
};

class DirectStudent:public UndergradStudent, public MAStudent, public PhDStudent{
    
    public:
    DirectStudent(int id):Student(id),UndergradStudent(id),MAStudent(id),PhDStudent(id){}
    virtual bool help(Student& s){
        return (typeid(s)==typeid(DirectStudent));
    }
    
};
