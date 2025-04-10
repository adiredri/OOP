#include<iostream>
#include "Q1.h"
#include "Q2.h"
#include "Q3.h"
#include "Q4.h"
#include "Employee.h"

using namespace std;

void test1a(){ // question 1.a test
    vector<int> v;
    for(int i=0;i<10;i++)
        v.push_back(i);
    
    vector<int> f;
    filter(v.begin(),v.end(),[](int i){return i%2==0;},f);
    if(f.size()!=5){
        cout<<"wrong size for filtered result (-10)"<<endl;
        return;
    }
    for(int x : f){
        if(x%2!=0)
            cout<<"problem with filtered int value (-1)"<<endl;
    }

    vector<float> v1;
    for(float i=0;i<5;i+=0.5f)
        v1.push_back(i);
        
    vector<float> f1;
    filter(v1.begin(),v1.end(),[](float i){return i>2.5f;},f1);
    
    if(f1.size()!=4){
        cout<<"wrong size for filtered result (-5)"<<endl;
        return;
    }
    for(float x : f1){
        if(x<=2.5f)
            cout<<"problem with filtered float value (-1)"<<endl;
    }
    
    
}

void test1b(){ // question 1.b test
    vector<int> v;
    for(int i=0;i<15;i++)
        v.push_back(i);
    
    vector<double> m;
    map(v.begin(),v.end(),[](int i){return i*2.0;},m);
    
    int a=0;
    for(double x : m){
        if(x!=a*2.0)
            cout<<"wrong result for mapped value (-1)"<<endl;
        a++;
    }
}

void test2(){ // question 2 test
    float grades[10]={85,90,50,60,91,70,78,98,99,100};
    Employee e(1234, 10 , grades);
    save("train.emp",e);
    e.compareTo(load("train.emp"));
}


void test3(){ // question 3 test
    Clock c;
    
    c=125; // 02:05
    if(c.getH()!=2 || c.getM()!=5)
        cout<<"wrong value after op= (-3)"<<endl;
    
    c.setH(2);
    c.setM(5);
    
    ++c;
    if(c.getM()!=6)
        cout<<"wrong value after op++ (-3)"<<endl;
    
    c.setM(6);    
    --c;
    --c;
    if(c.getM()!=4)
        cout<<"wrong value after op-- (-3)"<<endl;
    
    c.setH(2);
    c.setM(5);
    c+=62;
    if(c.getH()!=3 || c.getM()!=7)
        cout<<"wrong value after op+= (-3)"<<endl;
    
    c.setH(2);
    c.setM(5);
    c-=122;
    if(c.getH()!=0 || c.getM()!=3)
        cout<<"wrong value after op-= (-3)"<<endl;

    c.setH(2);
    c.setM(5);
    if(c[0]!=2 || c[1]!=5)
        cout<<"wrong value after op[] (-3)"<<endl;
    
    c.setH(2);
    c.setM(5);
    c*=5;
    if(c.getH()!=7 || c.getM()!=5)
        cout<<"wrong value after op*= (-3)"<<endl;

    c.setH(2);
    c.setM(5);
    c/=5;
    if(c.getH()!=9 || c.getM()!=5)
        cout<<"wrong value after op/= (-3)"<<endl;
}

void test4(){ // question 4 test
    float grades[10]={85,90,50,60,91,70,78,98,99,100};
    Employee* e1=new Employee(3, 10 , grades);
    for(int i=0;i<10;i++)
        grades[i]-=5;
    Employee* e2=new Employee(2, 10 , grades);
    for(int i=0;i<10;i++)
        grades[i]-=10;
    Employee* e3=new Employee(1, 10 , grades);
    
    Employee* arr[]={e1,e2,e3}; // some pointers to employees
    
    EmpSorter* s=new IdEmpSorter();
    s->bubbleSort(arr,3); // sorts by ID
    
    if(!(arr[0]->getID()<arr[1]->getID() && arr[1]->getID()<arr[2]->getID()))
        cout<<"sorting by ID error (-12)"<<endl;
    delete s;
    s=new AvgEmpSorter();
    s->bubbleSort(arr,3); // sorts by Average

    if(!(arr[0]->getAVG()<arr[1]->getAVG() && arr[1]->getAVG()<arr[2]->getAVG()))
        cout<<"sorting by average error (-12)"<<endl;
    
    delete e1;
    delete e2;
    delete e3;
    
}
int main()
{
    test1a();
    test1b();
    test2();
    test3();
	test4();
    cout<<"done"<<endl;

    return 0;
}


