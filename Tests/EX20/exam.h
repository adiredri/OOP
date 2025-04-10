#ifndef SRC_EXAM_H_
#define SRC_EXAM_H_

#ifndef NULL
#define NULL 0
#endif

class Person{
    public:
    const int id;    
    Person(int id):id(id){}
    virtual ~Person(){}
};

class Student:public virtual Person{
    int grade=100;
    public:
    Student(int id):Person(id){}
    virtual int getGrade(){
        return grade;
    }
    void setGrade(int grade){
        this->grade=grade;
    }
};

class Employee:public virtual Person{
    int workHours=250;    
    public:
    Employee(int id):Person(id){}
    virtual int getWorkHours(){
        return workHours;
    }
    void setWorkHours(int workHours){
        this->workHours=workHours;
    }

};


class PersonList{
    public:
    const PersonList* next;
    const Person* item;
    PersonList(PersonList* next,Person* item):next(next),item(item){}
    ~PersonList(){
        delete item;
        delete next;
    }
};



#endif /* SRC_EXAM_H_ */