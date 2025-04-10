#include "Q1.h"
#include "Q2.h"
#include "Q3.h"

#include <sstream>

void checkOutput(const char* str,stringstream& out,int points){
    char buff[100];
    out.getline(buff,100);
    int i=0;
    bool ok=true;
    while(ok && str[i]!='\0'){
        ok = (str[i]==buff[i]);
        i++;
    }
    if(!ok)
        cout<<"you have a wrong output (-"<<points<<")"<<endl;
}

void test1()
{
    stringstream out;
    Manager* m2=new Manager(2,9);
    m2->addEmployee(new Engineer(3,1)).addEmployee(new Engineer(4,2));
    m2->printDetails(out);
    // output:
    /*
        Manager ID: 2 Level: 9
        Engineer ID: 3 Degree: 1
        Engineer ID: 4 Degree: 2
    */
    checkOutput("Manager ID: 2 Level: 9",out,3);
    checkOutput("Engineer ID: 3 Degree: 1",out,3);
    checkOutput("Engineer ID: 4 Degree: 2",out,3);

    
    Manager* m1=new Manager(1,10);
    m1->addEmployee(m2).addEmployee(new Engineer(5,1)).addEmployee(new Engineer(6,2));
    m1->printDetails(out);
    // output:
    /*
        Manager ID: 1 Level: 10
        Manager ID: 2 Level: 9
        Engineer ID: 3 Degree: 1
        Engineer ID: 4 Degree: 2
        Engineer ID: 5 Degree: 1
        Engineer ID: 6 Degree: 2    
    */
    checkOutput("Manager ID: 1 Level: 10",out,3);
    checkOutput("Manager ID: 2 Level: 9",out,3);
    checkOutput("Engineer ID: 3 Degree: 1",out,3);
    checkOutput("Engineer ID: 4 Degree: 2",out,3);
    checkOutput("Engineer ID: 5 Degree: 1",out,3);
    checkOutput("Engineer ID: 6 Degree: 2",out,3);
    
    
    delete m1; // deletes all employees (including m2)
    if(!check.areAllFree())
        cout<<"not all employees are free (-8)"<<endl;
    
}

void test2(){
    list<int> l1;
    list<int> l2;
    
    l1+=10;
    l1+=24;
    l1+=45;
    list<int>::iterator it=l1.begin();
    if(*(it++) !=10 || *(it++) !=24 || *it !=45)
        cout<<"wrong implementation of operator+=val (-10)"<<endl;
    
    l2.push_back(30);
    l2+=l1;
    l2+=l1;
    
    it=l2.begin();
    if(*(it++) !=30 || *(it++) !=10 || *(it++) !=24 || *(it++) !=45 || *(it++) !=10 || *(it++) !=24 || *it !=45)
        cout<<"wrong implementation of operator+=list (-10)"<<endl;

    stringstream out;
    // prints the values
    out<<l2<<endl;
    checkOutput("30, 10, 24, 45, 10, 24, 45, ",out,9);


    if(!(l1!=l2))
        cout<<"wrong implementation for operator!= (-3)"<<endl; 
    if(l1==l2)
        cout<<"wrong implementation for operator== (-3)"<<endl; 

}


void test3(){
    Property<int> p1;
    Property<int> p2;
    Property<int> p3;
    Property<int> p4;
        
    p1.bindTo(p2); 
    p2.bindTo(p3); 
    p3.bindTo(p1);
    
    p3.set(10);
    p4.set(19); // no one is bound to p4..
    
    if(p3.get()!=10)
        cout<<"problem with set method (-5)"<<endl;
    if(p2.get()!=10)
        cout<<"problem with direct binding (-5)"<<endl;
    if(p1.get()!=10)
        cout<<"problem with transitive binding (-10)"<<endl;
        
    // avoid endless loops!!!
    
    p1.set(30);
    if(p3.get()!=30)
        cout<<"problem with transitive binding (-10)"<<endl;
    // avoid endless loops!!!
    
    if(p4.get()!=19)
        cout<<"problem with set method (-5)"<<endl;	
}


int main(){
	test1();
	test2();
	test3();
	cout << "done" << endl;

	// if you want visual studio's output to wait before disappearing...
	// int x;
	// cin>>x;
	return 0;
}