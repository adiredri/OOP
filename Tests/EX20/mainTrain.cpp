#include<iostream>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <typeinfo>
#include "exam.h"
#include "Q1.h"
#include "Q2.h"
#include "Q3.h"

using namespace std;

void test1(){

    Person* b=new StudentEmployee(0); // tests StudentEmployee is a type of Person. A fail cause runtime error...

    bool ok=true;
    Student* h=dynamic_cast<Student*>(b);
    if(h==NULL){
        cout<<"Your StudentEmployee is not a type of Student (-11)"<<endl;
        ok=false;
    }

    Employee* o=dynamic_cast<Employee*>(b);
    if(o==NULL){
        cout<<"Your StudentEmployee is not a type of Employee (-10)"<<endl;
        ok=false;
    }
    delete b;

    srand (time(NULL));

    try{
        StudentEmployee* ses[3];
        for(int i=0;i<3;i++){
            int workhours=rand()%250;
            int grade=rand()%100;
            int id=rand()%100;
            StudentEmployee se(id);
            se.setGrade(grade);
            se.setWorkHours(workhours);
            ses[i]=&se;
            char name[4]={(char)('0'+i),'.','b','\0'};
            se.save(name);
        }

        for(int i=0;i<3;i++){
            char name[4]={(char)('0'+i),'.','b','\0'};
            StudentEmployee se=StudentEmployee::load(name);

            if(se.id!=ses[i]->id || se.getGrade()!=ses[i]->getGrade() || se.getWorkHours()!=ses[i]->getWorkHours())
                cout<<"error loading StudentEmployee (-3)"<<endl;
        }
    }catch(...){
        cout<<"an exception was thrown trying to save or load StudentEmployees (-9)"<<endl;
    }

}

void test2(){

    srand (time(NULL));
    int id=rand()%100;
    Student s(id);
    isStudent is;
    if(!is(&s)){
        cout<<"problem with isStudent object function (-8)"<<endl;
    }

    Sum sm;
    sm(&s);
    if(sm.get()!=id){
        cout<<"problem with Sum object function (-8)"<<endl;
    }

    int size=16;
    int stdids=0;

    Person** Persons=new Person*[size];
    for(int i=0;i<size;i++){
        if(rand()%2){// 0,1
            Student* p=new Student(rand()%100);
            Persons[i]=p;
            stdids+=p->id;
        }else{
            Employee* e=new Employee(rand()%100);
            Persons[i]=e;
        }
    }
    
    Sum x = applyIf(Persons,size,isStudent(),Sum());
    if(x.get()!=stdids){
        int diff=abs(x.get() - stdids);
        cout<<"problem with applyIf function (-"<<min(diff,16)<<")"<<endl;
    }
    
    
    for(int i=0;i<size;i++){
        delete Persons[i];
    }

    delete [] Persons;
}


void test3(){
    srand (time(NULL));
    int size=35;
    Person** Persons=new Person*[size];
    for(int i=0;i<size;i++){
        Persons[i]=new Person(rand()%1000);
    }

    PersonList* last=new PersonList(NULL,NULL);
    for(int i=size-1;i>=0;i--){
        PersonList* bl=new PersonList(last, Persons[i]);
        last=bl;
    }
    PersonList* head=last;

    int i=0;
    PersonListIterator it(head);
    while (it.hasNext()){
        const Person* b = (*it);
        if(b->id !=Persons[i]->id)
            cout<<"wrong id for a Person (-1)"<<endl;
        ++it;
        ++i;
    }

    if (i!=size)
        cout<<"size error (-"<<(abs(size-i))<<")"<<endl;


    delete head; // delete the list and all items

    delete [] Persons;
}

int main()
{
    test1(); // 33 points
    test2(); // 32 points
    test3(); // 35 points
    cout<<"done"<<endl;
    return 0;
}
